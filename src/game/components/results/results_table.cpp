#include "game/components/results/results_table.hpp"

#define RESULTS_TABLE_LEFT_X 200
#define RESULTS_TABLE_RIGHT_X 700
#define RESULTS_TABLE_Y 250
#define RESULTS_DATA_FILENAME "results.data"
#define RESULTS_DATA_DELIMITER " - "

ResultsTable::ResultsTable() {
    get_file_data();
    make_table();
}

void ResultsTable::get_file_data() {
    std::string line;
    std::ifstream data_file(RESULTS_DATA_FILENAME);
    std::string delimiter = RESULTS_DATA_DELIMITER;
    if (data_file.is_open()) {
        while(std::getline(data_file, line)) {
            std::string name = line.substr(0, line.find(delimiter));
            std::string points = line.substr(line.find(delimiter) + delimiter.size(), line.size());
            table_values.push_back(std::pair<int, std::string>(std::stoi(points), name));
        }
        data_file.close();
    }
}

void ResultsTable::make_table() {
    int y = RESULTS_TABLE_Y;
    std::sort(table_values.begin(), table_values.end(), std::greater<std::pair<int, std::__cxx11::string>>());
    int count = 0;
    for (std::pair<int, std::string> table_value : table_values) {
        count++;
        TextObject* text = engine->add->text("WinterCat");
        text->setText(std::to_string(count) + ". " + table_value.second + " - " + std::to_string(table_value.first) + " pts");
        text->x = count <= 5 ? RESULTS_TABLE_LEFT_X : RESULTS_TABLE_RIGHT_X;
        text->y = y;
        lines.push_back(text);
        y += 50;
        if (count == 5) {
            y = RESULTS_TABLE_Y;
        }
        if (count >= 10) {
            break;
        }
    }
    std::vector<std::pair<int, std::string>>().swap(table_values);
}

ResultsTable::~ResultsTable() {
    for (TextObject* line : lines) {
        line->destroy();
    }
    std::vector<TextObject*>().swap(lines);
}
