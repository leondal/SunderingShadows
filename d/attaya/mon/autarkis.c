//Octothorpe (4/6/09)
//Attaya, Autarkis
//Original by Thundercracker

#include <std.h>
#include <daemons.h>
#include "../defs.h"
inherit WEAPONLESS;
object ob;
int Timer;

void create(){
   ::create();
   set_name("autarkis");
   set_id(({"autarkis","demon","abyssal lord","lord","abyssal","demon lord"}));
   set_short("%^BOLD%^%^BLACK%^Autarkis, Abyssal Lord of A%^RESET%^i"+
      "%^BOLD%^%^BLACK%^r and D%^RESET%^a%^BOLD%^%^BLACK%^rkness"+
      "%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^This being is both hideous and "+
      "impressive at the same time, most likely being representative "+
      "of one of the most foul entities ever to grace the Prime Material "+
      "Plane. This demon is massively built, and towers up to a height "+
      "of almost fifteen feet. Autarkis's head is generally bovine "+
      "in nature, complete with two ragged horns, not unlike that of a "+
      "minotaur. Large, leathery wings sprout from its back, and "+
      "appear to be strong enough to support their host in flight, "+
      "as well as combat. The most striking feature of this demon "+
      "are the %^RESET%^%^RED%^bloodied %^BOLD%^%^BLACK%^blades "+
      "erupting from its forearms. As if these unusual blades were "+
      "not enough, unnaturally long talons are found instead of "+
      "fingertips on this demon's fingers.%^RESET%^");
   set_race("demon");
   set_body_type("human");
   add_limb("forearm-mounted blades","forearm-mounted blades",0,0,0);
   add_limb("left wing","left wing",0,0,0);
   add_limb("right wing","right wing",0,0,0);
   add_limb("spiked tail","spiked tail",0,0,0);
   add_limb("talons","talons",0,0,0);
   set_attack_limbs(({"talons","left wing","right wing","spiked tail","forearm-mounted blades"}));
   set_base_damage_type("piercing");
   set_damage(3,20);
   set_gender("male");
   set_alignment(9);
   set_size(3);
   set_class("fighter");
   set_class("mage");
   set_guild_level("fighter",70);
   set_guild_level("mage",70);
   set_mlevel("mage", 70);
   set_hd(70,20);
   set_max_hp(25000);
   set_hp(query_max_hp());
   set_overall_ac(-21);
   set_stats("strength",25);
   set_stats("dexterity",25);
   set_stats("constitution",22);
   set_stats("intelligence",21);
   set_stats("wisdom",17);
   set_stats("charisma",17);
   set_exp(1000000);
   set_property("spell invulnerability",6);
   set_mob_magic_resistance("average");
   set_property("spell penetration",50);
   set_property("spell damage resistance",33);
   set_property("weapon resistance",4);
   set_property("full attacks",1);
   set_property("no paralyze", 1);
   set_property("no knockdown", 1);
   set_property("no death",1);
   set_property("no dominate",1);
   set_property("no bows",1);
   set_property("no hold", 1);
   set_property("no tripped", 1);
   set_property("swarm",1);
   set_property("magic",1);
   set_skill("perception",50);
   set("aggressive","aggfunc");
   command("speak wizish");
   command("speech whisper breathlessly");
   set_funcs(({
      "fireball",
	  "poison",
	  "freeze",
	  "fire",
	  "annihilate",
	  "light",
	  "impaler",
	  "tornado",
	  "bolt",
	  "circle",
	  "desoul",
   }));
   set_func_chance(100);
   set_spells(({
               "darkness",
                   "hellball",
                   "storm of vengeance",
                   "fire storm"
   }));
   set_spell_chance(25);
   add_money("gold",20+random(100000));
   new(OBJ"aut_armor")->move(TO);
   command("wear armor");
   new(OBJ"lgauntlets")->move(TO);
   command("wear gauntlets");
   ob=new("/d/deku/armours/ring_p.c");
   ob->set_property("enchantment",5);
   ob->move(TO);
   command("wear ring");
   new(OBJ"aut_notpball")->move(TO);
   set_resistance("negative energy",20);
   set_resistance("positive energy",-20);
   Timer = 0;

}

