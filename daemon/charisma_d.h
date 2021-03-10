// charisma_d.h
// Header file for charisma stuffs.
// +20 = preferential, +16 = Goodwill, +7 = Tolerant,  0 = Baseline.
// -7 = Neutral feelings with negative connotations. -16 = Antipathy,
// -20 = racial hatred.


#define DEFAULT "default"
#define _DROW ([ "drow": -15 , DEFAULT, -20 ])
#define _HALFDROW ([ DEFAULT, -18 ])
#define _DWARF ([ "drow": -18, "half-drow": -19 , "dwarf": 20, "elf" : -10, "gnome" : 13, "half-elf": -6, "halfling": 13, "half-orc": -17 , "human": -3 , DEFAULT: -4 ])
#define _ELF ([ "drow": -20, "half-drow": -20 , "dwarf": -10, "elf" : 20, "gnome" : 7, "half-elf": 10, "halfling": 7, "half-orc": -12 , "human": -15, DEFAULT: -6 ])
#define _GNOME ([ "drow": -20, "half-drow" : -19, "dwarf": 13 , "elf": 8, "gnome": 20,  DEFAULT: -5])
