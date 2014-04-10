public class Welcome {

     public static void main(String[] args) {
        System.out.println("Sum of two numbers:" + sum(1,2));
        System.out.println("Welcome to Java!");
     }

     public static int sum( int i, int j){
        int result = 0;
        result = i + j;
        return result;
    }
}
