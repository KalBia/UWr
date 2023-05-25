// Kalina Białek
// lista zadań nr 2: zadanie 1 oraz zadanie 4
// .Net 7.0.201
//**********************************

using System;

//**********************************
// [ ZADANIE 1 ]
//**********************************

class IntStream{

    protected int current_number; // chcemy móc używać tej zmiennej w podklasach

    public IntStream(){
        this.current_number = 0;
    }
    
    virtual public int next(){
        if (eos() == true){
            Console.WriteLine("End of Stream. Can't generate bigger number. Please reset Stream.");
            return current_number;
        }

        int give = current_number;
        current_number++;
        return give;       
    }
            
    virtual public bool eos(){
        if (current_number == Int32.MaxValue){
            return true;
        }
        return false;
    }

    virtual public void reset(){
        current_number = 0;
    }
    
}

//**********************************

class PrimeStream : IntStream{

    public PrimeStream(){
        this.current_number = 2;
    }

    bool is_prime(int check){
        if (check % 2 == 0 && check != 2){
            return false;
        }

        for (int i = 3; i <= (int)check/2; i++){
            if (check % i == 0){
                return false;
            }
        }

        return true;
    }

    override public int next(){
        while (eos() == false && !is_prime(current_number)){
            current_number++;
        }

        if (eos() == true){
            Console.WriteLine("End of Stream. Can't generate bigger prime number. Please reset Stream.");
            return current_number;
        }

        int give = current_number;
        current_number++;
        return give;
    }

    override public void reset(){
        current_number = 2;
    }
}

//**********************************
// skoro poprzednie klasy opierają się na liczbach naturalnych, to
// zakładam, że "liczby losowe" oznaczają "liczby losowe z zakresu liczb naturalnych"

class RandomStream : IntStream{

    Random generate_random;
    // według mojej implementacji RandomStream będzie się resetował do pierszej wylosowanej liczby w streamie
    int start_number; 

    public RandomStream(){
        generate_random = new Random();
        this.start_number = generate_random.Next();
        this.current_number = start_number;
    }

    override public int next(){
        int give = current_number;
        // RandomStream nie będzie generował dwa razy pod rząd tej samej liczby
        while (current_number == give){
            current_number = generate_random.Next();
        }
        return give;
    }

    override public bool eos(){
        return false;
    }

    override public void reset(){
        current_number = start_number;
    }
}

//**********************************

class RandomWordStream{
    
    // resetować będziemy stream do pierwszego wygenerowanego słowa
    string start_word;
    string current_word;
    PrimeStream len_of_word;
    int current_len;

    public RandomWordStream(){
        this.len_of_word = new PrimeStream();
        this.current_len = len_of_word.next();
        this.start_word = generate_word(current_len);
        this.current_word = start_word;
    }

    string generate_word(int len){
        // używając RandomStreamu w mojej implementacji będziemy dostawać słowa, gdzie sąsiednie znaki będą zawsze różne
        RandomStream generator = new RandomStream();
        string new_word = "";

        for (int i = 0; i < len; i++){
            new_word += give_sign(generator.next());
        }

        return new_word;
    }

    char give_sign(int key){
        // mamy 94 sensowne znaki w kodzie ASCII, z których będziemy tworzyć stringi (od 33 do 126);
        key = (key % 94) + 33;
        return (char)key;

        // jeśli treść zadania miała na myśli, że będą to jedynie litery, to proszę zakomentować 
        // powyższe dwa wiersze oraz odkomentować poniższe. Obie wersje działają.
        // Osobiście chyba wolę interpretację z symbolami a nie samymi literami. Ciekawsze hasła do kont
        // można tym generować.

        /*
        key = (key % 52) + 65;
        // ale pomiędzy dużymi i małymi literami w ASCII jest 6 niechcianych znaków; przesuwamy się zatem
        if (key >= 91){ 
            key += 6;
        }
        return (char)key;
        */
    }

    public string next(){
        if (eos() == true){
            Console.WriteLine("End of Stream. Can't generate word with bigger length. Please reset Stream.");
            return current_word;
        }

        string give = current_word;
        current_len = len_of_word.next();
        current_word = generate_word(current_len);
        return give;
    }

