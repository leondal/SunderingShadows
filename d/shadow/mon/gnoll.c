//gnoll.c - updated to use current code by Circe - 8/25/03
#include <std.h>
#include "/d/common/common.h"

inherit MONSTER;

void create() {
	object ob;
	::create();
	set_name("gnoll");
	set_id(({"gnoll","Gnoll","monster"}));
	set_race("gnoll");
	set_gender("male");
	set_short("A ferocious gnoll");
	set_long(
	"This gnoll stands larger than the average human, and has a very human looking body.  "+
	"Its head though is that of a canine, almost hyena-like with a mane from the head "+
      "spreading down over its greenish gray skin.  Its snarling mouth dripping with blood "+
      "tends to make you think it's not going to wait for you to die before it starts to eat you."
	);
	set_level(random(3)+5);
	set_hd(8, 3);
      set_class("fighter");
	set_mlevel("fighter",8);
	set_hp(random(10)+50);
	set_body_type("human");
	set("aggressive",19);
	set_alignment(3);
	if(random(2)) set_size(2);
	else set_size(3);
	set_overall_ac(8);
	set_stats("intelligence",6);
	set_stats("wisdom",4);
	set_stats("strength",13);
	set_stats("charisma",3);
	set_stats("dexterity",8);
	set_stats("constitution",7);
	set_max_hp(query_hp());
	set_wielding_limbs( ({ "right hand", "left hand"}) );
	ob = new(CWEAP"longsword");
	ob->set_property("monsterweapon",1);
	ob->move(this_object());
	command("wield sword in right hand");
	ob = new(CARMOR"hide");
	ob->set_property("monsterweapon",1);
	ob->move(TO);
	command("wear armor");
	add_money("gold",random(50));
	add_money("copper",random(20));
	set_max_level(10);
	//set_exp(150);
    set_exp(900);
	set_hp(45+random(15));
}

