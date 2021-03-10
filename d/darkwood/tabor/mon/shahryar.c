#include <std.h>
#include "../include/tabor.h"
inherit VENDOR;

void create()
{
	::create();
	set_name("Shahryar");
	set_id(({"Shahryar","shahryar","tailor"}));
	set_short("Shahryar, the tailor");
	set_long(
         "Shahryar is a dark-skinned man from the lands south of "+
         "Azha.  He has come here in an attempt to spread his "+
         "family's business northward - the business of making "+
         "clothing.  Shahryar is dressed in the manner of the "+
         "clothes he sells, with a turban wrapped around his head "+
         "that conceals the color of his hair and a kameez worn "+
         "above puffy pantaloons.  He is barefoot and moves "+
         "lightly around the shop, helping customers.  When he "+
         "is not busy, he is usually lounging and smoking his "+
         "hookah, leaving you to wonder when he has time to "+
         "tailor all these clothes."
	);
	set_gender("male");
	set_race("human");
	set_body_type("human");
	set_hd(20,3);
	set_max_hp(random(20)+100);
	set_hp(query_max_hp());
	set_alignment(1);
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
	set_exp(100);
      set_nwp("tailoring",15);
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
	set_storage_room("/d/darkwood/tabor/include/tailor-storage.c");
      set_items_allowed("clothing");
	set("aggressive",0);
	add_money("silver",random(20));
	force_me("speech say with a thick accent");
      set_mymaxvalue(8);
}