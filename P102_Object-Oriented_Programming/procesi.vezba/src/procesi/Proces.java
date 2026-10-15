package procesi;

public abstract class Proces {
    private int pid;
    private String naziv;
    private int mb;

    public Proces(int pid, String naziv, int mb) {
        this.pid = pid;
        this.naziv = naziv;
        this.mb = mb;
    }

    public int getPid() {
        return pid;
    }

    public String getNaziv() {
        return naziv;
    }

    public int getMb() {
        return mb;
    }

    @Override
    public String toString() {
        return "[" + this.getPid() + "] " + this.getNaziv() + " | " + this.getMb() + "MB";
    }
}
