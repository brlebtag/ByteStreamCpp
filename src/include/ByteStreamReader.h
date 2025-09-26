#ifndef __BYTE_STREAM_READER_H__
#define __BYTE_STREAM_READER_H__

#include "Types.h"
#include <functional>
#include <cassert>
#include <string>
#include <optional>

#define BYTE_MASK 0xFF
#define FAST_MOD_8(val) ((val) & 7)
#define CAST_TO_BYTE(val) ((val) & BYTE_MASK)
#define MOST_SIGNIFICANT_BIT(val) ((val) & 0x80)
#define IS_SET(val) ((val) > 0)
#define IS_NOT_SET(val) ((val) <= 0)

namespace ByteStream
{

template<typename U>
using ShapeFn = std::function<U(size_t)>;

template<typename T>
class ByteStreamReader
{
    const T& data_;
    size_t size_;
    size_t bytesUsedIndex;
    size_t bitsRemaining;
    size_t remainder;

public:

    ByteStreamReader(const T& data, size_t size)
        : data_(data)
        , size_(size)
        , bytesUsedIndex(0)
        , bitsRemaining(0)
        , remainder(0)
    {}

    constexpr T& data() const
    {        
        return data_;
    }

    constexpr uint64 bytesRead() const
    {
        return 0;
    }

    constexpr uint64 bitsRead() const
    {
        return 0;
    }

    constexpr uint64 dataBytes() const
    {
        return 0;
    }

    constexpr uint64 dataBits() const
    {
        return 0;
    }

    constexpr bool isAtEnd() const
    {
        return 0;
    }

    ByteStreamReader<T>& skipBit()
    {
        return *this;
    }

    ByteStreamReader<T>& skipBits(uint64 bits)
    {
        return *this;
    }

    uint64 count1s()
    {
        return 0;
    }

    uint64 count0s()
    {
        return 0;
    }

    ByteStreamReader<T>& skip1s()
    {
        return *this;
    }

    ByteStreamReader<T>& skip0s()
    {
        return *this;
    }

    ByteStreamReader<T>& rewind(size_t bits)
    {
        return *this;
    }

    ByteStreamReader<T>& rewind(size_t bits, size_t bytes)
    {
        return *this;
    }

    ByteStreamReader<T>& flush()
    {
        return *this;
    }

    std::string readUtf8BE()
    {
        return {};
    }

    std::string peakUtf8BE()
    {
        return {};
    }

    std::string readUtf8LE()
    {
        return {};
    }

    std::string peakUtf8LE()
    {
        return {};
    }

    std::string readFixedUtf8BE()
    {
        return {};
    }

    std::string peakFixedUtf8BE()
    {
        return {};
    }

    std::string readFixedUtf8LE()
    {
        return {};
    }

    std::string peakFixedUtf8LE()
    {
        return {};
    }
    
    std::u16string readUtf16BE()
    {
        return {};
    }

    std::u16string peakUtf16BE()
    {
        return {};
    }

    std::u16string readUtf16LE()
    {
        return {};
    }

    std::u16string peakUtf16LE()
    {
        return {};
    }

    std::u16string readFixedUtf16BE()
    {
        return {};
    }

    std::u16string peakFixedUtf16BE()
    {
        return {};
    }

    std::u16string readFixedUtf16LE()
    {
        return {};
    }

    std::u16string peakFixedUtf16LE()
    {
        return {};
    }

    uint8 readBit()
    {
    }

    uint8 peakBit()
    {
        return 0;
    }
    
    uint64 readIntNBE(int bits)
    {
        return 0;
    }

    uint64 peakIntNBE(int bits)
    {
        return 0;
    }

    uint64 readIntNLE(int bits)
    {
        return 0;
    }

    uint64 peakIntNLE(int bits)
    {
        return 0;
    }

    uint64 readUIntNBE(int bits)
    {
        return 0;
    }

    uint64 peakUIntNBE(int bits)
    {
        return 0;
    }

    uint64 readUIntNLE(int bits)
    {
        return 0;
    }

    uint64 peakUIntNLE(int bits)
    {
        return 0;
    }

    int8 readInt8()
    {
        return 0;
    }

    uint8 peakInt8()
    {
        return 0;
    }

    uint8 readUInt8()
    {
        return 0;
    }

    uint8 peakUInt8()
    {
        return 0;
    }

    int16 readInt16BE()
    {
        return 0;
    }

    int16 peakInt16BE()
    {
        return 0;
    }

    int16 readInt16LE()
    {
        return 0;
    }

    int16 peakInt16LE()
    {
        return 0;
    }

    uint16 readUInt16BE()
    {
        return 0;
    }

    uint16 peakUInt16BE()
    {
        return 0;
    }

    uint16 readUInt16LE()
    {
        return 0;
    }

    uint16 peakUInt16LE()
    {
        return 0;
    }

    int32 readInt32BE()
    {
        return 0;
    }

    int32 peakInt32BE()
    {
        return 0;
    }

    int32 readInt32LE()
    {
        return 0;
    }

    int32 peakInt32LE()
    {
        return 0;
    }
    
    uint32 readUInt32BE()
    {
        return 0;
    }

    uint32 peakUInt32BE()
    {
        return 0;
    }

    uint32 readUInt32LE()
    {
        return 0;
    }

    uint32 peakUInt32LE()
    {
        return 0;
    }

    int64 readInt64BE()
    {
        return 0;
    }

    int64 peakInt64BE()
    {
        return 0;
    }

    int64 readInt64LE()
    {
        return 0;
    }

    int64 peakInt64LE()
    {
        return 0;
    }
    
    uint64 readUInt64BE()
    {
        return 0;
    }

    uint64 peakUInt64BE()
    {
        return 0;
    }

    uint64 readUInt64LE()
    {
        return 0;
    }

    uint64 peakUInt64LE()
    {
        return 0;
    }

    template<U>
    U readList(ShapeFn<U> fn, uint64 quantityBits)
    {

    }

    template<U>
    U peakList(ShapeFn<U> fn, uint64 quantityBits)
    {

    }

    uint64 pop(T& destiny, uint8 bitsToRead, uint64 bufBits)
    {
        return 0;
    }

    uint64 peak(T& destiny, uint8 bitsToRead, uint64 bufBits)
    {
        return 0;
    }
};

}

#endif
