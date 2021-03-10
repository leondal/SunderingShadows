//Octothorpe (1/19/10)
//Attaya, Callista
//Original by Thundercracker

#include <std.h>
#include "../defs.h"
#include <daemons.h>
inherit MONSTER;

void create() {
   object ob;
   ::create();
   set_name("callista");
   set_id(({"callista","master assassin","assassin"}));
   set_short("%^RESET%^%^MAGENTA%^Callista, Master Assassin of the "+
      "Kinnesaruda%^RESET%^");
   set_long("%^RESET%^%^MAGENTA%^This woman can almost be universally "+
      "classified as one of the most beautiful beings in the world.  "+
	  "Composed of a lithe body and cat-like grace, she resembles a "+
	  "predator more than Tharisian harlot.  Light elven features "+
	  "touch her face, complete with high cheekbones and slightly "+
	  "tapered ears.  Her long %^BOLD%^%^BLACK%^raven bl%^RESET%^a"+
	  "%^BOLD%^%^BLACK%^ck %^RESET%^%^MAGENTA%^hair is tucked behind "+
	  "her ears, and reaches down to the small of her back.  She is "+
	  "clothed in skin-tight leather pants that are molded to her "+
	  "every curve, and a strapless bodice which does a fairly "+
	  "inadequate job at preserving the modesty of her torso.");
   set_race("half-elf");
   set_gender("female");
   set_hd(50,6);
   set_size(2);
   set_overall_ac(-24);
   set_class("fighter");
   set_property("undead", 1);
   set_class("thief");
   set_mlevel("fighter",55);
   set_mlevel("thief",55);
   set_guild_level("thief",55);
   set_guild_level("fighter",55);
   add_search_path("/cmds/fighter");
   add_search_path("/cmds/assassin");
   add_search_path("/cmds/thief");
   set_scrambling(1);
   set_max_hp(5000+random(1500));
   set_hp(query_max_hp());
   set_wielding_limbs(({"right hand","left hand"}));
   set_body_type("human");
   set_mob_magic_resistance("average");
   set_property("weapon resistance",3);
   set_property("full attacks",1);
   set_property("no paralyze", 1);
   set_property("no knockdown", 1);
   set_property("no death",1);
   set_property("no dominate",1);
   set_property("no bows",1);
   set_property("no hold", 1);
   set_property("no tripped", 1);
   set_property("swarm",1);
   set_skill("perception",50);
   set_property("magic", 1);
   set_property("assassin",1);
   set_stats("strength",22);
   set_stats("dexterity",22);
   set_stats("constitution",22);
   set_stats("wisdom",16);
   set_stats("intelligence",18);
   set_stats("charisma",24);
   set("aggressive","aggfunc");
   set_alignment(6);
   set_exp(50000);
   new(OBJ"cal_armor")->move(TO);
   new(OBJ"cal_gcutlass")->move(TO);
   command("wield sword in left hand");
   new(OBJ"cal_crysknife")->move(TO);
   command("wield dagger in right hand");
   ob=new("/d/islands/common/obj/chemise.c");
   ob->set_property("enchantment",2+random(4));
   ob->move(TO);
   new(OBJ"cal_pants")->move(TO);
   command("wearall");
   command("speak wizish");
   command("speech %^MAGENTA%^purr seductively%^RESET%^");
   set_monster_feats(({
      "ambidexterity",
	  "two weapon fighting",
	  "improved two weapon fighting",
	  "greater two weapon fighting",
	  "two weapon defense",
	  "hardenedminions",
	  "knockdown",
	  "blindfight",
	  "powerattack",
	  "shatter",
	  "sunder",
	  "rush",
	  "combat reflexes",
	  "expertise",
	  "disarm",
	  "dodge",
	  "mobility",
	  "evasion",
	  "scramble"
   }));
   set_funcs(({
      "fireball",
	  "allies",
	  "freeze",
	  "fire",
	  "kiss",
	  "light",
	  "impaler",
	  "tornado",
	  "healing",
	  "bolt",
	  "circle",
	  "desoul",
	  "flashit",
	  "rushit",
	  "kdit",
	  "disarmit",
	  "shatterit",
	  "sunderit"
   }));
   set_func_chance(95);
   add_money("gold",20000+random(10000));
}

