fun main(args: Array<String>) {

  // Résolution par programmation dynamique

  val budgetMax = (readLine()!!.toDouble() * 100.0).toInt()
  // Liste des prix qu'il est possible d'avoir en ajoutant des plats
  val prixAtteints = BooleanArray(budgetMax + 1, { _ -> false })

  val n = readLine()!!.toInt()
  // Pour n lignes
  val prix = (0 until n)
      // On convertit "escargots 15.2" => 1520
      .map { (readLine()!!.split(" ")[1].toDouble() * 100.0).toInt() }
      // On ne garde que les prix que l'on peut payer
      .filter { it <= budgetMax }

  // Si aucun prix n'est inférieur au budget => "0.00"
  if (prix.isEmpty()) {
    println("0.00")
  } else {
    // Pour chaque plat on indique qu'il est possible de payer le plat
    prix.forEach { prixAtteints[it] = true }

    for (i in prix.min()!!..budgetMax) {
      // Si on peut atteindre le prix avec une somme de prix
      if (prixAtteints[i]) {
        // On enregistre tous les autres prix atteignable depuis celui-ci
        for (p in prix) {
          if (i + p <= budgetMax) {
            prixAtteints[i + p] = true
          }
        }
      }
    }

    val dernierPrixAtteint = prixAtteints.lastIndexOf(true)
    println(String.format("%.2f", (dernierPrixAtteint.toDouble() / 100.0)))

  }

}