//panpipes.c - For instrument file coded by Circe 11/28/03
#include <std.h>
inherit "/d/common/obj/instruments/instrument_inherit.c";

void create()
{
   ::create();
   set_name("pan pipes");
   set_short("A set of pan pipes");
   set_id(({"pan pipes","set of pan pipes","pipes","set","instrument"}));
   set_long("Made by stringing a series of reeds together, the pan pipes are a "+
      "rustic instrument.  The reeds are bound in a row going from largest to "+
      "smallest, and the musician plays them by blowing on the top ends of the "+
      "reeds.  The sound produced is much like that of a number of flutes being "+
      "played either at once or in succession.  By moving the pipes from side to "+
      "side, the musician can create a rippling effect.");
   set_weight(3);
   set_value(75);
   set_lore("Originally created by the satyrs, pan pipes are said to hold strange "+
      "powers in the hands of those creatures.  The soothing music makes the pan "+
      "pipes a favorite of all fey as well as pleasing to many humans and elves.  "+
      "Halflings enjoy pan pipes for a time, but are quickly bored by the gentle, "+
      "repetitve melodies.");
}

