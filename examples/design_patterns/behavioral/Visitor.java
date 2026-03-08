package examples.design_patterns.behavioral;

// A type of visitor that operates on all valid shapes
interface ShapeVisitor {
    void visit(Rectangle r);

    void visit(Triangle t);
}

// A class that can be visited
interface Visitable {
    void accept(ShapeVisitor v);
}

class Rectangle implements Visitable {
    double width, height;

    Rectangle(double w, double h) {
        width = w;
        height = h;
    }

    public void accept(ShapeVisitor v) {
        v.visit(this);
    }
}

class Triangle implements Visitable {
    double base, height;

    Triangle(double b, double h) {
        base = b;
        height = h;
    }

    public void accept(ShapeVisitor v) {
        v.visit(this);
    }
}

// Can "visit" all valid shapes to calculate their areas
class AreaCalculator implements ShapeVisitor {
    public void visit(Rectangle r) {
        System.out.println("Rectangle area: " + (r.width * r.height));
    }

    public void visit(Triangle t) {
        System.out.println("Triangle area: " + (0.5 * t.base * t.height));
    }
}

// Usage:
// ShapeVisitor calc = new AreaCalculator();
// new Rectangle(4, 5).accept(calc); // "Rectangle area: 20.0"
// new Triangle(3, 6).accept(calc); // "Triangle area: 9.0"
