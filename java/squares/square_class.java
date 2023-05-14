package squares;

class square_class 
{
    int length;
    private static int number_of_squares;

    static int getNumber_of_squares()
    {
        return number_of_squares;
    }

    square_class()
    {
        number_of_squares++;
    }

    square_class(int i)
    {
        this.length = i;
        number_of_squares++;
    }

    double getArea()
    {
        return length*length;
    }

    double getPerimeter()
    {
        return length*4;
    }

    void setlength(int i)
    {
        this.length = i;
    }

    private String color_name;

    public void setColor(String color)
    {
        this.color_name = color;
    }

    public String getColor()
    {
        return color_name;
    }

}
