#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<math.h>
#include<string>
#include<unordered_map>
#include<map>

using namespace std;

#define WHITE 0
#define BLACK 1
#define NONE -1

struct Point {
    int i, j;
    Point(int i, int j) :i(i), j(j) {}
};

int N;
char chr_img[64][64];
int img[64][64];

int whichColor(Point, Point);
void compress(Point, Point);

void compress(Point topLeft, Point bottomRight) {
    

    int color = whichColor(topLeft, bottomRight);
    
    if (color == BLACK) {
        cout << BLACK;
        return;
    }
    if (color == WHITE) {
        cout << WHITE;
        return;
    }

    Point mid = Point((topLeft.i + bottomRight.i) / 2, (topLeft.j + bottomRight.j) / 2);
    cout << "(";
    compress(topLeft, mid);
    compress(Point(topLeft.i, mid.j), Point(mid.i, bottomRight.j));
    compress(Point(mid.i, topLeft.j), Point(bottomRight.i, mid.j));
    compress(mid, bottomRight);

    cout << ")";
}

int whichColor(Point topLeft, Point bottomRight) {
    int color = img[topLeft.i][topLeft.j];
    
    for (int i = topLeft.i; i < bottomRight.i; i++) {
        for (int j = topLeft.j; j < bottomRight.j; j++) {
            if (img[i][j] != color)
                return -1;
        }
    }

    return color;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> chr_img[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            img[i][j] = chr_img[i][j] - '0';
        }
    }



    compress(Point(0,0), Point(N,N));

    return 0;
}
