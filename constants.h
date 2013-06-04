#ifndef STOLEN_CONSTS
#define STOLEN_CONSTS

#define DRMAA_TIMEOUT_NO_WAIT            0
#define DRMAA_TIMEOUT_WAIT_FOREVER       -1
#define DRMAA_PS_UNDETERMINED            0x00
#define DRMAA_PS_QUEUED_ACTIVE           0x10
#define DRMAA_PS_SYSTEM_ON_HOLD          0x11
#define DRMAA_PS_USER_ON_HOLD            0x12
#define DRMAA_PS_USER_SYSTEM_ON_HOLD     0x13
#define DRMAA_PS_RUNNING                 0x20
#define DRMAA_PS_SYSTEM_SUSPENDED        0x21
#define DRMAA_PS_USER_SUSPENDED          0x22
#define DRMAA_PS_USER_SYSTEM_SUSPENDED   0x23
#define DRMAA_PS_DONE                    0x30
#define DRMAA_PS_FAILED                  0x40
#define DRMAA_CONTROL_SUSPEND            0
#define DRMAA_CONTROL_RESUME             1
#define DRMAA_CONTROL_HOLD               2
#define DRMAA_CONTROL_RELEASE            3
#define DRMAA_CONTROL_TERMINATE          4
#define DRMAA_JOB_IDS_SESSION_ALL        "DRMAA_JOB_IDS_SESSION_ALL"
#define DRMAA_JOB_IDS_SESSION_ANY        "DRMAA_JOB_IDS_SESSION_ANY"

#endif
