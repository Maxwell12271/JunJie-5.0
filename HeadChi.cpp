#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <utility>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <locale>
#include <codecvt> // ��ʹ�� C++17 ����Ͱ汾��Ҫ��ͷ�ļ�

using namespace std;



// ����������
wstring readTextFromFile(const string& filePath)
{
    wifstream file(filePath);
    // �����ļ���ʹ�� UTF-8 ����
    file.imbue(locale(locale::empty(), new codecvt_utf8<wchar_t>));

    if (!file.is_open())
    {
        wcerr << L"�޷����ļ�: " << wstring(filePath.begin(), filePath.end()) << endl;
        exit(1);
    }

    wstringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

vector<wstring> GetSentenceChi(wstring& text) {
    wstring str;
    vector<wstring> res;
    bool inside_quotes = false;  // ����״̬
    int open_paren_count = 0;    // ��������
    int open_bracket_count = 0; 
    int open_brace_count = 0;    

    for (size_t i = 0; i < text.size(); i++) {
        wchar_t ch = text[i];

        // �л�����״̬
        if (ch == L'��' || ch == L'��' || ch == L'��' || ch == L'��') {
            inside_quotes = !inside_quotes;  
        }

        // ����ƥ��
        if (ch == L'(') open_paren_count++;
        if (ch == L')') open_paren_count--;
        if (ch == L'[') open_bracket_count++;
        if (ch == L']') open_bracket_count--;
        if (ch == L'{') open_brace_count++;
        if (ch == L'}') open_brace_count--;

        str += ch;

        if (str == L"\n") { str.clear(); }

        // ��������ո���з�������������һ���ַ�
        if (ch == L' ' || ch == L'\n') {
            continue;
        }

        // ��������־���Ų��Ҹþ��Ӳ������Ż������У�����ƥ����ɣ��ͷ־�
        if (!inside_quotes && open_paren_count == 0 && open_bracket_count == 0 && open_brace_count == 0 &&
            (ch == L'��' || ch == L'��' || ch == L'��')) {

            // ����ź��Ƿ������š�
            if (i + 1 < text.size() && (text[i + 1] == L'��' || text[i + 1] == L'��' || text[i + 1] == L'��' || text[i + 1] == L'��')) {
                i++;  
                str += text[i];  
            }
            else {
               
                res.push_back(str);
                str.clear();
            }
        }
    }

    // ���һ�����Ӽ�����
    if (!str.empty()) {
        res.push_back(str);
    }

    return res;
}




vector<pair<wchar_t, int>> GetWordChi(vector<wstring>& S) {
    vector<pair<wchar_t, int>> res;
    pair<wchar_t, int> temp;

    unordered_set<wchar_t> ignored_symbols = {
        // ����ȫ�Ǳ�����
        L'��', L'��', L'��', L'��', L'��', L'��', L'��', L'��', L'��', L'��', L'��',
        L'��', L'��', L'��', L'��', L'��', L'��', L'��', L'��', L'��', L'��', L'��', L'��',
        L'����', L'��', L'��', L'��', L'�n', L'��',

        // ������Ƿ���
        L'.', L'!', L'?', L',', L';', L':', L'\'', L'"',
        L'-', L'(', L')', L'[', L']', L'{', L'}', L'<', L'>', L'/',
        L'\\', L'@', L'#', L'$', L'%', L'^', L'&', L'*', L'_', L'+', L'=',
        L'~', L'|'
    };

    for (int i = 0; i < S.size(); i++) {
        for (auto j : S[i]) {
            if (ignored_symbols.count(j) || j == ' ') {
                continue;
            }

            temp.first = j;
            temp.second = i;

            res.push_back(temp);
        }
    }
    return res;

}

int HashFunction(wchar_t key, int Hash_Size) {
    double A = 0.6180339887; // �˷�����
    double frac = key * A - (int)(key * A); // ȡС��
    return (int)(Hash_Size * frac);
}


void InsertChi(vector<list<pair<wchar_t, vector<int>>>>& Hash_Table, vector<pair<wchar_t, int>>& W, int Hash_Size) {
    for (auto& i : W) {

        int Hash_Value = HashFunction(i.first, Hash_Size);

        bool dirty = false;

        for (auto& j : Hash_Table[Hash_Value]) {

            if (j.first == i.first) {
                dirty = true;
                auto it = find(j.second.begin(), j.second.end(), i.second);
                if (it != j.second.end()) {
                    break;
                }
                else {
                    j.second.push_back(i.second);
                }
            }
        }

        if (dirty == false) {
            vector<int> Arr = { i.second };
            pair<wchar_t, vector<int>> temp = { i.first, Arr };
            Hash_Table[Hash_Value].push_back(temp);
        }
    }
}

std::vector<int> IntersectionOfVectors(const std::vector<std::vector<int>>& store) {
    if (store.empty()) return {};  // ���ؿ�����

    // ��һ������������ʼֵ
    std::vector<int> res = store[0];

    // ����
    std::sort(res.begin(), res.end());

    // �󽻼�
    for (size_t i = 1; i < store.size(); ++i) {
        std::vector<int> temp;
        std::vector<int> sortedStore = store[i];
        std::sort(sortedStore.begin(), sortedStore.end());

        // �����������Ľ���
        std::set_intersection(res.begin(), res.end(), sortedStore.begin(), sortedStore.end(),
            std::back_inserter(temp));
        res = temp;  // ���½��
        if (res.empty()) break;  // �������Ϊ�գ�ֱ������
    }

    // �������Ϊ�գ����� {-1}
    if (res.empty()) {
        return { -1 };
    }

    return res;
}


vector<int> Hash_SearchChi(vector<list<pair<wchar_t, vector<int>>>>& Hash_Table, vector<wchar_t> keywords, int Hash_Size)
{
    vector<vector<int>> store;
    vector<int> res;
    bool succeed = false;

    for (auto k : keywords) { 
        int Hash_Value = HashFunction(k, Hash_Size); // �����ϣֵ
        bool insertsucceed = false;

        // ������Ӧ��ϣֵ������
        for (const auto& i : Hash_Table[Hash_Value]) {
            if (i.first == k) { 
                store.push_back(i.second); 
                succeed = true;
                insertsucceed = true;
            }
        }
        if (insertsucceed == false) { return { -1 }; }
    }


    res = IntersectionOfVectors(store);
    if (succeed == false) { res = { -1 }; }

    return res;
}


bool contains_substring(const wstring& str, const vector<wchar_t>& sub_vec) {
    // �� vector<wchar_t> ת���� wstring
    wstring sub_str(sub_vec.begin(), sub_vec.end());

    // �������ַ���
    if (str.find(sub_str) != wstring::npos) {
        return true;  // �ҵ��Ӵ�
    }
    else {
        return false;  // û���ҵ��Ӵ�
    }
}