#include <std.h>
#include "../dragon.h";

inherit WEAPONLESS;

void create() {
   ::create();
   set_name("quaggoth");
   set_id(({"quaggoth","beast","leader"}));
   set_race("quaggoth");
   set_gender("male");
   set_short("Quaggoth tribe leader");
   set_long(
      "This Quaggoth is much larger and far more muscular than any other Quaggoth"+
      " that you have encountered in the entire sewer system. It stands tall and"+
      " proud, ruling over the others with supreme confidence. Its prowess and battle"+
      " may very well be the reason for that."
   );
   set_overall_ac(-7);
   set_hd(25,8);
   set_level(25);
   set_class("ranger");
   set_guild_level("ranger",25);
   set_alignment(6);
   set_max_hp(267);
   set_hp(267);
   set("aggressive",30);
   set_exp(22000);
   add_limb("right claw", "right arm", 0, 0, 0);
   add_limb("left claw", "left arm", 0, 0, 0);
   set_attack_limbs(({"right claw","left claw"}));
   set_base_damage_type("slashing");
   set_attacks_num(5);
   set_damage(1,8);
   set_stats("strength",19);
   set_stats("dexterity",16);
   set_stats("wisdom",11);
   set_stats("intelligence",9);
   set_mob_magic_resistance("average");
   set_funcs(({"berserk"}));
   set_func_chance(25);
   new(OBJ+"chain_shirt")->move(TO);
   force_me("wear chain");
   new(OBJ+"bluedragonbuckler")->move(TO);
   force_me("wear buckler");
   set_max_level(23);
}


int berserk(object targ){
   tell_room(ETO, "%^BOLD%^%^RED%^The beast tears into "+targ->query_cap_name()+" biting and clawing like mad!!", targ);
   tell_object(targ, "%^BOLD%^%^RED%^The beast tears into you biting and clawing like mad!!");
   targ->do_damage("torso",roll_dice(10,6)+10);
   return 1;
}

void init() {
   ::init();
   if(TP->query_invis() && !avatarp(TP)) {
      tell_object(TP,"The beast sniffs you out and attacks.");
      TO->force_me("kill "+TP->query_name()+"");
   }
}
