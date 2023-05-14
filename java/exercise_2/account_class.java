import java.util.ArrayList;

class account_class
{
    private int ID;
    private String name, phone;
    ArrayList<Account> Accounts;

    public account_class(int ID,String name,String phone)
    {
        this.ID = ID;
        this.name = name;
        this.phone = phone;

        Accounts = new ArrayList<>();
    }

    public boolean addAccount(Account account)
    {
        Accounts.add(account);
        return true;
    }

    public boolean removeAccount(int ID)
    {
        for(Account account : Accounts)
        {
            if(account.GetID() == ID)
            {
                Accounts.remove(account);
                return true;
            }
        }
        return false;
    }

    public String toString()
    {
        String code;
        
        code = ID +"-" + name + "-" + phone;

        for(Account account : Accounts)
        {
            code += account.toString() + "\n";
        }

        return code;
    }

    public int getID()
    {
        return this.ID;
    }

    public void setID(int ID)
    {
        this.ID = ID;
    }

    public String getName()
    {
        return this.name;
    }
    
    public void setName(String name)
    {
        this.name = name;
    }

    public String getPhone()
    {
        return this.phone;
    }

    public void setPhone(String phone)
    {
        this.phone = phone;
    }
}