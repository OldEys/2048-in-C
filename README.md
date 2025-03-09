# 2048-in-C

### Descriere

2048 este un un clasic al jocurilor pe calculator având un concept foarte simplu și în același timp
o satisfacție foarte mare de jucat .<br>
Scopul principal este combinarea numerelor cu aceeși valoare pentru a obține dublul acestora pe o tablă de 4x4.
Jocul se încheie atunci când ajungi la numărul 2048 , caz în care ai câșigat sau tabla se umple de valori pe care nu le poți combina .
<br>2 numere de același fel se pot combina doar dacă între ele nu se află un număr cu altă valoare.

### Cum poți juca
Pentru a juca 2048 va trebui să descarci arhiva .zip sau .tar.gz din release-ul cel mai recent
După care trebuie să extragi fișierele corespunzătoare în locul dorit . La final va trebui să rulezi fișierul .exe pentru a începe.
Jocul a fost realizat în consolă ,iar tabla este de tip **4x4** realizată prin caractere din codul ASCII pentru a simula aspectul 
de tablă de joc. 

### Modul de jucat
La început va apărea un prompt în care vei fi întrebat dacă dorești să (mai) joci .
Apoi folosind tastele **w,a,s,d** alegi direcția în care miști obiectele de pe tablă (sus,stânga,jos respectiv dreapta) .
Atunci când miști obiectele într-o anumită direcție acestea se vor muta pe tablă în direcția corespunzătoare până când ajunge pe marginea tablei
sau are în cale un număr cu altă valoare . Dacă în calea sa se află un număr cu aceeași valoare , acestea se vor combina , obținând valoarea dublă
care se comportă la fel , mișcându-se la rândul ei în direcția corespunzătoare . La fiecare selectare a direcției se va afișa tabla actualizată , apoi se va genera
o valoarea de **2** într-o zonă aleatorie disponibilă . După finalizarea jocului se va afișa un mesaj în funcție de rezultatul final .
