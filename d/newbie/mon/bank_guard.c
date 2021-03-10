#include <std.h>
#include "../newbie.h"
inherit MONSTER;

void create() {
	::create();
	set_name("bank guard");
	set_short("A bank guard");
	set_id(({"guard","bank guard"}));
	set_long(
	"This is one of the men employed as a guard by the bank of Offestry. He gets"+
	" paid better than the regular city guards, and is also a lot tougher than"+
	" them. He keeps alert for any trouble, and is prepared to break up any fight"+
	" that might start here. He takes his job very seriously, and you get the"+
	" feeling it wouldn't matter to him if someone got hurt, so long as no money"+
	" was lost."
	);
	set_race("human");
	set_gender("male");
	set_level(30);
	set_body_type("human");
	set_class("fighter");
	set("aggressive",0);
	set_alignment(2);
	set_hd(30,8);
	set_max_hp(300);
	set_hp(300);
	set_wielding_limbs(({"right hand","left hand"}));
	add_money("gold",random(5));
	add_money("silver",random(20));
	set_property("full attacks",1);
	new("/d/common/obj/armour/banded")->move(TO);
	command("wear banded");
	new("/d/common/obj/weapon/halberd")->move(TO);
	command("wield halberd");
}
