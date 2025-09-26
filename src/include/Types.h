#ifndef __BYTE_STREAM_TYPES_H__
#define __BYTE_STREAM_TYPES_H__

#include <cstdio>

namespace ByteStream
{

static_assert(sizeof(unsigned char) == 1);
using uint8 = unsigned char;
using byte = uint8;

static_assert(sizeof(signed char) == 1);
using int8 = signed char;

static_assert(sizeof(unsigned short int) == 2);
using uint16 = unsigned short int;

static_assert(sizeof(signed short int) == 2);
using int16 = signed short int;

static_assert(sizeof(unsigned int) == 4);
using uint32 = unsigned int;

static_assert(sizeof(signed int) == 4);
using int32 = signed int;

static_assert(sizeof(unsigned long long int) == 8);
using uint64 = unsigned long long int;

static_assert(sizeof(signed long long int) == 8);
using int64 = signed long long int;

static_assert(sizeof(float) == 4);
using float32 = float;

static_assert(sizeof(double) == 8);
using float64 = double;

}

#endif