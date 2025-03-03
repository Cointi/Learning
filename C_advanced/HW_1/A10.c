#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <stdbool.h>
/*Распаковать порядок
Необходимо реализовать программу, которой на входе передаётся вещественное число в типе float,
она возвращает порядок который хранится в поле EXP в виде десятичного целого числа.
Функция должна строго соответствовать прототипу*/
// Объявление объединения
union FloatUnion {
    float f;
    struct {
#ifdef __BIG_ENDIAN__ // директива на проверяет порядок байтов компилятора (если платформа Big-endian, то поля идут в порядке sign -> exp -> mant, если Little-endian, то mant -> exp -> sign).
        uint32_t sign : 1;
        uint32_t exp : 8;
        uint32_t mant : 23;
#else
        uint32_t mant : 23;
        uint32_t exp : 8;
        uint32_t sign : 1;
#endif
    } pack;
};

// Функция для извлечения и вывода показателя степени
int extractExp(union FloatUnion fl) {
    printf("%u\n", fl.pack.exp);
    return 0;
}

int main() {
    union FloatUnion fl;

    // Ввод числа с плавающей точкой
    if (scanf("%f", &fl.f) != 1)
        return 1; // Завершаем программу с ошибкой
    extractExp(fl);

    return 0;
}
