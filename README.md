# JunJie-5.0
JunJie 5.0 is a bio language(Chinese&amp;English) text research engine. You can easily start up it in windows.

> A dual-language (Chinese & English) keyword search engine based on hash table indexing and query processing, written in modern C++.

## ✨ Overview
This is a bilingual text search engine built as a final project for the Data Structures and Algorithms course at Sun Yat-sen University. The engine supports efficient keyword-based sentence retrieval from both Chinese and English corpora using hash table indexing. Designed with modularity and object-oriented C++ best practices in mind, this project demonstrates real-world applications of hash tables, hashing functions, and file I/O in multilingual environments.

---

## 🧠 Features
- 📚 **Support for Both Chinese and English Texts**: Handles encoding and parsing strategies specific to each language.
- 🧾 **Sentence-Level Indexing**: Retrieves complete sentences containing the queried word or phrase.
- ⚙️ **Custom Hash Table**: Built from scratch using chaining with `vector<list<>>` and specialized hash functions (DJB for English, golden ratio hashing for Chinese `wchar_t`).
- 🧪 **Performance Logging**: Includes timestamping of preprocessing and query execution time.
- 🧩 **Test Cases Provided**: Based on classic literature (e.g., *The Snows of Kilimanjaro*, *Warhammer 40k: The End and the Death III*).

---

## 🔧 Technical Architecture
```
ResearchEngine/
├── Main_All.cpp               # Entry point, user interaction and main UI
├── Chinese_Engine.cpp         # Main logic and control for Chinese mode
├── English_Engine.cpp         # Main logic and control for English mode
├── HeadChi.cpp / .hpp         # Chinese engine core logic (hashing, indexing, searching)
├── HeadEng.cpp / .hpp         # English engine core logic (hashing, indexing, searching)
├── test.txt / test2.txt       # Test datasets
└── text_form.cpp              # Utility for English text normalization
```

---

## 🧮 Algorithm Design Summary
### English Engine
- Tokenizes sentences and words
- Builds `HashTable<string, vector<int>>`
- Uses DJB hashing for good string distribution
- Searches based on exact word matches

### Chinese Engine
- Tokenizes into characters (wchar_t)
- Avoids word segmentation ambiguity
- Uses intersection of per-character inverted index vectors
- Searches sentence-level substrings only after candidate narrowing

---

## 🚀 Getting Started
### Dependencies
- C++17 or later
- Windows system with Visual Studio / g++ (with wide character support)

### Compile and Run
```bash
# Use Visual Studio or compile with g++
g++ -std=c++17 Main_All.cpp -o ResearchEngine
./ResearchEngine
```

---

## 📁 Input Format
- **Chinese input**: UTF-8 encoded `.txt` with standard punctuation
- **English input**: Cleaned `.txt` file (e.g., Hemingway's novel)

---

## 🧪 Sample Queries
| Language | Query         | Notes                               |
|----------|---------------|-------------------------------------|
| English  | `snow`        | Finds all sentences with "snow"     |
| English  | `death`       | Returns nothing (used in test case) |
| Chinese  | `帝皇`        | High-frequency term (many hits)     |
| Chinese  | `基里曼`      | Rare name (quick precise match)     |

---

## 📈 Performance Summary
| Metric               | English Corpus (~21k chars) | Chinese Corpus (~224k chars) |
|----------------------|-----------------------------|-------------------------------|
| Indexing Time        | ~0.0005s                    | ~1.2s                         |
| Query (frequent term)| ~0.001–0.05s                | ~0.5–1.5s                     |
| Query (rare term)    | ~0.0005s                    | ~0.002s                       |

---

## 🧠 Learning Highlights
This was my first full-scale program from scratch. Key takeaways:
- Correct Unicode file handling (UTF-8 vs ANSI, `wchar_t` intricacies)
- Thoughtful algorithmic design (hybrid search strategies)
- Performance engineering (hash table load factors, cache locality)
- And the joy of seeing a system come to life, quoting Belisarius Cawl:
> "There is no joy like watching your own creation think."

---

## 📜 License
This project is open-sourced for educational and non-commercial use.

---

## 📫 Contact
- 👨‍💻 Author: Tianyi Sun (孙天一)
- ✉️ Email: 2069571512@qq.com
- 🏫 Institution: Sun Yat-sen University, Class of 2023

> "矢勤矢勇，止戈长白。道阻且长，行则将至。"

---

## 💡 Slogan
> ***矢勤矢勇，止戈长白***

---
