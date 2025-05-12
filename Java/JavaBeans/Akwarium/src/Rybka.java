import java.beans.*;
import java.io.Serializable;
import java.lang.ref.WeakReference;
import java.util.concurrent.atomic.AtomicBoolean;

public class Rybka implements PropertyChangeListener, Serializable {
    private String gatunek = null;
    private int[] zakresTemperatur = new int[]{10, 40};
    private final AtomicBoolean alive = new AtomicBoolean(true);
    private WeakReference<Grzalka> grzalkaRef;
    // Dlaczego weak? Bo inaczej będzie zapętlona relacja strong referencji i nie będzie
    // się dało wrzucić tych obiektów do garbage collectora.
    // Grzałka ma referencję na słuchaczy!

    public Rybka(String gatunek, int[] zakresTemperatur, Grzalka grzalka) {
        this.gatunek = gatunek;

        if (zakresTemperatur.length != 2) {
            throw new IllegalArgumentException("Musisz podać dokładnie dwie liczby: granicę dolną i górną");
        }
        if (zakresTemperatur[0] > 20) {
            throw new IllegalArgumentException("Dolna granica nie może być większa niż 20");
        }
        if (zakresTemperatur[1] < 20) {
            throw new IllegalArgumentException("Górna granica nie może być mniejsza niż 20");
        }
        this.zakresTemperatur = zakresTemperatur.clone();

        this.grzalkaRef = new WeakReference<>(grzalka);
        grzalka.addPropertyChangeListener(this);
    }

    // -----------------------------------------------------------

    public String getGatunek() {
        return gatunek;
    }

    public void setGatunek(String gatunek) {
        this.gatunek = gatunek;
    }

    public int[] getZakresTemperatur() {
        return zakresTemperatur.clone();
    }

    public void setZakresTemperatur(int[] zakresTemperatur) {
        this.zakresTemperatur = zakresTemperatur.clone();
    }

    public boolean getAlive() {
        return alive.get();
    }

    @Override
    public String toString() {
        return "rybka z gatunku " + gatunek + " żyjąca w temperaturach z zakresu " + zakresTemperatur[0] + "-" + zakresTemperatur[1];
    }

    // ------------------------------------------------------------

    public void propertyChange(PropertyChangeEvent event) {
        if (!alive.get()) {
            return;
        }

        int temperatura = (int)event.getNewValue();
        if (temperatura < zakresTemperatur[0] || temperatura > zakresTemperatur[1]) {
            die();
        }
    }

    private void die() {
        if (!alive.compareAndSet(true, false)) {
            return;
        }

        System.out.println("Rybka " + gatunek + " niestety umarła z powodu złej temperatury");

        final Grzalka grzalka = grzalkaRef != null ? grzalkaRef.get() : null;
        if (grzalka != null) {
            grzalka.removePropertyChangeListener(this);
        }
        grzalkaRef = null;
    }
}
