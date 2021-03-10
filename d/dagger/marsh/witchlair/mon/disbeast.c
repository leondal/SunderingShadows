#include <std.h>
#include "../witchlair.h"
inherit WEAPONLESS;

void create(){
   ::create();
   set_name("displacer beast");
   set_id(({"beast","displacer","displacer beast",
"cat","hellcat"}));
   set_short("%^BOLD%^%^BLACK%^displacer beast"
"%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^This creature mostly "
"resembles a panther...mostly. It shares the cat's "
"general shape and size, but similarity stops there. "
"Slick, matte black flesh covers it in the place of "
"fur, putting its impressive musculature on display."
" The tail splits into three writhing snakelike "
"appendages, each tipped with a roughly spade-shaped "
"head lined with wicked...teeth? A malign "
"%^GREEN%^light %^BLACK%^is shed from its angry green "
"eyes, leaving ghostly trails in the wake of its "
"movements. The creature appears to be only partially "
"substantial, at times fading in color, even flickering"
"out of existence entirely.");
   set_gender("neuter");
   set_race("quadruped");
   set_alignment(6);
   set_size(2);
   set_hd(14,6);
   set("aggressive",1);
   set_stats("strength",16);
   set_hp(90 + random(20));
   set_max_hp(query_hp());
   set_exp(10);
   set_attacks_num(3);
   set_attack_limbs(({"left forepaw","right forepaw"}));
   set_base_damage_type("slashing");
   set_damage(2,10);
}
