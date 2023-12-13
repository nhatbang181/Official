#include "admin.h"

admin::admin()
{

}
admin::~admin()
{
}
rap admin::getrapquanly() {
    return rapquanly;
}
void admin::setusername(string s)
{
    username = s;
}
void admin::setpassword(string s)
{
    password = s;
}
void admin::dangkitaikhoan()
{
    getline(cin, username);
    string tmppassword;
    while (true)
    {
        char ch = _getch(); // H�m getch() t? th? vi?n <conio.h> d�ng ?? nh?n m?t k� t? t? b�n ph�m m� kh�ng hi?n th? l�n m�n h�nh

        if (ch == 13)
        { // 13 t??ng ?ng v?i ph�m Enter
            break;
        }
        else if (ch == 8)
        { // 8 t??ng ?ng v?i ph�m Backspace
            if (!(tmppassword).empty())
            {
                (tmppassword).pop_back();
                cout << "\b \b"; // X�a k� t? cu?i c�ng ???c hi?n th?
            }
        }
        else
        {
            (tmppassword).push_back(ch);
            cout << "*";
        }
    }

    password = (tmppassword);
}
string admin::getusername()
{
    return username;
}
string admin::getpassword()
{
    return password;
}
void admin::xacnhandatve(int i, int j, int e, int r, int k, string name_file)
{
    int p = 0;
    int q = 0;
    int z = 0;
    rapquanly.danhsachphong[i][j][e].ghengoi[r][k] = true;

    string tmp;
    ofstream o;

    o.open(name_file, ios::trunc);
    if (!o.is_open()) return;
    while (!o.eof()) {
        o << rapquanly.danhsachphong[p][q][z].idphong << endl;
        for (int v = 0; v < 7; v++) {
            for (int m = 0; m < 11; m++) {
                o << rapquanly.danhsachphong[p][q][z].ghengoi[v][m];
            }
            o << endl;
        }
        z++;
        if (z == 8) {
            q++;
            z = 0;
            if (q == 3) {
                p++;
                if (p == 10) break;
                q = 0;
            }
        }

    }

    o.close();
}
bool admin::ktrafull(phong p)
{
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            if (p.ghengoi[i][j] == false)
                return false;
        }
    }
    return true;
}
void admin::nhapphongchieu(string name_file) {
    ifstream i;
    i.open(name_file);
    if (!i.is_open()) return;
    string tmp;
    int k = 0, j = 0, z = 0;
    int p = 0, q = 0;
    while (getline(i, tmp))
    {

        if (tmp.length() <= 3) {
            rapquanly.danhsachphong[k][j][z].idphong = tmp;
        }
        else {
            for (int t = 0; t < 11; t++) {
                rapquanly.danhsachphong[k][j][z].ghengoi[p][q] = tmp[t] - '0';
                q++;
                if (q == 11) {
                    q = 0;
                    p++;
                    if (p == 7) {
                        p = 0; q = 0;
                        z++;
                        if (z == 8) {
                            z = 0;
                            j++;
                            if (j == 3) {
                                j = 0; k++; if (k == 10) break;
                            }
                        }

                    }
                }
            }
        }
    }
    i.close();
}
void admin::writephim(phim p, const string name_file) {
    ifstream i;
    i.open(name_file);
    string tmp;
    int count = 1;
    while (getline(i, tmp))
    {
        count++;
    }
    i.close();
    ofstream o;
    o.open(name_file, ios::app);
    if (count != 1) o << endl;
    o << p.gettenphim() << endl;
    o << p.getdaodien() << endl;
    o << p.gettheloai() << endl;
    o << p.getkhoichieu().getphut() << endl;
    o << p.getkhoichieu().getgio() << endl;
    o << p.getkhoichieu().getngay() << endl;
    o << p.getkhoichieu().getthang() << endl;
    o << p.getkhoichieu().getnam() << endl;
    o << p.getthoiluong() << endl;
    o << p.getngonngu() << endl;
    o << p.getgioithieuphim() << endl;
    o << p.getage() << endl;
    o << p.getdienvien() << endl;
    o.close();
}
void admin::nhapphim(const string name_file)
{
    phim p;
    cin >> p;
    writephim(p, name_file);
}
void admin::nhapphimchuachieu(const string name_file) {
    ifstream i;
    i.open(name_file);
    string tmp;
    int count = 1;
    while (getline(i, tmp))
    {
        count++;
    }
    i.close();
    ofstream o;
    phim p;
    cin >> p;
    o.open(name_file, ios::app);
    if (count != 1) o << endl;
    o << p.gettenphim() << endl;
    o << p.getdaodien() << endl;
    o << p.gettheloai() << endl;
    o << p.getkhoichieu().getphut() << endl;
    o << p.getkhoichieu().getgio() << endl;
    o << p.getkhoichieu().getngay() << endl;
    o << p.getkhoichieu().getthang() << endl;
    o << p.getkhoichieu().getnam() << endl;
    o << p.getthoiluong() << endl;
    o << p.getngonngu() << endl;
    o << p.getgioithieuphim() << endl;
    o << p.getage() << endl;
    o << p.getdienvien() << endl;
    o.close();
}
//void admin::chuyenphimchuachieu(const string name_file1, const string name_file2) {
//    phim p;
//    ifstream i;
//    string line;
//    int count = 1;
//    i.open(name_file2, ios::in);
//    if (!i.is_open()) return;
//    while (getline(i, line)) {
//        switch (count % 13) {
//        case 0:
//            setage(line, p);
//            break;
//        case 1:
//            settenphim(line, p);
//            break;
//        case 2:
//            setgiave(ConvertToInt(line), p);
//            break;
//        case 3:
//            setdaodien(line, p);
//            break;
//        case 4:
//            settheloai(line, p);
//            break;
//        case 5:
//            setgiochieu(ConvertToInt(line), p);
//            break;
//        case 6:
//            setphutchieu(ConvertToInt(line), p);
//            break;
//        case 7:
//            setngaychieu(ConvertToInt(line), p);
//            break;
//        case 8:
//            setthangchieu(ConvertToInt(line), p);
//            break;
//        case 9:
//            setnamchieu(ConvertToInt(line), p);
//            break;
//        case 10:
//            setthoiluong(ConvertToInt(line), p);
//            break;
//        case 11:
//            setngonngu(line, p);
//            break;
//        case 12:
//            setgioithieuphim(line, p);
//            break;
//        default:
//            break;
//        }
//        count++;
//        if ((count % 13) == 1) {
//            p.sethankhoichieu();
//            
//            setid(increaseString(rapquanly.maychurap.danhsachphim[rapquanly.maychurap.sophim - 2].getid()), p);
//            themphim(p);
//        }
//    }
//    i.close();
//
//}
void admin::setid(string s, phim& p)
{
    p.id = s;
}
void admin::settenphim(string s, phim& p)
{
    p.tenphim = s;
}
void admin::setdaodien(string s, phim& p)
{
    p.daodien = s;
}
void admin::setdienvien(string s, phim& p) {
    p.dienvien = s;
}
void admin::setgiochieu(int a, phim& p) { p.khoichieu.setgio(a); }
void admin::setphutchieu(int a, phim& p) { p.khoichieu.setphut(a); }
void admin::setngaychieu(int a, phim& p) { p.khoichieu.setngay(a); }
void admin::setthangchieu(int a, phim& p) { p.khoichieu.setthang(a); }
void admin::setnamchieu(int a, phim& p) { p.khoichieu.setnam(a); }
void admin::settheloai(string s, phim& p)
{
    p.theloai = s;
}
void admin::setkhoichieu(Time T, phim& p)
{
    p.khoichieu = T;
}
void admin::sethankhoichieu(phim& p)
{
    if (p.khoichieu.getngay() >= 15 && p.khoichieu.getthang() == 2)
    {
        p.hankhoichieu.setngay(p.khoichieu.getngay() + 14 - 28);
        p.hankhoichieu.setthang(p.khoichieu.getthang() + 1);
        p.hankhoichieu.setnam(p.khoichieu.getnam());
    }
    else if (p.khoichieu.getngay() >= 18 && p.khoichieu.getthang() == 12)
    {
        p.hankhoichieu.setngay(p.khoichieu.getngay() + 14 - 31);
        p.hankhoichieu.setthang(1);
        p.hankhoichieu.setnam(p.khoichieu.getnam() + 1);
    }
    else if (p.khoichieu.getngay() >= 17 && (p.khoichieu.getthang() == 4 || p.khoichieu.getthang() == 6 || p.khoichieu.getthang() == 9 || p.khoichieu.getthang() == 11))
    {
        p.hankhoichieu.setngay(p.khoichieu.getngay() + 14 - 30);
        p.hankhoichieu.setthang(p.khoichieu.getthang() + 1);
        p.hankhoichieu.setnam(p.khoichieu.getnam());
    }
    else if (p.khoichieu.getngay() >= 18 && (p.khoichieu.getthang() == 1 || p.khoichieu.getthang() == 3 || p.khoichieu.getthang() == 5 || p.khoichieu.getthang() == 7 || p.khoichieu.getthang() == 8 || p.khoichieu.getthang() == 10))
    {
        p.hankhoichieu.setngay(p.khoichieu.getngay() + 14 - 31);
        p.hankhoichieu.setthang(p.khoichieu.getthang() + 1);
        p.hankhoichieu.setnam(p.khoichieu.getnam());
    }
    else
    {
        p.hankhoichieu.setngay(p.khoichieu.getngay() + 14);
        p.hankhoichieu.setthang(p.khoichieu.getthang());
        p.hankhoichieu.setnam(p.khoichieu.getnam());
    }
    p.hankhoichieu.setphut(p.khoichieu.getphut());
    p.hankhoichieu.setgio(p.khoichieu.getgio());
}
void admin::setsosuatchieu(int n, phim& p)
{
    p.sosuatchieu = n;
}
void admin::setthoiluong(int s, phim& p)
{
    p.thoiluong = s;
}
void admin::setngonngu(string s, phim& p)
{
    p.ngonngu = s;
}
void admin::setgioithieuphim(string s, phim& p)
{
    p.gioithieuphim = s;
}
void admin::setage(string s, phim& p)
{
    p.age = s;
}
// g++ test.cpp thuvienadmin.cpp -o bangdz
void admin::setphim(phim& p)
{
    getline(cin, p.tenphim);
    getline(cin, p.daodien);
    getline(cin, p.theloai);
    cin >> p.khoichieu;
    this->sethankhoichieu(p);
    cin >> p.thoiluong;
    cin.ignore();
    getline(cin, p.ngonngu);
    getline(cin, p.gioithieuphim);
    cin >> p.age;
    cin.ignore();
}