void init(){
   ::init();
   add_action("no_rush","caress");
   add_action("no_rush","toss");
   add_action("no_rush","toss");
}

void die(object ob){
   object *attackers;
   int i;
   attackers = all_living(ETO);
   attackers = filter_array(attackers,"is_non_immortal_player",FILTERS_D);
//   if(sizeof(TO->query_attackers()) < 1) return; // this breaks autarkis- Uriel
   tell_room(ETO,"%^BOLD%^Autarkis spreads his wings, and his body "+
      "begins to harden.  Thousands of tiny holes open in his flesh "+
      "and brilliant %^YELLOW%^light %^WHITE%^speeds outward in all "+
      "directions!%^RESET%^ \n");
   tell_room(ETO,"%^BOLD%^Autarkis explodes in a fury of fire and "+
      "bone!%^RESET%^ \n");
   message("info","%^BOLD%^%^CYAN%^A massive shockwave originates deep "+
      "within the %^RESET%^%^GREEN%^jungles %^BOLD%^%^CYAN%^of Attaya "+
      "and spreads out over the realms obliterating all of the "+
      "%^WHITE%^clo%^RESET%^u%^BOLD%^ds %^BOLD%^%^CYAN%^in its path!%^RESET%^\n",users());
   tell_room(ETO, "%^CYAN%^After the explosion, a circular portal winks "+
      "into existance in front of the throne.%^RESET%^");
   ETO->add_exit("/d/attaya/firedock","portal");
   for(i=0;i<sizeof(attackers);i++){
      if(!objectp(attackers[i])) { continue; }
      if(member_array("Life force of the Kinnesaruda has faded, Intruder and Autarkis are defeated",attackers[i]->query_mini_quests()) == -1){
	     attackers[i]->set_mini_quest("Life force of the Kinnesaruda has faded, Intruder and Autarkis are defeated",100000,"%^BOLD%^%^BLACK%^Life force of the Kinnesaruda has faded, Intruder and Autarkis are defeated%^RESET%^");
      }
   }

    WORLD_EVENTS_D->inject_event((["A Demon Obliterated!" : (["start message" : "%^BOLD%^%^CYAN%^The power from the shockwave "+
    "washes over you.... bathing you in its light! You feel something ancient stirring deep within yourself and "+
    "%^BOLD%^%^YELLOW%^SUDDENLY%^BOLD%^%^CYAN%^ your ability to absorb information is magnified! For the next %^BOLD%^%^CYAN%^"+
    "four hours%^BOLD%^%^CYAN%^ all experience gained with award an additional %^BOLD%^%^CYAN%^25%^BOLD%^%^WHITE%^!%^RESET%^",
    "event type" : "exp bonus", "length" : 240, "notification" : "25% Bonus Exp",
    "event name" : "A Demon Obliterated!", "modifier" : 25, "announce" : 1, "announce to" : "world" ]),]));

   ::die(ob);
}

int no_rush(string str){
   force_me("say %^CYAN%^I don't think you realize the power that "+
      "you are facing, "+TP->QCN+".%^RESET%^");
   tell_object(TP,"%^BOLD%^Autarkis pulls out an ancient parchment "+
      "with a %^BOLD%^%^BLACK%^pentagram %^WHITE%^burned onto its "+
      "surface.  He presses it against your forehead, and a horrible "+
      "pain rips through your body!%^RESET%^");
   tell_room(ETO,"%^BOLD%^Autarkis pulls out an ancient parchment "+
      "and presses it against the forhead of "+TP->QCN+"!%^RESET%^",TP);
   TP->do_damage(TP->return_target_limb(),random(50)+100);
}

