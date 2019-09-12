#pragma once


class elf_image_full {

    elf_image image;
    elf_dynamics_table dynamics;
    elf_relocations_table relocations;
    elf_strings_table strings;
    elf_notes_table notes;
    elf_symbols_table symbols;

public:
    elf_image_full();
    elf_image_full(const elf_image& image);
    ~elf_image_full();

public:



};

