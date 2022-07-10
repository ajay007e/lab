class ThrowsExample  {
    public static void main(String[] args) throws InterruptedException  {
        Thread.sleep(10000); 
        System.out.println("Exception Throws"); 
        try{
            int x = 10/0;
            System.out.println(x);
          
        } catch (ArithmeticException e){
            System.out.println(e);
        } finally {
            System.out.println("Finally Block is executed");
        }
    
    }
}