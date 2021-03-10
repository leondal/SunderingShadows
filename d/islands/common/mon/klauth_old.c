// Nienne: Modifications made April 2010
// Klauth and Q are now stabbable (50) by highlevel rogues
// Fixed the chamber to re-open if combat ends, and set logging of all combat attempts to "klauth" log
// Mini-quest added and loot bound to the quest rather than soulbound
// All loot de-cursed and set up on a selection system rather than random drop
#include <std.h>
#include <daemons.h>
inherit WEAPONLESS;

object ob, *fighterz;
int fire, exit, active;
string mrace;

void create() {
   ::create();
   set_name("Klauth");
   set_id(({"dragon","red dragon","klauth"}));
   set_short("%^RESET%^%^RED%^Klauth, a great wyrm red dragon%^RESET%^");
   set_long(
      "%^RESET%^%^RED%^Klauth is known by several names depending on the area"+
      " you are in. To some he is known as the %^BOLD%^%^BLACK%^Terror of the Seas%^RESET%^%^RED%^ and to"+
      " others he is known by names such as %^BOLD%^%^BLACK%^The Bringer of Death%^RESET%^%^RED%^ or even %^BOLD%^%^BLACK%^The Tyrant of the skies.%^RESET%^%^RED%^"+
   " Regardless of who you are, one thing remains constant; Klauth is a force to"+
    " be reckoned with and feared. He resides on the top of this mountain and considers"+
      " all within his sight to be his property. This would explain his constant attacks on"+
      " ships in this area. Klauth is one of the oldest dragons known to"+
     " exist and his physical condition shows evidence of such a fact."+
      " He is at least 120 feet long and has a wing span of nearly 150 feet."+
      " His dull red scales are large, thick, and as hard as steel."+
      " His neck frill and wings are ash blue in color towards the edges."+
      " His pupiless eyes bring images of molten lava orbs to mind."
   );
   set_class("fighter");
   set_class("mage");
   set_hd(50,10);
   set_hp(13500);
   set_guild_level("fighter", 70);
   set_guild_level("mage", 70);
   set_mlevel("fighter", 70);
   set_mlevel("mage", 70);
   set_exp(1000000);
   set_overall_ac(-32);
   set_body_type("dragon");
   set_attack_limbs(({"right claw","left claw","mouth"}));
   set_attacks_num(5);
   set_damage(3,10);
   set_base_damage_type("slashing");
   set_class("fighter");
   set_gender("male");
   set_race("dragon");
   add_money("gold",random(100000));
   add_money("platinum",random(20000));
   set_alignment(9);
   set_mob_magic_resistance("average");
   set_property("weapon resistance", 4);
   set_property("no death", 1);
   set_property("no knockdown", 1);
   set_property("no steal", 1);
   set_property("no dominate", 1);
   set_property("no hold", 1);
   set_property("no paralyze", 1);
   set_property("no bows", 1);
   set_property("spell penetration",40);
   set_property("no tripped", 1);
   set_funcs(({"fire","fire","fireballs","fireballs","summon","summon","pounce","earthquake","rush","sweep"}));
   set_func_chance(85);
   set_spells(({"dispel magic"}));
   set_spell_chance(10);
   fire = 1;
   exit = 1;
   set_skill("perception",50); //make it stabbable by a highly skilled thief so they're not useless. Nienne, 04/10.
   ob = new("/d/common/obj/brewing/herb_special_inherit");
   ob->set_herb_name("heart of an ancient wyrm");
   ob->move(TO);
   set_resistance("fire",25);
   set_property("cast and attack",1);
   set_property("function and attack",1);
   set_property("add quest", "%^BOLD%^%^RED%^Defeated the great red wyrm Klauth!%^RESET%^");
   set_property("quest exp",1000000);
}

void init() {
   ::init();
   add_action("no_cast","toss");
   add_action("no_cast","throw");
    mrace=TP->query_race();
	if (base_name(TP) == "/d/token_hunt/token_monster") {
	   TP->move("/d/shadowgate/void");
	   TP->remove();
	   if(!fire) {
	      call_out("reset_fire",0);
	   }
	   return;
	}
    if (mrace == "devil") {
        force_me ("say Do your worse Pit Fiend.");
        return 1;
    }
    if (mrace == "clayman") {
        force_me ("say Attack the intruders!");
        return 1;
    } else {
   if(TP->query_invis() && !avatarp(TP)) {
      TO->force_me("kill "+TP->query_name()+"");
   }
   if(!TP->query_invis() && !avatarp(TP)) {
      TO->force_me("kill "+TP->query_name()+"");
   }
}
}

