#include <std.h>

inherit WEAPONLESS;

void create() {
  :: create();
  set_name("monk");
  set_id(({"monk","grandmaster","katerin"}));
  set_short("Grandmaster Katerin");
  set_long("%^GREEN%^%^BOLD%^
This overpowering human, represents the true nature of perfect balance.
Dressed in flowing green robes, he represents the goodness in all of
nature. The soul of this monk knows no torture, his body movements are
like the wind blowing through the trees.");
  add_limb("right arm","body",0,0,0);
  add_limb("right foot","right leg",0,0,0);
  add_limb("left foot","left foot",0,0,0);
  add_limb("head","body",0,0,0);
  add_limb("left arm","body",0,0,0);
  add_limb("body","body",0,0,0);
  add_limb("right leg","body",0,0,0);
  add_limb("left leg","body",0,0,0);
  add_limb("left hand","left arm",0,0,0);
  add_limb("right hand","right arm",0,0,0);
  set_attack_limbs(({"right hand","left hand","right foot","left foot"}));
  set_attacks_num(4);
  set_damage(1,12);
  set_gender("male");
  set_level(14);
  set_alignment(1);
  set("aggressive","aggfunc");
  set_hd(14,7);
  set_size(2);
  set_overall_ac(-3);
  set_hp(150);
  set_property("no bump",1);
  set_mob_magic_resistance("average");
  set_max_hp(180);
  set_exp(5000);
  set_body_type("human");
  set_race("human");
  set_class("fighter");
  set_guild_level("fighter",14);
  set_stats("strength",18);
  set_stats("constitution",20);
  set_stats("dexterity",18);
  set_stats("wisdom",18);
  set_stats("intelligence",18);
  set_stats("charisma",16);
  set_funcs(({"attack"}));
  set_func_chance(60);
}

int attack(object targ) {
   int flag;
  flag = random(4);
  switch(flag) {
    case 0:
    tell_object(targ,"%^BOLD%^%^GREEN%^The grandmaster leaps into the air and kicks you in the stomach.");
    tell_room(environment(targ),"%^BOLD%^%^GREEN%^The grandmaster leaps into the air and kicks "+targ->query_cap_name()+" in the stomach.",targ);
    targ->do_damage("torso",roll_dice(3,8));
    break;
    
     case 1:
    tell_object(targ, "%^BOLD%^%^GREEN%^The grandmaster does a wonderful spin kick that connects with your jaw.");
    tell_room(environment(targ), "%^BOLD%^%^GREEN%^The grandmaster spin kicks "+targ->query_cap_name()+" in the jaw.",targ);
    targ->do_damage("head",roll_dice(2,8));
    break;
    
    case 2:
    tell_object(targ,"%^BOLD%^%^GREEN%^The grandmaster does a series of flashing punches.");
    tell_room(environment(targ),"%^BOLD%^%^GREEN%^The grandmaster hits "+targ->query_cap_name()+" with a series of flashing punches.",targ);
    targ->do_damage("torso",roll_dice(1,6));
    targ->do_damage("torso",roll_dice(1,6));
    targ->do_damage("torso",roll_dice(1,6));
    break;

     case 3:
    tell_object(targ,"%^BOLD%^GREEN%^The grandmaster tackles you onto the ground.");
    tell_room(environment(targ),"%^BOLD%^%^GREEN%^The grandmaster tackles "+targ->query_cap_name()+" onto the ground.",targ);
    targ->do_damage("torso",roll_dice(2,10));
    targ->set_paralyzed(100,"The grandmaster renders you into darkness!");
    break;
    }
  return 1;
}

void aggfunc() {
  int PAL = this_player()->query_alignment();
  if((PAL == 3) || (PAL == 6) || (PAL == 9)) {
    force_me("say You do not belong here evil one!");
    this_player()->kill_ob(this_object(), 0);
  } else {
  force_me("bow");
  force_me("say Your soul tells me that you are good.");
  }
}
