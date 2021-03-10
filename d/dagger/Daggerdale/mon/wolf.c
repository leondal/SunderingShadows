#include <std.h>
inherit WEAPONLESS;

void create(){
   ::create();
   set_name("black wolf");
   setenv("MIN","$N prowls in.");
   setenv("MOUT","$N prowls $D.");
   set_id(({"wolf","black wolf","jet-black wolf"}));
   set_short("%^BOLD%^%^BLACK%^jet-black wolf%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^This haggard beast is anything but tame, with a feral "
"gleam in its %^RED%^glowing eyes%^BLACK%^. Its fur is matted and%^RESET%^%^WHITE%^ "
"pitch black%^BOLD%^%^BLACK%^, from its nose to the tip of its tail. It definitely looks "
"dangerous.");
   set_alignment(5);
   set_race("wolf");
   if(random(2)) set_gender("male");
   else set_gender("female");
   set_body_type("quadruped");
   set_hd(17,1);
   set_stats("strength",16);
   set_max_hp(125);
   set_hp(125);
   set_ac(0);
   set_exp(1);
   set_property("magic",1);
   set_attacks_num(1);
   set_damage(1,3);
   set_damage_bonus(3);
   set_size(1);
   set_weight(10000);
   set_property("knock unconscious",1);
}
