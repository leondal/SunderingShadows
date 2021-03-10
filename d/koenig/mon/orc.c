//orc.c - Standard orcs for Koenig area.  Updated by Circe 9/14/03
#include <std.h>
inherit MONSTER;

int dlevel;

create() {
    	::create();
	set_name("orc");
	set_id(({"orc","young orc","monster"}));
	set_race("orc");
	set_gender("male");
	set_short("A young orc");
	set_long(
         "This young orc is fairly short, but stout.  His tusks "+
         "are just growing in from his lower jaw, but they are already "+
         "yellowing with poor care.  He wears dirty hides that have become "+
         "matted and are filled with a pungent stench of decay.  In his "+
         "gnarled hand is a ill-made dagger, but he seems capable of "+
         "defending himself well enough.");
	dlevel = random(3) + 6;
      set_class("fighter");
	set_level(dlevel);
      set_mlevel("fighter",dlevel);
	set_body_type("human");
  	set("aggressive",20);
  	set_alignment(3);
  	set_size(2);
   	set_stats("intelligence",6 + dlevel);
   	set_stats("wisdom",4 + dlevel);
   	set_stats("strength",10 + dlevel);
   	set_stats("charisma",3 + dlevel/2);
   	set_stats("dexterity",8 + dlevel);
   	set_stats("constitution",7 + dlevel);
	set_hd(dlevel,8);
//   	set_exp(dlevel * 35);
	set_exp(dlevel * 100);
   	set_max_hp(20+(dlevel * (random(10) + 1)));
   	set_hp(query_max_hp());
   	set_max_level(7);
	set_wielding_limbs( ({ "right hand", "left hand" }) );
        	new("/d/common/obj/weapon/dagger")->move(TO);
      	command("wield dagger");
        	new("/d/common/obj/armour/hide")->move(TO);
      	command("wear hide");
	add_money("silver",random(5) * dlevel);
	add_money("copper",random(10) * dlevel);
    	set_emotes(1,({
		"Orc looks around quickly.",
		"Orc scratches himself absentmindedly.",
		"Orc eyes you warily.",
		"Orc sniffs the air.",
		"Orc checks his gear.",
		"Orc counts his coins eagerly."
    	}),0);
}
