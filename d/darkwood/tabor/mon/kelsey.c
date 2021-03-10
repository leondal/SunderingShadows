#include <std.h>
#include "../include/tabor.h"
inherit VENDOR;

void create()
{
	::create();
	set_name("Kelsey");
	set_id(({"Kelsey","kelsey","seamstress","tailor"}));
	set_short("Kelsey, a young seamstress");
	set_long(
         "Kelsey is a young woman with shoulder-length chestnut "+
         "hair worn pulled back from her face with combs.  A "+
         "smattering of freckles along the bridge of her nose "+
         "combines with her short height to make her appear "+
         "younger than she actually is.  She wears a pin cushion "+
         "on her left wrist and seems constantly distracted with "+
         "patterns and alterations.  She is dressed in clothing "+
         "of her own making - a sensible tunic above a long skirt, "+
         "worn above well-fitting boots."
	);
	set_gender("female");
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
	set_storage_room("/d/darkwood/tabor/include/tabor_clothing.c");
      set_items_allowed("clothing");
	set("aggressive",0);
	add_money("silver",random(20));
      set_mymaxvalue(8);
}