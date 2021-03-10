#include <std.h>
#include "../deep_echo.h"
inherit MONSTER;

void create (){

::create ();
   set_name("Ogre Mage");
   set_id(({"ogre","Ogre","ogremage","ogre mage"}));
   set_short("ogre-mage");
   set_long("This creature's large frame is"
   " covered in a putrid green colored skin.  His tiny beady eyes are"+
   " black with"+
   " pure white pupils.  His"+
   " ivory horns jut out of the top of his head,"+
   " and serve to contrast his jet-black teeth"+
   " and claws.  "+
   "His muscles are huge and out of proportion, giving him"+
   " a bulky, deformed look.  By the way he carries himself though,"+ 
   " he's quite powerful.");
   set_race("ogre-mage");
   set_gender("male");
   set_body_type("human");
   set_overall_ac(0);
   set_hd(15,2);
   set_size(3);
   set_property("swarm",1);
   set_stats("intelligence",20);
   set_stats("strength",18);
   set_stats("wisdom",10);
   set_stats("dexterity",13);
   set_stats("constitution",18);
   set_stats("charisma",4);
   set_money("gold",random(190));
   set_class("mage");
   set_hp(random(100)+150);
   set_max_hp(query_hp());  
   //set_exp(5000);
   set_new_exp(15,"normal");
   set_base_damage_type("bludgeoning"); 
   set_alignment(9);
   set("aggressive",19);
   set_mlevel("mage",16);
   set_guild_level("mage",16);
   if(random(2)==0)set_spells(({"ray of enfeeblement","ball lightning","acid breath",}));
   else set_spells(({"gust of wind","hold person","acid orb",}));
   
   set_mob_magic_resistance("average");
   set_achats(5, ({"The ogre-mage sneers at you and continues his attack.",
   "Ogre-mage drools and grins at you hungrily.",
   "Ogre-mage laughs evily.",}) );
   if(random(3)==1){
     new(OBJ"bchain")->move(TO);
	 force_me("wield chain");
	 set_spell_chance(80);
	}
	else if(!random(3)){
	  new(OBJ"psibane")->move(TO);
	 force_me("wield psibane");
	 set_spell_chance(80);
	}
	else set_spell_chance(95);
}
