#ifndef __BYTE_STREAM_READER_H__
#define __BYTE_STREAM_READER_H__

#include <Types.h>
#include <Helper.h>
#include <functional>
#include <cassert>
#include <string>
#include <optional>
#include <span>
#include <climits>


namespace ByteStreamCpp
{

template<typename U>
using ShapeFn = std::function<U(size_t)>;

template<typename Container>
class ByteStreamReader
{
    Container& view;
    size_t bytesUsedIndex;
    size_t bitsRemaining;
    byte remainder;

public:

    ByteStreamReader(Container& v)
        : view(v)
        , bytesUsedIndex(0)
        , bitsRemaining(0)
        , remainder(0)
    {}

    constexpr Container& data()
    {
        return view;
    }

    constexpr uint64 bytesRead() const
    {
        return bytesUsedIndex - (static_cast<byte>(bitsRemaining <= 0) >> 0);
    }

    constexpr uint64 bitsRead() const
    {
        return bytesUsedIndex * CHAR_BIT - (CHAR_BIT - bitsRemaining);
    }

    constexpr uint64 dataBytes() const
    {
        return view.size();
    }

    constexpr uint64 dataBits() const
    {
        return dataBytes() * CHAR_BIT;
    }

    constexpr bool isAtEnd() const
    {
        return (bytesUsedIndex * CHAR_BIT - (CHAR_BIT - bitsRemaining)) >= dataBits();
    }

    ByteStreamReader<Container>& skipBit()
    {
        return *this;
    }

    ByteStreamReader<Container>& skipBits(uint64 bits)
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

    ByteStreamReader<Container>& skip1s()
    {
        return *this;
    }

    ByteStreamReader<Container>& skip0s()
    {
        return *this;
    }

    ByteStreamReader<Container>& rewind(size_t bits)
    {
        return *this;
    }

    ByteStreamReader<Container>& rewind(size_t bits, size_t bytes)
    {
        return *this;
    }

    ByteStreamReader<Container>& flush()
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
        return 0;
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

    template<typename U>
    U readList(ShapeFn<U> fn, uint64 quantityBits)
    {
        return fn();
    }

    template<typename U>
    U peakList(ShapeFn<U> fn, uint64 quantityBits)
    {
        return fn();
    }

    uint64 pop(Container& destiny, uint8 bitsToRead, uint64 bufBits)
    {
        return 0;
    }

    uint64 peak(Container& destiny, uint8 bitsToRead, uint64 bufBits)
    {
        return 0;
    }
};

}

#endif
