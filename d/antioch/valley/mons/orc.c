//updating the old files to use the new exp functions for standardized
//exp values. ~Circe~ 2/4/13

#include <std.h>
#include "../valley.h"
inherit MONSTER;

void create(){
	::create();
	set_name("orc");
	set_id(({"orc","monster","fighter"}));
	set_short("An unkempt orc");
	set_long(
	"This is a hulking orc. His skin is a grayish-green color"+
	" and he's covered in coarse black hair. He's slightly"+
	" stooped over with a pig snout and large canines that"+
	" protrude from his mouth. His ears are short and pointy"+
	" and his hair is black and looks as though it has never"+
	" been washed, it's pulled back into a messy ponytail. He"+
	" would be about six feet tall if he were standing straight"+
	" up, and you can see many muscles on his body. He looks"+
	" mean and ugly."
	);
	set_race("orc");
	set_body_type("human");
	set_gender("male");
	set_alignment(3);
	set_hd(15,6);
        set_max_level(20);
	set_max_hp(random(50)+100);
	set_hp(query_max_hp());
	set_class("fighter");
	set_mlevel("fighter",20);
	set_level(14);
	set_stats("strength",19);
	set_size(2);
	set_overall_ac(2);
	set_stats("strength",20);
	set_wielding_limbs(({"right hand", "left hand"}));
	new(OBJ+"spear")->move(TO);
	//command("wield spear in left hand and right hand");
    command("wield spear");
	add_money("electrum",random(70));
//        set_exp(6000);
	set_new_exp(18,"normal");
	set_property("swarm",1);
	set("aggressive",25);
}

	
