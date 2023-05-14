import java.util.Date;


class Account
{
    private int ID;
    private double balance, AnnualInterestRate;
    private Date dateCreated;

    public Account (int ID, double balance,double AnnualInterestRate)
    {
        this.ID = ID;
        this.balance = balance;
        this.AnnualInterestRate = AnnualInterestRate;

        dateCreated = new Date();
    }
    
    public boolean withdraw(double amount)
    {
        if(amount > balance)
            return false;

        else
        {
            this.balance = this.balance - amount;
            return true;
        }
    }

    public void deposit(double amount)
    {
        this.balance = this.balance + amount;
    }

    public double GetBalance()
    {
        return this.balance;
    }

    public void SetID(int ID)
    {
        this.ID = ID;
    }

    public int GetID()
    {
        return ID;
    }


    public void SetBalance(double balance)
    {
        this.balance = balance;
    }

    public double GetAnnualIntrestRate()
    {
        return this.AnnualInterestRate;
    }

    public void SetAnnualIntrestRate(double AnnualInterestRate)
    {
        this.AnnualInterestRate = AnnualInterestRate;
    }

    public Date getDateCreated()
    {
        return dateCreated;
    }

    public String toString()
    {
        return ":" + this.ID + " " + this.balance + " " +this.AnnualInterestRate + " " + this.dateCreated; 
    }

}   