    public bool eos(){
        if (current_len == Int32.MaxValue){
            return true;
        }
        return false;
    }

    public void reset(){
        len_of_word = new PrimeStream();
        current_len = len_of_word.next();
        current_word = start_word;
    }
}

//**********************************
//**********************************
// [ ZADANIE 4 ]
//**********************************
// Interpretacja polecenia:
//"Elementami tej listy są kolejne liczby całkowite." - czyli lista[i] = i.
//"w trakcie wywołania metody element(100) budowanych jest pierwszych sto elementów" - czyli nie interesują nas ujemne
// liczby i rozszerzanie tablicy w tamtą stronę == pracujemy na liczbach naturalnych.

class LazyIntList{

    protected int max_indeks;
    protected List<int> lazy_list;

    public LazyIntList(){
        this.max_indeks = 0;
        this.lazy_list = new List<int>();
    }

    public int element(int i){
        if (i > max_indeks){
            expand_list(i);
        }
        // nie jesteśmy w stanie podać indeksu większego niż int, więc nie musimy tego sprawdzać
        // w przeciwieństwie do indeksu z PrimeLazyList...

        return lazy_list[i];
    }

    virtual protected void expand_list(int i){
        if (max_indeks == 0){
            lazy_list.Add(0);
        }

        for (int adding = max_indeks+1; adding <= i; adding++){
            lazy_list.Add(adding);
        }
        
        max_indeks = i;
    }

    public int size(){
        return max_indeks;
    }
}

//**********************************

class LazyPrimeList : LazyIntList{

    int last_prime;

    public LazyPrimeList(){
        this.max_indeks = 0;
        this.lazy_list = new List<int>();
        this.last_prime = 0;
    }

    override protected void expand_list(int i){
        int indeks;
        int adding;
        
        if (max_indeks == 0){
            lazy_list.Add(0);
        }

        for (indeks = max_indeks+1; indeks <= i; indeks++){
            adding = next_prime();

            if (adding == -1){
                Console.WriteLine("Can't generate next prime number - it's out of range.");
                Console.WriteLine("The biggest possible index is:");
                Console.WriteLine(indeks);
                break;
            }

            lazy_list.Add(adding);
            last_prime = adding;
        }
        
        max_indeks = Math.Min(i, indeks); 
        // jeśli for się zakończy wcześniej to chcemy zapamiętać do którego indeksu udało mu się zwiększyć
        // a jeśli wykonał się cały, to indeks == i+1
    }

    int next_prime(){
        int searching = Math.Max(1, last_prime); // dlaczego 1 ??? Bo w wierszu 287 i tak zwiększamy zawsze o 1

        // wejdziemy do środka ifa już po wpisaniu raz Int32.MaxValue do naszej listy, więc możemy wypluwać out of range
        if (searching == Int32.MaxValue){
            return -1;
        }

        searching++; // jeśli w tym momencie otrzymamy Int32.MaxValue, to jest to liczba pierwsza, więc
                    // nie zwiększymy searching w while'u już i nie wyjdziemy poza zakres.

        while (!is_prime(searching)){
            searching++;
        }

        return searching;
    }

    bool is_prime(int check){
        if (check % 2 == 0 && check != 2){
            return false;
        }

        for (int i = 3; i <= (int)check/2; i++){
            if (check % i == 0){
                return false;
            }
        }

        return true;
    }
}

//**********************************
//**********************************

