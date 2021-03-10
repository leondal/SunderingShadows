//shephut.c
#include <std.h>
#include "../../kildare.h"

inherit TBUILD;

void create()
{
   ::create();
   set_property("no sticks",1);
   set_long(
@CIRCE
%^YELLOW%^A Simple Stone Building
%^RESET%^%^ORANGE%^This stone building seems to have stood in this place 
for quite some time.  Some of the flagstones along the floor are 
cracked, but the whole place seems clean enough.  A few cobwebs 
and spots of dust reveal that the occupants are perhaps not the 
most careful people, but the building is definitely in use.  A few 
chairs surround a table near the center of the room, not far from 
a fireplace set into the southern wall.  A deck of cards, a chess 
set, and a few other games of leisure are piled on the table, while 
a shelf nearby holds a few tankards.  A keg of ale is resting on the 
floor, but there seems to be no food, beds, or other objects indicating 
a permanent residence here.  A long couch near the fireplace seems to 
have been slept in occasionally, judging from its rumpled appearance 
and the folded afghan at its foot.  A shepherd's crook stands in a 
corner near the door in the western wall.
CIRCE
   );
   set_items(([
      (({"stone","wall","floor"})) : "This building is made of the "+
         "dark gray stone of the mountain.  Dust has accumulated in "+
         "places, as well as a few cobwebs in the corners.",
      (({"chair","chairs"})) : "Several wooden chairs that have seen "+
         "much wear stand around the square table in the center of the "+
         "room.  They are not padded, and judging from the bow in their "+
         "legs, whoever usually sits in them likes to lean back a good bit.",
      (({"table","games","deck","cards","chess set","deck of cards"})) : "Cluttering "+
         "the top of the square wooden table are several games.  Mostly games "+
         "of skill, there seems to be no dice or other games of luck among them.  "+
         "The chess set is made of stone - white quartz battles against "+
         "deep gray granite pieces.  The deck of cards has seen much use, "+
         "judging from the worn corners and faded designs.",
      (({"shelf","tankard","tankards"})) : "A wooden shelf balanced on pegs "+
         "driven into the wall holds several large ale tankards.  They are "+
         "pounded metal mugs with ornate handles, but they - like the "+
         "rest of the building - have seen better days.",
      "couch" : "The couch near the fireplace might have been green at one time "+
         "but now is a muted brown with lighter patches.  The cushions are "+
         "threadbare, but someone apparently finds it comfortable enough.",
      (({"afghan","folded afghan","blanket"})) : "Folded at the foot of "+
         "the couch is a multi-colored afghan.  Shades of purple, yellow, and "+
         "green stand in stark contrast to the otherwise drab room.  Unlike "+
         "the other furnishings, this woven blanket seems new.",
      (({"crook","shepherd's crook"})) : "Standing near the doorway in the "+
         "western wall is a tall shepherd's crook.  It is made of dark cherry "+
         "wood and stands about seven feet tall, with the top ending in a deep "+
         "downward curve.",
      (({"fireplace","fire place"})) : "Set in the southern wall, the fire place "+
         "burns brightly and lights the room.  The smoke feeds into a stone chimney "+
         "running through the room.  A small pile of quartered wood sits nearby, ready "+
         "for use.",
      (({"keg","keg of ale","ale"})) : "A wooden barrel of ale stands near the table "+
         "within easy reach of anyone who sits there."
      ]));

   set_exits(([
      "north" : TROOMS"path14",
      "west" : TROOMS"pad3"
      ]));
   set_door("wooden door",TROOMS"path14","north",0);
   set_door("small door",TROOMS"pad3","west",0);

}
