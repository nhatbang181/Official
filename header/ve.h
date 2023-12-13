#pragma once
#include "phong.h"
class ve
{
private:
    string id;
    int giave;
    now ngaydat;
    string bap;
    string nuoc;
    suatchieu sc;
    string ghengoi;
public:
    ve();
    ve(now, string, string, suatchieu, string);
    ~ve();
    string getid();
    string gettenphim();
    int getgiave();
    Time getngayxem();
    int tinh_tien_bap(const string&);
    int tinh_tien_nuoc(const string&);
    now getngaydat();
    string getbap();
    string getnuoc();
    suatchieu getsc();
    string getghengoi();
    void setid(string);
    void setgiave(int);
    void setngayxem(Time);
    void setngaydat(Time);
    void setbap(string);
    void setnuoc(string);
    void setsc(suatchieu);
    void setghengoi(string);
    bool operator==(ve);
    void writeve(string);
    friend ostream& operator<<(ostream&, ve);
    ve operator=(ve);
    friend class maychu;
};