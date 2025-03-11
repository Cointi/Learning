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


// ����� ������ ���� ���������� �������
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
    int x;// ���������� x
    int y; // ���������� y
    int direction;// ����������� ��������
    size_t tsize;//������ ������
    struct tail_t *tail;//������ �� ������
    struct control_buttons controls;
} snake_t;


//����� ��� ������ ��������� �� ��������� x,y
typedef struct tail_t
{
    int x;
    int y;
} tail_t;

//������������� ������
void initTail(struct tail_t t[], size_t size) // ���������� ������ �� �������� ������ � ������ ������ ������
{
    /*struct*/ tail_t init_t={0,0};// ��������� �� �����
    for(size_t i=0; i<size; i++)
    {
        t[i]=init_t;// �������������� ��� ��������� ������
    }
}
//������� ������������� ������
void initHead(struct snake_t *head, int x, int y)//���������� ��������� �� ������ � ��� ��� ����������
{
    head->x = x;//����������� ����������� ������ ������� ���������
    head->y = y;
    head->direction = RIGHT;//���������� �������� ������
}
//������������� ����
void initSnake(snake_t *head, size_t size, int x, int y)
{
tail_t*  tail  = (tail_t*) malloc(MAX_TAIL_SIZE*sizeof(tail_t));//�������� ������ ��� ��� ������ �������� ������
    initTail(tail, MAX_TAIL_SIZE);
    initHead(head, x, y);
    head->tail = tail; // ����������� � ������ �����
    head->tsize = size+1;
    head->controls = default_controls;
}

//������� �������� ��������
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
//�������� ������ � ������ �������� ����������� ��������
int go(struct snake_t *head)
{
    char ch = '@';
    int max_x=0, max_y=0;
    getmaxyx(stdscr, max_y, max_x); // macros - ������ ���������
    //mvwprintw(stdscr, max_y-1, 0, "The number of rows - %d and columns - %d\n", max_y, max_x); // ������ ���������
    mvprintw(head->y, head->x, " "); // ������� ���� ������

    switch (head->direction)
    {
        case LEFT:
            if(head->x <= 0) // ����������� ��������, ����� �� ������� �� ������� ������
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
        return 1;// ���������� 1, ���� ��������� ������������
    refresh();
    return 0;
}
 //������� ����� ����������� ��������
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

 //�������� ������ � ������ �������� ������
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
    snake_t* snake = (snake_t*)malloc(sizeof(snake_t));//�������� ������ snake ��� ��������� ��������� �� ���� ������ � �������������� ������
    initSnake(snake,START_TAIL_SIZE,10,10);
    initscr();
    keypad(stdscr, TRUE); // �������� F1, F2, ������� � �.�.
    raw();                // ��������� line buffering
    noecho();            // ��������� echo() ����� ��� ������ getch
    curs_set(FALSE);    //��������� ������
    mvprintw(0, 0," Use arrows for control. Press 'F10' for EXIT");
    timeout(0);    //��������� ������� ����� ������� ������� � �����
    int key_pressed=0;
    int flag_game=0; // ���� ����� ����
    while( key_pressed != STOP_GAME && flag_game != 1)
    {
        key_pressed = getch(); // ��������� �������
        if(go(snake))
            flag_game=1; //���� ���� ���������
        goTail(snake);
        My_timeout(DEL); // �������� ��� ���������
        changeDirection(snake, key_pressed);
    }
    free(snake->tail);
    free(snake);
    endwin(); // ��������� ����� curses mod
    if(flag_game)
        printf("GAME OVER");
    return 0;
}
