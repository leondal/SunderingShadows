#include <std.h>
#include "../antioch.h"
inherit INTERACTIVE;

void create()
{
	::create();
	remove_std_db();
	remove_dbs(({"tailor"}));
	remove_random_act_dbs(({"tailorrandom"}));
	set_name("Kedaria");
	set_short("Kedaria, jeweler of Antioch");
	set_id(({"kedaria","Kedaria","jeweler"}));
	set_long(
	"Kedaria is a beautiful woman in her early twenties. Jet black hair flows"+
	" down the length of her back and her eyes are a mystic %^BOLD%^%^WHITE%^silver%^RESET%^%^CYAN%^"+
	" that seem mildly amused by something. She is wearing a %^BLUE%^dark blue%^CYAN%^"+
	" dress that shows off her curves. Some lovely pieces of subtle jewelry"+
	" adorn her neck, arms, and hands, hightlighting her beauty. She is"+
	" obviously the owner of the store, making jewelry is her livelihood as"+
	" well as her passion, she puts her heart into her work to make it as"+
	" good as possible."
	);
   set_items_allowed("clothing");
	set_race("human");
	set_body_type("human");
	set_gender("female");
	set_hd(30,4);
	set_max_hp(200+random(50));
	set_hp(query_max_hp());
	set_overall_ac(-17);
	set_alignment(1);
	set_class("mage");
	set_class("cleric");
	set_mlevel("mage",25);
	set_mlevel("cleric",25);
	set_level(30);
	set_stats("intelligence",18);
	set_stats("wisdom",18);
	set_stats("charisma",16);
	set_stats("strength",9);
	set_stats("constitution",8);
	set_stats("dexterity",14);
//	set_diety("helm");
//	new("/d/magic/symbols/helm_symbol.c")->move(TO);
	set_spells(({
	"meteor swarm",
	"flame strike",
	"mystic bolt",
	"limb attack",
	"monster summoning vii",
	"chain lightning",
	}));
	set_spell_chance(100);
	set_exp(100);
	set("aggressive",0);
	add_money("gold",random(50));
	set_storage_room(ROOMDIR+"jeweler.c");
	force_me("speech speak in a silky voice");
     set_nwp("tailoring",0);
     set_nwp("jewelling",20);
}

//chat, call guards, heal self during battle
