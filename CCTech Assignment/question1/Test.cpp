#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

struct Point {
    int id;
    double v1;
    double v2;
};

struct Connection {
    int id1;
    int id2;
};

int main() {
    std::ifstream file("dataa.txt");
    if (!file.is_open()) {
        std::cerr << "Error in opening file/file not exists" << std::endl;
        return 1;
    }
    std::vector<Point> points;
    std::vector<Connection> connections;
    std::string line;

    while (std::getline(file, line)) {
        if (line == "PTS") {
            while (std::getline(file, line) && line != "CON") {
                Point point;
                std::istringstream iss(line);
                iss >> point.id >> point.v1 >> point.v2;
                points.push_back(point);
            }
        } else if (line == "CON") {
            while (std::getline(file, line) && !line.empty()) {
                Connection connection;
                std::istringstream iss(line);
                iss>>connection.id1>>connection.id2;
                connections.push_back(connection);
            }
        }
    }
    file.close();
    std::cout<<"Points:"<<std::endl;
    for (const Point& point : points) {
        std::cout<<"ID: "<<point.id << ", Value1: "<<point.v1 <<",Value2:"<< point.v2 << std::endl;
    }

    std::cout << "Connections:"<< std::endl;
    for (const Connection& connection : connections) {
        std::cout << "ID1: "<<connection.id1<< ",ID2: "<< connection.id2 << std::endl;
    }
    return 0;
}
