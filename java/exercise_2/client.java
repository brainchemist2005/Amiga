import java.util.Scanner;

public class client
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        account_class[] clients = new account_class[2];

        clients[0] = new account_class(103879,"Zakariae","+212659417551");
        clients[1] = new account_class(23455,"LaHoucine","+212661091615");

        clients[0].addAccount(new Account(223344,5000,1.5));
        clients[0].addAccount(new Account(567833,10000,2.5));

        clients[1].addAccount(new Account(987678,3000,3.5));
        clients[1].addAccount(new Account(484328,50000,5.5));


        for(int i=0 ; i<clients.length ; i++)
        {
            System.out.println(clients[i]);
        }

    }
}