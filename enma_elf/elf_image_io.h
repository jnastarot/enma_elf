#pragma once

#include "elf_segment_io.h"

#ifndef ENMA_IO_DEFINES 
#define ENMA_IO_DEFINES

enum enma_io_mode {
    enma_io_mode_default,
    enma_io_mode_allow_expand,
};

enum enma_io_addressing_type {
    enma_io_address_raw,
    enma_io_address_rva,
    enma_io_address_va,
};

enum enma_io_code {
    enma_io_success,
    enma_io_incomplete, //part of read\write
    enma_io_data_not_present,
};

#endif

class elf_image_io {

    elf_image* image;
    uint32_t image_offset;

    enma_io_code last_code;
    enma_io_mode mode;
    enma_io_addressing_type addressing_type;


public:


};