void admin::themsuatchieu(suatchieu& sc, phim& p)
{
    if (p.sosuatchieu == 0)
    {
        p.danhsachsuatchieu = new suatchieu[1];
        *(p.danhsachsuatchieu + 0) = sc;
        p.sosuatchieu++;
    }
    else
    {
        suatchieu* tmp = new suatchieu[p.sosuatchieu + 1];
        for (int i = 0; i < p.sosuatchieu; i++)
        {
            *(tmp + i) = *(p.danhsachsuatchieu + i);
        }
        *(tmp + p.sosuatchieu) = sc;
        delete[] p.danhsachsuatchieu;
        p.sosuatchieu++;
        p.danhsachsuatchieu = new suatchieu[p.sosuatchieu];
        for (int i = 0; i < p.sosuatchieu; i++)
        {
            *(p.danhsachsuatchieu + i) = *(tmp + i);
        }
        delete[] tmp;
    }
    sc.setidphim(p.id);
}
void admin::themsuatchieu(suatchieu& sc, string s)
{
    for (int i = 0; i < this->getsophim(); i++) {
        if (rapquanly.maychurap.danhsachphim[i].getid() == s) {
            themsuatchieu(sc, rapquanly.maychurap.danhsachphim[i]);
        }
    }
}
void admin::setngaychieuphim(Time T) { rapquanly.ngaychieuphim = T; }
void admin::setphong(int i, int j, int k, phong p) { rapquanly.danhsachphong[i][j][k] = p; }
void admin::setmaychu(maychu mc) { rapquanly.maychurap = mc; }

