#pragma once

#include <rdapi/rdapi.h>

struct GUID
{
    u32 data1;
    u16 data2, data3;
    u8 data4[8];
};

typedef u32 LCID;
