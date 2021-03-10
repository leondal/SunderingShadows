#include <std.h>
#include <daemons.h>
#include "secrets.h"
inherit MONSTER;

int dlevel;
object ob;


void create() {
	::create();
   set_name("gravelingus");
   set_id(({"monster","dwarf","dwarf supervisor","supervisor"}));
   set_short("Gravelingus, Dwarven Supervisor");
   set_long(
   	"%^RESET%^%^ORANGE%^"+
   	"The dwarf is covered in dust and dirt like "+
   	"he has recently come from an underground dig.  He "+
   	"is naked from the waist up, but his long red "+
   	"beard, chest hair, and back hair cover his torso as "+
   	"effectively as any shirt.  He wears simple leather "+
   	"breeches and low, hard, mud-covered boots.  His face "+
   	"and chest are cover with dirt, but he does not appear "+
   	"to have been sweating recently.  In addition to "+
   	"breeches he wears a simple leather cap with a "+
   	"%^BOLD%^gold emblem %^RESET%^%^ORANGE%^in the "+
   	"front and carries a hammer.");
   set_body_type("humanoid");
   dlevel = random(20) +20;
   set_hd(dlevel,10);
   set_class("fighter");
   set_mlevel("fighter", dlevel);
   set_wielding_limbs(({"right hand","left hand"}));
   set_alignment(5);
   set_race("dwarf");
   set_gender("male");
   set_overall_ac(5);
   set_stats("strength",18);
   set_stats("dexterity",17);
   set_stats("intelligence",13);
   set_stats("wisdom",16);
   set_stats("charisma",9);
   set_stats("constitution",19);
   set_exp(dlevel*50);
   set_max_hp((random(100)+(dlevel*10)));
   set_hp(query_max_hp());
   	ob = new( "/d/common/obj/weapon/hammer_sm.c" );
     	ob->set_property("monsterweapon", 1);
     	ob->set_property("enchantment",4);
   	ob->move(TO);
    	command("wield hammer");
  	new(SARADIN+"dnote")->move(TO);
  	new(SARADIN+"cnote")->move(TO);
  	new("/d/shadow/obj/misc/pouch.c")->move(TO);
  		command("wear pouch");
  		command("put note in pouch");
  		command("put note in pouch");
   command("speak common");
   command("speech %^RESET%^%^ORANGE%^growl");
   set_property("full attacks",1);
   add_search_path("/cmds/fighter");
   set_max_level(25);
  	set_size(1);
	set_property("knock unconscious",1);
  	add_money("silver",(dlevel*30));
  	add_money("gold",(dlevel*10));
  	add_money("copper",(dlevel*50));
  	add_money("electrum",(dlevel*20));
}