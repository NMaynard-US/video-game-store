public class Camera extends Product {
    public Camera() {
        super("Camera", 5);
    }

    @Override
    public void run() {
        while (true) {
            long currentTime = System.currentTimeMillis();
            long elapsedTime = currentTime - startTime;

            if (elapsedTime >= PRODUCTION_TIME) {
                break;
            }

            System.out.println("Camera thread waiting to acquire lock...");

            synchronized (lock) {
                currentTime = System.currentTimeMillis();
                elapsedTime = currentTime - startTime;

                if (elapsedTime + buildTime > PRODUCTION_TIME) {
                    System.out.println("Camera skipped: Not enough time left to build.");
                    break;
                }

                System.out.println("Camera building at " + (elapsedTime / 1000.0) + " seconds");
                try {
                    Thread.sleep(buildTime);
                } catch (InterruptedException e) {
                    Thread.currentThread().interrupt();
                    System.err.println("Camera thread interrupted: " + e.getMessage());
                    break;
                }

                count++;
                System.out.println("Camera completed. Total: " + count);
            }

            Thread.yield(); // Give other threads a fair shot
        }
    }
}