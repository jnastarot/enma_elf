#include "pch.h"
#include "elf_segment_io.h"

extern bool view_data(
    size_t  required_offset, size_t required_size, size_t& real_offset,
    size_t& available_size, size_t& down_oversize, size_t& up_oversize,
    size_t present_offset, size_t present_size
);