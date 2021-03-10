//drum.c - For instrument file coded by Circe 11/28/03
#include <std.h>
inherit "/d/common/obj/instruments/instrument_inherit.c";

void create()
{
   ::create();
   set_name("drum");
   set_short("A hollow drum");
   set_id(({"drum","hollow drum","instrument"}));
   set_long("A simple instrument, this drum was formed by stretching a tanned "+
      "skin across the opening of a wooden pot.  The drum may be struck with "+
      "padded mallets or with the musician's fingers, creating a booming sound.");
   set_weight(3);
   set_value(100);
   set_lore("Drums are loved by nearly every race for their ability to stir "+
      "emotions and create a variety of beats for everything from dancing to "+
      "to marching into battle.  Elves are one of the few races who find "+
      "the music of a drum distasteful and savage.  The less-refined races, "+
      "such as goblins and orcs, love the drum of course.");
}

