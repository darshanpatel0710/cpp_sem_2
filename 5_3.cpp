#include <iostream>
using namespace std;

class point {
public:
    int x, y;

    point(int x = 0, int y = 0) : x(x), y(y) {}

    point operator-() const {
        return point(-x, -y);
    }

    point operator+(const point& other) const {
        return point(x + other.x, y + other.y);
    }

    bool operator==(const point& other) const {
        return x == other.x && y == other.y;
    }
};

class point_stack {
private:
    point* data;
    int capacity;
    int top_index;

public:
    point_stack(int size = 100) {
        capacity = size;
        data = new point[capacity];
        top_index = -1;
    }

    ~point_stack() {
        delete[] data;
    }

    void push(const point& p) {
        if (top_index + 1 < capacity) {
            data[++top_index] = p;
        }
    }

    point pop() {
        if (top_index >= 0) {
            return data[top_index--];
        }
        return point();
    }

    bool empty() const {
        return top_index == -1;
    }
};

int main() {
    point_stack history;
    point p1(2, 3);
    point p2(4, -1);
    point result = p1 + p2;
    history.push(result);
    result = -result;
    history.push(result);

    while (!history.empty()) {
        point last = history.pop();
        cout << "(" << last.x << ", " << last.y << ")\n";
    }

    cout<<"\nPatelDarshan_24CE076";

    return 0;
}
