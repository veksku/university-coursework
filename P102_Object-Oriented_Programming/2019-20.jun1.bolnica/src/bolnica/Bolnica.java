package bolnica;

import javafx.scene.chart.ScatterChart;

import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;
import java.util.ArrayList;
import java.util.List;

public class Bolnica {
    List<Pacijent> cekaonica = new ArrayList<>();
    List<Pacijent> izolacija = new ArrayList<>();
    List<Pacijent> zdravi = new ArrayList<>();

    public List<Pacijent> getCekaonica() {
        return cekaonica;
    }

    public List<Pacijent> getIzolacija() {
        return izolacija;
    }

    public List<Pacijent> getZdravi() {
        return zdravi;
    }

//    public void setCekaonica(List<Pacijent> cekaonica) {
//        this.cekaonica = cekaonica;
//    }
//
//    public void setIzolacija(List<Pacijent> izolacija) {
//        this.izolacija = izolacija;
//    }
//
//    public void setZdravi(List<Pacijent> zdravi) {
//        this.zdravi = zdravi;
//    }

    public void ucitaj(){
            try {
                List<String> linije = Files.readAllLines(Paths.get("pacijenti.txt"));

                int brKnjizice = 0;

                for (String linija : linije) {
                    String[] podaci = linija.split(",");
                    String ime = podaci[0].trim();
                    String prezime = podaci[1].trim();
                    String vrstaBolesti = podaci[2].trim();
                    int brojDana = Integer.parseInt(podaci[3].trim());
                    if (vrstaBolesti.equals("k")) {
                        boolean imaSimptome = podaci[4].trim().equals("da");
                        Korona bolest = new Korona(brojDana, imaSimptome);
                        cekaonica.add(new Pacijent(ime, prezime, brKnjizice, bolest));
                    } else if (vrstaBolesti.equals("g")) {
                        Grip bolest = new Grip(brojDana);
                        cekaonica.add(new Pacijent(ime, prezime, brKnjizice, bolest));
                    }
                    brKnjizice++;
                }
                cekaonica.sort((o1, o2) -> {
                    //vraca 0 ako su jednaki, <0 ako je o1 manji od o2, >0 ako je o1 veci od o2 i ovde menjaju mesta
                    if(o1.getDijagnoza() instanceof Korona && o2.getDijagnoza() instanceof Grip)
                        return -1;
                    else if(o1.getDijagnoza() instanceof Grip && o2.getDijagnoza() instanceof Korona)
                        return 1;
                    else return o2.getDijagnoza().getDuzinaBolesti() - o1.getDijagnoza().getDuzinaBolesti();
                });
            }
            catch (IOException e){
                e.printStackTrace();
            }
    }

    public void sledeci(){
        Pacijent prvi = cekaonica.get(0);

        if (prvi.getDijagnoza() instanceof Grip) {
            izolacija.add(prvi);
            prvi.setZarazen(true);
        }
        else if (prvi.getDijagnoza() instanceof Korona && ((Korona) prvi.getDijagnoza()).test()) {
            izolacija.add(prvi);
            prvi.setZarazen(true);
        }
        else {
            prvi.getDijagnoza().setDuzinaBolesti(0);
            prvi.setDuzinaLecenja(0);
            zdravi.add(prvi);
        }
        cekaonica.remove(0);
    }

    public void unesi() {
        try {
//            FileWriter writer = new FileWriter("izvestaj.txt");
//            PrintWriter printWr = new PrintWriter(writer);
//            for (Pacijent p : cekaonica) printWr.print(p.toString());
//            for (Pacijent p : izolacija) printWr.print(p.toString());
//            for (Pacijent p : zdravi) printWr.print(p.toString());
            Path izlaznaPutanja = Paths.get("izvestaj.txt");
            List<String> linije = new ArrayList<>();;
            linije.add("Cekaju:\n");
            for (Pacijent p : cekaonica)
                linije.add(p.toString());
            linije.add("\nU izolaciji:\n");
            for (Pacijent p : izolacija)
                linije.add(p.toString());
            linije.add("\nZdravi:\n");
            for (Pacijent p : zdravi)
                linije.add(p.toString());

            Files.write(izlaznaPutanja, linije, StandardOpenOption.TRUNCATE_EXISTING, StandardOpenOption.CREATE);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