int aggfunc(){
   string mrace=TP->query_race();
   if(mrace == "undead"){
      return 1;
   }
   else {
      if(wizardp(TP)) return 1;
      force_me("kill "+TPQN);
      force_me("watch");
      force_me("say %^CYAN%^Direct intervention is necessary.%^RESET%^");
      force_me("emote rises from the %^RED%^bloody %^RESET%^symbol to "+
      "face you!");
      force_me("say %^CYAN%^You are the type of warriors that legends "+
         "would have been written about...if you ever had escaped here "+
         "alive.%^RESET%^");
      force_me("yell %^CYAN%^I shall destroy your very soul...witness "+
         "the power of a time forgotten!!!%^RESET%^");
      force_me("emote cackles evilly");
    }
}

void impaler(object targ){
   string dam;
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   if(!"/daemon/saving_d.c"->fort_save(targ,-25)){
      dam="hurts";
   }
   else{
      dam="impales";
   }
   tell_object(targ,"%^MAGENTA%^Autarkis charges towards you and "+
      ""+dam+ "you with his forearm-mounted blades!%^RESET%^");
   tell_room(ETO,"%^MAGENTA%^Autarkis charges with his forearm-"+
      "mounted blades and impales "+targ->QCN+"!%^RESET%^",targ);
   if(dam=="impales"){
      targ->do_damage("torso",roll_dice(30,10));
      tell_object(targ,"%^RED%^You feel intense pain and your abillity "+
         "to fight has been compromised!%^RESET%^");
   }
   else{
      targ->do_damage("torso",roll_dice(20,10));
   }
}

void annihilate(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   if(random(60) > targ->query_stats("intelligence")){
      tell_room(ETO,"%^BOLD%^%^BLACK%^Autarkis annihilates "+targ->QCN+" "+
         "with a foul incantation!%^RESET%^",targ);
      tell_object(targ,"%^BOLD%^%^BLACK%^A foul incantation rips through "+
         "you!%^RESET%^");
      targ->do_damage("torso",125+random(75));
      return;
   }
   else{
      tell_room(ETO,"%^BOLD%^%^CYAN%^Autarkis touches his talons to his "+
         "forehead and mutters a chant.%^RESET%^");
      TO->add_hp(500);
   }
}

void fire(object targ){
   string dam;
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   if(SAVING_D->saving_throw(targ,"spell")){
      dam="hurts";
   }
   else {
      dam="singes";
   }
   tell_object(targ,"%^YELLOW%^Autarkis begins to glow as phantom "+
      "%^ORANGE%^f%^BOLD%^%^RED%^i%^YELLOW%^r%^RESET%^%^RED%^e "+
      "%^YELLOW%^flares about you, and "+dam+" you!%^RESET%^");
   tell_room(ETO,"%^YELLOW%^Autarkis summons a conflagration of phantom %^ORANGE%^"+
      "f%^BOLD%^%^RED%^i%^YELLOW%^r%^RESET%^%^RED%^e %^YELLOW%^on "+
      ""+targ->QCN+"!",targ);
   if(dam=="singes"){
      targ->do_damage("torso",145+random(70));
      tell_object(targ,"%^YELLOW%^You are blinded by a brilliant light "+
         "and intense heat!%^RESET%^");
      targ->set_paralyzed(random(10)+15,"%^YELLOW%^You cannot see your "+
         "opponent and stumble around blindly!%^RESET%^");
   }
   else{
      targ->do_damage("torso",80+random(80));
   }
   return;
}

void circle(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   if(random(50) > targ->query_stats("intelligence")){
      tell_object(targ,"%^RED%^Autarkis stabs you in the back!%^RESET%^");
      targ->do_damage("torso", random(200)+50);
      return;
   }
   else{
      tell_object(targ,"%^BOLD%^Autarkis misses a backstab "+
         "attempt.%^RESET%^");
   }
}

