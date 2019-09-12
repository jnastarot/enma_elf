#pragma once


enum elf_image_status {
    elf_image_status_ok,
    elf_image_status_bad_format,
    elf_image_status_unknown,
};

enum elf_table_code {
    elf_table_code_success      = 0 << 1,
    elf_table_code_not_present  = 1 << 1,
    elf_table_code_currupted    = 1 << 2
};