package examples.design_patterns.behavioral;

import java.util.List;
import java.util.ArrayList;

// Listens to (observes) an event feed and updates when notified
interface Observer {
    void update(String event);
}

// Uses a subscribe/publish model to register and update observers
class EventBus {
    private List<Observer> listeners = new ArrayList<>();

    public void subscribe(Observer o) {
        listeners.add(o);
    }

    public void publish(String event) {
        listeners.forEach(o -> o.update(event));
    }
}

class Logger implements Observer {
    public void update(String event) {
        System.out.println("LOG: " + event);
    }
}

class AlertSystem implements Observer {
    public void update(String event) {
        System.out.println("ALERT: " + event);
    }
}

// Usage:
// EventBus bus = new EventBus();
// bus.subscribe(new Logger());
// bus.subscribe(new AlertSystem());
// bus.publish("Server down");
// Prints: LOG: Server down / ALERT: Server down
