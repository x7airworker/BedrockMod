package bedrock;

public class FunctionPointer<T> extends Pointer<T> {
    public FunctionPointer(long address) {
        super(address);
    }

    public native T invoke(Class<T> returnType, Object... args);
}
