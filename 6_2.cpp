#include <iostream>
using namespace std;

class point {
private:
    int x, y;

public:
    point(int x = 0, int y = 0) {
        this->x = x;
        this->y = y;
    }

    point* move_by(int dx, int dy) {
        x += dx;
        y += dy;
        return this;
    }

    void display_coordinates() const {
        cout << "Point at (" << x << ", " << y << ")\n";
    }
};

int main() {
    point* p = new point(10, 20);
    p->display_coordinates();
    p->move_by(5, -3)->move_by(-2, 4)->move_by(1, 1);
    p->display_coordinates();
    delete p;
    cout << "24CE076_PatelDarshan";
    return 0;
}
