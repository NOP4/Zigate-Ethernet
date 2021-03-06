# Zigate-Ethernet
## English
Convert a Zigate USB device to an ethernet connexion.

#### Required hardware:

* Arduino + Level Shifter + W5100 Shield
* ESP8266 + W5100 Shield.

#### Installation:

* Download or clone repository to your Arduino folder.
* Compile and send to your arduino or ESP8266.
* Domoticz configuration: change Zigate setting from USB to Wifi.

<span style="color:red">Disconnect Zigate when uploading Arduino/ESP code. You'll have to disconnect Ethernet module as well due to RST connexion.</span>

<span style="color:red">This is still a work in progress. Not tested yet.</span>

<i>Inspired from https://github.com/fairecasoimeme/ZiGate/tree/master/Module%20WiFi/Firmware/v1.3</i>

## Français
Conversion d'une Zigate en version Ethernet.

#### Matériel requis :

* Arduino + Level Shifter + Shield W5100
* ESP8266 + Shield W5100.

#### Installation :

* Télécharger ou cloner dans votre répertoire Arduino
* Compiler et upload dans votre Arduino ou ESP
* Dans domoticz, changer simplement le modèle de zigate dans le paramétrage du matériel. Passer de USB à WiFi.

<span style="color:red">Déconnecter la Zigate lors de la mise à jour du code dans l'Arduino ou l'ESP. Déconnecter également le module Ethernet.</span>

<span style="color:red">Projet en cours, encore non testé.</span>

<i>Code inspiré de https://github.com/fairecasoimeme/ZiGate/tree/master/Module%20WiFi/Firmware/v1.3</i>

<hr>

<img src="Zigate Ethernet Arduino.png" width="800">

<hr>

<img src="Zigate Ethernet WemosD1mini.png" width="800">

