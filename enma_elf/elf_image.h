#pragma once

#include "elf_segment.h"

class elf_image {

    elf_image_status status;

    unsigned char e_ident[EI_NIDENT];
    uint16_t  e_type;
    uint16_t  e_machine;
    uint32_t  e_version;
    uint64_t  e_entry;
    uint64_t  e_phoff;
    uint64_t  e_shoff;
    uint32_t  e_flags;
    uint16_t  e_ehsize;
    uint16_t  e_phentsize;
    uint16_t  e_phnum;
    uint16_t  e_shentsize;
    uint16_t  e_shnum;
    uint16_t  e_shstrndx;

    void init_from_file(const uint8_t* image, size_t size);
public :
    elf_image();
    ~elf_image();

public:


public:
    elf_image_status get_status() const;

    //unsigned char get_e_ident[EI_NIDENT];
    uint16_t  get_e_type() const;
    uint16_t  get_e_machine() const;
    uint32_t  get_e_version() const;
    uint64_t  get_e_entry() const;
    uint64_t  get_e_phoff() const;
    uint64_t  get_e_shoff() const;
    uint32_t  get_e_flags() const;
    uint16_t  get_e_ehsize() const;
    uint16_t  get_e_phentsize() const;
    uint16_t  get_e_phnum() const;
    uint16_t  get_e_shentsize() const;
    uint16_t  get_e_shnum() const;
    uint16_t  get_e_shstrndx() const;

};

