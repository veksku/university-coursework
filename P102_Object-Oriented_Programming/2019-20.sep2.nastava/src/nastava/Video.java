package nastava;

public class Video extends NastavniMaterijal{
    private int duzinaTrajanja;
    private int brPregleda;
    private int brSvidjanja;

    public Video(String naslov, String format, int duzinaTrajanja, int brPregleda, int brSvidjanja) {
        super(naslov, format);
        this.duzinaTrajanja = duzinaTrajanja;
        this.brPregleda = brPregleda;
        this.brSvidjanja = brSvidjanja;
    }

    public int getDuzinaTrajanja() {
        return duzinaTrajanja;
    }

    public int getBrPregleda() {
        return brPregleda;
    }

    public int getBrSvidjanja() {
        return brSvidjanja;
    }

    @Override
    public boolean zaOcenu(String kriterijum) {
        return kriterijum.equals(getFormat()) || brPregleda > Integer.parseInt(kriterijum);
    }

    @Override
    public String toString() {
        return getNaslov() + " (" + getFormat() + ") " + "[" + duzinaTrajanja + "] pregleda: " + brPregleda + " svidjanja: " + brSvidjanja + "\n";
    }
}
