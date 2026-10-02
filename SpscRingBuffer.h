#pragma once

#include <string.h>
#include <algorithm>
#include <atomic>

//Capacity should be 2^n
template<size_t Capacity>
class SpscRingBuffer {
private:
    static constexpr size_t kMask = Capacity - 1;

    alignas(64) std::atomic<size_t> head_ = 0;  //pop
    alignas(64) std::atomic<size_t> tail_ = 0;  //push
    uint8_t buffer_[Capacity];

public:
    size_t push(const uint8_t *data, size_t count)
    {
        size_t current_tail = tail_.load(std::memory_order_relaxed);
        size_t current_head = head_.load(std::memory_order_acquire);
        const size_t bytesToWrite = std::min(count, Capacity - (current_tail - current_head));
        if (bytesToWrite == 0) {
            return 0;
        }
        size_t writePos = current_tail & kMask;
        size_t firstChunk = std::min(bytesToWrite, Capacity - writePos);
        size_t secondChunk = bytesToWrite - firstChunk;
        memcpy(&buffer_[writePos], data, firstChunk);
        if (secondChunk > 0) {
            memcpy(&buffer_[0], data + firstChunk, secondChunk);
        }
        tail_.store(current_tail + bytesToWrite, std::memory_order_release);
        return bytesToWrite;
    }

    size_t peek(uint8_t *data, size_t count)
    {
        size_t current_head = head_.load(std::memory_order_relaxed);
        size_t current_tail = tail_.load(std::memory_order_acquire);
        size_t bytesToRead = std::min(count, current_tail - current_head);
        size_t readPos = current_head & kMask;
        size_t firstChunk = std::min(bytesToRead, Capacity - readPos);
        size_t secondChunk = bytesToRead - firstChunk;
        memcpy(data, &buffer_[readPos], firstChunk);
        if (secondChunk > 0) {
            memcpy(data + firstChunk, &buffer_[0], secondChunk);
        }
        return bytesToRead;
    }

    void pop(size_t count)
    {
        size_t current_head = head_.load(std::memory_order_relaxed);
        size_t current_tail = tail_.load(std::memory_order_acquire);
        size_t bytesToPop = std::min(count, current_tail - current_head);
        if (bytesToPop > 0) {
            head_.store(current_head + bytesToPop, std::memory_order_release);
        }
    }

    size_t size()
    {
        size_t current_tail = tail_.load(std::memory_order_relaxed);
        size_t current_head = head_.load(std::memory_order_acquire);
        return current_tail - current_head;
    }

    void clear()
    {
        head_.store(tail_.load(std::memory_order_relaxed), std::memory_order_release);
    }
};
