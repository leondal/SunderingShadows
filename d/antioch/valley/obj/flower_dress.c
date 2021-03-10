//Added Lore - Cythera - 4/05
// updated cha bonus from the new system. Nienne, 09/07.
#include <std.h>
#include "../valley.h"
inherit "/std/armour";

int FLAG;

void create()
{
	::create();
	set_name("%^BOLD%^%^RED%^f%^BLUE%^l"+
		"%^MAGENTA%^o%^BLUE%^w%^MAGENTA%^e"+
                "%^RED%^r%^YELLOW%^ dress%^RESET%^");
	set_id(({"dress","flower dress","dress of flowers","+
		""flowery dress","flower gown","flower robe","+
		""summer dress","dress of summer's bouquet"}));
	set_short("%^YELLOW%^Dress of %^MAGENTA%^S%^YELLOW%^u%^WHITE%^"+
		"m%^RESET%^%^MAGENTA%^m%^BOLD%^%^RED%^e%^WHITE%^r%^YELLOW%^"+
		"'%^MAGENTA%^s%^YELLOW%^ Bouquet%^RESET%^");
	set_obvious_short("%^RESET%^%^GREEN%^A %^BOLD%^%^RED%^f%^BLUE%^l"+
		"%^MAGENTA%^o%^BLUE%^w%^MAGENTA%^e%^RED%^r%^RESET%^%^GREEN%^"+
		" covered %^YELLOW%^golden %^RESET%^%^GREEN%^dress%^RESET%^");
	set_long(
	"%^GREEN%^The pretty summer dress is made entirely out of flowers."+
	"  %^YELLOW%^Y%^RESET%^%^ORANGE%^e%^BOLD%^l%^RESET%^%^ORANGE%^l%^BOLD%^"+
	"o%^RESET%^%^ORANGE%^w%^BOLD%^ d%^WHITE%^a%^RESET%^%^ORANGE%^is%^BOLD%^"+
	"i%^WHITE%^e%^RESET%^%^ORANGE%^s%^GREEN%^, %^YELLOW%^d%^RESET%^%^ORANGE%^"+
	"a%^YELLOW%^f%^RESET%^%^ORANGE%^f%^BOLD%^o%^RESET%^%^ORANGE%^d%^BOLD%^i"+
	"%^RESET%^%^ORANGE%^l%^BOLD%^s%^RESET%^%^GREEN%^, %^BOLD%^%^BLUE%^i"+
	"%^RESET%^%^BLUE%^r%^CYAN%^i%^BOLD%^s%^BLUE%^e%^RESET%^%^BLUE%^s"+
	"%^GREEN%^, %^MAGENTA%^p%^BOLD%^%^BLACK%^a%^RESET%^%^MAGENTA%^ns"+
	"%^BOLD%^%^BLACK%^i%^RESET%^%^MAGENTA%^es%^GREEN%^, %^BOLD%^"+
	"%^MAGENTA%^a%^YELLOW%^s%^MAGENTA%^ters%^RESET%^%^GREEN%^, "+
	"%^BOLD%^%^RED%^p%^RESET%^%^RED%^o%^BOLD%^p%^RESET%^%^RED%^p%^BOLD%^"+
	"i%^RESET%^%^RED%^e%^BOLD%^s%^RESET%^%^GREEN%^, %^BOLD%^%^MAGENTA%^p"+
	"%^WHITE%^r%^MAGENTA%^i%^WHITE%^m%^MAGENTA%^r%^WHITE%^o%^MAGENTA%^s"+
	"%^WHITE%^e%^RESET%^%^GREEN%^, %^MAGENTA%^v%^BLUE%^i%^MAGENTA%^o"+
	"%^BLUE%^l%^MAGENTA%^e%^BLUE%^t%^MAGENTA%^s%^GREEN%^, and %^BOLD%^"+
	"%^RED%^w%^RESET%^%^RED%^i%^BOLD%^%^WHITE%^l%^MAGENTA%^d %^RESET%^"+
	"%^RED%^r%^BOLD%^o%^MAGENTA%^s%^RESET%^%^RED%^e%^BOLD%^s%^RESET%^%^GREEN%^"+ 
   	" are all sewn onto a %^YELLOW%^g%^RESET%^%^ORANGE%^o%^BOLD%^l%^RESET%^"+
	"%^ORANGE%^d%^BOLD%^e%^RESET%^%^ORANGE%^n%^GREEN%^ short dress made of silk so as to"+
	" protect the wearer from being scratched by the stems. It smells"+
	" simply divine, but the dress doesn't appear to be very sturdy. %^RESET%^"
	);
	set_lore("Woven from the bouquet of flowers that grow in the Moonstone"+
		" Valley, this enchanting dress posses all the beauty of the "+
		"flowers for a woman to wear.  The dress is favored by nymphs"+
		" and dryads for it's quiet and refined beauty.  Interwoven "+
		"among the silk and flowers is a healthy supply of fey magic"+
		" that keeps the flowers always fresh and in bloom, providing"+
		" their refreshing scent to the lucky lady.  It is said that "+
		"the dress often gives one the urge to %^BOLD%^%^MAGENTA%^"+
		"giggle%^RESET%^, %^YELLOW%^skip%^RESET%^, and %^MAGENTA%^"+
		"dance%^RESET%^.");
	set_property("lore",6);
	set_weight(3);
        set_property("enchantment",2);
	set_item_bonus("charisma",1);
	set_size(2);
	set_value(80);
	set_cointype("silver");
	set_type("clothing");
	set_limbs(({"torso"}));
	set_wear((:TO,"wearme":));
	set_remove((:TO,"removeme":));
}

int wearme()
{
	if((string)ETO->query_gender() == "male") {
		tell_object(ETO,"%^BOLD%^As you try to get your large frame"+
		" into the dainty little dress you rip it and the flowers"+
		" fall to the ground.");
		tell_room(environment(ETO),"%^BOLD%^As "+ETO->query_cap_name()+""+
		" tries to shove his large frame into the tiny dress he rips it"+
		" and flowers spill to the ground as the dress dissolves.",ETO);
		TO->remove();
		return 0;
	}
   if(!interactive(ETO)) return 1;
	if((string)ETO->query_gender() == "female") {
		tell_object(ETO,"%^YELLOW%^You slip into the flower dress"+
		" and feel like a young girl again.");
		tell_room(environment(ETO),"%^YELLOW%^"+ETO->query_cap_name()+""+
		" looks younger as she slips into the flower dress.",ETO);
      ETO->set("long","%^YELLOW%^"+capitalize(nominative(ETO))+" is cloaked "+
		"in a fragrant perfume of %^MAGENTA%^f%^RESET%^%^MAGENTA%^l"+
                "%^BOLD%^%^BLUE%^o%^WHITE%^w%^BLUE%^e%^RESET%^%^MAGENTA%^r"+
                "%^BOLD%^s%^YELLOW%^.");
                return 1;
	}
	else {
		tell_object(ETO,"You appear to be the victim of a vicious crime,"+
		" please contact authorities immediately.");
		return 0;
	}
}

int removeme()
{
	tell_object(ETO,"%^BOLD%^You can't repress a sigh as you remove"+
	" the beautiful dress and feel the weight of the world once more.");
	tell_room(environment(ETO),"%^BOLD%^"+ETO->QCN+""+
	" sighs softly as she slips out of her dress.",ETO);
        ETO->set("long",0);
	return 1;
}

void init()
{
	::init();
	add_action("giggle","giggle");
	add_action("skip","skip");
	add_action("dance","dance");
}

int giggle(string str)
{
	if(ETO->query_bound() || ETO->query_unconcious() || ETO->query_paralyzed() || ETO->query_tripped()) {
		ETO->send_paralyzed_message("info",ETO);
		return 1;
	}
	if(query_worn() && !str) {
		tell_object(ETO,"%^BOLD%^You give a girlish giggle.");
		tell_room(environment(ETO),"%^BOLD%^"+ETO->QCN+""+
		" gives a girlish giggle.",ETO);
		return 1;
	}
}

int skip(string str)
{
	if(ETO->query_bound() || ETO->query_unconcious() || ETO->query_paralyzed() || ETO->query_tripped()) {
		ETO->send_paralyzed_message("info",ETO);
		return 1;
	}
	if(query_worn() && !str) {
		tell_object(ETO,"%^BOLD%^%^MAGENTA%^You skip about without a care"+
                  " in the world.");
		tell_room(environment(ETO),"%^BOLD%^%^MAGENTA%^"+ETO->QCN+""+
		" skips merrily around the room.",ETO);
		return 1;
	}
}

int dance(string str)
{
	if(ETO->query_bound() || ETO->query_unconcious() || ETO->query_paralyzed() || ETO->query_tripped()) {
		ETO->send_paralyzed_message("info",ETO);
		return 1;
	}
	if(query_worn() && !str) {
		tell_object(ETO,"%^YELLOW%^You dance about happily, full of"+
		" joy and life.");
		tell_room(environment(ETO),"%^YELLOW%^"+ETO->QCN+""+
		" dances wildly about the room, looking happy and joyful.",ETO);
		return 1;
	}
}

