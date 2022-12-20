#include "line.h"
#include <complex>
double const PI = 3.14159265359;
template<class T>
double Line<T>::eps = 0.0001;
bool check_number(const std::string& num) {
    int dot_use = 1;
    for (int i = 0; i < num.size(); ++i) {
        if (!isdigit(num[i]) && !(num[i] == '.' && dot_use)) return false;
        if (num[i] == '.') dot_use = 0;
    }
    return true;
}
void get_trinagle() {
    double alp;
    double a;
    std::string alp_t;
    std::cout << "angle alpha in degrees = "; std::cin >> alp_t;
    while (!check_number(alp_t) || std::stod(alp_t) <= 0 || std::stod(alp_t) >= 180) {
        std::cout << "Incorrect angle\n";
        std::cout << "angle alpha in degrees = "; std::cin >> alp_t;
    }
    alp = std::stod(alp_t);
    std::string a_t;
    std::cout << "lengh of side = "; std::cin >> a_t;
    while (!check_number(a_t) || std::stof(a_t) < 1e-5) {
        std::cout << "incorrect lenght\n";
        std::cout << "lengh of side = "; std::cin >> a_t;
    }
    a = std::stod(alp_t);
    Line<double> ans(4);
    ans[1].x = a * sin(alp / 2 * PI / 180.0);
    ans[1].y = a * cos(alp / 2 * PI / 180.0);
    ans[2].y = 0;
    ans[2].x = ans[1].x * 2.0;
    std::cout << ans;
}
template<class T> void point(Line<T>& res);
template<class T> void set_tmp(Line<T>& res) {
    int n;
    std::string n_t;
    std::cout << "num of elems = "; std::cin >> n_t;
    while (!check_number(n_t) && std::stoi(n_t) < 0) {
        std::cout << "Incorrect number\n";
        std::cout << "num of elems = "; std::cin >> n_t;
    }
    n = std::stoi(n_t);
    res = Line<T>(n);
    for (int i = 0; i < res.size(); ++i) point(res);
}
template<class T> void point(Line<T>& res) {
    int id;
    std::string id_t;
    std::cout << "id = "; std::cin >> id_t;
    while (!check_number(id_t) || std::stoi(id_t) < 0) {
        std::cout << "Incorrect number\n";
        std::cout << "id = "; std::cin >> id_t;
    }
    id = std::stoi(id_t);
    std::cout << res[id].x << " " << res[id].y << "\n";
    int cmd;
    std::cout << "do you want to change? (1/0) "; std::cin >> cmd;
    if (cmd) {
        T x, y;
        std::string x_t;
        std::cout << "x = "; std::cin >> x_t;
        while (!check_number(x_t)) {
            std::cout << "Incorrect number\n";
            std::cout << "x = "; std::cin >> x_t;
        }
        x = std::stod(x_t);
        std::string y_t;
        std::cout << "y = "; std::cin >> y_t;
        while (!check_number(y_t)) {
            std::cout << "Incorrect number\n";
            std::cout << "y = "; std::cin >> y_t;
        }
        y = std::stof(y_t);
        res[id].x = x;
        res[id].y = y;
    }
}
template<class T> void concat1(Line<T>& a, Line<T>& b) {
    set_tmp(b);
    Line tmp = a + b;
    std::cout << tmp;
}
template<class T> void concat2(Line<T>& a, Point<T> b) {
    T x, y;
    std::cout << "x = "; std::cin >> x;
    std::cout << "y = "; std::cin >> y;
    b.x = x;
    b.y = y;
    Line tmp = a + b;
    std::cout << tmp;
}
template<class T> void concat3(Point<T> b, Line<T>& a) {
    T x, y;
    std::string x_t;
    std::cout << "x = "; std::cin >> x_t;
    while (!check_number(x_t)) {
        std::cout << "Incorrect number\n";
        std::cout << "x = "; std::cin >> x_t;
    }
    x = std::stof(x_t);
    std::string y_t;
    std::cout << "y = "; std::cin >> y_t;
    while (!check_number(y_t)) {
        std::cout << "Incorrect number\n";
        std::cout << "y = "; std::cin >> y_t;
    }
    y = std::stof(y_t);
    b.x = x;
    b.y = y;
    Line tmp = b + a;
    std::cout << tmp;
}
template<class T> void len(Line<T>& a) {
    std::cout << a.len() << "\n";
}
int main() {
    Line <std::complex<int>>tmp1(1);
    Point <std::complex<int>>tmp2;
    Line <std::complex<int>> tmp3;
    int cmd;
    while (true) {
        std::cout << "1 set the line\n2 set/get point in line\n3 concat with other line\n4 concat with point (end)\n5 concat with point (begin)\n6 get lenght of line\n7 get trinagle\n8 print the line\n9 exit\n";
        std::cin >> cmd;
        if (cmd == 9) break;
        switch (cmd)
        {
        case 1: 
            system("cls");
            set_tmp(tmp1);
            break;
        case 2:
            system("cls");
            point(tmp1);
            break;
        case 3:
            system("cls");
            concat1(tmp1, tmp3);
            break;
        case 4:
            system("cls");
            concat2(tmp1, tmp2);
            break;
        case 5:
            system("cls");
            concat3(tmp2, tmp1);
            break;
        case 6:
            system("cls");
            len(tmp1);
            break;
        case 7:
            system("cls");
            get_trinagle();
            break;
        case 8:
            system("cls");
            std::cout << tmp1;
            break;
        }

    }

}