//Scintillating Boots of Brilliance - grant 1 bonus level 5 and 6 spell slot - Saide
#include <std.h>
inherit ARMOUR;

void create() 
{
    	::create();
    	set_value(15000);
	set_property("enchantment", 2);
	set_name("pair of crimson boots");

	set_id(({"boots", "boots of brilliance", "scintillating boots", 
	"scintillating boots of brilliance"}));

	set_obvious_short("%^BOLD%^%^RED%^A pair of crimson boots%^RESET%^");

	set_short("%^RESET%^%^MAGENTA%^S%^BOLD%^%^RED%^c%^RESET%^%^MAGENTA%^"+
	"i%^BOLD%^%^RED%^n%^RESET%^%^MAGENTA%^t%^BOLD%^%^RED%^i"+
	"%^RESET%^%^MAGENTA%^l%^BOLD%^%^RED%^l%^RESET%^%^MAGENTA%^"+
	"a%^BOLD%^%^RED%^t%^RESET%^%^MAGENTA%^i%^BOLD%^%^RED%^n"+
	"%^RESET%^%^MAGENTA%^g Boots of %^BOLD%^B%^RESET%^%^RED%^"+
	"r%^BOLD%^%^MAGENTA%^i%^RESET%^%^RED%^l%^BOLD%^%^MAGENTA%^"+
	"l%^RESET%^%^RED%^i%^BOLD%^%^MAGENTA%^a%^RESET%^%^RED%^n"+
	"%^BOLD%^%^MAGENTA%^c%^RESET%^%^RED%^e%^RESET%^");

	set_long("%^BOLD%^%^MAGENTA%^These short boots are crafted "+
	"from a %^BOLD%^%^RED%^dark cr%^BOLD%^%^YELLOW%^i%^BOLD%^%^RED%^"+
	"m%^BOLD%^%^RED%^son %^BOLD%^%^MAGENTA%^material that has "+
	"been stitched together seamlessly.  The top of them has been "+
	"folded down and is a much %^BOLD%^%^RED%^lighter red%^BOLD%^"+
	"%^MAGENTA%^ hue.  The inside of the boots is a thick and very "+
	"soft %^BOLD%^%^YELLOW%^down%^BOLD%^%^MAGENTA%^.  Two disembodied "+
	"hands have been %^BOLD%^%^YELLOW%^e%^BOLD%^%^MAGENTA%^"+
	"m%^BOLD%^%^YELLOW%^b%^BOLD%^%^MAGENTA%^r%^BOLD%^%^YELLOW%^"+
	"o%^BOLD%^%^MAGENTA%^i%^BOLD%^%^YELLOW%^d%^BOLD%^%^MAGENTA%^"+
	"e%^BOLD%^%^YELLOW%^r%^BOLD%^%^MAGENTA%^e%^BOLD%^%^YELLOW%^"+
	"d%^BOLD%^%^MAGENTA%^ on both sides of each boot, "+
	"each constantly waving about, as if completing "+
	"the final part of some unknown %^BOLD%^%^BLUE%^"+
	"r%^BOLD%^%^CYAN%^i%^BOLD%^%^BLUE%^t%^BOLD%^%^CYAN%^"+
	"u%^BOLD%^%^BLUE%^a%^BOLD%^%^CYAN%^l%^BOLD%^%^MAGENTA%^  "+
	"With the completion of each movement, a shower of "+
	"%^BOLD%^%^YELLOW%^s%^BOLD%^%^RED%^p%^BOLD%^%^YELLOW%^"+
	"a%^BOLD%^%^RED%^r%^BOLD%^%^YELLOW%^k%^BOLD%^%^YELLOW%^s "+
	"%^BOLD%^%^MAGENTA%^is released and then absorbed by "+
	"the boots.%^RESET%^"); 

	set_property("lore difficulty", 30);

	set_lore("%^BOLD%^%^MAGENTA%^These boots were created by the tailor "+
	"Minithes Aldom many years ago as a present for a wizard "+
	"friend.  He paid dearly to have them imbued with a magic "+
	"that would help increase the capacity of his friends mind.  "+
	"The enchantment was a splendid success, though neither of the "+
	"two men have been heard from in ages.%^RESET%^");
	set_weight(2);
    	set_type("clothing");
	set_size(-1);
	set_limbs( ({ "right foot", "left foot" }) );
	set_wear((:TO, "wear_me":));
	set_remove((:TO, "remove_me":));
	set_property("bonus_spell_slots_5", 1);
	set_property("bonus_spell_slots_6", 1);

}

int wear_me()
{
	if(ETO->query_highest_level() < 30)
	{
		tell_object(ETO, "%^BOLD%^%^RED%^The boots refuse to be worn "+
		"by someone as weak as you!%^RESET%^");
		return 0;
	}
	set_heart_beat(1);
	//ETO->set_property("bonus_spell_slots_5", 1);
	//ETO->set_property("bonus_spell_slots_6", 1);
	tell_object(ETO, "%^BOLD%^%^MAGENTA%^You feel as if your mind has "+
	"suddenly expanded as you slip into the comfortable boots.%^RESET%^");
	return 1;
}

int remove_me()
{
	//ETO->set_property("bonus_spell_slots_5", -1);
	//ETO->set_property("bonus_spell_slots_6", -1);
	tell_object(ETO, "%^BOLD%^%^MAGENTA%^You feel the power from the boots "+
	"edd away as you slip them off your feet.%^RESET%^");
	return 1;
}

void heart_beat()
{
	if(!objectp(TO)) return;
	if(!objectp(ETO)) return;
	if(!objectp(EETO)) return;
	if(!query_worn()) return;
	if(random(5000) < 4985) return;

	tell_object(ETO, "%^BOLD%^%^MAGENTA%^Your boots suddenly release a shower of "+
	"%^BOLD%^%^YELLOW%^s%^BOLD%^%^RED%^p%^BOLD%^%^YELLOW%^"+
	"a%^BOLD%^%^RED%^r%^BOLD%^%^YELLOW%^k%^BOLD%^%^YELLOW%^s"+
	"%^BOLD%^%^MAGENTA%^ as the disembodied hands on them "+
	"complete another portion of their neverending ritual!%^RESET%^");
	
	if(ETO->query_true_invis()) return;

	if(ETO->query_invis()) 
	{
		tell_room(EETO, "%^BOLD%^%^MAGENTA%^A sudden shower of "+
		"%^BOLD%^%^YELLOW%^s%^BOLD%^%^RED%^p%^BOLD%^%^YELLOW%^"+
		"a%^BOLD%^%^RED%^r%^BOLD%^%^YELLOW%^k%^BOLD%^%^YELLOW%^s"+
		"%^BOLD%^%^MAGENTA%^ appears near the ground!%^^RESET%^", ETO);
		return;
	}
	tell_room(EETO, "%^BOLD%^%^MAGENTA%^A sudden shower of "+
	"%^BOLD%^%^YELLOW%^s%^BOLD%^%^RED%^p%^BOLD%^%^YELLOW%^"+
	"a%^BOLD%^%^RED%^r%^BOLD%^%^YELLOW%^k%^BOLD%^%^YELLOW%^s"+
	"%^BOLD%^%^MAGENTA%^ bursts forth from the boots "+
	"worn by "+ETOQCN+"%^BOLD%^%^MAGENTA%^!%^RESET%^", ETO);
	return;
}