void die(object ob){
   object *attackers;
   int i;
   attackers = TO->query_attackers();
   attackers = filter_array(attackers,"is_non_immortal_player",FILTERS_D);
   if(sizeof(TO->query_attackers()) < 1) return;
   tell_room(ETO,"%^BOLD%^Callista falls to her knees and mutters "+
      "whilst %^RESET%^%^RED%^blood %^BOLD%^%^WHITE%^drips out of her mouth...\n "+
       "%^RESET%^%^RED%^Father...please...help me...%^RESET%^\n");
   tell_room(ETO,"%^BOLD%^%^BLACK%^A voice snarls out of the shadows"+
      "%^RESET%^: %^BOLD%^You have failed me, bitch.%^RESET%^\n");
   tell_room(ETO,"%^BOLD%^Callista suddenly begins to decay rapidly, "+
      "and shrivels up until only a %^RESET%^%^ORANGE%^leathery-"+
	  "skinned %^BOLD%^%^WHITE%^skeleton remains.");
   TO->set_name("rotting skeleton");
   for(i=0;i<sizeof(attackers);i++){
      if(!objectp(attackers[i])) { continue; }
	  if(member_array("Deadly Beauty, Defeated Callista",attackers[i]->query_mini_quests()) == -1){
	     attackers[i]->set_mini_quest("Deadly Beauty, Defeated Callista",50000,"%^RESET%^%^RED%^Deadly Beauty, Defeated Callista%^RESET%^");
      }
   }
   ::die(ob);
}

void aggfunc(object targ) {
   string mrace=TP->query_race();
   if(mrace == "undead"){
      return;
   }
   else{
      if(wizardp(TP)) return;
      tell_object(TP,"%^MAGENTA%^Callista purrs seductively%^RESET%^: "+
         "%^RED%^Welcome...to your doom!%^RESET%^\n");
      TO->force_me("kill "+TPQN);
      TO->force_me("rush "+TPQN);
      TO->force_me("watch");
      TO->force_me("hardenedminions");
   }
}

void allies(object ob){
   int i, num;
   num=random(4)+1;
   if(!objectp(TO)) return;
   tell_room(ETO,"%^BOLD%^Callista raises her hands above her head and "+
      "a spinning vortex of %^MAGENTA%^m%^YELLOW%^u%^BLUE%^l%^RED%^t"+
	  "%^GREEN%^i%^CYAN%^co%^GREEN%^l%^RED%^o%^BLUE%^r%^YELLOW%^e"+
	  "%^MAGENTA%^d %^WHITE%^light appears.%^RESET%^");
   switch(random(2)){
      case 0:
	     tell_room(ETO,"%^BOLD%^%^BLACK%^Several phantasmic crows "+
	        "appear from the vortex before it closes.%^RESET%^");
		 for(i=0;i<num;i++){
		    ob=new(MON"crow");
			ob->move(ETO);
			TO->add_follower(ob);
		 }
         break;
      case 1:
         tell_room(ETO,"%^BOLD%^%^BLACK%^Several phantasmic jackals "+
            "leap from the vortex before it closes.%^RESET%^");
	     for(i=0;i<num;i++){
		    ob=new(MON"jackal");
			ob->move(ETO);
			TO->add_follower(ob);
		 }
		 break;
   }
}

void impaler(object targ){
   string dam;
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   if(!"/daemon/saving_throw_d.c"->fort_save(targ,-25)){
      dam="impales";
   }
   else{
      dam="hurts";
   }
   tell_object(targ,"%^BOLD%^%^MAGENTA%^ Callista charges towards "+
      "you and "+dam+" you with her sword!");
   tell_room(ETO,"%^MAGENTA%^Callista charges with her "+
      "sword and impales "+targ->QCN+"!%^RESET%^",targ);
   if(dam=="impales"){
      targ->do_damage("torso",roll_dice(10,20));
	tell_object(targ,"%^RED%^You feel intense pain and your ability to "+
	   "fight has been compromised!\n");
   }
   else{
      targ->do_damage("torso",roll_dice(8,20));
   }
   return;
}

void fire(object targ){
   string dam;
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   if(!"/daemon/saving_throw_d.c"->will_save(targ,-25)){
      dam="singes";
   }
   else{
      dam="hurts";
   }
   tell_object(targ,"%^BOLD%^%^RED%^Callista begins to glow.  Phantom "+
      "fire flashes about you and "+dam+" you!%^RESET%^");
   tell_room(environment(targ),"Callista casts %^RED%^phantom fire at "+
      ""+targ->QCN+"!%^RESET%^",targ);
    if(dam=="singes") {
        targ->do_damage("torso",roll_dice(5,10));
	tell_object(targ,"%^BOLD%^You are blinded by a brilliant light and intense heat!");
	targ->set_tripped(random(10)+15,"%^MAGENTA%^You cannot see your "+
	   "opponent and stumble around blindly!%^RESET%^");
    }
	else{
       targ->do_damage("torso",roll_dice(5,10));
    }
    return;
}
void healing(object ob){
   if(!objectp(TO)) return;
   tell_room(ETO,"%^GREEN%^Callista touches her fingers to her "+
      "forehead and mutters a chant.  %^BOLD%^%^WHITE%^Callista's "+
	  "wounds begin to heal themselves.");
   TO->add_hp(random(600)+400);
}

