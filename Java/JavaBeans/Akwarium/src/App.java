import java.beans.PropertyVetoException;
import java.util.Random;
import java.util.concurrent.atomic.AtomicInteger;

public class App {
    private static final int TOTAL_TEMPERATURE_CHANGES = 15;

    public static void main(String[] args) {
        // Tworzenie symulacji
        Grzalka grzalka = new Grzalka();
        Termostat termostat = new Termostat(grzalka);

        Rybka[] rybki = new Rybka[7];
        rybki[0] = new Rybka("Złota rybka", new int[]{18, 25}, grzalka);
        rybki[1] = new Rybka("Sum", new int[]{15, 28}, grzalka);
        rybki[2] = new Rybka("Karp", new int[]{12, 30}, grzalka);
        rybki[3] = new Rybka("Pstrąg", new int[]{10, 22}, grzalka);
        rybki[4] = new Rybka("Pirania", new int[]{20, 35}, grzalka);
        rybki[5] = new Rybka("Węgorz", new int[]{16, 24}, grzalka);
        rybki[6] = new Rybka("Rekin", new int[]{19, 32}, grzalka);

        // Wielowątkowość
        AtomicInteger changeCounter = new AtomicInteger(0);

        Thread[] threads = new Thread[3];
        for (int i = 0; i < threads.length; i++) {
            threads[i] = new Thread(new TemperatureChanger(grzalka, changeCounter, i+1));
            threads[i].start();

            // Dodanie opóźnienia między uruchomieniem wątków
            try {
                Thread.sleep(1500 * (i + 1)); // Opóźnienie: 1.5s, 3s, 4.5s
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        // Symulacja
        for (Thread thread : threads) {
            try {
                thread.join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        // Stan akwarium na koniec
        System.out.println("\nStatus końcowy ryb:");
        for (Rybka rybka : rybki) {
            System.out.println(rybka + (rybka.getAlive() ? " - żywa" : " - martwa"));
        }

        System.out.println("\nProgram zakończony po " + TOTAL_TEMPERATURE_CHANGES + " zmianach temperatury.");
    }

    // ----------------------------------------------------------------
    // Klasa wewnętrzna dla postaci
    static class TemperatureChanger implements Runnable {
        private final Grzalka grzalka;
        private final AtomicInteger changeCounter;
        private final int threadId;
        private final Random random = new Random();
        private boolean preferIncrease;
        private int streakCounter;

        public TemperatureChanger(Grzalka grzalka, AtomicInteger changeCounter, int threadId) {
            this.grzalka = grzalka;
            this.changeCounter = changeCounter;
            this.threadId = threadId;

            // Inicjalizacja preferencji dla wątku
            this.preferIncrease = threadId % 2 == 0;
            this.streakCounter = 0;
        }

        @Override
        public void run() {
            while (changeCounter.get() < TOTAL_TEMPERATURE_CHANGES) {
                try {
                    if (changeCounter.get() >= TOTAL_TEMPERATURE_CHANGES) {
                        break;
                    }

                    // Próba zmiany temperatury
                    System.out.println("\nWątek " + threadId + " próbuje zmienić temperaturę...");

                    // Decyzja czy podnieść czy obniżyć temperaturę:
                    // 70% szans na kontynuowanie w preferowanym kierunku
                    // 30% szans na zmianę w przeciwnym kierunku
                    boolean increase;
                    if (streakCounter > 0 && random.nextInt(100) < 70) {
                        // Kontynuuj serię w tym samym kierunku
                        increase = preferIncrease;
                        streakCounter++;
                    } else {
                        // Zmień kierunek
                        if (random.nextInt(100) < 60) {
                            increase = !preferIncrease;
                        } else {
                            increase = preferIncrease;
                        }
                        preferIncrease = increase;
                        streakCounter = 1;
                    }
                    // -------

                    try {
                        if (increase) {
                            grzalka.podniesTemperatura();
                        } else {
                            grzalka.obnizTemperatura();
                        }

                        int currentCount = changeCounter.incrementAndGet();
                        System.out.println("Wątek " + threadId + " zmienił temperaturę (" +
                                          (increase ? "+" : "-") + "1). Zmiana nr " + currentCount);
                    } catch (PropertyVetoException e) {
                        System.out.println("Wątek " + threadId + ": Termostat zablokował zmianę - " + e.getMessage());

                        // Jeśli zmiana została zablokowana, spróbuj zmienić temperaturę w przeciwnym kierunku następnym razem
                        preferIncrease = !preferIncrease;
                        streakCounter = 0;
                    }

                    // Zasypanie na losowy kwant czasu
                    int sleepTime = random.nextInt(1500) + 500;
                    System.out.println("Wątek " + threadId + " idzie spać na " + sleepTime + "ms");
                    Thread.sleep(sleepTime);

                } catch (InterruptedException e) {
                    Thread.currentThread().interrupt();
                    System.out.println("Wątek " + threadId + " został przerwany.");
                    break;
                }
            }

            System.out.println("Wątek " + threadId + " zakończył działanie.");
        }
    }
}
