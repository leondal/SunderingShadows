//pathway19.c - Path through Lothwaite.  Circe 2/26/04
#include <std.h>
#include "../lothwaite.h"
inherit PATHEND;

void create(){
   ::create();
   set_long( ::query_long()+"  To the southwest, a stone building "+
      "stands upon a rocky outcropping overlooking the river.  A "+
      "wooden sign hangs just above the door.  "+
      "A narrow pathway also leads south into a large "+
      "practice field.\n");
   add_item("building","This stone building has three stone chimneys, "+
      "all of which constantly pour smoke.  Just behind the building, "+
      "you can see the practice field for the warriors of the village, "+
      "and a narrow path seems to lead to it.");
   add_item("outcropping","The rocky outcropping seems to be a spur of "+
      "the mountain rising just above the rest of the valley.  A "+
      "portion of the river runs underneath it.");
   add_item("river","The river looks very deep and frigid this high up "+
      "in the mountains.");
   add_item("field","This field looks to be a practice field for the "+
      "warriors of Lothwaite.  The grass is trampled and there are "+
      "several muddy patches from the constant mist of the nearby "+
      "river.  At all times of the day, firbolgs can be see training "+
      "with all manner of weapons.");
   add_item("sign",(:TO,"signdesc":));
   set_exits(([
      "southwest" : PATHEXIT"smithy",
      "northeast" : PATHEXIT"pathway20",
      "south" : PATHEXIT"training1"
   ]));
   set_door("door",PATHEXIT"smithy","southwest",0);
   set_door_description("door","A sturdy wooden door made of hewn pine planks "+
      "lashed together with thick rope and packed with mud to keep out the wind.");
}

string signdesc(){
   return(
@CIRCE
%^RED%^~~~~~~~~~~~~~~~~~~~~~

 %^BOLD%^The Warrior's Crown

%^RESET%^%^RED%^~~~~~~~~~~~~~~~~~~~~~%^RESET%^
CIRCE
   );
}