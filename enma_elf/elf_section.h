#pragma once



class elf_section {

    uint32_t  sh_name;
    uint32_t  sh_type;
    uint64_t  sh_flags;
    uint64_t  sh_addr;
    uint64_t  sh_offset;
    uint64_t  sh_size;
    uint32_t  sh_link;
    uint32_t  sh_info;
    uint64_t  sh_addralign;
    uint64_t  sh_entsize;


public:
    elf_section();
    elf_section(const elf_section& section);
    ~elf_section();

    elf_section& operator=(const elf_section& section);
public:
    elf_section& set_sh_name(uint32_t sh_name);
    elf_section& set_sh_type(uint32_t sh_type);
    elf_section& set_sh_flags(uint64_t sh_flags);
    elf_section& set_sh_addr(uint64_t sh_addr);
    elf_section& set_sh_offset(uint64_t sh_offset);
    elf_section& set_sh_size(uint64_t sh_size);
    elf_section& set_sh_link(uint32_t sh_link);
    elf_section& set_sh_info(uint32_t sh_info);
    elf_section& set_sh_addralign(uint64_t sh_addralign);
    elf_section& set_sh_entsize(uint64_t sh_entsize);

public:
    uint32_t  get_sh_name() const;
    uint32_t  get_sh_type() const;
    uint64_t  get_sh_flags() const;
    uint64_t  get_sh_addr() const;
    uint64_t  get_sh_offset() const;
    uint64_t  get_sh_size() const;
    uint32_t  get_sh_link() const;
    uint32_t  get_sh_info() const;
    uint64_t  get_sh_addralign() const;
    uint64_t  get_sh_entsize() const;
};
