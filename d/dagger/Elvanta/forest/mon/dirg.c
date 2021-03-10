
#include <std.h>
#include "/d/shadow/mon/melnmarn.h"
#include </d/antioch/areadefs.h>
inherit MONSTER;

void init() {
	::init();
add_action("stab_func", "stab");
}
create() {
   ::create();
set_name("dirg");
set_id(({"dirg", "blacksmith"}));
set("race", "elf");
set_gender("male");
set("short", "%^ORANGE%^Dirg, the blacksmith");
  set("long",
"%^BOLD%^RED%^Dirg is an ordinary looking elf, at first sight.  He has plain brown hair and a plain face, ruddy from the heat of his forge.  He is neither tall nor short, nor thin or stout.  He is sober and quiet, and like most men who follow his trade, he is enormously strong.  He wears a rough leather jerkin and an apron of the same material.  Both are spotten with burns from the sparks which fly from his forge.%^RESET%^");
set_level(20);
	set_body_type("human");
	set("aggressive", 0);
	set_alignment( 50);
	set_size(2);
     set_stats("intelligence", 14);
	set_stats("wisdom", 15);
	set_stats("strength", 20);
	set_stats("charisma", 21);
	set_stats("dexterity", 18);
     set_stats("constitution", 22);
add_money("gold", 250);
set_hp(120);
	set_max_mp(0);
set_mp(query_max_mp());
set_hd(20,1);
set_exp(500);
	set_max_hp(query_hd());
	set_max_sp(query_hp());
	set_sp(query_max_sp());
set_wielding_limbs( ({"right hand", "left hand"}) );
new("/d/shadow/obj/weapon/mace")->move(this_object());
command("wield mace in right hand");
new("/d/shadow/obj/weapon/dagger")->move(this_object());
command("wield dagger in left hand");
new("/d/dagger/Elvanta/forest/items/armor/mithril")->move(this_object());
command("wear armor");
}
int stab_func(string str){
	write("%^BOLD%^CYAN%^Dirg bellows : Are you really that stupid, traveller?");
	return 1;
}
