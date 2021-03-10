#include <std.h>
#include "../dragon.h";

inherit WEAPONLESS;

void create() {
   ::create();
   set_name("construct");
   set_id(({"construct","sanctmob"}));
   set_short("Steel construct");
   set_long(
      "This construction is made of various shades of steel that range from"+
      " rusted to brand new. It is over seven feet tall with a large helm"+
      " attatched for the head."
   );
   set_race("construct");
   set_gender("neuter");
   set_hd(17,9);
   set_class("fighter");
   set_guild_level("fighter",15);
   set_alignment(9);
   set_max_hp(216);
   set_hp(216);
   set_overall_ac(-5);
   set_mob_magic_resistance("average");
   set_size(3);
   set("aggressive",30);
   set_exp(17000);
   set_attacks_num(2);
   add_limb("right fist", "right arm", 0, 0, 0);
   add_limb("left fist", "left arm", 0, 0, 0);
   set_attack_limbs(({"right fist","left fist"}));
   set_damage(1,15);
   set_stats("strength",22);
   set_stats("dexterity",15);
   set_max_level(23);
}
