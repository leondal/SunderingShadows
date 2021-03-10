#include <std.h>
#include "../kildare.h"

inherit ROOM;
void create(){
   ::create();
   set_indoors(0);
   set_property("light",2);
   set_terrain(ROCKY);
   set_travel(RUTTED_TRACK);
   set_name("Abandoned Trail");
   set_short("Abandoned Trail");
   set_long(
@CIRCE
%^GREEN%^Abandoned Trail
%^RESET%^Running into the foothills of the Echoes and Charu Mountains, the 
faint tracks of wagons can be seen worn into the rocky ground.  It 
seems the trail was abandoned rather quickly, however, and now much of 
the ground has been covered with coarse grass and the few scrub bushes 
that manage to grow here.  It is not clear why the builders of the 
track tried to take it up into the mountainside, but it seems that 
their wagons could not go that way.  However, there looks to be 
some sort of footpath running up the side of the mountain.
CIRCE
   );
   set_items(([
      (({"mountain","mountains","mountainside"})) : "The deep gray rock of "+
         "two mountain ranges rise high to the west and north.  To the southeast, "+
         "the land seems to grow somewhat flatter, and there looks to be a "+
         "wider track that way.",
      (({"grass","bushes","scrub","scrub bushes"})) : "The coarse green grass "+
         "grows short in clumps along the mountainside.  It seems to become "+
         "thinner and more sporadic as the trail climbs into the mountains.  "+
         "The low, squat bushes are misshapen from the wind.",
      (({"footpath","path"})) : "Rising high into the mountains to the northeast, "+
         "a narrow footpath winds its way upward.  From here, you can see that "+
         "it twists and turns as it works its way along."
   ]));
   set_smell("default","You smell the clean air of the mountains.");
   set_listen("default","You can hear the wind blowing through the valley.");
 }
