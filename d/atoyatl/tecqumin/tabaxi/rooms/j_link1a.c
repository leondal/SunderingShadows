#include <std.h>
#include <terrain.h>
#include "../../tecqumin.h"
inherit J_MAZE;

void create() {
  ::create();
  set_exits( ([ "south" : JUNG_ROOM + "j_link1", ]) );
}
void init(){
  object mazeroom, builder;
  mapping mazes;
  string *exits, *saved_exits, file;
  ::init();
  mazeroom = find_object_or_load(JUNG_ROOM + "j_maze0.c");
  exits = mazeroom->query_exits();
  if (sizeof(query_exits())<2){
    BUILDER->restore_exits(TO);
  }
  file = file_name(TO);
  mazes = BUILDER->query_saved_mazes();
  saved_exits = mazes[file];
  if (sizeof(exits)<1 && sizeof(saved_exits)<1){
    "/d/atoyatl/maze_d.c"->set_roompath(JUNG_ROOM + "j_maze");
    "/d/atoyatl/maze_d.c"->set_southroom(WEMIC + "path14.c");
    "/d/atoyatl/maze_d.c"->set_northroom(JUNG_ROOM + "j_link1.c");
    "/d/atoyatl/maze_d.c"->set_eastroom(JUNG_ROOM + "j_link8a.c");  
    "/d/atoyatl/maze_d.c"->set_special_rooms( ({JUNG_ROOM + "jung_clearing.c", JUNG_ROOM 
                                                  + "jung_waterhole"}) );
    "/d/atoyatl/maze_d.c"->init_maze(5, 5, JUNG_ROOM + "j_maze", 30);
  }    
  set_had_players(3);
}