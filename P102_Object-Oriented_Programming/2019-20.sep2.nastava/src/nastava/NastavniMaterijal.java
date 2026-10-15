package nastava;

public abstract class NastavniMaterijal implements Comparable<NastavniMaterijal> {
    private String naslov;
    private String format;

    public NastavniMaterijal(String naslov, String format) {
        this.naslov = naslov;
        this.format = format;
    }

    public String getNaslov() {
        return naslov;
    }

    public String getFormat() {
        return format;
    }

    public abstract boolean zaOcenu(String kriterijum);

    public int compareTo(NastavniMaterijal o) {
        if ((this.format.equals("pdf") || this.format.equals("zip")) && o.format.equals("mp4")){
            return -1;
        }
        else if((o.format.equals("pdf") || o.format.equals("zip")) && this.format.equals("mp4")) {
            return 1;
        }
        else if(this.format.equals("pdf") && o.format.equals("zip")) {
            return -1;
        }
        else if(o.format.equals("pdf") && this.format.equals("zip")){
            return 1;
        }
        return this.naslov.compareTo(o.naslov);
    }
}
