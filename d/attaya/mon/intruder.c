//Octothorpe (2/16/09)
//Attaya, Intruder
//Original by Thundercracker

#include <std.h>
#include <daemons.h>
#include "../defs.h"
inherit MONSTER;

object *weapon;
int stage = 0;

void create(){
   ::create();
   set_id(({"intruder","Intruder"}));
   set_name("intruder");
   set_short("%^WHITE%^Intruder, Warrior-General of the Kinnesaruda%^RESET%^");
   set_long("%^BOLD%^%^BLUE%^This undead entity reaches to the height "+
      "of eight feet, and appears to have the girth to match.  From "+
      "what little is not covered by armor, it would appear that he "+
      "is nothing more than a sentient skeletal undead.  Intruder's "+
      "%^WHITE%^bleached %^BLUE%^skull bears a %^BOLD%^%^BLACK%^"+
      "blackened %^BLUE%^mark on the forehead, the symbol of the "+
      "Kinnesaruda.  Dark %^RESET%^%^RED%^red %^BOLD%^%^BLUE%^flame "+
      "glows inside of the skull's eye sockets, flickering about in an "+
      "undulating manner.  He is armored in an impressive suit of "+
      "%^RESET%^%^YELLOW%^g%^ORANGE%^o%^YELLOW%^ld%^ORANGE%^e%^YELLOW%^"+
      "n %^BOLD%^%^BLUE%^plate constructed out of thousands of half-"+
      "inch squares.  An exquisite set of broad, %^WHITE%^s%^RESET%^i"+
      "%^BOLD%^lv%^RESET%^e%^BOLD%^r%^RESET%^y %^BOLD%^%^BLUE%^"+
      "shoulderplates completes his suit of full plate armor.%^RESET%^");
   set_race("undead");
   set_body_type("human");
   set_gender("male");
   set_alignment(3);
   set_size(2);
   set_class("fighter");
   set_class("mage");
   set_mlevel("fighter",70);
   set_mlevel("mage",70);
   set_skill("perception",55);
   set_guild_level("fighter",70);
   set_guild_level("mage",70);
   add_search_path("/cmd/fighter");
   add_search_path("/cmd/mage");
   set_hd(70,20);
   set_spells(({
      "cone of cold",
	  "frost orb",
	  "ghoul touch",
	  "blindness",
	  "frost orb",
	  "bestow curse",
	  "ray of enfeeblement",
	  "touch of idiocy",
	  "stormbolts", //correcting a typo here, was strombolts Odin 12/17/20
   }));
   set_spell_chance(75);
   set_stats("strength",25);
   set_stats("constitution",25);
   set_stats("dexterity",15);
   set_stats("charisma",19);
   set_stats("intelligence",20);
   set_stats("wisdom",19);
   set_max_hp(13500);
   set_hp(query_max_hp());
   set_overall_ac(-20);
   set_exp(1000000);
   set_mob_magic_resistance("extremely low");
   set_property("spell penetration",50);
   set_property("weapon resistance",4);
   set_property("full attacks",1);
   set_property("damage resistance",20);
   set_property("no paralyze", 1);
   set_property("no knockdown", 1);
   set_property("no death",1);
   set_property("no dominate",1);
   set_property("no bows",1);
   set_property("no hold", 1);
   set_property("no tripped", 1);
   set_property("swarm",1);
   set_skill("perception",50);
   command("speak wizish");
   command("speech snarl in a gutteral tone");
   set("aggressive","aggfunc");
   set_funcs(({
      "whistle",
	  "rushit",
	  "whistle",
	  "kdit",
	  "pwnit",
	  "flashit",
	  "impaleit",
	  "whistle",
	  "sweepit",
	  "dazeit",
	  "shatterit",
	  "sunderit"
   }));
   set_monster_feats(({
      "toughness",
	  "improved toughness",
	  "damage resistance",
	  "improved damage resistance",
	  "regeneration",
      "rush",
	  "sweepingblow",
	  "blade block",
	  "impale",
	  "light weapon",
	  "strength of arm",
	  "knockdown",
      "powerattack",
      "expertise",
      "daze",
      "shatter",
      "sunder"
   }));
   set_func_chance(60);
   new(OBJ"phantasmic_plate")->move(TO);
   command("wear armor");
   new(OBJ"shoulderplates")->move(TO);
   command("wear shoulderplates");
   new(OBJ"bonestripper")->move(TO);
   command("wield bonestripper");
      set_resistance("negative energy",20);
      set_resistance("positive energy",-20);
}

void heart_beat()
{
    ::heart_beat();
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!sizeof(TO->query_attackers()))
    {
        TO->set_hp((int)TO->query_max_hp());
        return;
    }
    if (!sizeof(TO->query_wielded())){
      command("wield bonestripper");
    }
}

