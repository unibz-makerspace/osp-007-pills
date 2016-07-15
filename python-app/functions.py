#!/usr/bin/python
# -*- coding: utf8 -*-
#
# File: functions.py
#
# Copyright (C) 2016 Marco Marinello
# 
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# Life-saving pills distributor Controller
# A project of the High school "E. Torricelli" http://www.torricelli.bz.it
# developed in collaboration with the Makerspace of
# the Free University of Bolzano http://makerspace.inf.unibz.it

# Functions to be called by the shell
from os import system
from serial import Serial
from ConfigParser import ConfigParser

global debug
debug = True

class Configuration:
    def mail_set(arg, email):
        cp = ConfigParser()
        cp.read("conf.txt")
        cp.set("parents", "mail", email)
        hd = open("conf.txt", "w")
        cp.write(hd)
        hd.close()
    def mail(*args):
        cp = ConfigParser()
        cp.read("conf.txt")
        return cp.get("parents","mail")

    def hour(*args):
        cp = ConfigParser()
        cp.read("conf.txt")
        return int(cp.get("pills_must_be_taken","hour"))
    def hour_set(arg, hour):
        cp = ConfigParser()
        cp.read("conf.txt")
        cp.set("pills_must_be_taken", "hour", hour)
        hd = open("conf.txt", "w")
        cp.write(hd)
        hd.close()
        
    def minutes(*args):
        cp = ConfigParser()
        cp.read("conf.txt")
        return int(cp.get("pills_must_be_taken","minutes"))
    def minutes_set(arg, mins):
        cp = ConfigParser()
        cp.read("conf.txt")
        cp.set("pills_must_be_taken", "minutes", mins)
        hd = open("conf.txt", "w")
        cp.write(hd)
        hd.close()
        
conf = Configuration()

class ArduinoComunicator:
    def send_message(arg, value):
        if debug: print "SERIAL send on /dev/ttyACM0 %s" %value
        return
    
    def susp_send_message(arg, value): # Suspended until arduino is working
        ide = Serial("/dev/ttyACM0", 9600)
        ide.write(value)
        ide.close()
        return

    def get_message(arg, *args):
        return raw_input("Message to return (by arduino.get_message): ")

    def susp_get_message(arg, *args):
        ide = Serial("/dev/ttyACM0", 9600)
        e = ide.read()
        ide.close()
        return e

arduino = ArduinoComunicator()

class _exit:
    command = "q"
    info = "Exit from the shell"
    
    def do(*args):
        if debug: print "Goodbye!"
        exit()

class config:
    command = "config"
    info = "Configure the program"

    def do(*args):
        while True:
            print "Entered in configuration mode."
            print "Type 'q' and enter to return to the shell\nCommands:"
            print "mail\tInsert parents email\n"
            cmd = raw_input("LSPiD Config>>> ")
            if cmd == "mail":
                mail = raw_input("Parents e-mail: ")
                conf.mail_set(mail)
                print conf.mail() == mail and "New e-mail address set.\n\n" or "ERROR"
            elif cmd == "q":
                break
            else:
                print "Unknown config: %s\n\n" %cmd

class sound_alert:
    command = "alert"
    info = "Play an auditory alert"

    def do(*args):
        if debug: print "Palying sound..."
        n = 0
        while n < 4:
            system("mplayer alert.mp3")
            n += 1
        if debug: print "Sound played."

class parents_alert:
    command = "parental-alert"
    info = "Send an email to alert the parents"

    def do(*args):
        inet = """
From: Distributore di pillole salvavita <alerts@lspid.local>
To: Parenti dell'anziano <%s>
Subject: Notifica dal distributore di pillole

Gentile signor/a,

il suo parente non ha ancora assunto i farmaci prescritti.

Cordiali saluti,
il distributore

E-Mail spedita automaticamente
NON-SPAM
""" %conf.mail()
        cmd = "/usr/sbin/sendmail %s << EOF %sEOF" %(conf.mail(), inet)
        system(cmd)
        if debug: print "Mail sent"

class pills_taken:
    command = "pills-taken"
    info = "Change LED color to comunicate that the pills was taken"
    
    def do(*args):
        if debug: print "Comunicating with arduino"
        arduino.send_message("set status: pills-taken")
        arduino.send_message("set led.color: green")
    
