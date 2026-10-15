package bolnica;

import java.util.Random;

public class Korona extends ZaraznaBolest {
    private boolean pokazujeSimptome;

    public Korona(int duzinaBolesti, boolean pokazujeSimptome) {
        super(duzinaBolesti);
        this.pokazujeSimptome = pokazujeSimptome;
    }

    public Korona(Korona k){
        super(k.getDuzinaBolesti());
        this.pokazujeSimptome = k.pokazujeSimptome;
    }

    public boolean isPokazujeSimptome() {
        return pokazujeSimptome;
    }

    public boolean test(){
        Random random = new Random();
        if(pokazujeSimptome)
            return random.nextDouble() < 0.8;
        else
            return (random.nextDouble() < 0.4);
    }

    @Override
    public String toString() {
        return "Boluje od: Korona traje: " + this.getDuzinaBolesti() +
                (isPokazujeSimptome() ? " sa simptomima" : " bez simptoma");
    }
}