void init(){
   ::init();
   add_action("no_rush","caress");
   add_action("no_rush","toss");
   add_action("no_rush","throw");
}

int no_rush(string str){
   force_me("say %^RED%^Your pathetic attack is no match for my "+
      "power, "+TP->QCN+".%^RESET%^");
   tell_object(TP,"%^BOLD%^Thousands of %^YELLOW%^gl%^WHITE%^o"+
      "%^YELLOW%^wing %^WHITE%^particles radiate out from Intruder "+
      "and slam into you!%^RESET%^");
   tell_room(ETO,"%^BOLD%^Thousands of %^YELLOW%^gl%^WHITE%^o"+
      "%^YELLOW%^wing %^WHITE%^particles radiate out from Intruder "+
      "and slam into "+TP->QCN+"!%^RESET%^",TP);
   TP->do_damage(TP->return_target_limb(),random(50)+100);
   return 1;
}

int pwnit(object targ){
   weapon = TO->query_wielded();
   if(!objectp(targ)) return 0;
   if(!objectp(TO)) return 0;
   if((weapon == ({}))) command("wield bonestripper");
   if(!"/daemon/saving_throw_d.c"->fort_save(targ,-25)){
      if(targ->query_property("no death")){
         tell_object(targ,"%^BOLD%^Intruder kicks you in the chest, "+
            "knocking you down to the ground, and then %^RESET%^%^RED%^"+
            "skewers %^BOLD%^%^WHITE%^you in the chest with his sword!");
         tell_room(ETO,"%^BOLD%^Intruder kicks "+targ->QCN+" in the chest, "+
            "knocking "+targ->QO+" down to the ground, and then %^RESET%^"+
            "%^RED%^skewers %^BOLD%^%^WHITE%^"+targ->QCN+" in the chest "+
            "with his sword!",targ);
         targ->do_damage(targ->return_target_limb(),random(100)+150);
         targ->set_tripped(1,"%^YELLOW%^You are trying to recover from being "+
            "skewered!");
         return(random(3)+1);
      }
      tell_object(targ,"%^BOLD%^Intruder kicks you in the chest, "+
         "knocking you down to the ground, and then %^RESET%^%^RED%^"+
         "skewers %^BOLD%^%^WHITE%^you in the chest with his sword!");
      tell_room(ETO,"%^BOLD%^Intruder kicks "+targ->QCN+" in the chest, "+
         "knocking "+targ->QO+" down to the ground, and then %^RESET%^"+
         "%^RED%^skewers %^BOLD%^%^WHITE%^"+targ->QCN+" in the chest "+
         "with his sword!",targ);
      targ->do_damage(targ->return_target_limb(),random(500)+1500);
      tell_object(targ,"%^BOLD%^Intruder's sword destroys your %^RESET%^"+
         "%^RED%^heart%^BOLD%^%^WHITE%^, killing you instantly!");
      return 1;
   }
}

void whistle(object targ){
   object ob;
   object obx;
   weapon = TO->query_wielded();
   if(!objectp(targ)) return 0;
   if(!objectp(TO)) return 0;
   if((weapon == ({}))) command("wield bonestripper");
   if(objectp(targ)){
      tell_room(ETO,"%^BOLD%^Intruder concentrates on a spot on the floor, "+
         "and grins as a %^BOLD%^%^BLACK%^dark %^BOLD%^%^WHITE%^form "+
         "begins to coalesce.%^RESET%^",TP);
      ob = new(MON"phalanx");
      ob->move(ETO);
      if(!random(5)){
         obx = new(MON"solstice");
         obx->move(ETO);
      }
   }
}

void aggfunc(object targ) {
   string mrace=TP->query_race();
   if(mrace == "undead"){
      return 1;
   }
   else {
      if(wizardp(TP)) return;
      tell_object(targ,"%^BOLD%^Intruder stands up from the throne "+
         "and walks toward you!%^RESET%^\n");
      tell_object(targ,"%^MAGENTA%^Intruder snarls in a gutteral "+
         "tone%^RESET%^: %^RED%^I have watched your approach, and for a "+
         "time, I actually considered sparing your worthless little "+
         "life.%^RESET%^\n");
      tell_object(targ,"%^MAGENTA%^Intruder yells%^RESET%^: %^RED%^"+
         "Death to all who oppose my power...I shall crush your "+
         "entrails beneath my heel!%^RESET%^\n");
      force_me("kill "+TPQN);
      force_me("watch");
      call_out("whistle",1);
   }
}

