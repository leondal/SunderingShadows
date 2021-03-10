#include <std.h>
inherit WEAPONLESS;

void create() {
   ::create();
   set_name("rat");
   set_id(({"rat","large rat"}));
   set_short("%^BOLD%^%^BLACK%^a large rat%^RESET%^");
   set_long("%^ORANGE%^A %^BOLD%^%^BLACK%^dirty grey rat %^RESET%^%^ORANGE%^stares up at you with his beady "
"little eyes.  His fat little body is covered with filthy, greasy hair.  A %^BOLD%^%^MAGENTA%^long pink "
"tail%^RESET%^%^ORANGE%^ twitches anxiously as he bares his teeth at you.%^RESET%^");
   set_race("rat");
   set_body_type("quadruped");
   set_gender("male");
   set_size(1);
   set("aggressive",25);
   set_property("swarm",1);
   set_level(2);
   set_class("fighter");
   set_mlevel("fighter",2);
   set_max_hp(20);
   set_hp(20);
   set_exp(25);
   set_max_level(2);
   set_damage(1,4);
   set_attacks_num(1);
   set_base_damage_type("piercing");
   set_attack_limbs(({"right forepaw","left forepaw","mouth"}));
   set_ac(8);
   set_alignment(5);
   add_money("gold",random(11)+1);
   add_money("silver",random(10));
   add_money("copper",random(50)+10);
}
