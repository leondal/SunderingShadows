//mini boss for argentrock
//coded 5/31/11 by hades
#include <std.h>
#include <daemons.h>
#include "../argabbr.h"
inherit MONSTER;

void create()
{ ::create();
  set_name("Mutated Goblin");
  set_id(({"goblin","gobo","monster","mutated goblin"}));
  set_short("%^RESET%^%^ORANGE%^A mutated %^BOLD%^goblin");
  set_long("This goblin looks like he is the product of "+
  "some kind of experiment.  His muscles bulge "+
  "unnaturally and his eyes look to be almost "+
  "popping out of his body.  He has veins sticking"+
  " out all over his body and is covered in sweat."+
  "  He is covered in chains and wields a pair of"+
  " rather nasty looking daggers.");
  set_race("goblin");
  set_body_type("human");
  set_gender("male");
  set_size(1);
  set("aggressive",20);
  set_class("thief");
  set_mlevel("thief",60);
  add_search_path("/cmds/feats");
  add_search_path("/cmds/thief");
  set_hd(60,10);
  set_level(60);
  set_hp(random(1000)+700);
  set_overall_ac(-5);
  set_alignment(9);
  set_stats("intelligence",5);
  set_stats("wisdom",4);
  set_stats("strength",25);
  set_stats("charisma",3);
  set_stats("dexterity", 25);
  set_stats("constitution",20);
  set_exp(30000);
  add_money("gold",random(2000));
  set_property("full attacks",1);
  set_mob_magic_resistance("very low");
  set_monster_feats(({"dodge","evasion",
  "mobility","scramble","power attack","rush","combat reflexes",
  "two weapon fighting","ambidexterity","greater two weapon fighting",
  "two weapon defense","knockdown","spring attack"}));
  set_skill("stealth",35);
  set_skill("athletics",35);
  set_thief_skill("move silently",95);
  set_thief_skill("hide in shadows",95);
  add_damage_bonus(8);
  set_property("damage resistance",4);
  set_funcs(({"strik"}));
  set_func_chance(30);
  set_scrambling(1);
  new(OBJ+"godag")->move(TO);
  new(OBJ+"godag")->move(TO);
  new(OBJ+"chain")->move(TO);
  new(OBJ+"shak")->move(TO);
  command("wield dagger");
  command("wield dagger 2");
  command("wearall");

}
void strik(object targ)
{  int x;
   if(!objectp(TO)) return 1;
   if(!objectp(ETO)) return 1;

	else{
   tell_object(targ,"%^ORANGE%^The goblin tumbles next to you"+
   " and strikes repeatedly. Chunks of %^BOLD%^your flesh%^RESET%^%^ORANGE%^"+
   " fly off you as he flails madly!  %^RED%^His body odor is toxic!");
   tell_room(ETO,"%^ORANGE%^The Goblin tumbles into"+
   " "+targ->query_cap_name()+" and strikes them repeatedly, "+
   "with a spray of %^BOLD%^blood%^RESET%^%^ORANGE%^ "+
   "and %^RED%^chunks of flesh%^ORANGE%^ flying off them!",targ);
    for(x=0;x<random(5)+3;x++)
        targ->do_damage(targ->return_target_limb(),random(70)+10);

   if(!"/daemon/saving_throw_d.c"->reflex_save(targ,-30))
    targ->set_paralyzed(10+random(30),
     "%^MAGENTA%^Oh god.. the stink...can't...breath..");
	 }
   return 1;
}
void set_paralyzed(int time,string message){
 force_me("emote %^BOLD%^%^RED%^SCREAMS%^RESET%^ and continues attacking.");
 execute_attack();
 execute_attack();
 return 1;}
void set_tripped(int time,string message){
 force_me("emote is %^GREEN%^flung%^RESET%^ from his feet"+
  " but %^GREEN%^flips%^RESET%^ over and continues attacking.");
 execute_attack();
 execute_attack();
}
void heart_beat(){
  object *attackers;
  int x;
  ::heart_beat();
  if(!objectp(TO))return;

  if(!objectp(query_current_attacker())) { return ; }
   if(query_attackers()==({ })) return;
  attackers = query_attackers();
  x = sizeof (attackers);
  if(random(2)==0)
    force_me("rush "+attackers[random(x)]->query_name());
  else force_me("knockdown "+attackers[random(x)]->query_name());
  return;
}
