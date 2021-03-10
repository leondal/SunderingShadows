#include <std.h>
#include <daemons.h>
#include <magic.h>
#include "../elf.h"
inherit WEAPONLESS;

void create() {
   ::create();
   set_name("Dire Squid");
   set_id(({"squid","dire squid"}));
   set_short("%^BLUE%^D%^CYAN%^i%^BLUE%^re S%^CYAN%^q%^BLUE%^uid");
   set_long("This is a rather gigantic squid.  It is nearly a"+
   " hundred feet long with matching hundred foot tentacles.  "+
   "It has purple black skin and a very thick hide.  It seems "+
   "like rocks are embedded in its flesh.  It has dark tentacles"+
   " that reach out with hundreds of suction cups and hooked "+
   "points in it. It has a very large beak on its underside "+
   "that likely could consume a person whole. "   );
   set_class("fighter");
   set_hd(50,10);
   set_hp(9000);
   set_guild_level("fighter", 70);
   set_mlevel("fighter", 70);
   set_overall_ac(-30);
   set_body_type("snake");
   remove_limb("tail");
   add_limb("tentacle","torso",0,0,0);
   add_limb("beak","torso",0,0,0);
   add_limb("head","torso",0,0,0);
   set_attack_limbs(({"tentacle","beak"}));
   set_attacks_num(8);
   set_damage(3,10);
   set_base_damage_type("slashing");
   set_class("fighter");
   set_gender("male");
   set_race("squid");
   set_alignment(5);
   set_mob_magic_resistance("average");
   set_property("damage resistance", 4);
   set_property("no death", 1);
   set_property("no knockdown", 1);
   set_property("no steal", 1);
   set_property("no dominate", 1);
   set_property("no hold", 1);
   set_property("no paralyze", 1);
   set_property("no bows", 1);
   set_property("no tripped", 1);
   set_property("water breather", 1);
   set_funcs(({"pounce","sweep"}));
   set_func_chance(55);
   set_skill("perception",50); 
   set("aggressive",25);
   set_new_exp(36,"boss");
   set_max_level(36);
   set_base_damage_type("bludgeoning"); 

}
void sweep(object targ){

  object *ppl;
  int i;
  if(!objectp(targ)) return;
  if(!objectp(TO)) return;
  if(!ETO) return;
  ppl=filter_array(all_living(ETO),"is_non_immortal",FILTERS_D);
  tell_room(ETO,     "%^BOLD%^%^BLUE%^Dire Squid lashes out with a tentacle.");
  for (i = 0; i < sizeof (ppl); i++){
    if(!objectp(ppl[i])) continue;
    if(!"/daemon/saving_throw_d.c"->reflex_save(ppl[i],-30)) {
         tell_object(ppl[i],
           "%^BOLD%^%^BLUE%^Dire squid whips a tentacle through the water and it sends you sprawling.");
         ppl[i]->set_tripped(1,"%^BOLD%^%^BLUE%^The tentacle sent you sprawling.");
         ppl[i]->add_attacker(TO);
		 ppl[i]->cause_typed_damage(ppl[i],0,roll_dice(5,10),"bludgeoning");
    }
        
  }
}
void pounce(object targ){
   int x;
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   if(!interactive(targ)){
     tell_room(ETO,"%^BOLD%^%^BLUE%^Dire squid wraps a tentacle around "
     +targ->QCN+" and swallows them whole.");
     targ->move("/d/shadowgate/void");
     targ->die(); //slay fodder
	 return;
   }
   tell_room(ETO, "%^BOLD%^%^BLUE%^The squid darts at "
   +targ->QCN+" and pins them to the ground!",targ);
   tell_object(targ, "%^BOLD%^%^BLUE%^Dire Squid darts into you and pins you "+
   "between its beak and the ground where it %^RED%^chomps%^BLUE%^ on you %^RED%^repeatedly");

   for(x=0;x<random(5)+5;x++)  
	 targ->cause_typed_damage(targ,0,random(40)+5,"bludgeoning");
     if(!"/daemon/saving_throw_d.c"->reflex_save(targ,-35))
       targ->set_paralyzed(10+random(30),
       "%^MAGENTA%^Oh god.. %^RED%^it hurts..");
         
  return;
}
void die(object ob){
  tell_room(ETO,"%^CYAN%^As the giant squid dies it spits out some items.");
  new(OBJ"anklet")->move(ETO);
  new(OBJ"spear")->move(ETO);
  new(OBJ"trident")->move(ETO);
  new(OBJ"bracers")->move(ETO);
  new(OBJ"breastpt")->move(ETO);
  ::die(TO);
}
