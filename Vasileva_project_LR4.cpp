// Vasileva Ekaterina
#include <iostream>
#include <limits>
#include <string>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <random>
#include <set>
#include <cstring>
#include <typeinfo>
#include <functional>
#include <map>
using namespace std;

const int infinity = std::numeric_limits<int>::max();

struct MenuItem
{
    string title; // название пункта меню
    function <void()> action; // действие, выполняемое при выборе пункта
};

bool UserInput (string input){
    // если строка пустая, то ввод некорректен
    if(input.empty()) return false;

    // попытка
    try {
        // преобразование введённого значения  в тип int 
        int number  = stoi(input);
    }

    catch (...) // если возникла ошибка в блоке try
    {return false;}
    return true;

}

function <void()> EnterNumber (int& varlink, string label){
    return [&varlink, label](){
        string raw_input;
        cout << label << " = ";
        getline(cin, raw_input);

        while (!UserInput(raw_input)){
            cout << label << " = ";
            getline(cin, raw_input);
        }
        varlink = stoi(raw_input);
    };
}

int q, p;

void InputQ (){
    EnterNumber (q, "Введите Q: ")();
    cout << "Q: " << q << endl;
}

void IntputP (){
    
}

void modQonP (){
    
}

void divQonP (){
    
}


int main() {
    map<int, MenuItem> menu = {
        {1, {"Ввести целое число Q", InputQ} },
        {2, {"Ввести натуральное число P (меньше Q)", IntputP}},
        {3, {"Найти остаток от деления Q на P", modQonP}},
        {4, {"Найти целую часть от деления Q на P", divQonP}}
    };

    int choice = 0;

    while (true)
    {
        cout << "Меню:" << endl;

        for (const auto& item : menu){
            cout << "Task " << item.first << ". " << item.second.title << endl;

        }

        cout << "0. Выход" << endl; 

        EnterNumber (choice, "Введите номер пункта: ")();

        if (choice == 0){
            cout << "@ 2025 Ekaterina Vasileva" << endl;
            break;
        }

        cout << endl;

        if (menu.find(choice) != menu.end()) {
            menu[choice].action();
        }
        else{
            cout << "Некорректный ввод. ";
        }

        cout << endl << endl;

    }
    return 0; 

}
