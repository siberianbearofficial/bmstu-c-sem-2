import ctypes

_lib_array = ctypes.CDLL("./libarray.so", mode=ctypes.RTLD_LOCAL)

_filter_array = _lib_array.filter_array
_filter_array.argtypes = (ctypes.POINTER(ctypes.c_int), ctypes.c_int,
                          ctypes.POINTER(ctypes.c_int), ctypes.c_int)
_filter_array.restype = ctypes.c_int

_shift_array = _lib_array.shift_array
_shift_array.argtypes = (ctypes.POINTER(ctypes.c_int), ctypes.c_int, ctypes.c_int)
_shift_array.restype = None


def filter_array(array, reserve_memory=False):
    """
    Копирует в dst полные квадраты из src, если позволяет размер выходного массива.
    :param array: Входной массив.
    :param reserve_memory: Если передано истинное значение, выделяет память с запасом, иначе вызывает функцию дважды.
    :return:
    """

    src = (ctypes.c_int * len(array))(*array)
    dst = (ctypes.c_int * len(array))()

    if reserve_memory:
        dst_len = _filter_array(dst, len(array), src, len(array))
    else:
        dst_len = _filter_array(None, 0, src, len(array))
        if dst_len > 0:
            _filter_array(dst, dst_len, src, len(array))

    return list(dst)[:dst_len]


def shift_array(array, k):
    """
    Сдвигает массив циклически на k позиций влево.
    :param array: Массив для сдвига.
    :param k: Количество позиций, на которые нужно сдвинуть.
    :return:
    """

    tmp = (ctypes.c_int * len(array))(*array)
    _shift_array(tmp, len(array), k)
    tmp = list(tmp)
    return tmp
