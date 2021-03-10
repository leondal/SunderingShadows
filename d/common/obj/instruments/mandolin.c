//mandolin.c - For instrument file coded by Circe 11/28/03
#include <std.h>
inherit "/d/common/obj/instruments/instrument_inherit.c";

void create()
{
   ::create();
   set_name("mandolin");
   set_short("A small mandolin");
   set_id(({"mandolin","small mandolin","instrument"}));
   set_long("A smaller version of the lute, the mandolin is less than 2 feet long "+
      "and has a very round body.  It is fitted with twelve strings which are placed "+
      "very close together.  It lacks the lute's distinctive bent neck, and it produces "+
      "a much sweeter, higher-pitched sound.  A mandolin is usually played with a pick - "+
      "both to protect the musician's fingers and to allow accurate plucking of the strings.");
   set_weight(5);
   set_value(250);
   set_lore("The wonderful range of tone possible when playing a mandolin has made it a "+
      "favorite of the smaller folk, especially halflings and gnomes.  Both races champion "+
      "the mandolin as being even better than the lute.");
}

