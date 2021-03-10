//Added lore and inherit shield - Cythera 4/05\\
#include <std.h>
#include "../valley.h"
inherit "/d/common/obj/armour/shield.c";

int x, OWNED;
string owner;

void create()
{
	::create();
	set_name("%^YELLOW%^golden shield%^RESET%^");
	set_id(({"golden shield","Golden Shield","shield","sunburst shield","sun shield"}));
	set_short("%^YELLOW%^S%^WHITE%^u%^RED%^n%^WHITE%^b%^YELLOW%^"+
		"u%^RED%^r%^YELLOW%^s%^WHITE%^t%^YELLOW%^ Shield%^RESET%^");
	set_obvious_short("%^YELLOW%^A golden shield%^RESET%^");
	set_long(
	"			   %^YELLOW%^Golden Shield		%^RESET%^\n"+
	"	%^WHITE%^The golden shield is created from three types of gold.\n"+
	"	%^BOLD%^%^YELLOW%^Yellow gold forms the sun in the center of the shield.\n"+
	"	%^RED%^Rose gold is used as the flames bursting from the sun.\n"+
	"	%^WHITE%^White gold contrasts the sunburst as the background.%^RESET%^"
	);
	set_lore("The Order of the Dawn Phoenix is a band of adventuring"+
		" clerics and warriors devoted to Lathander, the Morninglord."+
		"  The members of  the order are one of the more martial sects"+
		" within Lathander's faith, seeking out that which threatens "+
		"life in the world and acting swiftly to stop it.  The members"+
		" of the Dawn Phoenix were well known for their golden suits "+
		"of chainmail, their phoenix shaped helms, and the Sunburst "+
		"Shields they carried.  Though the order was small, for the "+
		"life they lived was dangerous and deadly, they were able to "+
		"spread the light of Lathander across the lands.  When the "+
		"Moonstone Valley become under threat the Dawn Phoenix "+
		"answered the call of the druids.  Though a member of this"+
		" order has not been seen in over 30 years.  No one knows what"+
		" ever happened them.");
	set_property("lore",13);
        set_size(-1);
	set_property("enchantment",2);
	set_weight(10);
	set_value(6000);
	set_cointype("gold");
	set_wear((:TO,"wearme":));
	set_remove((:TO,"removeme":));
	set_struck((:TO,"strikeme":));
	x = query_property("enchantment");
}

void init()
{
	::init();
	if(!interactive(ETO)) return;
	if(interactive(TP) && TP == environment(TO) && !OWNED) {
		owner = TPQN;
		OWNED = 1;
	}
}

int wearme()
{
	int align;

	if((string)TPQN != owner) {
		tell_object(ETO,"This is not your shield!");
		return 0;
	}
	align = ETO->query_alignment();
	switch(align) {
		case 1: case 4: case 7:
			tell_object(ETO,"%^YELLOW%^The sunburst pattern seems"+
			" to brighten as you don the shield and it feels"+
			" pleasantly warm to your touch.");
			tell_room(environment(ETO),"%^YELLOW%^The sunburst"+
			" pattern brightens momentarily on "+ETO->query_cap_name()+"'s"+
			" shield.",ETO);
         ETO->set_property("good item",1);
			return 1;

		case 2: case 5: case 8:
			tell_object(ETO,"%^BOLD%^You hear a soft humming sound"+
			" coming from the shield and you get an inner sense of"+
			" peace.");
			tell_room(environment(ETO),"%^BOLD%^A soft humming sound"+
			" is emitted from "+ETO->query_cap_name()+"'s shield.",ETO);
			while(query_property("enchantment") != x-1) {
				remove_property("enchantment");
				set_property("enchantment",x-1);
			}
         ETO->set_property("good item",1);
			return 1;

		case 3: case 6: case 9:
			tell_object(ETO,"%^BOLD%^%^RED%^The sunburst pattern on the"+
			" shield flares angrily as you put it on.");
			tell_room(environment(ETO),"%^BOLD%^%^RED%^The sunburst"+
			" pattern on "+ETO->query_cap_name()+"'s shield flares"+
			" brightly.",ETO);
			while(query_property("enchantment") != x-2) {
				remove_property("enchantment");
				set_property("enchantment",x-2);
			}
         ETO->set_property("good item",1);
			return 1;
		default:
			notify_fail("Nice try, but that doesn't work here."+
			" Now go seek some help like a good little mental"+
			" patient.");
			return 0;
	}
}

int removeme()
{
	int align;

	align = ETO->query_alignment();

	switch(align) {
		case 1: case 4: case 7:
			tell_object(ETO,"%^YELLOW%^The glow from the shield"+
			" reluctantly fades as you remove it.");
			tell_room(environment(ETO),"%^YELLOW%^The glow from"+
			" "+ETO->query_cap_name()+"'s shield slowly fades.",ETO);
      ETO->set_property("good item",-1);
			return 1;

		case 2: case 5: case 8:
			tell_object(ETO,"%^BOLD%^A melancholy note is emitted"+
			" from the shield as you remove it.");
			tell_room(environment(ETO),"%^BOLD%^A melancholy note"+
			" is emitted from "+ETO->query_cap_name()+"'s shield.",ETO);
			while(query_property("enchantment") != x) {
				remove_property("enchantment");
				set_property("enchantment",x);
			}
      ETO->set_property("good item",-1);
			return 1;

		case 3: case 6: case 9:
			tell_object(ETO,"%^BOLD%^%^RED%^The shield flashes again as"+
			" you remove it, seeming happy to be rid of you.");
			while(query_property("enchantment") != x) {
				remove_property("enchantment");
				set_property("enchantment",x);
			}
      ETO->set_property("good item",-1);
			return 1;

		default:
			notify_fail("Uh, nice try, but something's broke and"+
			" needs a little fixing.");
			return 0;
	}
}

int strikeme(int damage, object what, object who)
{
	int align;
	align = ETO->query_alignment();

	switch(align) {
		case 1: case 4: case 7:
			if(objectp(what)) {
				tell_object(ETO,"%^YELLOW%^The Sunburst Shield rings as it"+
				" is struck by the "+what->query_name()+".");
            return (-1)*(damage/2);
			}
			else {
				tell_object(ETO,"%^YELLOW%^The Sunburst Shield flares"+
				" brightly as "+who->query_cap_name()+" strikes it.");
				tell_object(who,"%^YELLOW%^The Sunburst Shield worn by"+
				" "+ETO->query_cap_name()+" flares brightly as you strike it.");
				tell_room(environment(query_worn()),"%^YELLOW%^The Golden"+
				" Shield flares brightly as it absorbs the blow from"+
				" "+who->query_cap_name()+".",({who,ETO}));
				return (-1)*(damage/3);
			}
		case 2: case 3: case 5: case 6: case 8: case 9:
			return 1;
	}
	return 1;
}
