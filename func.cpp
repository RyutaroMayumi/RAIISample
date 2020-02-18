#include "func.h"

void function1A(size_t count) {
    double* array1 = NULL;
    double* array2 = NULL;
    try {
        // 配列を動的に確保する。メモリ確保失敗により std::bad_alloc 例外がスローされる可能性がある。
        array1 = new double[count]();
        array2 = new double[count]();

        // 動的に確保した配列をここで作業領域として使用する。
        for (size_t i = 0; i < count; ++i) {
            array1[i] = i * 0.1;
            array2[i] = i * 0.1;
        }
        // ...

        // 配列を使わなくなったので削除する。
        delete[] array2;
        delete[] array1;
    }
    catch (...) {
        // 例外がスローされる場合に備える。
        delete[] array2;
        delete[] array1;
        throw; // 例外の再送出。
    }
}

void function1B(size_t count) {
    ArrayWrapper<double> array1(count);
    ArrayWrapper<double> array2(count);

    // 動的に確保した配列をここで作業領域として使用する。
    for (size_t i = 0; i < count; ++i) {
        array1[i] = i * 0.1;
        array2[i] = i * 0.1;
    }
    // ...

} // RAII 変数 array1, array2 の属するブロックを抜ける。このとき array2, array1 の各デストラクタが順に呼ばれ、それぞれが内部で管理する配列メモリ領域は自動的に破棄される。