void circle(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   if(!"/daemon/saving_throw_d.c"->reflex_save(targ,-25)){
      tell_object(targ,"%^BOLD%^%^BLACK%^Callista stabs you in the back!");
      targ->do_damage("torso", random(150)+50);
	  if(!random(2)){
	     TO->force_me("crit "+targ->query_name());
	  }
   }
   else{
   tell_object(targ,"%^BOLD%^Callista misses a backstab attempt.");
   }
}

void freeze(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
    if(!"/daemon/saving_throw_d.c"->fort_save(targ,-25)){
	   tell_room(ETO,"%^CYAN%^Callista draws in the energy around "+
	      "her and congeals it into a dagger of %^BOLD%^%^WHITE%^ic"+
		  "%^RESET%^%^CYAN%^e.");
	   tell_room(ETO,"%^CYAN%^Callista casts a dagger of compressed "+
	      "%^BOLD%^%^WHITE%^ic%^RESET%^%^CYAN%^e at "+targ->QCN+"!",targ);
	   tell_object(targ, "%^CYAN%^Callista's dagger of compressed "+
	      "%^BOLD%^%^WHITE%^ic%^RESET%^%^CYAN%^e rips into you and "+
		  "the surrounding blood freezes!");
       targ->do_damage("torso",random(50)+50);
	   targ->set_paralyzed(random(30)+30,"%^BOLD%^You are frozen solid!");
	   return;
    }
	else{
	   tell_room(ETO,"%^BOLD%^Callista loses concentration while "+
	      "attempting to draw in the energy around her");
    }
}

void fireball(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   if(!"/daemon/saving_throw_d.c"->reflex_save(targ,-25)){
      tell_room(ETO,"%^BOLD%^%^RED%^Callista hurls a fireball at "+targ->QCN+"!",targ);
	  tell_object(targ,"%^BOLD%^%^RED%^Callista hurls a fireball at you!");
      targ->do_damage("torso",random(75)+75);
	  return;
   }
   else{
      tell_object(targ,"%^RED%^Callista's fireball speeds past you and "+
         "slams into the wall in a shower of sparks!");
      tell_room(environment(targ),"%^BOLD%^%^RED%^Callista hurls a "+
         "fireball at "+targ->QCN+" and misses.",targ);
   }
}

void bolt(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   if(!"/daemon/saving_throw_d.c"->will_save(targ,-25)){
      tell_room(environment(targ),"%^YELLOW%^Callista shoots lightning "+
	     "from her fingertips and blasts "+targ->QCN+"!",targ);
	  tell_object(targ,"%^YELLOW%^Callista shoots lightning from her "+
	     "fingertips and blasts you!");
      targ->do_damage("torso",random(50)+80);
	  return;
   }
   else{
      tell_object(targ,"%^YELLOW%^Callista shoots lightning from her "+
	     "fingertips and it strikes all around you!");
	  tell_room(environment(targ),"%^YELLOW%^Callista shoots lightning "+
	     "from her fingertips and it strikes all around "+targ->QCN+"!",targ);
      targ->do_damage("torso",random(35)+80);
   }
}

void tornado(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   if("/daemon/saving_throw_d.c"->reflex_save(targ,-25)){
      tell_room(ETO,"Callista kneels and touches her palms against "+
	     "the floor.");
	  tell_room(ETO,"%^BOLD%^A tornado rises beneath "+targ->QCN+"!",targ);
	  tell_object(targ,"%^BOLD%^A tornado rises beneath you and thrusts "+
	     "you upwards against the ceiling!");
      targ->do_damage("torso", random(80)+80);
	  return;
   }
   else{
      tell_room(ETO,"Callista kneels and touches her palms against "+
	     "the floor.");
	  tell_room(environment(targ),"%^CYAN%^The ground beneath your "+
	     "feet shakes violently");
	  targ->force_me("drop all");
   }
}

void light(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   if(!"/daemon/saving_throw_d.c"->will_save(targ,-25)){
      tell_room(ETO,"%^BOLD%^Callista thrusts her hands foreward, then upwards.");
	  tell_room(ETO,"%^BOLD%^%^BLACK%^The shadows compress to form a "+
	     "ball of energy in her hands.");
	  tell_room(ETO,"%^MAGENTA%^Her body trembles as dark lightning "+
	     "tears down her arms and her eyes begin to glow.");
	  tell_room(ETO,"%^BOLD%^%^BLACK%^Callista lowers her hands and "+
	     "blasts a horrible beam of black light at "+targ->QCN+"!",targ);
	  tell_object(targ,"%^BOLD%^%^BLACK%^Callista lowers her hands "+
	     "and blasts you with a horrible beam of black light!");
	  tell_object(targ,"%^RED%^It utterly destroys you!");
      targ->do_damage("torso",random(400)+100);
	  return;
   }
   else{
      tell_object(targ,"%^YELLOW%^Callista grabs you by the throat "+
	     "and slams you against the wall!");
      targ->do_damage("torso",random(170)+50);
	  tell_room(ETO,"%^YELLOW%^Callista grabs "+targ->QCN+" and slams "+
	     ""+targ->QP+" head against the wall.",targ);
   }
}

