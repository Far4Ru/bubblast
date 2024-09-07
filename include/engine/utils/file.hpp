#include <iostream>
#include <fstream>

class File {
    public:
        static bool init_file(std::string name);
        File() = delete;
    private:
        static bool is_empty(std::fstream& file);
};