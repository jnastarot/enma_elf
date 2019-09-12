#include "pch.h"
#include "elf_image_io.h"

bool view_data( //-> true if data or path of data is available or can be used trought adding size
    size_t  required_offset, size_t required_size, size_t& real_offset,
    size_t& available_size, size_t& down_oversize, size_t& up_oversize,
    size_t present_offset, size_t present_size) {


    //         ...............
    //  .............................
    //  |    | |             |      |
    //  v    v |             |      |
    // (down_oversize)       |      |
    //         |             |      |
    //         v             v      |
    //         (available_size)     |
    //                       |      |
    //                       v      v
    //                       (up_oversize)

    real_offset = 0;
    available_size = 0;
    down_oversize = 0;
    up_oversize = 0;

    if (required_offset < present_offset) {
        down_oversize = (present_offset - required_offset);

        if (down_oversize >= required_size) {

            return false; //not in bounds
        }
        else {
            available_size = (required_size - down_oversize);

            if (available_size > present_size) {
                up_oversize = (available_size - present_size);
                available_size = present_size;

                return true;//partially in bounds
            }

            return true;//partially in bounds
        }
    }
    else {//if(required_offset >= present_offset)

        if (required_offset <= (present_offset + present_size)) {
            real_offset = (required_offset - present_offset);

            if (required_size + required_offset > (present_offset + present_size)) {
                up_oversize = (required_size + required_offset) - (present_offset + present_size);
                available_size = required_size - up_oversize;

                return true; //partially in bounds
            }
            else {
                available_size = required_size;

                return true; //full in bounds
            }
        }
        else {
            real_offset = (required_offset - present_offset + present_size);
            up_oversize = (required_size + required_offset) - (present_offset + present_size);
            available_size = 0;

            return true; //trough full adding size 
        }
    }

    return true;
}