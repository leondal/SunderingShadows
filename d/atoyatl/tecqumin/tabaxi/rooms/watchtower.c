#include <std.h>
#include <move.h>
#include <daemons.h>
#include "../../tecqumin.h"

inherit ROOM;


void create() {
  ::create();
  set_short("In the watchtower");
  set_long("You are in the watchtower above the main gate of the stockade. From here you have a great"
          +" view out over the fields and into the jungle beyond. You will be able to see most"
          +" activity going on below.");
  set_exits( ([ "down": TABAXROOM + "battlement6",
                "se": TABAXROOM + "southeast_corner",  //These exits are just to allow people in the 
                "sw": TABAXROOM + "southwest_corner",  //watchtower to yell orders to those on the 
                "st": TABAXROOM + "stockade",          //battlement or manning the catapults
                "bt5": TABAXROOM + "battlement5",
                "bt6": TABAXROOM + "battlement6",
                "bt7": TABAXROOM + "battlement7"
             ]) );

  set_invis_exits( ({"se", "sw", "st", "bt5", "bt6", "bt7"}) );
  set_pre_exit_functions( ({"se", "sw", "st", "bt5", "bt6", "bt7"}),({"go_on", "go_on", "go_on",
                             "go_on", "go_on", "go_on"}) );
}

int go_on() {
  return 0;
}

void init(){
  ::init();
  add_action("yell_me", "yell");
  add_action("yell_me", "flay");
  set_had_players(3);
}

int command_tabaxi(string str, object ob){
  object * critters, critter, corner;
  int j;
  corner = find_object_or_load(TABAXROOM+"southeast_corner");
  str = "tabaxi to " + str;
  if (objectp(corner)){
    critters = all_living(corner);
    if (sizeof(critters)>0){
      for (j=0;j<sizeof(critters);j++){
        critter = critters[j];
        if (critter->id("tabaxi")){
          critter->command_me(str, ob);
        }
      }
    }
  }
}

int yell_me(string str){
  string junk, what;
  str = lower_case(str);
  str = FILTERS_D->filter_colors(str);
  command_tabaxi(str, TP);
}
