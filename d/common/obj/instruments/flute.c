//flute.c - For instrument file coded by Circe 11/28/03
#include <std.h>
inherit "/d/common/obj/instruments/instrument_inherit.c";

void create()
{
   ::create();
   set_name("flute");
   set_short("A wooden flute");
   set_id(({"flute","wooden flute","instrument"}));
   set_long("This small wooden instrument is a thin, hollow wooden tube drilled "+
      "with six fingerholes.  It is made to be held at a right angle to the lips, "+
      "and air is blown across a small opening.  The fingerholes can be covered or "+
      "uncovered to produce a variety of different notes, all of which have a light, "+
      "airy quality.  This flute is about a foot and a half long and is made of a light "+
      "blonde wood.");
   set_weight(2);
   set_value(200);
   set_lore("Flutes are often used as a backdrop to stories.  They can produce a gentle, "+
      "idyllic melody unattainable by other instruments, and as such, they are often used "+
      "to accompany love stories or pastoral poems.");
}

