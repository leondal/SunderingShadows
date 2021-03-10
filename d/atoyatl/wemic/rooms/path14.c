#include <std.h>
#include <terrain.h>
#include "../wemic.h"
inherit PATHBASE;


void create() {
  ::create();
  set_exits( ([      "south" : ROOMS + "path13", "northwest" : JUNG_ROOM1 + "j_link8a" ])  );
//  set_pre_exit_functions(({"northeast",}),({"GoNortheast"}));
}


void GoNortheast(){
/*  object mazeroom1, link_room;
  string *exits;
  link_room = find_object_or_load(JUNG_ROOM1 + "j_link8a");
  mazeroom1 = find_object_or_load(JUNG_ROOM1 + "j_maze0.c");
  exits = mazeroom1->query_exits();
  if (sizeof(exits)<1){
    BUILDER->restore_exits(mazeroom1);
    exits = mazeroom1->query_exits();
  }
  if (sizeof(exits)<1){
    mazeroom1->remove_maze();
    if (objectp(link_room) && sizeof(link_room->query_exits())<2){
      link_room->set_basic_exits();
    }
    mazeroom1->make_maze();
  }   */
}
