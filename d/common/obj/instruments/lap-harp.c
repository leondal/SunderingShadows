//lap-harp.c - For instrument file coded by Circe 11/28/03
#include <std.h>
inherit "/d/common/obj/instruments/instrument_inherit.c";

void create()
{
   ::create();
   set_name("lap-harp");
   set_short("A wooden lap-harp");
   set_id(({"lap-harp","wooden lap-harp","instrument"}));
   set_long("Intricately carved, this lap-harp is fitted with seventeen wires, "+
      "all made of silver.  The light wood of this lap-harp has been highly "+
      "polished so that the scrollwork carvings shine.  The harp is about two "+
      "and a half feet tall and a little over a foot wide.  It is played by "+
      "the musician strumming his fingers across the silver wires, which produces "+
      "a gentle, rippling melody.");
   set_weight(8);
   set_value(550);
   set_lore("Highly prized by elven bards for its light, soothing sound, the lap-harp "+
      "is one of the three primary bardic instruments - the other two being the lute "+
      "and the fiddle.  Elven lap-harps are often passed down for generations, and many "+
      "of them acquire reputations and legends all their own.");
}

