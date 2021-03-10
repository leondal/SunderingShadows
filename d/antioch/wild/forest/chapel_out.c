// Created by Grolim, for ShadowGate
// Coded Tue 9 May, 1995 14:39:52 CET
// Forest around Antioch

#include <std.h>
#include "/d/antioch/areadefs.h"
inherit "/std/church.c";

void create() {
  ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
  set_property( "light", 2);
   set_property( "indoors", 1);
  set_property( "no castle", 1);
  set("short",
       "A chapel outside the city"
      );
  set("long",
@ANTIOCH
You are standing in a place of devotion.
This place is used to pray, and there is an atmosphere of silence and 
respect here.  You feel here a presence of something higher.  That 
something makes you feel very peaceful.
ANTIOCH
      );
   set_exits( ([
      "southwest": FOREST+"forest_entr1",
      ]) );
   set_smell( 
   "default", "You are experiencing a smell of devotion. ",
   );
   set_listen( 
   "default", "You hear the sound of souls in peace. ",
   );
}

void init() {
   ::init();
   add_action("search_room","search");
}

int search_room(string str){
  int r;
  if(str) {
    tell_object(TP,"You can't search that.");
    return 1;
  }
  if(!present("chest")){
    r = random(2);
    if(r==0) new("/d/hm_quest/chests/chest3")->move(TO);
    else new("/d/hm_quest/chests/chest25")->move(TO);
    tell_object(TP,"You find a strange chest.");
  }
  return 1;
}
