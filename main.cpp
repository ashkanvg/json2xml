#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include <pugixml.hpp>

using json = nlohmann::json;
using namespace std;

// Recursive function to convert JSON to XML nodes
void json_to_xml(const json& j, pugi::xml_node& node) {
    if (j.is_object()) {
        for (auto& [key, value] : j.items()) {
            pugi::xml_node child = node.append_child(key.c_str());
            json_to_xml(value, child);
        }
    } else if (j.is_array()) {
        for (const auto& item : j) {
            pugi::xml_node child = node.append_child("item");
            json_to_xml(item, child);
        }
    } else {
        node.append_child(pugi::node_pcdata).set_value(j.dump().c_str());
    }
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: json2xml input.json output.xml" << std::endl;
        return 1;
    }

    // Load JSON from file
    std::ifstream input(argv[1]);
    if (!input.is_open()) {
        std::cerr << "Failed to open JSON file: " << argv[1] << std::endl;
        return 1;
    }

    json j;
    try {
        input >> j;
    } catch (const std::exception& e) {
        std::cerr << "Error parsing JSON: " << e.what() << std::endl;
        return 1;
    }

    // Create XML document
    pugi::xml_document doc;
    pugi::xml_node root = doc.append_child("root");

    json_to_xml(j, root);

    // Save XML
    if (!doc.save_file(argv[2], "  ")) {
        std::cerr << "Failed to write XML to: " << argv[2] << std::endl;
        return 1;
    }

    std::cout << "Conversion complete: " << argv[2] << std::endl;
    return 0;
}
