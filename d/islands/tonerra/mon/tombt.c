//Fuck it, let's bring on the slaughter - Octothorpe 2/2/10
//updated by Circe 11/21/04 after bug reports of him being too easy
//pray he doesn't slaughter all now
//tombt.c
//Fixed some bugs related to fodder, and cleaned up some of the functions -Ares 6/5/06

#include <std.h>
#include <daemons.h>
inherit WEAPONLESS;

void create(){
   ::create();
   set_name("tomb tapper");
   set_short("%^BOLD%^%^BLACK%^T%^RESET%^o%^BOLD%^%^BLACK%^mb Tapper%^RESET%^");
   set_id(({"tomb","tapper","Tomb","Tapper","Tomb Tapper","tomb tapper"}));
   /*set_long(
   "%^RED%^This loathsome creature gazes at you from non-existant eyes "+
   "set in the middle of a faceless head. The blueish hued skin is pulled "+
   "tightly over the well muscled humanoid body. You notice that there is "+
   "no sign of sex to this beast and no sign of hair or emotion. The truly "+
   "fightening thing in this creature is the large maw in the center of "+
   "the abdomen.%^RESET%^"
   );*/
   set_long("%^BOLD%^%^BLACK%^This massive construct reaches up to "+
      "fifteen feet in height with a generic humanoid form.  Its body "+
	  "almost seems to have been hewn from d%^RESET%^a%^BOLD%^"+
	  "%^BLACK%^rk stone and %^RESET%^i%^BOLD%^%^BLACK%^ron.  The "+
	  "head of the tapper is devoid of any feature lending it a truly "+
	  "alien quality.  A terrifying maw full of sharp, metal teeth "+
	  "is found on this creature's torso, and looks capable of "+
	  "rending through nearly any known material.");
   set_body_type("human");
   set_wielding_limbs(({"right hand","left hand"}));
   set_hd(44,10);
//   set_hp(1150);
//turned up in response to reports that he was too easy.  Circe 9/26/04
//other suggestions have been to make him hit through stoneskin.
   set_hp(2000+random(250));
   set_attack_limbs(({"right claw","left claw","mouth"}));
   set_damage(1,20);
   set_hit_funcs((["right claw":(:TO,"clawfunc":),"left claw":(:TO,"clawfunc":),"mouth":(:TO,"mouthfunc":)]));
   set_property("no animate",1);
   set_property("no death",1);
   set_property("full attacks",1);
   set_mob_magic_resistance("average");
   set_property("no tripped",1);
   set_property("no paralyze",1);
   set_stats("strength",24);
   set_property("magic",1);
   set_attacks_num(3);
   set_base_damage_type("slashing");
   set_overall_ac(-30);
   set_max_level(36);
   set_size(3);
   set_monster_feats(({
      "toughness",
	  "improved toughness",
	  "damage resistance",
	  "improved damage resistance",
	  "regeneration",
	  "sweepingblow",
	  "blade block",
	  "impale",
	  "light weapon",
	  "strength of arm",
	  "knockdown",	  
   }));
   new("/d/islands/tonerra/obj/hammer_of_destruction")->move(TO);
   command("wield hammer");
   set_exp(100000);
   set_new_exp(35,"boss");
   set_funcs(({"done","impaleit","sweepit","kdit"}));
   set_func_chance(55);
   set_race("construct");
   set_gender("sexless");
   set_skill("perception",55);
}

void init(){
   ::init();
   if(interactive(TP) && !TP->query_true_invis()){
        call_out("smash",1);
        kill_ob(TP,1);
   }
   return;
}

void smash()
{
    if(!present("hammer",TO)) { return; }
    if(sizeof(ETO->query_exits())) { command("smash"); }
    return;
}

int clawfunc(object targ)
{
    if(!objectp(targ)) { return 0; }
    if(!interactive(targ)) { targ->die(); return 0; }
    tell_object(targ,"%^RED%^The tapper rakes you horribly.");
    return random(12)+1;
}

int mouthfunc(object targ)
{
    if(!objectp(targ)) { return 0; }
    if(!interactive(targ)) { targ->die(); return 0; }
    return random(9)+1;
}

void done(object targ)
{
    if(!objectp(targ)) return;
    if(!interactive(targ)) { targ->die(); return; }

    tell_room(ETO,"%^CYAN%^The tapper lunges toward "+targ->QCN+".",targ);
    tell_object(targ,"%^CYAN%^The tapper lunges toward you.");
    if(random(30) > random((int)targ->query_stats("deterity")))
    {
        tell_object(targ,"%^CYAN%^The massive beast lands squarely on top of you "
            "and its mouth starts gnawing at your body while you are pinned.");
        tell_room(ETO,"%^CYAN%^The massive creature lands on top of "+targ->QCN+" "
            "pinning "+targ->QO+" down.",targ);
        targ->set_paralyzed(random(3)+2,"You are pinned.");
        targ->do_damage("torso",roll_dice(3,10));
        call_out("next",5,targ);
        set_attacks_num(0);
        set_func_chance(0);
        return;
    } 
    else 
    {
        tell_room(ETO,"The tapper fails to find its target.");
    }
}

void next(object targ)
{
    if(!objectp(targ))
    {
      set_attacks_num(4);
      set_func_chance(55);
      return;
    }
   
    if(!present(targ,ETO))
    {
      set_attacks_num(4);
      set_func_chance(55);
      return;
    }

    if(random(30) > random(targ->query_stats("strength")))
    {
        tell_object(targ,"The creature continues to chew on you.");
        targ->do_damage("torso",roll_dice(2,10));
        targ->set_paralyzed(5,"You are pinned.");
        call_out("next",6,targ);
        return;
    }
    tell_object(targ,"You break free of the tapper.");
    set_attacks_num(4);
    set_func_chance(65);
    continue_attack();
}

void kdit(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return; 
   TO->force_me("knockdown "+targ->query_name());
}

void impaleit(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return; 
   TO->force_me("impale "+targ->query_name());
}

void sweepit(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return; 
   TO->force_me("sweepingblow");
}

void die(object ob)
{
   object *attackers;
   int i;
   attackers = TO->query_attackers();
   attackers = filter_array(attackers,"is_non_immortal_player",FILTERS_D);
   if(sizeof(TO->query_attackers()) < 1) return; 
   for(i=0;i<sizeof(attackers);i++)
   { 
       if(!objectp(attackers[i])) { continue; }
      if(member_array("Silenced the Spirit of the Catacombs, Defeated Tomb Tapper",attackers[i]->query_mini_quests()) == -1){
	     attackers[i]->set_mini_quest("Silenced the Spirit of the Catacombs, Defeated Tomb Tapper",1000000,"%^BOLD%^%^BLACK%^Silenced the Spirit of the Catacombs, Defeated Tomb Tapper%^RESET%^");
      }
   }	  
   ::die(ob);
}

set_paralyzed(int time, string message) {return 1;}

/*
int kill_ob(object victim, int x)
{
   if(!userp(victim) && victim != TO)
   {
      tell_room(ETO,"The tapper looks over the "+victim->query_cap_name()+" and laughs.");
      tell_room(ETO,"%^BLUE%^With a nod of its head the "+victim->query_cap_name()+" disappears in a destructive burst.");
      victim->move("/d/shadowgate/void");
      victim->remove();
   }
   return ::kill_ob(victim,x);
}
*/
