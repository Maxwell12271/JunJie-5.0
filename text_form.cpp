//#include <iostream>
//#include <fstream>
//#include <string>
//#include <cctype>
//#include <unordered_set>
//using namespace std;
//
//// Function to check if a character is a valid sentence delimiter
//bool isDelimiter(char ch) {
//    return ch == '.' || ch == '!' || ch == '?';
//}
//
//// Function to check if a character is a valid ignored symbol
//bool isIgnoredSymbol(char ch) {
//    unordered_set<char> ignored_symbols = {
//        ',', ';', ':', '\'', '"',  '-',
//        '(', ')', '[', ']', '{', '}', '<', '>', '/', '@', '#',
//        '$', '%', '^', '&', '*', '_', '+', '=', '~', '|'
//    };
//    return ignored_symbols.count(ch) > 0;
//}
//
//// Function to standardize text
//string standardizeText(const string& input) {
//    string result;
//    bool inNewLine = false; // Keep track of paragraph breaks
//
//    for (size_t i = 0; i < input.size(); ++i) {
//        char ch = input[i];
//
//        // Preserve sentence delimiters
//        if (isDelimiter(ch)) {
//            result += ch;
//        }
//        // Skip ignored symbols
//        else if (isIgnoredSymbol(ch)) {
//            continue;
//        }
//        // Handle newline characters
//        else if (ch == '\n') {
//            if (!inNewLine) {
//                result += '\n';
//                inNewLine = true; // Mark that a newline was added
//            }
//        }
//        // Add other valid characters
//        else {
//            result += ch;
//            inNewLine = false; // Reset newline state on valid character
//        }
//    }
//
//    return result;
//}
//
//int main() {
//    // Input and output file paths
//    string inputFilePath = "input.txt";
//    string outputFilePath = "output.txt";
//
//    // Open input file
//    ifstream inputFile(inputFilePath);
//    if (!inputFile.is_open()) {
//        cerr << "Error: Could not open input file." << endl;
//        return 1;
//    }
//
//    // Read the entire input file
//    string inputText((istreambuf_iterator<char>(inputFile)), istreambuf_iterator<char>());
//    inputFile.close();
//
//    // Standardize the text
//    string standardizedText = standardizeText(inputText);
//
//    // Write to the output file
//    ofstream outputFile(outputFilePath);
//    if (!outputFile.is_open()) {
//        cerr << "Error: Could not open output file." << endl;
//        return 1;
//    }
//    outputFile << standardizedText;
//    outputFile.close();
//
//    cout << "Standardization complete. Output saved to " << outputFilePath << endl;
//    return 0;
//}