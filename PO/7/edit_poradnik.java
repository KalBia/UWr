import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.File;
import java.io.IOException;

public class edit_poradnik extends JFrame implements ActionListener
{
    private poradnik K;
    private File F;

    private Container kontener;
    private JLabel title_label;
    private JLabel author_label;
    private JLabel year_label;
    private JLabel category_label;
    private JLabel language_label;
    private JLabel pages_label;
    private JTextField title;
    private JTextField author;
    private JTextField year;
    private JTextField category;
    private JTextField language;
    private JTextField pages;
    private JButton save;

    //*******************************************

    public edit_poradnik(poradnik k, File f)
    {
        K = new poradnik(k.getTitle(), k.getAuthor(), k.getYear(), k.getCategory(), k.getLanguage(), k.getPages());
        F = f;

        // GLOWNE OKIENKO
        setTitle("EDIT HANDBOOK");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        kontener = getContentPane();
        kontener.setLayout(new GridLayout(7, 2));

        // EDYCJA TYTULU
        title_label = new JLabel("Title");
        kontener.add(title_label);

        title = new JTextField(K.getTitle(), 40);
        kontener.add(title);

        // EDYCJA AUTORA
        author_label = new JLabel("Author");
        kontener.add(author_label);

        author = new JTextField(K.getAuthor(), 40);
        kontener.add(author);

        // EDYCJA ROKU WYDANIA
        year_label = new JLabel("Year");
        kontener.add(year_label);

        year = new JTextField(Integer.toString(K.getYear()), 40);
        kontener.add(year);

        // EDYCJA KATEGORII
        category_label = new JLabel("Category");
        kontener.add(category_label);

        category = new JTextField(K.getCategory(), 40);
        kontener.add(category);

        // EDYCJA JEZYKA
        language_label = new JLabel("Language");
        kontener.add(language_label);

        language = new JTextField(K.getLanguage(), 40);
        kontener.add(language);

        // EDYCJA LICZBY STRON
        pages_label = new JLabel("Pages");
        kontener.add(pages_label);

        pages = new JTextField(Integer.toString(K.getPages()), 40);
        kontener.add(pages);

        // PRZYCISK ZAPISZ
        save = new JButton("Save");
        save.addActionListener(this);
        kontener.add(save);

        // ZAKONCZENIE
        pack();
        setVisible(true);
    }

    //*******************************************

    public void actionPerformed(ActionEvent e)
    {
        K.setTitle(title.getText());
        K.setAuthor(author.getText());
        K.setYear(Integer.parseInt(year.getText()));
        K.setCategory(category.getText());
        K.setLanguage(language.getText());
        K.setPages(Integer.parseInt(pages.getText()));

        try 
        {
            K.writeToFile(F);
        } 
        catch (IOException e1) 
        {
            System.err.println("Problem with writing to file");
        }
    }
}
