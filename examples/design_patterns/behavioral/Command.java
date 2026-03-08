package examples.design_patterns.behavioral;

// A common interface for many different types of command
interface Command {
    void execute();

    void undo();
}

class Light {
    public void on() {
        System.out.println("Light is ON");
    }

    public void off() {
        System.out.println("Light is OFF");
    }
}

class LightOnCommand implements Command {
    private Light light;

    LightOnCommand(Light l) {
        this.light = l;
    }

    public void execute() {
        light.on();
    }

    public void undo() {
        light.off();
    }
}

class LightOffCommand implements Command {
    private Light light;

    LightOffCommand(Light l) {
        this.light = l;
    }

    public void execute() {
        light.off();
    }

    public void undo() {
        light.on();
    }
}

// Utilizes plain Command objects, unaware of implementation
// Can operate on any kind of command as long as it matches the interface
class RemoteControl {
    private java.util.Deque<Command> history = new java.util.ArrayDeque<>();

    public void press(Command cmd) {
        cmd.execute();
        history.push(cmd);
    }

    public void undoLast() {
        if (!history.isEmpty())
            history.pop().undo();
    }
}

// Usage:
// Light light = new Light();
// RemoteControl remote = new RemoteControl();
// remote.press(new LightOnCommand(light)); // "Light is ON"
// remote.press(new LightOffCommand(light)); // "Light is OFF"
// remote.undoLast();
