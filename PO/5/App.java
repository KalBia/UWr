// Kalina Białek
// zadanie 1
// VSCode

public class App 
{
    public static void main(String[] args) throws Exception 
    {
        System.out.println("TEST START");

        OrderedList cards = new OrderedList();
        cards.add_element(new Flush());
        cards.add_element(new FourOfKind());
        cards.add_element(new OnePair());
        cards.add_element(new OnePair());
        cards.add_element(new ThreeOfKind());

        System.out.println(cards.toString());
        ListElem card = cards.get_first();
        System.out.println(card.toString());
        card = cards.get_first();
        System.out.println(card.toString());
        card = cards.get_first();
        System.out.println(card.toString());
    }
}
