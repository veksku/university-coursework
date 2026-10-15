package procesi;

public class AktivanProces extends Proces {
    private int iskoriscenostCPU;

    public AktivanProces(int pid, String naziv, int mb, int iskoriscenostCPU) {
        super(pid, naziv, mb);
        this.iskoriscenostCPU = iskoriscenostCPU;
    }

    public int getIskoriscenostCPU() {
        return iskoriscenostCPU;
    }

    @Override
    public String toString() {
        return super.toString() + " / " + iskoriscenostCPU + "% CPU";
    }

}
