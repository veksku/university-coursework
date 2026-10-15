import org.apache.spark.rdd.RDD
import org.apache.spark.{SparkConf, SparkContext}

object cars {
  def main(args: Array[String]): Unit = {

    val conf : SparkConf = new SparkConf()
      .setAppName("MainSparkApp")
      .setMaster("local[4]")

    val context = new SparkContext(conf)
    val rdd = context.textFile("cars.csv")
      .filter(linija => linija.startsWith("AWD") && linija.contains("Gasoline") && linija.contains("Automatic"))
      .filter(linija => (linija.contains("5 Speed Automatic") || linija.contains("6 Speed Automatic")))
      .map(linija => {
        val niz = linija.split(",")
        (niz(0).trim(), niz(3).trim().toFloat, niz(7).trim().toInt,  niz(8).trim().toInt)
        //pogon         mpg                    godina                snaga
      })
      .filter(linija => linija._3 > 2010 && linija._4 > 300)
      .map(r => (r._1, r._2)) //sklanjamo godinu i snagu jer smo isfilterisali one koji nam trebaju, pravimo kljuc i vrednost
      .aggregateByKey((0.0, 0))((acc, v) => (acc._1 + v, acc._2 + 1), 
      //za svaki kljuc (0.0, 0) => "0.0" je cesto zbir, "0" je cesto brojac; v je jedna od vrednosti iz proslog mapiranja (nikako kljuc)
        (acc1, acc2) => (acc1._1 + acc2._1, acc1._2 + acc2._2))
      .map(r => r._2._1 / r._2._2) //oblika je (kljuc, (zbir, brojac))
      .foreach(r => println(r))
//    val cache = context.textFile("cars.csv")
//      .filter(linija => linija.contains("AWD") && linija.contains("Gasoline") && linija.contains("Automatic"))
//      .filter(linija => (linija.contains("5 Speed Automatic") || linija.contains("6 Speed Automatic")))
//      .map(linija => {
//        val niz = linija.split(",")
//        (niz(3).trim().toFloat, niz(7).trim().toInt,  niz(8).trim().toInt)
//        //mpg                   godina                snaga
//      })
//      .filter(linija => linija._2 > 2010 && linija._3 > 300)
//      .cache()
//
//    val brojLinija = cache
//        .count()
//
//    val sumMPG = cache
//        .map(r => r._1)
//        .reduce(_+_)
//
//    println(sumMPG/brojLinija.toFloat)
    context.stop()
  }
}
