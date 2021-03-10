//fiddle.c - For instrument file coded by Circe 11/28/03
#include <std.h>
inherit "/d/common/obj/instruments/instrument_inherit.c";

void create()
{
   ::create();
   set_name("fiddle");
   set_short("A wooden fiddle");
   set_id(({"fiddle","wooden fiddle","instrument"}));
   set_long("This wooden instrument is small and portable with strings stretched "+
      "over an hourglass body.  The fiddle has five strings made of gut that are "+
      "anchored at the top of a long thin neck by pegs.  The fiddle is played by "+
      "drawing a bow - which is a long, thin piece of wood fitted with fine strands of "+
      "animal hair - across the strings.  The fiddle produces lively music often "+
      "used for dancing.");
   set_weight(4);
   set_value(350);
   set_lore("The rousing music of the fiddle is often prized by rural folk.  It is "+
      "especially loved by both halflings and kobolds, whose minstrels dance lively "+
      "jigs while playing to showcase their talents.  Only bards who prefer lively dance "+
      "music to the serene melodies produced by other instruments favor the fiddle.");
}


