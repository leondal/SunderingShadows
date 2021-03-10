//treeout.c - inherit for outdoor rooms in Aketon
//Circe 10/04
#include "/d/dagger/aketon/short.h"

inherit ROOM;

void create(){
   ::create();
   set_light(2);
   set_indoors(0);
   set_terrain(BRANCHES);
   set_travel(FOOT_PATH);
   set_name("Treetop Village of Aketon");
   set_listen("default","%^B_BLUE%^%^BOLD%^%^GREEN%^ACK! This room "+
      "needs a sound - tell Circe!%^RESET%^");
   set_smell("default","%^B_BLUE%^%^BOLD%^%^GREEN%^ACK! This room "+
      "needs a smell - tell Circe!%^RESET%^");
}