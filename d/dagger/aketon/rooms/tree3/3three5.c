#include "/d/dagger/aketon/short.h"

inherit ROOM;

void create() {
   ::create();
   set_property("light",2);
   set_short("A butterfly garden in Aketon");
   set_long("%^GREEN%^A butterfly garden in Aketon%^RESET%^\n"+
   "This is a rather interesting garden, for it is not the flowers"+
   " that are the main attraction, but the butterflies. The entire"+
   " center of the room is taken up by a large square of earth that"+
   " has been planted with various flowers that butterflies love. The"+
   " edges of the branches on the outlying areas are used as places"+
   " for the caterpillars to live and make their cocoons to turn into"+
   " butterflies, who then can survive off the beautiful flowers."+
   " There are numerous butterflies here of all colors and they look"+
   " so gentle and carefree as they flutter and float in the breeze.");
   set_smell("default","The smells of the are garden pleasant.");
   set_listen("default","The wind rustles gently through the leaves.");
   set_items(([
   "flowers" : "There are numerous types of flowers in the center of"+
   " the room. You notice the yellow and orange of butterfly weed, white"+
   " baby's breath, purple loosestrife and foxglove, variously colored"+
   " asters, phlox, and columbine, pink ironweed, and many other"+
   " perennials of various colors.",
   "butterflies" : "There are so many beautiful butterflies fluttering"+
   " about the flowers! There are many different colors and patterns"+
   " on their wings, and they come in all sorts of sizes. It is hard"+
   " to believe there are so many different types. You notice many"+
   " with blues and purples on their back framed by a darker black or"+
   " brown, some that are brighter orange and yellow, and a couple"+
   " smaller ones that are just a plain white, and many, many others.",
   "caterpillars" : "There are many caterpillars crawling along the"+
   " tree branches here. Some are small, some are long, some are thick,"+
   " some are furry, a few have spikes, and they are all different"+
   " colors and patterns.",
   ({"cocoons","branches"}) : "There are many cocoons that have been"+
   " secured in the outlying branches, waiting to hatch out a butterfly.",
   ]));
   set_exits( (["northeast":RPATH3+"3three1"]) );
}
