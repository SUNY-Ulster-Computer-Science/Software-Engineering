package examples.design_patterns.structural;

interface Renderer {
    void renderShape(String shape);
}

class VectorRenderer implements Renderer {
    public void renderShape(String s) {
        System.out.println("Drawing " + s + " as vectors");
    }
}

class RasterRenderer implements Renderer {
    public void renderShape(String s) {
        System.out.println("Drawing " + s + " as pixels");
    }
}

abstract class DrawnShape {
    // Renderer implementation abstracted away from DrawnShape implementation
    protected Renderer renderer;

    DrawnShape(Renderer r) {
        this.renderer = r;
    }

    abstract void draw();
}

class Circle extends DrawnShape {
    Circle(Renderer r) {
        super(r);
    }

    public void draw() {
        renderer.renderShape("Circle");
    }
}

// Usage:
// DrawnShape c = new Circle(new VectorRenderer());
// c.draw(); // "Drawing Circle as vectors"
