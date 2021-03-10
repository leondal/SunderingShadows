//Octothorpe (12/12/09)
//Attaya, Phantom Solstice Warrior
//Original by Thundercracker

#include <std.h>
#include "../defs.h"
inherit MONSTER;

void create() {
   object ob1, ob2;
   ::create();
   set_name("solstice warrior");
   set_id(({"solstice warrior","warrior","shadow","solstice","phantom"}));
   set_short("%^BOLD%^%^BLACK%^h%^BOLD%^%^WHITE%^a%^RESET%^z%^BOLD%^"+
      "%^BLACK%^y phantom warrior%^BOLD%^%^RED%^");
   set_long("%^BOLD%^%^BLACK%^This h%^BOLD%^%^WHITE%^a%^RESET%^z"+
      "%^BOLD%^%^BLACK%^y shadow is all that remains of a member of "+
	  "the ancient Order of the Divine Solstice.  Formerly tasked to "+
	  "serve as personal bodyguard of the just Kinnesarudan kings of "+
	  "old, this fallen solstice warrior haunts his old homeland, "+
	  "protecting it now from the living.  Composed entirely of "+
	  "negative energy, this man-sized entity is devoid of any "+
	  "distinguishing marks or features from its past life, and is "+
	  "able to entirely fade from view at will.  Curiously, it is "+
	  "still able to use weapons on this plane, wielding two wicked "+
	  "daggers in each hand.%^RESET%^");
   set_race("undead");
   set_body_type("human");
   set_gender("male");
   set_size(2);
   set_alignment(9);
   set_class("thief");
//   set_class("assassin");
// assassin things were glitching the game. Removed til we get a PrC
   set_level(36);
   set_hd(36,10);
   set_overall_ac(-10);
   set_guild_level("thief",36);
//   set_guild_level("assassin",36);
   set_mlevel("thief",36);
//   set_mlevel("assassin",36);
   set_max_hp(275);
   set_hp(query_max_hp());
   set_wielding_limbs(({"right hand","left hand"}));
   set_property("swarm",1);
   set_property("no_bump",1);
   set_property("magic",1);
   set_stats("strength",25);
   set_stats("dexterity",23);
   set_stats("constitution",17);
   set_stats("wisdom",7);
   set_stats("intelligence",7);
   set_stats("charisma",3);
   set_thief_skill("move silently",95);
   set_thief_skill("hide in shadows",95);
   set_property("assassin",1);
   add_search_path("/cmds/thief");
   add_search_path("/cmds/assassin");
   add_damage_bonus(2+random(9));
   add_attack_bonus(2+random(9));
   //set("aggressive",25);
   set_mob_magic_resistance("average");
   set_exp(24000);
   set_max_level(36);
   ob1 = new(OBJ"screamer");
   ob1->set_property("monsterweapon",1);
   ob1->move(TO);
   command("wield dagger in right hand");
   ob2 = new(OBJ"screamer");
   ob2->set_property("monsterweapon",1);
   ob2->move(TO);
   command("wield dagger in left hand");
   set_invis();
   set_funcs(({"fire","kdit"}));
   set_func_chance(15);
   set_scrambling(1);
   set_skill("stealth",40);
   set_skill("athletics",40);
   set_moving(1);
   set_speed (20);
   command("speak wizish");
   command("speech %^BOLD%^%^BLACK%^whisper");
   set_monster_feats(({
      "ambidexterity",
      "whirl",
	  "two weapon fighting",
	  "improved two weapon fighting",
	  "greater two weapon fighting",
	  "two weapon defense",
	  "dodge",
	  "evasion",
	  "mobility",
	  "scramble",
	  "spring attack",
	  "expertise",
	  "knockdown",
	  "unassailable parry",
	  "combat reflexes"
   }));
      set_resistance("negative energy",20);
      set_resistance("positive energy",-20);
}

void init()
{
    string mrace;
    if(!objectp(TO) || !objectp(TP)) return;
    mrace = TP->query_race();
   ::init();
   if(!objectp(TO)) return;
   if(wizardp(TP)) return;
   if(TP->query_true_invis()) return;
   if(mrace == "undead"){
	  command("say %^RED%^Hail, brother.%^RESET%^");
	  return;
   }
   command("say %^RED%^Ancient spirits of the Kinnesaruda...guide "+
      "my hand in vengeance against this invader!%^RESET%^");
   command("say %^RED%^ Death to all who oppose us!%^RESET%^");
   if(objectp(TP)) command("stab "+TPQN);
   if(objectp(TO) && objectp(TP)) { TO->force_me("crit "+TPQN); }
}

void die(object ob){
   object ob3;
   tell_room(ETO,"%^BOLD%^%^YELLOW%^There is a brilliant flash of "+
      "light that blinds you momentarily!%^RESET%^");
   if(!random(5)){
      ob3 = new(OBJ"screamer");
      ob3->move(ETO);
   }
   TO->move("/d/shadowgate/void");
   TO->remove();
}

void fire(object targ){
   string dam;
   if(!objectp(TO)) return;
   if(!objectp(targ)) return;
   if(!"/daemon/saving_throw_d.c"->fort_save(targ,-26)){
      dam="hurt";
   }
   else{
	  dam="singe";
   }
   tell_object(targ,"%^BOLD%^The solstice warrior begins to glow a "+
	  "bright %^BOLD%^%^RED%^red%^BOLD%^%^WHITE%^, and phantom %^RESET%^"+
	  "%^RED%^f%^ORANGE%^l%^YELLOW%^a%^BOLD%^m%^RED%^"+
      "e%^RESET%^%^RED%^s %^BOLD%^%^WHITE%^flash about you and "+
	  ""+dam+ " you!%^RESET%^");
   tell_room(ETO,"%^BOLD%^The solstice warrior begins to glow a bright "+
      "%^BOLD%^%^RED%^red%^BOLD%^%^WHITE%^, and phantom %^RESET%^"+
	  "%^RED%^f%^ORANGE%^l%^YELLOW%^a%^BOLD%^m%^RED%^e%^RESET%^%^RED%^s "+
	  "%^BOLD%^%^WHITE%^flash around "+targ->QCN+"!%^RESET%^",targ);
   set_property("magic",1);
   if(dam=="singe"){
	  targ->do_damage("torso",random(100));
	  tell_object(targ,"%^YELLOW%^You are blinded by a brilliant "+
	     "light and intense heat!%^RESET%^");
	  targ->set_paralyzed(random(10)+15,"%^MAGENTA%^You cannot see "+
	     "your opponent and stumble around blindly!%^RESET%^");
   }
   else{
	  targ->do_damage("torso",random(120));
   }
   remove_property("magic");
   return 1;
}

void kdit(object targ){
   if(!objectp(TO)) return;
   if(!objectp(targ)) return;
   TO->force_me("knockdown "+targ->query_name());
}

void heart_beat() {
   int i,max;
   object ob;
   object here,*inv;

    ::heart_beat();

   if(!objectp(TO)) return;
   if(!objectp(ETO)) return;

   here = ETO;
   for(i=0, max = sizeof(inv=all_inventory(here)); i<max; i++){
      if(living(inv[i]) && !userp(inv[i]) &&(string)inv[i]->query_race()== "snake"){
         tell_room(ETO,"%^BOLD%^Your "+inv[i]->QCN+" explodes for no "+
		    "apparent reason!%^RESET%^");
		 inv[i]->remove();
	  }
   }
   if((int)TO->query_hp() < 275) {
      TO->add_hp(random(10)+1);
	  return;
   }
   else{
   return;
   }
}

int test_heart(){ return 1;}
