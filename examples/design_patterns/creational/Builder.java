package examples.design_patterns.creational;

class Pizza {
    private String size, crust, topping;

    private Pizza() {
    }

    // Builder class constructs a pizza through chained method calls
    static class Builder {
        private Pizza pizza = new Pizza();

        public Builder size(String s) {
            pizza.size = s;
            return this;
        }

        public Builder crust(String c) {
            pizza.crust = c;
            return this;
        }

        public Builder topping(String t) {
            pizza.topping = t;
            return this;
        }

        public Pizza build() {
            return pizza;
        }
    }

    public String toString() {
        return size + " pizza, " + crust + " crust, " + topping;
    }
}

// Usage:
// Pizza p = new Pizza.Builder().size("Large").crust("Thin").topping("Pepperoni").build();
// System.out.println(p); // "Large pizza, Thin crust, Pepperoni"
