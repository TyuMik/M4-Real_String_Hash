#include <iostream>
#include <string>

int real_string_hash(std::string& str, int& p, int& n) {

    unsigned long long int hash, tmp;
    hash = 0;
    tmp = 1;
        
    for (int i = 0; i < str.length(); i++) {
        hash += static_cast<int>(str[i]) * tmp;
        tmp *= p;
    }
    
    return hash % n;  
}

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "Russian");
    std::string str;
    int p, n;

    std::cout << "Введите p: ";
    std::cin >> p;
    std::cout << "Введите n: ";
    std::cin >> n;

    do {
        std::cout << "Введите строку: ";
        std::cin >> str;
        std::cout << "Хэш строки " << str << ": ";
        std::cout << real_string_hash(str, p, n) << std::endl;
        std::cout << std::endl;

    } while (str != "exit");

    return 0;
}