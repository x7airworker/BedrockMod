package bedrock;

import java.util.List;
import java.util.stream.Collectors;

public class Loader {
    public static void main(String[] args) {
        System.out.println("Hello from Java!");
    }

    public static void fireEvent(String name, List<Object> args) {
        System.out.println("Received " + name + " " + args.stream().map(Object::toString).collect(Collectors.joining(",")));
        // TODO: fire Event through Java EventBus
    }
}
