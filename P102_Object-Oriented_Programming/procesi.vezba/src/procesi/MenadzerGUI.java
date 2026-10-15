package procesi;

import javafx.application.Application;
import javafx.geometry.Insets;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

import java.util.List;


public class MenadzerGUI extends Application {

    private MenadzerProcesa menadzerProcesa = new MenadzerProcesa();

    public static void main(){
        launch();
    }

    public void start(Stage primaryStage) throws Exception{
        HBox root = new HBox(10);
        root.setPadding(new Insets(10));

        TextArea taIspis = new TextArea();
        VBox vBox = new VBox(10);

        root.getChildren().addAll(taIspis, vBox);

        Button btnIzlistaj = new Button("Izlistaj");
        Button btnMem = new Button("Memorijski najzahtevniji");
        Button btnSistemski = new Button("Sistemski procesi");
        Button btnCPU = new Button("Ukupna iskoriscenost CPU");
        Button btnZaustavi = new Button("Zaustavi proces");
        TextField tfUnos = new TextField();

        vBox.getChildren().addAll(btnIzlistaj, btnMem, btnSistemski, btnCPU, tfUnos, btnZaustavi);

        if(menadzerProcesa.ucitajProcese("procesi.txt")){
            taIspis.setText("Procesi su ucitani\n\n");
        }
        else{
            taIspis.setText("Greska prilikom ucitavanja procesa\n");
        }

        btnIzlistaj.setOnAction(e -> {
            taIspis.appendText(menadzerProcesa.toString() + "\n");
        });

        btnMem.setOnAction(e -> {
            int gornjaGranica;
            try{
                if(tfUnos.getText().trim().equals(""))
                    gornjaGranica = 0;
                else
                    gornjaGranica = Integer.parseInt(tfUnos.getText().trim());
            }
            catch(Exception ex){
                gornjaGranica = 0;
            }
            taIspis.appendText("Memorijski najzahtevniji: \n" + menadzerProcesa.memorijskiNajzahtevniji(gornjaGranica) + "\n\n");
        });

        btnSistemski.setOnAction(e -> {
            List<Proces> procesi = menadzerProcesa.sistemskiProcesi();
            taIspis.appendText("Sistemski procesi:\n");
            if(procesi != null){
                for(Proces p : procesi){
                    taIspis.appendText(p.toString() + "\n");
                }
            }

            taIspis.appendText("\n");
        });

        btnCPU.setOnAction(e -> {
            taIspis.appendText("Ukupna iskoriscenost CPU: " + menadzerProcesa.ukupnaIskoriscenostCPU() + "%\n\n");
        });

        btnZaustavi.setOnAction(e -> {
            try{
                int pid = Integer.parseInt(tfUnos.getText().trim());
                if(!menadzerProcesa.zaustaviProces(pid)){
                    taIspis.appendText("Zaustavljen proces: " + pid + "\n\n");
                }
                else
                    taIspis.appendText("Los pid: " + tfUnos.getText().trim() + "\n\n");
            }
            catch (Exception ex){
                taIspis.appendText("Los pid: " + tfUnos.getText().trim() + "\n\n");
            }
        });

        primaryStage.setScene(new Scene(root, 700, 500));
        primaryStage.setTitle("Proces menadzer");
        primaryStage.show();
    }
}
