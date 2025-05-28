
# JSON-to-XML Converter
a basic C++ example to convert a large JSON file to an XML file using the popular libraries:
- nlohmann/json for parsing JSON
- pugixml for writing XML

## Requirements
You'll need to install:
- nlohmann/json (#include <nlohmann/json.hpp>)
- pugixml (#include <pugixml.hpp>)

You can install them via your package manager or include the header-only versions.

## How to Run 
0. Install Required Libraries 
1. Compile:
   ```
    -I/opt/homebrew/opt/nlohmann-json/include \
    -I/opt/homebrew/opt/pugixml/include \
    -L/opt/homebrew/opt/pugixml/lib -lpugixml
   ```
2. Run:
   ```
    ./json2xml
   ```