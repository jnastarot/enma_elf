#include "pch.h"
#include "elf_segment.h"


elf_segment::elf_segment() 
 : p_type(0), p_flags(0), p_offset(0), p_vaddr(0),
    p_paddr(0), p_filesz(0), p_memsz(0),
    p_align(0) {}

elf_segment::elf_segment(const elf_segment& seg) {
    this->operator=(seg);
}
elf_segment::~elf_segment() {

}

elf_segment& elf_segment::operator=(const elf_segment& seg) {

    this->p_type = seg.p_type;
    this->p_flags = seg.p_flags;
    this->p_offset = seg.p_offset;
    this->p_vaddr = seg.p_vaddr;
    this->p_paddr = seg.p_paddr;
    this->p_filesz = seg.p_filesz;
    this->p_memsz = seg.p_memsz;
    this->p_align = seg.p_align;

    this->segment_data = seg.segment_data;

    return *this;
}

elf_segment& elf_segment::set_p_type(uint32_t p_type) {
    this->p_type = p_type;

    return *this;
}
elf_segment& elf_segment::set_p_flags(uint32_t p_flags) {
    this->p_flags = p_flags;

    return *this;
}
elf_segment& elf_segment::set_p_offset(uint64_t p_offset) {
    this->p_offset = p_offset;

    return *this;
}
elf_segment& elf_segment::set_p_vaddr(uint64_t p_vaddr) {
    this->p_vaddr = p_vaddr;

    return *this;
}
elf_segment& elf_segment::set_p_paddr(uint64_t p_paddr) {
    this->p_paddr = p_paddr;

    return *this;
}
elf_segment& elf_segment::set_p_filesz(uint64_t p_filesz) {
    this->segment_data.resize(p_filesz);

    return *this;
}
elf_segment& elf_segment::set_p_memsz(uint64_t p_memsz) {
    this->p_memsz = p_memsz;

    return *this;
}
elf_segment& elf_segment::set_p_align(uint64_t p_align) {
    this->p_align = p_align;

    return *this;
}
elf_segment& elf_segment::set_segment_data(const std::vector<uint8_t>& data) {
    this->segment_data = data;

    return *this;
}

uint32_t  elf_segment::get_p_type() const {
    return this->p_type;
}
uint32_t  elf_segment::get_p_flags() const {
    return this->p_flags;
}
uint64_t  elf_segment::get_p_offset() const {
    return this->p_offset;
}
uint64_t  elf_segment::get_p_vaddr() const {
    return this->p_vaddr;
}
uint64_t  elf_segment::get_p_paddr() const {
    return this->p_paddr;
}
uint64_t  elf_segment::get_p_filesz() const {
    return this->segment_data.size();
}
uint64_t  elf_segment::get_p_memsz() const {
    return this->p_memsz;
}
uint64_t  elf_segment::get_p_align() const {
    return this->p_align;
}

std::vector<uint8_t>& elf_segment::get_segment_data() {
    return this->segment_data;
}
const std::vector<uint8_t>& elf_segment::get_segment_data() const {
    return this->segment_data;
}