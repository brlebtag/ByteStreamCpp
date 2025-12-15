#ifndef __HELPER_H__
#define __HELPER_H__

#include <Types.h>

namespace ByteStreamCpp
{

inline byte to_byte(size_t data)
{
    return data & 0xFF;
}

// fast mod 8
inline byte fmod8(size_t data)
{
    return data & 7;
}

// most significant bit
inline bool msb(byte data)
{
    return (data & 0x80) > 0;
}

// least significant bit
inline bool lsb(byte data)
{
    return (data & 0x01) > 0;
}

}


#endif