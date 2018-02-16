fun main(args: Array<String>) {

  // Pour n entrées (données dans cin)
  (0 until readLine()!!.toInt()).forEach {

    // On récupère la ligne et on la transforme en list de Char (pour manipulations
    var input = readLine()!!.map { it }

    /*
      On compte le nombre d'apparition des lettres
      acbbacb => [(a, 2), (c, 2), (b, 3)]
     */
    val countLetter = input
        .groupBy { it }
        .map {
          Pair(it.key, it.value.size)
        }

    // On récupère la lettre qui apparait un nombre impair de fois (si elle existe)
    val impairLetter = countLetter.firstOrNull { it.second % 2 == 1 }?.first

    // Si il y a une lettre en nombre impair on l'enlève de la liste
    if(impairLetter != null) {
      input -= impairLetter
    }

    // On trie les lettres pour avoir les mêmes côte à côte
    val sorted = input.sorted()

    // On prend une lettre sur deux et on la met dans le groupe de début
    val begin = sorted.filterIndexed { index, _ -> index % 2 == 0 }.joinToString("")
    // On prend une lettre sur deux et on la met dans le groupe de fin
    val end = sorted.filterIndexed { index, _ -> index % 2 != 0 }.sortedDescending().joinToString("")

    // Si on avait une lettre impaire on l'ajoute au milieu sinon on prend juste le début + la fin
    val result = if(impairLetter != null) {
      begin + impairLetter.toString() + end
    } else {
      begin + end
    }

    if(isPalindrom(result)) {
      println(result)
    } else {
      println("-")
    }

  }

}

fun isPalindrom(string: String): Boolean {
  var a = 0
  var b = string.length - 1
  while(a < b && string[a] == string[b]) {
    a++
    b--
  }
  return a >= b
}
