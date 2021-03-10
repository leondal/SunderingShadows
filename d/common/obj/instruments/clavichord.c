//clavichord.c - For instrument file coded by Circe 11/28/03
#include <std.h>
inherit "/d/common/obj/instruments/instrument_inherit.c";

void create()
{
   ::create();
   set_name("clavichord");
   set_short("A rectangular clavichord");
   set_id(({"clavichord","rectangular clavichord","instrument"}));
   set_long("This rectangular instrument is far too bulky to be carried around "+
      "and used by bards in the field.  It is about one foot wide and three "+
      "feet long.  It seems to be much like a cross between a pipe organ and a "+
      "piano, but on a much smaller scale.  It must be placed on a flat surface "+
      "to be played.  It has a keyboard attached to small metal pieces which strike "+
      "strings inside the box, sounding the note.  The music of the clavichord is never "+
      "particularly loud, but it is often soothing.");
   set_weight(15);
   set_value(600);
   set_lore("The clavichord is an instrument favored by wealthy merchants and other "+
      "people of similar standing.  They often have such instruments made of extravagant "+
      "materials in their homes and will hire musicians to play when they are entertaining "+
      "guests.  The music of the clavichord is said to lend itself well to enchanment "+
      "spells because of its soothing nature.");
}