int no_cast(string str) {
   object targ;
   targ = this_player();
   tell_object(targ, "%^RESET%^%^RED%^The dragon sends you a frightful glare and freezes your action!%^RESET%^");
   return 0;
}

void breathe() {
   new("/cmds/spells/s/_stoneskin.c")->use_spell(TO,TO,100,100,"mage");
   /*tell_room(ETO,"%^BOLD%^%^RED%^Rocks and dust start to kick up as the dragon begins to inhale air at an incredible speed through his nostrils and mouth!!!%^RESET%^");
tell_room(ETO,"The stairs leading up are suddenly covered in rubble.");
   ob = find_object_or_load("/d/islands/common/aramanth/mountain10");
   ob->remove_exit("top");*/
   call_out("warning1",15);
   fire = 0;
}

void fire() {
   if(!fire) {
   object *vars;
   int i;
   vars = all_living(ETO);
   vars = filter_array(vars, "is_non_immortal_player",FILTERS_D);
   for(i=0;i<sizeof(vars);i++){
      if(vars[i] == TO) continue;
      tell_object(vars[i],"%^BOLD%^%^BLACK%^The dragon snorts and smoke rises from his nostrils.%^RESET%^\n%^BOLD%^%^RED%^His mouth opens wide and his head thrusts forward spewing a blazing flame all over the mountain top!%^RESET%^");
      if(!"/daemon/saving_throw_d"->reflex_save(vars[i],-35)) {
         tell_object(vars[i],"%^BOLD%^%^RED%^You are unable to dodge the flame and catch the full effect of the explosion!!!%^RESET%^");
         set_property("magic", 1);
         vars[i]->do_damage("torso", random(200)+200);
         remove_property("magic");
}else{
         tell_object(vars[i],"%^BOLD%^%^RED%^You are able to dodge the full explosion of fire, but still get burned!%^RESET%^");
         set_property("magic", 1);
         vars[i]->do_damage("torso", random(150)+150);
         remove_property("magic");
      }
   }
   }else{
   call_out("breathe",0);
   return 1;
   }
}
void fireballs(object targ) {
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   if(!fire) {
   tell_room(ETO,"Sets off an array of %^BOLD%^%^MAGENTA%^spell triggers%^RESET%^ that %^BOLD%^%^YELLOW%^lights%^RESET%^ the area up with %^BOLD%^%^BLUE%^s%^BOLD%^%^RED%^e%^BOLD%^%^WHITE%^v%^BOLD%^%^YELLOW%^e%^BOLD%^%^GREEN%^r%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^l c%^RESET%^RED%^o%^BOLD%^%^YELLOW%^l%^RESET%^GREEN%^o%^RESET%^%^MAGENTA%^r%^BOLD%^%^BLUE%^s%^RESET%^!", targ);
   tell_object(targ,"Sets off an array of %^BOLD%^%^MAGENTA%^spell triggers%^RESET%^ that %^BOLD%^%^YELLOW%^lights%^RESET%^ the area up with %^BOLD%^%^BLUE%^s%^BOLD%^%^RED%^e%^BOLD%^%^WHITE%^v%^BOLD%^%^YELLOW%^e%^BOLD%^%^GREEN%^r%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^l c%^RESET%^RED%^o%^BOLD%^%^YELLOW%^l%^RESET%^GREEN%^o%^RESET%^%^MAGENTA%^r%^BOLD%^%^BLUE%^s%^RESET%^!");
   //ADDED BY SAIDE - I changed all of the following spells to 
   //use simply "targ" as the target, instead of "targ->query_name()"
   //I'm fairly sure it needs to be an object and not a string
   new("/cmds/spells/f/_fireball.c")->use_spell(TO,targ->query_name(),50,100,"mage");
   new("/cmds/spells/f/_fireball.c")->use_spell(TO,targ->query_name(),50,100,"mage");
   new("/cmds/spells/p/_prismatic_spray.c")->use_spell(TO,targ->query_name(),50,100,"mage");
   new("/cmds/spells/p/_powerword_stun.c")->use_spell(TO,targ->query_name(),50,100,"mage");
      return 1;
   }else{
   call_out("breathe",0);
   return 1;
   }
}
void sweep(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   if(!fire) {
   tell_room(ETO, "%^BOLD%^%^CYAN%^The dragon snaps it's tail like a whip, then strikes out at "+targ->query_cap_name()+" with lightning quickness!%^RESET%^", targ);
   tell_object(targ, "%^BOLD%^%^CYAN%^The dragon snaps it's tail like a whip, then strikes out at you with lightning quickness!%^RESET%^");
   targ->do_damage("torso", random(75)+75);
   return 1;
   }else{
   call_out("breathe",0);
   return 1;
   }
}
void pounce(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   if(!fire) {
   tell_room(ETO, "%^BOLD%^%^BLACK%^The dragon leaps off the ground and pounces over "+targ->query_cap_name()+" and delivers several slashes with it's claws!%^RESET%^", targ);
   tell_object(targ, "%^BOLD%^%^BLACK%^The dragon leaps off the ground and pounces over you!%^RESET%^");
   tell_object(targ, "%^BOLD%^%^BLACK%^The dragon slashes you!%^RESET%^");
   targ->do_damage("torso", random(15)+10);
   tell_object(targ, "%^BOLD%^%^BLACK%^The dragon slashes you!%^RESET%^");
   targ->do_damage("torso", random(15)+10);
   tell_object(targ, "%^BOLD%^%^BLACK%^The dragon slashes you!%^RESET%^");
   targ->do_damage("torso", random(15)+10);
   tell_object(targ, "%^BOLD%^%^BLACK%^The dragon slashes you!%^RESET%^");
   targ->do_damage("torso", random(15)+10);
   tell_object(targ, "%^BOLD%^%^BLACK%^The dragon slashes you!%^RESET%^");
   targ->do_damage("torso", random(15)+10);
   return 1;
   }else{
   call_out("breathe",0);
   return 1;
   }
}
void rush(object targ) {
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   if(!fire) {
   tell_room(ETO, "%^BOLD%^%^WHITE%^Klauth lifts off with one powerful flap of his wings, then dives down on "+targ->query_cap_name()+"!%^RESET%^", targ);
   tell_object(targ, "%^BOLD%^%^WHITE%^Klauth lifts off with one powerful flap of his wings, then dives down on you!%^RESET%^");
   targ->do_damage("torso", random(200)+250);
   return 1;
   }else{
   call_out("breathe",0);
   return 1;
   }
}
void summon(object ob) {
   if(!fire) {
   tell_room(ETO, "%^BOLD%^%^BLACK%^Klauth spits out black mud onto the mountain top!");
   tell_room(ETO, "%^BOLD%^%^BLACK%^From the mud arises undead warriors to aid the dragon!");
    ob = new("/d/islands/common/mon/fallen")->move(ETO);
    ob = new("/d/islands/common/mon/fallen")->move(ETO);
    ob = new("/d/islands/common/mon/fallen")->move(ETO);
    ob = new("/d/islands/common/mon/fallen")->move(ETO);
    ob = new("/d/islands/common/mon/fallen")->move(ETO);
   return 1;
   }else{
   call_out("breathe",0);
   return 1;
   }
}
void earthquake(){
   if(!objectp(TO)) return;
   if(!fire) {
   object *vars;
   int i;
   vars = all_living(ETO);
    vars = filter_array(vars,"is_non_immortal_player",FILTERS_D);
   for(i=0;i<sizeof(vars);i++){
      if(vars[i] == TO) continue;
      tell_object(vars[i],"%^RESET%^%^ORANGE%^The dragon jumps up and lands hard on the mountain, causing a violent rumble%^RESET%^!");
	  if(!"/daemon/saving_throw_d"->reflex_save(vars[i],-35)) {
         tell_object(vars[i],"%^BOLD%^%^RED%^The rumble sends you flying to the ground!%^RESET%^");
//         vars[i]->set_tripped(25,"%^BOLD%^%^BLUE%^You are shaken and trying to regain your footing!%^RESET%^"); //way too high for round-based trip timer. N, 4/11.
         vars[i]->set_tripped(3,"%^BOLD%^%^BLUE%^You are shaken and trying to regain your footing!%^RESET%^",3);
}else{
         tell_object(vars[i],"%^BOLD%^%^RED%^The rumble only causes you to loose your balance for a moment!%^RESET%^");
//         vars[i]->set_tripped(7,"%^BOLD%^%^BLUE%^You are shaken and trying to regain your footing!%^RESET%^"); //way too high for round-based trip timer. N, 4/11.
         vars[i]->set_tripped(1,"%^BOLD%^%^BLUE%^You are shaken and trying to regain your footing!%^RESET%^",1);
      }
   }
   if(!exit){
	     ob = find_object_or_load("/d/islands/common/aramanth/mountain10");
         ob->remove_exit("top");
		 tell_room(ETO,"%^BOLD%^%^RED%^The violent rumbling causes rocks to split apart and tumble down!!!%^RESET%^");
tell_room(ETO,"The stairs leading up are suddenly covered in rubble.");
         exit = 1;
      }
   }else{
   call_out("breathe",0);
   return 1;
   }
}

