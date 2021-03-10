#include <std.h>
#include "../githyanki.h"

inherit STORAGE"prison.c";

void create(){
   ::create();
  set_long(::query_long()+"%^RESET%^%^ORANGE%^There is a heavy iron door here%^RESET%^.\n");
   set_exits(([
      "west" : ROOMS"1_12",
      "east" : ROOMS"1_26",
      "south" : ROOMS"1_18",
   ]));

    set_door("iron door",ROOMS"1_26","east","gith_key");
    set_locked("iron door", 1);
    lock_difficulty("iron door",-80, "lock");
    set_door_description("iron door","%^BLACK%^%^BOLD%^This door has been wrought "+
"from iron and looks very secure. %^RESET%^Arcane runes%^BLACK%^%^BOLD%^ have been "+
"carved into it around the hinges and around the lock%^RESET%^");
    set_string("ornate door", "open", "%^BLACK%^%^BOLD%^The hinges squeel as the door opens.%^RESET%^");
    set_string("ornate door", "close", "%^BLACK%^%^BOLD%^The door closes with a >THUD<.%^RESET%^");



}