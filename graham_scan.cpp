#include <bits/stdc++.h>
using namespace std;

// chatgpt generated
// Structure to represent a 2D point
struct Point {
    int x, y;
};

// Helper function to find the orientation of three points
int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0; // collinear
    return (val > 0) ? 1 : 2; // 1 for clockwise, 2 for counterclockwise
}

// Comparator function to sort points based on polar angle
bool compare(Point p1, Point p2) {
    // Find orientation of p1, p2, and the reference point
    int o = orientation({0, 0}, p1, p2);
    if (o == 0) // If collinear, choose the one closer to the reference point
        return (p1.x * p1.x + p1.y * p1.y) < (p2.x * p2.x + p2.y * p2.y);
    return (o == 2); // Sort in counterclockwise order
}

// Function to find the convex hull using Graham Scan
vector<Point> convexHull(vector<Point>& points) {
    int n = points.size();
    if (n < 3) return {}; // Convex hull not possible with less than 3 points

    // Find the point with the lowest y-coordinate (and leftmost if tied)
    int ymin = points[0].y, minIdx = 0;
    for (int i = 1; i < n; i++) {
        int y = points[i].y;
        if ((y < ymin) || (ymin == y && points[i].x < points[minIdx].x)) {
            ymin = y;
            minIdx = i;
        }
    }

    // Place the lowest point at the beginning of the vector
    swap(points[0], points[minIdx]);

    // Sort the points based on polar angle with respect to the lowest point
    sort(points.begin() + 1, points.end(), compare);

    // Create a stack to store the points of the convex hull
    stack<Point> hull;
    hull.push(points[0]);
    hull.push(points[1]);
    hull.push(points[2]);

    // Process the remaining points
    for (int i = 3; i < n; i++) {
        while (orientation(hull.top(), points[i], points[i - 1]) != 2) {
            hull.pop(); // Remove points that are not part of the convex hull
        }
        hull.push(points[i]);
    }

    // Transfer the points from the stack to a vector
    vector<Point> convexHullPoints;
    while (!hull.empty()) {
        convexHullPoints.push_back(hull.top());
        hull.pop();
    }

    // Reverse the vector to maintain counterclockwise order
    reverse(convexHullPoints.begin(), convexHullPoints.end());

    return convexHullPoints;
}

int main() {
    vector<Point> points = {{0, 3}, {2, 2}, {1, 1}, {2, 1}, {3, 0}, {0, 0}, {3, 3}};
    vector<Point> convexHullPoints = convexHull(points);

    // Print the points constituting the convex hull
    cout << "Points constituting the convex hull:\n";
    for (auto p : convexHullPoints) {
        cout << "(" << p.x << ", " << p.y << ")\n";
    }

    return 0;
}
