#!/usr/bin/python
# -*- coding: utf8 -*-
#
# File: webapp.py
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

# WebApp for the life-saving pills distributor

import functions
import os
import cherrypy

# Inizialize web pages
wwwpages = {}
def load_page(filename):
    if not os.path.isfile(filename):
        return False
    fh = open(filename, "r")
    fc = fh.read()
    fh.close()
    wwwpages[filename.split(".")[0]] = fc
    return
load_page("index.html")
load_page("style.css")
load_page("done.html")

class AdministrationWebApp:
    def index(self, *args):
        return wwwpages["index"] %(functions.conf.mail(),
                                   str(functions.conf.hour()),
                                   str(functions.conf.minutes())
                                   )
    index.exposed = True

    def mod(self, mail, hour, minutes, *args):
        functions.conf.mail_set(mail)
        functions.conf.hour_set(hour)
        functions.conf.minutes_set(minutes)
        return wwwpages["done"]
    mod.exposed = True
    def modd(self, mail, hour, minutes, *args):
        functions.conf.mail_set(mail)
        functions.conf.hour_set(hour)
        functions.conf.minutes_set(minutes)
        return "OK"
    modd.exposed = True

    def data(self, *args):
        return "%s:%s:%s" %(functions.conf.mail(),
                            str(functions.conf.hour()),
                            str(functions.conf.minutes())
                            )
    data.exposed = True

    def style(self, *args):
        return wwwpages["style"]
    style.exposed = True

conf = {}
conf["global"] = {"server.socket_host" : "0.0.0.0",
                       "server.socket_port" : 14302,
                       "server.max_request_body_size" : 104857600,
                       "server.socket_timeout" : 60,
                        }
conf["/logo.png"] = {"tools.staticfile.on" : True,
                     "tools.staticfile.filename" : os.path.abspath("logo.png")
                     }

cherrypy.quickstart(AdministrationWebApp(), config=conf)
