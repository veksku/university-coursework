package nastava;

import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.List;

public class OcenaKvaliteta {
    private Kvalitet kvalitet;
    List<Integer> ocene;

    public OcenaKvaliteta(Kvalitet kvalitet, List<Integer> ocene) {
        this.kvalitet = kvalitet;
        this.ocene = new ArrayList<>();
    }

    public Kvalitet getKvalitet() {
        return kvalitet;
    }

    public List<Integer> getOcene() {
        return ocene;
    }

    public void dodajOcenu(Integer ocena){
        ocene.add(ocena);
    }

    public double prosecnaOcena(){
        double brojac = 0;
        double rez = 0;
        for(int x : ocene) {
            rez += x;
            brojac++;
        }
        rez = rez/brojac;
        return rez;
    }

    @Override
    public String toString() {
        return getKvalitet() + ": " + prosecnaOcena() + " ";
    }

    public String sveOcene(){
        String result = "kvalitet: [";
        for(int ocena : ocene){
            result += Integer.toString(ocena);
            result += ", ";
        }
        result = result.substring(0, result.length() - 2);
        result += "] (";
        result += prosecnaOcena();
        result += ")";
        return result;
    }
}
