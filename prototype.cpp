#include <string>
#include <iostream>

struct Point
{
  int x{ 0 }, y{ 0 };

  Point(){}

  Point(const int x, const int y) : x{x}, y{y} {}
};

struct Line
{
  Point *start, *end;

  Line(Point* const start, Point* const end)
    : start(start), end(end)
  {
  }

  ~Line()
  {
    delete start;
    delete end;
  }

  Line deep_copy() const
  {
    return Line( new Point(start->x, start->y), new Point(end->x, end->y));
  }
};

int main()
{
    Line line{new Point(0, 0), new Point(1,1)};
    std::cout << line.end->x << std::endl;
    Line line2 = line.deep_copy();
    return 0;
}
