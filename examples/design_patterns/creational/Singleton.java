package examples.design_patterns.creational;

class AppConfig {
    // Static instance member ensures only one AppConfig is ever created
    private static AppConfig instance;
    private String theme = "Dark";

    private AppConfig() {
    }

    public static AppConfig getInstance() {
        // Ensure only one instance exists
        if (instance == null)
            instance = new AppConfig();
        return instance;
    }

    public String getTheme() {
        return theme;
    }
}

// Usage:
// AppConfig cfg = AppConfig.getInstance();
// System.out.println(cfg.getTheme()); // "Dark"
