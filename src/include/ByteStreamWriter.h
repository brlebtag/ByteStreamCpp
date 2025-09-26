#ifndef __BYTE_STREAM_WRITER_H__
#define __BYTE_STREAM_WRITER_H__

#include "Types.h"
#include <functional>
#include <cassert>
#include <string>

template<typename U>
using ShapeFn = std::function<U(size_t)>;

namespace ByteStream
{

template<typename T>
class ByteStreamWriter
{
    const T& data_;
    size_t size_;
    size_t bytesUsedIndex;
    size_t bitsRemaining;
    size_t remainder;
public:

    ByteStreamWriter(const T& data, size_t size)
        : data_(data)
        , size_(size)
        , bytesUsedIndex(0)
        , bitsRemaining(8)
        , remainder(0)
    {
    }

    void flush()
    {
    }

    constexpr T& data()
    {
        flush();
        return data_;
    }

    constexpr uint64 bytesWritten() const
    {
        return 0;
    }

    constexpr uint64 bitsWritten() const
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

    ByteStreamWriter<T>& skipBit()
    {
        return *this;
    }

    ByteStreamWriter<T>& skipBits(size_t bits)
    {
        return *this;
    }

    ByteStreamWriter<T>&  write1()
    {
        return *this;
    }

    ByteStreamWriter<T>& write0()
    {
        return *this;
    }

    ByteStreamWriter<T>& write1s(size_t bits)
    {
        return *this;
    }

    ByteStreamWriter<T>& write0s(size_t bits)
    {
        return *this;
    }

    ByteStreamWriter<T>& rewind(size_t bit)
    {
        return *this;
    }

    ByteStreamWriter<T>& rewind(size_t bit, size_t byte)
    {
        return *this;
    }

    ByteStreamWriter<T>& flush()
    {
        return *this;
    }

    ByteStreamWriter<T>& writeUtf8BE(std::string value)
    {
        return *this;
    }

    ByteStreamWriter<T>& writeUtf8LE(std::string value)
    {
        return *this;
    }

    ByteStreamWriter<T>& writeFixedUtf8BE(uint64 bits, std::string value)
    {
        return *this;
    }

    ByteStreamWriter<T>& writeFixedUtf8LE(uint64 bits, std::string value)
    {
        return *this;
    }

    ByteStreamWriter<T>& writeUtf16BE(std::u16string value) 
    {
        return *this;
    }

    ByteStreamWriter<T>& writeUtf16LE(std::u16string value) 
    {
        return *this;
    }
    
    ByteStreamWriter<T>& writeFixedUtf16BE(uint64 bits, std::u16string value)
    {
        return *this;
    }

    ByteStreamWriter<T>& writeFixedUtf16LE(uint64 bits, std::u16string value)
    {
        return *this;
    }

    template<typename U>
    ByteStreamWriter<T>& writeFixedList(U list, ShapeFn<U> shapeFn, uint64 quantity, uint64 quantityBits, uint64 beginIndex)
    {
        return *this;
    }

    template<typename U>
    ByteStreamWriter<T>& writeVaryingList(U list, ShapeFn<U> shapeFn, uint64 quantity, uint64 quantityBits, uint64 beginIndex)
    {
        return *this;
    }

    template<typename U>
    ByteStreamWriter<T>& writeFixedInfinityList(ShapeFn<U> shapeFn, uint64 quantityBits)
    {
        return *this;
    }

    template<typename U>
    ByteStreamWriter<T>& writeVaryingInfinityList(ShapeFn<U> shapeFn, uint64 quantityBits)
    {
        return *this;
    }
    
    ByteStreamWriter<T>& setBit(uint64 bit, uint64 byte)
    {
        return *this;
    }

    ByteStreamWriter<T>& unsetBit(uint64 bit, uint64 byte)
    {
        return *this;
    }

    ByteStreamWriter<T>& writeIntNBE(uint8 n, uint64 value)
    {
        return *this;
    }

    ByteStreamWriter<T>& writeIntNLE(uint8 n, uint64 value)
    {
        return *this;
    }

    ByteStreamWriter<T>& replaceIntNBE(uint64 bitToStart, uint8 n, uint64 value)
    {
        return *this;
    }

    ByteStreamWriter<T>& replaceIntNLE(uint64 bitToStart, uint8 n, uint64 value)
    {
        return *this;
    }

    ByteStreamWriter<T>& writeUIntNBE(uint8 n, uint64 value)
    {
        return *this;
    }

    ByteStreamWriter<T>& writeUIntNLE(uint8 n, uint64 value)
    {
        return *this;
    }

    ByteStreamWriter<T>& replaceUIntNBE(uint64 bitToStart, uint8 n, uint64 value)
    {
        return *this;
    }

