#include <std.h>
#include "../dragon.h";

inherit VAULT;

void create() {
   ::create();
   set_long(
      "%^RESET%^This room is obviously that of a mage's study."+
      " A bookshelf sits on one side of the room and a desk on"+
      " the other. Small tomes are piled on the desk and papers are"+
      " strewn about almost recklessly. Candles light this room,"+
      " covering it in a strong light."+
      " The floor is covered in a soft wall to wall red carpet."
   );
   set_items( ([
      "carpet" : "This is a soft plush carpet that feels good as you walk on it.",
      "bookshelf" : "A solid bookshelf full with books. None of them stick out to be interesting.",
      "desk" : "The desk is made well and is covered with papers. Drawers are along the side but are locked.",
      "papers" : "Various papers, though, none seem that important.",
      "candles" : "The candles are all worn down slightly, their wax melting and flowing down the length of the candles.",
      "target" : "There is a small target behind the door.",
   ]) );
   set_property("light", 2);
   set_property("indoors", 1);
   set_terrain(STONE_BUILDING);
   set_travel(SLICK_FLOOR);
   set_property("no teleport", 1);
   set_short("Tower of the Arcane Brotherhood");
   set_listen("default","It is very quiet here.");
   set_smell("default","The air is full of pleasant scents.");
}
