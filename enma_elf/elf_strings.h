#pragma once

class elf_strings_table {

    std::vector<std::string> strings;


public:
    elf_strings_table();
    elf_strings_table(const elf_strings_table& table);
    ~elf_strings_table();

    elf_strings_table& operator=(const elf_strings_table& table);
public:

    const std::vector<std::string>& get_strings() const;
    std::vector<std::string>& get_strings();
};


elf_table_code get_strings_table(_In_ const elf_image& image,
    _Out_ elf_strings_table& strings);