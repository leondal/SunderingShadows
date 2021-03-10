#include <std.h>
#include <daemons.h>
#include "/d/common/common.h";
inherit MONSTER;
int dlevel;

create() {
    ::create();
	set_name("orc");
	set_id(({"orc","guard","orc guard","young orc","young orc guard"}));
	set_race("orc");
	set_gender("male");
	set_short("A young orc guard");
	set_long("This young orc seems to be some sort of guard.  He moves with "+
         "a cautious look in his eyes, which are set deep within a mottle gray "+
         "face.  He looks something like a pig, with small tusks and a low forehead "+
         "complete with a broad snout.  He has a battered and filthy sheath on his "+
         "back which clearly houses the two-handed sword he now wields.  His hide "+
         "armor is in slightly better shape than most of the other orcs', but he "+
         "still reeks and clearly could use a bath.");
	dlevel = random(3) + 6;
      set_class("fighter");
	set_level(dlevel);
	set_body_type("human");
  	set("aggressive",20);
  	set_alignment(3);
  	set_size(2);
   	set_stats("intelligence",6);
   	set_stats("wisdom",4);
   	set_stats("strength",10 + dlevel);
   	set_stats("charisma",3);
   	set_stats("dexterity",8 + dlevel);
   	set_stats("constitution",7 + dlevel);
	set_hd(dlevel, 8);
//      set_exp(dlevel * 40);
      set_exp(dlevel * 100);
   	set_max_hp(20+(dlevel * (random(10) + 1)));
   	set_hp(query_max_hp());
   	set_max_level(7);
	set_wielding_limbs( ({ "right hand", "left hand" }) );
        	new(CWEAP"bastard_two")->move(TO);
      	command("wield sword");
        	new("/d/common/obj/armour/hide")->move(TO);
      	command("wear hide");
	add_money("silver",random(5) * dlevel);
	add_money("copper",random(10) * dlevel);

}
