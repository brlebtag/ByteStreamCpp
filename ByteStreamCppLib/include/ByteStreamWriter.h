#ifndef __BYTE_STREAM_WRITER_H__
#define __BYTE_STREAM_WRITER_H__

#include <Types.h>
#include <Helper.h>
#include <functional>
#include <cassert>
#include <string>
#include <span>
#include <climits>

template<typename U>
using ShapeFn = std::function<U(size_t)>;

namespace ByteStreamCpp
{

template<typename Container>
class ByteStreamWriter
{
    Container& view;
    size_t size_;
    size_t bytesUsedIndex;
    size_t bitsRemaining;
    size_t remainder;
public:

    ByteStreamWriter(Container& v)
        : view(v)
        , bytesUsedIndex(0)
        , bitsRemaining(8)
        , remainder(0)
    {
    }

    ~ByteStreamWriter()
    {
        flush();
    }

    constexpr Container& data()
    {
        return view;
    }

    ByteStreamWriter<Container>& flush()
    {
        return *this;
    }

    constexpr size_t bytesWritten() const
    {
        return bytesUsedIndex + (static_cast<size_t>(bitsRemaining < CHAR_BIT) >> 0);
    }

    constexpr size_t bitsWritten() const
    {
        return (bytesUsedIndex * CHAR_BIT) + (CHAR_BIT - bitsRemaining);
    }

    constexpr size_t dataBytes() const
    {
        return view.size();
    }

    constexpr size_t dataBits() const
    {
        return dataBytes() * CHAR_BIT;
    }

    constexpr bool isAtEnd() const
    {
        return ((bytesUsedIndex * 8) + (8 - bitsRemaining)) >= dataBits();
    }

    ByteStreamWriter<Container>& skipBit()
    {
        return *this;
    }

    ByteStreamWriter<Container>& skipBits(size_t bits)
    {
        return *this;
    }

    ByteStreamWriter<Container>&  write1()
    {
        return *this;
    }

    ByteStreamWriter<Container>& write0()
    {
        return *this;
    }

    ByteStreamWriter<Container>& write1s(size_t bits)
    {
        return *this;
    }

    ByteStreamWriter<Container>& write0s(size_t bits)
    {
        return *this;
    }

    ByteStreamWriter<Container>& rewind(size_t bit)
    {
        return *this;
    }

    ByteStreamWriter<Container>& rewind(size_t bit, size_t byte)
    {
        return *this;
    }

    ByteStreamWriter<Container>& writeUtf8BE(std::string value)
    {
        return *this;
    }

    ByteStreamWriter<Container>& writeUtf8LE(std::string value)
    {
        return *this;
    }

    ByteStreamWriter<Container>& writeFixedUtf8BE(uint64 bits, std::string value)
    {
        return *this;
    }

    ByteStreamWriter<Container>& writeFixedUtf8LE(uint64 bits, std::string value)
    {
        return *this;
    }

    ByteStreamWriter<Container>& writeUtf16BE(std::u16string value) 
    {
        return *this;
    }

    ByteStreamWriter<Container>& writeUtf16LE(std::u16string value) 
    {
        return *this;
    }
    
    ByteStreamWriter<Container>& writeFixedUtf16BE(uint64 bits, std::u16string value)
    {
        return *this;
    }

    ByteStreamWriter<Container>& writeFixedUtf16LE(uint64 bits, std::u16string value)
    {
        return *this;
    }

    template<typename U>
    ByteStreamWriter<Container>& writeFixedList(U list, ShapeFn<U> shapeFn, uint64 quantity, uint64 quantityBits, uint64 beginIndex)
    {
        return *this;
    }

    template<typename U>
    ByteStreamWriter<Container>& writeVaryingList(U list, ShapeFn<U> shapeFn, uint64 quantity, uint64 quantityBits, uint64 beginIndex)
    {
        return *this;
    }

    template<typename U>
    ByteStreamWriter<Container>& writeFixedInfinityList(ShapeFn<U> shapeFn, uint64 quantityBits)
    {
        return *this;
    }

    template<typename U>
    ByteStreamWriter<Container>& writeVaryingInfinityList(ShapeFn<U> shapeFn, uint64 quantityBits)
    {
        return *this;
    }
    
    ByteStreamWriter<Container>& setBit(uint64 bit, uint64 byte)
    {
        return *this;
    }

    ByteStreamWriter<Container>& unsetBit(uint64 bit, uint64 byte)
    {
        return *this;
    }

    ByteStreamWriter<Container>& writeIntNBE(uint8 n, uint64 value)
    {
        return *this;
    }

    ByteStreamWriter<Container>& writeIntNLE(uint8 n, uint64 value)
    {
        return *this;
    }

    ByteStreamWriter<Container>& replaceIntNBE(uint64 bitToStart, uint8 n, uint64 value)
    {
        return *this;
    }

    ByteStreamWriter<Container>& replaceIntNLE(uint64 bitToStart, uint8 n, uint64 value)
    {
        return *this;
    }

    ByteStreamWriter<Container>& writeUIntNBE(uint8 n, uint64 value)
    {
        return *this;
    }

