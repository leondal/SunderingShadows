#include <std.h>
#include "../defs.h"
inherit NPC;

void create() {
   ::create();
   set_name("Zilvanna");
   set_id(({"clerk","zilvanna","librarian"}));
   set_short("%^RESET%^%^BLUE%^Zilvanna Phaeraan, the librarian%^RESET%^");
   set_long("%^BLUE%^Zilvanna carries a fairly robust build, not commonly seen amongst drowkind.  She wears "
"her %^WHITE%^snowy hair %^BLUE%^folded back with a glittering brooch, and is garbed in a fine spidersilk robe "
"that fits snugly to her figure.  She is often seen moving about the library, perusing various scrolls and "
"tomes as she does.  A %^ORANGE%^brooch %^BLUE%^is pinned to the front of her clothes, marked with the "
"insignia of a noble house.%^RESET%^");
   set("aggressive", 0);
   set_level(15);
   set_gender("female");
   set_alignment(9);
   set_race("drow");
   add_money("gold", random(200));
   set_body_type("human");
   set_hd(20,10);
   set_max_hp(query_hp());
   set_max_sp(query_hp());
   set_exp(1);
   set_property("no bow",1);
}