void warning1() {
    tell_room(ETO,"%^RESET%^%^RED%^Klauth's eyes roll back in his head as he spits a dark ball of fire into the sky.");
    message("info","%^RESET%^%^RED%^The sky turns scarlet red and the clouds begin to bleed fire!",
    users());
    exit = 0;
	call_out("warning2",(random(15))+5);
	earthquake();
}

void warning2() {
    tell_room(ETO,"%^BOLD%^%^BLACK%^The ball of fire reaches its pinnacle and explodes.");
    message("info","%^BOLD%^%^BLACK%^Tears of %^RESET%^%^MAGENTA%^black lightning%^BOLD%^%^BLACK%^ falls from the heavens!",
    users());
    call_out("warning3",(random(15))+5);
}

void warning3(){
    message("info","%^BOLD%^%^RED%^The sky rips open and %^BOLD%^%^BLACK%^something%^BOLD%^%^RED%^ finds its way through!",
    users());
    tell_room(ETO,"%^RESET%^%^RED%^The unstoppable pit fiend is on its way.");
    call_out("doom",(random(15))+10);
}

void doom() {
    tell_room(ETO,"%^BOLD%^%^BLACK%^Qualtatoth %^BOLD%^%^RED%^IS HERE!!!");
    message("info","%^BOLD%^%^RED%^The whole world shakes as %^BOLD%^%^BLACK%^it%^BOLD%^%^RED%^ arrives...",
    users());
    ob = new("/d/islands/common/mon/fiend")->move(ETO);
}

