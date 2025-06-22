public class LavaLamp extends Product {
    public LavaLamp() {
        super("Lava Lamp", 4);
    }

    @Override
    public void run() {
        while (System.currentTimeMillis() - startTime < PRODUCTION_TIME) {
            synchronized (lock) {
                if (System.currentTimeMillis() - startTime + buildTime > PRODUCTION_TIME) break;
                System.out.println("Building Lava Lamp...");
                try { Thread.sleep(buildTime); } catch (InterruptedException e) {}
                count++;
            }
        }
    }
}