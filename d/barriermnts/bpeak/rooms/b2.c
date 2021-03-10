//b2.c
#include <std.h>
#include "../bpeak.h"
inherit IHRMS+"b.c";
int searched;

void create(){
::create();
set_exits(([
"north":INRMS+"b1",
"southwest":INRMS+"b3"
]));
}
string ldesc(string str){
   return("%^RESET%^The %^ORANGE%^sandy shores %^RESET%^continue here in their"
" endless loll of peace and tranquility, stretching out to the southwest in flat"
" stretches of fine %^ORANGE%^sand.  %^RESET%^The %^BOLD%^%^CYAN%^clear"
" %^RESET%^%^CYAN%^w%^BLUE%^a%^BOLD%^%^CYAN%^t%^RESET%^%^CYAN%^e%^BOLD%^%^CYAN%^r"
"%^BLUE%^s %^RESET%^of the %^CYAN%^Dagger Sea %^RESET%^roll up to the %^ORANGE%^"
"shores %^RESET%^in %^BOLD%^%^WHITE%^white capped %^CYAN%^w%^RESET%^%^CYAN%^a"
"%^BLUE%^v%^BOLD%^%^CYAN%^e%^RESET%^%^CYAN%^s %^RESET%^that continually wash up"
" %^GREEN%^kelp, %^RESET%^s%^BOLD%^%^WHITE%^h%^BLACK%^e%^WHITE%^l%^RESET%^l"
"%^BOLD%^%^WHITE%^s, %^RESET%^and other pieces of %^CYAN%^sea life, %^RESET%^leaving"
" them to litter the %^ORANGE%^sands %^RESET%^around you feet.  Every once in a while"
" a small %^RESET%^c%^BOLD%^%^BLACK%^r%^RESET%^a%^BOLD%^%^BLACK%^b %^RESET%^can be"
" seen scurrying across the %^ORANGE%^sands %^RESET%^before it burrows down below"
" them.");
}

