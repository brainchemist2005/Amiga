import java.util.Scanner;

class employee_class
{
    private int n_hours;
    private double salary;
    private String password;

    Scanner input = new Scanner(System.in);
    info_class employee = new info_class(input.next());


    public void getInfo(int n_hours,double salary)
    {
        this.n_hours = n_hours;
        this.salary = salary;
    }

    public boolean addSal()
    {
        if(this.salary < 5000)
        {
            this.salary += 100;
            return true;
        }
        
        return false;
    }

    public boolean addWork()
    {
        if(this.n_hours > 6)
        {
            this.salary += 5;
            return true;
        }

        return false;
    }

    public int getHours()
    {
        return this.n_hours;
    }

    public double getSalary()
    {
        return this.salary;
    }
    

    public String GetPass()
    {
        employee.name = input.next();
        password = employee.toString();
        return password;
    }
}