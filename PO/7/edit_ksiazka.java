import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.File;
import java.io.IOException;

public class edit_ksiazka extends JFrame implements ActionListener
{
    private ksiazka K;
    private File F;

    private Container kontener;
    private JLabel title_label;
    private JLabel author_label;
    private JLabel year_label;
    private JTextField title;
    private JTextField author;
    private JTextField year;
    private JButton save;

    //*******************************************

    public edit_ksiazka(ksiazka k, File f)
    {
        K = new ksiazka(k.getTitle(), k.getAuthor(), k.getYear());
        F = f;

        // GLOWNE OKIENKO
        setTitle("EDIT BOOK");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        kontener = getContentPane();
        kontener.setLayout(new GridLayout(4, 2));

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
