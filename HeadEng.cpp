#include<iostream>
#include<utility>
#include<vector>
#include<unordered_set>
using namespace std;



vector<string> GetSentence(string& text) {
    string str;
    vector<string> res;
    bool inside_quotes = false; // 标记是否在引号内

    for (size_t i = 0; i < text.size(); i++) {
        char ch = text[i];

        // 如果是引号，切换状态
        //if (ch == '"' || ch == '\'' || ch == '“' || ch == '”') {
        //    inside_quotes = !inside_quotes; // 切换状态
        //}

        // 跳过换行符
        if (ch == '\n' || ch == '\'' || ch == '"') {
            continue;
        }

        str += ch; // 添加字符到当前句子

        if (str == " ") { str.clear(); }

        // 检测是否为句子结束符（不能在引号内）
        if (/*!inside_quotes && */(ch == '.' || ch == '!' || ch == '?')) {
            //if (text[i + 1] == '\'' || text[i + 1] == '"') { i++; str += text[i]; }
            res.push_back(str); // 添加句子
            str.clear();        // 重置当前句子
        }
    }

    // 添加最后一段
    if (!str.empty()) {
        res.push_back(str);
    }

    return res;
}




vector<pair<string, int>> GetWord(vector<string>& text) {
    int size = text.size();
    vector<pair<string, int>> res;

    // 定义需要忽略的符号
    unordered_set<char> ignored_symbols = {
        '.', '!', '?', ',', ';', ':', '\'', '"',
        '-', '(', ')', '[', ']', '{', '}', '<', '>', '/',
        '\\', '@', '#', '$', '%', '^', '&', '*', '_', '+', '=',
        '~', '|'
    };

    for (int i = 0; i < size; i++) {
        pair<string, int> temp;
        string str;
        for (auto ch : text[i]) {
            if (ignored_symbols.count(ch)) {
                continue;  // 忽略符号
            }
            if (ch == ' ') {
                if (!str.empty()) {  // 处理当前单词
                    temp.first = str;
                    temp.second = i;
                    res.push_back(temp);

                    str.clear();
                }
            }
            else {
                str += ch;
            }
        }
        if (!str.empty()) {  // 处理行末的最后一个单词
            temp.first = str;
            temp.second = i;
            res.push_back(temp);
        }
    }
    return res;
}


int DJBHash(const string& str, int Hash_Size) {
    int hash_value = 5381;
    for (char c : str) {
        hash_value = ((hash_value << 5) + hash_value + c);
    }
    return abs(hash_value % Hash_Size);
}

void Insert(vector<list<pair<string, vector<int>>>>& Hash_Table, vector<pair<string, int>>& W, int Hash_Size) {
    for (int i = 0; i < W.size(); i++) {  // 遍历vector
        int Hash_Value = DJBHash(W[i].first, Hash_Size);  // 哈希函数

        bool dirtyall = false;
        bool dirtyfirst = false;

        // 遍历list
        for (auto& j : Hash_Table[Hash_Value]) {
            if (j.first == W[i].first) {  // 找到相同的单词键
                for (auto k : j.second) {
                    if (k == W[i].second) {
                        dirtyall = true;  // 该单词的该句子编号已经存在
                    }
                }

                if (!dirtyall) {
                    dirtyfirst = true;  // 寻找到相同单词键，但句子编号同
                }
            }
        }

        if (dirtyall) {
            continue;  // 如果单词编号均相同，跳过
        }

        if (dirtyfirst) {  // 如果单词相同句子不同，合并句子编号
            for (auto& iter : Hash_Table[Hash_Value]) {
                if (iter.first == W[i].first) {
                    iter.second.push_back(W[i].second);  // 添加句子编号
                }
            }
        }

        if (!dirtyall && !dirtyfirst) {  // 单词都没找到
            vector<int> array{ W[i].second };  // 创建一个新的键
            pair<string, vector<int>> P{ W[i].first, array };  
            Hash_Table[Hash_Value].push_back(P);  // 将新 pair 插入哈希表
        }
    }
}


void Hash_Search(vector<list<pair<string, vector<int>>>>& Hash_Table, string s, vector<string> S, int Hash_Size) {
    int Hash_Value = DJBHash(s, Hash_Size);

    bool succeed = false;

    vector<int> Array;
    for (auto& i : Hash_Table[Hash_Value]) {
        if (i.first == s) {
            Array = i.second;
        }
    }

    for (auto j : Array) {
        if (j >= 0 && j < S.size()) {
            succeed = true;
            cout << S[j] << endl;
            cout << endl;
        }
        else {
            cerr << "Error: Index " << j << " is out of bounds for S." << endl;
        }
    }

    if (succeed == false) {
        cout << "Sorry, there is no sentence matching your keyword in the text." << endl;
    }

}