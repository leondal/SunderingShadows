#include <std.h>
#include "../yntala.h"
inherit WEAPONLESS;
void create (){

::create ();
   set_name("%^GREEN%^A green lizard%^RESET%^");
   set_id(({"large lizard","lizard"}));
   set_short("%^RESET%^%^GREEN%^A large green lizard%^BOLD%^%^RED%^");
set_long("%^RESET%^%^GREEN%^This is a large green lizard that doesn't look like it could do much harm. Its beady little eyes are constantly darting around and its movements are quick and skittish.%^RESET%^");
   set_race("lizard");
   set_gender("male");
   set_body_type("reptile");
   set_overall_ac(4);
   set_hd(4,2);
   set_size(1);
   set_stats("intelligence",2);
   set_stats("strength",3);
   set_stats("wisdom",12);
   set_stats("dexterity",13);
   set_stats("constitution",10);
   set_stats("charisma",2);
   set_class("fighter");
   set_hp(25);
   set_exp(20);
   set_alignment(5);
   set_damage(1,3);
   set_property("full attacks",1);
   set("aggressive",5);
   add_limb("claws","left foreleg",0,0,0);
   set_attack_limbs(({"claws"}));
   set_base_damage_type("slashing");
   set_emotes(1,({"%^GREEN%^The little lizard darts across the path.%^RESET%^",
"%^GREEN%^The lizard flicks its %^GREEN%^tongue.%^RESET%^",
"%^GREEN%^The lizard lazily moves onto a bush.%^RESET%^"}), 0);
}
