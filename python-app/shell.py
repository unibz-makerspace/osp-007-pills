#!/usr/bin/python
# -*- coding: utf8 -*-
#
# File: __init__.py
#
# Copyright (C) 2016 Marco Marinello <mmarinello@sezf.it>
# 
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#

# Shell for the life-saving pills distributor

# Import modules
try:
    import functions
except:
    print "ImportError, exiting."
    exit()

print """Life-saving pills distributor Controller
A project of the High school "E. Torricelli" http://www.torricelli.bz.it
developed in collaboration with the Makerspace of
the Free University of Bolzano http://makerspace.inf.unibz.it
Copyright (c) 2016 Marco Marinello
"""

# Read and load functions

commands = {}

def append_function(func):
    commands[func().command] = [func().info, func().do]

class got_help:
    command = "help"
    info = "Shows shell's help"

    def do(*args):
        for i in sorted(commands):
            print "%s%s%s" %(i, len(i) > 6 and "\t" or "\t\t", commands[i][0])
        print ""

append_function(got_help)

append_function(functions.sound_alert)
append_function(functions.parents_alert)
append_function(functions.config)
append_function(functions.pills_taken)

append_function(functions._exit)


# Launch shell
while True:
    try:
        do = raw_input("LSPiD Shell>>> ").lower()
    except EOFError:
        print str()
        commands["q"][1]()
    
    working = True
    
    if " " in do:
        print "Please, run one-word commands only."
        working = False
    
    if do in commands and working:
        commands[do][1]()
    else:
        print "Unknown command: %s" %do
