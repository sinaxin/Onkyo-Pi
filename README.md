# Onkyo-RI
Control Onkyo devices is possible among others through Remote Interactive port. This port is normally used for direct communication between two Onkyo devices (ex. receiver and CD player). But why not turn on the receiver automatically when you start your own player?

## Support for Raspberry Pi
This is based on docbender's work: Onkyo-RI library.

Thanks a lot to zatrax for helping me in converting docbender's Onkyo-RI to using WiringPi instead of the Arduino library. 
A makefile has also been created for compiling the code with g++.
Please compile on your Raspberry pi using the makefile (modify to your taste). Please also modify the main.cpp to the code you want to send.

Please be sure to have WiringPi installed: http://wiringpi.com

## Connection
To connect to the RI port is used 3.5mm mono jack. Tip is for data signal and sleeve is ground (GND). Data are sent via TTL logic. So it is easy to connect RI device to 3.3v serial (RPi). Just connect data signal to some output pin and connect GND between each other.

## Protocol
Protocol description could be found at:
*    http://lirc.sourceforge.net/remotes/onkyo/Remote_Interactive

or with grafical representation at:
*    http://fredboboss.free.fr/articles/onkyo_ri.php .

Protocol is pretty simple for implementation. In one message is transfered 12 bit code. This code represents action for target device. Most significant bit is send first.

## Library
* blocking - send() method blocks other program execution until whole command is sent. It takes up to 61 ms.

### RI codes - receiver 
Codes are valid for TX-8020 receiver. With a high probability it will work with other Onkyo receivers.
<table>
  <tr><td><b>Action</b></td><td><b>Command</b></td><td><b>Notes</b></td></tr>
  <tr><td>Input CD</td><td>0x20</td><td>Switch input to CD channel</td></tr>
  <tr><td>Turn On + CD</td><td>0x2F</td><td>Turn on receiver and select CD as input channel</td></tr>
  <tr><td>Input TAPE</td><td>0x70</td><td>Switch input to TAPE channel</td></tr>
  <tr><td>Turn On + TAPE</td><td>0x7F</td><td>Turn on receiver and select TAPE as input channel</td></tr>
  <tr><td>Input BD/DVD</td><td>0x120</td><td>Switch input to BD/DVD channel</td></tr>
  <tr><td>Turn On + BD/DVD</td><td>0x12F</td><td>Turn on receiver and select BD/DVD as input channel</td></tr>
  <tr><td>Input DOCK</td><td>0x170</td><td>Switch input to DOCK channel</td></tr>
  <tr><td>Turn On + DOCK</td><td>0x17F</td><td>Turn on receiver and select DOCK as input channel</td></tr>  
  <tr><td>Dimmer Hi</td><td>0x2B0</td><td>Set dimmer brightness to highest level</td></tr>
  <tr><td>Dimmer Mid</td><td>0x2B1</td><td>Set dimmer brightness to mid level</td></tr>  
  <tr><td>Dimmer Lo</td><td>0x2B2</td><td>Set dimmer brightness to lowest level</td></tr>  
  <tr><td>Dimmer Hi</td><td>0x2B8</td><td>Set dimmer brightness to highest level</td></tr>
  <tr><td>Dimmer Lo</td><td>0x2BF</td><td>Set dimmer brightness to lowest level</td></tr>    
  <tr><td>Turn Off</td><td>0x420</td><td>Turn off(set into standby) receiver</td></tr>  
  <tr><td>Test mode</td><td>0x421 - 0x424</td><td>Some kind of test modes. Leave test mode is possible by code 0x420 (Turn Off). Test modes provides clear of receiver setting.</td></tr>
  <tr><td>Radio search next</td><td>0x430</td><td>Tune next radio station when radio is selected.</td></tr>  
  <tr><td>Radio search previous</td><td>0x431</td><td>Tune previous radio station when radio is selected.</td></tr>  
  <tr><td>Radio Stereo/Mono</td><td>0x432</td><td>Switch between Stereo and Mono when FM radio is selected.</td></tr>  
  <tr><td>Radio station next</td><td>0x433</td><td>Jump to next stored radio station when radio is selected.</td></tr>  
  <tr><td>Radio station previous</td><td>0x434</td><td>Jump to previous stored radio station when radio is selected.</td></tr>
</table>