    ByteStreamWriter<T>& replaceUIntNLE(uint64 bitToStart, uint8 n, uint64 value)
    {
        return *this;
    }

    ByteStreamWriter<T>& writeInt8(int8 value)
    {
        return *this;
    }

    ByteStreamWriter<T>& replaceInt8(uint64 bitToStart, int8 value)
    {
        return *this;
    }

    ByteStreamWriter<T>& writeUInt8(uint8 value)
    {
        return *this;
    }

    ByteStreamWriter<T>& replaceUInt8(uint64 bitToStart, uint8 value)
    {
        return *this;
    }

    ByteStreamWriter<T>& writeInt16BE(int16 value)
    {
        return *this;
    }

    ByteStreamWriter<T>& writeInt16LE(int16 value)
    {
        return *this;
    }

    ByteStreamWriter<T>& replaceInt16BE(uint64 bitToStart, int16 value) 
    {
        return *this;
    }

    ByteStreamWriter<T>& replaceInt16LE(uint64 bitToStart, int16 value) 
    {
        return *this;
    }

    ByteStreamWriter<T>& writeUInt16BE(uint16 value)
    {
        return *this;
    }

    ByteStreamWriter<T>& writeUInt16LE(uint16 value)
    {
        return *this;
    }

    ByteStreamWriter<T>& replaceUInt16BE(uint64 bitToStart, uint16 value)
    {
        return *this;
    }

    ByteStreamWriter<T>& replaceUInt16LE(uint64 bitToStart, uint16 value)
    {
        return *this;
    }

    ByteStreamWriter<T>& writeInt32BE(int32 value)
    {
        return *this;
    }

    ByteStreamWriter<T>& writeInt32LE(int32 value)
    {
        return *this;
    }

    ByteStreamWriter<T>& replaceInt32BE(uint64 bitToStart, int32 value)
    {
        return *this;
    }

    ByteStreamWriter<T>& replaceInt32LE(uint64 bitToStart, int32 value)
    {
        return *this;
    }

    ByteStreamWriter<T>& writeUInt32BE(uint32 value)
    {
        return *this;
    }

    ByteStreamWriter<T>& writeUInt32LE(uint32 value)
    {
        return *this;
    }

    ByteStreamWriter<T>& replaceUInt32BE(uint64 bitToStart, uint32 value)
    {
        return *this;
    }

    ByteStreamWriter<T>& replaceUInt32LE(uint64 bitToStart, uint32 value)
    {
        return *this;
    }

    ByteStreamWriter<T>& writeInt64BE(int64 value)
    {
        return *this;
    }

    ByteStreamWriter<T>& writeInt64LE(int64 value)
    {
        return *this;
    }

    ByteStreamWriter<T>& replaceInt64BE(uint64 bitToStart, int64 value)
    {
        return *this;
    }

    ByteStreamWriter<T>& replaceInt64LE(uint64 bitToStart, int64 value)
    {
        return *this;
    }

    ByteStreamWriter<T>& writeUInt64BE(uint64 value)
    {
        return *this;
    }

    ByteStreamWriter<T>& writeUInt64LE(uint64 value)
    {
        return *this;
    }

    ByteStreamWriter<T>& replaceUInt64BE(uint64 bitToStart, uint64 value)
    {
        return *this;
    }

    ByteStreamWriter<T>& replaceUInt64LE(uint64 bitToStart, uint64 value)
    {
        return *this;
    }

    ByteStreamWriter<T>& writeFloat32BE(float32 value)
    {
        return *this;
    }

    ByteStreamWriter<T>& writeFloat32LE(float32 value)
    {
        return *this;
    }

    ByteStreamWriter<T>& replaceFloat32BE(uint64 bitToStart, float32 value)
    {
        return *this;
    }

    ByteStreamWriter<T>& replaceFloat32LE(uint64 bitToStart, float32 value)
    {
        return *this;
    }

    ByteStreamWriter<T>& writeFloat64BE(float64 value)
    {
        return *this;
    }

    ByteStreamWriter<T>& writeFloat64LE(float64 value)
    {
        return *this;
    }

    ByteStreamWriter<T>& replaceFloat64BE(uint64 bitToStart, float64 value)
    {
        return *this;
    }

    ByteStreamWriter<T>& replaceFloat64LE(uint64 bitToStart, float64 value)
    {
        return *this;
    }

    ByteStreamWriter<T>& replace(uint64 bitToStart, uint64 n, std::function<void()> writeFn)
    {
        return *this;
    }

    ByteStreamWriter<T>& push(T& source, uint64 n, uint64 bufSize)
    {
        return *this;
    }
};

}

#endif