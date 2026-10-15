package nastava;

public class Tekstualni extends NastavniMaterijal{
    private boolean prateciSadrzaj;

    public Tekstualni(String naslov, String format, boolean prateciSadrzaj) {
        super(naslov, format);
        this.prateciSadrzaj = prateciSadrzaj;
    }

    @Override
    public boolean zaOcenu(String kriterijum) {
        return kriterijum.equals(getFormat()) || (prateciSadrzaj && kriterijum.equals("da")) || (!prateciSadrzaj && kriterijum.equals("ne"));
    }

    @Override
    public String toString() {
        return getNaslov() + " (" + getFormat() + ")" + ((prateciSadrzaj) ? ((this.getFormat().equals("pdf")) ? " + za radoznale" : " + domaci") : "" ) + "\n";
    }
}
