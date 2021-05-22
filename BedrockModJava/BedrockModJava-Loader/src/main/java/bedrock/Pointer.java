package bedrock;

public class Pointer<T> {
    protected final long address;

    public Pointer(long address) {
        this.address = address;
    }

    public long getAddress() {
        return address;
    }

    @Override
    public String toString() {
        return "Pointer{" +
                "address=" + address +
                '}';
    }
}