    ByteStreamWriter<Container>& writeUIntNLE(uint8 n, uint64 value)
    {
        return *this;
    }

    ByteStreamWriter<Container>& replaceUIntNBE(uint64 bitToStart, uint8 n, uint64 value)
    {
        return *this;
    }

    ByteStreamWriter<Container>& replaceUIntNLE(uint64 bitToStart, uint8 n, uint64 value)
    {
        return *this;
    }

    ByteStreamWriter<Container>& writeInt8(int8 value)
    {
        return *this;
    }

    ByteStreamWriter<Container>& replaceInt8(uint64 bitToStart, int8 value)
    {
        return *this;
    }

    ByteStreamWriter<Container>& writeUInt8(uint8 value)
    {
        return *this;
    }

    ByteStreamWriter<Container>& replaceUInt8(uint64 bitToStart, uint8 value)
    {
        return *this;
    }

    ByteStreamWriter<Container>& writeInt16BE(int16 value)
    {
        return *this;
    }

    ByteStreamWriter<Container>& writeInt16LE(int16 value)
    {
        return *this;
    }

    ByteStreamWriter<Container>& replaceInt16BE(uint64 bitToStart, int16 value) 
    {
        return *this;
    }

    ByteStreamWriter<Container>& replaceInt16LE(uint64 bitToStart, int16 value) 
    {
        return *this;
    }

    ByteStreamWriter<Container>& writeUInt16BE(uint16 value)
    {
        return *this;
    }

    ByteStreamWriter<Container>& writeUInt16LE(uint16 value)
    {
        return *this;
    }

    ByteStreamWriter<Container>& replaceUInt16BE(uint64 bitToStart, uint16 value)
    {
        return *this;
    }

    ByteStreamWriter<Container>& replaceUInt16LE(uint64 bitToStart, uint16 value)
    {
        return *this;
    }

    ByteStreamWriter<Container>& writeInt32BE(int32 value)
    {
        return *this;
    }

    ByteStreamWriter<Container>& writeInt32LE(int32 value)
    {
        return *this;
    }

    ByteStreamWriter<Container>& replaceInt32BE(uint64 bitToStart, int32 value)
    {
        return *this;
    }

    ByteStreamWriter<Container>& replaceInt32LE(uint64 bitToStart, int32 value)
    {
        return *this;
    }

    ByteStreamWriter<Container>& writeUInt32BE(uint32 value)
    {
        return *this;
    }

    ByteStreamWriter<Container>& writeUInt32LE(uint32 value)
    {
        return *this;
    }

    ByteStreamWriter<Container>& replaceUInt32BE(uint64 bitToStart, uint32 value)
    {
        return *this;
    }

    ByteStreamWriter<Container>& replaceUInt32LE(uint64 bitToStart, uint32 value)
    {
        return *this;
    }

    ByteStreamWriter<Container>& writeInt64BE(int64 value)
    {
        return *this;
    }

    ByteStreamWriter<Container>& writeInt64LE(int64 value)
    {
        return *this;
    }

    ByteStreamWriter<Container>& replaceInt64BE(uint64 bitToStart, int64 value)
    {
        return *this;
    }

    ByteStreamWriter<Container>& replaceInt64LE(uint64 bitToStart, int64 value)
    {
        return *this;
    }

    ByteStreamWriter<Container>& writeUInt64BE(uint64 value)
    {
        return *this;
    }

    ByteStreamWriter<Container>& writeUInt64LE(uint64 value)
    {
        return *this;
    }

    ByteStreamWriter<Container>& replaceUInt64BE(uint64 bitToStart, uint64 value)
    {
        return *this;
    }

    ByteStreamWriter<Container>& replaceUInt64LE(uint64 bitToStart, uint64 value)
    {
        return *this;
    }

    ByteStreamWriter<Container>& writeFloat32BE(float32 value)
    {
        return *this;
    }

    ByteStreamWriter<Container>& writeFloat32LE(float32 value)
    {
        return *this;
    }

    ByteStreamWriter<Container>& replaceFloat32BE(uint64 bitToStart, float32 value)
    {
        return *this;
    }

    ByteStreamWriter<Container>& replaceFloat32LE(uint64 bitToStart, float32 value)
    {
        return *this;
    }

    ByteStreamWriter<Container>& writeFloat64BE(float64 value)
    {
        return *this;
    }

    ByteStreamWriter<Container>& writeFloat64LE(float64 value)
    {
        return *this;
    }

    ByteStreamWriter<Container>& replaceFloat64BE(uint64 bitToStart, float64 value)
    {
        return *this;
    }

    ByteStreamWriter<Container>& replaceFloat64LE(uint64 bitToStart, float64 value)
    {
        return *this;
    }

    ByteStreamWriter<Container>& replace(uint64 bitToStart, uint64 n, std::function<void()> writeFn)
    {
        return *this;
    }

    ByteStreamWriter<Container>& push(Container& source, uint64 n, uint64 bufSize)
    {
        return *this;
    }
};

}

#endif