void admin::nhaprap()
{
    rapquanly.tenrap = "CGV DA NANG";
    rapquanly.diachi = "Lien Chieu ";
    for (int o = 0; o < 8; o++)
    {
        ((rapquanly.danhsachphong[0][0][o].suat[o])).setgiochieu(7 + (2 * o), 45);
        ((rapquanly.danhsachphong[0][1][o].suat[o])).setgiochieu(7 + 1 + (2 * o), 0);
        ((rapquanly.danhsachphong[0][2][o].suat[o])).setgiochieu(7 + 1 + (2 * o), 15);
    }
    for (int o = 0; o < 3; o++)
    {
        for (int k = 0; k < 8; k++)
        {
            if (o == 0)
            {
                rapquanly.danhsachphong[0][o][k].suat[k].setgioketthucfirst(rapquanly.danhsachphong[0][o][k].suat[k].getthoigianchieu().getgio() + 2);
                rapquanly.danhsachphong[0][o][k].suat[k].setgioketthucsecond(rapquanly.danhsachphong[0][o][k].suat[k].getthoigianchieu().getphut() + 45 - 60);
            }
            else if (o == 1)
            {
                rapquanly.danhsachphong[0][o][k].suat[k].setgioketthucfirst(rapquanly.danhsachphong[0][o][k].suat[k].getthoigianchieu().getgio() + 2);
                rapquanly.danhsachphong[0][o][k].suat[k].setgioketthucsecond(rapquanly.danhsachphong[0][o][k].suat[k].getthoigianchieu().getphut() + 45);
            }
            else
            {
                rapquanly.danhsachphong[0][o][k].suat[k].setgioketthucfirst(rapquanly.danhsachphong[0][o][k].suat[k].getthoigianchieu().getgio() + 2);
                rapquanly.danhsachphong[0][o][k].suat[k].setgioketthucsecond(rapquanly.danhsachphong[0][o][k].suat[k].getthoigianchieu().getphut() - 15);
            }
        }
    }
    for (int g = 0; g < 10; g++)
    {
        for (int o = 0; o < 3; o++)
        {
            for (int k = 0; k < 8; k++)
            {
                rapquanly.danhsachphong[g][o][k].suat[k].setgiochieu(rapquanly.danhsachphong[0][o][k].suat[k].getthoigianchieu().getgio(), rapquanly.danhsachphong[0][o][k].suat[k].getthoigianchieu().getphut());
                rapquanly.danhsachphong[g][o][k].suat[k].setgioketthucfirst(rapquanly.danhsachphong[0][o][k].suat[k].getthoigianchieu().getgio());
                rapquanly.danhsachphong[g][o][k].suat[k].setgioketthucsecond(rapquanly.danhsachphong[0][o][k].suat[k].getthoigianchieu().getphut());
            }
        }
    }
}

