#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <curses.h>
#include <inttypes.h>
#include <string.h>
#include <unistd.h>

#define MIN_Y  2
#define DEL 0.1
enum {LEFT=1, UP, RIGHT, DOWN, STOP_GAME=KEY_F(10)};
enum {MAX_TAIL_SIZE=100, START_TAIL_SIZE=20, MAX_FOOD_SIZE=20, FOOD_EXPIRE_SECONDS=10};


// Здесь храним коды управления змейкой
struct control_buttons
{
    int down;
    int up;
    int left;
    int right;
}control_buttons;

struct control_buttons default_controls = {KEY_DOWN, KEY_UP, KEY_LEFT, KEY_RIGHT};


typedef struct snake_t
{
    int x;// координата x
    int y; // координата y
    int direction;// направление движения
    size_t tsize;//размер хвоста
    struct tail_t *tail;//ссылка на хваост
    struct control_buttons controls;
} snake_t;


//Хвост это массив состоящий из координат x,y
typedef struct tail_t
{
    int x;
    int y;
} tail_t;

//инициализация хвоста
void initTail(struct tail_t t[], size_t size) // отправляем массив из структур хвоста и размер самого хвоста
{
    /*struct*/ tail_t init_t={0,0};// структура из нолей
    for(size_t i=0; i<size; i++)
    {
        t[i]=init_t;// инициализируем все структуры нулями
    }
}
//Функция инициализации головы
void initHead(struct snake_t *head, int x, int y)//отправляем указатель на голову и где она находиться
{
    head->x = x;//присваиваем координатам головы текущее положении
    head->y = y;
    head->direction = RIGHT;//изначально движение вправо
}
//инициализация змеи
void initSnake(snake_t *head, size_t size, int x, int y)
{
tail_t*  tail  = (tail_t*) malloc(MAX_TAIL_SIZE*sizeof(tail_t));//выделяем память под наш массив структур хвоста
    initTail(tail, MAX_TAIL_SIZE);
    initHead(head, x, y);
    head->tail = tail; // прикрепляем к голове хвост
    head->tsize = size+1;
    head->controls = default_controls;
}

//функция проверки утыкания
int crash(struct snake_t *head)
{
    for(int i=0; i< head->tsize;i++){
        if((head->x == head->tail[i].x) && (head->y == head->tail[i].y))
        {
            mvwprintw(stdscr, 1, 0, "GAME OVER");
            return 1;
        }
    }
    return 0;
}
//Движение головы с учетом текущего направления движения
int go(struct snake_t *head)
{
    char ch = '@';
    int max_x=0, max_y=0;
    getmaxyx(stdscr, max_y, max_x); // macros - размер терминала
    //mvwprintw(stdscr, max_y-1, 0, "The number of rows - %d and columns - %d\n", max_y, max_x); // размер терминала
    mvprintw(head->y, head->x, " "); // очищаем один символ

    switch (head->direction)
    {
        case LEFT:
            if(head->x <= 0) // Циклическое движение, чтобы не уходить за пределы экрана
                head->x = max_x;
            mvprintw(head->y, --(head->x), "%c", ch);
        break;
        case RIGHT:
            if(head->x >= max_x)
                head->x = 0;
            mvprintw(head->y, ++(head->x), "%c", ch);
        break;
        case UP:
            if(head->y <= 0)
                head->y = max_y;
            mvprintw(--(head->y), head->x, "%c", ch);
        break;
        case DOWN:
            if(head->y >= max_y)
                head->y = 0;
            mvprintw(++(head->y), head->x, "%c", ch);
        break;
        default:
        break;
    }
    if(crash(head))
        return 1;// Возвращаем 1, если произошло столкновение
    refresh();
    return 0;
}
 //функция смены направления движения
void changeDirection(struct snake_t* snake, const int32_t key)
{
    if ((key == snake->controls.down) && (snake->direction != UP))
        snake->direction = DOWN;
    else if ((key == snake->controls.up) && (snake->direction != DOWN))
        snake->direction = UP;
    else if ((key == snake->controls.right) && (snake->direction != LEFT))
        snake->direction = RIGHT;
    else if ((key == snake->controls.left) && (snake->direction != RIGHT))
        snake->direction = LEFT;
}

 //Движение хвоста с учетом движения головы
void goTail(struct snake_t *head)
{
    char ch = '*';
    mvprintw(head->tail[head->tsize-1].y, head->tail[head->tsize-1].x, " ");
    for(size_t i = head->tsize-1; i>0; i--)
    {
        head->tail[i] = head->tail[i-1];
        if( head->tail[i].y || head->tail[i].x)
            mvprintw(head->tail[i].y, head->tail[i].x, "%c", ch);
    }
    head->tail[0].x = head->x;
    head->tail[0].y = head->y;
}

void My_timeout(double delay_sec)
{
    clock_t begin = clock();
    while((double)(clock() - begin)/CLOCKS_PER_SEC<delay_sec){}
}

int main()
{
    snake_t* snake = (snake_t*)malloc(sizeof(snake_t));//выделяем память snake это структура указатель на нашу голову и прикрепленному хвосту
    initSnake(snake,START_TAIL_SIZE,10,10);
    initscr();
    keypad(stdscr, TRUE); // Включаем F1, F2, стрелки и т.д.
    raw();                // Откдючаем line buffering
    noecho();            // Отключаем echo() режим при вызове getch
    curs_set(FALSE);    //Отключаем курсор
    mvprintw(0, 0," Use arrows for control. Press 'F10' for EXIT");
    timeout(0);    //Отключаем таймаут после нажатия клавиши в цикле
    int key_pressed=0;
    int flag_game=0; // флаг конца игры
    while( key_pressed != STOP_GAME && flag_game != 1)
    {
        key_pressed = getch(); // Считываем клавишу
        if(go(snake))
            flag_game=1; //если змея врезалась
        goTail(snake);
        My_timeout(DEL); // Задержка при отрисовке
        changeDirection(snake, key_pressed);
    }
    free(snake->tail);
    free(snake);
    endwin(); // Завершаем режим curses mod
    if(flag_game)
        printf("GAME OVER");
    return 0;
}