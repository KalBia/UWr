import java.io.File;
import java.io.FileInputStream;
//import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
//import java.io.ObjectOutputStream;
//import java.io.Serializable;

public class czasopismo extends ksiazka
{
    private String type;
    private String category;
    private int pages;

    //*******************************************

    public czasopismo()
    {
        super();
        type = "";
        category = "";
        pages = 0;
    }

    public czasopismo(String n, String a, int y, String t, String c, int p)
    {
        super(n, a, y);
        type = t;
        category = c;
        pages = p;
    }

    public String toString()
    {
        return super.toString() + "\n[ type: " + type + " | category: " + category + " | pages: " + Integer.toString(pages) + " ]";
    }

    //*******************************************

    public String getType() {return type;}
    public String getCategory() {return category;}
    public int getPages() {return pages;}

    public void setType(String t) {type = t;}
    public void setCategory(String c) {category = c;}
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
        czasopismo wczytana = (czasopismo)ois.readObject();

        title = wczytana.getTitle();
        author = wczytana.getAuthor();
        year = wczytana.getYear();
        category = wczytana.getCategory();
        type = wczytana.getType();
        pages = wczytana.getPages();

        ois.close();
        fis.close();
    }
}
