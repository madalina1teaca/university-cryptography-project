# Referat GF

## Prezentarea Aplicației


Scopul aplicației este implementarea unei metode de criptare și decriptare folosinf funcții modulo 26. Paramterii utilizați au fost calculați, conform cerinței, din numele și prenumele studentului.

> **NUME**: Teacă
> **PRENUME**: Mădălina-Elena

**Parametrii Obținuți:**

> **CUVÂNTUL CHEIE**: TEA
> **a** = 1
> **b** = 9

Funcția de criptare utilizată este următoarea:
$E(x) = (x + 9) \mod 26$

Funcția de decriptare este funcția inversă::
$D(y) = (y - 9) \mod 2$

Programul a fost implementat în limbajul `C++` și permite introducerea unui text de la tastatură, c riptarea acestuia și, mai apoi, recuperarea textului inițial prin aplicarea funcției inverse.
Rezultatele obținute confirmă corectitudinea implementării întrucât textul decriptat este la fel cu cel introdus inițial.

## Capturi de Ecran cu Rezultate ale Rulării Aplicației

### TEA
![TEA](/Calcule%20în%20corpuri%20Galois%20GF/capturi/TEA.png)

### CRIPTARE MODULO
![CRIPTARE MODULO](/Calcule%20în%20corpuri%20Galois%20GF/capturi/CRIPTARE%20MODULO.png)

### REFERAT CRIPTOGRAFIE
![REFERAT CRIPTOGRAFIE](/Calcule%20în%20corpuri%20Galois%20GF/capturi/REFERAT%20CRIPTOGRAFIE.png)
