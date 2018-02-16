import java.util.*

typealias Coordonnees = Pair<Int, Int>

fun main(args: Array<String>) {

  // Définit la taille de la matrice
  val size = readLine()!!.toInt()
  val matrix = Array(size, { _ -> CharArray(size, { _ -> ' ' }) })

  // Mémoization des tailles de chemin
  val tailleChemin = Array(size, { _ -> IntArray(size, { _ -> -1 }) })
  fun tailleDuChemin(i: Int, j: Int, vus: List<Coordonnees>): Int {

    // Si on a pas déjà calculé la longueur du chemin
    if (tailleChemin[i][j] == -1) {
      var x = i
      var y = j
      val dejaVus = vus + Coordonnees(i, j)
      // On calcule le prochain point
      when (matrix[x][y]) {
        '^' -> x -= 1
        'V', 'v' -> x += 1
        '<' -> y -= 1
        else /* '>' */ -> y += 1
      }
      val nouvellesCoordonnees = Coordonnees(x, y)

      if (x < 0 || x >= size || y < 0 || y >= size || nouvellesCoordonnees in dejaVus) {
        // Si on sort ou qu'on à déjà vu le prochain point on met une taille de chemin à 1
        tailleChemin[i][j] = 1
      } else {
        // Si on ne sort pas de la matrice et qu'on n'a pas déjà vus le point
        // on calcule le chemin du prochain point et on ajoute 1
        tailleChemin[i][j] = tailleDuChemin(x, y, dejaVus) + 1
      }
    }

    return tailleChemin[i][j]
  }


  // Pour chaque ligne de la matrice
  (0 until size).forEach { line ->

    // On lit la ligne et on la transforme en List<Char>
    val directions = readLine()!!.map { it }
    // On remplit la liste de la matrice avec la ligne
    directions.forEachIndexed { column, c ->
      matrix[line][column] = c
    }

  }

  var max = 0
  for(i in 0 until size) {
    for(j in 0 until size) {
      // Calcule la taille du chemin pour chaque entrée de la matrice
      val taille = tailleDuChemin(i, j, listOf(Coordonnees(i, j)))
      // Si la taille > max déjà connu on le met à jour
      if (taille > max) {
        max = taille
      }
    }
  }
  println(max)

}



