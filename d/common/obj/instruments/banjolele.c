//banjolele.c - For instrument file coded by Circe 11/28/03
#include <std.h>
inherit "/d/common/obj/instruments/instrument_inherit.c";

void create()
{
   ::create();
   set_name("banjolele");
   set_short("A rustic banjolele");
   set_id(({"banjolele","rustic banjolele","instrument"}));
   set_long("This guitar-like instrument is about 18 inches in "+
      "length.  It has a vellum skin stretched across a round body, "+
      "much like a tambourine.  It's guitar-like neck stretches away "+
      "from the body and is fitted with wooden pegs that secure the five "+
      "metal strings stretched along it.  Some find this music uplifting, "+
      "while others think this horrid combination of a banjo and ukelele is "+
      "apalling.");
   set_weight(3);
   set_value(300);
   set_lore("This instrument is a favorite of halfling bards, who love "+
      "the jaunty tunes it provides as a backdrop to their stories of "+
      "mischief and mayhem.  It is otherwise not a favorite in the world "+
      "of music lovers.");
}

