
# Automatically generated by /home/kevin/Documents/cpsc-120-solution-lab-12/.action/ccsrcutilities.py on 2023-11-16 15:45:36

TOPTARGETS = all clean spotless format lint header test unittest

SUBDIRS = $(wildcard part-?/.)

default all: all

$(TOPTARGETS): $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -f Makefile -C $@ $(MAKECMDGOALS)

.PHONY: $(TOPTARGETS) $(SUBDIRS)

