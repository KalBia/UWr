import java.beans.*;
import java.io.Serializable;

public class Termostat implements VetoableChangeListener, Serializable {
    private int minTemperatura = 18;
    private int maxTemperatura = 30;

    public Termostat(Grzalka grzalka) {
        grzalka.addVetoableChangeListener(this);
    }

    // --------------------------------------------------------

    public int getMinTemperatura() {
        return minTemperatura;
    }

    public void setMinTemperatura(int minTemperatura) {
        this.minTemperatura = minTemperatura;
    }

    public int getMaxTemperatura() {
        return maxTemperatura;
    }

    public void setMaxTemperatura(int maxTemperatura) {
        this.maxTemperatura = maxTemperatura;
    }

    @Override
    public String toString() {
        return "Termostat pilnujący temperatury od " + minTemperatura + " do " + maxTemperatura;
    }

    // --------------------------------------------------------------

    public void vetoableChange(PropertyChangeEvent event) throws PropertyVetoException{
        int nowa_temperatura = (int) event.getNewValue();
        if (nowa_temperatura > maxTemperatura) {
            System.out.println("Temperatura byłaby zbyt wysoka! VETO!");
            throw new PropertyVetoException("zbyt wysoka", event);
        }
        else if (nowa_temperatura < minTemperatura) {
            System.out.println("Temperatura byłaby zbyt niska! VETO!");
            throw new PropertyVetoException("zbyt niska", event);
        }
    }

}
