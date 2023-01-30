#include "geometric.h"


double magnitudeSquared(Point end) {
    return dotProduct(end, end);
}
    
double dotProduct(Point vectorA, Point vectorB) {
    return vectorA.x * vectorB.x + vectorA.y * vectorB.y + vectorA.z * vectorB.z;
}

Point orthogonalProjection(Point start, Point end, Point point) {
    Point result;
    Point v, u;
    // Move vector to the origin
    v = end - start;
    u = point - start;
    
    // Find the cosT
    double t = dotProduct(v, u) / (magnitudeSquared(v));
    
    // Closest point either lies within a segment range or not
    //Case: closer to the end of the segment
    if (t > 1) {
        result = end;
    }
    // Case: closer to the origin of a vector
    else if (t < 0) {
        result = start;
    }
    // Case: in a range
    else {
        result = start + v.scalar(t);
    }
    result.squaredMagnitude = magnitudeSquared(point - result);
    return result;
}