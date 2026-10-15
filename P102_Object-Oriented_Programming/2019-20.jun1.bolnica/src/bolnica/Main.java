package bolnica;

import javafx.application.Application;
import javafx.geometry.Insets;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;
import javafx.stage.Stage;
import java.util.List;

public class Main extends Application {

    private Bolnica bolnica = new Bolnica();

    public static <T> void ispis(List<T> pacijenti, TextArea ta){
        ta.setText("");
        for(T p : pacijenti){
           ta.appendText(p.toString() + "\n");
        }
        ta.appendText("\n");
    }

    public void start(Stage primaryStage) throws Exception {
        HBox root = new HBox(10);
        root.setPadding(new Insets(10));
        VBox vBox1 = new VBox(10);
        VBox vBox2 = new VBox(10);

        root.getChildren().addAll(vBox1, vBox2);
        Button btnUcitaj = new Button("Ucitaj pacijente");
        Button btnSledeci = new Button("Sledeci");
        Label lblBrojDana = new Label("Broj dana:");
        TextField tfBrojDana = new TextField();
        Button btnUbrzaj = new Button("Ubrzaj vreme!");
        Label lblGreska = new Label("Greska!");
        lblGreska.setVisible(false);
        lblGreska.setTextFill(Color.web("RED"));
        RadioButton rbSve = new RadioButton("Sve");
        rbSve.setSelected(true);
        RadioButton rbKorona = new RadioButton("Korona");
        ToggleGroup tg = new ToggleGroup();
        rbSve.setToggleGroup(tg);
        rbKorona.setToggleGroup(tg);
        Button btnPrikazi = new Button("Prikazi statistike");
        Button btnUnesi = new Button("Unesi");

        vBox1.getChildren().addAll(btnUcitaj, btnSledeci, lblBrojDana, tfBrojDana, btnUbrzaj, lblGreska, rbSve, rbKorona, btnPrikazi, btnUnesi);

        Label lblCekaju = new Label("Cekaju:");
        TextArea taCekaju = new TextArea();
        Label lblIzolacija = new Label("U izolaciji:");
        TextArea taIzolacija = new TextArea();
        Label lblZdravi = new Label("Zdravi:");
        TextArea taZdravi = new TextArea();

        vBox2.getChildren().addAll(lblCekaju, taCekaju, lblIzolacija, taIzolacija, lblZdravi, taZdravi);

        btnUcitaj.setOnAction(e -> {
            try {
                bolnica.ucitaj();
                ispis(bolnica.getCekaonica(), taCekaju);
                ispis(bolnica.getIzolacija(), taIzolacija);
                ispis(bolnica.getZdravi(), taZdravi);
            }
            catch (Exception ex){
                taCekaju.appendText("Greska!");
            }
        });

        btnSledeci.setOnAction(e -> {
            try {
                lblGreska.setVisible(false);
                bolnica.sledeci();
                ispis(bolnica.cekaonica, taCekaju);
                ispis(bolnica.izolacija, taIzolacija);
                ispis(bolnica.zdravi, taZdravi);
            }
            catch (Exception ex){}
        });

        btnUbrzaj.setOnAction(e -> {
            int brojDana = 0;
            lblGreska.setVisible(false);
            try{
                brojDana = Integer.parseInt(tfBrojDana.getText().trim());
            }
            catch (Exception ex){
                lblGreska.setVisible(true);
            }
            if(brojDana > 0) {
                for (Pacijent p : bolnica.izolacija) {
                    p.leci(brojDana);
                    if (p.izlecen()) {
                        bolnica.zdravi.add(p);
                        bolnica.izolacija.remove(p);
                    }
                }
                ispis(bolnica.cekaonica, taCekaju);
                ispis(bolnica.izolacija, taIzolacija);
                ispis(bolnica.zdravi, taZdravi);
            }
        });

        btnPrikazi.setOnAction(e -> {
            lblGreska.setVisible(false);
            try{
                if(rbSve.isSelected()){
                    double brIzolacija = 0.0, brZdravih = 0.0;
                    for(Pacijent p : bolnica.izolacija) {
                        brIzolacija++;
                    }
                    for(Pacijent p : bolnica.zdravi){
                        brZdravih++;
                    }
                    double procenatZdravih = brZdravih/(brIzolacija+brZdravih);
                    double procenatZarazenih = brIzolacija/(brIzolacija+brZdravih);
                    taIzolacija.appendText("\n\nProcenat zarazenih u odnosu na broj testiranih: " + (procenatZarazenih*100) + "%" );
                    taZdravi.appendText("\n\nProcenat izlecenih u odnosu na broj testiranih: " + (procenatZdravih*100) + "%" );
                }
                else {
                    double brTestiranih = 0.0, brZdravih = 0.0;
                    for(Pacijent p : bolnica.izolacija) {
                        if( p.getDijagnoza() instanceof Korona ) {
                            brTestiranih++;
                        }
                    }
                    for(Pacijent p : bolnica.zdravi){
                        if( p.getDijagnoza() instanceof Korona) {
                            brTestiranih++;
                            brZdravih++;
                        }
                    }
                    double procenatZdravih = brZdravih/brTestiranih;
                    double procenatZarazenih = 1 - procenatZdravih;
                    taIzolacija.appendText("\nProcenat zarazenih u odnosu na broj testiranih: " + (procenatZarazenih*100) + "%\n" );
                    taZdravi.appendText("\nProcenat izlecenih u odnosu na broj testiranih: " + (procenatZdravih*100) + "%\n" );
                }

            }
            catch (Exception ex){
                ex.printStackTrace();
            }
        });

        btnUnesi.setOnAction(e -> {
            try{
                bolnica.unesi();
            }
            catch (Exception ex){
                ex.printStackTrace();
            }
        });

        primaryStage.setScene(new Scene(root, 750, 650));
        primaryStage.setTitle("Bolnica");
        primaryStage.show();
    }
}