void heart_beat() {
    int i;
    string printme;
    object thatroom;
    ::heart_beat();
    if(!objectp(TO)) return;
    if((int)TO->query_hp() < 18500) TO->add_hp(random(90)+90);
    if(!active && sizeof(query_attackers())) {
      active = 1;
      fighterz = ({});
      fighterz += filter_array(all_living(ETO),"is_non_immortal_player",FILTERS_D);
      if(sizeof(fighterz)) printme = fighterz[0]->query_name();
      if(sizeof(fighterz) > 1) {
        for(i=1;i<sizeof(fighterz);i++) printme += ", "+fighterz[i]->query_name();
      }
      log_file("klauth", "Fight commenced at "+ctime(time())+" by "+printme+".\n");
    }
    if(active) {
      if(!sizeof(query_attackers())) {
        active = 0;
        fighterz = ({});
        call_out("reset_fire",0);
        thatroom = find_object_or_load("/d/islands/common/aramanth/mountain10");
        if(member_array("top",thatroom->query_exits()) == -1)
          thatroom->add_exit("/d/islands/common/aramanth/mountain11","top");
        tell_room(thatroom,"%^CYAN%^Some mighty force from within the mountaintop sends the heaped stones flying, "
"revealing an entry to a lair at the very peak.");
      }
    }
}

void reset_fire(object targ) {
   if(!objectp(TO)) return;
   if(!objectp(targ)){
      if(!fire) {
         fire = 1;
      }
   }	  
}

void die(object ob) {
    object *ppl, destroom;
    string fighterztwo, printme;
    int i;
    string queststring;

    message("info","%^BOLD%^%^RED%^A mighty roar follows the rumble of the earth as Klauth has fallen from his mountain!%^RESET%^",users());
    
    //queststring = "%^BOLD%^%^RED%^Defeated the great red wyrm Klauth!%^RESET%^";
    ppl = ({});
    for(i=0;i<sizeof(fighterz);i++) {
        if(!objectp(fighterz[i])) { continue; }
      if(interactive(fighterz[i])) {
        ppl += ({ fighterz[i] });
       // if(member_array(queststring,fighterz[i]->query_mini_quests()) == -1) {
        //  fighterz[i]->set_mini_quest(queststring,1000000,queststring);
         // tell_object(fighterz[i],"\n%^BOLD%^%^RED%^A thrilling sense of accomplishment runs through you as you realise "
//"the great red wyrm Klauth has fallen to your hand!%^RESET%^\n");
       // }
      }
    }
    if(sizeof(ppl)) {
      fighterztwo = ({});
      for(i = 0;i<sizeof(ppl);i++) {
        fighterztwo += ({ (string)ppl[i]->query_name() });
        if(!i) printme = (string)ppl[i]->query_name();
        else printme += ", "+(string)ppl[i]->query_name();
      }
      log_file("klauth", "Slain at "+ctime(time())+" by "+printme+".\n");
    }
    destroom = find_object_or_load("/d/islands/common/aramanth/treasurevault");
    tell_room(ETO,"At the death of the dragon, a portal opens up, leading elsewhere, but it looks unstable as if it will close at any time.");
    ETO->add_exit("/d/islands/common/aramanth/treasurevault","portal");
    destroom->activate_lewt();
   ::die();
}
