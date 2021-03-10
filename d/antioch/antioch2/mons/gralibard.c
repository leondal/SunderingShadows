#include <std.h>
#include "../antioch.h"
inherit INTERACTIVE;

void create()
{
	::create();
	remove_std_db();
	remove_dbs(({"miscvendors"}));
	set_name("Gralibard");
	set_short("Gralibard, the general store clerk");
	set_id(({"Gralibard","gralibard","clerk","store clerk"}));
	set_long(
	"Gralibard is the clerk of the general store. He is a veteran fighter,"+
	" and on the large size, though not very tall. He only reaches five foot"+
	" six in height, but his shoulders are very broad. Blonde hair tumbles"+
	" down to just past his shoulders and his blue eyes seem friendly. His"+
	" skin is tanned and he is very muscled. He is wearing a white shirt"+
	" that is pulled taut across his chest. Brown pants cover his legs and"+
	" matching boots are on his feet." 
	);
   set_items_allowed("all");
	set_gender("male");
	set_race("human");
	set_body_type("human");
	set_hd(30,8);
	set_alignment(1);
	set_max_hp(300+random(50));
	set_hp(query_max_hp());
	set_level(30);
	set_overall_ac(-15);
	set_class("fighter");
	set_mlevel("fighter",30);
	set_stats("strength",20);
	set_stats("consitution",18);
	set_stats("dexterity",14);
	set_stats("charisma",12);
	set_stats("wisdom",8);
	set_exp(100);
	set("aggressive",0);
	set_storage_room(ROOMDIR+"general");
	add_money("gold",random(50));
	force_me("speech speak in a deep voice");
	remove_std_db();
	remove_dbs( ({"/d/db/armors","/d/db/vendor","/d/db/weapons", 
	"/d/db/miscvendors" }) );
	remove_random_act_dbs(({"/d/db/armorsrandom"}));
}

//chat, call guards
