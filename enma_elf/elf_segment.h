#pragma once

class elf_segment {

    uint32_t  p_type;
    uint32_t  p_flags;
    uint64_t  p_offset;
    uint64_t  p_vaddr;
    uint64_t  p_paddr;
    uint64_t  p_filesz;
    uint64_t  p_memsz;
    uint64_t  p_align;

    std::vector<uint8_t> segment_data;

public:
    elf_segment();
    elf_segment(const elf_segment& seg);
    ~elf_segment();

    elf_segment& operator=(const elf_segment& seg);
public:
    elf_segment& set_p_type(uint32_t p_type);
    elf_segment& set_p_flags(uint32_t p_flags);
    elf_segment& set_p_offset(uint64_t p_offset);
    elf_segment& set_p_vaddr(uint64_t p_vaddr);
    elf_segment& set_p_paddr(uint64_t p_paddr);
    elf_segment& set_p_filesz(uint64_t p_filesz);
    elf_segment& set_p_memsz(uint64_t p_memsz);
    elf_segment& set_p_align(uint64_t p_align);
    elf_segment& set_segment_data(const std::vector<uint8_t>& data);

public:
    uint32_t  get_p_type() const;
    uint32_t  get_p_flags() const;
    uint64_t  get_p_offset() const;
    uint64_t  get_p_vaddr() const;
    uint64_t  get_p_paddr() const;
    uint64_t  get_p_filesz() const;
    uint64_t  get_p_memsz() const;
    uint64_t  get_p_align() const;

    std::vector<uint8_t>& get_segment_data();
    const std::vector<uint8_t>& get_segment_data() const;
};

