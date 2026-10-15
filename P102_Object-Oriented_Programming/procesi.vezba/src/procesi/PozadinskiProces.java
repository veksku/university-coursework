package procesi;

public class PozadinskiProces extends Proces {
    private boolean sys;

    public PozadinskiProces(int pid, String naziv, int mb, boolean sys) {
        super(pid, naziv, mb);
        this.sys = sys;
    }

    public boolean isSys() {
        return sys;
    }

    @Override
    public String toString() {
        return super.toString() + (sys ? " (System)" : "");
    }
}
