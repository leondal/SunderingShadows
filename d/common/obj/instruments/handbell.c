//handbell.c - For instrument file coded by Circe 11/28/03
#include <std.h>
inherit "/d/common/obj/instruments/instrument_inherit.c";

void create()
{
   ::create();
   set_name("handbell");
   set_short("A set of handbells");
   set_id(({"handbells","set of handbells","set","bells","instrument"}));
   set_long("This set consists of three bronze handbells, ranging in size from "+
      "3 inches in length to 9 inches.  Each bell is a hollow, beehive-shaped "+
      "instrument that has been ornately carved.  To play each bell, the performer "+
      "simply has to swing the bell, causing the clapper inside to create a ringing "+
      "note.  Skilled performers can use multiple handbells to create beautiful melodies.");
   set_weight(2);
   set_value(200);
   set_lore("Handbells are favored by humans and elves for their beautiful, ethereal melodies.  "+
      "Often choirs are formed full of people who play the handbells so that occasionally "+
      "elven cities ring with the music of countless bells playing intricate songs almost "+
      "impossible for other ears to distinguish and follow.");
}

