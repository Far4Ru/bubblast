#include <fstream>

#include "engine/engine.hpp"

class ResultsTable {
    public:
        ResultsTable();
        ~ResultsTable();
    private:
        std::vector<std::pair<int, std::string>> table_values;
        std::vector<TextObject*> lines;

        void get_file_data();
        void make_table();
};