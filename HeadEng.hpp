#ifndef CHINESEENGINE_HPP
#define CHINESEENGINE_HPP

#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <utility>

void English_Engine();


// ��ȡ���ӣ�����š���̾�š��ʺŷ־䣩
std::vector<std::string> GetSentence(std::string& text);

// ��ȡ���ʼ������ھ��ӱ��
std::vector<std::pair<std::string, int>> GetWord(std::vector<std::string>& text);

// DJB2 ��ϣ����
int DJBHash(const std::string& str, int Hash_Size);

// ���뵥�ʵ���ϣ��
void Insert(std::vector<std::list<std::pair<std::string, std::vector<int>>>>& Hash_Table,
    std::vector<std::pair<std::string, int>>& W, int Hash_Size);

// ���ҹؼ��ʶ�Ӧ�ľ���
void Hash_Search(std::vector<std::list<std::pair<std::string, std::vector<int>>>>& Hash_Table,
    std::string s, std::vector<std::string> S, int Hash_Size);

#endif // CHINESEENGINE_HPP
