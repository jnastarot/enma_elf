#pragma once

class elf_segment {

    uint32_t  sh_name;
    uint32_t  sh_type;
    uint64_t  sh_flags;
    uint64_t  sh_addr;
    uint64_t  sh_offset;
    uint32_t  sh_link;
    uint32_t  sh_info;
    uint64_t  sh_addralign;
    uint64_t  sh_entsize;

    std::vector<uint8_t> segment_data;

public:
    elf_segment();
    ~elf_segment();


public:


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

