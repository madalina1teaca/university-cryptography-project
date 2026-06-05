# Referat Criptografie – CRIPTO-GF

## 1. Introducere
Criptografia reprezintă domeniul care studiază metodele de protejare a informațiilor prin transformarea acestora într-o formă inaccesibilă persoanelor neautorizate. Un sistem criptografic trebuie să permită atât criptarea mesajului, cât și recuperarea informației inițiale prin aplicarea unei funcții inverse.

Scopul acestei lucrări este implementarea unui algoritm de criptare și decriptare utilizând operații modulo 26 și parametri calculați conform cerințelor temei.

Aplicația a fost realizată în limbajul **`C++`** și permite introducerea unui mesaj de la tastatură, criptarea acestuia și recuperarea textului original prin decriptare.

## 2. Determinarea parametrilor
Conform cerințelor temei, parametrii utilizați au fost calculați pe baza numelui și prenumelui studentului.

> **Prenume:**
> Mădălina-Elena
> **Nume:**
> Teacă

> Primele trei litere distincte din numele de familie sunt:
> T E A

> Rezultând cuvântul cheie:
> TEA

> Parametrii utilizați în algoritm sunt:
> **a** = 1
> **b** = 9

## 3. Funcția de criptare
Fiecărei litere îi este asociată poziția sa în alfabetul englez:

> A = 0
B = 1
...
Z = 25

Criptarea se realizează utilizând relația:

> **E(x) = (x + 9) mod 26**

unde:

> ***x*** reprezintă poziția caracterului în alfabet;
***E(x)*** reprezintă caracterul criptat.

Prin aplicarea acestei funcții, fiecare literă este deplasată cu 9 poziții în cadrul alfabetului.

## 4. Funcția de decriptare
Pentru recuperarea mesajului original se utilizează funcția inversă:

> **D(y) = (y - 9) mod 26**


>***y*** reprezintă caracterul criptat;
***D(y)*** reprezintă caracterul obținut după decriptare.

Aplicarea funcției inverse permite recuperarea exactă a textului inițial.

## 5. Implementare
Programul a fost implementat în limbajul C++ și este organizat modular.

Structura proiectului este:

```
src/
|–– main.cpp
|–– CryptoGF.cpp
|–– CryptoGF.h
```

Fișierul `CryptoGF.cpp` conține implementarea funcțiilor de criptare și decriptare, iar fișierul `main.cpp` gestionează interacțiunea cu utilizatorul.

Exemplu de instrucțiune utilizată pentru criptare:

`int y = (a * x + b) % 26;`

Exemplu de instrucțiune utilizată pentru decriptare:

`int x = (y - b + 26) % 26;`


## 6. Capturi Cod

### ENCRYPT
![COD](/Cryprography/CRIPTO-GF/capturi/cripto-gf-cod2.png)

### DECRYPT
![COD](/Cryprography/CRIPTO-GF/capturi/cripto-gf-cod1.png)

> La finalul doumentului se află și linkul către repo-ul de pe GitHub.

## 7. Exemplu de rulare
### TEA
![tea](/Cryprography/CRIPTO-GF/capturi/TEA.png)

### CRIPTARE MODULO
![Modulo](/Cryprography/CRIPTO-GF/capturi/CRIPTARE%20MODULO.png)

### CRIPTOGRAFIE
![criptografie](/Cryprography/CRIPTO-GF/capturi/REFERAT%20CRIPTOGRAFIE.png)

## 8. Concluzii

În cadrul acestei lucrări a fost implementat un sistem de criptare și decriptare bazat pe aritmetică modulo 26. Algoritmul utilizează parametri calculați conform cerințelor temei și permite transformarea unui mesaj într-o formă criptată, precum și recuperarea acestuia prin aplicarea funcției inverse.

Rezultatele obținute confirmă funcționarea corectă a algoritmului și demonstrează principiile fundamentale ale criptării prin substituție utilizând operații matematice modulo 26.


--- 
#### Link GitHub Repo
https://github.com/madalina1teaca/university-cryptography-project/tree/main/CRIPTO-GF

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