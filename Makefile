# Makefile for mp3cast~

lib.name = mp3cast~

class.sources = mp3cast~.c

ldlibs = -lmpg123 -lmp3lame

define forWindows
  ldlibs = -lwsock32 -lmpg123 -lmp3lame
endef

datafiles = mp3cast~-help.pd mp3cast~-meta.pd README.md LICENSE.txt

# This Makefile is based on the Makefile from pd-lib-builder written by
# Katja Vetter. You can get it from:
# https://github.com/pure-data/pd-lib-builder

PDLIBBUILDER_DIR=pd-lib-builder/
include $(firstword $(wildcard $(PDLIBBUILDER_DIR)/Makefile.pdlibbuilder Makefile.pdlibbuilder))


localdep_linux: install
	scripts/localdeps.linux.sh -d "${installpath}/mp3cast~.${extension}"

localdep_windows: install
	scripts/localdeps.win.sh "${installpath}/mp3cast~.${extension}"

localdep_macos: install
	scripts/localdeps.macos.sh "${installpath}/mp3cast~.${extension}"
