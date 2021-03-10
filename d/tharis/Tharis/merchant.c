//merchant.c

#include <std.h>
#include "../tharis.h"

inherit VAULT;

void create(){
   ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_property("no sticks", 1);
   set_property("light",2);
   set_property("indoors",1);

   set_short(
@JAVAMAKER
The Merchants Guild hall
JAVAMAKER
   );

   set_long(
@JAVAMAKER
     %^RED%^The Merchants Guild Hall%^RESET%^
This building has been converted into a confortable area.
The merchant's guild covers all transactions in the area. Most of
the money from fees comes here. You can't sell any thing in
Tharis unless you're a member.  Dark panelling lines the walls.
The stone floor is covered with several hide rugs. You notice
a particularly grand bearskin rug in the middle.
JAVAMAKER
   );

   set_smell("default","You smell cedar, must be from the panelling.");
   set_listen("default","You hear the rustling of papers and small chit chat amongst lounging merchants.");
   set_items(([
      "rugs":"You see in this group of rugs many different creatures: bears, various cats, you notice a heavily scaled one that must be from part of a dragon.",
      "panelling":"This dark panelling appears to be made from cedar. There are many knots in the boards. You think they could have gotten better quality wood.",
      "knots":"These knots are everywhere.  Surely with the money this place has they could have gotten better quality wood.",
      "bearskin":"This skin has its head attached and it looks to roar at you as you enter the room.",
   ]));

   set_exits(([
      "southeast":ROOMS"market1",
   ]));

   set_invis_exits(({}));
   set_trap_functions(({}),({}),({}));
   set_pre_exit_functions(({}),({}));
   set_post_exit_functions(({}),({}));
   set_door("door",ROOMS"market1","southeast","blah");

}


void reset(){
   ::reset();

}

void init(){
   ::init();
     add_action("push","push");
}

int push(string str){
     if(!str || (str != "knots" && str != "knot"))  return 0;
     if(!random(3)){
          tell_object(TP,"You push on some of the knots but nothing seems to happen.");
          tell_room(TO,""+TPQCN+" pushes on some of the knots and nothing seems to happen",TP);
          return 1;	
     }
     tell_room(TO,""+TPQCN+" pushes on some knots and one of them makes a clicking noise.",TP);
     tell_object(TP,"You push on some of the knots, then one of them gives and makes a clicking noise.");
     add_exit(ROOMS"msecret","storage");
     set_door("storage door",ROOMS"msecret","storage","blah");
     set_open("storage door",0);
     set_locked("storage door",1);
     return 1;



}
