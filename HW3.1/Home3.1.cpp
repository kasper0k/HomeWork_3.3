/* Тема: ООП: абстракция и инкапсуляция. Задача 1, Адреса
В этом задании вы будете читать адреса из файла и выводить их в другой файл в другом формате.
Вам дан файл in.txt, в котором находится N адресов. Число N идёт первым в файле.
После числа N располагаются N блоков по 4 строки в каждом.
Каждый блок состоит из следующих строк: название города, название улицы, номер дома, номер квартиры.

Задача программы заключается в том, чтобы считать адреса из файла in.txt
и вывести их в файл out.txt в другом формате и в обратном порядке. Не забудьте вывести количество адресов в начале.

Формат вывода адреса: <название города>, <название улицы>, <номер дома>, <номер квартиры>. */

#include <iostream>
#include <string>
#include <fstream>

class clAddress
{
private:
    std::string City;
    std::string Street;
    int HomeNum;
    int AppartmentNum;

public:
    std::string get_City() { return City; }
    std::string get_Street() { return Street; }
    int get_HomeNum() { return HomeNum; }
    int get_AppartmentNum() { return AppartmentNum; }
    void set_City(std::string newCity) { City = newCity; }
    void set_Streer(std::string newStreet) { Street = newStreet; }
    void set_HomeNum(int newHomeNum) { HomeNum = newHomeNum; }
    void set_AppartmentNum(int newAppartmentNum) { AppartmentNum = newAppartmentNum; }

    //Конструкторы
    clAddress()
    {
        City = "Москва";
        Street = "Большая Садовая";
        HomeNum = 302;
        AppartmentNum = 50;
    }

    //Методы
    std::string out_address_one_line()
    {
        return this->City + ", " + this->Street + ", " + std::to_string(this->HomeNum) + ", " + std::to_string(this->AppartmentNum);
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    std::string inText;
    int inNum;
    std::ifstream fileIn("in.txt");
    std::ofstream fileOut("out.txt");

    fileIn >> inText;
    int qtyAddress = atoi(inText.c_str());
    clAddress* fileAddress = new clAddress[qtyAddress];

    //Заполнение из файла
    if (fileIn.is_open())
    {
        while (std::getline(fileIn, inText)) {
            for (int i = 0; i < qtyAddress; i++)
            {
                fileIn >> inText;
                fileAddress[i].set_City(inText);
                fileIn >> inText;
                fileAddress[i].set_Streer(inText);
                fileIn >> inNum;
                fileAddress[i].set_HomeNum(inNum);
                fileIn >> inNum;
                fileAddress[i].set_AppartmentNum(inNum);

            }
        }
    }
    fileIn.close();

    //Запись в файл
    if (fileOut.is_open())
    {
        fileOut << qtyAddress << std::endl;
        for (int i = (qtyAddress - 1); i >= 0; i--)
        {
            fileOut << fileAddress[i].out_address_one_line() << std::endl;
        }
    }
    fileOut.close();

    std::cout << "Работа завершена";
    delete[] fileAddress;
    return 0;
}