void freeze(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   if(random(50) > targ->query_stats("wisdom")){
      tell_room(ETO,"%^BOLD%^Autarkis draws in the energy around him, "+
         "and congeals it into a dagger of %^CYAN%^i%^WHITE%^c%^CYAN%^e"+
         "%^BOLD%^%^WHITE%^.%^RESET%^");
      tell_room(ETO,"%^BOLD%^Autarkis rips into "+targ->QCN+" with the "+
         "%^CYAN%^i%^WHITE%^c%^CYAN%^e %^BOLD%^%^WHITE%^"+
         "dagger!%^RESET%^",targ);
      tell_object(targ,"%^BOLD%^Autarkis's dagger %^CYAN%^i%^WHITE%^"+
         "c%^CYAN%^e %^BOLD%^%^WHITE%^rips into you and the surrounding "+
         "blood freezes!%^RESET%^");
      targ->do_damage("torso",random(80)+40);
      targ->set_paralyzed(roll_dice(1, 2) * 4,"%^BOLD%^You are frozen "+
         "solid!%^RESET%^");
      return;
   }
   else{
      tell_room(ETO,"%^BOLD%^Autarkis loses his concentration while "+
         "attempting to draw in the energy around him.%^RESET%^");
   }
}

void fireball(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   if(random(75) > targ->query_stats("wisdom")){
      tell_room(ETO,"%^ORANGE%^Autarkis hurls a f%^BOLD%^%^RED%^i"+
         "%^YELLOW%^r%^RESET%^%^RED%^eb%^ORANGE%^a%^RED%^ll %^ORANGE%^"+
         "at "+targ->QCN+"!%^RESET%^",targ);
      tell_object(targ,"%^ORANGE%^Autarkis hurls a f%^BOLD%^%^RED%^i"+
         "%^YELLOW%^r%^RESET%^%^RED%^eb%^ORANGE%^a%^RED%^ll "+
         "%^ORANGE%^at you!");
      targ->do_damage("torso",random(150)+50);
      return;
   }
   else{
      tell_object(targ,"%^ORANGE%^%^Autarkis's f%^BOLD%^%^RED%^i"+
         "%^YELLOW%^r%^RESET%^%^RED%^eb%^ORANGE%^a%^RED%^ll %^ORANGE%^"+
         "speeds past you and slams into the %^BOLD%^%^BLACK%^obisd"+
         "%^RESET%^i%^BOLD%^%^BLACK%^an %^ORANGE%^wall in a shower "+
         "of %^YELLOW%^sp%^WHITE%^a%^YELLOW%^rks!%^RESET%^");
      tell_room(ETO,"%^ORANGE%^Autarkis hurls a f%^BOLD%^%^RED%^i"+
         "%^YELLOW%^r%^RESET%^%^RED%^eb%^ORANGE%^a%^RED%^ll %^ORANGE%^"+
         "at "+targ->QCN+" and misses!%^RESET%^",targ);
   }
}

void bolt(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   if(random(70) > targ->query_stats("wisdom")){
      tell_room(ETO,"%^BLUE%^Autarkis shoots %^YELLOW%^lightning "+
         "%^RESET%^%^BLUE%^from his talons and blasts "+targ->QCN+"!",targ);
      tell_object(targ,"%^BLUE%^Autarkis shoots %^YELLOW%^lightning "+
         "%^RESET%^%^BLUE%^from his talons and blasts you!");
      targ->do_damage("torso", random(120)+80);
      return;
   }
   else{
      tell_object(targ,"%^BLUE%^Autarkis shoots %^YELLOW%^lightning "+
         "%^RESET%^%^BLUE%^from his talons and it strikes all around you!"+
         "%^RESET%^");
      tell_room(ETO,"%^BLUE%^Autarkis shoots %^YELLOW%^lightning "+
         "%^RESET%^%^BLUE%^from his talons and it strikes all around "+
         ""+targ->QCN+"!%^RESET%^",targ);
      targ->do_damage("torso",random(60)+40);
   }
}

