#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <locale>
#include <codecvt> 
#include <chrono>
#include "HeadChi.hpp"

using namespace std;

void Chinese_Engine() {
    cout << "欢迎访问俊杰搜索引擎4.0(中文版)" << endl;
    cout << "                        由Maxwell开发" << endl;
    cout << endl;

    cout << "矢勤矢勇，止戈长白" << endl;
    cout << endl;

    // 设置全局区域（支持宽字符）
    locale::global(locale(""));

    // 文件路径
    string filePath = "testChi.txt";

    auto start = std::chrono::high_resolution_clock::now();

    // 读取文件内容
    wstring text = readTextFromFile(filePath); // 宽字符

    cout << "提供的输入文件已经成功打开。" << endl;

    vector<wstring> S = GetSentenceChi(text);
    vector<pair<wchar_t, int>> W = GetWordChi(S);

    int Hash_Size = static_cast<int>(W.size() * 0.75);
    if (Hash_Size % 2 == 0) {
        Hash_Size++;
    }

    vector<list<pair<wchar_t, vector<int>>>> Hash_Table(Hash_Size);

    InsertChi(Hash_Table, W, Hash_Size);

    cout << "搜索引擎部署完毕，请输入关键词" << endl;
    cout << endl;

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    cout << "准备时间: " << elapsed.count() << " 秒" << endl;

    vector<wchar_t> keywords;
    wstring keyword_input;

    // 清空缓冲区
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // 清除残留的换行符

    // 使用 getline 读取整行输入
    getline(wcin, keyword_input);  // 使用 getline 读取一行输入

    auto start1 = std::chrono::high_resolution_clock::now();

    // 将输入的每个字符转换为关键词
    for (wchar_t c : keyword_input) {
        keywords.push_back(c); // 将每个字符添加到 keywords
    }

    cout << endl;

    vector<int> Possi = Hash_SearchChi(Hash_Table, keywords, Hash_Size);

    vector<int> fail = { -1 };
    if (Possi == fail) {
        cout << "查找失败，该文件中未搜索到指定关键词。" << endl;
        return;
    }

    bool finalsuccess = false;
    for (auto i : Possi) {
        if (contains_substring(S[i], keywords)) {
            wcout << S[i] << endl;
            cout << endl;
            finalsuccess = true;
        }
    }

    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed1 = end1 - start1;
    cout << "查找时间: " << elapsed1.count() << " 秒" << endl;

    if (finalsuccess) {
        cout << "查找完毕，请阅览以上数据。" << endl;
    }
    else {
        cout << "查找失败，该文件中未搜索到指定关键词。" << endl;
    }
    return;
}

