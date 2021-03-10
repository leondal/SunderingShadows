//vil2.c
#include "../../kildare.h"

inherit TBUILD;

void create()
{
   ::create();
   set_long(
@CIRCE
%^BOLD%^%^BLACK%^An Old Stone Building
%^RESET%^%^WHITE%^This simple building is made of stone 
quarried from the mountain itself.  It is a deep gray color, 
and it seems that little has been done to make this a cozy 
home.  The occupant seems content to dwell in only a small 
portion of this large room, leaving the rest of the building 
to the countless layers of dust and cobwebs that have taken 
over.  A simple rocking chair has been pushed close to the 
fireplace, and a loom stands before it.  Hanging on the wall 
behind the chair are various lengths of woven cloth.  
CIRCE
   );

   set_items(([
      (({"stone","building","room"})) : "The dark gray stone "+
      "of the surrounding mountainside has been used to build "+
      "this simple square room.  A slight draft comes through the "+
      "battered doorframe and it does little to help stave off "+
      "the empty feeling of the room.",
      (({"dust","webs","cobwebs"})) : "The light gray cobwebs "+
      "of countless spiders have completely conquered the "+
      "southeastern part of this house.  The dust over the rest "+
      "of the room is inches thick in some places.",
      (({"chair","rocking chair"})) : "A well-worn wooden rocking "+
      "chair stands near the fireplace in the western wall.  Shallow "+
      "grooves have actually been carved into the stone floor below "+
      "the rocker, indicating that the occupant has spent many days "+
      "sitting there.",
      "fireplace" : "A roaring fire is steadily burning in the stone "+
      "fireplace set into the western wall.  It seems to be the only "+
      "source of warmth in this large room.",
      "loom" : "A wooden loom stands before the rocking chair, and on "+
      "it is stretched a work in progress.  The wool is soft to the "+
      "touch and is a light gray color.  The weaver is obviously "+
      "highly skilled, as the quality is fantastic.",
      (({"wall","lengths","cloth","woven cloth"})) : "Lengths of "+
      "the same excellent quality wool hang from wooden pegs in "+
      "the stone wall."
      ]));

   set_exits(([
      "north" : TROOMS"path8"
      ]));
   set_door("battered door",TROOMS"path8","north",0);
}
void reset()
{
        ::reset();
        if(!present("soren")) {
                new(MON"soren")->move(TO);
        }
}
