#include "engine/utils/file.hpp"

bool File::init_file(std::string name) {
    std::fstream file;
    bool is_empty_file;
    file.open(name, std::ios_base::out | std::ios_base::in);
    if (!file.is_open()) {
        file.clear();
        file.open(name, std::ios_base::out);
        is_empty_file = true;
    } else {
        is_empty_file = is_empty(file);
    }
    file.close();
    return is_empty_file;
}

bool File::is_empty(std::fstream& file) {
    return file.peek() == std::fstream::traits_type::eof();
}