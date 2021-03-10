#include <std.h>
#include "../witchlair.h"
inherit "/d/common/obj/jewelry/necklace.c";

void create() {
  ::create();
  set_name("Artisan's Token");
  set_id(({ "necklace","pendant","artisans token",
"artisan necklace","token" }));
  set_obvious_short("%^RESET%^%^MAGENTA%^a necklace of "
"%^BOLD%^%^WHITE%^m%^CYAN%^i%^RESET%^%^WHITE%^t%^BOLD%^h"
"r%^RESET%^i%^BOLD%^l %^RESET%^%^MAGENTA%^and "
"%^BOLD%^%^BLACK%^lod%^WHITE%^e%^BLACK%^st%^WHITE%^o%^BLACK%^ne%^RESET%^");
  set_short("%^RESET%^%^MAGENTA%^A%^BOLD%^%^CYAN%^r"
"%^RESET%^%^MAGENTA%^ti%^CYAN%^s%^BOLD%^%^CYAN%^a"
"%^RESET%^%^MAGENTA%^n's T%^BOLD%^%^BLACK%^o%^CYAN%^k"
"%^RESET%^%^MAGENTA%^en%^RESET%^");
  set_long("%^BOLD%^%^WHITE%^Formed of small, delicate "
"links of mi%^RESET%^t%^BOLD%^%^CYAN%^h%^WHITE%^ril, "
"this chain necklace is the work of a master jeweller. "
"Fine etchings, barely visible to the naked eye, mark "
"each of the tiny links with geometrical designs, a feat"
" that testified the crafter's skill. The ends of the "
"chain meet at a fist-sized piece of %^BLACK%^lo"
"%^RESET%^%^WHITE%^d%^BOLD%^%^BLACK%^est%^RESET%^%^WHITE%^o"
"%^BOLD%^%^BLACK%^ne %^WHITE%^shaped as a "
"%^RESET%^%^ORANGE%^rabbit%^BOLD%^%^WHITE%^. Its features "
"are exaggerated and somewhat like a cave painting, giving"
" the creature a more streamlined look. Twin pieces of "
"cabochan-cut %^BLUE%^b%^WHITE%^l%^BLUE%^ue a"
"%^RESET%^%^BLUE%^me%^BOLD%^%^BLUE%^th%^RESET%^%^BLUE%^y"
"%^BOLD%^%^WHITE%^s%^BLUE%^t %^WHITE%^are set into place as "
"the eyes, and seem to %^CYAN%^sh%^WHITE%^i%^CYAN%^ne "
"%^WHITE%^with an inner magic.%^RESET%^");
  set_lore("%^BOLD%^%^WHITE%^Mattias Dunborough was a "
"halfling artificer of great skill, known most commonly for "
"his method of magically imbuing arms and armor while in the "
"forging process. Ever protective of his methods, the "
"proud artisan would share his secrets with none, not "
"even when offered staggering sums of gold. The truth is, "
"the feats he accomplished in his youth pleased his god, "
"the Rider of the Winds, who blessed His follower upon "
"retirement from adventuring with this gift to spread wealth "
"and art across the lands.\n");
  set_weight(2);
  set_value(4200);
  set_type("clothing");
  set_limbs(({"neck"}));
  set_wear((:TO,"wearit":));
  set_property("enchantment",3);
  set_ac(0);
  set_item_bonus("craft, armorsmith",1);
  set_item_bonus("craft, weaponsmith",1);
  set_item_bonus("craft, jeweller",2);
}

int wearit(){
  if((int)ETO->query_level() < 15) {
    tell_object(ETO,"%^RESET%^%^CYAN%^You don't suspect "
"you've got enough experience in the world to utilize "
"this item's magic.%^RESET%^");
    return 0;
  }
    tell_object(ETO,"%^RESET%^%^MAGENTA%^As you place "
"the light chain over your neck, you swear you can hear "
"someone, somewhere, humming a pleasant tune.%^RESET%^");
    tell_room(environment(ETO),"%^RESET%^%^MAGENTA%^You "
"see "+ETOQCN+" smile a bit, looking amused.%^RESET%^",ETO);
    return 1;
}
