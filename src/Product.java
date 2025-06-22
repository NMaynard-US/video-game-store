public abstract class Product implements Runnable {
    protected String name;
    protected int buildTime; // in seconds
    protected int count = 0;
    protected static final Object lock = new Object(); // shared lock
    protected static final long PRODUCTION_TIME = 24 * 1000; // in milliseconds
    protected static long startTime;

    public Product(String name, int buildTime) {
        this.name = name;
        this.buildTime = buildTime * 1000; // convert to milliseconds
    }

    public static void setStartTime() {
        startTime = System.currentTimeMillis();
    }

    public abstract void run(); // No @Override annotation for abstract methods

    public int getCount() {
        return count;
    }

    public String getName() {
        return name;
    }
}