//pad1.c
#include <std.h>
#include "../../kildare.h"

inherit VAULT;
void create(){
   ::create();
   set_indoors(0);
   set_property("light",1);
   set_terrain(ROCKY);
   set_travel(FOOT_PATH);
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
paddock.  A gate to the east leads out onto the footpath through the 
village, while the paddock opens out further west and south.
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
      "the ewes have no horns but fuller coats.",
      "wooden gate" : "The sturdy wooden gate has been set within the stone "+
      "fence to allow access to the paddock.  It is made of light pine wood "+
      "slats and fitted with a simple wooden latch."
   ]));

   set_exits(([
      "east" : TROOMS"path14",
      "west" : TROOMS"pad2",
      "south" : TROOMS"pad3"
      ]));
   set_door("gate",TROOMS"path14","east",0);

}
