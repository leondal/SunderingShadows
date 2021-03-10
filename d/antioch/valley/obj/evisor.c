//Added Lore - Cythera 4/05
#include <std.h>
#include "../valley.h"
inherit "/std/armour";

int x;

void create()
{
	::create();
	set_name("%^RESET%^%^GREEN%^Emerald visor%^RESET%^");
	set_id(({"emerald visor","visor","emerald helm","emerald helmet","helmet","helm","crystal visored helm"}));
	set_short("%^RESET%^%^GREEN%^Emerald visor%^RESET%^");
	set_obvious_short("%^BOLD%^%^GREEN%^A crystal visored helm%^RESET%^");
	set_long(
	"%^GREEN%^The helm is an exquisite piece of craftsmanship."+
	" It is made of steel that has been enchanted to a deep shade of emerald."+
	" A crystal visor comes down over the wearer's eyes"+
	" that is also tinted green, giving the world an emerald"+
	" hue.%^RESET%^"
	);
	set_lore("The Emerald Visor was thought to be the legendary"+
		" helm of Eclustis Samboard, a warrior devoted to Silvanus."+
		"  Eclustis trained to become a knight, like his father and "+
		"father's father, but found the journey and trials unrewarding."+
		"  In the middle of his training Eclustis just walked away one "+
		"day, leaving his family socially embarrassed and the young man"+
		" feeling isolated.  Taking long walks in the forest, to try to"+
		" figure out where his path in life laid, the young man came upon"+
		" an older female being harassed and attacked by a pack of feral "+
		"humans.  Without a second thought, it is said, Eclustis reached "+
		"for his long sword and entered the forest clearing in defense of"+
		" the woman.  After a lengthy battle, the two were able to put down"+
		" several of the feral humans before the pack fled.  The woman he "+
		"had saved it turned out was an elderly druid of Silvanus who found"+
		" herself at the mercy  of the feral humans.  The feral ones, "+
		"she explained, were member of a cult devoted to Malar the Beastlord"+
		" called, People of the Black Blood.  It was under the guidance and"+
		" council of Willow, the druid, that Eclustis found the path in his"+
		" life that he was seeking.  Eclustis' name is well known among the"+
		" druids of Silvanus as The Cavalier of Nature.");
	set_property("lore",12);
	set_weight(10);
        set_size(-1);
	set_type("armour");
	set_limbs(({"head"}));
	set_property("enchantment",3);
	set_item_bonus("sight bonus",5);
	set_value(1000);
	set_ac(1);
	set_wear((:TO,"wearme":));
	set_remove((:TO,"removeme":));
}

void init()
{
	x = (int)ETO->query_size();

	::init();
	add_action("look_at","look");
	set_size(x);
}

int wearme()
{
	if(ETO->query_lowest_level() < 10) {
		tell_object(ETO,"You aren't experienced enough to use this yet.");
		return 0;
	}
	tell_object(ETO,"%^BOLD%^%^GREEN%^You now see the world"+
	" through an emerald glass and everything is clear.");
	return 1;
}

int removeme()
{
	tell_object(ETO,"%^GREEN%^As you remove the visor the world"+
	" becomes a shadowed mystery again.");
	return 1;
}

int look_at(string str)
{
	if(!query_worn()) {
		return 0;
	}
	else {
		tell_object(ETO,"%^BOLD%^%^GREEN%^You see everything in shades"+
		" of green.");
		return 0;
	}
}
