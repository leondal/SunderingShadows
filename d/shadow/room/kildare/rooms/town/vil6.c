//vil6.c
#include <std.h>
#include "../../kildare.h"

inherit TBUILD;

void create()
{
   ::create();
   set_property("no sticks",1);
   set_long(
      "%^BOLD%^%^GREEN%^Mariel's Bobbins and Dyes\n"
      "%^BOLD%^%^BLUE%^The small stone room that houses this shop has been "+
      "gaily decorated in shades of blue, yellow, and green, and seems rather "+
      "cheerful compared to most of the buildings in Kildare Glen.  The young "+
      "tailor who runs the shop seems to have studied for quite some time to gain "+
      "as much skill as she has.  Finished garments hang from a wooden rack near the "+
      "front of the room, and a few are folded atop wooden shelves as well.  Behind "+
      "a long stone counter are a stool and a large round spinning wheel used for "+
      "making thread.  A bookcase behind the counter holds dyes, needles, and other "+
      "implements.  Spools of finished thread in all colors line a matching bookcase "+
      "beside the wheel, and it seems that the tailor must sell her wares to other "+
      "areas, as well as providing for the small village.  Just behind the bookcases "+
      "is a wooden wall with a door, which seems to have been added to the stone building "+
      "after it was built.  It seems likely that the tailor's home is there."
   );
   set_items(([
      (({"stone","wall","floor"})) : "This building is made of the "+
         "dark gray stone of the mountain.  The floor and walls are "+
         "decorated in hangings and rugs in shades of blue, yellow, and green.",
      "counter" : "The stone counter seems to have been quarried from the "+
         "stone of the mountain.  It has been covered with a long blue cloth "+
         "that helps to brighten the room.",
      (({"garments","racks","garment","shelves"})) : "Coats, sweaters, and "+
         "pants hand on the crossed rack near the front of the room, while "+
         "gloves, mittens, hats, shoes, and the like line the shelves.  All "+
         "are kept neatly put away and seem to be of very high quality.",
      "dyes" : "Jars of dye and small cakes of color are scattered across a "+
         "bookcase in the back of the room behind the counter.  Standing "+
         "near the spinning wheel, it seems they are used to dye the thread "+
         "the tailor spins so she can use all the wonderful colors seen in the shop.",
      (({"needles","implements"})) : "Behind the counter is a small bookcase "+
         "covered with needles of all sizes stuck within pincushions.  Jars of "+
         "pins stand alongside trays of scissors, measuring tapes, and folded "+
         "patterns that the shopkeeper needs to make her clothing.",
      (({"thread","spools","finished thread"})) : "The large wooden spools wound "+
         "with finished thread are carefully divided by color along the bookcase "+
         "in the back of the room.  The spools seem an endless rainbow of colors "+
         "and have varying thickness and quality as well."
      ]));

   set_exits(([
      "east" : TROOMS"path13"
      ]));
   set_door("wooden door",TROOMS"path13","east",0);

}
void reset()
{
        ::reset();
        if(!present("mariel")) {
                new(MON"mariel")->move(TO);
        }
}
