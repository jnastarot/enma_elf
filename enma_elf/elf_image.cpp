#include "pch.h"
#include "elf_image.h"


elf_image::elf_image() {

}
elf_image::elf_image(const elf_image& image) {
    this->operator=(image);
}
elf_image::elf_image(const uint8_t* raw_image, uint32_t size) {
    clear_image();
    init_from_file(raw_image, size);
}
elf_image::elf_image(const std::string& file_path) {
    clear_image();

    FILE* hfile = fopen(file_path.c_str(), "rb");


    if (hfile != nullptr) {
        fseek(hfile, 0, SEEK_END);
        size_t file_size = ftell(hfile);
        fseek(hfile, 0, SEEK_SET);

        uint8_t* file_buffer = new uint8_t[file_size];


        if (fread(file_buffer, file_size, 1, hfile)) {

            init_from_file(file_buffer, file_size);
        }
        else {
            image_status = elf_image_status_bad_format;
        }

        delete[] file_buffer;

        fclose(hfile);
    }
    else {
        image_status = elf_image_status_unknown;
    }
}
elf_image::~elf_image() {
    clear_image();
}


elf_image& elf_image::operator=(const elf_image& image) {


    return *this;
}

elf_section& elf_image::add_section() {

    sections.push_back(new elf_section());

    return *sections.back();
}
elf_section& elf_image::add_section(const elf32_shdr& hdr) {

    elf_section& section = add_section();

    endian_encoding encoder(this->e_ident[EI_DATA]);

    section.set_sh_name(encoder(hdr.sh_name))
        .set_sh_type(encoder(hdr.sh_type))
        .set_sh_flags(encoder(hdr.sh_flags))
        .set_sh_addr(encoder(hdr.sh_addr))
        .set_sh_offset(encoder(hdr.sh_offset))
        .set_sh_size(encoder(hdr.sh_size))
        .set_sh_link(encoder(hdr.sh_link))
        .set_sh_info(encoder(hdr.sh_info))
        .set_sh_addralign(encoder(hdr.sh_addralign))
        .set_sh_entsize(encoder(hdr.sh_entsize));


    return section;
}
elf_section& elf_image::add_section(const elf64_shdr& hdr) {

    elf_section& section = add_section();

    endian_encoding encoder(this->e_ident[EI_DATA]);

    section.set_sh_name(encoder(hdr.sh_name))
        .set_sh_type(encoder(hdr.sh_type))
        .set_sh_flags(encoder(hdr.sh_flags))
        .set_sh_addr(encoder(hdr.sh_addr))
        .set_sh_offset(encoder(hdr.sh_offset))
        .set_sh_size(encoder(hdr.sh_size))
        .set_sh_link(encoder(hdr.sh_link))
        .set_sh_info(encoder(hdr.sh_info))
        .set_sh_addralign(encoder(hdr.sh_addralign))
        .set_sh_entsize(encoder(hdr.sh_entsize));

    return section;
}

elf_segment& elf_image::add_segment() {

    segments.push_back(new elf_segment());

    return *segments.back();
}
elf_segment& elf_image::add_segment(const elf32_phdr& hdr) {
    
    elf_segment& segment = add_segment();

    endian_encoding encoder(this->e_ident[EI_DATA]);

    segment.set_p_type(encoder(hdr.p_type))
        .set_p_offset(encoder(hdr.p_offset))
        .set_p_vaddr(encoder(hdr.p_vaddr))
        .set_p_paddr(encoder(hdr.p_paddr))
        .set_p_filesz(encoder(hdr.p_filesz))
        .set_p_memsz(encoder(hdr.p_memsz))
        .set_p_flags(encoder(hdr.p_flags))
        .set_p_align(encoder(hdr.p_align));

    return segment;
}
elf_segment& elf_image::add_segment(const elf64_phdr& hdr) {

    elf_segment& segment = add_segment();

    endian_encoding encoder(this->e_ident[EI_DATA]);

    segment.set_p_type(encoder(hdr.p_type))
        .set_p_offset(encoder(hdr.p_offset))
        .set_p_vaddr(encoder(hdr.p_vaddr))
        .set_p_paddr(encoder(hdr.p_paddr))
        .set_p_filesz(encoder(hdr.p_filesz))
        .set_p_memsz(encoder(hdr.p_memsz))
        .set_p_flags(encoder(hdr.p_flags))
        .set_p_align(encoder(hdr.p_align));

    return segment;
}
elf_segment& elf_image::add_segment(const elf32_phdr& hdr, const std::vector<uint8_t>& data) {
    return add_segment(hdr).set_segment_data(data);
}
elf_segment& elf_image::add_segment(const elf64_phdr& hdr, const std::vector<uint8_t>& data) {
    return add_segment(hdr).set_segment_data(data);
}

