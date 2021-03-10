#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit VAULT;

string long_desc();
string query_slope1();
string query_slope2();
int clear;
void set_floor();

void create() {
  ::create();
  clear = 0;
  set_property("indoors", 1);
  set_property("light", 2);
  set_short("A narrow tunnel");
  set_long((:TO, "long_desc":));
  set_terrain(NAT_CAVE);
  set_travel(SLICK_FLOOR);
  set_smell("default","The air is stale and musty");
  set_listen("default","It's very quiet");
  call_out("set_floor", 1);
  set_items( ([     
       ({ "root", "roots", }): "The ancient roots that have crept up"
                       +" through the floor here are gnarled and twisted,"
                       +" thick as an ogre's wrist and tough as old"
                       +" leather. They make moving at more than a"
                       +" walking pace difficult, and would take some"
                       +" effort to clear."
        ]) );

  
}
void init(){
  ::init();
  add_action("move_fun", "north");
  add_action("move_fun", "northeast");
  add_action("move_fun", "east");
  add_action("move_fun", "southeast");
  add_action("move_fun", "south");
  add_action("move_fun", "southwest");
  add_action("move_fun", "west");
  add_action("move_fun", "northwest");
  add_action("move_fun", "down"); 
  add_action("clear", "clear");
}

void reset(){
  ::reset();
  if (clear ==1 && random(2)==1){
    tell_room(TO, "The weeds and roots tangle back into place on the floor");
    clear = 0;
  }
  set_floor();
}

string query_slope1(){
  return "";
}
string query_slope2(){
  return "";
}

void set_floor(){
  string floor, exit1, exit2, *exits;
  switch (clear){
  case 0:
    floor = "The floor is plain earth here, and many fibrous old"
                +" roots poke through, their tangled and knotted shapes"
                +" grasping at your feet as you try to move.";
    break;
  case 1:
    floor = "The floor is plain earth here. The tree roots have been removed to make a clear"
           +" path.";
    break;
  }
  exits = TO->query_exits();
  if (query_slope1()!=""){
    exit1 = query_slope1();
    exit2 = query_slope2();
  } else {
    if (sizeof(exits)>1){
      exit1 = exits[0];
      exit2 = exits[1];
    }
  }
  if (exit1 && exit2){
    floor += " There is a slope in the floor, downwards from %^BOLD%^%^YELLOW%^" + exit1 
            +"%^RESET%^ to %^BOLD%^%^YELLOW%^" + exit2 + "%^RESET%^." ;
  }
  add_item("floor", floor);
}


int is_clear(){
  return clear;
}

int clear(string str){
  if (!objectp(TP)){
    return 0;
  }
  if (str != "roots" && str != "floor"){
    tell_object(TP, "Clear what?");
    return 1;
  }
  if (clear == 1){
    tell_object(TP, "The floor has already been cleared of roots here");
    return 1;
  }
  tell_object(TP, "You set about clearing the roots from the floor");
  tell_room(TO, TPQCN + "%^RESET%^ sets about clearing the roots from the"
                       +" floor", TP);
  TP->set_paralyzed(5, "You are busy clearing away the roots");
  set_floor();
  clear = 1;
}

int move_fun(string str){
  object snag, ball;
  if (!objectp(TP)){ 
    return 0;
  }
  // Make sure people can't just run past the stone ball to avoid getting
  // crushed
  ball = present("stone ball", TO);
  if (objectp(ball)){
    if (str == (string)ball->query_last_exit()){
      tell_object(TP, "You can't go that way! The massive stone ball"
                     +" rolling towards you is in the way, and it's"
                     +" filling up the whole tunnel!");
    }
  }
  //Then trip them up if they have got their feet snagged in the roots
  snag = present("xxsnagxx", TP);
  if (!objectp(snag) && clear == 0){
    snag = new(OBJ + "snag.c");
    snag->move(TP);
  } 
  // And if they weren't snagged before, snag them now.
  else {        
    snag->move_fun();
  }
  return 0;
}

string long_desc(){
    switch (clear){
    case 0:
      return "This is an %^ORANGE%^arched tunnel%^RESET%^, some fifteen"
          +" feet in height,  seemingly dug through the"
          +" %^GREEN%^li%^ORANGE%^ving ear%^GREEN%^th%^RESET%^. There are"
          +" no visible supports in the tunnel, and it doesn't appear"
          +" particularly stable. Patches of it are quite damp, and loose"
          +" %^ORANGE%^earth%^RESET%^ drops from the walls from time to"
          +" time. %^ORANGE%^Tree roots%^RESET%^ and %^GREEN%^weeds"
          +"%^RESET%^ poke through the walls, floor and ceiling. It all"
          +" appears rather unstable. And yet, somehow, the tunnel"
          +" remains in place.";
     case 1:
       return "This is an %^ORANGE%^arched tunnel%^RESET%^, some fifteen"
          +" feet in height,  seemingly dug through the"
          +" %^GREEN%^li%^ORANGE%^ving ear%^GREEN%^th%^RESET%^. There are"
          +" no visible supports in the tunnel, and it doesn't appear"
          +" particularly stable. Patches of it are quite damp, and loose"
          +" %^ORANGE%^earth%^RESET%^ drops from the walls from time to"
          +" time. %^ORANGE%^Tree roots%^RESET%^ and %^GREEN%^weeds"
          +"%^RESET%^ poke through the walls and ceiling, though the floor has been cleared of"
          +" them. It all appears rather unstable. And yet, somehow, the tunnel"
          +" remains in place.";
  }
}