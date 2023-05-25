import java.io.File;
import java.io.FileInputStream;
//import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
//import java.io.ObjectOutputStream;
//import java.io.Serializable;

public class poradnik extends ksiazka
{
    private String category;
    private String language;
    private int pages;

    //*******************************************

    public poradnik()
    {
        super();
        category = "";
        language = "";
        pages = 0;
    }

    public poradnik(String n, String a, int y, String c, String l, int p)
    {
        super(n, a, y);
        category = c;
        language = l;
        pages = p;
    }

    public String toString()
    {
        return super.toString() + "\n[ category: " + category + " | language: " + language + " | pages: " + Integer.toString(pages) + "]";        
    }

    //*******************************************

    public String getCategory() {return category;}
    public String getLanguage() {return language;}
    public int getPages() {return pages;}

    public void setCategory(String c) {category = c;}
    public void setLanguage(String l) {language = l;}
    public void setPages(int p) {pages = p;}

    //*******************************************

    public void writeToFile(File f) throws IOException
    {
        super.writeToFile(f);
    }
    
    public void readFromFile(File f) throws IOException, ClassNotFoundException
    {
        FileInputStream fis = new FileInputStream(f);
        ObjectInputStream ois = new ObjectInputStream(fis);
        poradnik wczytana = (poradnik)ois.readObject();

        title = wczytana.getTitle();
        author = wczytana.getAuthor();
        year = wczytana.getYear();
        category = wczytana.getCategory();
        language = wczytana.getLanguage();
        pages = wczytana.getPages();

        ois.close();
        fis.close();
    }
}
