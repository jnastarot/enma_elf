#include "pch.h"
#include "elf_section.h"


elf_section::elf_section()
    : sh_name(0), sh_type(0), sh_flags(0), sh_addr(0),
    sh_offset(0), sh_link(0), sh_info(0),
    sh_addralign(0), sh_entsize(0) {}

elf_section::elf_section(const elf_section& section) {
    this->operator=(section);
}
elf_section::~elf_section() {

}

elf_section& elf_section::operator=(const elf_section& section) {

    this->sh_name = section.sh_name;
    this->sh_type = section.sh_type;
    this->sh_flags = section.sh_flags;
    this->sh_addr = section.sh_addr;
    this->sh_offset = section.sh_offset;
    this->sh_link = section.sh_link;
    this->sh_info = section.sh_info;
    this->sh_addralign = section.sh_addralign;
    this->sh_entsize = section.sh_entsize;
 
    return *this;
}

elf_section& elf_section::set_sh_name(uint32_t sh_name) {
    this->sh_name = sh_name;

    return *this;
}
elf_section& elf_section::set_sh_type(uint32_t sh_type) {
    this->sh_type = sh_type;

    return *this;
}
elf_section& elf_section::set_sh_flags(uint64_t sh_flags) {
    this->sh_flags = sh_flags;

    return *this;
}
elf_section& elf_section::set_sh_addr(uint64_t sh_addr) {
    this->sh_addr = sh_addr;

    return *this;
}
elf_section& elf_section::set_sh_offset(uint64_t sh_offset) {
    this->sh_offset = sh_offset;

    return *this;
}
elf_section& elf_section::set_sh_size(uint64_t sh_size) {
    this->sh_size = sh_size;

    return *this;
}
elf_section& elf_section::set_sh_link(uint32_t sh_link) {
    this->sh_link = sh_link;

    return *this;
}
elf_section& elf_section::set_sh_info(uint32_t sh_info) {
    this->sh_info = sh_info;

    return *this;
}
elf_section& elf_section::set_sh_addralign(uint64_t sh_addralign) {
    this->sh_addralign = sh_addralign;

    return *this;
}
elf_section& elf_section::set_sh_entsize(uint64_t sh_entsize) {
    this->sh_entsize = sh_entsize;

    return *this;
}

uint32_t  elf_section::get_sh_name() const {
    return this->sh_name;
}
uint32_t  elf_section::get_sh_type() const {
    return this->sh_type;
}
uint64_t  elf_section::get_sh_flags() const {
    return this->sh_flags;
}
uint64_t  elf_section::get_sh_addr() const {
    return this->sh_addr;
}
uint64_t  elf_section::get_sh_offset() const {
    return this->sh_offset;
}
uint64_t  elf_section::get_sh_size() const {
    return this->sh_size;
}
uint32_t  elf_section::get_sh_link() const {
    return this->sh_link;
}
uint32_t  elf_section::get_sh_info() const {
    return this->sh_info;
}
uint64_t  elf_section::get_sh_addralign() const {
    return this->sh_addralign;
}
uint64_t  elf_section::get_sh_entsize() const {
    return this->sh_entsize;
}