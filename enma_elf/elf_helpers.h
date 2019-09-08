#pragma once

enum endian_encoding_type {
    ENDIAN_ENCODING_LITTLE,
    ENDIAN_ENCODING_BIG,
};

class endian_encoding {

    endian_encoding_type host_encoding;
    endian_encoding_type need_encoding;


public:
    endian_encoding();
    endian_encoding(endian_encoding_type need_encoding);
    endian_encoding(uint32_t elf_data_type);
    ~endian_encoding();

    endian_encoding& operator=(const endian_encoding& _encoding);
public:
    uint8_t operator()(uint8_t value) const;
    uint16_t operator()(uint16_t value) const;
    uint32_t operator()(uint32_t value) const;
    uint64_t operator()(uint64_t value) const;

    int8_t operator()(int8_t value) const;
    int16_t operator()(int16_t value) const;
    int32_t operator()(int32_t value) const;
    int64_t operator()(int64_t value) const;

public:
    void set_need_encoding(endian_encoding_type need_encoding);
    
public:
    endian_encoding_type get_host_encoding() const;
    endian_encoding_type get_need_encoding() const;
};