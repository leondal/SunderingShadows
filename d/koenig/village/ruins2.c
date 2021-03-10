//ruins2.c - Coded by Circe 11/27/03
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
      "The original purpose of this building are no longer clear.  However, a "+
      "tall counter and a burned and battered %^RED%^stage %^RESET%^suggest that "+
      "it may have been an inn at one time.  It lies now in utter %^RED%^ruin"+
      "%^RESET%^, with the walls barely standing.  The "+
      "%^BLUE%^floor %^RESET%^is covered in the rubble of burned %^ORANGE%^wood "+
      "%^RESET%^and %^BOLD%^%^BLACK%^ash%^RESET%^.  Little else remains here."+
      "\n"
    );
    set_items(([
      ({"rubble","wood","floor"}) : "The floor was once wooden, but has now been "+
         "covered with the rotting wood of the shelves and a thick layer of ash "+
         "and soot.  It would take a lot of work to dig through it, but it might "+
         "be hiding something.",
      ({"walls","wall"}) : "The remaining walls are falling apart, "+
         "and the outdoors is clearly visible through them.",
      ({"soot","ash"}) : "The thick layer of black ash covers everything.",
      ({"counter","tall counter"}) : "The tall counter was made of wood and set "+
         "with a marble top.  Now the once-%^BOLD%^white%^RESET%^ top is "+
         "dingy and gray.",
      "stage" : "The low stage in the northeastern counter is rather small and "+
         "would have provided only enough room for a wandering minstrel and perhaps "+
         "his accompanist.  Now, it has rotted through and appears quite treacherous."
   ]));
   set_listen("default","The wind is the only sound you hear.");
   set_smell("default","The pungent scent of ash rises from the floor.");
   set_search("default","You think the rubble might be hiding something.");
   set_search("rubble",(:TO,"search_rubble":));
   set_exits(([
      "west" : VILROOMS"k_road09"
   ]));
}

void search_rubble(){
   if(!items){
      tell_object(TP,"The rubble is overturned as if someone has searched here already.");
      return;
   }
   switch(random(30)){
      case 0..10:  tell_object(TP,"You find nothing of interest in the rubble, but you "+
                     "stir up a huge cloud of dust.");
                  tell_room(ETP,""+TPQCN+" searches the rubble, stirring up dust.",TP);
                  break;
      case 11..12:  tell_object(TP,"You find something hidden in the rubble, but you "+
                     "stir up a huge cloud of dust.");
               tell_room(ETP,""+TPQCN+" searches the rubble, stirring up dust.",TP);
               new("/d/common/obj/instruments/lute")->move(TO);
               break;
      case 13..14:  tell_object(TP,"You find something hidden in the rubble, but you "+
                     "stir up a huge cloud of dust.");
               tell_room(ETP,""+TPQCN+" searches the rubble, stirring up dust.",TP);
               new("/d/common/obj/instruments/fiddle")->move(TO);
               break;
      case 15:  tell_object(TP,"You find something hidden in the rubble, but you "+
                     "stir up a huge cloud of dust.");
               tell_room(ETP,""+TPQCN+" searches the rubble, stirring up dust.",TP);
               new("/d/common/obj/instruments/lap-harp")->move(TO);
               break;
      case 16..17:  tell_object(TP,"You find something hidden in the rubble, but you "+
                     "stir up a huge cloud of dust.");
               tell_room(ETP,""+TPQCN+" searches the rubble, stirring up dust.",TP);
               new("/d/common/obj/instruments/harmonica")->move(TO);
               break;
      case 18:  tell_object(TP,"You find something hidden in the rubble, but you "+
                     "stir up a huge cloud of dust.");
               tell_room(ETP,""+TPQCN+" searches the rubble, stirring up dust.",TP);
               new("/d/common/obj/instruments/bagpipes")->move(TO);
               break;
      case 19:  tell_object(TP,"You find something hidden in the rubble, but you "+
                     "stir up a huge cloud of dust.");
               tell_room(ETP,""+TPQCN+" searches the rubble, stirring up dust.",TP);
               new("/d/common/obj/instruments/banjolele")->move(TO);
               break;
      case 20:  tell_object(TP,"You find something hidden in the rubble, but you "+
                     "stir up a huge cloud of dust.");
               tell_room(ETP,""+TPQCN+" searches the rubble, stirring up dust.",TP);
               new("/d/common/obj/instruments/bones")->move(TO);
               break;
      case 21:  tell_object(TP,"You find something hidden in the rubble, but you "+
                     "stir up a huge cloud of dust.");
               tell_room(ETP,""+TPQCN+" searches the rubble, stirring up dust.",TP);
               new("/d/common/obj/instruments/bongodrums")->move(TO);
               break;
      case 22:  tell_object(TP,"You find something hidden in the rubble, but you "+
                     "stir up a huge cloud of dust.");
               tell_room(ETP,""+TPQCN+" searches the rubble, stirring up dust.",TP);
               new("/d/common/obj/instruments/drum")->move(TO);
               break;
      case 23:  tell_object(TP,"You find something hidden in the rubble, but you "+
                     "stir up a huge cloud of dust.");
               tell_room(ETP,""+TPQCN+" searches the rubble, stirring up dust.",TP);
               new("/d/common/obj/instruments/flute")->move(TO);
               break;
      case 24:  tell_object(TP,"You find something hidden in the rubble, but you "+
                     "stir up a huge cloud of dust.");
               tell_room(ETP,""+TPQCN+" searches the rubble, stirring up dust.",TP);
               new("/d/common/obj/instruments/handbell")->move(TO);
               break;
      case 25:  tell_object(TP,"You find something hidden in the rubble, but you "+
                     "stir up a huge cloud of dust.");
               tell_room(ETP,""+TPQCN+" searches the rubble, stirring up dust.",TP);
               new("/d/common/obj/instruments/hautbois")->move(TO);
               break;
      case 26:  tell_object(TP,"You find something hidden in the rubble, but you "+
                     "stir up a huge cloud of dust.");
               tell_room(ETP,""+TPQCN+" searches the rubble, stirring up dust.",TP);
               new("/d/common/obj/instruments/lyre")->move(TO);
               break;
      case 27:  tell_object(TP,"You find something hidden in the rubble, but you "+
                     "stir up a huge cloud of dust.");
               tell_room(ETP,""+TPQCN+" searches the rubble, stirring up dust.",TP);
               new("/d/common/obj/instruments/mandolin")->move(TO);
               break;
      case 28:  tell_object(TP,"You find something hidden in the rubble, but you "+
                     "stir up a huge cloud of dust.");
               tell_room(ETP,""+TPQCN+" searches the rubble, stirring up dust.",TP);
               new("/d/common/obj/instruments/panpipes")->move(TO);
               break;
      case 29:  tell_object(TP,"You find something hidden in the rubble, but you "+
                     "stir up a huge cloud of dust.");
               tell_room(ETP,""+TPQCN+" searches the rubble, stirring up dust.",TP);
               new("/d/common/obj/instruments/tabor")->move(TO);
               break;
   }
   items = 0;
   return;
}