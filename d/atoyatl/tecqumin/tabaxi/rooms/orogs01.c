#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit ROOM;


void create() {
  ::create();
  set_short("%^BOLD%^%^BLACK%^bl%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^ck"
           +" gr%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^n%^RESET%^i%^BOLD%^%^BLACK%^te"
           +" cl%^RESET%^i%^BOLD%^%^BLACK%^ff");
  set_long("You are inside a cave at the bottom of a cliff");

  set_exits( ([  "out" : TABAXROOM + "orog_entry.c" ]) );

}

void init(){
  ::init();
  set_had_players(3);
}

