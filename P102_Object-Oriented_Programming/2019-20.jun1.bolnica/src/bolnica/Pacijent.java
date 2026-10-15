package bolnica;

import java.util.Objects;

public class Pacijent implements Izleciv{
    private String ime, prezime;
    private int brKnjizice, duzinaLecenja;
    private boolean zarazen;
    private ZaraznaBolest dijagnoza;

    public Pacijent(String ime, String prezime, int brKnjizice, ZaraznaBolest dijagnoza) {
        this.ime = ime;
        this.prezime = prezime;
        this.brKnjizice = brKnjizice;
        this.duzinaLecenja = 0;
        this.zarazen = false;
        this.dijagnoza = dijagnoza;
    }

    public void setZarazen(boolean zarazen) {
        this.zarazen = zarazen;
    }

    public boolean isZarazen() {
        return zarazen;
    }

    public ZaraznaBolest getDijagnoza() {
        return dijagnoza;
    }

    public void setDuzinaLecenja(int duzinaLecenja) {
        this.duzinaLecenja = duzinaLecenja;
    }

    @Override
    public boolean izlecen() {
        return duzinaLecenja >= this.dijagnoza.getDuzinaBolesti();
    }

    @Override
    public void leci(int brojDana) {
        duzinaLecenja += brojDana;
    }

    @Override
    public String toString() {
        return "Id: " + brKnjizice + " " + ime + " " + prezime + (izlecen() ? "" : "\n" + dijagnoza.toString() + " Vreme do izlecenja " + (dijagnoza.getDuzinaBolesti() - duzinaLecenja));
    }
}
