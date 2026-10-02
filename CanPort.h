#pragma once

typedef uint32_t (__stdcall *can_openDevice)(uint32_t DeviceType, uint32_t DeviceInd, uint32_t Reserved);
typedef uint32_t (__stdcall *can_closeDevice)(uint32_t DeviceType, uint32_t DeviceInd);
typedef uint32_t (__stdcall *can_initCAN)(uint32_t DeviceType, uint32_t DeviceInd, uint32_t CANInd, VCI_INIT_CONFIG *pInitConfig);
typedef uint32_t (__stdcall *can_readBoardInfo)(uint32_t DeviceType, uint32_t DeviceInd, VCI_BOARD_INFO *pInfo);
typedef uint32_t (__stdcall *can_startCAN)(uint32_t DeviceType, uint32_t DeviceInd, uint32_t CANInd);
typedef uint32_t (__stdcall *can_resetCAN)(uint32_t DeviceType, uint32_t DeviceInd, uint32_t CANInd);
typedef uint32_t (__stdcall *can_clearBuffer)(uint32_t DeviceType, uint32_t DeviceInd, uint32_t CANInd);
typedef uint32_t (__stdcall *can_getReceiveNum)(uint32_t DeviceType, uint32_t DeviceInd, uint32_t CANInd);
typedef uint32_t (__stdcall *can_transmit)(uint32_t DeviceType, uint32_t DeviceInd, uint32_t CANInd, VCI_CAN_OBJ *pTransmit, uint32_t len);
typedef uint32_t (__stdcall *can_receive)(uint32_t DeviceType, uint32_t DeviceInd, uint32_t CANInd, VCI_CAN_OBJ *pReceive, uint32_t len, int wait_time);
typedef uint32_t (__stdcall *can_setReference)(uint32_t DeviceType, uint32_t DeviceInd, uint32_t CANInd, uint32_t RefType, void *pData);
typedef uint32_t (__stdcall *can_usbDeviceReset)(uint32_t DeviceType, uint32_t DeviceInd, uint32_t Reserved);

typedef struct {
    uint16_t hw_Version;
    uint16_t fw_Version;
    uint16_t dr_Version;
    uint16_t in_Version;
    uint16_t irq_Num;
    uint8_t can_Num;
    char str_Serial_Num[20];
    char str_hw_Type[40];
    uint16_t reserved[4];
} VCI_BOARD_INFO;

typedef struct {
    uint32_t acc_code;
    uint32_t acc_mask;
    uint32_t reserved;
    uint8_t filter;
    uint8_t timing0;
    uint8_t timing1;
    uint8_t mode;
} VCI_INIT_CONFIG;

typedef struct {
    uint32_t ID;
    uint32_t TimeStamp;
    uint8_t	 TimeFlag;
    uint8_t	 SendType;
    uint8_t	 RemoteFlag;
    uint8_t	 ExternFlag;
    uint8_t	 DataLen;
    uint8_t	 data[8];
    uint8_t	 Reserved[3];
} VCI_CAN_OBJ;

#define CAN_EFF_FLAG 0x80000000u    //EFF/SFF is set in the MSB
#define CAN_RTR_FLAG 0x40000000u    //remote transmission request
#define CAN_ERR_FLAG 0x20000000u    //error message frame
#define CAN_ID_FLAG  0x1FFFFFFFu    //id

#define CAN_SEF_MASK 0x000007FFu    //standard frame format
#define CAN_EFF_MASK 0x1FFFFFFFu    //extended frame format
#define CAN_ERR_MASK 0x1FFFFFFFu    //omit EFF, RTR, ERR flags

#define CAN_SFF_ID_BITS     11
#define CAN_EFF_ID_BITS     29

#define VCI_USBCAN1			3
#define VCI_USBCAN2			4

#define STATUS_ERR			0
#define	STATUS_OK			1

#define TRANSMIT_NORMAL 0
#define TRANSMIT_SINGLE 1
#define TRANSMIT_SELFLOOP 2
#define TRANSMIT_SINGLE_SELFLOOP 3

static int kCanBaudrate[] = {
    20000,
    50000,
    100000,
    125000,
    250000,
    500000,
    800000,
    1000000,
};

static const uint16_t kTimingCode[] = {
    0x1C18,
    0x1C09,
    0x1C04,
    0x1C03,
    0x1C01,
    0x1C00,
    0x1600,
    0x1400,
};

class CanPort : public QObject {
    Q_OBJECT

private:
    uint32_t hDevice;
    uint32_t channel;

    can_openDevice VCI_OpenDevice;
    can_closeDevice VCI_CloseDevice;
    can_initCAN VCI_InitCAN;
    can_readBoardInfo VCI_ReadBoardInfo;
    can_startCAN VCI_StartCAN;
    can_resetCAN VCI_ResetCAN;
    can_clearBuffer VCI_ClearBuffer;
    can_getReceiveNum VCI_GetReceiveNum;
    can_transmit VCI_Transmit;
    can_receive VCI_Receive;
    can_setReference VCI_SetReference;
    can_usbDeviceReset VCI_UsbDeviceReset;

    HANDLE close_event = nullptr;
    QThread *workerThread = nullptr;

    void readLoop();

public:
    bool isOpen = false;
    SpscRingBuffer<4096> ring_buffer;

    CanPort(QObject *parent = nullptr);
    ~CanPort();
    bool openPort(uint32_t chan, uint32_t baudrate);
    void closePort();
    bool writeDataAsync(const QByteArray &data, int timeoutMs = kTimeout);

signals:
    void dataReceived();
    void errorOccurred(const QString &errorMsg);
};
