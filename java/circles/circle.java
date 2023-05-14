class circle
    {
        double radius;
        Point center;

        circle()
        {

        }

        circle(Point center0, double radius0)
        {
            this.center = center0;
            this.radius = radius0;
        }

        double getPerimeter()
        {
            return 2 * Math.PI * this.radius;
        }

        double getArea()
        {
            return Math.PI * this.radius * this.radius;
        }

        void setCenter(Point center)
        {
            this.center = center;
        }

        void setRadius(int radius)
        {   
            this.radius = radius;
        }
    }