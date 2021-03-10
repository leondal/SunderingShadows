#include <std.h>
#include <terrain.h>
#include "../../tecqumin.h"
inherit J_MAZE;

void create() {
  ::create();
  base_exits = ([ "west": JUNG_ROOM + "ropebridge5"]);
  set_basic_exits();
  set_post_exit_functions(({"west"}), ({"WentWest"}));
  set_pre_exit_functions(({"west"}), ({"GoWest"}));
  r_path = JUNG_ROOM9;
}
int is_map_transition(){
  return 1;
}


void on_enter(){
  object mazeroom1, mazeroom2;
  string *exits;
  mazeroom1 = find_object_or_load(JUNG_ROOM9 + "j_maze0.c");
  set_basic_exits();
  if (sizeof(query_exits())<2){
    BUILDER->restore_exits(TO);
  }
  set_basic_exits();
  if (sizeof(query_exits())<2){
    mazeroom1->remove_maze();
    mazeroom1->make_maze();
  }   
}

void enter_west(){
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

int GoWest(){
  "/d/atoyatl/bridge_monitor_d.c"->set_PosDir(TP, 
                                      ({64, STATIONARY, WEST}));
  return 1;
}

int WentWest(){
  object room;
  room = find_object_or_load(JUNG_ROOM + "ropebridge5");
  if (objectp(room)){
    room->enter_east();
  }
}
