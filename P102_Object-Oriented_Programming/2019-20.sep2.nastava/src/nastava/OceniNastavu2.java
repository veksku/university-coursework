package nastava;

import javafx.application.Application;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.*;
import java.util.List;

public class OceniNastavu2 extends Application {
    private Map<NastavniMaterijal, OcenaKvaliteta[]> nastavniMaterijal = new TreeMap<>();
    private List<NastavniMaterijal> preporuceno = new ArrayList<>();
    private List<NastavniMaterijal> ocenjeno = new ArrayList<>();

    private static Random random = new Random();

    public OcenaKvaliteta napraviOcKv(String ocene[], int rbr){
        List<Integer> lista = new ArrayList<>();
        OcenaKvaliteta rez = new OcenaKvaliteta(Kvalitet.izBroja(rbr), lista);
        for(String s : ocene)
            rez.dodajOcenu(Integer.parseInt(s));
        return rez;
    }

    public void start(Stage primaryStage) throws Exception {
        VBox root = new VBox(10);
        root.setPadding(new Insets(10));
        VBox vbox1 = new VBox(10);
        VBox vbox2 = new VBox(10);
        HBox hbox3 = new HBox(10);
        VBox vbox4 = new VBox(10);
        HBox hbox5 = new HBox(10);
        HBox hbox6 = new HBox(10);

        root.getChildren().addAll(vbox1,vbox2,hbox3,vbox4,hbox5,hbox6);

        Button btnUcitaj = new Button("Ucitaj");
        vbox1.getChildren().add(btnUcitaj);

        TextArea taNastavniMaterijal = new TextArea();
        vbox2.getChildren().add(taNastavniMaterijal);

        Label lblKriterijum = new Label("Unesite kriterijum pretrage:");
        TextField tfKriterijum = new TextField();
        Button btnPretrazi = new Button("Pretrazi");

        hbox3.getChildren().addAll(lblKriterijum, tfKriterijum, btnPretrazi);
        hbox3.setAlignment(Pos.CENTER);

        TextArea taPreporuka = new TextArea();
        vbox4.getChildren().add(taPreporuka);

        RadioButton rbKorisno = new RadioButton("KORISNO");
        rbKorisno.setSelected(true);
        RadioButton rbInteresantno = new RadioButton("INTERESANTNO");
        RadioButton rbRazumljivo = new RadioButton("RAZUMLJIVO");
        ToggleGroup tg = new ToggleGroup();
        rbKorisno.setToggleGroup(tg);
        rbInteresantno.setToggleGroup(tg);
        rbRazumljivo.setToggleGroup(tg);

        hbox5.getChildren().addAll(rbKorisno, rbInteresantno, rbRazumljivo);
        hbox5.setAlignment(Pos.CENTER);

        Label lblOceni = new Label("Ocenite kvalitet materijala:");
        TextField tfOcena = new TextField();
        Button btnOceni = new Button("Oceni");
        Button btnSveOcene = new Button("Sve ocene");

        hbox6.getChildren().addAll(lblOceni, tfOcena, btnOceni, btnSveOcene);
        hbox6.setAlignment(Pos.CENTER);

        btnUcitaj.setOnAction( e-> {
            try{
                List<String> linije = Files.readAllLines(Paths.get("materijali.txt"));
                for(String linija : linije){
                    String podaci[] = linija.split(", ");
                    String naslov = podaci[0].trim();
                    String format = podaci[1].trim();
                    if(podaci[1].equals("pdf") || podaci[1].equals("zip")){
                        String prateci_sadrzaj = podaci[2].trim();
                        String ocene = podaci[3].trim();
                        String ocenjeno[] = ocene.split(";");
                        String oceneKorisno[] = ocenjeno[0].split(",");
                        String oceneInteresantno[] = ocenjeno[1].split(",");
                        String oceneRazumljivo[] = ocenjeno[2].split(",");

                        if(prateci_sadrzaj.equals("da")) {
                            nastavniMaterijal.put(new Tekstualni(naslov, format, true),
                                    new OcenaKvaliteta[]{napraviOcKv(oceneKorisno, 0), napraviOcKv(oceneInteresantno, 1), napraviOcKv(oceneRazumljivo,2)});
                        }
                        else if(prateci_sadrzaj.equals("ne")) {
                            nastavniMaterijal.put(new Tekstualni(naslov, format, false),
                                    new OcenaKvaliteta[]{napraviOcKv(oceneKorisno, 0), napraviOcKv(oceneInteresantno, 1), napraviOcKv(oceneRazumljivo,2)});
                        }
                    }
                    else{
                        String duzina_trajanja = podaci[2].trim();
                        String broj_pregleda = podaci[3].trim();
                        String broj_svidjanja = podaci[4].trim();
                        String ocene = podaci[5].trim();
                        String ocenjeno[] = ocene.split(";");
                        String oceneKorisno[] = ocenjeno[0].split(",");
                        String oceneInteresantno[] = ocenjeno[1].split(",");
                        String oceneRazumljivo[] = ocenjeno[2].split(",");

                        int duzina, pregledi, svidjanje;
                        duzina = Integer.parseInt(duzina_trajanja);
                        pregledi = Integer.parseInt(broj_pregleda);
                        svidjanje = Integer.parseInt(broj_svidjanja);

                        nastavniMaterijal.put(new Video(naslov, format, duzina, pregledi, svidjanje),
                                new OcenaKvaliteta[]{napraviOcKv(oceneKorisno, 0), napraviOcKv(oceneInteresantno, 1), napraviOcKv(oceneRazumljivo,2)});
                    }
                }
                for (Map.Entry<NastavniMaterijal, OcenaKvaliteta[]> n : nastavniMaterijal.entrySet()){
                    taNastavniMaterijal.appendText(n.getKey().toString());
                    double ocena = 0.0;
                    for(OcenaKvaliteta qq : n.getValue()){
                        taNastavniMaterijal.appendText(qq.toString());
                        ocena += qq.prosecnaOcena();
                    }
                    taNastavniMaterijal.appendText("\n");
                    taNastavniMaterijal.appendText("Prosecna ocena: " + (ocena/3) + "\n\n");
                }
            }
            catch (Exception ex){
                ex.printStackTrace();
            }
        });

//        btnPretrazi.setOnAction( e-> {
//            try {
//                String kriterijum = tfKriterijum.getText();
//                for (Map.Entry<NastavniMaterijal, OcenaKvaliteta[]> n : nastavniMaterijal.entrySet()) {
//                    if (n.getKey().zaOcenu(kriterijum)) {
//                        preporuceno.add(n.getKey());
//                        taPreporuka.appendText(n.getKey().toString());
//                    }
//                }
//                if(preporuceno.size() > 0){
//                    int index = random.nextInt(preporuceno.size());
//                    taPreporuka.appendText("\nOdabrani materijal:" + preporuceno.get(index).getNaslov() + "\n");
//                }
//                preporuceno.clear();
//            }
//            catch (Exception ex){
//                ex.printStackTrace();
//            }
//        });

        primaryStage.setScene(new Scene(root, 600, 500));
        primaryStage.setTitle("Bolnica");
        primaryStage.show();
    }
}
