# Projet Capteur 

## Description du projet

Ce projet a eu lieu dans le cadre de l'UF "du capteur au banc de test" en 4ème année de Génie physique à l'insa Toulouse. Le principe est d'établir une datasheet pour un capteur graphène soit une feuille de papier ou un tracé au crayon a papier est utilisé comme résistance.
Pour cela nous avons établis un banc de test avce differents composants arduino et avons utilisé le logiciel kikad pour créer un pcb pour les composants. Enfin nous avons éffectué des mesure pour déterminer la variation de la résistance en fonction du graphène et de la flexion du papier.
Nous avons utilisé un écran OLED sur le pcb pour choisir entre la mesure du capteur grapehène et d'un flex sensor et avons crée un application android pour avoir les valeurs de mesures sur le téléphone à l'aide d'une communication bluetooth.

## Livrables

* PCB shield pour arduino uno
* Code arduino
* Banc de test du capteur
* Application android qui fonctionne par bluetooth
* Datasheet

## Materiel Utilisé

* Ecran OLED
* Flex sensor
* Encodeur Rotatoire
* Capteur Graphène
* Module Bluetooth
* LCT-1050
* MCP 41050
* Résistances : 2x100kOhm, 1x33kOhm, 1*10kOhm, 1x1kOhm
* Capacités : 2x100nF, 1x1uF

## PCB Shield Pour Arduino Uno
### Partie Kikad
![SHEMATIC](https://github.com/MOSH-Insa-Toulouse/2023-2024-4GP-RIETHMULLER-GESSINN/assets/160252962/51b6af84-ad8f-4ffb-87dc-6c732b9fce76)

Nous avons commencé par mettre en place un shematic pour notre PCB. Pour cela, nous avons tout d'abord utilisé un template pour arduino uno et nous avons ensuite crée les empreintes et shematic pour chacun des composants sur notre plaque. Ensuite nous avons relié les entrées de chacun des composants aux entrées de l'arduino. Pour cela nous avons du faire des choix que l'on peut retrouver dans le document

https://github.com/MOSH-Insa-Toulouse/2023-2024-4GP-RIETHMULLER-GESSINN/blob/main/Projet%20Capteur%20composants.docx
