import java.util.Scanner;

public class Account_main
{
    public static void main(String[] args)
    {
        boolean status;
        Scanner input = new Scanner(System.in);

        int ID;
        double balance,AnnualInterestRate;

        ID = input.nextInt();
        balance = input.nextDouble();
        AnnualInterestRate = input.nextDouble();

        Account acc = new Account(ID,balance,AnnualInterestRate);

        status = acc.withdraw(2500);
        if(status == true)
            System.out.println("Succesfully withdrawn");
        else
            System.out.println("Not enough funds");

        acc.deposit(3000);
        System.out.println("ID: " + acc.GetID() +" Balance: "+ acc.GetBalance() +" Date: "+ acc.getDateCreated());

    }
}