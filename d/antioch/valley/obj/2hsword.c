//Added Lore
#include <std.h>
#include "../valley.h"
inherit "/d/common/obj/weapon/two_hand_sword.c";

void create()
{
	::create();
	set_name("two-handed sword");
	set_id(({"sword","large sword","two-handed sword","two handed sword","skull sword","skull blade","blade"}));
	set_short("%^RESET%^%^BLUE%^Skull Sword%^RESET%^");
	set_obvious_short("%^RESET%^%^BLUE%^A rune carved two handed sword%^RESET%^");
	set_long(
	"%^WHITE%^The blade of this sword is an odd dark gray in color,"+
	" there are runes carved into the blade itself. The hilt of the"+
	" sword has a large %^BLUE%^sapphire%^RESET%^ embedded in it"+
	" with the magical image of a skull placed inside the gem. The"+
	" eyes of the skull almost appear to be watching you.");
	//set_type("slash");
	//set_weight(15);
	//set_size(3);
	//set_wc(1,10);
	//set_large_wc(3,6);
	set_value(450);
        set_property("enchantment",2+random(2));
	set_hit((:TO,"hitme":));
	set_wield((:TO,"wieldme":));
	set_lore("Once known as one of the Blue Sapphire Sword,"+
		" the Skull Sword was twisted by the curse that fell"+
		" over elder Antioch.  A group of warriors who pledged"+
		" themselves to protect the ancient city of Antioch were"+
		" known for their suits of platemail crested with an eagle"+
		" and their sapphire hilted two handed swords.  Antioch's "+
		"Eagles though fell under the same curse as the rest of the"+
		" city.  Some speculate the undead that haunt the Dark Trails"+
		" near the ruins of Antioch are what is left of the former "+
		"residents.");
	set_property("lore",8);
}

void init()
{
	::init();
	add_action("read_runes","read");
}

int read_runes(string str)
{
	if(!str) {
		tell_object(ETO,"Read what?");
		return 0;
	}
	if(str != "runes" && str != "sword") {
		notify_fail("You can't read that!");
		return 0;
	}
	if(ETO->query_stats("intelligence") < 9) {
		tell_object(ETO,"The pretty runes swirl before your eyes"+
		" in beautiful patterns.");
		return 1;
	}
	if(ETO->query_stats("intelligence") < 15) {
		tell_object(ETO,"The runes twist and turn under your gaze"+
		" and you can make no sense of them.");
		return 1;
	}
	else {
		tell_object(ETO,"The runes are carved from top to bottom of"+
		" the blade, they read:%^BOLD%^%^BLUE%^\n"+
		"			D\n\n"+
		"			E\n\n"+
		"			A\n\n"+
		"			T\n\n"+
		"			H\n");
		return 1;
	}
}

int wieldme()
{
	if(ETO->query_level() < 10) {
		tell_object(ETO,"The sword refuses to be wielded by an incompetent such as yourself!");
		return 0;
	}
	else {
		tell_object(ETO,"%^BLUE%^The skull cackles eerily as you"+
		" wield the sword.");
		tell_room(environment(ETO),"%^BLUE%^Strange laughter seems"+
		" to emanate from "+ETO->query_cap_name()+"'s sword as"+
		" "+ETO->query_subjective()+" wields it.",ETO);
		return 1;
	}
}


int hitme(object targ)
{
	if(!objectp(targ)) return 1;

	if(!random(50)) {
		tell_object(ETO,"%^BLUE%^Blue"+
		" %^B_BLUE%^%^RED%^%^BOLD%^flames%^RESET%^%^BLUE%^"+
		" erupt along the length of the blade, scorching"+
		" "+targ->query_cap_name()+" as you hit"+
		" "+targ->query_objective()+".");
		tell_room(environment(ETO),"%^BLUE%^Blue"+
		" %^B_BLUE%^%^RED%^%^BOLD%^flames%^RESET%^%^BLUE%^"+
		" erupt along the length of "+ETO->query_cap_name()+"'s"+
		" blade, scorching "+targ->query_cap_name()+" as"+
		" "+ETO->query_subjective()+" hits "+targ->query_objective()+".",({ETO,targ}));
		tell_object(targ,"%^BLUE%^Blue"+
		" %^B_BLUE%^%^RED%^%^BOLD%^flames%^RESET%^%^BLUE%^"+
		" erupt along the length of "+ETO->query_cap_name()+"'s"+
		" blade, sending waves of fiery agony through your body"+
		" as the sword hits you.");
		targ->do_damage("torso",random(20)+3);
		return 1;
	}
	return 0;
}
