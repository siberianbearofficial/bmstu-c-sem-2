#ifndef ARRAY_H
#define ARRAY_H

/**
 * Копирует в dst полные квадраты из src, если позволяет размер выходного массива.
 * @param dst Входной массив.
 * @param dst_len Размер входного массива.
 * @param src Выходной массив.
 * @param src_len Размер выходного массива.
 * @return Требуемый размер выходного массива.
 */
int filter_array(int *dst, int dst_len, int *src, int src_len);

/**
 * Сдвигает массив циклически на k позиций влево.
 * @param arr Массив для сдвига.
 * @param arr_len Размер массива.
 * @param k Количество позиций, на которые нужно сдвинуть.
 */
void shift_array(int *arr, int arr_len, int k);

#endif //ARRAY_H
