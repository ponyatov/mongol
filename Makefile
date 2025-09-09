# var
APP     = $(notdir $(CURDIR))
REL     = $(shell git rev-parse --short=4    HEAD)
BRANCH  = $(shell git rev-parse --abbrev-ref HEAD)
NOW     = $(shell date +%y%m%d)
PEPS    = E26,E302,E305,E401,E402,E701,E702
BINFILE = $(APP)_$(BRANCH)_$(REL)_$(NOW)
CORES   = $(shell grep processor /proc/cpuinfo| wc -l)

# dir
CWD = $(CURDIR)
INC = $(CWD)/inc
SRC = $(CWD)/src
TMP = $(CWD)/tmp

# src
C += $(wildcard src/*.c*)
H += $(wildcard inc/*.h*)
S += $(wildcard lib/*.ini lib/*.f)

# cfg
CFLAGS += -I$(INC) -I$(TMP)

# all
.PHONY: all run
all: bin/$(BINFILE) $(S)
run: bin/$(BINFILE) $(S)
	$^

# rule
bin/$(BINFILE): $(C) $(H)
	$(CXX) $(CFLAGS) -o $@ $(C) $(L)
