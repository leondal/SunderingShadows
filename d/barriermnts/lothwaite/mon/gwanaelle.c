//gwanaelle.c - clothing vendor for lothwaite.  Circe 12/19/04
#include <std.h>
#include "../lothwaite.h"
inherit VENDOR;

void create()
{
	::create();
	set_name("Gwanaelle");
	set_id(({"gwanaelle","Gwanaelle","tailor"}));
	set_short("Gwanaelle, the tailor");
	set_long(
         "Gwanaelle is an aging female firbolg with a long "+
         "%^RESET%^gray braid %^CYAN%^running down the center "+
         "of her back.  She wears a simple %^ORANGE%^tan dress "+
         "%^CYAN%^of her own making, displaying her skill as a "+
         "seamstress.  Her weathered face is creased with laugh "+
         "lines, evidence of her sunny nature.  She wears a "+
         "%^RED%^pin cushion %^CYAN%^upon her left wrist, and "+
         "her wide waist sports a %^ORANGE%^leather belt %^CYAN%^"+
         "filled with other implements of her trade.  The only "+
         "decoration upon her is the %^BOLD%^%^RED%^b%^RESET%^"+
         "%^ORANGE%^e%^YELLOW%^a%^GREEN%^d%^CYAN%^e%^BLUE%^d "+
         "%^WHITE%^abrigon%^RESET%^%^CYAN%^ hanging beside her "+
         "right cheek."
	);
	set_gender("female");
	set_race("firbolg");
	set_hd(20,3);
	set_max_hp(random(20)+100);
	set_hp(query_max_hp());
	set_alignment(4);
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
      set_nwp("tailoring",20);
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
	set_storage_room("/d/barriermnts/lothwaite/inherit/clothing_storage");
      set_items_allowed("clothing");
	set("aggressive",0);
	add_money("silver",random(20));
	force_me("speech say in a gentle voice");
}