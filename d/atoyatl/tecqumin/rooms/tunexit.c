#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"

inherit TUNBASE;

string query_covering();

void create() { 
  ::create();

  set_exits( ([ "north" : ROOMS + "tun24", 
                   "up" : JUNG_ROOM8 + "tun_entry"]) );
  set_door("trapdoor",JUNG_ROOM + "tun_entry","up",0); 
  set_pre_exit_functions(({"up"}), ({"GoUp"}));
  set_post_exit_functions(({"up"}), ({"WentUp"}));
}

int WentUp(){
  tell_object(TP, "You emerge from a trapdoor that was hidden under " + ETP->query_identifier());
  return 1;
}

int GoUp(){
  object exitroom;
  exitroom = find_object_or_load(JUNG_ROOM8 + "tun_entry");
  if (objectp(exitroom)){
    exitroom->on_enter();
    exitroom->place_exit();
  }
  return 1;
}

string query_slope1(){
  return "north";
}

string query_slope2(){
  return "south";
}

string query_covering(){
  object room;
  room = find_object_or_load(JUNG_ROOM + "tun_entry");
  if (objectp(room)){
    return room->query_covering();
  }
  return "nothing";
}
