//lute.c - For instrument file coded by Circe 11/28/03
#include <std.h>
inherit "/d/common/obj/instruments/instrument_inherit.c";

void create()
{
   ::create();
   set_name("lute");
   set_short("A wooden lute");
   set_id(({"lute","wooden lute","instrument"}));
   set_long("This simple instrument has a pear-shaped body fitted with a distinctive "+
      "bent neck.  The neck has frets for fingering, and six strings stretch along the "+
      "neck, attaching to wooden pegs.  This lute is about 32 inches long, although most "+
      "of that length is taken up by the large, rounded bowl.  The instrument can be strummed "+
      "or plucked to create an enormous variety of notes and inflections.  It has a rich, "+
      "full sound.");
   set_weight(5);
   set_value(300);
   set_lore("The lute is the most popular of the three primary bardic instruments.  It is "+
      "an easy instrument to learn, but nearly impossible to master.  Grand master bards "+
      "who have been playing the lute for a lifetime still find new ways to utilize its "+
      "endless sounds.  The lute is a particular favorite among half-elven bards.");
}