template <typename image_format>
bool init_elf_header(elf_image& image, const uint8_t* raw_image) {

    image_format* p_header = (image_format*)raw_image;

    endian_encoding encoder(p_header->e_ident[EI_DATA]);


    image.set_e_ident(p_header->e_ident[0], 0)
        .set_e_ident(p_header->e_ident[1], 1)
        .set_e_ident(p_header->e_ident[2], 2)
        .set_e_ident(p_header->e_ident[3], 3)
        .set_e_ident(p_header->e_ident[4], 4)
        .set_e_ident(p_header->e_ident[5], 5)
        .set_e_ident(p_header->e_ident[6], 6)
        .set_e_ident(p_header->e_ident[7], 7)
        .set_e_ident(p_header->e_ident[8], 8)
        .set_e_ident(p_header->e_ident[9], 9)
        .set_e_ident(p_header->e_ident[10], 10)
        .set_e_ident(p_header->e_ident[11], 11)
        .set_e_ident(p_header->e_ident[12], 12)
        .set_e_ident(p_header->e_ident[13], 13)
        .set_e_ident(p_header->e_ident[14], 14)
        .set_e_ident(p_header->e_ident[15], 15)
        .set_e_type(encoder(p_header->e_type))
        .set_e_machine(encoder(p_header->e_machine))
        .set_e_version(encoder(p_header->e_version))
        .set_e_entry(encoder(p_header->e_entry))
        .set_e_phoff(encoder(p_header->e_phoff))
        .set_e_shoff(encoder(p_header->e_shoff))
        .set_e_flags(encoder(p_header->e_flags))
        .set_e_ehsize(encoder(p_header->e_ehsize))
        .set_e_phentsize(encoder(p_header->e_phentsize))
        .set_e_phnum(encoder(p_header->e_phnum))
        .set_e_shentsize(encoder(p_header->e_shentsize))
        .set_e_shnum(encoder(p_header->e_shnum))
        .set_e_shstrndx(encoder(p_header->e_shstrndx));

    return true;
}


template <typename image_format>
bool init_elf_segments(elf_image& image, const uint8_t* raw_image, size_t raw_size) {

    if (image.get_e_phoff() + image.get_e_phentsize() * image.get_e_phnum() > raw_size) {
        return false;
    }

    image_format* p_segment = (image_format*)&raw_image[image.get_e_phoff()];
    endian_encoding encoder(image.get_e_ident(EI_DATA));

   
    for (size_t segment_idx = 0; 
        segment_idx < image.get_e_phnum();
        segment_idx++, p_segment = (image_format*)((uint8_t*)p_segment + image.get_e_phentsize()) ) {

        if (raw_size < p_segment->p_offset + p_segment->p_filesz) {
            return false;
        }

        std::vector<uint8_t> seg_data;
        seg_data.resize(p_segment->p_filesz);

        memcpy(seg_data.data(), &raw_image[p_segment->p_offset], p_segment->p_filesz);

        image.add_segment(*p_segment, seg_data);
    }

    return true;
}

template <typename image_format>
bool init_elf_sections(elf_image& image, const uint8_t* raw_image, size_t raw_size) {

    if (image.get_e_shoff() + image.get_e_shentsize() * image.get_e_shnum() > raw_size) {
        return false;
    }

    image_format* p_section = (image_format*)& raw_image[image.get_e_shoff()];
    endian_encoding encoder(image.get_e_ident(EI_DATA));


    for (size_t section_idx = 0;
        section_idx < image.get_e_shnum();
        section_idx++, p_section = (image_format*)((uint8_t*)p_section + image.get_e_shentsize())) {

        image.add_section(*p_section);
    }

    return true;
}

void elf_image::init_from_file(const uint8_t* image, size_t size) {

    if (size < EI_NIDENT) {
        image_status = elf_image_status_bad_format;
        return;
    }

    if (image[EI_CLASS] == ELFCLASS32) {

        if (!init_elf_header<elf32_ehdr>(*this, image)) {

            image_status = elf_image_status_bad_format;
            return;
        }

        if (!init_elf_sections<elf32_shdr>(*this, image, size)) {

            image_status = elf_image_status_bad_format;
            return;
        }

        if (!init_elf_segments<elf32_phdr>(*this, image, size)) {

            image_status = elf_image_status_bad_format;
            return;
        }

    }
    else if (image[EI_CLASS] == ELFCLASS64) {

        if (!init_elf_header<elf64_ehdr>(*this, image)) {

            image_status = elf_image_status_bad_format;
            return;
        }

        if (!init_elf_sections<elf64_shdr>(*this, image, size)) {

            image_status = elf_image_status_bad_format;
            return;
        }

        if (!init_elf_segments<elf64_phdr>(*this, image, size)) {

            image_status = elf_image_status_bad_format;
            return;
        }
    }
    else {

        image_status = elf_image_status_bad_format;
        return;
    }


    for (auto& section : sections) {
        cout << std::hex << section->get_sh_name() << "\t"
            //  << std::hex << section->get_sh_type() << "\t"
            << std::hex << section->get_sh_flags() << "\t"
            << std::hex << section->get_sh_addr() << "\t"
            << std::hex << section->get_sh_offset() << "\t"
            << std::hex << section->get_sh_link() << "\t"
            << std::hex << section->get_sh_info() << "\t"
            << std::hex << section->get_sh_addralign() << "\t"
            << std::hex << section->get_sh_entsize() << "\t" << endl;
    }

    cout << endl << endl;

    for (auto& segment : segments) {
        cout //<< std::hex << segment->get_p_type() << "\t"
            << std::hex << segment->get_p_offset() << "\t"
            << std::hex << segment->get_p_vaddr() << "\t"
            << std::hex << segment->get_p_paddr() << "\t"
            << std::hex << segment->get_p_filesz() << "\t"
            << std::hex << segment->get_p_memsz() << "\t"
            << std::hex << segment->get_p_flags() << "\t"
            << std::hex << segment->get_p_align() << "\t" << endl;
    }

   
    image_status = elf_image_status_ok;
}