int die(object ob){
   object oba;
   object obb;

   if(stage == 0)
   {
      tell_room(ETO,"%^MAGENTA%^Intruder mutters raggedly%^RESET%^: %^RED%^Darkness beyond the void, heed my command! Bishimon! I give you another chance!%^RESET%^ \n");
      new(MON"bishimon")->move(ETO);
      stage = 1;
      TO->set_hp(query_max_hp() / 2);
      return 0;
   }
   if(stage == 1)
   {
      tell_room(ETO,"%^MAGENTA%^Intruder mutters raggedly%^RESET%^: %^RED%^Darkness beyond the void, heed my command! Ashtar! Prove your faith in battle!!%^RESET%^ \n");
      new(MON"ashtar")->move(ETO);
      stage = 2;
      TO->set_hp(query_max_hp() / 2);
      return 0;
   }
   if(stage == 2)
   {
      tell_room(ETO,"%^MAGENTA%^Intruder mutters raggedly%^RESET%^: %^RED%^Darkness beyond the void, heed my command! Volkerps! Release your rage!!%^RESET%^ \n");
      new(MON"volkerps")->move(ETO);
      stage = 3;
      TO->set_hp(query_max_hp() / 2);
      return 0;
   }
   if(stage == 3)
   {
      tell_room(ETO,"%^MAGENTA%^Intruder mutters raggedly%^RESET%^: %^RED%^Darkness beyond the void, heed my command! Io! Raise and prove that Icarus Empire are worthy ally!%^RESET%^ \n");
      new(MON"io")->move(ETO);
      stage = 4;
      TO->set_hp(query_max_hp() / 2);
      return 0;
   }

    if (!random(5)) {
        new("/d/common/obj/misc/tools/portable_smithy_bag.c")->move(TO);
    }


   tell_room(ETO,"Intruder drops to his knees and begins to laugh "+
      "mockingly. \n");
   tell_room(ETO,"%^BOLD%^As Intruder's undead existence ends, he "+
      "mutters one final chant.%^RESET%^ \n");
   tell_room(ETO,"%^MAGENTA%^Intruder mutters raggedly%^RESET%^: "+
      "%^RED%^Heed my command, ancient spirits of evil..."+
      "avenge me and plunge this world into eternal "+
      "darkness!%^RESET%^ \n");
   if((string)EVENTS_D->query_time_of_day() == "day"){
      message("info","%^BOLD%^%^BLACK%^Darkness descends over the realms "+
         "as a solar eclipse blots out the %^YELLOW%^sun%^BOLD%^%^BLACK%^!\n",users());
      ASTRONOMY_D->set_eclipse();
   }
   if((string)EVENTS_D->query_time_of_day() == "night"){
      message("info","%^BOLD%^%^BLACK%^The %^BOLD%^%^WHITE%^moon "+
         "%^BOLD%^%^BLACK%^disappears from the night sky suddenly!%^RESET%^\n",users());
   }
   tell_room(ETO,"%^BOLD%^Intruder's skeleton begins to crumble and "+
      "suddenly turns into a pool of %^RESET%^%^RED%^blood %^BOLD%^"+
      "%^WHITE%^that quickly flows towards the %^CYAN%^glowing "+
      "%^WHITE%^symbol on the floor...%^RESET%^ \n");
   obb = new("/d/dagger/drow/obj/blood");
   obb->move(ETO);
   tell_room(ETO,"%^BOLD%^A sudden rush of air fills the chamber, "+
      "and then a horrible entity begins to rise from the %^RESET%^"+
      "%^RED%^bloody %^BOLD%^%^WHITE%^symbol...%^RESET%^ \n");
   oba = new(MON"autarkis");
   oba->move(ETO);
   return ::die();
}

void kdit(object targ){
   weapon = TO->query_wielded();
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   if((weapon == ({}))) command("wield bonestripper");
   TO->force_me("knockdown "+targ->query_name());
}

void flashit(object targ){
   weapon = TO->query_wielded();
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   if((weapon == ({}))) command("wield bonestripper");
   TO->force_me("flash "+targ->query_name());
}

void rushit(object targ){
   weapon = TO->query_wielded();;
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   if((weapon == ({}))) command("wield bonestripper");
   TO->force_me("rush "+targ->query_name());
}

void impaleit(object targ){
   weapon = TO->query_wielded();
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   if((weapon == ({}))) command("wield bonestripper");
   TO->force_me("impale "+targ->query_name());
}

void sweepit(object targ){
   weapon = TO->query_wielded();
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   if((weapon == ({}))) command("wield bonestripper");
   TO->force_me("sweepingblow");
}

void dazeit(object targ){
   weapon = TO->query_wielded();
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   if((weapon == ({}))) command("wield bonestripper");
   TO->force_me("daze "+targ->query_name());
}

void shatterit(object targ){
   weapon = TO->query_wielded();
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   if((weapon == ({}))) command("wield bonestripper");
   TO->force_me("shatter "+targ->query_name());
}

void sunderit(object targ){
   weapon = TO->query_wielded();
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   if((weapon == ({}))) command("wield bonestripper");
   TO->force_me("sunder "+targ->query_name());
}
