import java.util.Scanner;

public class classes
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        class1[] clients = new class1[5];

        for(int i=0 ; i<clients.length ; i++)
        {
            clients[i].name = input.next();
        }

        System.out.println(clients[0].i);
    }
}