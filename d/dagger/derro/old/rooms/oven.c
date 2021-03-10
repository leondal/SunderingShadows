#include <std.h>
#include "../derrodefs.h"
inherit ROOM;

void create(){
  ::create();
   set_terrain(STONE_BUILDING);
   set_travel(RUTTED_TRACK);
  set_property("no teleport",1);
  set_property("light",2);
  set_name("An oven");
  set_property("indoors",1);
  set_short("%^RED%^Inside an oven!%^RESET%^");
  set_long( "%^RED%^Inside an oven!%^RESET%^" );
  set_listen("default","You sizzle like a prize pig!");
  set_smell("default","Damn it's hot!");
  set_items(([
  ]));
  set_exits(([
  "door":(ROOMS"c23"),
  ]));
  set_pre_exit_functions(({"door"}),({"DOOR"}));
  set_heart_beat(8);
  set_property("continue heartbeat",1);
}

void heart_beat(){
  object snake, snake2, snake3, snake4;
  object *heat;
  int i, j;
  ::heart_beat();
  heat=all_living(TO);
  if(present("fire snake",TO)){
    snake=(present("fire snake",TO));
  snake2=(present("fire snake 2",TO));
  snake3=(present("fire snake 3",TO));
  snake4=(present("fire snake 4",TO));
  }
  heat-=({snake,snake2,snake3,snake4});
  j=sizeof(heat);
  for(i=0;i<j;i++){
  if(heat[i]->query_true_invis())  continue;
  tell_object(heat[i],"%^BOLD%^%^RED%^The heat sears you!");
  heat[i]->do_damage(heat[i]->return_target_limb(),5);
  heat[i]->add_attacker(TO);
  heat[i]->continue_attack();
  }
}
int DOOR() {
  if(present("fire snake")){
  write("The firesnakes won't let you leave!");
  tell_room(TO, "The firesnakes won't let "+TPQCN+" leave!", TP);
  return 0;
   } 
  return 1;
}
