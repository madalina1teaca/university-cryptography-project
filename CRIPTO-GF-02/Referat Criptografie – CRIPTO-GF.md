# Referat Criptografie – CRIPTO-GF

## 1. Introducere
Acest proiect implementează un sistem de criptare bazat pe operații efectuate în corpul finit GF(27).
 
Corpul GF(27) este un corp finit cu $27 = 3^3$ elemente, fiecare element fiind reprezentat printr-un polinom de grad maxim 2, având coeficienți în $GF(3) = {0,1,2}$.

Scopul proiectului este implementarera unui algoritm de criptare și decriptare care utilizează proprietățile algebrice ale corpurilor finite și o secvență de chei dependentă de poziția caracterelor în text.

Aplicația a fost realizată în limbajul **`C++`** și permite:
* ***criptarea*** unui text afișând toți pașii urmați
* ***decriptarea*** unui text afișând toți pașii urmați
* ***criptarea*** +  ***decriptarea*** unui text afișând toți pașii urmați
* afișarea ***tabelului GF(27)***
* afișarea ***secvenței cheiii***

## 2. Obiective
Proiectul urmărește:
* construirea corpului finit GF(27)
* reprezentarea elementelor sub formă polinomială și exponențială
* generarea unei secvențe de chei
* criptarea textelor prin utilizarea unei funcții de transformare definite în corpul finit GF(27)
* decriptarea textelor criptate
* afișarea etapelor intermediare pentru verificarea corectitudinii calculelor


## 3. Determinarea parametrilor

### Alfabetul Utilizat
> A B C D E F G H I J K L M
> N O P Q R S T U V W X Y Z

Fiecărei litere îi este asociat un element GF(27).

| **Literă** | **f_n** |
| :---: | :---: |
| A | 1 |
| B | 2 |
| C | 3 |
| ... | ... |
| Z | 26 |

### Cheia personalizată
> **Prenume:**
> Mădălina-Elena
> **Nume:**
> Teacă

| a_i & b_i | Litera | exp |
| :---: | :---: | :---: |
| a1 | M | exp 13 |
| a2 | A | exp 1|
| b1 | T | exp 20|
| b2 | E | exp 5|


## 5. Structura aplicației
Programul a fost implementat în limbajul C++ și este organizat modular.

Structura proiectului este:

```
src/
|–– main.cpp
|–– CryptoGF.cpp
|–– CryptoGF.h
```

### `main.cpp`
**Conține**:
* meniul aplicației
* citirea datelor de la tastatură
* apelarea funcțiilor de criptare și decriptare

### `CryproGF.cpp`
**Conține**:
* generarea corpului GF(27)
* conversii între reprezentări
* secvențele cheii
* algorimii de criptare
* algoritmii de decriptare

## 6. Explicarea logicii matematice și a algoritmilor

### Generarea corpului GF(27)

Pentru fiecare exponent:

$t^1, t^2, ..., t^26$

programul generează:
* reprezentarea polinomială
* valoarea numerică $f_n$
* litera asociată
  
**Exemplu**:
| Exp | Polinom | f_n | Litera |
|---  |:---: |---|:---:|
| $t^1$ | 010 | 3 | C |
| $t^2$ | 100 | 9 | I |
| $t^3$ | 012 | 5 | E |
| $t^4$ | 120 | 15 | O |

### Generarea secvenței de chei

Pentru fiecare poziție din text se generează două secvențe:

$$a_i$$
$$b_i$$

**Exemplu**:
| i | $a_i$ | $b_i$ | 
|---  |:---: |---|
| 1 | $t^{13}$ | $t^2$ |
| 2 | $t^1$ | $t^5$ |
| 3 | $t^3$ | $t^{25}$ |

Aceste valori sunt utilizate ulterior în procesul de criptare.

### Algoritmul de criptare

Pentru fiecare caracter se aplică transformarea:

$ y = a_i * x_i + b_i $

unde:

* $x_i$ - caracterul clar (necriptat)
* $a_i$ și $b_i$ - valorile din secvența cheii
* $y$ - caracterul criptat

Toate operațiile sunt efectuate în corpul GF(27).

### Algoritmul de decriptare

Pentru recuperarea caracterului inițial se utilizează relația:

$x = (y - b_i) * a_i^{-1}$

unde:

* $a_i^{-1}$ - inversul multiplicativ al lui $a_i$ în corpul GF(27).

## 7. Funcțiile principale ale aplicației

**`buildGF27()`**

