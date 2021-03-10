#include <std.h>
#include "../tormdefs.h"
inherit whatever;
object bboard;
void create()
  {
  ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
    set_short("Entrance to Torm's park");
  set_long(
    "Entrance to Torm's park.\n"
    "  Torm's marketplace stretches out to all sides but north here."
  "  You can see through the open gates to the north the central park of Torm and the mansion which houses its government."
    "  Just to the south you can see Torm's great water fountain in the center of the marketplace."
  );
  set("night long",
  "%^BLUE%^"
  "Torm's central park lies to the north through a set of open gates."
    "  To all other sides Torm's great open marketplace lies shrouded in fog and fades away in the distance."
  );
  set_exits(([
  "north":TCITY+"c103",
  "east":TCITY+"c46",
  "west":TCITY+"c44",
  "south":TCITY+"c56",
  ]));
  set_pre_exit_functions(({"north"}),({"block"}));
  set_light(2);
  add_item("gates","The gates hinges are rusty and look as if they haven't been closed in ages, and really don't look like they could be moved anymore.");
}
void reset(){
  ::reset();
  if(!bboard){
  bboard=new("/std/bboard");
  bboard->set_name("board");
  bboard->set_id(({"board",
  "bulltin board","a bulletin board","bulletin board on the wall","a bulletin board on the wall",
  }));
  bboard->set_board_id("union_board");
  bboard->set_max_posts(25);
 bboard->set_short("Arcane Bulletin Board");
  bboard->set_long("This elegantly framed bulletin board is host to the notes and remarks of the people passing through the city of Torm for other travelers and merchants.");
  }
  bboard->set_location("/d/dagger/Torm/city/c45");
}
int block(){
  if((string)TP->query_race()=="sahuagin"){
  tell_room(ETO,"%^GREEN%^The sahuagin looks north and then thinks again about going that way.");
  return 0;
  }
  return 1;
}