//void admin::datve()
//{
//
//    now homnay;
//    Time TmpT;
//    cout << "Ban muon xem phim gi ?" << endl;
//    for (int j = 0; j < 10; j++)
//    {
//        (TmpT).congngay(rapquanly.ngaychieuphim, j);
//        phimchieutrongngay((TmpT));
//    }
//    cout << "Nhap ngay ban muon xem phim : " << endl;
//    int k;
//    cin >> k;
//    cin.ignore();
//    for (int i = 0; i < 10; i++)
//    {
//        if (k == rapquanly.ngaychieuphim.getngay() + i)
//        {
//            (TmpT).congngay(rapquanly.ngaychieuphim, i);
//            break;
//        }
//    }
//    phimchieutrongngay(TmpT);
//    cout << "Nhap phim ban muon xem : " << endl;
//    string tmp;
//    getline(cin, tmp);
//    phim tmpphim;
//    tmpphim = getphim((tmp));
//    cout << tmpphim;
//    for (int l = 0; l < tmpphim.sosuatchieu; l++)
//    {
//        if ((*(tmpphim.danhsachsuatchieu + l)).getthoigianchieu().equalday(TmpT))
//        {
//            (*(tmpphim.danhsachsuatchieu + l)).xuatgiochieu();
//        }
//    }
//    cout << endl
//        << "Nhap suat chieu ban muon xem : " << endl;
//    int tmpphut = 0;
//    int tmpgio = 0;
//    string tmp2;
//    getline(cin, tmp2);
//    if ((int)tmp2[2] > 57 || (int)tmp2[2] < 48) {
//        tmpgio = ((int)((tmp2)[0]) - 48) * 10 + ((int)((tmp2)[1]) - 48);
//
//        if (tmp2.length() == 4) {
//            tmpphut = ((int)((tmp2)[3]) - 48);
//        }
//        else {
//            tmpphut = ((int)((tmp2)[3]) - 48) * 10 + ((int)((tmp2)[4]) - 48);
//        }
//    }
//    else if (tmp2[1] > 57 || tmp2[1] < 48) {
//        tmpgio = ((int)((tmp2)[0]) - 48);
//        if (tmp2.length() == 3) {
//            tmpphut = ((int)((tmp2)[2]) - 48);
//        }
//        else {
//            tmpphut = ((int)((tmp2)[2]) - 48) * 10 + ((int)((tmp2)[3]) - 48);
//        }
//    }
//    suatchieu tmpsc;
//    tmpsc = getsuatchieu(tmpgio, tmpphut, TmpT);
//    cout << "Chon cho ngoi : " << endl;
//    (*((tmpsc).phongchieu)).hienthighe();
//    string tmpghe;
//    getline(cin, tmpghe);
//    int tmpghe1 = 0;
//    int tmpghe2 = 0;
//    string tmpghestring;
//    for (int i = 0; i < (tmpghe).length(); i++)
//    {
//        if ((tmpghe)[i] <= 76 && (tmpghe)[i] >= 65)
//        {
//            (tmpghestring) += (tmpghe)[i];
//            (tmpghe1) = (int)(tmpghe)[i] - 65;
//        }
//        else if ((tmpghe)[i] >= 97 && (tmpghe)[i] <= 118)
//        {
//            (tmpghestring) += (tmpghe)[i];
//            (tmpghe1) = (int)(tmpghe)[i] - 97;
//        }
//        else if ((tmpghe)[i] >= 48 && (tmpghe)[i] <= 57)
//        {
//            (tmpghestring) += (tmpghe)[i];
//            (tmpghe2) = (int)(tmpghe)[i] - 48;
//        }
//        else
//            continue;
//    }
//    cout << "Chon Bap, nuoc  : " << endl;
//    string tmpbap;
//    string tmpnuoc;
//    cout << "Bap : ";
//    getline(cin, tmpbap);
//    cout << "Nuoc : ";
//    getline(cin, tmpnuoc);
//    ve v(homnay, tmpbap, tmpnuoc, tmpsc, tmpghestring);
//    rapquanly.maychurap.themve(v);
//
//
//    //cout << (tmpsc.phongchieu->getidphong());
//    //cout << ((int)(tmpsc.phongchieu->getidphong())[2] - 48) << endl;
//    //xacnhandatve(k-rapquanly.ngaychieuphim.getngay(), , tmpghe1, tmpghe2, "DanhSachPhong.txt");
//    cout << endl << "bangcoto";
//    (*(tmpsc).phongchieu).hienthighe();
//    cout << v;
//}
void admin::quanlychieuphim() {
    now n;
    n.gancho(rapquanly.ngaychieuphim);
    if (((*(rapquanly.maychurap.danhsachphim + 0)).sosuatchieu) > 0)
    {
        for (int i = 0; i < rapquanly.maychurap.sophim; i++)
        {
            delete[](*(rapquanly.maychurap.danhsachphim + i)).danhsachsuatchieu;
            (*(rapquanly.maychurap.danhsachphim + i)).danhsachsuatchieu = new suatchieu;
            (*(rapquanly.maychurap.danhsachphim + i)).sosuatchieu = 0;
        }
    }

    int r = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 3; j++) {
            for (int o = 0; o < 8; o++) {
                (rapquanly.danhsachphong)[i][j][o].suat[o].idphong = ((rapquanly.danhsachphong)[i][j])[o].getidphong();
                (rapquanly.danhsachphong)[j][j][o].suat[o].idphim = (rapquanly.maychurap.danhsachphim + r)->getid();
                (rapquanly.danhsachphong)[i][j][o].suat[o].thoigianchieu.congngay(rapquanly.ngaychieuphim, i);
                themsuatchieu(((rapquanly.danhsachphong)[i][j][o].suat[o]), (*(rapquanly.maychurap.danhsachphim + r)));
                r = r + 1;
                if (r == rapquanly.maychurap.getsophim())
                {
                    r = 0;
                }

            }
        }
    }
}
void admin::swap(Time& T1, Time& T2)
{
    int tmp;
    tmp = T1.getphut();
    T1.setphut(T2.getphut());
    T2.setphut(tmp);
    tmp = T1.getgio();
    T1.setgio(T2.getgio());
    T2.setgio(tmp);
    tmp = T1.getngay();
    T1.setngay(T2.getngay());
    T2.setngay(tmp);
    tmp = T1.getthang();
    T1.setthang(T2.getthang());
    T2.setthang(tmp);
    tmp = T1.getnam();
    T1.setnam(T2.getnam());
    T2.setnam(tmp);
    tmp = T1.getthungay();
    T1.setthungay(T2.getthungay());
    T2.setthungay(tmp);
}
suatchieu admin::getsuatchieu(int i, int j, Time T)
{
    int k = T.trungay(rapquanly.ngaychieuphim);
    for (int o = 0; o < 3; o++)
    {
        for (int p = 0; p < 8; p++)
        {
            if (rapquanly.danhsachphong[k][o][p].suat[p].getthoigianchieu().getgio() == i && rapquanly.danhsachphong[k][o][p].suat[p].getthoigianchieu().getphut() == j)
            {
                return rapquanly.danhsachphong[k][o][p].suat[p];
            }
        }
    }
    suatchieu tmpsc;
    return tmpsc;
}

