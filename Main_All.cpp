#include <iostream>
#include "HeadChi.hpp"
#include "HeadEng.hpp"

using namespace std;

int main() {


    cout << "���������ɹ�����ӭʹ�ÿ���5.0˫����������ϵͳ" << endl;
    cout << "The program has started successfully, welcome to the Junjie 5.0 bilingual search engine system" << endl;
    cout << endl;
    cout << "��ȷ������ļ�·����������Ӣ����λ���һ���ļ�" << endl;
    cout << "Please confirm your file path and do not mix Chinese and English paragraphs into one file" << endl;
    cout << endl;
    cout << endl;

    int choose = -1;

    cout << "��ѡ������汾�����İ�������1��Ӣ�İ���Ϊ0���˳�������-1��" << endl;
    cout << "Please select engine version, Chinese version please enter 1; The English version is 0; To exit, enter -1." << endl;
    cout << endl;
    cout << "�����߲���ѧǳ�����в���֮����������" << endl;
    cout << endl;

    cin >> choose;

    if (choose != -1)cout << "���ڽ����ӳ���......" << endl;
    cout << endl;
    cout << endl;

    if (choose == 1) {   
        Chinese_Engine();  // ����Chinese_Engine����
        return 0;
    }

    if (choose == 0) {
        English_Engine();  // ����English_Engine����
        return 0;
    }

    

    if (choose == -1) {
        return -1;  // �˳�
    }
}
