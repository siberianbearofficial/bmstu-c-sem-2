/*
Программа выполняет следующие действия над двоичным файлом целых чисел int:

- Генерация файла со случайным количеством случайных чисел из промежутка [0, 100).
Команда: app.exe c file_name.bin

- Вывод чисел из файла.
Команда: app.exe p file_name.bin

- Сортировка пузырьком по возрастанию.
Команда: app.exe s file_name.bin
*/

#include "main.h"

int main(int argc, char **argv)
{
    int exit_code = process(argc, argv);    
    return exit_code;
}
