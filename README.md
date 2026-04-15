#Programmieraufgabe 2: TREE CHECK

##create_new_node(int number):

Erstellt einen Knoten, reserviert Speicher und speichert den übergebenen Wert. Die Zeiger nach links und rechts werden leer initialisiert, da dort am Anfang noch nichts stehen soll.

Aufwand: Es wird nur ein Knoten erstellt, also O(1), sowohl im Best Case als auch im Worst Case.

##insert_value(Node *root, int number):

Fügt einen Wert in den Baum bzw. später in den entsprechenden Knoten ein. Es wird überprüft, ob der Wert kleiner oder größer ist, und er wird jeweils nach links oder rechts eingeordnet, wobei dort weitergesucht wird.
Die Funktion arbeitet rekursiv, da sie sich so lange selbst aufruft, bis eine passende Stelle gefunden wurde.

Aufwand: Der Aufwand hängt von der Höhe des Baums ab.
Best Case: O(log n) bei einem ausgeglichenen Baum.
Worst Case: O(n), wenn der Baum stark einseitig ist.

##read_tree_from_file(const char *filename):

Öffnet die bestehende Textdatei, bei uns test.txt, und liest alle Integer Werte zeilenweise ein. Jeder Wert wird in den Baum eingefügt. Am Ende gibt die Funktion die Wurzel zurück.

Aufwand: durchschnittlich und im Best Case O(n log n)
Worst Case: O(n²)

##free_tree(Node *root):

Gibt den Baum rekursiv aus dem Speicher frei. Wichtig ist, dass zuerst die Kinder und danach der Knoten selbst gelöscht werden, da sonst der Zeiger auf die Kinder verloren geht.

Aufwand: O(n), da jeder Knoten genau einmal gelöscht wird.
Worst Case: O(n)
Best Case: O(n)

##print_tree(Node *root):

Gibt die Werte des Baums rekursiv in traversierter Reihenfolge aus. Zuerst wird der linke Teilbaum besucht, dann der aktuelle Knoten und danach der rechte Teilbaum. Dadurch erscheinen die Werte sortiert. Sobald root == NULL ist, bricht die Funktion ab.

Aufwand: O(n), da jeder Knoten genau einmal besucht wird.
Worst Case: O(n)
Best Case: O(n)
