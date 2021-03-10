#include <std.h>
#include "../ninja.h";

inherit WEAPONLESS;

object ob;

void create() {
   ::create();
   set_name("elemental");
   set_id(({"elemental","giant earth elemental","earth elemental"}));
   set_short("%^RESET%^%^ORANGE%^Giant Earth Elemental%^RESET%^");
   set_long(
      "This is a very large stony humanoid. It stands easily over 40ft tall."+
      " Constructed of obsidian, granite, and sandstone it appears quite sturdy."+
     " Two multifaceted gems serve as eyes on a lifeless"+
      " expressionless face."
   );
   set_class("fighter");
   set_mlevel("fighter", 70);
   set_guild_level("fighter",70);
   set_max_hp(23450);
   set_hp(23450);
   set_exp(300000);
   set_overall_ac(-30);
   set_body_type("humanoid");
   set_gender("neuter");
   set_race("earth elemental");
   set_alignment(5);
   set_property("weapon resistance", 4);
   set_attack_limbs(({"right fist","left fist"}));
   set_damage(3,10);
   set_base_damage_type("bludgeoning");
   set_attacks_num(6);
   set_property("no death", 1);
   set_stats("strength", 25);
   set_stats("constitution", 25);
   set_stats("dexterity", 10);
   set_stats("intelligence", 6);
   set_stats("wisdom", 11);
   set_stats("charisma", 11);
}
