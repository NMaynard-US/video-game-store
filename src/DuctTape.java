public class DuctTape extends Product {
    public DuctTape() {
        super("Duct Tape", 2);
    }

    @Override
    public void run() {
        while (System.currentTimeMillis() - startTime < PRODUCTION_TIME) {
            synchronized (lock) {
                if (System.currentTimeMillis() - startTime + buildTime > PRODUCTION_TIME) break;
                System.out.println("Building Duct Tape...");
                try { Thread.sleep(buildTime); } catch (InterruptedException e) {}
                count++;
            }
        }
    }
}
