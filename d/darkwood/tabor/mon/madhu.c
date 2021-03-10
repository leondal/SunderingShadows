#include <std.h>
#include "../include/tabor.h"
inherit VENDOR;

void create()
{
	::create();
   set_name("Madhu");
    set_id(({"Madhu","madhu","potion dealer","dealer","vendor"}));
   set_short("Madhu Raghvatz, Potion maker extrodanaire");
	set_long(
   "Madhu is a dark-skinned man from the lands south of "+
   "Azha.  He has light brown eyes and long sable tresses tied back in neat a braid. "+
"He dresses in the typical Tsarven garb in colors of %^BOLD%^%^BLACK%^black and gray.%^RESET%^%^CYAN%^"+
   "He looks to be quick and nimble on his feet and is constantly performing some amazing feat with his potions - be it juggling them, tossing them behind his back and catching them, or just uncorking them to allow some of their strange effects to be seen."
	);
	set_gender("male");
    set_race("human");
   set_alignment(6);
	set_body_type("human");
	set_hd(20,3);
	set_max_hp(random(20)+100);
	set_hp(query_max_hp());
	set_class("mage");
	set_mlevel("mage",20);
	set_overall_ac(-3);
	set_level(20);
	set_stats("dexterity",18);
	set_stats("intelligence",18);
	set_stats("wisdom",12);
	set_stats("strength",13);
	set_stats("constitution",10);
	set_stats("charisma",15);
	set_mob_magic_resistance("average");
   set_exp(500);
   set_moving(1);
   set_speed(60);
	set_spells(({
	"hideous laughter",
	"magic missile",
	"acid arrow",
	"chain lightning",
	"phantom guardians",
	"fireball",
	"monster summoning vii",
	"web",
	"meteor swarm",
	"hold person",
	}));
	set_spell_chance(100);
   set_storage_room("/d/darkwood/tabor/include/potions-storage.c");
	set("aggressive",0);
	add_money("silver",random(20));
   force_me("speech speak with a fluent accent");
}
