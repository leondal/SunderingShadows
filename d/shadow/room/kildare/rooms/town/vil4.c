//vil4.c
#include <std.h>
#include "../../kildare.h"

inherit TBUILD;

void create()
{
   ::create();
   set_property("no sticks",1);
   set_long(
@CIRCE
%^BOLD%^%^RED%^The Butcher's Shop
%^RESET%^%^RED%^This stone building, like the others of the town, consists mainly 
of one square room.  The ceiling for this one, however, is 
much higher though not quite two stories.  Near the northern end 
of the room is a long, low counter.  A rack stands atop it, 
supporting cleavers and knives of all sizes.  Various hooks 
and pegs line the walls behind the counter, though they all 
are empty right now.  A roaring fireplace is set in the eastern 
wall, providing illumination and warmth to the room.  Despite 
the grisly business, this room seems spotless.  A mop, bucket, 
and broom rest in one corner, along with a few rags.  A wooden 
loft has been built, and it seems the owner of the building has 
chosen to place his personal belongings there rather than on 
the floor with the counter.
CIRCE
   );
   set_items(([
      (({"stone","wall","floor"})) : "This building is made of the "+
         "dark gray stone of the mountain.  The floor and walls are "+
         "spotless, providing a sanitary place for the butcher to work.",
      "counter" : "The counter has been made from a light, almost white "+
         "quartz.  It seems to be hewn from one single piece and it provides "+
         "a good, solid place for the butcher to work.",
      (({"rack","cleavers","knives"})) : "The simple wooden rack is made of "+
         "a block of wood with slits carved into it.  Many knives with wooden "+
         "handles are thrust into the block, as well as several large metal "+
         "cleavers.  With those implements, the butcher could probably "+
         "work with most any size animal.",
      (({"hooks","pegs"})) : "Seemingly, the hooks and pegs driven into the "+
         "wall normally hold meat that the butcher is working on.  However, "+
         "they hang empty now.  Very faint red streaks can be seen below them, "+
         "although someone obviously keeps this place as spotless as possible.",
      (({"fire","fireplace","fire place"})) : "The fire burns high in the "+
         "fireplace, giving great warmth to the room.  A spit is suspended over "+
         "the flames, large enough for only small game.",
      (({"mop","bucket","rags","broom"})) : "Standing in a corner neatly are a "+
         "mop, broom, and a bucket filled with rags.  All have obviously seen "+
         "much use, judging by the worn condition.",
      (({"loft","wooden loft","belongings"})) : "The wooden loft overhead has a "+
         "ladder leading up to it.  Just over the corner, you can see a small bed, "+
         "and table, along with a padded chair."
      ]));

   set_exits(([
      "south" : TROOMS"path9"
      ]));
   set_door("pine door",TROOMS"path9","south",0);

}
void reset()
{
        ::reset();
        if(!present("david")) {
                new(MON"david")->move(TO);
        }
}
