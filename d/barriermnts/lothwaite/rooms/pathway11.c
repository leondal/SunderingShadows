//pathway11.c - Path through Lothwaite.  Circe 5/10/04
#include <std.h>
#include "../lothwaite.h"
inherit PATHEND;

void create(){
   ::create();
   set_long( ::query_long()+"  An iron-bound pine gate leads through a "+
      "tall earthen rampart to the west.\n");
   add_item("rampart",(:TO,"wall_desc":));
   set_exits(([
      "west" : PATHEXIT"pathway10",
      "east" : PATHEXIT"pathway12"
   ]));
   set_door("gate",PATHEXIT"pathway10","west","giant_key");
   set_door_description("gate","A massive gate made of rough pine "+
      "planks bound with iron.");
}

string wall_desc(){
   if(TP->query_size() < 2){
      return("%^GREEN%^The intimidating earthen rampart rises well "+
         "over ten times your height!  It marches both north and "+
         "south and leads west through an iron-bound gate out of "+
         "this strange town.");
   }
   if(TP->query_size() > 1 && TP->query_size() < 3){
      return("%^GREEN%^An amazing earthen rampart rises well over "+
         "five times your height, seeming somehow to fit in with "+
         "the width of the path and the unbelievable height of "+
         "the iron-bound gate to the west that runs through it.");
   } else {
   return("%^GREEN%^An earthen rampart about 30 feet high runs both "+
      "north and south, encircling this town.  For "+
      "once, the gate seems made just for you, being both wide "+
      "and tall enough for you to walk through comfortably.");
   }
}
