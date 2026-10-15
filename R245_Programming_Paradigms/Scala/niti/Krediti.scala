import java.io.File
import java.util.Scanner
import java.util.concurrent.{ConcurrentLinkedQueue, ThreadLocalRandom}
import java.util.concurrent.atomic.AtomicLong

class Sluzbenica(kamata : Int,
                 kapital : AtomicLong,
                 redKlijenata : ConcurrentLinkedQueue[Klijent],
                 zaduzeniKlijenti : ConcurrentLinkedQueue[Klijent])
  extends Thread {
  override def run(): Unit = {
    while(true){
      var k : Klijent = redKlijenata.poll()
      if (k == null)
        return

      println("Klijent " + k.getIme + " razgovara sa sluzbenicom.")
      Thread.sleep(ThreadLocalRandom.current().nextInt(1,5)*1000)
      kapital.synchronized{
        if(k.getPozajmica > kapital.get())
          println("Klijent " + k.getIme + " ne moze dobiti kredit.")
        else{
          k.setDug(k.getPozajmica*((100+kamata.toFloat)/100))
          val novKapital = kapital.get() - k.getPozajmica
          kapital.set(novKapital)
          println("Klijent " + k.getIme + " je dobio kredit u iznosu od " + k.getPozajmica + "e, sa kamatom " + k.getDug + "e.")
          zaduzeniKlijenti.add(k)
        }
      }
    }
  }

}

class Klijent (ime : String, pozajmica : Int){
  var dug: Float = 0

  def getIme = ime
  def getPozajmica = pozajmica
  def getDug = dug

  def setDug(d : Float): Unit = {
    dug = d
  }
}

object Krediti {
  def main(args : Array[String]) : Unit ={
    val sc1 = new Scanner(System.in)

    println("Unesite pocetni kapital banke: ")
    val kapital = new AtomicLong(sc1.nextLong())
    val sacuvanKapital : Float = kapital.get()

    println("Unesite kamatnu stopu: ")
    val kamata = sc1.nextInt()

    println("Unesite broj sluzbenica u ekspozituri: ")
    val sluzbenice = new Array[Sluzbenica](sc1.nextInt())

    val sc2 = new Scanner(new File("datoteke/red_klijenata.txt"))

    val redKlijenata = new ConcurrentLinkedQueue[Klijent]()
    val zaduzeniKlijenti = new ConcurrentLinkedQueue[Klijent]()

    while(sc2.hasNextLine)
      redKlijenata.add(new Klijent(sc2.next(), sc2.nextInt()))

    for(i<- sluzbenice.indices)
      sluzbenice(i) = new Sluzbenica(kamata, kapital, redKlijenata, zaduzeniKlijenti)

    for(s<- sluzbenice)
      s.start()

    for(s<- sluzbenice)
      s.join()


  }
}