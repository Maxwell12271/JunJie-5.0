#include <iostream>
#include "HeadChi.hpp"
#include "HeadEng.hpp"

using namespace std;

int main() {


    cout << "程序启动成功，欢迎使用俊杰5.0双语搜索引擎系统" << endl;
    cout << "The program has started successfully, welcome to the Junjie 5.0 bilingual search engine system" << endl;
    cout << endl;
    cout << "请确认你的文件路径，切勿将中英文语段混用一个文件" << endl;
    cout << "Please confirm your file path and do not mix Chinese and English paragraphs into one file" << endl;
    cout << endl;
    cout << endl;

    int choose = -1;

    cout << "请选择引擎版本，中文版请输入1；英文版则为0；退出请输入-1。" << endl;
    cout << "Please select engine version, Chinese version please enter 1; The English version is 0; To exit, enter -1." << endl;
    cout << endl;
    cout << "开发者才疏学浅，若有不足之处请多包涵。" << endl;
    cout << endl;

    cin >> choose;

    if (choose != -1)cout << "正在进入子程序......" << endl;
    cout << endl;
    cout << endl;

    if (choose == 1) {   
        Chinese_Engine();  // 调用Chinese_Engine函数
        return 0;
    }

    if (choose == 0) {
        English_Engine();  // 调用English_Engine函数
        return 0;
    }

    

    if (choose == -1) {
        return -1;  // 退出
    }
}
