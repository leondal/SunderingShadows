#include <std.h>
#include "Pepitom.h"
inherit "/d/shadow/room/pepitom/pepitom.c";
inherit ROOM;

void create(){ 
   ::create();
   set_property("light",0);

   set_short(
@JAVAMAKER
East Main Street
JAVAMAKER
   );

   set_long(
@JAVAMAKER
You are in the house of the Weaponsmith, Stella.
JAVAMAKER
   );

   set_smell("default","You smell the odor of fresh manure.");
   set_listen("default","You can hear the occasional sound of people moving about the town.");
   set_items(([
   ]));

   set_exits(([
      "west":ROOMS+"wroad13.c",
]));

}


void reset(){
   ::reset();

}

void init(){
   ::init();

}








