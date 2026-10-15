import java.io.File
import java.util.Scanner
import java.util.concurrent.ThreadLocalRandom

import scala.collection.mutable.ArrayBuffer
import scala.util.Random

class Ucesnici (ime : String,
                prezime : String,
                indeks : Int,
                popusti : ArrayBuffer[Int])
  extends Thread{

  override def run(): Unit = {
    popusti.synchronized{
      popusti.wait()
    }
    if(popusti(indeks) == 0)
      println("Vaucer sa 20% popusta dobio je: " + this.getCeloIme)
    else if(popusti(indeks) == 1)
      println("Vaucer sa 10% popusta dobio je: " + this.getCeloIme)
    else if(popusti(indeks) == 2)
      println("Vaucer sa 5% popusta dobio je: " + this.getCeloIme)
  }

  def getCeloIme = ime + " " + prezime
}



object niti_jun2018 {
  def main (args : Array[String]): Unit ={
    val sc1 = new Scanner(new File("datoteke/ucesnici.txt"))
    val sc2 = new Scanner(new File("datoteke/ucesnici.txt"))

    val ucesnici = new ArrayBuffer[Ucesnici]
    val popusti = new ArrayBuffer[Int]
    var n = 0

    while(sc2.hasNextLine){
      sc2.nextLine()
      popusti.append(-1)
      n += 1
    }
    var indeks = 0
    while (sc1.hasNextLine){
      val ime = sc1.next()
      val prezime = sc1.next()
      ucesnici.append(new Ucesnici(ime, prezime, indeks, popusti))
      indeks += 1
    }

    var popust1 = 5 //20%
    var popust2 = 7   //10%
    var popust3 = 10  //5%

    for(u<-ucesnici)
      u.start()

    println("Cekamo da se izvuku pobednici...")
    Thread.sleep(2000)

    while(popust1 + popust2 + popust3 > 0){
      var random = ThreadLocalRandom.current().nextInt(0,n)
      while(popusti(random) != -1)
        random = ThreadLocalRandom.current().nextInt(0,n)

      val random_popust = ThreadLocalRandom.current().nextInt(0,2)
      if(random_popust == 0){
        if(popust1 != 0) {
          popusti(random) = 0
          popust1 -= 1
        }
        else{
          if(popust2 != 0){
            popusti(random) = 1
            popust2 -= 1
          }
          else if(popust3 != 0){
            popusti(random) = 2
            popust3 -= 1
          }
        }
      }

      else if(random_popust == 1){
        if(popust2 != 0) {
          popusti(random) = 1
          popust2 -= 1
        }
        else{
          if(popust1 != 0){
            popusti(random) = 0
            popust1 -= 1
          }
          else if(popust3 != 0){
            popusti(random) = 2
            popust3 -= 1
          }
        }
      }

      else if(random_popust == 2){
        if(popust3 != 0) {
          popusti(random) = 2
          popust3 -= 1
        }
        else{
          if(popust2 != 0){
            popusti(random) = 1
            popust2 -= 1
          }
          else if(popust1 != 0){
            popusti(random) = 0
            popust1 -= 1
          }
        }
      }
    }

    popusti.synchronized{
      popusti.notifyAll()
    }

    for(u<-ucesnici)
      u.join()
  }
}
