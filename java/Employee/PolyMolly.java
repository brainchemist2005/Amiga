public class PolyMolly
{
    public static void main(String[] args)
    {
        cars car1 = new cars();
        planes plane1 = new planes();

        plane1.name = "Boing 737";

        car1.name = "Micra Nissan";
        car1.speedTest(200);
        plane1.speedTest(750);

        System.out.println(plane1.type);
    }
}