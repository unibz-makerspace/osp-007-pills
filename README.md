# osp-007-pills

## Source code for the pill dispenser project of the Liceo Scientifico "Torricelli" Bolzano.

A project in collaboration with makerspace - Faculty of Computer Science at
the Free University of Bolzano. See also
[makerspace | learning by doing](http://makerspace.inf.unibz.it/).

```
 m  a  k  e  r  s  p  a  c  e  .  i  n  f  .  u  n  i  b  z  .  i  t  
                                                                      
8888888888888888888888888888888888888888888888888888888888888888888888
                                                                      
               8                                                      
               8                                                      
YoYoYo. .oPYo. 8  .o  .oPYo. YoYo. .oPYo. 8oPYo. .oPYo. .oPYo. .oPYo. 
8' 8' 8 .oooo8 8oP'   8oooo8 8  `  Yb..`  8    8 .oooo8 8   `  8oooo8 
8  8  8 8    8 8 `b.  8.  .  8      .'Yb. 8    8 8    8 8   .  8.  .  
8  8  8 `YooP8 8  `o. `Yooo' 8     `YooP' 8YooP' `YooP8 `YooP' `Yooo' 
                                          8                           
                                          8                           
                                                                      
8888888888888888888888888888888888888888888888888888888888888888888888
                                                                      
 c  o  m  p  u  t  e  r    s  c  i  e  n  c  e    f  a  c  u  l  t  y 
```

### Usage Instructions

*Clone this repository* with git command line or Git for Windows or else you can
also *download the repository as a ZIP file*. Then put the project folder
somewhere on your filesystem of your PC. Launch your Arduino installation and go
to the menu bar `File | Preferences`. In the `Settings` tab click the `Browse`
button on the right side of `Sketchbook location:` and select the *project
folder that you have just copied*. Hit the `OK` button and close the Arduino IDE
without saving the empty sketch. Now after every restart of the IDE you can
launch any sketch that resides within the project folder and any included
software library within the library folder will be available for your sketches.

### Environment

The sketches have been developed with the *Arduino IDE 1.6.8* from the
[arduino.cc](https://www.arduino.cc/) website. You can expect that the sketches
can be executed for any future release of the IDE. Any previous release of the
IDE is not guaranteed to work as it could be that specific properties or
behaviours of the IDE are expected or used.

As a second option for developing software for Arduino you can use the *Visual
Studio* plugin [Visual Micro](http://www.visualmicro.com/). The Visual Studio
IDE can nowadays be downloaded from [Mircosoft](https://www.visualstudio.com/)
for free as a *Community* edition, that needs only a valid registered Microsoft
account such that it works properly.

### Platform

The sketches have been developed for the *Arduino Uno*. Any other board with an
*ATmega328* compatible microcontroller might also work but our mileage may vary.

### Other Hardware
The project can be used with the serial bluetooth module HC-06 or HC-05. Be
beware that the module works with 3.3V signal levels and therefore on the
Arduino Uno a simple voltage translator is needed for the *RXD* pin of the
module.

The wiring is as follows:
![HC-05 Arduino Wiring](http://cdn.instructables.com/FSK/AI30/HMMFE6UO/FSKAI30HMMFE6UO.MEDIUM.jpg)

**Please make sure that the module is detached when your try to upload a sketch
the Arduino Uno or else the process will fail!**

### Bluetooth Communication
You can test the bluetooth connection on an Android smartphone by installing
apps like
[BT Simple Terminal](https://play.google.com/store/apps/details?id=wingood.bluetooth.btsimpleterminal)
or by creating a custom application in Android Studio by following the guides of
[Android-er](http://android-er.blogspot.it/2015/07/android-example-to-communicate-with.html).
Further details about developing applications for Android can be found at
http://developer.android.com/sdk/.

### Useful Links
* https://www.arduino.cc/
* https://www.visualstudio.com/
* http://www.visualmicro.com/
* http://developer.android.com/sdk/
* https://git-for-windows.github.io/
* https://123d.circuits.io