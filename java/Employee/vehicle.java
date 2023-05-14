class vehicle
{
    double speed;
    String name;
    String type;

    public void speedTest(double speed)
    {   
        if(type == "cars")
        {
            if(speed == 0)
                System.out.println("The "+ name + "isn't moving\n");
            
            else if(speed > 120)
                System.out.println("The "+ name + "is going off limits\n");

            else
                System.out.println("The "+ name + "is going good\n");
        }

        else if(type == "planes")
        {
            if(speed == 0)
                System.out.println("The "+ name + "isn't moving\n");
            
            else if(speed > 800)
                System.out.println("The "+ name + "is going off limits\n");

            else
                System.out.println("The "+ name + "is going good\n");
        }
    }
}