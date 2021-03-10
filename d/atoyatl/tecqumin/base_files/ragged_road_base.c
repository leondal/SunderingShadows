#include <std.h>
#include <move.h>
#include "../tecqumin.h"


inherit CITY_JUNG;


void create() {
  ::create();
  add_item ( ({"road", "ancient road", "remains of road", 
    "remains of ancient road", "stone", "patches of stone", 
    "patches of worked stone", "worked gray stone"}), 
    "The ancient road has been largely overgrown by the jungle. Only"
   +" patches of stone remain, green with moss and crossed over with"
   +" tree roots. Even so, what is left suggests that long ago this may"
   +" have been a major causeway." );

}


string short_desc(){
  return "%^BOLD%^%^GREEN%^In a %^RESET%^%^GREEN%^thick%^BOLD%^"
           +" %^GREEN%^jungle";
}

