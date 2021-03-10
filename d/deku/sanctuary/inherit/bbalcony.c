#include <std.h>
#include "../dragon.h";

inherit VAULT;

void create() {
   ::create();
   set_long(
      "%^RESET%^This is the balcony that overlooks the foyer"+
      " below. It is made out of stone and looks to be strongly"+
      " supported. The railing is made out of stone as well, which"+
      " has been polished to a sheen. From up here you can see the"+
      " extravagance of the tower, and how much the owners must have"+
      " spent in its crafting. A large set of stairs go up from here"+
      " into a room that has many reflections of light from it."
   );
   set_items( ([
      "railing" : "The railing is finely crafted and polished."
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
