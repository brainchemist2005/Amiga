package rectangle ;

public class rectangle 
{
    private double width;
    private double height;

    public rectangle()
    {
        this.height = 1.0;
        this.width = 1.0;
    }

    public rectangle(double width,double height)
    {
        this.width = width;
        this.height = height;
    }

    public double getArea()
    {
        return this.height * this.width;
    }

    public double getPerimeter()
    {
        return (2 * (this.height + this.width));
    }

    public void setWidth(double width)
    {
        this.width = width;
    }

    public void setHeight(double height)
    {
        this.height = height;
    }

    public double getHeight()
    {
        return this.height;
    }

    public double getWidth()
    {
        return this.width;
    }
}
