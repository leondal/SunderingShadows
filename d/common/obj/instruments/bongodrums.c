//bongodrums.c - For instrument file coded by Circe 11/28/03
#include <std.h>
inherit "/d/common/obj/instruments/instrument_inherit.c";

void create()
{
   ::create();
   set_name("bongo drums");
   set_short("A set of bongo drums");
   set_id(({"drums","bongo drum","set","set of bongo drums","instrument"}));
   set_long("This set of drums is more highly developed than an ordinary drum.  "+
      "It consists of two drums bound together - one is about 5 inches in diameter "+
      "while the other is about 7 inches.  A strap is attached so that the musician "+
      "can play as he walks, or they may be placed on the ground.  Bongo drums are "+
      "played by the musician rapidly tapping the stretched drumheads with his fingers, "+
      "and the most skilled can play intricate rhythms by switching between the two drums.");
   set_weight(5);
   set_value(250);
   set_lore("Although bongo drums can be found in many different cultures, it is the "+
      "goblins who prize them most.  Goblins often use bongo drums to convey "+
      "complex messages, though to the outsider, all of them sound the same.");
}

