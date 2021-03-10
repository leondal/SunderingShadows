#include <std.h>
#include "../defs.h"
inherit NPC;

void create() {
   ::create();
   set_nwp("healing",15);
   set_name("shrityrr");
   set_id(({"shrityrr","priestess","healer"}));
   set_short("%^RESET%^%^MAGENTA%^Shrityrr Ainenthraith, a slender drow priestess%^RESET%^");
   set_long("%^MAGENTA%^The drow female before you is clad in the garments of a priestess, with a long "
"spidersilk gown of %^BOLD%^%^BLACK%^deep ebony %^RESET%^%^MAGENTA%^that matches almost perfectly with her "
"dark skin.  Her %^WHITE%^snowy hair%^MAGENTA%^ is restrained by several onyx combs, and a %^RED%^spider "
"brooch %^MAGENTA%^is pinned predominantly on the front of her clothing.  She spends most of her time here "
"manipulating and creating various potions with her nimble fingers.%^RESET%^");
   set_alignment(9);
   set_race("drow");
   set_class("cleric");
   set_body_type("human");
   set_hd(25,1);
   set_max_hp(800);
   set_hp(800);
   set_gender("female");
}
