//candle.c - Candle maker for Lothwaite.  Circe 6/15/04
#include <std.h>
#include "../lothwaite.h"
inherit VAULT;

void create(){
   ::create();
   set_indoors(1); 
   set_property("light",2);
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
   set_name("Tallow Chandler");
   set_short("Tallow Chandler");
   set_long("%^ORANGE%^This quaint shop is nestled in the valley "+
      "that houses the firbolg village of Lothwaite.  Strangely, "+
      "though the ceiling is still high enough for a firbolg to "+
      "stand comfortably, everything else seems sized for a human.  "+
      "A large, square table is in the center of the room, with "+
      "multiple %^RESET%^lines %^ORANGE%^strung above it.  From "+
      "these, many %^MAGENTA%^candles %^ORANGE%^hang drying, still "+
      "connected by the %^RESET%^wicks%^ORANGE%^.  Arranged atop "+
      "the table are various buckets and vats with the waxy residue "+
      "left from candle-making.  A large %^RED%^fireplace %^ORANGE%^"+
      "is set into the eastern wall with a %^RESET%^stone chimney "+
      "%^ORANGE%^rising above it, and an %^BOLD%^%^BLACK%^iron "+
      "cauldron %^RESET%^%^ORANGE%^suspended above it for melting "+
      "%^CYAN%^wax%^ORANGE%^.  A wooden counter "+
      "in the back of the room holds many other %^MAGENTA%^candles"+
      "%^ORANGE%^, these in fanciful designs.  It also supports a "+
      "small wooden tray bearing many sticks of %^BOLD%^%^BLUE%^"+
      "sealing wax %^RESET%^%^ORANGE%^in a variety of colors.  A "+
      "door behind the counter leads to another room, most likely "+
      "the shopkeeper's quarters.%^RESET%^\n");
   set_items(([
      ({"counter","wooden counter"}) : "The counter in the back of "+
         "the shop is only about four feet tall, much too short for "+
         "a firbolg.  Various wares are displayed upon it, from "+
         "sealing wax to decorative candles.",
      ({"table","square table","wooden table"}) : "%^ORANGE%^The "+
         "large wooden table in the center of the room is a perfect "+
         "square and takes up much of the floor space.  There is just "+
         "enough room around it for a firbolg to move relatively "+
         "comfortably, while it would probably give a human ample "+
         "space to work.  Metal buckets and vats cover its surface, and "+
         "it is stained a variety of colors from past wax spills.",
      ({"buckets","vats","metal buckets","waxy residue","residue"}) : "The "+
         "table's surface is covered with buckets in varying sizes.  These "+
         "are filled with wax, and the tallow chandler uses them "+
         "to dip the wicks, building the candle slowly.  Generally, "+
         "colorless candles are made, but it seems that this chandler "+
         "enjoys creating works of art as well.  The buckets and "+
         "vats seem to have been stained with waxy residue.",
      ({"candles","drying candles","lines","drying lines"}) : "%^CYAN%^"+
         "Hanging above the table on thin lines made of twine are "+
         "many candles of various colors.  Most are still attached "+
         "to one another by a single wick, which will be cut before "+
         "the candles are sold.  There seem to be mostly tall tapers "+
         "and pillars of various sizes.",
      ({"fire","fireplace","chimney","cauldron","iron cauldron"}) : "The "+
         "fireplace and chimney are made of light gray stone that does "+
         "not seem to match the stone from the valley.  The %^BOLD%^"+
         "%^BLACK%^iron cauldron %^RESET%^is rather large and seems "+
         "meant for melting wax in bulk, with the color then added "+
         "in the vats on the table.  A warming %^BOLD%^%^RED%^f"+
         "%^YELLOW%^ir%^RED%^e %^RESET%^seems to always burn in the "+
         "fireplace.",
      ({"sealing wax","designer candles","fanciful candles"}) : "The "+
         "counter in the back holds many different candles, all of them "+
         "unique in one way or another.  Some are in shapes, such as "+
         "animals, while others are simply carved with twists and "+
         "layered with different colors.  The wooden tray has sealing "+
         "wax in different colors lined neatly on top of it.",
      ({"door","back door"}) : "The door in the back of the shop "+
         "is smaller than the front door, seemingly sized for a human.  "+
         "It looks like it probably leads back to the chandler's "+
         "personal quarters."
   ]));
   set_smell("default","The strong scent of wax seems to mask all other smells.");
   set_listen("default","The crackling of the fire seems soothing.");
   set_exits(([
      "east" : PATHEXIT"grass1"
   ]));
   set_door("door",PATHEXIT"grass1","east",0);
   set_door_description("door","A sturdy wooden door made of hewn pine planks "+
      "lashed together with thick rope and packed with mud to keep out the wind.");
}

void reset(){
   ::reset();
   if(!present("galen")){
      new(MON"galen")->move(TO);
   }
}