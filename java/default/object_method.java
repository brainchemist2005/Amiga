//Create a Car object named myCar. Call the fullThrottle() and speed() methods on the myCar object, and run the program:

public class object_method
{
    public void fullThrottle()
    {
        System.out.println("The car is going fast");
    }

    public void speed(int x)
    {
        System.out.println("The speed is " + x);
    }
    public static void main(String[] args)
    {
        object_method MyCar = new object_method();
        MyCar.fullThrottle();
        MyCar.speed(100);
    }
}