import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;

public class ksiazka implements Serializable
{
    protected String title;
    protected String author;
    protected int year;

    //*******************************************

    public ksiazka()
    {
        title = "";
        author = "";
        year = 0;
    }

    public ksiazka(String n, String a, int y)
    {
        title = n;
        author = a;
        year = y;
    }

    public String toString()
    {
        return "Ksiazka [ title: " + title + " | author: " + author + " | year: " + Integer.toString(year) + " ]";
    }

    //*******************************************

    public String getTitle() {return title;}
    public String getAuthor() {return author;}
    public int getYear() {return year;}

    public void setTitle(String n) {title = n;}
    public void setAuthor(String a) {author = a;}
    public void setYear(int y) {year = y;}

    //*******************************************

    public void writeToFile(File f) throws IOException
    {
        FileOutputStream fos = new FileOutputStream(f);
        ObjectOutputStream oos = new ObjectOutputStream(fos);
        oos.writeObject(this);

        oos.close();
        fos.close();
    }
    
    public void readFromFile(File f) throws IOException, ClassNotFoundException
    {
        FileInputStream fis = new FileInputStream(f);
        ObjectInputStream ois = new ObjectInputStream(fis);
        ksiazka wczytana = (ksiazka)ois.readObject();

        title = wczytana.getTitle();
        author = wczytana.getAuthor();
        year = wczytana.getYear();

        ois.close();
        fis.close();
    }
}
