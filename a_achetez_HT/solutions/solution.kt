fun main(args: Array<String>) {

  /*
    HT + HT * TAUX = TVA
    HT * (1 + TAUX) = TVA
    HT = TVA
        -----
        (1 + TAUX)
   */

  val vatPrice = readLine()!!.toDouble()
  val taxRate = readLine()!!.toDouble() / 100.0 // Convert percent to taxRate

  println(String.format("%.2f", vatPrice / (1.0 + taxRate)))

}