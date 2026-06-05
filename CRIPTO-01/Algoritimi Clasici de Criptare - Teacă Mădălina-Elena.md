# Algoritmi Clasici de Criptare - Referat

## 1. Introducere și Obiective
Referatul prezintă rezolvarea cerințele practice stabilite în cadrul temei *'Referat1_Criptografie-cerințe'*. Obiectivul principal constă în proiectarea și implementarea de la zero a unor algoritmi de criptografie clasici (fără utilizarea unor librării criptografice dedicate).

Aplicația este dezvoltată nativ în **`C++`** și respectă o arhitectură modulară curată: fiecare algoritm are dedicat o interfață proprie (fișierele `.h`) și o secțiune izolată de implementare a logicii matematice (fișierele `.cpp`) toate fiind organizate dinamic printr-un meniu interactiv controlat din terminal (`Menu.cpp`).

## 2. Structura Proiectului
```
src/
|–– main.cpp
|–– Menu.cpp
|–– Menu.h
|–– Caesar.cpp
|–– Caesar.h
|–– Vigenere.cpp
|–– Vigenere.h
|–– Substitution.cpp
|–– Substitution.h
|–– Transposition.cpp
|–– Transposition.h
|–– Mixed.cpp
|–– Mixed.h
```
La finalul doumentului se află și linkul către repo-ul de pe GitHub.

## 3. Descrierea Algoritmilor și a Fundamentelor Matematice

### 3.1. Cifrul Caesar

#### Descriere
Una dintre cele mai vechi metode de criptare. Fiecare literă este deplasată în alfabet cu un număr fix de poziții reprezentat de o cheie.

#### Formule
* **Formula de Criptare:** $E(x) = (x + k) \pmod{26}$
* **Formula de Decriptare:** $D(y) = (y - k + 26) \pmod{26}$ *(Adunarea valorii 26 previne rezultatele negative în operatorul modular din C++).*

#### Fragment din cod
```
// Sursă: Caesar.cpp
std::string caesarEncrypt(std::string text, int key) {  
    std::string result;
    for(char c : text) {
        if(isalpha(c)) {
            c = toupper(c);
            int x = c - 'A';
            int y = (x + key) % 26;
            result += char(y + 'A');
        } else { result += c; }
    }
    return result;
}
```
#### Exemplu
> **Mesaj:**
> CRIPTOGRAFIE
> **Cheie:**
> 3

>**Rezultat:**
>**Criptat:** FULSWRJUDILH
>**Decriptat**: CRIPTOGRAFIE

#### Capturi de ecran
![COD](/Cryprography/CRIPTO-01/capturi/Caesar%20Cod.png)
![COD](/Cryprography/CRIPTO-01/capturi/Caesar%20Cod%20-%20D.png)
![Rezultate terminal](/Cryprography/CRIPTO-01/capturi/Caesar%20Result.png)

### 3.2. Cifrul Vigenère
#### Descriere 
Cifrul Vigenère utilizează un cuvânt-cheie pentru a determina deplasarea aplicată fiecărei litere din mesaj. Acesta reprezintă o metodă de criptare polialfabetică.

#### Formule
* **Formula de Criptare:** $c_j = (m_j + k_{j \bmod n}) \pmod{26}$
* **Formula de Decriptare:** $m_j = (c_j - k_{j \bmod n} + 26) \pmod{26}$

#### Fragment din cod
```
// Sursă: Vigenere.cpp
std::string vigenereEncrypt(std::string text, std::string key) {
    std::string result;
    int keyIndex = 0;
    for(char c : text) {
        if(isalpha(c)) {
            c = toupper(c);
            int x = c - 'A';
            char k = toupper(key[keyIndex % key.length()]);
            int shift = k - 'A';
            int y = (x + shift) % 26;
            result += char(y + 'A');
            keyIndex++;
        } else {
            result += c;
        }
    }
    return result;
}
```

#### Exemplu

> **Mesaj:**
> CRIPTARE
> **Cheie:**
> TEACA

> **Rezultat:**
> **Criptat:** VVIRTTVE
> **Decriptat:** CRIPTARE

#### Capturi de ecran
![COD](/Cryprography/CRIPTO-01/capturi/vignere%20cod1.png)
![COD](/Cryprography/CRIPTO-01/capturi/vignere%20cod2.png)
![Rezultate terminal](/Cryprography/CRIPTO-01/capturi/Vigenere%20Result.png)

### 3.3. Algoritmul de Substituție
#### Descriere
Metoda de substituție înlocuiește fiecare literă cu o altă literă conform unui alfabet de substituție prestabilit.

#### Observații

În implementarea realizată a fost utilizat un alfabet de substituție construit pe baza unei chei prestabilite.

