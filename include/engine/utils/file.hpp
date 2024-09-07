#include <iostream>
#include <fstream>

class File {
    public:
        bool init_file(std::string name);
    private:
        bool is_empty(std::fstream& file);
};