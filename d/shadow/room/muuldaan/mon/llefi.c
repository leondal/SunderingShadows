#include <std.h>
#include "../defs.h"
inherit MONSTER;

create() {
   ::create();
   set_name("llefi");
   set_id(({"llefi","assistant","kobold assistant"}));
   set_short("Llefi, kobold assistant");
   set_long("Llefi is a little, scrawny creature like the rest of his kin, with rather dark scaly hide that "
"is almost black.  He wears a ragged little coat that is so torn it could barely serve as a vest, and has a "
"long tail and two horns upon his head, one of which seems to have been broken at some point.  He scurries "
"around the room, taking food to customers and often taking a bit to eat from the meals himself.");
   set_gender("male");
   set_alignment(9);
   set_race("kobold");
   set_hd(25,1);
   set_max_hp(500);
   set_hp(500);
   set_body_type("human");
   set_class("thief");
   set_scrambling(1);
   set_spoken("undercommon");
}
