
#include <std.h>
inherit WEAPONLESS;
void create(){
  ::create();
  set_name("silvery wolf");
  setenv("MIN", "$N stalks in with teeths bared.");
  setenv("MOUT", "$N stalks to the $D without a sound.");
  set_id(({"wolf","silver wolf","Wolf"}));
  set_short("%^BOLD%^%^WHITE%^Silver wolf%^RESET%^");;
  set_long("%^BOLD%^%^WHITE%^A large, silver coated wolf. It's teeths are bared with a ferocious grin. but surprcingly intelligent eyes");
  set_hd(35,5);
  set_max_hp(45);
  set_hp(45);
  set_race("wolf");
  set_body_type("quadruped");
  set_ac(0);
  set_exp(1);
  set_property("magic",1);
  set_mob_magic_resistance("average");
  set_attacks_num(2);
  set_damage(3,6);
//  set_attack_limbs(({"razored claws","slashing beak"}));
  set_attack_limbs(({"right claw","left claw","beak"}));
  set_base_damage_type("slashing");
  set_property("knock unconscious",1);
  set_funcs(({"shake"}));
  set_func_chance(5);
    set_emotes(2,({
  "The silver wolf scans the area observantly",
  "sniffs the grouns for tracks."
  "The silver wolf stays loyally close to his master"
  }),0);
  set_emotes(4,({
  "%^RED%^bears it teeths in a angry snarl!",
  "%^CYAN%^The silver wolf jumps loyaly in defence of his master master!",
  }),1);
  }


void shake(object targ)
{
   tell_object(targ,"%^GREEN%^ The wolf has caught you in it's jaws and shakes it's head voulenty to tear flesh!");
   tell_room(ETO,"%^YELLOW%^The silvery wolf catches "+targ->QCN+" with its jaws and shakes its head voulenty to tear flesh",targ);
   targ->do_damage(targ->return_target_limb(),(roll_dice(3,6)+10));
   return 1;
}