#include <std.h>
inherit "/std/comp_vend";

void create(){
	::create();
	set_name("rusilas");
	set_short("Rusilas Gumbletree, gnomish gemcutter");
	set_id(({"rusilas","Rusilas","gemcutter","cutter","gem cutter","gumbletree"}));
	set_long(
         "Rusilas Gumbletree is a young male gnome with a bulbous "+
         "nose considered large even by gnomish standards.  His "+
         "white hair stands out in all directions, giving him a "+
         "startled appearance enhanced by his overlarge goggles.  "+
         "He wears a leather apron bristling with pockets, each "+
         "of which is stuffed full with some sort of odds and "+
         "ends.  Black soft leather boots reach past his knees, "+
         "while a forest green shirt is visible beneath his "+
         "apron.  He seems quite content to work with gems all "+
         "day, humming merrily as he moves."
	);
	set_race("gnome");
	set_gender("male");
	set_hd(20,4);
	set_max_hp(150+random(50));
	set_hp(query_max_hp());
	set_overall_ac(-12);
	set_alignment(4);
	set_class("mage");
	set_class("cleric");
	set_mlevel("mage",20);
	set_mlevel("cleric",20);
	set_level(20);
	set_stats("intelligence",18);
	set_stats("wisdom",18);
	set_stats("charisma",16);
	set_stats("strength",9);
	set_stats("constitution",8);
	set_stats("dexterity",14);
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
    set_shop_type("psion");
      set_components(100);
	set("aggressive",0);
	add_money("gold",random(50));
}
