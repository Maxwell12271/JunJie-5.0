#ifndef HEADCHI_HPP
#define HEADCHI_HPP

#include <string>
#include <vector>
#include <list>
#include <unordered_set>
#include <utility>

void Chinese_Engine();

// 读取文本文件
std::wstring readTextFromFile(const std::string& filePath);

// 中文文本分句（按句号、感叹号、问号分割句子）
std::vector<std::wstring> GetSentenceChi(std::wstring& text);

// 获取中文文本中的词（忽略符号）
std::vector<std::pair<wchar_t, int>> GetWordChi(std::vector<std::wstring>& S);

// 哈希函数，针对中文字符
int HashFunction(wchar_t key, int Hash_Size);

// 插入中文单词到哈希表
void InsertChi(std::vector<std::list<std::pair<wchar_t, std::vector<int>>>>& Hash_Table,
    std::vector<std::pair<wchar_t, int>>& W, int Hash_Size);

// 查找多个关键词的交集
std::vector<int> Hash_SearchChi(std::vector<std::list<std::pair<wchar_t, std::vector<int>>>>& Hash_Table,
    std::vector<wchar_t> keywords, int Hash_Size);

// 判断字符串是否包含某个子字符串
bool contains_substring(const std::wstring& str, const std::vector<wchar_t>& sub_vec);

#endif // HEADCHI_HPP
