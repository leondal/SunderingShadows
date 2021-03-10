#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit ROOM;


void create() {
  object ob;
  ::create();
  set_short("Inside the stockade");
  set_long("You are in the southeast corner of the %^ORANGE%^stockade%^RESET%^, just east of the"
          +" gateway. A stairway here leads up onto the battlement. There is an old catapault"
          +" tucked away in a disused area here.");
  set_exits( ([ "up" : TABAXROOM + "battlement5", 
             "north" : TABAXROOM + "east_section",
              "west" : TABAXROOM + "stockade",
             "watch" : TABAXROOM + "watchtower",
             "bt6"   : TABAXROOM + "battlement6",
             "bt7"   : TABAXROOM + "battlement7"
             ]) );
  set_invis_exits( ({"watch", "bt7", "bt6", }) );
  set_pre_exit_functions( ({"watch", "bt7", "bt6"}),({"go_on", "go_on", "go_on" }) );
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
  return "west";
}
