public class recursion {
    static int sum(int x)
    {
        if(x > 0)
            return (x + sum(x-1));

        else
            return x;
    }

    public static void main(String[] args)
    {
        int n = sum(10);

        System.out.println(n);
    }
}
