// OOP_L3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include "List.h"

class Test {
protected:
    int value;
public:
    Test() {
        value = 5;
    }
    void setValue(int value) {
        this->value = value;
    }
    int getValue() {
        return value;
    }
};



int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "RUS");
    List<Test> list;

    int itternum = 100;
    int count = 0;
    while (count < 3) {
        long double time_spent = 0;
        clock_t begin = clock();
        for (int i = 0; i < itternum; i++) {
            switch (rand() % 3) {
                int r;
            case 0:
                if (list.getSize() == 0)
                    r = 0;
                else
                    r = rand() % (list.getSize());
                list.Del(r);
                break;
            case 1:
                switch (rand() % 3) {
                case 0:
                    if (list.getSize() == 0)
                        r = 0;
                    else
                        r = rand() % (list.getSize());
                    list.Add(new Test(), r);
                    break;
                case 1:
                    list.push(new Test());
                    break;
                case 2:
                    list.push_back(new Test());
                    break;
                }
                break;
            case 2:
                switch (rand() % 3) {
                case 0:
                    list.getSize();
                    break;
                case 1:
                    if (list.getSize() == 0)
                        r = 0;
                    else
                        r = rand() % (list.getSize());
                    list.Set(new Test(), r);
                    break;
                case 2:
                    if (list.getSize() == 0)
                        r = 0;
                    else
                        r = rand() % (list.getSize());
                    list.get(r).getValue();
                    break;
                }
                break;
            }

        }
        clock_t end = clock();
        time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
        printf("Итераций: %d; Время: %lf seconds\n", itternum, time_spent);
        count++;
        itternum *= 10;
    }
}
