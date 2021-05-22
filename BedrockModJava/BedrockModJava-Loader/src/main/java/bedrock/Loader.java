package bedrock;

public class Loader {
    public static void main(String[] args) {
        System.out.println("Hello from Java!");
    }

    public static void fireEvent(String name/*, Object... args*/) {
        System.out.println("Received " + name);
        // TODO: fire Event through Java EventBus
    }
}
