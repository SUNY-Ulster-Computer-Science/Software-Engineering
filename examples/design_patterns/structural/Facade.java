package examples.design_patterns.structural;

class CPU {
    void start() {
        System.out.println("CPU started");
    }
}

class Memory {
    void load() {
        System.out.println("Memory loaded");
    }
}

class Disk {
    void spin() {
        System.out.println("Disk spinning");
    }
}

// A single interface for external systems to interact with instead of many
class ComputerFacade {
    private CPU cpu = new CPU();
    private Memory mem = new Memory();
    private Disk disk = new Disk();

    public void powerOn() {
        cpu.start();
        mem.load();
        disk.spin();
    }
}

// Usage:
// new ComputerFacade().powerOn();
// Prints: CPU started / Memory loaded / Disk spinning
