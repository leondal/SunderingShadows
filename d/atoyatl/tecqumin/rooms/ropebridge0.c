#include <std.h>
#include <move.h>
#include "../tecqumin.h"


inherit TECBASE + "ropebridge_base.c";

void create() {
  ::create();
  set_exits(([
      "west" : JUNG_ROOM5 + "j_link9",
      "east" : JUNG_ROOM + "ropebridge1",
      "path" : JUNG_ROOM + "canyon_path6"
   ]));
  set_post_exit_functions(({"west"}), ({"WentWest"}));
  add_item("path", "The small path winds north and south down the canyon wall to the riverbank far below");
}


void init(){
  ::init();
}

string base_desc(){
  return "%^GREEN%^You are standing at the%^ORANGE%^"
  +" western%^GREEN%^ end of a %^RESET%^rope bridge"
  +" %^GREEN%^over a wide %^BOLD%^%^GREEN%^j%^RESET%^"
  +"%^GREEN%^u%^BOLD%^%^GREEN%^ng%^RESET%^%^GREEN%^l"
  +"%^BOLD%^%^GREEN%^e %^RESET%^%^ORANGE%^canyon%^GREEN%^."
  +" A small %^RESET%^path %^GREEN%^leads down to the bed"
  +" of the %^ORANGE%^canyon%^RESET%^%^GREEN%^, where a"
  +" %^BOLD%^%^BLUE%^br%^RESET%^%^BLUE%^o%^BOLD%^%^WHITE%^a"
  +"%^RESET%^%^CYAN%^d %^BLUE%^r%^RESET%^%^BLUE%^i%^CYAN%^v"
  +"%^BOLD%^%^BLUE%^er %^RESET%^%^GREEN%^flows in a"
  +" generally southerly direction. A small %^RESET%^path%^GREEN%^"
  +" winds down the side of the %^ORANGE%^canyon wall"
  +" %^GREEN%^to the riverbank far below";
}

string long_desc(){
  string desc;
  desc = ::long_desc();
  desc += "";
  return desc;
}


int head_west(string str){
  return 0;
}

int WentWest(){
  object room;
  room = find_object_or_load(JUNG_ROOM + "j_link9");
  if (objectp(room)){
    room->enter_east();
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
                                                           == -1){
        "/d/atoyatl/bridge_monitor_d.c"->set_PosDir(critters[i], 
                                        ({0, STATIONARY, EAST}));
      }
    }
  }
}
