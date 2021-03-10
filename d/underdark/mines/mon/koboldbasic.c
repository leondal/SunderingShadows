//Octothorpe (1/5/09)
//Underdark Mining Caverns, Kobold Master Inherit

#include <std.h>
#include "../defs.h"
inherit MONSTER;

void create(){
   object ob;
   object ob1;
   ::create();
   set_id(({"kobold"}));
   set_name("kobold grunt");
   set_short("%^RESET%^%^ORANGE%^sh%^RESET%^i%^ORANGE%^fty-eyed kobold%^RESET%^");
   set_long("%^ORANGE%^This scrawny creature barely reaches above three "+
      "feet in height. Its scaly skin is a %^BOLD%^%^BLACK%^d%^RESET%^ir"+
      "%^BOLD%^%^BLACK%^ty %^RESET%^%^ORANGE%^brown color, and is "+
      "partially clothed in a simple vest and dungarees. Unfortunately "+
      "for any non-kobolds though, their stench is hardly as simple as "+
      "their clothing. It is best described as a cocktail of a stagnant "+
      "pool of water and wet dogs, but in this case, this kobold smells "+
      "more like a dead dog in stagnant water. Its dark %^RED%^red "+
      "%^ORANGE%^eyes gleam with sinister intent.%^RESET%^");
   set_race("kobold");
   set_body_type("human");
   set_gender("male");
   set_alignment(3);
   set_size(1);
   set_class("thief");
   add_search_path("/cmds/thief");
   set_hd(24,random(2)+4);
   set_guild_level("thief",24);
   set_mlevel("thief",24);
   set_max_hp(random(50)+175);
   set_hp(query_max_hp());
   set_stats("strength",18);
   set_stats("dexterity",22);
   set_stats("constitution",12);
   set_stats("intelligence",9);
   set_stats("wisdom",11);
   set_stats("charisma",8);
   set_property("full attacks",1);
   set_property("swarm",1);
   set_new_exp(17,"normal");
   set_max_level(20);
   set_overall_ac(-8);
   set_wielding_limbs(({"left hand","right hand"}));
   ob = new("/d/newbie/rooms/forest/stuff/kobvest");
   ob->move(TO);
   ob->set_property("monsterweapon",1);
   command("wear vest");
   ob1 = new("/d/newbie/obj/weapons/sdagger");
   ob1->move(TO);
   ob1->set_property("monsterweapon",1);
   ob1->set_property("enchantment",3);
   command("wield dagger");
   add_money("copper", random(800)+50);
   set("aggressive",6);
   set_moving(1);
   set_scrambling(1);
   set_speed(70);
   set_skill("stealth",17);
   set_skill("athletics",17);
   set_func_chance(10);
   set_funcs(({"helpme"}));
//fixed a typo that resulted in garbled language ~Circe~ 7/24/19
   force_me("speak undercommon");
   add_attack_bonus(1);
   set_monster_feats(({
      "dodge",
	  "evasion",
	  "mobility",
	  "scramble",
	  "spring attack"
   }));
}

//stolen from kobchamp.c in the same folder
//as another function for them if theres
//already enough kobolds here - Saide
void flashit(object targ)
{
	if(!objectp(targ)) return;
   	if(!objectp(TO)) return;
   	TO->force_me("flash "+targ->query_name());
}


void helpme(object targ)
{
	object obx;
	object oby;
	//added to prevent everything from going nuts - 
	//was a group of 45 in one room :P - Saide
	if(present("kobold 6", ETO)) 
	{
		return flashit(targ);
	}
   	TO->force_me("say Eeeek! Dey be too strongs, git mar tails 'n 'ere quicks!");
   	tell_room(ETO,"%^ORANGE%^The sound of scampering claws becomes "+
      "louder as some draconic backup enters the area.%^RESET%^");
   	obx = new(MON+"koboldbasic");
   	obx->move(ETO);
   	TO->add_follower(obx);
   	TO->add_protector(obx);
   	if(!random(10) && !present("kobold 6", ETO))
	{
      	oby = new(MON+"kobchamp");
	      oby->move(ETO);
	  	TO->add_follower(oby);
	  	TO->add_protector(oby);
   	}
}

//Adapted from Grazzt's goblins, query_invis suggestion from Nienne
void init(){
   string mname=TP->query_name();
   string mrace=TP->query_race();
   ::init();
   if(TP->query_invis()) return;
   if(mrace == "gnome" || mrace == "svirfneblin" || mrace == "halfling" || mrace == "elf" || mrace == "hook horror" || mrace == "dwarf"){
      if(!random(3)) command ("stab "+TPQN); //reduced chance as they were killing a 4-player group without even getting past initial stabs. N, 3/11
   }
   if(present("gldstr",TP)){
      command ("kill "+TPQN);
   } 
/*   if(mname == "kobold kommando"){ //put on hold as this cound potentially stack up indefinitely... N, 3/11
      add_attack_bonus(query_attack_bonus()+1);
   }*/
}
