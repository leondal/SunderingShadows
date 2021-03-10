//Mob for the phantasmal killer priest spell
#include <std.h>

inherit WEAPONLESS;

void create(){
   ::create();

   set_name("phantasmal killer");
   set_short("%^RESET%^%^CYAN%^A slender humanoid figure");
    set_id(({"figure","human","humanoid figure","phantasmal killer","killer","greater summon"}));
   set_long("Though seeming somewhat insubstantial, this creature "+
      "poses a very real threat to those it turns its empty gaze "+
      "upon.  It is strong and agile, bent upon protecting its "+
      "creator."
   );
   set_race("phantom");
   set_gender("neuter");
   set_body_type("humanoid");
   set_attack_limbs(({"right hand","left hand"}));
   set_damage(1,6);
   set_hd(1,8);
   set_attacks_num(1);
   set_stats("strength",10);
   set_stats("dexterity",20);
   set_class("fighter");
   set_mlevel("fighter",10);
   set_guild_level("fighter",10);
   add_search_path("/cmds/fighter");
   set_hp(205);
   set_attack_bonus(2);
   set_weight(10000);
   set_damage_bonus(2);
   set_size(2);
   set_overall_ac(0);
   set("magic",1);
  // call_out("check",1);
}

void die(object ob)
{
   tell_room(ETO,"%^RED%^The phantasmal killer shimmers and is dispelled.%^RESET%^");
   remove();
   return;
}
