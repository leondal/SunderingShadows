#include <std.h>
#include "../defs.h"
inherit NPC;

void create() {
   ::create();
   set_nwp("forage",8);
   set_name("fyvir");
   set_id(({"fyvir","forager","kobold forager"}));
   set_short("Fyvir, kobold forager");
   set_long("Fyvir is rather short, even for a kobold, and moves with "
      "quick slinking motions.  Two little horns sit atop his head, "
      "and he has the usual scaly, rust-brown hide of his kind.  "
      "He smells absolutely terrible and has a long rat-like tail.  "
      "He spends his time rummaging through the trash, looking for "
      "a few edible things for his companions to cook.");
   set_gender("male");
   set_alignment(9);
   set_race("kobold");
   set_hd(25,1);
   set_max_hp(500);
   set_hp(500);
   set_body_type("human");
   set_class("fighter");
   set_spoken("undercommon");
}
