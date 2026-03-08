package examples.design_patterns.structural;

class LegacyPrinter {
    public void printWithBanner(String text) {
        System.out.println("*** " + text + " ***");
    }
}

interface ModernPrinter {
    void print(String text);
}

// Allows modern code that only accepts ModernPrinter to support LegacyPrinter
class PrinterAdapter implements ModernPrinter {
    private LegacyPrinter legacy = new LegacyPrinter();

    public void print(String text) {
        legacy.printWithBanner(text);
    }
}

// Usage:
// ModernPrinter printer = new PrinterAdapter();
// printer.print("Hello"); // "*** Hello ***"
