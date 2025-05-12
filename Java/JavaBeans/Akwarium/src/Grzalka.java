import java.beans.*;
import java.io.Serializable;
import java.util.concurrent.locks.ReentrantLock;

public class Grzalka implements Serializable {
    private volatile int temperatura = 20;
    private final ReentrantLock temperaturaLock = new ReentrantLock();

    public Grzalka() {
        // pusty konstruktor
    }

    // ---------------------------------------------------------

    public int getTemperatura() {
        return temperatura;
    }

    public void podniesTemperatura() throws PropertyVetoException{
        temperaturaLock.lock();
        try {
            int stara_temperatura = temperatura;
            int nowa_temperatura = Math.min(40, temperatura + 1);
            vcs.fireVetoableChange("temperatura", stara_temperatura, nowa_temperatura);
            this.temperatura = nowa_temperatura;
            pcs.firePropertyChange(new PropertyChangeEvent(this, "temperatura", stara_temperatura, temperatura));

            System.out.println("Temperatura została ZWIEKSZONA do " + temperatura);
        }
        finally {
            temperaturaLock.unlock();
        }
    }

    public void obnizTemperatura() throws PropertyVetoException {
        temperaturaLock.lock();
        try {
            int stara_temperatura = temperatura;
            int nowa_temperatura = Math.max(10, temperatura - 1);
            vcs.fireVetoableChange("temperatura", stara_temperatura, nowa_temperatura);
            this.temperatura = nowa_temperatura;
            pcs.firePropertyChange(new PropertyChangeEvent(this, "temperatura", stara_temperatura, temperatura));

            System.out.println("Temperatura została ZMNIEJSZONA do " + temperatura);
        }
        finally {
            temperaturaLock.unlock();
        }
    }

    @Override
    public String toString() {
        return "Grzalka wskazuje obecnie temperature: " + temperatura;
    }

    // ------------------------------------------------------

    private PropertyChangeSupport pcs = new PropertyChangeSupport(this);
    private VetoableChangeSupport vcs = new VetoableChangeSupport(this);

    public synchronized void addPropertyChangeListener(PropertyChangeListener lst) {
        pcs.addPropertyChangeListener(lst);
    }

    public synchronized void removePropertyChangeListener(PropertyChangeListener lst) {
        pcs.removePropertyChangeListener(lst);
    }

    public PropertyChangeListener[] getPropertyChangeListeners () {
        return pcs.getPropertyChangeListeners();
    }

    public synchronized void addVetoableChangeListener(VetoableChangeListener lst) {
        vcs.addVetoableChangeListener(lst);
    }

    public synchronized void removeVetoableChangeListener(VetoableChangeListener lst) {
        vcs.removeVetoableChangeListener(lst);
    }

    public VetoableChangeListener[] getVetoableChangeListeners () {
        return vcs.getVetoableChangeListeners();
    }
}