void tornado(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   if(random(25) > targ->query_stats("wisdom")){
      tell_room(ETO,"%^MAGENTA%^Autarkis kneels and touches his palms "+
         "against the floor.%^RESET%^");
      tell_room(ETO,"%^MAGENTA%^A tornado rises beneath "+
         ""+targ->QCN+"!%^RESET%^",targ);
      tell_object(targ,"%^MAGENTA%^A tornado rises beneath you and "+
         "thrusts you upwards against the %^BOLD%^%^BLACK%^obisd"+
         "%^RESET%^i%^BOLD%^%^BLACK%^an %^RESET%^%^MAGENTA%^"+
         "ceiling!%^RESET%^");
      targ->do_damage("torso", random(100)+25);
      return;
   }
   else{
      tell_room(ETO,"%^BOLD%^Autarkis kneels and touches his palms "+
         "against the floor.%^RESET%^");
      tell_room(ETO,"The ground begins to shake violently!");
      if(!random(10)){
         targ->force_me("drop all");
      }
   }
}

void light(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   if(random(50) > targ->query_stats("wisdom")){
      tell_room(ETO,"%^BOLD%^Autarkis thrusts his hands outwards, "+
         "then upwards.%^RESET%^");
      tell_room(ETO,"%^BOLD%^The %^BOLD%^%^BLACK%^shadows %^WHITE%^"+
         "compress to form a ball of %^BOLD%^%^BLACK%^dark %^BOLD%^"+
         "energy in his hands.%^RESET%^");
      tell_room(ETO,"%^BOLD%^Autarkis lowers his hands and blasts a "+
         "beam of %^BLACK%^dark %^WHITE%^energy at "+targ->QCN+"!"+
         "%^RESET%^",targ);
      tell_object(targ,"%^BOLD%^Autarkis lowers his hands and blasts "+
         "you with a beam of %^BOLD%^%^BLACK%^dark %^WHITE%^"+
         "energy!%^RESET%^");
      targ->do_damage("torso",random(200)+130);
      return;
   }
   else{
      tell_room(ETO,"%^BOLD%^Autarkis grabs "+targ->QCN+" by the "+
         "throat and slams "+targ->QO+" against the %^BOLD%^%^BLACK%^"+
         "obisd%^RESET%^i%^BOLD%^%^BLACK%^an %^WHITE%^wall!"+
         "%^RESET%^",targ);
      tell_object(targ,"%^BOLD%^Autarkis grabs you by the throat and "+
         "slams you against the %^BOLD%^%^BLACK%^obisd%^RESET%^i"+
         "%^BOLD%^%^BLACK%^an %^WHITE%^wall!%^RESET%^");
        targ->do_damage("torso",random(50)+100);
   }
}

void poison(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   if(random(50) > targ->query_stats("charisma")){
      tell_room(ETO,"%^GREEN%^Autarkis spreads his talons and %^RESET%^"+
         "%^RED%^slashes %^GREEN%^"+targ->QCN+" across the "+
         "chest!%^RESET%^",targ);
      tell_object(targ,"%^GREEN%^Autarkis spreads his talons and "+
         "%^RESET%^%^RED%^slashes %^GREEN%^you across the "+
         "chest!%^RESET%^");
      tell_object(targ,"%^BOLD%^%^BLACK%^You have been poisoned severely!%^RESET%^");
      targ->do_damage("torso",random(50)+42);
      targ->add_poisoning(100);
      return;
   }
   else{
      tell_object(targ,"%^BOLD%^Autarkis cleaves you with his forearm"+
         "-mounted blades!%^RESET%^");
      targ->do_damage("torso",random(100)+50);
      tell_room(ETO,"%^BOLD%^Autarkis cleaves "+targ->QCN+" with his "+
         "forearm-mounted blades.%^RESET%^",targ);
   }
}