bool compareStrings(const  string& str1, const  string& str2) {
    const size_t  sai = 4;  // Ng??ng cho ph�p s? l??ng k� t? kh�c nhau

    size_t  t = abs((int)(str1.length() - str2.length()));
    if (t > sai) {
        return false;
    }

    size_t  khac = 0;
    size_t i = 0, j = 0;
    while (i < str1.length() && j < str2.length()) {
        if (tolower(str1[i]) != tolower(str2[j])) {
            ++khac;
            if (khac > sai) {
                return false;
            }
            if (str1.length() > str2.length()) {
                ++i;
            }
            else if (str2.length() > str1.length()) {
                ++j;
            }
            else {
                ++i;
                ++j;
            }
        }
        else {
            ++i;
            ++j;
        }
    }
    return  khac <= sai;
}
int admin::getphimtuid(string tmp1) {
    for (int i = 0; i < rapquanly.maychurap.sophim; i++)
    {
        if ((*(rapquanly.maychurap.danhsachphim + i)).id == tmp1) return (i);

    }
    return -1;
}
phim admin::getphim(string tmp1)
{
    for (int i = 0; i < rapquanly.maychurap.sophim; i++)
    {
        string tmp = (*(rapquanly.maychurap.danhsachphim + i)).tenphim;
        if (compareStrings(tmp, tmp1))
        {
            return *(rapquanly.maychurap.danhsachphim + i);
        }
    }
    phim tmp43;
    return tmp43;
}
string admin::chinhSuaText(string tmpText, int textDistance[], int n, bool name) {
    int MAX_STRING_LENGTH;
    int MAX_DISPLAY_LENGTH;
    int MIN_DISPLAY_LENTH;
    int FirstLetter;
    if (name) {
        MAX_STRING_LENGTH = 40;
        MAX_DISPLAY_LENGTH = 30;
        MIN_DISPLAY_LENTH = 20;
        FirstLetter = 14;
    }
    else {
        MAX_STRING_LENGTH = 50;
        MAX_DISPLAY_LENGTH = 40;
        MIN_DISPLAY_LENTH = 30;
        FirstLetter = 25;
    }
    if (tmpText.size() >= MIN_DISPLAY_LENTH && tmpText.size() <= MAX_STRING_LENGTH) {

        string tmp1, tmp2;
        for (int i = FirstLetter; i < tmpText.size(); i++) {
            if (tmpText[i] == ' ') {
                for (int j = 0; j < i; j++) {
                    tmp1 += tmpText[j];
                }
                for (int j = i + 1; j < tmpText.size(); j++) {
                    tmp2 += tmpText[j];
                }
                textDistance[n] += 7;
                break;
            }
        }
        return (tmp1 + "\n" + tmp2);
    }
    else if (tmpText.size() > MAX_STRING_LENGTH) {
        string tmp1, tmp2, tmp3;
        for (int i = FirstLetter; i < tmpText.size(); i++) {
            if (tmpText[i] == ' ') {
                for (int j = 0; j < i; j++) {
                    tmp1 += tmpText[j];
                }
                for (int j = 34; j <= MAX_STRING_LENGTH; j++) {
                    if (tmpText[j] == ' ') {
                        for (int k = i + 1; k < j; k++) {
                            tmp2 += tmpText[k];
                        }
                        for (int k = j; k < tmpText.size(); k++) {
                            tmp3 += tmpText[k];
                        }
                        textDistance[n] += 14;
                        break;
                    }
                }
                break;
            }
        }



        return (tmp1 + "\n" + tmp2 + "\n" + tmp3);
    }
    else {

        return (tmpText);
    }

}
phim* admin::getdanhsachphim() {
    return rapquanly.maychurap.getdanhsachphim();
}
int ConvertToInt(string s) {
    int result = 0;
    int multiply = 1;

    for (int i = s.length() - 1; i >= 0; --i) {
        if (isdigit(s[i])) {
            result += (s[i] - '0') * multiply;
            multiply *= 10;
        }
        else {
            return 0;
        }
    }

    return result;
}
string admin::increaseString(string str) {
    string str1;
    str1 = "000";
    if (str[2] == '9') {
        if (str[1] == '9') {
            (str1[0]) = (str[0]) + 1;
            str1[1] = '0';
            str1[2] = '0';
        }
        else {
            (str1[0]) = (str[0]);
            (str1[1]) = (str[1]) + 1;
            str1[2] = '0';
        }
    }
    else {
        (str1[0]) = (str[0]);
        (str1[1]) = (str[1]);
        (str1[2]) = (str[2]) + 1;
    }
    return str1;
}
void admin::themphim(string namefile)
{
    delete[] rapquanly.maychurap.danhsachphim;
    rapquanly.maychurap.sophim = 0;
    ifstream i;
    i.open(namefile, ios::in);
    if (!i.is_open()) return;
    int tmpcount = 1;
    string tmp;
    while (getline(i, tmp)) {
        tmpcount++;
    }
    i.close();
    rapquanly.maychurap.danhsachphim = new phim[tmpcount];
    string line;
    int count = 1;
    int countphim = 0;
    i.open(namefile, ios::in);
    if (!i.is_open()) return;
    while (getline(i, line)) {
        switch (count % 13) {
        case 0:
            setdienvien(line, rapquanly.maychurap.danhsachphim[countphim]);
            break;
        case 1:
            settenphim(line, rapquanly.maychurap.danhsachphim[countphim]);
            break;
        case 2:
            setdaodien(line, rapquanly.maychurap.danhsachphim[countphim]);
            break;
        case 3:
            settheloai(line, rapquanly.maychurap.danhsachphim[countphim]);
            break;
        case 4:
            setgiochieu(ConvertToInt(line), rapquanly.maychurap.danhsachphim[countphim]);
            break;
        case 5:
            setphutchieu(ConvertToInt(line), rapquanly.maychurap.danhsachphim[countphim]);
            break;
        case 6:
            setngaychieu(ConvertToInt(line), rapquanly.maychurap.danhsachphim[countphim]);
            break;
        case 7:
            setthangchieu(ConvertToInt(line), rapquanly.maychurap.danhsachphim[countphim]);
            break;
        case 8:
            setnamchieu(ConvertToInt(line), rapquanly.maychurap.danhsachphim[countphim]);
            break;
        case 9:
            setthoiluong(ConvertToInt(line), rapquanly.maychurap.danhsachphim[countphim]);
            break;
        case 10:
            setngonngu(line, rapquanly.maychurap.danhsachphim[countphim]);
            break;
        case 11:
            setgioithieuphim(line, rapquanly.maychurap.danhsachphim[countphim]);
            break;
        case 12:
            setage(line, rapquanly.maychurap.danhsachphim[countphim]);
        default:
            break;
        }
        count++;
        if ((count % 13) == 0) {
            rapquanly.maychurap.danhsachphim[countphim].sethankhoichieu();
            if (countphim == 0) { setid("000", rapquanly.maychurap.danhsachphim[countphim]); }
            else {
                setid(increaseString(rapquanly.maychurap.danhsachphim[countphim - 1].getid()), rapquanly.maychurap.danhsachphim[countphim]);
            }
            countphim++;
        }
    }
    i.close();


    rapquanly.maychurap.sophim += countphim;
}

