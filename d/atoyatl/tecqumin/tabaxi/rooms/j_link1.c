#include <std.h>
#include <terrain.h>
#include "../../tecqumin.h"
inherit J_MAZE;

void create() {
  ::create();
  set_exits( ([ "north": JUNG_ROOM + "j_link1a", ]) );
}

void init(){
  object mazeroom, builder;
  string *exits, *saved_exits, file;
  mapping mazes;
  ::init();
  mazeroom = find_object_or_load(JUNG_ROOM2 + "j_maze0.c");
  exits = mazeroom->query_exits();
  if (sizeof(query_exits())<2){
    BUILDER->restore_exits(TO);
  }
  file = file_name(TO);
  mazes = BUILDER->query_saved_mazes();
  saved_exits = mazes[file];
  if (sizeof(exits)<1 && sizeof(saved_exits)<1){
    "/d/atoyatl/maze_d.c"->set_roompath(JUNG_ROOM2 + "j_maze");
    "/d/atoyatl/maze_d.c"->set_special_rooms( ({ }) );
    "/d/atoyatl/maze_d.c"->set_southroom(JUNG_ROOM + "j_link1a.c");
    "/d/atoyatl/maze_d.c"->set_northroom(JUNG_ROOM + "j_link2.c");
    "/d/atoyatl/maze_d.c"->init_maze(5, 5, JUNG_ROOM2 + "j_maze", 30);
  }    
  set_had_players(3);
}