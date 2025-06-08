#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>
#include <chrono>
#include "HeadEng.hpp"

using namespace std;

void English_Engine() {
    system("chcp 65001");

    auto start = std::chrono::high_resolution_clock::now();
    ifstream file("test.txt"); // 打开文件
    if (!file.is_open()) { // 检查是否成功打开
        cerr << "Error: Could not open the file." << endl;
        return;
    }
    ostringstream buffer;
    buffer << file.rdbuf();
    string text = buffer.str();//输入流结束，获得text字符串为存储全文。

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    cout << "Prepare time: " << elapsed.count() << " seconds" << endl;
    cout << endl;

    vector<string> S = GetSentence(text);
    vector<pair<string, int>> W = GetWord(S);

    int Hash_Size = static_cast<int>(W.size() * 0.75);
    if (Hash_Size % 2 == 0) {
        Hash_Size++;
    }

    vector<list<pair<string, vector<int>>>> Hash_Table(Hash_Size);

    Insert(Hash_Table, W, Hash_Size);

    cout << "Welcome to the JunJie research engine 3.0(for English user)!" << endl;
    cout << "                        Created by Maxwell" << endl;
    cout << endl;

    if (file.is_open()) {
        cout << "Your input file has been successfully opened." << endl;
    }
    cout << "Please enter your keywords." << endl;
    cout << endl;

    string input;
    cin >> input;
    cout << endl;

    auto start1 = std::chrono::high_resolution_clock::now();

    Hash_Search(Hash_Table, input, S, Hash_Size);

    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed1 = end1- start1;
    cout << "Execute time: " << elapsed1.count() << " seconds" << endl;
    cout << endl;

    cout << endl;
    
}
