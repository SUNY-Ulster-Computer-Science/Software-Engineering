package examples.design_patterns.behavioral;

class TextEditor {
    private String text = "";

    // Memento used to encapsulate and save hidden editor state for later use
    static class Memento {
        final String state;

        Memento(String s) {
            state = s;
        }
    }

    public void type(String words) {
        text += words;
    }

    public Memento save() {
        return new Memento(text);
    }

    public void restore(Memento m) {
        text = m.state;
    }

    public String getText() {
        return text;
    }
}

// Usage:
// TextEditor ed = new TextEditor();
// ed.type("Hello ");
// TextEditor.Memento snap = ed.save();
// ed.type("World");
// System.out.println(ed.getText()); // "Hello World"
// ed.restore(snap);
// System.out.println(ed.getText()); // "Hello "
