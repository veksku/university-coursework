package bolnica;

public class Grip extends ZaraznaBolest{

    public Grip(int duzinaBolesti) {
        super(duzinaBolesti);
    }

    public Grip (Grip g){
        super(g.getDuzinaBolesti());
    }



    @Override
    public String toString() {
        return "Boluje od: Grip traje: " + this.getDuzinaBolesti();
    }
}
