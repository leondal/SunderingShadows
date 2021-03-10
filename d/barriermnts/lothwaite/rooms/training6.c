//training area for Lothwaite.  Circe 9/17/04
#include <std.h>
#include "../lothwaite.h"

inherit STORAGE"training";

void create(){
   ::create();
   set_long( ::query_long()+"  You are standing in the middle of the "+
      "training field, where the ground seems to be the muddiest from "+
      "the countless feet that have wandered through here.\n");
   set_exits(([
      "northwest" : PATHEXIT"training2",
      "north" : PATHEXIT"training3",
      "northeast" : PATHEXIT"training4",
      "east" : PATHEXIT"training7",
      "southeast" : PATHEXIT"training10",
      "south" : PATHEXIT"training9",
      "southwest" : PATHEXIT"training8",
      "west" : PATHEXIT"training5"
   ]));
}

void reset(){
   ::reset();
   if(!query_night()){
      if(!present("trainer")){
         new(MON"trainer")->move(TO);
      }
   }
}