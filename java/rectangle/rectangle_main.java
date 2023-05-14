package rectangle;
import java.util.Scanner;

public class rectangle_main
{
    public static void main(String[] args)
    {
        char choice;
        rectangle[] rectangles = new rectangle[3];

        Scanner input = new Scanner(System.in);

        for(int i=0 ; i<3 ; i++)
        {
            System.out.println("Do you want to enter to width and height? (1/0) \n");
            choice = input.next().charAt(0);
            if(choice == '1')
            {
                rectangles[i] = new rectangle(input.nextDouble(),input.nextDouble());
            }
            else
                rectangles[i] = new rectangle();
        }

        for(int i=0 ; i<3 ; i++)
        System.out.println("Rectangle #" + i + " Area: " +rectangles[i].getArea() + " Perimeter: " + rectangles[i].getPerimeter() + " Height: " + rectangles[i].getHeight() + " Width: " + rectangles[i].getWidth()+ "\n");

    }

}