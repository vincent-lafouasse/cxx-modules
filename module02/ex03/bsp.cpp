#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    typedef Point::Orientation Orientation;

    Orientation o1 = point.orientation(a, b);
    Orientation o2 = point.orientation(b, c);
    Orientation o3 = point.orientation(c, a);

    bool has_lefts = (o1 == Orientation::Left) || (o2 == Orientation::Left) ||
                     (o3 == Orientation::Left);
    bool has_rights = (o1 == Orientation::Right) ||
                      (o2 == Orientation::Right) || (o3 == Orientation::Right);

    return !(has_lefts && has_rights);
}