void desoul(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   if(random(22) > targ->query_stats("constitution")){
      if(targ->query_property("no death")){
         tell_room(targ,"%^BOLD%^Autarkis calls to powers greater than "+
            "any you have ever known.%^RESET%^");
         tell_room(ETO,"Autarkis points to "+targ->QCN+"!",targ);
         force_me("say %^CYAN%^This is true power.%^RESET%^");
         tell_room(targ,"%^BOLD%^Autarkis's eyes glow %^RESET%^%^RED%^red "+
            "%^BOLD%^%^WHITE%^as he shrieks loudly!%^RESET%^");
         tell_object(targ,"%^BOLD%^%^RED%^Your soul has nearly "+
	        "been destroyed!%^RESET%^");
         //targ->set_hp(66);
         targ->set_hp(((int)targ->query_hp()/3));
         return;
      }
      tell_room(targ,"%^BOLD%^Autarkis calls to powers greater than "+
         "any you have ever known.%^RESET%^");
      tell_room(ETO,"Autarkis points to "+targ->QCN+"!",targ);
      force_me("say %^CYAN%^This is true power.%^RESET%^");
      tell_room(targ,"%^BOLD%^Autarkis's eyes glow %^RESET%^%^RED%^red "+
         "%^BOLD%^%^WHITE%^as he shrieks loudly!%^RESET%^");
      tell_object(targ,"%^BOLD%^%^RED%^Your soul has been destroyed!%^RESET%^");
      targ->set_hp(-10);
      return;
   }
   else{
      force_me("say %^CYAN%^My attacks will tear you apart.%^RESET%^");
      tell_object(targ,"%^GREEN%^Autarkis's talons slash about you "+
         "quickly, leaving trails of %^YELLOW%^light%^RESET%^"+
         "%^GREEN%^.%^RESET%^");
      tell_object(targ,"%^BOLD%^Autarkis %^RED%^slices %^WHITE%^your "+
         "flesh with quick talon strikes!");
      targ->do_damage("torso", random(15)+5);
      tell_object(targ,"%^BOLD%^Autarkis %^RED%^slices %^WHITE%^your "+
         "flesh with quick talon strikes!");
      targ->do_damage("torso", random(15)+5);
      tell_object(targ,"%^BOLD%^Autarkis %^RED%^slices %^WHITE%^your "+
         "flesh with quick talon strikes!");
      targ->do_damage("torso", random(15)+5);
      tell_object(targ,"%^BOLD%^Autarkis %^RED%^slices %^WHITE%^your "+
         "flesh with quick talon strikes!");
      targ->do_damage("torso", random(15)+5);
      tell_object(targ,"%^BOLD%^Autarkis %^RED%^slices %^WHITE%^your "+
         "flesh with quick talon strikes!");
      targ->do_damage("torso", random(15)+5);
      tell_object(targ,"%^BOLD%^Autarkis %^RED%^slices %^WHITE%^your "+
         "flesh with quick talon strikes!");
      targ->do_damage("torso", random(15)+5);
      tell_object(targ,"%^BOLD%^Autarkis %^RED%^slices %^WHITE%^your "+
         "flesh with quick talon strikes!");
      targ->do_damage("torso", random(15)+5);
      tell_object(targ,"%^BOLD%^Autarkis %^RED%^slices %^WHITE%^your "+
         "flesh with quick talon strikes!");
      targ->do_damage("torso", random(15)+5);
      tell_room(ETO,"%^BOLD%^Autarkis's talons %^YELLOW%^glow and he "+
         "furiously tears at "+targ->QCN+"!%^RESET%^",targ);
   }
}

void heart_beat()
{
    int i,max;
    object ob;
    object here,*inv;
    ::heart_beat();
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!sizeof(TO->query_attackers()))
    {
        Timer++;
        if(Timer > 600)
        {
            TO->move("/d/shadowgate/void");
            if(!objectp(TO)) TO->remove();
            return;
        }
    }
    else if(sizeof(TO->query_attackers()))
    {
        if((int)TO->query_hp() < (int)TO->query_max_hp()) TO->heal(roll_dice(4,20));
        if(Timer) Timer = 0;
    }
    here = ETO;
    for(i=0, max = sizeof(inv=all_inventory(here)); i<max; i++)
    {
        if(living(inv[i]) && !userp(inv[i]) && (string)inv[i]->query_race() == "snake")
        {
            tell_room(ETO,"Autarkis casts a spell on the "+inv[i]->QCN+"!");
            tell_room(ETO,"%^ORANGE%^The "+inv[i]->QCN+" crumbles into a "+
            "pile of dust and blows away!%^RESET%^");
            inv[i]->remove();
            return;
        }
    }
}
