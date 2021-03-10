//lyre.c - For instrument file coded by Circe 11/28/03
#include <std.h>
inherit "/d/common/obj/instruments/instrument_inherit.c";

void create()
{
   ::create();
   set_name("lyre");
   set_short("A turtle-shell lyre");
   set_id(({"lyre","turtle-shell lyre","instrument"}));
   set_long("A predecessor to the lap-harp, this lyre is made from a turtle shell "+
      "fitted with two curved arms and a crossbar holding six gut strings taut.  All a "+
      "musician must do to play the lyre is hold it in one hand while strumming or "+
      "plucking the strings with the other.  Even a novice can strum a lyre to wonderful "+
      "effect.");
   set_weight(5);
   set_value(150);
   set_lore("Lyres are exceptionally popular among rural folk and among fey creatures "+
      "because of the ease of their construction.  Its ties to nature and the simplicity "+
      "of a lyre's music ensure its popularity among the less civilized cultures.  Satyrs "+
      "especially love lyres, second only to the pan pipes.");
}

