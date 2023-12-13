#include "phong.h"
#include<iostream>
phong::phong() {
    idphong = "A";
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 11; j++) {
            ghengoi[i][j] = false;
        }
    }
}
phong::~phong() {
}
string phong::getidphong() {
    return idphong;
}

bool phong::getghengoi(int i, int j)
{
    return ghengoi[i][j];
}
suatchieu phong::getsuat(int i)
{
    return suat[i];
}
void phong::operator=(phong p) {
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 11; j++) {
            ghengoi[i][j] = p.getghengoi(i, j);
        }
    }
    for (int i = 0; i < 8; i++) {
        suat[i] = p.getsuat(i);
    }
    idphong = p.getidphong();
}
void phong::setghengoi(int i, int j, bool o)
{
    this->ghengoi[i][j] = o;
}
void phong::setidphong(string s) { this->idphong = s; }
void phong::setsuat(int i, suatchieu sc) { this->suat[i] = sc; }
void phong::hienthighe()
{
    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 14; j++)
        {
            if (ghengoi[i][j] == true)
            {
                std::cout << (char)(i + 65) << j << " (Sold) ";
            }
            else
            {
                std::cout << (char)(i + 65) << j << " (Trong)"
                    << " ";
            }
        }
        std::cout << std::endl;
    }
}
