public class Factory {
    public static void main(String[] args) {
        // Create product instances
        Car car = new Car();
        DuctTape ductTape = new DuctTape();
        Camera camera = new Camera();
        LavaLamp lavaLamp = new LavaLamp();

        // Set global production start time
        Product.setStartTime();

        // Start threads
        Thread t1 = new Thread(car);
        Thread t2 = new Thread(ductTape);
        Thread t3 = new Thread(camera);
        Thread t4 = new Thread(lavaLamp);

        t1.start();
        t2.start();
        t3.start();
        t4.start();

        try {
            t1.join();
            t2.join();
            t3.join();
            t4.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        // Print results
        System.out.println("\n--- Production Summary ---");
        System.out.println("Cars produced: " + car.getCount());
        System.out.println("Duct Tape produced: " + ductTape.getCount());
        System.out.println("Cameras produced: " + camera.getCount());
        System.out.println("Lava Lamps produced: " + lavaLamp.getCount());
    }
}
