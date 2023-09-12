#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

struct Point {
    int x, y;
};

bool compare(Point p1, Point p2) {
    return (p1.x < p2.x)||(p1.x == p2.x && p1.y < p2.y);
}

int crossProduct(Point p1, Point p2, Point p3) {
    return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
}

std::vector<Point> convexHull(std::vector<Point> points) {
    int n = points.size();
    if (n < 3) {
        return points;
    }

    std::sort(points.begin(), points.end(), compare);

    std::vector<Point> hull;
    hull.push_back(points[0]);
    hull.push_back(points[1]);

    for (int i = 2; i < n; i++) {
        while (hull.size()>=2&&crossProduct(hull[hull.size() - 2], hull[hull.size() - 1], points[i]) <= 0) {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }

    return hull;
}

double calculateArea(const std::vector<Point>& polygon) {
    int n=polygon.size();
    if (n<3) {
        return 0.0;
    }

    double area=0.0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        area+=(polygon[i].x * polygon[j].y-polygon[j].x * polygon[i].y);
    }

    return std::abs(area)/2.0;
}

int main() {
    int n;
    std::cout << "Enter the number of points: ";
    std::cin>>n;

    std::vector<Point> points(n);

    std::cout << "Enter the coordinates of each point" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cin >> points[i].x >> points[i].y;
    }

    std::vector<Point> hull = convexHull(points);
    double largestArea = calculateArea(hull);
    std::cout << "The largest area of the shape formed by the points = " << largestArea << std::endl;
    return 0;
}