void admin::writesuatchieu(const string name_file) {
    ofstream o;
    o.open(name_file, ios::trunc);
    Time T;
    now n;
    n.gancho(T);
    for (int j = 0; j < 10; j++) {
        for (int k = 0; k < 3; k++) {
            for (int p = 0; p < 8; p++) {

                o << (rapquanly.danhsachphong)[j][k][p].suat[p].getidphim() << endl;
                o << rapquanly.getidphong((rapquanly.danhsachphong)[j][k][p].suat[p]) << endl;
                o << (((rapquanly.danhsachphong)[j][k][p].suat[p].getthoigianchieu().trungay(T) + T.thungay) % 7) << endl;
                o << (rapquanly.danhsachphong)[j][k][p].suat[p].getthoigianchieu().getgio() << ":";
                o << (rapquanly.danhsachphong)[j][k][p].suat[p].getthoigianchieu().getphut() << " ";
                o << (rapquanly.danhsachphong)[j][k][p].suat[p].getthoigianchieu().getngay() << "/";
                o << (rapquanly.danhsachphong)[j][k][p].suat[p].getthoigianchieu().getthang() << "/";
                o << (rapquanly.danhsachphong)[j][k][p].suat[p].getthoigianchieu().getnam() << endl;
            }
        }
    }


    o.close();
}

