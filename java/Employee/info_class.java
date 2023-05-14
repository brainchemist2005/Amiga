public class info_class
{
    private String CIN;
    public String name;

    public info_class(String CIN)
    {
        this.CIN = CIN;
    }

    public String toString()
    {
        return name + "-" + CIN;
    }

}