> **Alfabet permutat generator:** TEABCDFGHIJKLMNOPQRSUVWXYZ

#### Fragment din cod

```
// Sursă: Substitution.cpp
std::string substitutionEncrypt(std::string text) {
    std::string result;
    for(char c : text) {
        if(isalpha(c)) {
            c = toupper(c);
            int pos = ALPHABET.find(c);
            result += SUBSTITUTE[pos];
        } else {
            result += c;
        }
    }
    return result;
}
```

#### Capturi de ecran
![COD](/Cryprography/CRIPTO-01/capturi/substitution%20cod1.png)
![COD](/Cryprography/CRIPTO-01/capturi/substitution%20cod2.png)
![Rezultate terminal](/Cryprography/CRIPTO-01/capturi/Substitution%20Result.png)

### 3.4. Algoritmul de Transpoziție
#### Descriere

Metoda de transpoziție modifică poziția caracterelor în mesaj fără a modifica valorile acestora.

Mesajul este scris într-un tabel și apoi citit pe coloane pentru obținerea textului criptat.

#### Observații
**Preprocesare:** Conform cursului, spațiile și caracterele non-alfabetice sunt ignorate sau eliminate pentru compactarea textului.

#### Fragment din cod

```
// Sursă: Transposition.cpp
std::string transpositionEncrypt(std::string text, int columns) {
    std::string cleanText;
    std::string result;
    for(char c : text) {
        if(isalpha(c)) cleanText += toupper(c);
    }
    int length = cleanText.length();
    for(int col = 0; col < columns; col++) {
        for(int i = col; i < length; i += columns) {
            result += cleanText[i];
        }
    }
    return result;
}
```

#### Capturi de ecran
![COD](/Cryprography/CRIPTO-01/capturi/transposition%20cod1.png)
![COD](/Cryprography/CRIPTO-01/capturi/transposition%20cod2.png)
![Rezultate terminal](/Cryprography/CRIPTO-01/capturi/Transpo%20Result.png)


### 3.5. Sistemul Mixt (Produs de Cifruri)

#### Descriere

Sistemul mixt combină două metode de criptare:
1. ***Substituția monoalfabetică***
2. ***Transpoziția***
La decriptare se aplică operațiile în ordine inversă.

#### Fragment din cod

```
// Sursă: Mixed.cpp
std::string mixedEncrypt(std::string text, int columns) {
    std::string substituted = substitutionEncrypt(text);
    std::string encrypted = transpositionEncrypt(substituted, columns);
    return encrypted;
}
```
#### Capturi de ecran
![COD](/Cryprography/CRIPTO-01/capturi/mixed%20cod1.png)
![COD](/Cryprography/CRIPTO-01/capturi/mixed%20cod2.png)
![Result](/Cryprography/CRIPTO-01/capturi/Substitution%20Result.png)

## 4. Interfața și Validarea Datelor (`Menu.cpp`)
Pentru a elimina riscul crash-urilor sau al comportamentelor nedefinite (runtime errors), modulul care gestionează interfața interactivă a fost optimizat:
* **Tratarea excepțiilor de stream `(cin.fail())`**: În cazul în care utilizatorul introduce caractere alfabetice în loc de numere la opțiunile meniului sau la cheia Caesar, starea de eroare a stream-ului este resetată (`cin.clear()`), iar bufferul rezidual este eliminat complet.
* **Validarea valorilor introduse**: Numărul de coloane utilizat la transpoziție și sistemul mixt este validat să fie $C \ge 1$, împiedicând apariția excepțiilor de tip împărțire la zero.

## 5.Concluzii
În cadrul acestui proiect au fost implementați și testați mai mulți algoritmi clasici de criptografie. Fiecare metodă permite atât criptarea, cât și decriptarea mesajelor introduse de utilizator.
Implementarea modulară a permis separarea logicii fiecărui algoritm și organizarea eficientă a codului sursă. Prin realizarea acestui proiect au fost aprofundate conceptele fundamentale ale criptografiei clasice și modul de implementare al acestora în limbajul C++.

--- 
#### Link GitHub Repo
https://github.com/madalina1teaca/university-cryptography-project/tree/main/CRIPTO-01

--- 
### UNIVERSITATEA TITU MAIORESCU
#### FACULTATEA DE INFORMATICĂ
**Disciplina:** Criptografie și Securitatea Informației  
**Activitate:** Raport de Laborator — Referatul 1 (`CRIPTO-R1`)

---

### Date Student
* **Nume și prenume:** Teacă Mădălina-Elena
* **Specializare:** Informatică
* **Coordonatori disciplină:** Prof. univ. dr. ing. Răcuciu Ciprian / Lector univ. dr. ing. Rogobete Marius