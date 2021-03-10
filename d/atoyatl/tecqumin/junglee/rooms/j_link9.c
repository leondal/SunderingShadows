#include <std.h>
#include <terrain.h>
#include "../../tecqumin.h"
inherit J_MAZE;

void create() {
  ::create();
  base_exits = ([ "east": JUNG_ROOM + "ropebridge0" ]);
  set_basic_exits();
  set_post_exit_functions(({"east"}), ({"WentEast"}));
  set_pre_exit_functions(({"east"}), ({"GoEast"}));
  r_path = JUNG_ROOM5;
}
int is_map_transition(){
  return 1;
}


void on_enter(){
  string *exits;
  set_basic_exits();
  update_exits();
}

int GoEast(){
  "/d/atoyatl/bridge_monitor_d.c"->set_PosDir(TP, 
                                      ({0, STATIONARY, EAST}));
  return 1;
}

void enter_east(){
  object * critters;
  int i, count;
  critters = all_living(TO);
  count = sizeof(critters); 
  if (count >0){
    for (i=0;i<count;i++){
      if((int)"/d/atoyatl/bridge_monitor_d.c"->query_pos(critters[i])
                                                           != -1){
        "/d/atoyatl/bridge_monitor_d.c"->remove_crosser(critters[i]);
      }
    }
  }
}

int WentEast(){
  object room;
  room = find_object_or_load(JUNG_ROOM + "ropebridge0");
  if (objectp(room)){
    room->enter_west();
  }
}