elf_image& elf_image::set_image_status(elf_image_status status) {
    this->image_status = status;

    return *this;
}
elf_image& elf_image::set_e_ident(unsigned char _byte, uint8_t idx) {

    if (idx >= 0 && idx < EI_NIDENT) {
        this->e_ident[idx] = _byte;
    }

    return *this;
}
elf_image& elf_image::set_e_type(uint16_t e_type) {
    this->e_type = e_type;

    return *this;
}
elf_image& elf_image::set_e_machine(uint16_t e_machine) {
    this->e_machine = e_machine;

    return *this;
}
elf_image& elf_image::set_e_version(uint32_t e_version) {
    this->e_version = e_version;

    return *this;
}
elf_image& elf_image::set_e_entry(uint64_t e_entry) {
    this->e_entry = e_entry;

    return *this;
}
elf_image& elf_image::set_e_phoff(uint64_t e_phoff) {
    this->e_phoff = e_phoff;

    return *this;
}
elf_image& elf_image::set_e_shoff(uint64_t e_shoff) {
    this->e_shoff = e_shoff;

    return *this;
}
elf_image& elf_image::set_e_flags(uint32_t e_flags) {
    this->e_flags = e_flags;

    return *this;
}
elf_image& elf_image::set_e_ehsize(uint16_t e_ehsize) {
    this->e_ehsize = e_ehsize;

    return *this;
}
elf_image& elf_image::set_e_phentsize(uint16_t e_phentsize) {
    this->e_phentsize = e_phentsize;

    return *this;
}
elf_image& elf_image::set_e_phnum(uint16_t e_phnum) {
    this->e_phnum = e_phnum;

    return *this;
}
elf_image& elf_image::set_e_shentsize(uint16_t e_shentsize) {
    this->e_shentsize = e_shentsize;

    return *this;
}
elf_image& elf_image::set_e_shnum(uint16_t e_shnum) {
    this->e_shnum = e_shnum;

    return *this;
}
elf_image& elf_image::set_e_shstrndx(uint16_t e_shstrndx) {
    this->e_shstrndx = e_shstrndx;

    return *this;
}

elf_image_status elf_image::get_image_status() const {
    return this->image_status;
}

unsigned char elf_image::get_e_ident(uint8_t idx) const {

    if (idx >= 0 && idx < EI_NIDENT) {
        return this->e_ident[idx];
    }
    else {
        return 0;
    }
}
uint16_t  elf_image::get_e_type() const {
    return this->e_type;
}
uint16_t  elf_image::get_e_machine() const {
    return this->e_machine;
}
uint32_t  elf_image::get_e_version() const {
    return this->e_version;
}
uint64_t  elf_image::get_e_entry() const {
    return this->e_entry;
}
uint64_t  elf_image::get_e_phoff() const {
    return this->e_phoff;
}
uint64_t  elf_image::get_e_shoff() const {
    return this->e_shoff;
}
uint32_t  elf_image::get_e_flags() const {
    return this->e_flags;
}
uint16_t  elf_image::get_e_ehsize() const {
    return this->e_ehsize;
}
uint16_t  elf_image::get_e_phentsize() const {
    return this->e_phentsize;
}
uint16_t  elf_image::get_e_phnum() const {
    return this->e_phnum;
}
uint16_t  elf_image::get_e_shentsize() const {
    return this->e_shentsize;
}
uint16_t  elf_image::get_e_shnum() const {
    return this->e_shnum;
}
uint16_t  elf_image::get_e_shstrndx() const {
    return this->e_shstrndx;
}

void elf_image::clear_image() {
    this->image_status = elf_image_status_unknown;

    memset(e_ident, 0, sizeof(e_ident));

    this->e_type = 0;
    this->e_machine = 0;
    this->e_version = 0;
    this->e_entry = 0;
    this->e_phoff = 0;
    this->e_shoff = 0;
    this->e_flags = 0;
    this->e_ehsize = 0;
    this->e_phentsize = 0;
    this->e_phnum = 0;
    this->e_shentsize = 0;
    this->e_shnum = 0;
    this->e_shstrndx = 0;
}