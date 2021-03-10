#include <std.h>

inherit WEAPONLESS;

void create() {
   ::create();
   set_name("quaggoth");
   set_id(({"quaggoth","hunter","beast"}));
   set_race("quaggoth");
   set_gender(random(2)?"male":"female");
   set_short("Quaggoth hunter");
   set_long(
      "This is a seven foot tall beastlike creature. Its apperance brings the image"+
      " of a bear to mind. The Quaggoth has beastlike claws and thick black fur. Its"+
      " mouth is full of razor sharp teeth and it has a pair of narrow yellow eyes"+
      " fixed on you."
   );
   set_overall_ac(-4);
   set_hd(25,8);
   set_level(25);
   set_class("ranger");
   set_guild_level("ranger",25);
   set_alignment(6);
   set_max_hp(237);
   set_hp(237);
   set("aggressive",30);
   set_exp(19000);
   add_limb("right claw", "right arm", 0, 0, 0);
   add_limb("left claw", "left arm", 0, 0, 0);
   set_attack_limbs(({"right claw","left claw"}));
   set_base_damage_type("slashing");
   set_attacks_num(5);
   set_damage(1,8);
   set_stats("strength",16);
   set_stats("dexterity",16);
   set_stats("wisdom",11);
   set_stats("intelligence",9);
   set_funcs( ({"berserk"}) );
   set_func_chance(25);
   set_max_level(23);
}

int berserk(object targ){
   tell_room(ETO, "%^BOLD%^%^RED%^The beast tears at "+targ->query_cap_name()+", clawing and biting madly!", targ);
   tell_object(targ, "%^BOLD%^%^RED%^The beast tears at you, clawing and biting madly!");
   targ->do_damage("torso",roll_dice(10,4)+10);
   return 1;
}

void init() {
   ::init();
   if(TP->query_invis() && !avatarp(TP)) {
      tell_object(TP,"The beast sniffs you out and attacks.");
      TO->force_me("kill "+TP->query_name()+"");
   }
}
