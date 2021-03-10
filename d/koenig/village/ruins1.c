//ruins1.c - Coded by Circe 11/27/03
#include <std.h>
#include "../koenig.h"

inherit ROOM;

int items;

void create() {
items = 1;
    ::create();
    set_terrain(WOOD_BUILDING);
    set_travel(DIRT_ROAD);
    set_property("light",2);
    set_property("indoors",1);
    set_short("A ruined building");
    set_name("A ruined building");
    set_long(
      "The original purpose of this building are no longer clear.  "+
      "It lies now in utter %^RED%^ruin%^RESET%^, with the walls barely "+
      "standing.  %^ORANGE%^Rotted shelving %^RESET%^along one of the walls "+
      "hints that this was perhaps a store of some sort at one time.  The "+
      "%^BLUE%^floor %^RESET%^is covered in the rubble of burned %^ORANGE%^wood "+
      "%^RESET%^and %^BOLD%^%^BLACK%^ash%^RESET%^.  Little else remains here."+
      "\n"
    );
    set_items(([
      ({"rubble","wood","floor"}) : "The floor was once wooden, but has now been "+
         "covered with the rotting wood of the shelves and a thick layer of ash "+
         "and soot.  It would take a lot of work to dig through it, but it might "+
         "be hiding something.",
      ({"walls","shelving","shelves"}) : "The remaining walls are falling apart, "+
         "and the outdoors is clearly visible through them.  Shelves are still "+
         "attached in places, but they are not sturdy enough to hold anything.",
      ({"soot","ash"}) : "The thick layer of black ash covers everything."
   ]));
   set_listen("default","The wind is the only sound you hear.");
   set_smell("default","The pungent scent of ash rises from the floor.");
   set_search("default","You think the rubble might be hiding something.");
   set_search("rubble",(:TO,"search_rubble":));
   set_exits(([
      "east" : VILROOMS"k_road09"
   ]));
}

void search_rubble(){
   if(!items){
      tell_object(TP,"The rubble is overturned as if someone has searched here already.");
      return;
   }
   switch(random(10)){
      case 0..1:  tell_object(TP,"You find nothing of interest in the rubble, but you "+
                     "stir up a huge cloud of dust.");
                  tell_room(ETP,""+TPQCN+" searches the rubble, stirring up dust.",TP);
                  break;
      case 2..5:  tell_object(TP,"You find something hidden in the rubble, but you "+
                     "stir up a huge cloud of dust.");
               tell_room(ETP,""+TPQCN+" searches the rubble, stirring up dust.",TP);
               "/d/common/daemon/randstuff_d"->find_stuff(TO,"stuff");
               break;
      case 6:  tell_object(TP,"You find something hidden in the rubble, but you "+
                     "stir up a huge cloud of dust.");
               tell_room(ETP,""+TPQCN+" searches the rubble, stirring up dust.",TP);
               "/d/common/daemon/randstuff_d"->find_stuff(TO,"scroll");
               break;
      case 7:  tell_object(TP,"You find something hidden in the rubble, but you "+
                     "stir up a huge cloud of dust.");
               tell_room(ETP,""+TPQCN+" searches the rubble, stirring up dust.",TP);
               "/d/common/daemon/randstuff_d"->find_stuff(TO,"component",random(4)+2);
               break;
      case 8:  tell_object(TP,"You find something hidden in the rubble, but you "+
                     "stir up a huge cloud of dust.");
               tell_room(ETP,""+TPQCN+" searches the rubble, stirring up dust.",TP);
               "/d/common/daemon/randgear_d"->arm_me(TO,"tool",20,1);
               break;
      case 9:  tell_object(TP,"You find something hidden in the rubble, but you "+
                     "stir up a huge cloud of dust.");
               tell_room(ETP,""+TPQCN+" searches the rubble, stirring up dust.",TP);
               "/d/common/daemon/randgear_d"->armor_me(TO,"shield",20,1);
               break;
   }
   items = 0;
   return;
}
