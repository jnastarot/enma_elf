#pragma once

#include "elf_segment.h"
#include "elf_section.h"

class elf_image {

    elf_image_status image_status;

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

    std::vector<elf_segment*> segments;
    std::vector<elf_section*> sections;


    void init_from_file(const uint8_t* image, size_t size);
public :
    elf_image();
    elf_image(const elf_image& image);
    elf_image(const uint8_t* raw_image, uint32_t size);
    elf_image(const std::string& file_path);
    ~elf_image();

    elf_image& operator=(const elf_image& image);
public:
    elf_section& add_section();
    elf_section& add_section(const elf32_shdr& hdr);
    elf_section& add_section(const elf64_shdr& hdr);

    elf_segment& add_segment();
    elf_segment& add_segment(const elf32_phdr& hdr);
    elf_segment& add_segment(const elf64_phdr& hdr);
    elf_segment& add_segment(const elf32_phdr& hdr, const std::vector<uint8_t>& data);
    elf_segment& add_segment(const elf64_phdr& hdr, const std::vector<uint8_t>& data);

public:
    elf_image& set_image_status(elf_image_status status);

    elf_image& set_e_ident(unsigned char _byte, uint8_t idx);
    elf_image& set_e_type(uint16_t e_type);
    elf_image& set_e_machine(uint16_t e_machine);
    elf_image& set_e_version(uint32_t e_version);
    elf_image& set_e_entry(uint64_t e_entry);
    elf_image& set_e_phoff(uint64_t e_phoff);
    elf_image& set_e_shoff(uint64_t e_shoff);
    elf_image& set_e_flags(uint32_t e_flags);
    elf_image& set_e_ehsize(uint16_t e_ehsize);
    elf_image& set_e_phentsize(uint16_t e_phentsize);
    elf_image& set_e_phnum(uint16_t e_phnum);
    elf_image& set_e_shentsize(uint16_t e_shentsize);
    elf_image& set_e_shnum(uint16_t e_shnum);
    elf_image& set_e_shstrndx(uint16_t e_shstrndx);

public:
    elf_image_status get_image_status() const;

    unsigned char get_e_ident(uint8_t idx) const;
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

    std::vector<elf_segment*>& get_segments();
    const std::vector<elf_segment*>& get_segments() const;
    std::vector<elf_section*>& get_sections();
    const std::vector<elf_section*>& get_sections() const;
public://util
    void clear_image();
};

