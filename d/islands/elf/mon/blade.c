
#include <std.h>
#include "../elf.h"
#include <daemons.h>
inherit MONSTER;

int FLAG;

void create()
{ object pap;
  ::create();

  set_name("Elea");
  set_id(({"elf","Elea","blade singer","bladesinger","guardian","elea"}));
  set_short("Elea, guardian of the grove");
  set_long("This is a regal looking elf with bronze skin "+
  "and golden eyes.  Complementing her golden eyes is"+
  " long coppery red hair.  She wears a silver headband"+
  " and some light leather armor.  Her armor is covered"+
  " in a bright orange robe of masterwork quality. ");
  set_race("elf");
  set_gender("female");
  set_class("mage");
  set_mlevel("mage",40);
  add_search_path("/cmds/feats");
  add_search_path("/cmds/mage");
  set_hd(40,10);
  set_level(40);
  set_hp(random(2000)+1000);
  set_overall_ac(-30);
  set_alignment(1);
  set_stats("intelligence",19);
  set_stats("wisdom",10);
  set_stats("strength",16);
  set_stats("charisma",16);
  set_stats("dexterity", 25);
  set_stats("constitution",16);
  add_money("silver",random(2000));
  set_property("full attacks",1);
  set_mob_magic_resistance("average");
  set_monster_feats(({"dodge","knockdown","expertise"
  ,"powerattack","rush","spell focus","knockdown",
  "spell penetration","greater spell penetraion" }));
  set_skill("stealth",50);
  set_skill("perception",50);
  set_funcs(({"strik"}));
  set_func_chance(20);
  set_property("alignment adjustment",-6);
  set_property("no dominate",1);
  set_property("knock unconsious",1);
    set_emotes(2,({
   "Elea watches you cautiously.",
   "Elea scans the area.",
   "Elea looks around.",
   "Elea whispers a few arcane phrases.",
   "Elea nods slightly.",
   "Elea adjusts her clothing.",
   "Elea guards the area.",
   "Elea lets some gold elves into the keep.",
   }),0);
  add_attack_bonus(10);
     set_spells(({
      "disintegrate",
      "greater shout",
	  "gust of wind",
	  "dispel magic"
   }));
   set_spell_chance(50);
   if(random(2) == 0){
     new(OBJ"fan")->move(TO);
     force_me("wield fan");
   }
   else{
     new(OBJ"rape")->move(TO);
     force_me("wield rapier");
   }
   new(OBJ"scroll_case")->move(TO);
  pap = new("/d/common/obj/misc/paper");
  pap->move(TO);
  pap->set("language","elven");
  pap->set("read","%^GREEN%^ELF Journal\n\n%^RESET%^"+
       "Mine eye runneth down with rivers of water"+
	   " for the destruction of the daughters of "+
	   "my people.  Mine eye trickleth down, and "+
	   "ceaseth not, without any intermission, Until"+
	   " the Lord looks down and beholds from heaven."+
	   "  Mine eye affecteth mine heart because of "+
	   "all the daughters of my city.  Mine enemies "+
	   "chased me sore, like a bird, without cause. "+
	   " They have cut off my life in the dungeon, "+
	   "and cast a stone upon me.  Waters flowed over"+
	   " mine head; then I said, I am cut off.");
   set_new_exp(30,"very high");
   set_max_level(35);
   set_base_damage_type("bludgeoning"); 
}
int query_blinking() {
   return 1;
}
void init(){
  ::init();
  if(wizardp(TP)) return;
  if(!interactive(TP)) return;
         if((string)TP->query_race() != "elf")  {
           command("say Your kind are not welcome here.");
           command("emote points towards the gate, and glares.");
           //call_out("strik",10,TP);
		   }
   return;
}
void strik(object targ)
{  int x;
   if(!objectp(targ)) return 1;
   if(!objectp(TO)) return 1;
   if(!objectp(ETO)) return 1;
   if(!present(targ)) return 1;	
	else{
   tell_object(targ,"%^MAGENTA%^Elea throws a handful "+
   "of %^CYAN%^glittering dust%^MAGENTA%^ at you from a bag!");
   tell_room(ETO,"%^MAGENTA%^Elea throws a handful of"+
   " %^CYAN%^glittering dust%^MAGENTA%^ at"+
   " "+targ->QCN+" from a bag.",targ);

   if(!"/daemon/saving_throw_d.c"->reflex_save(targ,-40))
    targ->set_asleep(1,
     "%^BOLD%^%^BLUE%^You have fallen asleep and are in dreamland.");
	 }
   return 1;
}
void set_paralyzed(int time,string message){
 force_me("emote %^BOLD%^sings%^RESET%^ and continues attacking.");
 execute_attack();
 execute_attack();
 return 1;}
