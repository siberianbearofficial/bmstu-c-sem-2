//Решение этой задачи размещается в папке lab_04_01. В функции main следует
//сравнить поведение реализованных функций1 и функций из стандартной библиотеки.
//От студента ожидается ровно один функциональный тест в этой задаче — на
//вход ничего не подаётся, файл pos_01_in.txt пуст, на экран следует распечатывать
//количество проваленных сравнений поведения реализованных функций и функций
//стандартной библиотеки.
//Требуется самостоятельно реализовать аналоги следующих строковых функций:
//0. strpbrk;
//1. strspn;
//2. strcspn;
//3. strchr;
//4. strrchr.
//Сигнатура аналога должна совпадать с сигнатурой оригинала с точностью до
//имени, к именам аналогов следует прибавлять префикс «my_», например, свой аналог
//функции strpbrk следует объявлять не иначе, как my_strpbrk.

#include "main.h"

int main(void)
{
    int count = 0;
    for (int i = 0; i < 100; i++)
    {
        char reject[] = "                              ";
        for (int j = 0; j < 29; j++)
            reject[j] = (char) (i + j);
        char s[] = "01234Abcsfhywgjewkyqegwhkfjyitghekwf2873482732t383yewfduhvjeafdshhkfj5667898765678";

        char *etalon1 = strpbrk(s, reject);
        char *my_res1 = my_strpbrk(s, reject);
//        printf("%d %d\n", etalon, my_res);
        if (etalon1 != my_res1)
            count++;

        size_t etalon2 = strspn(s, reject);
        size_t my_res2 = my_strspn(s, reject);
//        printf("%d %d\n", etalon, my_res);
        if (etalon2 != my_res2)
            count++;

        size_t etalon3 = strcspn(s, reject);
        size_t my_res3 = my_strcspn(s, reject);
//        printf("%d %d\n", etalon, my_res);
        if (etalon3 != my_res3)
            count++;

        char *etalon4 = strchr(s, i);
        char *my_res4 = my_strchr(s, i);
//        printf("%d %d\n", etalon, my_res);
        if (etalon4 != my_res4)
            count++;

        char *etalon5 = strrchr(s, i);
        char *my_res5 = my_strrchr(s, i);
//        printf("%d %d\n", etalon, my_res);
        if (etalon5 != my_res5)
            count++;
    }
    printf("%d", count);
    return count > 0;
}
