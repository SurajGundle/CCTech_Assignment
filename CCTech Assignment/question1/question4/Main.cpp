#include <iostream>
#include <vector>

struct Point {
    double x, y;
};
int main() {
    int n;
    std::cout <<"Enter the number of points: ";
    std::cin >> n;
    std::vector<Point> points(n);
    std::cout << "Enter the coordinates of each point:" <<std::endl;
    for (int i = 0; i < n; i++) {
        std::cin>>points[i].x>>points[i].y;
    }
    double sumX = 0.0;
    double sumY = 0.0;

    for (int i = 0; i < n; i++) {
        sumX+=points[i].x;
        sumY +=points[i].y;
    }

    Point centroid;
    centroid.x=sumX / n;
    centroid.y=sumY / n;

    std::cout <<"The centroid point is (" <<centroid.x<<", "<< centroid.y <<")."<< std::endl;
    return 0;
}
