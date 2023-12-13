#pragma once
#include "phim.h"
class phong
{
private:
    string idphong;
    bool ghengoi[7][11];
    suatchieu suat[8];
public:
    phong();
    ~phong();
    string getidphong();
    bool getghengoi(int, int);
    suatchieu getsuat(int);
    void setidphong(string);
    void setghengoi(int, int, bool);
    void setsuat(int, suatchieu);
    void hienthighe();
    void operator= (phong);
    friend class admin;
    friend class rap;
    friend class suatchieu;
};