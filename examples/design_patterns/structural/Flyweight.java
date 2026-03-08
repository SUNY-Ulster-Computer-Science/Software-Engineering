package examples.design_patterns.structural;

import java.util.HashMap;
import java.util.Map;

class TreeType {
    String name, texture;

    TreeType(String name, String texture) {
        this.name = name;
        this.texture = texture;
    }

    void draw(int x, int y) {
        System.out.println("Drawing " + name + " at (" + x + "," + y + ")");
    }
}

// Collects previous objects and uses caching to quickly retrieve them
class TreeFactory {
    private static Map<String, TreeType> cache = new HashMap<>();

    public static TreeType get(String name, String texture) {
        return cache.computeIfAbsent(name, k -> new TreeType(name, texture));
    }
}

// Usage:
// TreeType oak = TreeFactory.get("Oak", "rough");
// oak.draw(10, 20); // "Drawing Oak at (10,20)"
// TreeType oak2 = TreeFactory.get("Oak", "rough"); // reuses cached instance
// System.out.println(oak == oak2); // true
