//path14.c
#include "../../kildare.h"

inherit PATHEND;

void create()
{
   ::create();
   set_long(
@CIRCE
%^BOLD%^%^WHITE%^A Rocky Path
%^RESET%^%^CYAN%^Despite the hard stone of the mountain, this well-worn footpath 
runs through this tiny valley.  The path ends here before a small paddock 
to the west and a stone hut to the south.  Sheep can be seen grazing on 
the more plentiful patches of coarse grass of the paddock.  A low stone 
fence surrounds the paddock, keeping the sheep in.  A wooden gate has 
been inserted into the fence opening, allowing villagers to tend the 
sheep.
CIRCE
    );
   
   set_items(([
      (({"stone","mountain"})) : "The dark gray stone of the mountain "+
      "gives way to clumps of coarse grass in places.",
      (({"path","footpath","foot path"})) : "The worn footpath has "+
      "obviously been made only through the travel of the villagers "+
      "over time.  It ends here, in front of a paddock to the west and "+
      "a stone hut to the south.",
      (({"paddock","fence","stone fence"})) : "A low stone fence has been "+
      "placed around the section of the valley that seems to grow the most "+
      "grass.  The paddock rises up the mountainside, and many sheep seem "+
      "to be grazing within.",
      (({"gate","wooden gate"})) : "The sturdy wooden gate has been set "+
      "within the stone fence to allow access to the paddock.  It is made of "+
      "light pine wood slats and fitted with a simple wooden latch.",
      (({"hut","stone hut","simple hut"})) : "The low stone hut to the south "+
      "has been made squat to withstand the gusting winds at this altitude.  "+
      "Its proximity to the paddock suggests that it must be the shepherds' "+
      "quarters."
      ]));

   set_exits(([
      "west" : TROOMS"pad1",
      "south" : TROOMS"shephut",
      "northeast" : TROOMS"path13"
      ]));
   set_door("gate",TROOMS"pad1","west",0);
   set_door("wooden door",TROOMS"shephut","south",0);
}
