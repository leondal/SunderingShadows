//orccaptain.c - Updated by Circe 11/28/03
#include <std.h>
#include <daemons.h>
#include "/d/common/common.h";
inherit MONSTER;

int dlevel;

void create() {
object ob;
    	::create();
	set_name("orc captain");
    	set_id(({"orc","orc captain","captain","monster"}));
	set_race("orc");
	set_gender("male");
	set_short("A tall orc captain");
	set_long("A broad snout of a nose spreads across the gray skin of "+
         "this orc captain.  He has coarse black hair worn long and pulled back "+
         "into matted braids.  His low forehead and prominent lower canines give "+
         "him a boarish appearance despite his upright posture.  He wears simple "+
         "hide armor and wields a gruesome looking halberd, all covered with a ragged, "+
         "lice-infested cloak.");
      dlevel = random(3) + 10;
      set_class("fighter");
      set_level(dlevel);
	set_body_type("human");
  	set("aggressive",20);
  	set_alignment(3);
  	set_size(2);
   	set_stats("intelligence",4 + dlevel);
   	set_stats("wisdom",4);
   	set_stats("strength",6 + dlevel);
   	set_stats("charisma",1 + dlevel);
   	set_stats("dexterity",6 + dlevel);
   	set_stats("constitution",3 + dlevel);
     	set_hd(dlevel,8);
//      set_exp(dlevel *45);
      set_exp(dlevel *100);
   	set_max_hp(20+(dlevel * (random(10) + 3)));
   	set_hp(query_max_hp());
   	set_max_level(8);
	set_wielding_limbs( ({ "right hand", "left hand" }) );
        	new(CWEAP"halberd")->move(TO);
      	command("wield halberd");
        	new("/d/common/obj/armour/hide")->move(TO);
      	command("wear hide");
	add_money("silver",random(5) * dlevel);
	add_money("gold",random(10) * dlevel);
      ob = new("/d/shadow/obj/clothing/raggedcloak");
         if(random(3)){
            ob->set_property("monsterweapon",1);
         }
      ob->move(TO);
        	command("wear cloak");
}
