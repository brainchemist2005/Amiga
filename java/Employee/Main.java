import java.util.Scanner;

public class Main
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);

        employee_class employee1 = new employee_class();
        employee_class employee2 = new employee_class();

        employee1.getInfo(input.nextInt(),input.nextDouble());
        employee2.getInfo(input.nextInt(),input.nextDouble());

        System.out.println(employee1.addSal());
        System.out.println(employee1.getSalary() +" "+employee1.getHours() + "\n");

        System.out.println(employee2.addSal());
        System.out.println(employee2.getSalary() +" "+employee2.getHours());

        System.out.println("\nThe Password is : " + employee1.GetPass());
    }
}