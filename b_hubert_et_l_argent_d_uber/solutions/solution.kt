fun main(args: Array<String>) {

  // On crée la carte des prix
  val alimentPrice = mutableMapOf<String, Int>()
  // Pour n entrées (indiquées par readLine)
  (0 until readLine()!!.toInt()).forEach {

    // On a "aliment" "prix(string)"
    val (aliment, priceStr) = readLine()!!.split(" ")
    // On enregistre le prix de l'aliment dans la carte
    alimentPrice[aliment] = priceStr.toInt()
  }

  var sum = 0
  // Pour n entrées (indiquées par readLine)
  (0 until readLine()!!.toInt()).forEach {
    // On a "aliment" "quantité(string)"
    val (aliment, qteStr) = readLine()!!.split(" ")
    // On ajoute le prix de l'aliment * sa quantité à la somme
    sum += alimentPrice[aliment]!! * qteStr.toInt()
  }

  println(sum)

}