package procesi;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.*;

public class MenadzerProcesa {
    private Map<Integer, Proces> procesi = new TreeMap<>();

    public boolean ucitajProcese(String putanja){
        try{
            List<String> linije = Files.readAllLines(Paths.get(putanja));

            for(String linija : linije) {
                String[] podaci = linija.split(",");
                int pid = Integer.parseInt(podaci[1].trim());
                String naziv = podaci[2].trim();
                int mb = Integer.parseInt((podaci[3].trim()));

                if(podaci[0].trim().equals("A")){
                    int cpu = Integer.parseInt(podaci[4].trim());
                    procesi.put(pid, new AktivanProces(pid, naziv, mb, cpu));
                }
                else{
                    boolean sistemski = podaci.length == 5;
                    procesi.put(pid, new PozadinskiProces(pid, naziv, mb, sistemski));
                }
            }
            return true;
        }
        catch (IOException e){
            e.printStackTrace();
            return false;
        }
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();

        List<Proces> listaProcesa = new ArrayList<>(procesi.values());

        listaProcesa.sort((o1, o2) -> {
            if(o1 instanceof AktivanProces && o2 instanceof PozadinskiProces) {
                return -1;
            }
            else if (o1 instanceof PozadinskiProces && o2 instanceof AktivanProces) {
                return 1; //menjaju se mesta
            }
            else return o2.getMb() - o1.getMb();
        });

        for (Proces p : listaProcesa){
            sb.append(p).append("\n");
        }

        return sb.toString();
    }

    public Proces memorijskiNajzahtevniji(int gornjaGranica){
        Proces najzahtevniji = null;

        if(gornjaGranica == 0){
            for(Proces p : procesi.values())
                if(najzahtevniji == null)
                    najzahtevniji = p;
                else if(p.getMb() > najzahtevniji.getMb())
                    najzahtevniji = p;
        }
        else{
            for(Proces p : procesi.values())
                if(p.getMb() < gornjaGranica) {
                    if (najzahtevniji == null)
                        najzahtevniji = p;
                    else if (p.getMb() > najzahtevniji.getMb())
                        najzahtevniji = p;
                }
        }
        return najzahtevniji;
    }

    public List<Proces> sistemskiProcesi(){
        List<Proces> sistemski = new ArrayList<>();

        for(Proces p : procesi.values()){
            if(p instanceof PozadinskiProces && ((PozadinskiProces) p).isSys()){
                sistemski.add(p);
            }
        }
        return sistemski.size() == 0 ? null : sistemski;
    }

    public int ukupnaIskoriscenostCPU(){ // mozda ne radi
        int cpu = 0;

        for(Proces p : procesi.values()){
            if(p instanceof AktivanProces)
                cpu += ((AktivanProces) p).getIskoriscenostCPU();
        }
        return cpu;
    }

    public boolean zaustaviProces(int pid){
        return procesi.remove(pid) == null;
    }
}


