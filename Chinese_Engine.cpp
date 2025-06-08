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
    cout << "��ӭ���ʿ�����������4.0(���İ�)" << endl;
    cout << "                        ��Maxwell����" << endl;
    cout << endl;

    cout << "ʸ��ʸ�£�ֹ�곤��" << endl;
    cout << endl;

    // ����ȫ������֧�ֿ��ַ���
    locale::global(locale(""));

    // �ļ�·��
    string filePath = "testChi.txt";

    auto start = std::chrono::high_resolution_clock::now();

    // ��ȡ�ļ�����
    wstring text = readTextFromFile(filePath); // ���ַ�

    cout << "�ṩ�������ļ��Ѿ��ɹ��򿪡�" << endl;

    vector<wstring> S = GetSentenceChi(text);
    vector<pair<wchar_t, int>> W = GetWordChi(S);

    int Hash_Size = static_cast<int>(W.size() * 0.75);
    if (Hash_Size % 2 == 0) {
        Hash_Size++;
    }

    vector<list<pair<wchar_t, vector<int>>>> Hash_Table(Hash_Size);

    InsertChi(Hash_Table, W, Hash_Size);

    cout << "�������沿����ϣ�������ؼ���" << endl;
    cout << endl;

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    cout << "׼��ʱ��: " << elapsed.count() << " ��" << endl;

    vector<wchar_t> keywords;
    wstring keyword_input;

    // ��ջ�����
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // ��������Ļ��з�

    // ʹ�� getline ��ȡ��������
    getline(wcin, keyword_input);  // ʹ�� getline ��ȡһ������

    auto start1 = std::chrono::high_resolution_clock::now();

    // �������ÿ���ַ�ת��Ϊ�ؼ���
    for (wchar_t c : keyword_input) {
        keywords.push_back(c); // ��ÿ���ַ���ӵ� keywords
    }

    cout << endl;

    vector<int> Possi = Hash_SearchChi(Hash_Table, keywords, Hash_Size);

    vector<int> fail = { -1 };
    if (Possi == fail) {
        cout << "����ʧ�ܣ����ļ���δ������ָ���ؼ��ʡ�" << endl;
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
    cout << "����ʱ��: " << elapsed1.count() << " ��" << endl;

    if (finalsuccess) {
        cout << "������ϣ��������������ݡ�" << endl;
    }
    else {
        cout << "����ʧ�ܣ����ļ���δ������ָ���ؼ��ʡ�" << endl;
    }
    return;
}