*  generează și construiește corpul finit GF(27), calculând corespondențele dintre reprezentările exponențiale, polinomiale și numerice ale elementelor

**`gfAdd()`**

* realizează operația de adunare a două elemente din corpul GF(27), utilizând adunarea coeficienților modulo 3

**`gfMultiplyExp()`**

- efectuează înmulțirea a două elemente reprezentate exponențial, folosind proprietățile corpului Galois și aritmetica modulo 26

**`polynomialToFn()`**

* transformă reprezentarea polinomială a unui element în valoarea numerică asociată $(f_n)$

**`fnToPolynomial()`**

* convertește o valoare numerică $(f_n)$ în reprezentarea sa polinomială din corpul $GF(27)$.

**`getLetterIndex()`**

* determină poziția unei litere în alfabet și returnează valoarea numerică asociată

**`getLetterFromIndex()`**

* transformă o valoare numerică din intervalul 1–26 în litera corespunzătoare a alfabetului

**`normalizeText()`**

* normalizează textul introdus de utilizator prin transformarea literelor în majuscule și eliminarea/înlocuirea caracterelor care nu aparțin alfabetului utilizat

**`generateASequence()`**

* generează secvența de valori $a_i$ utilizată în procesul de criptare și decriptare

**`generateBSequence()`**

* generează secvența de valori $b_i$ utilizată în procesul de criptare și decriptare

**`encryptGF()`**

* realizează criptarea textului prin aplicarea relației $y = a_i * x_i + b_i$ unde toate operațiile sunt efectuate în corpul $GF(27)$

**`decryptGF()`**

* recuperează textul original utilizând relația inversă $x = (y − b_i) * a_i{-1}$ și operațiile specifice corpului finit

**`printGFTable()`**

* afișează tabelul complet al elementelor din corpul $GF(27)$, incluzând reprezentările exponențiale, polinomiale și numerice

**`printKeySequence()`**

* afișează secvențele de chei $a_i$ și $b_i$ generate pentru fiecare poziție din text

**`main()`**

- reprezintă punctul de intrare al aplicației și gestionează meniul interactiv, permițând utilizatorului să aleagă operația dorită (criptare, decriptare, afișare tabel $GF(27)$ sau afișare secvență cheie)

## 8. Capturi de ecran

### Rulare Cod

#### 1 - criptare
![criptare_1](/Cryprography/CRIPTO-GF-02/capturi/01_criptare1.png)
![criptare_2](/Cryprography/CRIPTO-GF-02/capturi/01_criptare2.png)


### 2 - decriptare
![decriptare_1](/Cryprography/CRIPTO-GF-02/capturi/02_decriptare1.png)
![decriptare_2](/Cryprography/CRIPTO-GF-02/capturi/02_decriptare2.png)


### 3 - criptare + decriptare
![crptare+decriptare_1](/Cryprography/CRIPTO-GF-02/capturi/03_criptare+decriptare1.png)
![crptare+decriptare_2](/Cryprography/CRIPTO-GF-02/capturi/03_criptare+decriptare2.png)
![crptare+decriptare_3](/Cryprography/CRIPTO-GF-02/capturi/03_criptare+decriptare3.png)

### 4 - afișarea tabelului GF(27)
![afișarea_tabelului_gf(27)](/Cryprography/CRIPTO-GF-02/capturi/04_afișare_tabel_gf(27).png)

### 5 - afișare secvenței cheii
![afișarea_secvenței_cheii](/Cryprography/CRIPTO-GF-02/capturi/05_afișare_secvența_cheii.png)

### Excel

![excel_1](/Cryprography/CRIPTO-GF-02/capturi/excel1.png)
![excel_2](/Cryprography/CRIPTO-GF-02/capturi/excel2.png)
![excel_3](/Cryprography/CRIPTO-GF-02/capturi/excel3.png)

--- 
#### Link GitHub Repo
https://github.com/madalina1teaca/university-cryptography-project/tree/main/CRIPTO-GF-02

--- 
### UNIVERSITATEA TITU MAIORESCU
#### FACULTATEA DE INFORMATICĂ
**Disciplina:** Criptografie și Securitatea Informației  
**Activitate:** Raport de Laborator — Referatul 2 (`CRIPTO-GF`)

---

### Date Student
* **Nume și prenume:** Teacă Mădălina-Elena
* **Specializare:** Informatică
* **Coordonatori disciplină:** Prof. univ. dr. ing. Răcuciu Ciprian / Lector univ. dr. ing. Rogobete Marius


