public class Car extends Product {
    public Car() {
        super("Car", 8);
    }

    @Override
    public void run() {
        while (true) {
            long currentTime = System.currentTimeMillis();
            long elapsedTime = currentTime - startTime;

            if (elapsedTime >= PRODUCTION_TIME) {
                break;
            }

            synchronized (lock) {
                currentTime = System.currentTimeMillis();
                elapsedTime = currentTime - startTime;

                if (elapsedTime + buildTime > PRODUCTION_TIME) {
                    break;
                }

                System.out.println("Building Car...");
                try {
                    Thread.sleep(buildTime);
                } catch (InterruptedException e) {
                    // Restore the interrupted status and exit
                    Thread.currentThread().interrupt();
                    System.err.println("Car production interrupted: " + e.getMessage());
                    break;
                }
                count++;
            }
        }
    }
}