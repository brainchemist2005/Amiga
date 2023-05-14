package squares;

public class square 
{
    
    public static void main(String[] args)
    {
        square_class square1 = new square_class();
        //square_class square2 = new square_class();

        square1.setColor("Blue");

        System.out.println(square1.getColor());

        square1.setlength(5);
        //square2.setlength(10);

        System.out.println(square1.getPerimeter());
        System.out.println(square_class.getNumber_of_squares());

    }
}
