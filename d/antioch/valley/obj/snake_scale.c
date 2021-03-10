//Added lore and had it inherit scale - Cythera 4/05\\
#include <std.h>
#include "../valley.h"
inherit "/d/common/obj/armour/scale.c";

string owner;

void create()
{
	::create();
	set_name("%^BOLD%^%^GREEN%^Reptilian Scale Mail%^RESET%^");
	set_id(({"reptilian scale mail","reptilian scalemail","scale mail","scalemail","reptilian mail","reptilian scale","scale armor","scale armour","Reptilian Scale Mail","scale","mail"}));
	set_short("%^RESET%^%^BOLD%^%^GREEN%^Reptilian Scale Mail%^RESET%^");
	set_obvious_short("%^BOLD%^%^GREEN%^A suit of green scale mail%^RESET%^");
	set_long(
        "%^BOLD%^%^GREEN%^The reptilian scale mail is quite lovely to"+
	" look at. The scales are those of a rather large snake and the"+
	" the colors range from a %^RESET%^%^BLUE%^deep blue %^BOLD%^%^GREEN%^"+
	" to %^CYAN%^aqua%^GREEN%^ with shades of %^RESET%^%^GREEN%^forest"+
	" green%^BOLD%^, though the predominant color is a vibrant green."+
	" The scales have been woven carefully together and look like"+
	" they would protect the wearer well. %^RESET%^"
	);
	set_property("lore",13);
	set_lore("The Moonstone Valley has been under many threats in"+
		" recent times.  From the ogre and undead hordes along "+
		"the dark trials, to the wild and savage beasts that have"+
		" taken over the Dark Forest that surrounds it.  The druids"+
		" and the fey creatures have been successful for the most part"+
		" in keeping the valley fortified and safe.  Except for one "+
		"creature.. the darkfang snake.  A creature rumored to be the"+
		" creation of an ancient god of decay and rotting.  This elder"+
		" god, who's name has vanished with time, was believed to have"+
		" been a chief rival of Mielikki, the Protector of Fey and Forests"+
		" and was seeking to corrupt and twist the valley into his own "+
		"paradise of decay and rot.  The serpent was planted inside the "+
		"valley as a way for the decay to spread.  With the god's death "+
		"now though, this serpent has lost most of it's rumored powers."+
		"  Still the druids find it hard to kill the serpent and all of"+
		" its children, so they are under constant threats from it.  "+
		"The scales of the serpent are favored by druids and nature "+
		"oriented folk as a sign of pride and honor for slaying such a"+
		" corrupt beast.");
	set_value(5700);
	set_size(-1);
	set_wear((:TO,"wearme":));
	set_remove((:TO,"removeme":));
	set_struck((:TO,"strikeme":));
        set_property("enchantment",3);
	set_item_bonus("magic resistance",1);
}

int wearme()
{
// Vaping owner check as per the hide - no actual owner setting. N, 2/15
/*        if((string)TPQN != owner) {
		tell_object(ETO,"%^CYAN%^The scales hiss at you angrily and"+
		" refuse your touch for you are not their owner!");
		tell_room(environment(ETO),"%^CYAN%^The scales hiss at "+ETO->query_cap_name()+".",ETO);
		return 0;
        } */
	tell_object(ETO,"%^BOLD%^%^CYAN%^The scales of the suit shimmer"+
	" faintly.");
	tell_room(environment(ETO),"%^BOLD%^%^CYAN%^The scales of"+
	" "+ETO->query_cap_name()+"'s suit shimmer faintly.",ETO);
	return 1;
}

int removeme()
{
	tell_object(ETO,"%^GREEN%^The scales return to their normal"+
	" color as you remove the suit.");
	tell_room(environment(ETO),"%^GREEN%^The scales of "+ETO->query_cap_name()+"'s"+
	" suit return to their normal color.",ETO);
	return 1;
}

int strikeme(int damage, object what, object who)
{
	if(objectp(what)) {
		tell_object(ETO,"%^BOLD%^%^BLUE%^The scales shimmer a"+
		" sapphire shade as they are struck by "+what->query_name()+".");
		tell_room(environment(ETO),"%^BOLD%^%^BLUE%^The scales"+
		" turn a sapphire color as they are struck by "+what->query_name()+".",ETO);
		return (-1)*(damage/4);
	}
	else {
		tell_object(ETO,"%^BOLD%^%^GREEN%^The scales shine a"+
		" brilliant emerald as "+who->query_cap_name()+" strikes"+
		" them.");
		tell_room(environment(ETO),"%^BOLD%^%^GREEN%^The scales on"+
		" "+ETO->query_cap_name()+"'s mail shine a brilliant"+
		" emerald as "+who->query_cap_name()+" strikes them.",({ETO,who}));
		tell_object(who,"%^BOLD%^%^GREEN%^The scales on "+ETO->query_cap_name()+"'s"+
		" mail shine a brilliant green as you strike them.");
		if(!"daemon_saving_d"->saving_throw(who,"paralyzation_poison_death")) {
			tell_object(who,"%^GREEN%^Poison seems to creep into"+
			" your body from where you touched the scales.");
			who->add_poisoning(15);
			who->do_damage("torso",random(5)+1);
		}
		else {
			who->do_damage("torso",random(5)+1);
		}
		return (-1)*(damage/3);
	}
}

int is_metal() { return 0; } //not metal