void set_tripped(int time,string message){
 force_me("emote is %^GREEN%^flung%^RESET%^ from her feet"+
  " but %^GREEN%^flips%^RESET%^ over and continues attacking.");
 execute_attack();
 execute_attack();
}
void crit(object targ){
  tell_object(targ, "%^BOLD%^%^RED%^A slender blade "+
   "appears in the elf's hand before"+
   " she drives it deep into your body, incapacitating you!");
  tell_room(ETO,"%^BOLD%^%^RED%^A slender weapon "+
  "appears in the elf's hand before"+
  " she drives it deep into "+targ->QCN+"%^BOLD%^%^RED%^ leaving them"+
  " twitching when it is pulled out.",targ);
  targ->cause_typed_damage(targ,0,roll_dice(5,10)+20,"piercing");
  targ->set_paralyzed(5,"%^RED%^That last hit %^BOLD%^HURT!");
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
  if(random(2)==0)
    force_me("knockdown "+attackers[random(x)]->query_name());
  else crit(query_current_attacker());
  return;
}

void struck(int damage, object weapon, object attacker, string limb) 
{
    int x;
    if(damage > 0  )
    {
        if( random(6)==0)
	{
	damage = 0;
        tell_room(ETO,"%^BOLD%^"+
            "Elea dances away from the blow "+
             "as "+
            ""+attacker->QCN+" strikes at her.",({ETO,attacker}));
 
        tell_object(attacker,"%^BOLD%^Elea dances "+
            " as "+
            "you strike at her, avoiding the blow!");

	}
	else  x = do_damage(limb,damage);
	if(objectp(attacker))
		attacker->send_messages(0, weapon,limb, x, TO);
    }
    return damage;
}

void catch_say(string msg){
   call_out("reply_func",1,msg,TP);
}
void reply_func(string msg, object who){
   if(!msg || !objectp(who)) return;
   if (base_name(who) == base_name(TO)) return;
   
   if((strsrch(msg,"rapier") != -1) && present("rapier",TO)){
      force_me("say I'll show this to you.");
      force_me("show rapier to "+who->query_name());
      force_me("say I use the blade to protect the people.");
      force_me("say There are tales of a ghost that haunts"+
	  " the land.  Bring me her locket, and I will part with it.");
      force_me("say I wish the sounds at night would stop,"+
	  " her sorrowful singing brings an even worse chill to the night.");
      return;
	  }
	if((strsrch(msg,"fan") != -1) && present("fan",TO)){
      force_me("say I'll show this to you.");
      force_me("show fan to "+who->query_name());
      force_me("say I use the fan to protect the people.");
      force_me("say There are tales of a ghost that haunts"+
	  " the land.  Bring me her locket, and I will part with it.");
      force_me("say I wish the sounds at night would stop,"+
	  " her sorrowful singing brings an even worse chill to the night.");
      return;
	  }
	    if(strsrch(msg,"hello") != -1 || strsrch(msg,"hi") != -1 
		|| strsrch(msg,"greeting") != -1) {
      force_me("emote nods to you politely.");
	  if(ALIGN->is_evil(who))
	    force_me("say You don't belong here, leave now.");
      return;
   } 
}
void receive_given_item(object obj){
   if(!objectp(obj)) return;
//   if((string)obj->query_name() == "elfquestlocket"){
// I guess noone checked if this actually worked before it was installed?
   if(base_name(obj) == OBJ"locket"){
      force_me("smile "+TPQN);
      force_me("say Thank you for stopping that haunting for me. "
         "I am in debt to you.");
      force_me("emote throws the locket on the floor and smashes it "
         "with her feet.");
      obj->remove();
	  if((string)TP->query_race() != "elf"){
	    force_me("say thank you for your efforts."+
	    "  I'm surprised someone who isn't elven would want to help me.");
	    force_me("give "+query_money("silver")+" silver coins to "+TPQN);
	    return;
	  }
      if(present("rapier",TO)) force_me("give rapier to "+TPQN);
      else if(present("fan",TO)) force_me("give fan to "+TPQN);
      else force_me("give "+query_money("silver")+" silver coins to "+TPQN);
      force_me("say Please take it. I don't have much to give.");
      return;
   }

}
