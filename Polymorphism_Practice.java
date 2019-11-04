package gspractice;

class A
{
    void fnc()
    {
        System.out.println("RoflA");
    }

}

class B extends A
{
    void fnc()
    {
        System.out.println("RoflB");
    }

    void snap()
    {
        System.out.println("SNAP A");
    }
}

class D
{
    public static void main(String[] args) {
        A a = new B();
    }
}