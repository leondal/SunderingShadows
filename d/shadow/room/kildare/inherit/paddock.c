//paddock.c
#include <std.h>
#include "../kildare.h"

inherit CROOM;
void pick_critters();

void create(){
      pick_critters();
      set_repop(60);
   ::create();
   set_indoors(0);
   set_property("light",1);
   set_terrain(ROCKY);
   set_travel(FOOT_PATH);
   set_name("A Fenced Paddock");
   set_short("A Fenced Paddock");
   set_long(
@CIRCE
%^BOLD%^%^GREEN%^A Fenced Paddock
%^RESET%^%^GREEN%^The grass growing in this rocky paddock is short 
and coarse, though the sheep grazing here seem content enough.  
The gray stone of the mountainside is broken here by great patches 
of grass, and a few small bushes lie along the fence.  The low stone 
fence has a strange green moss growing between the stones and seems 
to have stood undisturbed for countless years.  Sheep of all shades 
of gray, from nearly white to almost midnight black, dot the rolling 
paddock.  The paddock sprawls over rocky outcroppings in many directions.
CIRCE
   );

   set_smell("default","You smell the clean air of the mountains.");
   set_listen("default","The sound of bleating sheep mixes with the gusting wind.");
   set_items(([
      (({"paddock","rocky paddock","bushes","grass"})) : "The gray stone "+
      "mountainside is covered here in patches of short, coarse grass.  "+
      "Small bushes are spread around the fence, though many of them "+
      "seem to have become food for the sheep as well.",
      (({"fence","stone fence","moss"})) : "The stones for the fence seem to "+
      "have been quarried from the mountain itself.  The green moss "+
      "growing between the stones gives it an ancient appearance.",
      "sheep" : "The sheep all have thick, curly wool covering their bodies "+
      "in varying shades of gray.  The rams have long, curling horns while "+
      "the ewes have no horns but fuller coats."
   ]));

}

void reset() {
   int active;
   active = has_mobs();
   if(!active) {
     if(mons) mons = ([]);
     pick_critters();
   }
   ::reset();
}

void pick_critters(){
   switch(random(6)){
      case 0..1: break;
      case 2:  set_monsters( ({MON"citizen3"}),({1}) );
               break;
      case 3:  set_monsters( ({MON"sheep1"}),({1}) );
               break;
      case 4:  set_monsters( ({MON"sheep2"}),({1}) );
               break;
      case 5:  set_monsters( ({MON"sheep3"}),({1}) );
               break;
   }
}