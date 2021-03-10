//vil3.c
#include "../../kildare.h"

inherit TBUILD;

void create()
{
   ::create();
   set_long(
@CIRCE
%^BOLD%^%^BLUE%^A Long, Low Stone Building
%^RESET%^From the front, this stone building looks like all 
the others in the town.  Inside, though, it has obviously 
been dug back into the mountainside, making it much longer 
than any of the other homes around.  A row of bunkbeds made 
from rough pine timbers line the northern wall.  Along the 
southern wall runs a long shelf piled with clothes, and 
cloaks are hung from pegs just beneath the shelf.  Two small 
fireplaces heat the room, set within the middle of the northern
and southern walls respectively.  Near the back of the house, 
the firelight causes shadows to flicker and dance, making it 
seem as though the room might be longer.
CIRCE
   );
   set_items(([
      (({"stone","building","room"})) : "The dark gray stone "+
      "of the surrounding mountainside has been used to build "+
      "this long building.  Near the back of the building, the "+
      "small stone blocks give way to the smooth walls carved "+
      "into the mountainside.",
      (({"fireplace","fire place","fireplaces"})) : "The two stone "+
      "fireplaces are set into the northern and southern walls and "+
      "warm the building nicely.",
      (({"bunkbeds","bunk beds","beds","bunk bed","bed"})) : "Six "+
      "sets of bunkbeds line the northern wall, each with a wool "+
      "blanket folded at its foot.  It seems whoever lives here "+
      "must keep things quite neat and orderly.",
      (({"shelf","long shelf"})) : "A long wooden shelf placed "+
      "about six feet high is set into the southern wall.  It "+
      "breaks midway to allow room for the fireplace before beginning "+
      "again.  It is piled with neatly folded clothes.",
      "clothes" : "The clothes folded on the shelf seem to be mostly "+
      "woolen and warm.  Several pairs of suede breeches are also "+
      "folded there, as well as a few pairs of warm gloves.",
      (({"pegs","peg","cloaks"})) : "Only a few of the pegs below "+
      "the shelves have cloaks hanging on them.  They seem to be "+
      "well-made woolen cloaks that look quite warm.  They are mostly "+
      "in shades of gray and seem like they would blend well with the "+
      "mountainside.",
      (({"shadow","shadows"})) : "%^BOLD%^%^BLACK%^Near the eastern end of the house, "+
      "where the stone blocks give way to carved rock, there seems to "+
      "be a small tunnel curving back southward and further into the "+
      "mountainside.  Perhaps you could take a closer look."
      ]));
   set_search("default","The shadows on the eastern end of the house "+
      "look as though they might be hiding something.");
   set_search("shadows","You search through the shadows and find a "+
      "<tunnel> leading further back!");
   set_exits(([
      "west" : TROOMS"path9",
      "tunnel" : TROOMS"vil8"
      ]));
   set_door("cypress door",TROOMS"path9","west",0);
   set_invis_exits( ({"tunnel"}) );
}

void reset()
{
        ::reset();
        if(!present("man")) {
                new(MON"man")->move(TO);
        }
        if(!present("boy")) {
                new(MON"boy")->move(TO);
        }
}
