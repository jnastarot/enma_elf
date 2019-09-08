#include "pch.h"
#include "elf_helpers.h"

endian_encoding_type get_native_encoding() {

    const int _test = 1;
    if (*(uint8_t*)& _test = 1) {
        return ENDIAN_ENCODING_LITTLE;
    }
    else {
        return ENDIAN_ENCODING_BIG;
    }
}

endian_encoding::endian_encoding() 
    : host_encoding(get_native_encoding()), need_encoding(get_native_encoding()) {}

endian_encoding::endian_encoding(endian_encoding_type need_encoding)
    : host_encoding(get_native_encoding()), need_encoding(need_encoding) {}

endian_encoding::endian_encoding(uint32_t elf_data_type) 
    : host_encoding(get_native_encoding()) {


    if (elf_data_type == ELFDATA2LSB) {
        need_encoding = ENDIAN_ENCODING_LITTLE;
    }
    else {
        need_encoding = ENDIAN_ENCODING_BIG;
    }
}

endian_encoding::~endian_encoding() {
}

endian_encoding& endian_encoding::operator=(const endian_encoding& _encoding) {

    this->need_encoding = _encoding.need_encoding;

    return *this;
}

uint8_t endian_encoding::operator()(uint8_t value) const {
    return value;
}
uint16_t endian_encoding::operator()(uint16_t value) const {

    if (this->host_encoding == this->need_encoding) {
        return value;
    }

    return ((value & 0x00FF) << 8) |
           ((value & 0xFF00) >> 8);
}
uint32_t endian_encoding::operator()(uint32_t value) const {

    if (this->host_encoding == this->need_encoding) {
        return value;
    }

    return ((value & 0x000000FF) << 24) |
           ((value & 0x0000FF00) << 8)  |
           ((value & 0x00FF0000) >> 8)  |
           ((value & 0xFF000000) >> 24);
}
uint64_t endian_encoding::operator()(uint64_t value) const {

    if (this->host_encoding == this->need_encoding) {
        return value;
    }

    return ((value & 0x00000000000000FF) << 56) |
           ((value & 0x000000000000FF00) << 40) |
           ((value & 0x0000000000FF0000) << 24) |
           ((value & 0x00000000FF000000) << 8)  |
           ((value & 0x000000FF00000000) >> 8)  |
           ((value & 0x0000FF0000000000) >> 24) |
           ((value & 0x00FF000000000000) >> 40) |
           ((value & 0xFF00000000000000) >> 56);
}

int8_t endian_encoding::operator()(int8_t value) const {
    return value;
}
int16_t endian_encoding::operator()(int16_t value) const {
    return (int16_t)(*this)((uint16_t)value);
}
int32_t endian_encoding::operator()(int32_t value) const {
    return (int32_t)(*this)((uint32_t)value);
}
int64_t endian_encoding::operator()(int64_t value) const {
    return (int64_t)(*this)((uint64_t)value);
}

void endian_encoding::set_need_encoding(endian_encoding_type need_encoding) {
    this->need_encoding = need_encoding;
}

endian_encoding_type endian_encoding::get_host_encoding() const {
    return this->host_encoding;
}

endian_encoding_type endian_encoding::get_need_encoding() const {
    return this->need_encoding;
}