
#include <std.h>

inherit WEAPONLESS;
create ()
{
::create ();
set_name("tomb wight");
set_id(({"wight","tomb wight"}));
  set_short("%^RED%^Tomb wight%^RESET%^");
  set_long(
  "  This horrible creature glares at you with red eyes that shine from his flat black body."
  "  Shadows swirl around him as if a cloak and he snarls inarticualatly as he starts to claw at you!."
  );
set_gender("male");
  set_race("undead");
  set_hd(25,0);
set_overall_ac(4);
set_size(2);
  set_body_type("human");
  set_property("magic",1);
set_stats("strength", 18);
set_stats("intelligence", 6);
set_stats("dexterity", 16);
set_stats("charisma", 1);
set_stats("wisdom", 4);
set_class("fighter");
set("aggressive", 25);
set_base_damage_type("slashing");
set_damage(5,8);
set_attack_limbs(({"right claw","left claw","fangs"}));
  set_mob_magic_resistance("average");
set_attacks_num(3);
add_limb("fangs","head",0,0,0);
set_max_hp(400);
set_hp(400);
set_alignment(8);
set_exp(3500);
set_emotes(20,({"%^YELLOW%^The tomb wight snarls and attacks!",
 "%^BOLD%^The tomb wight goes berserk!!"}),1);
set_funcs( ({"berserk"}) );
set_func_chance(40);
}


void berserk(object targ)
{
  if(!targ) return 0;
  tell_room(environment(targ),"%^RED%^The tomb wight tears into "+targ->query_cap_name()+" biting and clawing like mad!!",targ);
 tell_object(targ,"%^RED%^The tomb wight tears into you biting and clawing like mad!!");
  targ->do_damage("torso",random(5)+14);
  return 1;
}



void die(mixed ob){
  new("/d/dagger/Torm/obj/Mlong+2.c")->move(ETO);
  tell_room(ETO,"%^BOLD%^%^RED%^As the wight stumbles back from the last blow he knocks a glittering sword from the hands of the skeleton on the bier.");
  ::die();
}
void init(){
  ::init();
  if(TP->query_invis()&&!avatarp(TP)){
  kill_ob(TP,1);
  }
}
