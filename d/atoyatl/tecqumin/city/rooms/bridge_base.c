#include <std.h>
#include <move.h>
#include "../../tecqumin.h"


inherit CITY_ROOM + "canalbank_base.c";
string bridge_dir;


void create() {
  ::create();
  add_item( ({"bridge", "stone bridge"}), 
    "The bridge is of fairly simple design. A small flight"
   +" of steps leads from the causeway up to the first of"
   +" three massive stone slabs that lay across a three"
   +" pairs of stone columns rising from the %^GREEN%^st"
   +"%^BOLD%^%^BLACK%^a%^RESET%^%^GREEN%^gn"
   +"%^BOLD%^%^BLACK%^a%^RESET%^%^GREEN%^nt %^BOLD%^%^BLACK%^"
   +"w%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^t%^RESET%^%^BLUE%^e"
   +"%^GREEN%^r%^BOLD%^%^BLACK%^s %^RESET%^of the"
   +" %^BOLD%^%^BLACK%^c%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^nal"
   +".");
}

string long_desc(){
  return ::long_desc() + "A %^ORANGE%^broad causeway%^GREEN%^"
  +" runs east-west through the j%^BOLD%^%^GREEN%^u%^RESET%^"
  +"%^GREEN%^ng%^ORANGE%^l%^GREEN%^e here, leading to a"
  +" %^RESET%^stone bridge %^GREEN%^across a disused"
  +" %^BOLD%^%^BLACK%^c%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^nal"
  +" %^RESET%^to the "+ bridge_dir + ".";
}

