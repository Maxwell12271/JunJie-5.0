#ifndef CHINESEENGINE_HPP
#define CHINESEENGINE_HPP

#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <utility>

void English_Engine();


// 获取句子（按句号、感叹号、问号分句）
std::vector<std::string> GetSentence(std::string& text);

// 获取单词及其所在句子编号
std::vector<std::pair<std::string, int>> GetWord(std::vector<std::string>& text);

// DJB2 哈希函数
int DJBHash(const std::string& str, int Hash_Size);

// 插入单词到哈希表
void Insert(std::vector<std::list<std::pair<std::string, std::vector<int>>>>& Hash_Table,
    std::vector<std::pair<std::string, int>>& W, int Hash_Size);

// 查找关键词对应的句子
void Hash_Search(std::vector<std::list<std::pair<std::string, std::vector<int>>>>& Hash_Table,
    std::string s, std::vector<std::string> S, int Hash_Size);

#endif // CHINESEENGINE_HPP
