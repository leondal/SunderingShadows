#include <std.h>
#include <move.h>
#include "../tecqumin.h"

inherit ROOM;

string long_desc();

void create() {
  ::create();
  set_indoors(0);
  set_property("light", 2);
  set_terrain(JUNGLE);
  set_travel(FOOT_PATH);
  set_name("A lake shore by a waterfall");
  set_short("%^BOLD%^%^CYAN%^On the %^YELLOW%^shore%^BOLD%^%^CYAN%^ of"
                 +" a lake, at the foot of a %^BOLD%^%^BLUE%^waterfall");
  set_long( "%^BOLD%^%^YELLOW%^You are on the shore of a%^BOLD%^%^CYAN%^"
           +" lake%^YELLOW%^, at the foot of a major%^BOLD%^%^BLUE%^"
           +" waterfall%^BOLD%^%^CYAN%^. The %^RESET%^%^GREEN%^j%^BOLD%^"
           +"%^GREEN%^u%^RESET%^%^GREEN%^ng%^BOLD%^%^GREEN%^l%^RESET%^"
           +"%^GREEN%^e %^BOLD%^%^YELLOW%^sits behind the shore, the"
           +" %^RESET%^%^ORANGE%^trees%^BOLD%^%^YELLOW%^ thick and the"
           +" %^RESET%^%^GREEN%^undergr%^BOLD%^%^BLACK%^o%^RESET%^"
           +"%^GREEN%^wth %^BOLD%^%^YELLOW%^unpassable apart from a few"
           +" dark, winding %^BOLD%^%^BLACK%^paths%^RESET%^%^GREEN%^. " );
  set_items(([  ]));
  set_smell("default","The air is heavy with %^CYAN%^humidity%^ORANGE%^"
                    +" and the heady scent of %^GREEN%^j%^BOLD%^"
                    +"%^GREEN%^u%^RESET%^%^GREEN%^ngle %^ORANGE%^plant"
                    +" life");
  set_listen("default","There is the constant roar of the water tumbling"
                     +" over the brink of the waterfall.");
}
void init(){
  object mazeroom;
  string *exits;
  ::init();
  mazeroom = find_object_or_load(JUNG_ROOM8 + "j_maze0.c");
  exits = mazeroom->query_exits();
  if (sizeof(query_exits())<1){
    BUILDER->restore_exits(TO);
  }
  if (sizeof(exits)<1){
    BUILDER->restore_exits(mazeroom);
    exits = mazeroom->query_exits();
  }
  if (sizeof(exits)<1){
    "/d/atoyatl/maze_d.c"->set_roompath(JUNG_ROOM8 + "j_maze");
    "/d/atoyatl/maze_d.c"->set_eastroom(JUNG_ROOM + "j_link7a.c");
    "/d/atoyatl/maze_d.c"->set_westroom(JUNG_ROOM + "j_link8.c");  
    "/d/atoyatl/maze_d.c"->set_southroom(JUNG_ROOM + "shore.c");
    "/d/atoyatl/maze_d.c"->set_special_rooms( ({ }) );
    "/d/atoyatl/maze_d.c"->init_maze(5, 5, JUNG_ROOM8 + "j_maze", 30);
  }    
}



