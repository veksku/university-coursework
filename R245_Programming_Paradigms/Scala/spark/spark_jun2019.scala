import org.apache.spark.{SparkConf, SparkContext}

object spark_jun2019 {
  def main(args: Array[String]) {
    val konf = new SparkConf()
      .setAppName("Spark_Jun2019")
      .setMaster("local[4]")

    val sk = new SparkContext(konf)


    val datoteka = sk.textFile("biostats.csv")
      .map(linija => {
        val niz = linija.split(",")
        (niz(1), (niz(3).toDouble, niz(4).toDouble))
        //pol    //visina         //tezina
      })
      .aggregateByKey((0.0, 0.0, 0))((acc, v) => (acc._1 + v._1, acc._2 + v._2, acc._3 + 1),
                      (a1, a2) => (a1._1 + a2._1, a1._2 + a2._2, a1._3 + a2._3))
      .map( res => (res._1, (res._2._1/res._2._3* 2.54, res._2._2/res._2._3* 0.45359237)))
      .sortByKey()
      .collect()
      .foreach( res =>
        if(res._1 == "F")
          println("F: " + res._2._1 + " cm")
        else
          println("M: " + res._2._2 + " kg"))

    sk.stop()
//=================drugo resenje=================
//    val cached = sk.textFile("biostats.csv")
//      .cache()
//
//    val zenski = cached
//      .filter(_.contains(",F,"))
//      .map(linija => {
//        val niz = linija.split(",")
//        (niz(1), niz(3).toDouble)
//      })
//      .groupByKey()
//      .map(z => {
//        val visina = z._2.sum / z._2.size * 2.54
//        (z._1, visina)
//      })
//      .collect()
//
//    val muski = cached
//      .filter(_.contains(",F,"))
//      .map(linija => {
//        val niz = linija.split(",")
//        (niz(1), niz(4).toDouble)
//      })
//      .groupByKey()
//      .map(m => {
//        val tezina = m._2.sum / m._2.size * 0.45359237
//        (m._1, tezina)
//      })
//      .collect()
//
//    sk.stop()
//
//    zenski.foreach(z => println("F: " + z._2 + " cm"))
//    muski.foreach(m => println("M: " + m._2 + " kg"))
//==============================================
  }
}
