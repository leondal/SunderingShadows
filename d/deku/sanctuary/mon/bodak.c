#include <std.h>
#include "../dragon.h";

inherit WEAPONLESS;

void create() {
   ::create();
   set_name("bodak");
   set_id(({"bodak","sanctmob"}));
   set_short("Bodak");
   set_long(
      "This creature is dressed in nothing and has smooth, supple, black skin."+
      " Its head is shaped long and oval with a snout like mouth."+
      " Its cyan eyes glow dimly and to look into them is almost hypnotic."
   );
   set_race("undead");
   set_gender("neuter");
   set_hd(15,8);
   set_class("fighter");
   set_guild_level("fighter",15);
   set_alignment(9);
   set_max_hp(189);
   set_hp(189);
   set_overall_ac(-2);
   set_mob_magic_resistance("average");
   set_size(2);
   set("aggressive",30);
   set_exp(18000);
   set_attacks_num(2);
   add_limb("right fist", "right arm", 0, 0, 0);
   add_limb("left fist", "left arm", 0, 0, 0);
   set_attack_limbs(({"right fist","left fist"}));
   set_damage(1,12);
   set_stats("strength",20);
   set_stats("dexterity",15);
   set_funcs(({"gaze"}));
   set_func_chance(35);
   set_max_level(23);
}
void gaze(object targ){
    if(!"/daemon/saving_throw_d.c"->fort_save(targ,-15)){
        tell_object(targ,"%^BOLD%^%^BLUE%^The Bodak gazes into your eyes hypnotizing you!");
        tell_room(ETO,"%^BOLD%^%^BLUE%^The Bodak gazes into "+targ->query_cap_name()+"'s eyes!",targ);
        tell_room(ETO,""+targ->query_cap_name()+"'s body goes limp.",targ);
        targ->set_paralyzed(50,"%^RESET%^%^CYAN%^You stare off into space.");
        return 1;
    }
    tell_object(targ,"%^BOLD%^%^BLUE%^The Bodak gazes into your eyes but you resist its gaze!");
    tell_room(ETO,"%^BOLD%^%^BLUE%^The Bodak gazes into "+targ->query_cap_name()+"'s eyes but "+targ->query_subjective()+" resists its gaze!",targ);
    return 1;
}
