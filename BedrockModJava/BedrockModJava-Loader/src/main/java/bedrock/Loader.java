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
        if (name.equals("Minecraft::Init")) {
            Pointer<Object> minecraft = (Pointer<Object>) args.get(0);
            FunctionPointer<Pointer> getLevelPointerFunc = new FunctionPointer<>(0x013b0cd0);
            System.out.println("Pointer to Level " + getLevelPointerFunc.invoke(Pointer.class, minecraft).address);
        }
    }
}
