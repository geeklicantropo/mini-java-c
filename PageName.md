# Automaten #

Ich habe mal mit dem Tool, das Michael mir genannt hat, Automaten für den Lexer erstellt. Die wesentlichen Teilautomaten sind
  * Automat für Identifier
  * Automat für Integer-Literale
  * Automaten für Tokens, die nur aus einem Zeichen bestehen ({, }, ; ...)
  * Automaten für Tokens, die aus zwei Zeichen bestehen (&&, ||, ...)
  * Automat für Kommentare
Die habe ich dann über Epsilon-Transitionen in einem NEA zusammengehängt und anschließend in einen DEA umgewandelt (minimieren ist keine gute Idee, dann wirft er alle Endzustände zusammen).
Wenn wir erst allgemein Strings erkennen und dann später unterscheiden, ob das Schlüsselworte sind oder nicht, muss man dafür noch einen extra-Automaten machen - das mache ich heute Nachmittag.


Ein paar Hinweise noch zu den Automaten:
  * Bestimmte Zeichen kann man nicht im Alphabet verwenden, ich hab stattdessen andere genommen:
§ entspricht (, $ entspricht ), # entspricht "mal", " entspricht "plus", ü entspricht irgendeinem Leerzeichen
  * ~ (im Automaten für Kommentare) steht für "irgendein anderes Zeichen"
  * Ich hab an die Teilautomaten für Kommentare und Leerzeichen auch Endzustände gemacht, man muss ja für diese Endzustände dann keine Tokens produzieren.
  * In dem DEA, der alle Teilautomaten umfasst, müsste man eigentlich von allen Knoten noch eine Transition zu einem Errorzustand haben, die genommen wird wenn man ein Zeichen findet, für das man keine Verwendung hat. Ich hab den Zustand weggelassen, damit es übersichtlicher ist.
  * In dem Kommentar-DEA ist w ein Zustand, in dem man eine Warnung ausgeben könnte, weil ein Kommentarzeichen innerhalb eines Kommentars aufgetreten ist.
  * Mir war nicht ganz klar, ob man [.md](.md) bzw. () als eigenes Token repräsentieren muss, das muss man noch mal schauen.
  * Die Automaten sind ziemlich unübersichtlich; um besser zu sehen, welches Zeichen an welche Kante gehört, ist es praktisch, wenn man das Tool installiert hat, dann kann man auf die Kanten klicken und die dazugehörige Beschriftung wird rot eingefärbt:
http://www.fh-trier.de/index.php?id=12085
  * Die Automaten (pdf und xml) sind in der Download-Section, der Automat zum erkennen der Schlüsselwörter kommt heute Nachmittag.