void kiss(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   if(!"/daemon/saving_throw_d.c"->fort_save(targ,-25)){
	  tell_room(ETO,"Callista kisses "+targ->QCN+" on the cheek.",targ);
	  tell_object(targ,"%^BLUE%^Callista kisses you on the cheek while muttering an ancient chant!");
	  tell_object(targ,"%^BOLD%^%^RED%^You have been poisoned severely!");
	  targ->do_damage("torso",random(1)+9);
      targ->add_poisoning(300);
	  return;
   }
   else{
      tell_object(targ,"%^RED%^Callista cleaves you with her sword!");
      targ->do_damage("torso",random(100)+20);
	  tell_room(ETO,"Callista cleaves "+targ->QCN+" with her sword.",targ);
    }
}

/* I'm considering the addition of an item that will protect a person's soul from being desouled.  Most likely would be added to Magus Prime's lab, or maybe in the Soulchamber room.  If I do go ahead with this I'll be adding in a present check for the item in the desoul function. - Octothorpe 2/1/10 */

void desoul(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   if(!"/daemon/saving_throw_d.c"->will_save(targ,-15)){
      if(targ->query_property("no death")){
         tell_room(ETO,"%^BOLD%^%^BLUE%^Callista calls to powers greater "+
	        "than any you have ever known.");
	     tell_room(ETO,"%^BOLD%^%^BLUE%^Callista's hair begins to fly "+
	        "around, moved by a sudden wind.");
	     tell_room(ETO,"%^BOLD%^Callista points to "+targ->QCN+"!",targ);
	     force_me("say I shall destroy your very soul.");
	     tell_room(ETO,"%^RED%^Callista's eyes glow red and she screams "+
	        "loudly.");
	     tell_room(ETO,"%^BOLD%^%^BLACK%^Callista casts desoul on "+
	        ""+targ->QCN+"!",targ);
	     tell_object(targ,"%^BOLD%^%^BLACK%^Callista casts desoul on "+
	        "you!");
	     tell_object(targ,"%^BOLD%^%^RED%^Your soul has been seriously "+
	        "fucked up!");
	     force_me("say May whatever gods you believe in have mercy on "+
	        "your soul...");
         targ->set_hp(((int)targ->query_hp()/3));;
         return;
      }
      tell_room(ETO,"%^BOLD%^%^BLUE%^Callista calls to powers greater "+
         "than any you have ever known.");
	  tell_room(ETO,"%^BOLD%^%^BLUE%^Callista's hair begins to fly "+
	     "around, moved by a sudden wind.");
	  tell_room(ETO,"%^BOLD%^Callista points to "+targ->QCN+"!",targ);
	  force_me("say I shall destroy your very soul.");
	  tell_room(ETO,"%^RED%^Callista's eyes glow red and she screams "+
	     "loudly.");
	  tell_room(ETO,"%^BOLD%^%^BLACK%^Callista casts desoul on "+
	     ""+targ->QCN+"!",targ);
	  tell_object(targ,"%^BOLD%^%^BLACK%^Callista casts desoul on "+
	     "you!");
	  tell_object(targ,"%^BOLD%^%^RED%^Your soul has been destroyed!");
      force_me("say May whatever gods you believe in have mercy on "+
	     "your soul...");
      targ->set_hp(-10);
      return;
   }
   else{
	  tell_object(targ,"%^MAGENTA%^Callista thrusts her right leg "+
	     "upwards and hooks it around your neck.");
	  tell_object(targ,"%^MAGENTA%^Callista drops, slamming your face "+
	     "against the floor beneath her weight.");
      targ->do_damage("torso", random(70)+80);
	  tell_room(ETO,"%^MAGENTA%^Callista thrusts her right leg upward "+
	     "and hooks it around  "+targ->QCN+".  She then drops, slamming "+
         ""+targ->QP+" face into the floor.",targ);
   }
}

void kdit(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   TO->force_me("knockdown "+targ->query_name());
}

void flashit(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   TO->force_me("flash "+targ->query_name());
}

void rushit(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   TO->force_me("rush "+targ->query_name());
}

void disarmit(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   TO->force_me("disarm "+targ->query_name());
}

void sunderit(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   TO->force_me("sunder "+targ->query_name());
}

void shatterit(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   TO->force_me("shatter "+targ->query_name());
}