void admin::nhapsuatchieu(string namefile)
{
    ifstream i;
    string tmpID;
    string tmpIDPhong;
    int j = 0, k = 0, o = 0, r = 0;
    string line;
    i.open(namefile, ios::in);
    if (!i.is_open()) return;
    int THUNGAY;
    Time tmpTime;
    int count = 1;
    while (getline(i, line)) {
        if (count % 4 == 1) {
            tmpID = line;
            count++;
        }
        else if (count % 4 == 2) {
            tmpIDPhong = line;
            count++;
        }
        else if (line.length() == 1) {
            THUNGAY = stoi(line);
            count++;
        }
        else {
            count++;
            j = tmpIDPhong[0] - 48;
            k = tmpIDPhong[1] - 48;
            size_t pos = 0;
            int gio = std::stoi(line, &pos);
            line = line.substr(pos + 1);

            // Lấy phút
            int phut = std::stoi(line, &pos);
            line = line.substr(pos + 1);

            // Lấy ngày
            int ngay = std::stoi(line, &pos);
            line = line.substr(pos + 1);

            // Lấy tháng
            int thang = std::stoi(line, &pos);
            line = line.substr(pos + 1);
            // Lấy năm
            int nam = std::stoi(line);
            Time tmpTime(phut, gio, ngay, thang, nam, THUNGAY);

            r = getphimtuid(tmpID);
            (rapquanly.danhsachphong)[j][k - 1][o].suat[o].setidphim(tmpID);
            (rapquanly.danhsachphong)[j][k - 1][o].suat[o].setidphong(tmpIDPhong);
            (rapquanly.danhsachphong)[j][k - 1][o].suat[o].thoigianchieu = tmpTime;
            themsuatchieu(((rapquanly.danhsachphong)[j][k - 1][o].suat[o]), (*(rapquanly.maychurap.danhsachphim + r)));
            o++;
            if (o >= 8) {
                o = 0;
            }

        }
        // Lấy giờ


    }
    i.close();
}