class Program{
    public static void Main(){

        //**********************************

        Console.WriteLine("\nPrezentacja klasy [IntStream]");
        IntStream test_Int = new IntStream();

        Console.WriteLine("\n[.next()]");
        for (int i = 0; i <= 10; i++){
            Console.WriteLine(test_Int.next());
        }

        Console.WriteLine("\n[.eos()]");
        Console.WriteLine(test_Int.eos()); 

        Console.WriteLine("\n[.reset]");
        test_Int.reset();
        for (int i = 0; i <= 10; i++){
            Console.WriteLine(test_Int.next());
        }

        Console.WriteLine("\n\n");

        //**********************************

        Console.WriteLine("\nPrezentacja klasy [PrimeStream]");
        PrimeStream test_Pr = new PrimeStream();

        Console.WriteLine("\n[.next()]");
        for (int i = 0; i <= 10; i++){
            Console.WriteLine(test_Pr.next());
        }

        Console.WriteLine("\n[.eos()]");
        Console.WriteLine(test_Pr.eos());

        Console.WriteLine("\n[.reset]");
        test_Pr.reset();
        for (int i = 0; i <= 10; i++){
            Console.WriteLine(test_Pr.next());
        }

        Console.WriteLine("\n\n");

        //**********************************

        Console.WriteLine("\nPrezentacja klasy [RandomStream]");
        RandomStream test_R = new RandomStream();

        Console.WriteLine("\n[.next()]");
        for (int i = 0; i <= 10; i++){
            Console.WriteLine(test_R.next());
        }

        Console.WriteLine("\n[.eos()]");
        Console.WriteLine(test_R.eos());

        Console.WriteLine("\n[.reset]");
        test_R.reset();
        for (int i = 0; i <= 10; i++){
            Console.WriteLine(test_R.next());
        }

        Console.WriteLine("\n\n");

        //**********************************
        
        Console.WriteLine("\nPrezentacja klasy [RandomWordStream]");
        RandomWordStream test_W = new RandomWordStream();

        Console.WriteLine("\n[.next()]");
        for (int i = 0; i <= 10; i++){
            Console.WriteLine(test_W.next());
        }

        Console.WriteLine("\n[.eos()]");
        Console.WriteLine(test_W.eos());

        Console.WriteLine("\n[.reset]");
        test_W.reset();
        for (int i = 0; i <= 10; i++){
            Console.WriteLine(test_W.next());
        }

        Console.WriteLine("\n\n");

        //**********************************
        //**********************************

        Console.WriteLine("\nPrezentacja klasy [LazyIntList]");
        LazyIntList test_list = new LazyIntList();

        Console.WriteLine("\n");
        Console.WriteLine("element nr 3");
        Console.WriteLine(test_list.element(3));
        Console.WriteLine("size:");
        Console.WriteLine(test_list.size());

        Console.WriteLine("\n");
        Console.WriteLine("element nr 9");
        Console.WriteLine(test_list.element(9));
        Console.WriteLine("size:");
        Console.WriteLine(test_list.size());

        Console.WriteLine("\n");
        Console.WriteLine("element nr 6");
        Console.WriteLine(test_list.element(6));
        Console.WriteLine("size:");
        Console.WriteLine(test_list.size());

        Console.WriteLine("\n");
        Console.WriteLine("element nr 72");
        Console.WriteLine(test_list.element(72));
        Console.WriteLine("size:");
        Console.WriteLine(test_list.size());

        Console.WriteLine("\n");
        Console.WriteLine("element nr 53");
        Console.WriteLine(test_list.element(53));
        Console.WriteLine("size:");
        Console.WriteLine(test_list.size());

        Console.WriteLine("\n\n");

        //**********************************

        Console.WriteLine("\nPrezentacja klasy [LazyPrimeList]");
        LazyPrimeList test_LP = new LazyPrimeList();

        Console.WriteLine("\n");
        Console.WriteLine("element nr 3");
        Console.WriteLine(test_LP.element(3));
        Console.WriteLine("size:");
        Console.WriteLine(test_LP.size());

        Console.WriteLine("\n");
        Console.WriteLine("element nr 9");
        Console.WriteLine(test_LP.element(9));
        Console.WriteLine("size:");
        Console.WriteLine(test_LP.size());

        Console.WriteLine("\n");
        Console.WriteLine("element nr 6");
        Console.WriteLine(test_LP.element(6));
        Console.WriteLine("size:");
        Console.WriteLine(test_LP.size());

        Console.WriteLine("\n");
        Console.WriteLine("element nr 72");
        Console.WriteLine(test_LP.element(72));
        Console.WriteLine("size:");
        Console.WriteLine(test_LP.size());

        Console.WriteLine("\n");
        Console.WriteLine("element nr 53");
        Console.WriteLine(test_LP.element(53));
        Console.WriteLine("size:");
        Console.WriteLine(test_LP.size());

        Console.WriteLine("\n\n");
    }
}