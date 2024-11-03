/* Тема: ООП: абстракция и инкапсуляция. Задача 2, Сортируем адреса
В этом задании вы будете читать из файла адреса и выводить их в другой файл в другом формате, отсортированными по названию города.
Вам дан файл in.txt, в котором находится N адресов. Число N идёт первым в файле. 
После числа N располагаются N блоков по 4 строки в каждом. Каждый блок состоит из следующих строк: название города, название улицы, номер дома, номер квартиры.

Задача программы заключается в том, чтобы считать адреса из файла in.txt, отсортировать их по названию города и вывести отсортированный список адресов в файл out.txt в другом формате. Не забудьте вывести количество адресов в начале.
Города должны быть отсортированы в алфавитном порядке.
Формат вывода адреса: <название города>, <название улицы>, <номер дома>, <номер квартиры>.*/

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

void sortAddress(clAddress* addresses, int size)
{
    std::string tempCity = addresses[0].get_City();
    clAddress tempAddress;

    int temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (addresses[j].get_City() > addresses[j+1].get_City()) {
                tempAddress = addresses[j];
                addresses[j] = addresses[j + 1];
                addresses[j + 1] = tempAddress;
            }
        }
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    std::string inText;
    int inNum;
    std::ifstream fileIn("in.txt");
    std::ofstream fileOut("out.txt");
    int qtyAddress = 0;
    
    if (fileIn.is_open())
    {
        fileIn >> inText;
        qtyAddress = atoi(inText.c_str());
    }
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
    
    //Сортировка
    if (qtyAddress != 0) 
    {
        sortAddress(fileAddress, qtyAddress);
    }

    //Запись в файл
    if (fileOut.is_open())
    {
        fileOut << qtyAddress << std::endl;
        for (int i = 0; i < qtyAddress; i++)
        {
            fileOut << fileAddress[i].out_address_one_line() << std::endl;
        }
    }
    fileOut.close();

    std::cout << "Работа завершена";

    delete[] fileAddress;
    return 0;
}