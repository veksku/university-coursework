package nastava;

public enum Kvalitet {
    KORISNO(0), INTERESANTNO(1), RAZUMLJIVO(2);

    private int rbr;

    Kvalitet(int rbr) {
        this.rbr = rbr;
    }

    public int getRbr() {
        return rbr;
    }

    public static Kvalitet izBroja(int rbr){
        switch (rbr) {
            case 0: return KORISNO;
            case 1: return INTERESANTNO;
            default: return RAZUMLJIVO;
        }
    }
}
