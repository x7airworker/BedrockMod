package bedrock;

public class Loader {
    public static void main(String[] args) {
        System.out.println("Hello from Java!");
        FunctionPointer<Void> ptr = new FunctionPointer<>(0x0075ef50);
        ptr.invoke(Void.class, "Hallo über printf");
    }
}
