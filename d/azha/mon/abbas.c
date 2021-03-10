#include <std.h>
inherit "/std/comp_vend";

void create(){
	::create();
	set_name("abbas");
	set_short("Abbas, mystic gemshaper");
	set_id(({"abbas","Abbas","gemshaper","mystic","shaper"}));
	set_long(
         "Abbas is a middle-aged human with an austere appearance.  "+
         "His head is clean-shaven and smooth, leaving no hint of "+
         "hair, while his eyes radiate a clear pale green.  He is "+
         "dressed very simply in a flowing monk's robe with a thick "+
         "strand of prayer beads placed carefully across his torso.  "+
         "He wears very simple wrappings in place of shoes upon his "+
         "feet, and something about his demeanor hints that the "+
         "opulence of this shop is not out of a selfish desire "+
         "for monetary gain, but rather an emphasis on the "+
         "asthetically pleasing simplicity of decoration.  Abbas "+
         "rarely speaks frivolously, often completing full "+
         "transactions without a word before going back to his "+
         "meditations."
	);
	set_race("human");
	set_gender("male");
	set_hd(20,4);
	set_max_hp(150+random(50));
	set_hp(query_max_hp());
	set_overall_ac(-12);
	set_alignment(4);
	set_class("psion");
	set_class("cleric");
	set_mlevel("psion",20);
	set_mlevel("cleric",20);
	set_level(20);
	set_stats("intelligence",18);
	set_stats("wisdom",18);
	set_stats("charisma",16);
	set_stats("strength",9);
	set_stats("constitution",8);
	set_stats("dexterity",14);
	set_spells(({
         "mind thrust","mind thrust","call crystals","energy bolt","energy bolt","ultrablast"
	}));
	set_spell_chance(60);
	set_exp(100);
	set("aggressive",0);
	add_money("gold",random(50));
    set_shop_type("psion");
    set_components(100);
}
