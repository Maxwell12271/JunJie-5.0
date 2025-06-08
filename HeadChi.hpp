#ifndef HEADCHI_HPP
#define HEADCHI_HPP

#include <string>
#include <vector>
#include <list>
#include <unordered_set>
#include <utility>

void Chinese_Engine();

// ��ȡ�ı��ļ�
std::wstring readTextFromFile(const std::string& filePath);

// �����ı��־䣨����š���̾�š��ʺŷָ���ӣ�
std::vector<std::wstring> GetSentenceChi(std::wstring& text);

// ��ȡ�����ı��еĴʣ����Է��ţ�
std::vector<std::pair<wchar_t, int>> GetWordChi(std::vector<std::wstring>& S);

// ��ϣ��������������ַ�
int HashFunction(wchar_t key, int Hash_Size);

// �������ĵ��ʵ���ϣ��
void InsertChi(std::vector<std::list<std::pair<wchar_t, std::vector<int>>>>& Hash_Table,
    std::vector<std::pair<wchar_t, int>>& W, int Hash_Size);

// ���Ҷ���ؼ��ʵĽ���
std::vector<int> Hash_SearchChi(std::vector<std::list<std::pair<wchar_t, std::vector<int>>>>& Hash_Table,
    std::vector<wchar_t> keywords, int Hash_Size);

// �ж��ַ����Ƿ����ĳ�����ַ���
bool contains_substring(const std::wstring& str, const std::vector<wchar_t>& sub_vec);

#endif // HEADCHI_HPP
