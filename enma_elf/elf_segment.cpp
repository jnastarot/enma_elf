#include "pch.h"
#include "elf_segment.h"


elf_segment::elf_segment() {

}

elf_segment::~elf_segment() {

}


uint32_t  elf_segment::get_sh_name() const {
    return this->sh_name;
}
uint32_t  elf_segment::get_sh_type() const {
    return this->sh_type;
}
uint64_t  elf_segment::get_sh_flags() const {
    return this->sh_flags;
}
uint64_t  elf_segment::get_sh_addr() const {
    return this->sh_addr;
}
uint64_t  elf_segment::get_sh_offset() const {
    return this->sh_offset;
}
uint64_t  elf_segment::get_sh_size() const {
    return this->segment_data.size();
}
uint32_t  elf_segment::get_sh_link() const {
    return this->sh_link;
}
uint32_t  elf_segment::get_sh_info() const {
    return this->sh_info;
}
uint64_t  elf_segment::get_sh_addralign() const {
    return this->sh_addralign;
}
uint64_t  elf_segment::get_sh_entsize() const {
    return this->sh_entsize;
}