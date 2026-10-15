import org.apache.spark.{SparkConf, SparkContext}

object primerispita {
  def main(args: Array [String]){
    val konf = new SparkConf()
      .setAppName("primerispita")
      .setMaster("local[4]")

    val sk = new SparkContext(konf)

    val datoteka = sk.textFile("insurance.csv")
      .filter(_.contains("Wood"))
      .filter(_.contains("Residential"))
      .filter(_.contains("PALM BEACH COUNTY"))
      .map(linija => {
        val niz = linija.split(",")
        (niz(2), (niz(3).toDouble, niz(4).toDouble))
      })
      .aggregateByKey((0.0, 0.0, 0))((acc, v) => (acc._1 + v._1, acc._2 + v._2, acc._3 + 1),
                      (a1, a2) => (a1._1 + a2._1, a1._2 + a2._2, a1._3 + a2._3))
      .map( res => ((res._2)._1 / (res._2)._3, (res._2)._2 / (res._2)._3))
      .collect()
      .aggregate((0.0, 0.0))((acc, v) => (acc._1 + v._1, acc._2 + v._2),
                 (a1, a2) => (a1._1 + a2._1, a1._2 + a2._2))

    sk.stop()

    println(datoteka)
  }
}
