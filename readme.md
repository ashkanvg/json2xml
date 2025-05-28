# JSON to XML Converter (C++)

This is a simple C++ program that converts a JSON file to an XML file. It uses:

- [`nlohmann/json`](https://github.com/nlohmann/json) – for parsing JSON
- [`pugixml`](https://pugixml.org/) – for writing XML

---

## 📦 Dependencies

You can install both libraries via [Homebrew](https://brew.sh/) on macOS:

```bash
brew install nlohmann-json pugixml
```

Alternatively, you can use the source files directly (see below).

---

## 🛠️ Build Instructions

### Option A – Using Homebrew-installed Libraries

```bash
g++ -std=c++17 main.cpp -o json2xml \
  -I/opt/homebrew/opt/nlohmann-json/include \
  -I/opt/homebrew/opt/pugixml/include \
  -L/opt/homebrew/opt/pugixml/lib -lpugixml
```

### Option B – Using Local Headers and Source Files

1. Download:
   - [`json.hpp`](https://github.com/nlohmann/json/releases/latest/download/json.hpp)
   - [`pugixml.hpp`](https://raw.githubusercontent.com/zeux/pugixml/master/src/pugixml.hpp)
   - [`pugixml.cpp`](https://raw.githubusercontent.com/zeux/pugixml/master/src/pugixml.cpp)

2. Place them in the same folder as `main.cpp`.

3. Compile:
```bash
g++ -std=c++17 main.cpp pugixml.cpp -o json2xml
```

---

## 🚀 Usage

```bash
./json2xml input.json output.xml
```

Example:
```bash
./json2xml sample.json result.xml
```

---

## 📂 Example Input (`sample.json`)

```json
{
  "name": "Ashkan",
  "age": 28,
  "skills": ["C++", "Python", "XML"]
}
```

## 📄 Example Output (`result.xml`)

```xml
<root>
  <name>Ashkan</name>
  <age>23</age>
  <skills>
    <item>C++</item>
    <item>Python</item>
    <item>XML</item>
  </skills>
</root>
```

---

## 📌 Notes

- Arrays are written as repeated `<item>` nodes — you can change it in the code.
- The root XML element is always named `<root>` — you can change it in the code.
- For large files, this implementation loads everything into memory. For massive JSON files, consider a streaming parser (e.g. [cuJSON](https://github.com/ashkanvg/cuJSON), [simdjson](https://github.com/simdjson/simdjson)).

---
