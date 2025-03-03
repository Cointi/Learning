#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <stdbool.h>
/*Весы
В стартер боксе Geek Brains есть электронные чашечные весы (вместимость каждой чашки 1 тонна) и гири массами 1г, 3г, 9г, 27г, и т.д.
по одной штуке каждой массы. Менеджер из рекламного отдела взял такие весы и не знает, можно ли взвесить что-нибудь тяжелое и если можно,
сколько гирь придется положить на весы (на любую чашку).
Надо помочь ему. Формат входных данных: единственное натуральное число – масса взвешиваемого товара в граммах (не больше 1000000000).
Формат выходных данных: единственное целое число – общее количество гирь или число –1 если данный товар взвесить невозможно.*/
#include <stdio.h>

int count_weights(int mass) {
    int count = 0;
    int left = 0, right = 0;  // Сумма гирь на каждой чаше
    int power = 1;  // Текущая степень 3

    while (mass > 0) {
        int remainder = mass % 3;
        if (remainder == 2) {  // 2 в тройке заменяем на -1 с переносом
            remainder = -1;
            mass += 1;
        }

        if (remainder == 1) {
            left += power;
        } else if (remainder == -1) {
            right += power;
        }

        if (left > 1000000 || right > 1000000) {
            return -1;  // Превышен лимит массы на чаше
        }

        mass /= 3;
        power *= 3;
        count += (remainder != 0);
    }

    return count;
}

int main() {
    int mass;
    scanf("%d", &mass);
    printf("%d\n", count_weights(mass));
    return 0;
}
