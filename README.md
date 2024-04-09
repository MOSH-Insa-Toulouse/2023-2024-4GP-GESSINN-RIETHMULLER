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

Nous avons commencé par mettre en place un shematic pour notre PCB. Pour cela, nous avons tout d'abord utilisé un template pour arduino uno et nous avons ensuite crée les empreintes et shematic pour chacun des composants sur notre plaque. Ensuite nous avons relié les entrées de chacun des composants aux entrées de l'arduino. Pour cela nous avons du faire des choix que l'on peut retrouver dans le document ci dessous :

https://github.com/MOSH-Insa-Toulouse/2023-2024-4GP-RIETHMULLER-GESSINN/blob/main/Projet%20Capteur%20composants.docx

Nous anvons ensuite procédé à l'organisation de la partie PCB. Nous avons disposé tout les elements sur la plaque et avons relié de façon à avoir un plan de masse sur la plaque et éviter d'avoir a faire des vias. Nous avons choisi d'avoir les pistes sur le dessus du PCB et d'avoir que des composants traverstants. Vous pouvez voir ci dessous le PCB à l'état fini.

Mettre ici l'image du PCB

### Impression du PCB 

Lorsque nous avions fini le PCB il fallait le réaliser. Avec l'aide de Catherine Crouzet nous avons imprimé notre plan de PCB et l'avons réalisé dans l'atelier du Batiment Génie Electrique. Nous avons ensuite percé la plaque à l'aide de forets de 1 ou 0.8 mm. Nous avons ensuite soudé les composant et ajouté des supports pour pouvoir déposer le PCB directement sur l'arduino UNO. Nous avons ensuite effectué des test de contact électrique de nos composants pour vérifier que tout était comme prévu et avons remarqué qu'il y avait une erreur.

![image](https://github.com/MOSH-Insa-Toulouse/2023-2024-4GP-RIETHMULLER-GESSINN/assets/160252962/435726a2-56f5-4d1d-a915-e4f4c4ffa622)

## Code Arduino

## Banc de test

## Application android

Pour la conception de notre application, nous avons utilisé le site MIP App Inventor, le but étant d'avoir accès au résultats de nos mesures sur un téléphone par communication Bluetooth

## Datasheet


Au niveau du premier point, deux pistes ne devant pas être relièes entraient en contact et au niveau du seconc, le plan de masse que devait être supposement relié à la masse ne l'était pas. Nous avons donc du remedier à ces problèmes avant de passer à la suite, pour cela nous avons bricolé pour éviter de devoir imprimer le PCB une seconde fois. Nous avons également corrigé cela sur le ficher Kikad qui se trouve sur le dossier en décalent simplement une réistance pour laisser l'espace nécessaire au plan de masse et au passage paralelle des deux pistes.
