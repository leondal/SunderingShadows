#include <std.h>
#include "../defs.h"
inherit MONSTER;
object ob;

void create() {
   ::create();
   set_name("Chrin");
   set_id(({"human","wererat","chrin","Chrin Clawreaper","Chrin"}));
   set_short("%^YELLOW%^Chrin Clawreaper%^RESET%^");
   set_long("%^RESET%^A man stands before you, and looks to be human upon first glance. "+ 
	   "He seems a bit short, as such things go. He has "+ 
	   "%^ORANGE%^b%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^ady b%^BOLD%^%^BLACK%^r%^RESET%^%^ORANGE%^own "+ 
	   "e%^BOLD%^%^BLACK%^y%^RESET%^%^ORANGE%^es %^WHITE%^that, judging on the way they %^BOLD%^glare "+ 
	   "%^RESET%^at you, are not happy to see you here, and a mop of %^ORANGE%^wild brown hair "+ 
	   "%^WHITE%^atop his head. A %^ORANGE%^scraggly moustache %^WHITE%^is nestled beneath a pointy "+ 
	   "nose that %^BOLD%^twitches %^RESET%^incessantly. He is thin and wiry, and is likely quite "+ 
	   "capable with that %^BOLD%^%^BLACK%^knife %^RESET%^and %^BOLD%^%^BLACK%^gun %^RESET%^he holds. "+ 
	   "One thing is for certain, he has no intentions of letting you move beyond this point, "+ 
	   "or even from escaping this place with your life.%^WHITE%^");
   set_class("fighter");
   set_guild_level("fighter",12);
   set_hd(11,5);
   set_race("wererat");
   set_body_type("human");
   set_gender("male");
   set_size(2);
   set("aggressive",25);
   set_gender("male");
   set_hd(20,8);
   set_alignment(6);
   set_max_hp(250);
   set_hp(250);
   set_overall_ac(2);
   set_size(2);
   set_new_exp(11,"boss");
   set_wielding_limbs(({"right hand","left hand"}));
   ob = new(OBJ"bluegun.c");
   ob->move(TO);
   command("wield pistol in right hand");
   ob = new(OBJ"lrpouch.c");
   ob->move(TO);
   set_property("full attacks",1);
   set_stats("strength",19);
   set_stats("constitution",19);
   set_stats("intelligence",14);
   set_stats("wisdom",12);
   set_stats("charisma",9);
   set_stats("dexterity",18);
   set_func_chance(45);
   add_money("gold",random(1000)+75);
   set("aggressive","aggfunc");
   set_funcs( ({ "manyshotit","shootit"}) );
   add_search_path("/cmds/fighter");
   set_monster_feats(({
	  "exotic weapon proficiency"
	  "deadeye",
	  "manyshot",
	  "preciseshot",
	  "point blank shot",
	  "swipe",        
	  "opportunistic parry",                
	  "opportunity strikes",                           
	  "positioning",                                        
	  "swipe",                                               
	  "true strikes",   
   }));
}

void aggfunc() {
    tell_room(ETO, "%^RESET%^%^MAGENTA%^Chrin snarls: %^BOLD%^You will not get past me.\n%^RESET%^");
    if(wizardp(TP)) return 1;
    call_out("force_me",1,"swipe "+TPQN+ "");
}

void manyshotit(object targ) {
   TO->force_me("manyshot");
}

void shootit(object targ) {
   TO->force_me("preciseshot "+targ->query_name());
}

void die(object ob){
	tell_room(ETO,"%^RESET%^%^ORANGE%^Chrin gives a final %^RESET%^snarl%^RESET%^%^ORANGE%^ before his body starts to twist and morph, shrinking into itself. Some of his belongings fall to the floor..%^RESET%^");
    tell_room(ETO,"%^YELLOW%^Where once stood a man is now only a %^RESET%^%^ORANGE%^giant rat%^YELLOW%^. It bares its %^RESET%^fangs%^YELLOW%^ at you before scurrying off through a crack in the wall.%^RESET%^");  
	TO->remove();
}