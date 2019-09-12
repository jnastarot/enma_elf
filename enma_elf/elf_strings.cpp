#include "pch.h"
#include "elf_strings.h"



elf_strings_table::elf_strings_table() {}

elf_strings_table::elf_strings_table(const elf_strings_table& table) {
    this->operator=(table);
}

elf_strings_table::~elf_strings_table() {

}

elf_strings_table& elf_strings_table::operator=(const elf_strings_table& table) {

    this->strings = table.strings;

    return *this;
}


const std::vector<std::string>& elf_strings_table::get_strings() const {
    return this->strings;
}

std::vector<std::string>& elf_strings_table::get_strings() {
    return this->strings;
}



elf_table_code get_strings_table(_In_ const elf_image& image,
    _Out_ elf_strings_table& strings) {




    return elf_table_code_success;
}