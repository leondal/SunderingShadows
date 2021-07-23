#include <std.h>
#include <move.h>

inherit PARMOUR;

int TIMED_USAGE_DELAY = 0;

void create(){
	::create();
	set_name("leather pouch");
	set_id(({ "refreshing pouch", "leather pouch", "pouch", "belt", "leather belt", "belt pouch" }));
	set_short("%^BOLD%^%^BLACK%^re%^YELLOW%^f%^BLACK%^res%^MAGENTA%^h%^BLACK%^ing p%^WHITE%^o%^BLACK%^uch%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^a l%^WHITE%^e%^RESET%^a%^BLACK%^%^BOLD%^th%^RESET%^e%^BOLD%^%^BLACK%^r b%^WHITE%^e%^RESET%^l%^BOLD%^%^BLACK%^t p%^WHITE%^o%^RESET%^u%^BOLD%^%^BLACK%^ch%^RESET%^");
	set_long(
@AVATAR
%^RESET%^Created from supple %^BOLD%^%^BLACK%^gray leather%^RESET%^, this belt and pouch combo appear ordinary but for the intricate tool working on the leather.  The wide belt is edged with thick %^BOLD%^%^BLACK%^black twine %^RESET%^that protects and strengthens its surface.  Evenly spaced between and about two inches apart from one another are %^MAGENTA%^amethyst %^RESET%^and %^BOLD%^%^WHITE%^silver %^RESET%^studs.  Surrounding these can be seen a melody of looping swirls that might be indicative of %^BOLD%^%^CYAN%^wind%^RESET%^, %^CYAN%^water %^RESET%^or %^BOLD%^%^BLACK%^shadows%^RESET%^.  The buckle is likewise %^BOLD%^%^WHITE%^silver %^RESET%^and is styled as two hands clasping, the fingernails highlighted in %^MAGENTA%^amethyst %^RESET%^half moons.  The pouch is rectangular in design and likewise decorated with the same swirls and ribbons as the belt.  A flap closes over the top and has a matching buckle to keep it closed.%^RESET%^

AVATAR
	);
	set_weight(5);
   set_value(0);
	set_lore(
@AVATAR
These pouches are highly sought after by those who need to travel light but are forced to travel in dangerous places.  Besides holding a few small personal items that the wearer might need, each pouch is enchanted to summon healing potions.  The wearer simply need to focus their mind on their desire and will the potions to the top.  The pouch will supply them with a small cluster of kits that should help in such a situation.  Of course, such magic is limited and once the power is used it may be a while before it can be used again.  Since the pouches must summon a kit from a local location, there is also no guarantee what strength the kits will be.

AVATAR
	);
	set_property("lore difficulty",13);
	set_max_internal_encumbrance(15);
	set_type("clothing");
	set_limbs(({ "waist" }));
	set_size(-1);
   while ((int)TO->query_property("enchantment") != 5) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",5);
   }
	set_wear((:TO,"wear_func":));
    set_overallStatus(220);
    set_property("no disenchant",1);
}

int isMagic(){ return 1; }

int wear_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^As you buckle the belt into place, you notice a small marking on the back of the pouch amongst all the swirls.  Looking closer, you see it says: %^RESET%^%^MAGENTA%^will potion%^RESET%^");
	return 1;
}

int random_potions(string str)
{
	if(!objectp(TP)) { return 1; }
	
	if(!stringp(str) || str == "" || str == " ")
	{
		tell_object(TP,"will what?");
		return 0;
	}

	if(lower_case(str) != "potion" && lower_case(str) != "potions" && lower_case(str) != "kit" && lower_case(str) != "kits")
	{
		tell_object(TP,"will what?");
		return 0;
	}

	if(TIMED_USAGE_DELAY > time())
	{
		tell_object(TP,"%^RESET%^%^RED%^You will the pouch to create potions but nothing happens.\n%^RESET%^"
			"%^RESET%^%^BOLD%^Perhaps it needs time to recharge%^RESET%^\n");
		return 1;
	}

	else
	{
		object obj;

		TIMED_USAGE_DELAY = 43200 + time();
		
		switch(random(100))
		{
		case 0..49:

			obj = new("/d/common/obj/potion/extra_heal.c");
			obj->set_uses(roll_dice(2,4)+2);
			break;

		case 50..89:

			obj = new("/d/common/obj/potion/advanced_heal.c");
			obj->set_uses(roll_dice(2,3)+1);
			break;

		case 90..99:

			obj = new("/d/common/obj/potion/legendary_heal.c");
			obj->set_uses(roll_dice(1,3)+1);
			break;
		}

		tell_object(TP,"%^RESET%^%^BOLD%^%^BLACK%^You flip the flap of your pouch up "
			"and reach in while concentrating on what you %^RESET%^need%^RESET%^%^BOLD%^%^BLACK%^.  "
			"Soon you feel the cool texture of %^BOLD%^%^CYAN%^glass%^RESET%^%^BOLD%^%^BLACK%^ "
			"against your fingers and find a helpful "
			"%^RESET%^%^BOLD%^k%^RESET%^%^BOLD%^%^MAGENTA%^i%^RESET%^%^YELLOW%^t%^RESET%^%^BOLD%^%^BLACK%^ "
			"waiting in your hands.%^RESET%^");		
		tell_room(ETP,"%^RESET%^%^BOLD%^%^BLACK%^"+TP->QCN+" seems to be concentrating "
			"hard as "+TP->QS+" reaches into the pouch at "+TP->QP+" side.%^RESET%^",({TP}));

		if((int)obj->move(TP) == MOVE_NO_ROOM) // if it's too heavy, move it to the room instead
		{
			tell_object(TP,"%^RESET%^%^BOLD%^The potions are too heavy and you drop them!%^RESET%^");
			obj->move(ETP);
		}

	}
	return 1;
}

void init()
{
	add_action("random_potions","will");
	::init();
}

