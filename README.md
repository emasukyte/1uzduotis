# 1uzduotis

Pirmiausia sukūriau programą, kuri nuskaito iš anksto nustatyto skaičiaus studentų vardus ir pavardes, jų namų darbų pažymius bei egzamino rezultatą.
Vėliau programa išveda studentų vardus ir pavardes bei galutinį rezultatą (sudarytą iš namų darbų vidurkio bei egzamino rezultato).

Vėliau programą patobulinau ir pridėjau galimybę jos vartotojui pasirinkti, ar jis nori galutinį rezultatą matyti išvestą naudojant medianą, ar vidurkį.
Prie jau sukurtos programos pridėjau galimybę leisti jos vartotojui pačiam įvesti, kelių studentų duomenis jis įvedinės. 

Taip pat, padariau  beveik neribojamą (iki 10000) namų darbų skaičių, pats programos vartotojas gali nuspręsti, kada jis įvedė visus namų darbus ir nutraukti programą (paspaudžiant 0). Namų darbų rezultatus saugojau į vektorių. Realizuoti šios dalies su dinaminiu masyvu nepavyko. 

Pridėjau galimybę programos vartotojui pasirinkti, ar skaičius jis nori įvesti pats, ar juos sugeneruoti random. Taip pat daugumą funkcijų sukėliau į atskirus voidus,  jog būtų paprasčiau tvarkyti tekstą, ištaisiau klaidas (skaičiuojant galutinį pažymį).

Realizuoti dalies, kur yra dirbama su nuskaitytais duomenimis taip pat nepayko.


PAPILDYMAS

#v0.4
 Programa gali sugeneruoti 5 atsitiktinius studentų sąrašus su 1000, 10000, 100000, 1000000 ir 10000000 studentais. Studentai, kurių galutinis balas < 5 priskiriami "silpniesiems", o kurių galutinis balas >= 5, priskiriami "kietiakams". Surūšiuoti studentai išvedami į 2 atskirus failus.
 
![Ekrano kopija (2)](https://user-images.githubusercontent.com/90967510/150316439-c4d4af6e-90e2-47bc-8918-c08be4c994c4.png)


#v0.5
Programa patobulinta ir studentai gali būti saugomi arba į vektorių, arba į listą.

Intel(R) Core(TM) i7-1065G7 CPU @ 1.30GHz, 8.00 GB RAM, SDD

VEKTORIUS

![Ekrano kopija (4)](https://user-images.githubusercontent.com/90967510/150318157-f900a69c-d3af-4641-a8d0-5675baaf8d54.png)


LISTAS

![Ekrano kopija (6)](https://user-images.githubusercontent.com/90967510/150318398-9ba6adcd-54a7-4b67-b0a2-00ed9fdaeb98.png)


#v1.0
Programa patobulinta ir dabar galima rinktis 2 strategijas.

PIRMA STRATEGIJA, VEKTORIUS

![Ekrano kopija (8)](https://user-images.githubusercontent.com/90967510/150319674-2a18ea9a-7443-47bc-916c-7c84bcc08139.png)

ANTRA STRATEGIJA, VEKTORIUS

![Ekrano kopija (10)](https://user-images.githubusercontent.com/90967510/150319909-5f84b203-e669-4ec3-8c50-8e4f67c62aff.png)

PIRMA STRATEGIJA, LISTAS

![Ekrano kopija (12)](https://user-images.githubusercontent.com/90967510/150320099-1348d6e8-1a72-4af6-a9c0-3aa09594f2d5.png)

ANTRA STRATEGIJA, LISTAS

![Ekrano kopija (14)](https://user-images.githubusercontent.com/90967510/150320315-c3f5340b-3465-4946-85e0-92a077cdf25a.png)

Kol kas cmake nepavyko padaryti.



#v1.1 

Naudojant class 

![Ekrano kopija (16)](https://user-images.githubusercontent.com/90967510/150323316-424b0cef-17ef-4944-8b58-257c0cd65bff.png)

Naudojant struct ir vektorių

![Ekrano kopija (18)](https://user-images.githubusercontent.com/90967510/150323622-42d0ddaf-a9c7-4d41-9d60-a4c853f0ca92.png)


Kol kas su dalies su flagais nepavyko padaryti.



#v1.2






#v1.5

Vietoje turimos vienos Studentas klasės sukurkitos dvi: bazinė klasė - "Asmuo", skirta bendrai aprašyti žmogų ir jos išvestinė (derived) klasė - "Studentas"

![Ekrano kopija (20)](https://user-images.githubusercontent.com/90967510/150324493-b4d11ee0-0a7c-46b6-81de-1be9a85fd657.png)
