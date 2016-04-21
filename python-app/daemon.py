#!/usr/bin/python
# -*- coding: utf8 -*-
#
# File: daemon.py
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

# Daemon for the life-saving pills distributor
print "Daemon started!"
# Import modules
try:
    import functions
    import time
    from datetime import datetime
except:
    print "ImportError, exiting."
    exit()

# Disable debug
functions.debug = True
# Read and load functions
commands = {}

def append_function(func):
    commands[func().command] = [func().info, func().do]

def call(func):
    if func in commands:
        commands[func][1]()

append_function(functions.sound_alert)
append_function(functions.parents_alert)
append_function(functions.config)
append_function(functions.pills_taken)

hour = functions.conf.hour()
mins = functions.conf.minutes()

uwt = 0
first_timeout_alert = 60+9 #900
secnd_timeout_alert = 60+18 #1800

while True:
    if int(datetime.now().strftime("%H")) == hour and \
       int(datetime.now().strftime("%M")) == mins:
        functions.arduino.send_message("must take the pills")
        time.sleep(60)
        uwt = 60
    if uwt == first_timeout_alert:
        functions.arduino.send_message("has taken the pills")
        r = functions.arduino.get_message()
        if r == "was taken":
            uwt = 0
        else:
            call("alert")
    if uwt == secnd_timeout_alert:
        functions.arduino.send_message("has taken the pills")
        r = functions.arduino.get_message()
        if r == "was taken":
            uwt = 0
        else:
            call("parental-alert")
            call("alert")
    time.sleep(1)
    uwt += 1
    print "uwt", uwt