void admin::themphim(phim sc)
{
    if (rapquanly.maychurap.sophim == 0)
    {
        delete[] rapquanly.maychurap.danhsachphim;
        rapquanly.maychurap.danhsachphim = new phim[1];
        *(rapquanly.maychurap.danhsachphim + 0) = sc;
        setid("000", (*(rapquanly.maychurap.danhsachphim + 0)));
        rapquanly.maychurap.sophim++;
    }
    else
    {
        phim* tmp = new phim[rapquanly.maychurap.sophim + 1];
        for (int i = 0; i < rapquanly.maychurap.sophim; i++)
        {
            *(tmp + i) = *(rapquanly.maychurap.danhsachphim + i);
        }
        *(tmp + rapquanly.maychurap.sophim) = sc;
        delete[] rapquanly.maychurap.danhsachphim;
        rapquanly.maychurap.sophim++;
        rapquanly.maychurap.danhsachphim = new phim[rapquanly.maychurap.sophim];
        int r = 0;
        for (int i = 0; i < rapquanly.maychurap.sophim; i++)
        {
            *(rapquanly.maychurap.danhsachphim + i) = *(tmp + i);
        }
        r = rapquanly.maychurap.sophim - 1;
        setid(increaseString((*(rapquanly.maychurap.danhsachphim + (r - 1))).getid()), (*(rapquanly.maychurap.danhsachphim + r)));

        delete[] tmp;

    }
    quanlychieuphim();
}
int admin::getsophim() {
    return rapquanly.maychurap.getsophim();
}



void admin::xuatphim() {
    for (int i = 0; i < rapquanly.maychurap.sophim; i++) {
        cout << rapquanly.maychurap.danhsachphim[i].gettenphim() << endl;
        for (int j = 0; j < rapquanly.maychurap.danhsachphim[i].sosuatchieu; j++) {
            cout << rapquanly.maychurap.danhsachphim[i].danhsachsuatchieu[j].thoigianchieu.getngay() << endl;
            cout << rapquanly.maychurap.danhsachphim[i].danhsachsuatchieu[j].thoigianchieu.getthungay() << endl;
        }
    }
}

suatchieu admin::getsuat(int i, int j, int k) {
    return this->rapquanly.danhsachphong[i][j][k].suat[k];
}
phong admin::getphong(string s) {
    return rapquanly.getphong(s);
}