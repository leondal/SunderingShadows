#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit ROOM;


void create() {
  object ob;
  ::create();
  set_short("Inside the stockade");
  set_long("You are in the southwest corner of the %^ORANGE%^stockade%^RESET%^, just west of the"
          +" gateway. A stairway here leads up onto the battlement.");
  set_exits( ([ "up" : TABAXROOM + "battlement7", 
             "north" : TABAXROOM + "west_section",
             "east"  : TABAXROOM + "stockade",
             "watch" : TABAXROOM + "watchtower",
             "bt6"   : TABAXROOM + "battlement6",
             "bt5"   : TABAXROOM + "battlement5"
             ]) );
  set_invis_exits( ({"watch", "bt5", "bt6", }) );
  set_pre_exit_functions( ({"watch", "bt5", "bt6"}),({"go_on", "go_on", "go_on" }) );
  ob = new(TABAXOBJ + "catapult.c");
  ob->move(TO);
}

int go_on(){
  return 0;
}

void init(){
  ::init();
  set_had_players(3);
}

string query_granary_dir(){
  return "north";
}
