#include<iostream>
#include<utility>
#include<vector>
#include<unordered_set>
using namespace std;



vector<string> GetSentence(string& text) {
    string str;
    vector<string> res;
    bool inside_quotes = false; // ����Ƿ���������

    for (size_t i = 0; i < text.size(); i++) {
        char ch = text[i];

        // ��������ţ��л�״̬
        //if (ch == '"' || ch == '\'' || ch == '��' || ch == '��') {
        //    inside_quotes = !inside_quotes; // �л�״̬
        //}

        // �������з�
        if (ch == '\n' || ch == '\'' || ch == '"') {
            continue;
        }

        str += ch; // ����ַ�����ǰ����

        if (str == " ") { str.clear(); }

        // ����Ƿ�Ϊ���ӽ������������������ڣ�
        if (/*!inside_quotes && */(ch == '.' || ch == '!' || ch == '?')) {
            //if (text[i + 1] == '\'' || text[i + 1] == '"') { i++; str += text[i]; }
            res.push_back(str); // ��Ӿ���
            str.clear();        // ���õ�ǰ����
        }
    }

    // ������һ��
    if (!str.empty()) {
        res.push_back(str);
    }

    return res;
}




vector<pair<string, int>> GetWord(vector<string>& text) {
    int size = text.size();
    vector<pair<string, int>> res;

    // ������Ҫ���Եķ���
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
                continue;  // ���Է���
            }
            if (ch == ' ') {
                if (!str.empty()) {  // ����ǰ����
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
        if (!str.empty()) {  // ������ĩ�����һ������
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
    for (int i = 0; i < W.size(); i++) {  // ����vector
        int Hash_Value = DJBHash(W[i].first, Hash_Size);  // ��ϣ����

        bool dirtyall = false;
        bool dirtyfirst = false;

        // ����list
        for (auto& j : Hash_Table[Hash_Value]) {
            if (j.first == W[i].first) {  // �ҵ���ͬ�ĵ��ʼ�
                for (auto k : j.second) {
                    if (k == W[i].second) {
                        dirtyall = true;  // �õ��ʵĸþ��ӱ���Ѿ�����
                    }
                }

                if (!dirtyall) {
                    dirtyfirst = true;  // Ѱ�ҵ���ͬ���ʼ��������ӱ��ͬ
                }
            }
        }

        if (dirtyall) {
            continue;  // ������ʱ�ž���ͬ������
        }

        if (dirtyfirst) {  // ���������ͬ���Ӳ�ͬ���ϲ����ӱ��
            for (auto& iter : Hash_Table[Hash_Value]) {
                if (iter.first == W[i].first) {
                    iter.second.push_back(W[i].second);  // ��Ӿ��ӱ��
                }
            }
        }

        if (!dirtyall && !dirtyfirst) {  // ���ʶ�û�ҵ�
            vector<int> array{ W[i].second };  // ����һ���µļ�
            pair<string, vector<int>> P{ W[i].first, array };  
            Hash_Table[Hash_Value].push_back(P);  // ���� pair �����ϣ��
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