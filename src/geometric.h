#ifndef GEOMETRIC_H_
#define GEOMETRIC_H_

class Point {
public:
    double x;
    double y;
    double z;
    double squaredMagnitude;
    int segment;

    Point(double u = 0, double v = 0, double t = 0) {
        x = u;
        y = v;
        z = t;
    }

    Point operator + (Point const& anotherVector) {
        Point res;
        res.x = x + anotherVector.x;
        res.y = y + anotherVector.y;
        res.z = z + anotherVector.z;
        return res;
    }

    Point operator - (Point const& anotherVector) {
        Point res;
        res.x = x - anotherVector.x;
        res.y = y - anotherVector.y;
        res.z = z - anotherVector.z;
        return res;
    }

    Point scalar(double const& num) {
        Point res;
        res.x = x*num;
        res.y = y*num;
        res.z = z*num;
        return res;
    }
   
};

double magnitudeSquared(Point end);
double dotProduct(Point vectorA, Point vectorB);
Point orthogonalProjection(Point start, Point end, Point point);

#endif  // GEOMETRIC_H_