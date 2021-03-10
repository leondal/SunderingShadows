#include "/d/newbie/newbie.h"


mapping MAP_GRID =  ([ "9-5": (["file" : MAINTOWN"nstreet3", "symbol" : " # ", "color" : "%^BOLD%^%^YELLOW%^"]),\
                    "9-6" : (["file" :  MAINTOWN"nstreet2", "symbol" : " | ", "color" : "%^BOLD%^%^WHITE%^"]),\
                    "9-7" : (["file" : MAINTOWN"nstreet1", "symbol" : " | ", "color" : "%^BOLD%^%^WHITE%^"]),\
                    "9-8" : (["file" : MAINTOWN"square", "symbol" : " @ ", "color" : "%^BOLD%^%^YELLOW%^"]),\
                    "9-9" : (["file" : MAINTOWN"sstreet1", "symbol" : " | ", "color": "%^BOLD%^%^WHITE%^"]),\
                    "9-10" : (["file" : MAINTOWN"sstreet2", "symbol" : " | ", "color": "%^BOLD%^%^WHITE%^"]),\
                    "9-11" : (["file" : MAINTOWN"sstreet3", "symbol" : " # ", "color" : "%^BOLD%^%^YELLOW%^"]),\
                    "6-7" : (["file" : MAINTOWN"mtower1", "symbol" : " M ", "color" : "%^BOLD%^%^CYAN%^"]),\
                    "6-8" : (["file" : MAINTOWN"wstreet3", "symbol" : " # ", "color" : "%^BOLD%^%^YELLOW%^"]),\
                    "6-9" : (["file" : MAINTOWN"library", "symbol" : " L ", "color" : "%^BOLD%^%^CYAN%^"]),\
                    "7-7" : (["file" : MAINTOWN"weapon", "symbol" : " W ", "color" : "%^BOLD%^%^CYAN%^"]),\
                    "7-8" : (["file" : MAINTOWN"wstreet2", "symbol" : " = ", "color": "%^BOLD%^%^WHITE%^"]),\
                    "7-9" : (["file" : MAINTOWN"wbar", "symbol" : " B ", "color" : "%^BOLD%^%^CYAN%^"]),\
                    "8-7" : (["file" : MAINTOWN"clothing", "symbol" : " J ", "color" : "%^BOLD%^%^CYAN%^"]),\
                    "8-8" : (["file" : MAINTOWN"wstreet1", "symbol" : " = ", "color": "%^BOLD%^%^WHITE%^"]),\
                    "8-9" : (["file" : MAINTOWN"general", "symbol" : " G ", "color" : "%^BOLD%^%^CYAN%^"]),\
                    "8-5" : (["file" : MAINTOWN"instruments", "symbol" : " i ", "color" : "%^BOLD%^%^CYAN%^"]),\
                    "8-6" : (["file" : MAINTOWN"bardcomps", "symbol" : " I ", "color" : "%^BOLD%^%^CYAN%^"]),\
                    "10-6" : (["file" : MAINTOWN"church", "symbol" : " C ", "color" : "%^BOLD%^%^CYAN%^"]),\
                    "10-9" : (["file" : MAINTOWN"bank", "symbol" : " b ", "color" : "%^BOLD%^%^CYAN%^"]),\
                    "10-8" : (["file" : MAINTOWN"estreet1", "symbol" : " = ", "color": "%^BOLD%^%^WHITE%^"]),\
                    "11-8" : (["file" : MAINTOWN"estreet2", "symbol" : " = ", "color": "%^BOLD%^%^WHITE%^"]),\
                    "12-8" : (["file" : MAINTOWN"estreet3", "symbol" : " # ", "color" : "%^BOLD%^%^YELLOW%^"]),\
                    "10-7" : (["file" : MAINTOWN"healer", "symbol" : " H ", "color" : "%^BOLD%^%^CYAN%^"]),\
                    "11-7" : (["file" : MAINTOWN"armor", "symbol" : " A ", "color" : "%^BOLD%^%^CYAN%^"]),\
                    "11-9" : (["file" : MAINTOWN"stable", "symbol" : " S ", "color" : "%^BOLD%^%^CYAN%^"]),\
                    "12-7" : (["file" : MAINTOWN"psifoyer", "symbol" : " Ps", "color" : "%^BOLD%^%^CYAN%^"]),\
                    "12-9" : (["file" : MAINTOWN"scribe", "symbol" : " Sc", "color" : "%^BOLD%^%^CYAN%^"]),\
                    "9-4" : (["file" : FROAD"1", "symbol" : " * ", "color" : "%^RESET%^%^GREEN%^"]),\
                    "9-3" : (["file" : FROAD"2", "symbol" : " * ", "color" : "%^RESET%^%^GREEN%^"]),\
                    "10-2" : (["file" : FROAD"3", "symbol" : " * ", "color" : "%^RESET%^%^GREEN%^"]),\
                    "13-8" : (["file" : FROAD"4", "symbol" : " * ", "color" : "%^RESET%^%^GREEN%^"]),\
                    "14-8" : (["file" : FROAD"5", "symbol" : " * ", "color" : "%^RESET%^%^GREEN%^"]),\
                    "15-8" : (["file" : FROAD"6", "symbol" : " * ", "color" : "%^RESET%^%^GREEN%^"]),\
                    "16-8" : (["file" : FROAD"7", "symbol" : " * ", "color" : "%^RESET%^%^GREEN%^"]),\
                    "5-8" : (["file" : FROAD"8", "symbol" : " * ", "color" : "%^RESET%^%^GREEN%^"]),\
                    "4-8" : (["file" : FROAD"9", "symbol" : " * ", "color" : "%^RESET%^%^GREEN%^"]),\
                    "3-8" : (["file" : FROAD"10", "symbol" : " * ", "color" : "%^RESET%^%^GREEN%^"]),\
                    "2-8" : (["file" : FROAD"11", "symbol" : " * ", "color" : "%^RESET%^%^GREEN%^"]),\
                    "9-12" : (["file" : FROAD"12", "symbol" : " * ", "color" : "%^RESET%^%^GREEN%^"]),\
                    "9-13" : (["file" : FROAD"13", "symbol" : " * ", "color" : "%^RESET%^%^GREEN%^"]),\
                    "9-14" : (["file" : FROAD"14", "symbol" : " * ", "color" : "%^RESET%^%^GREEN%^"]),\
                    "8-15" : (["file" : FROAD"15", "symbol" : " * ", "color" : "%^RESET%^%^GREEN%^"]),\
                    "7-16" : (["file" : FROAD"16", "symbol" : " * ", "color" : "%^RESET%^%^GREEN%^"]),\
                    "6-17" : (["file" : FROAD"17", "symbol" : " Ho", "color" : "%^BOLD%^%^BLACK%^"]),\
                    "10-15" : (["file" : FROAD"18", "symbol" : " * ", "color" : "%^RESET%^%^GREEN%^"]),\
                    "11-16" : (["file" : FROAD"19", "symbol" : " * ", "color" : "%^RESET%^%^GREEN%^"]),\
                    "12-17" : (["file" : FROAD"20", "symbol" : " * ", "color" : "%^RESET%^%^GREEN%^"]),\
                    "12-18" : (["file" : HILL"mine1", "symbol" : " Mi", "color" : "%^BOLD%^%^BLACK%^"]),\
                    "1-7" : (["file" : KEEP"path4", "symbol" : " K ", "color" : "%^BOLD%^%^BLUE%^"]),\
                    "16-9" : (["file" : GRAVEYARD"cemetary1", "symbol" : " Gy", "color" : "%^BOLD%^%^BLACK%^"]),\
                    "10-1" : (["file" : MEADOWR"meadow2", "symbol" : " Me", "color" : "%^BOLD%^%^YELLOW%^"]),\
                    "x-size" : 20, "y-size" : 20]);