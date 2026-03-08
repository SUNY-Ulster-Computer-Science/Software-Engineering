package examples.design_patterns.creational;

interface Button {
    void render();
}

interface Checkbox {
    void render();
}

// OS-dependent buttons

class WinButton implements Button {
    public void render() {
        System.out.println("Windows Button");
    }
}

class MacButton implements Button {
    public void render() {
        System.out.println("Mac Button");
    }
}

// OS-dependent checkboxes

class WinCheckbox implements Checkbox {
    public void render() {
        System.out.println("Windows Checkbox");
    }
}

class MacCheckbox implements Checkbox {
    public void render() {
        System.out.println("Mac Checkbox");
    }
}

interface GUIFactory {
    Button createButton();

    Checkbox createCheckbox();
}

// Different subclasses create different kinds of objects

class WinFactory implements GUIFactory {
    public Button createButton() {
        return new WinButton();
    }

    public Checkbox createCheckbox() {
        return new WinCheckbox();
    }
}

class MacFactory implements GUIFactory {
    public Button createButton() {
        return new MacButton();
    }

    public Checkbox createCheckbox() {
        return new MacCheckbox();
    }
}

// Usage:
// GUIFactory factory = new WinFactory();
// factory.createButton().render(); // "Windows Button"
