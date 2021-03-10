#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit ROOM;


void create() {
  int i;
  object tabaxi;
  ::create();
  set_short("A place to shoot arrows from");
  set_long("This is a secret place and you really shouldn't be here!");
}

void init(){
  ::init();
  set_had_players(3);
}
