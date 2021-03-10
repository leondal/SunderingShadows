#include <std.h>
#include <daemons.h>
#include "../inherits/area_stuff.h"
inherit VENDOR;
int activated;

void create() 
{
	object wpn1;
   	::create();
	set_name("gimpy");
   	set_id(({"gimpy", "gimpy the gnome"}));

	set_short("%^BOLD%^%^GREEN%^Gimpy, A %^BOLD%^%^CYAN%^"+
	"blue %^BOLD%^%^GREEN%^eyed gnome with a "+
	"pronounced limp%^RESET%^");

	set_long("%^BOLD%^%^YELLOW%^This little gnome is completely "+
	"cloaked in a shroud of %^BOLD%^%^BLACK%^darkness%^BOLD%^"+
	"%^YELLOW%^.  All you can really make out of his face "+
	"are his brilliant %^BOLD%^%^CYAN%^blue%^BOLD%^%^YELLOW%^ "+
	"eyes.  His body appears well toned and the skin that you can "+
	"make out is very tanned.  His left leg appears several "+
	"inches shorter than his right and with each step he "+
	"takes there is a very noticed and pronounced limp.  "+
	"He doesn't seem to care at all that you are here, but "+
	"curiously enough there is no explaination for why he "+
	"is in this place.  He motions for you - and shows you a "+
	"few vials of a %^BOLD%^%^MAGENTA%^brilliant rose potion"+
	"%^BOLD%^%^YELLOW%^ that he has for sale.%^RESET%^");
   	set_race("gnome");
   	set_body_type("human");
   	set_gender("male");
   	set_size(1);
   	set_alignment(5);
   	set_class("mage");
   	set_level(10);
   	set_overall_ac(-20);
   	set_guild_level("mage",10);
	set_mlevel("mage", 10);
   	set_max_hp(125);
   	set_hp(query_max_hp());
   	set_wielding_limbs(({"right hand","left hand"}));
	set_property("full attacks", 1);
	set_stats("strength",15);
   	set_stats("dexterity",15);
   	set_stats("constitution",25);
   	set_stats("wisdom",30);
   	set_stats("intelligence",30);
   	set_stats("charisma",3);
   	set_exp(10);
	set_new_exp(1, "very low");
	command("speak wizish");
	set_storage_room("/d/realm/inherits/merchant_room");
}



