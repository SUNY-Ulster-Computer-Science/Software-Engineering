package examples.design_patterns.creational;

class Shape implements Cloneable {
    String type;

    Shape(String type) {
        this.type = type;
    }

    // Objects can be cloned based off of the original prototype
    public Shape clone() {
        try {
            return (Shape) super.clone();
        } catch (CloneNotSupportedException e) {
            return null;
        }
    }

    public String toString() {
        return "Shape: " + type;
    }
}

// Usage:
// Shape original = new Shape("Circle");
// Shape copy = original.clone();
// copy.type = "Oval";
// System.out.println(original); // "Shape: Circle"
// System.out.println(copy); // "Shape: Oval"
