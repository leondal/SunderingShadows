#include <std.h>
inherit "/d/common/obj/clothing/magerobe.c";

string FLAG;

void create()
{
    ::create();
    set_name("robes");
    set_obvious_short("%^RESET%^%^RED%^D%^BOLD%^%^BLACK%^ark re%^RESET%^%^RED%^d r%^BOLD%^%^BLACK%^o%^RESET%^%^RED%^bes%^WHITE%^");
    set_short("%^RESET%^%^RED%^R%^BOLD%^%^BLACK%^ob%^RESET%^%^RED%^es %^BOLD%^of th%^RESET%^%^RED%^e %^WHITE%^A%^BOLD%^rc%^RESET%^hm%^BOLD%^a%^RESET%^gi%^RESET%^");
    set_id(({"robes","robes of the archmagi","Robes of the Archmagi","mage robes","magi robes","robe"}));
	set_long(
"%^RED%^These robes are a d%^BOLD%^%^BLACK%^a%^RESET%^%^RED%^rk r%^BOLD%^%^BLACK%^e%^RESET%^%^RED%^d in color, representing a mage who upholds the balance of power. They are very strong, as they appear to be made out of a very %^BOLD%^s%^BLACK%^t%^RED%^r%^BLACK%^o%^RED%^n%^BLACK%^g %^RED%^c%^BLACK%^o%^RED%^t%^BLACK%^t%^RED%^o%^BLACK%^n%^RESET%^%^RED%^. A pair of wide f%^BOLD%^low%^RESET%^%^RED%^i%^BOLD%^ng %^RESET%^%^RED%^sle%^BOLD%^ev%^RESET%^%^RED%^es are %^WHITE%^trimmed with %^BOLD%^%^CYAN%^r%^RESET%^%^CYAN%^u%^BOLD%^ne %^RESET%^e%^BOLD%^n%^RESET%^c%^BOLD%^r%^RESET%^u%^BOLD%^s%^RESET%^t%^BOLD%^e%^RESET%^d %^CYAN%^e%^BOLD%^%^WHITE%^lec%^RESET%^tr%^BOLD%^u%^RESET%^m f%^BOLD%^a%^RESET%^br%^BOLD%^i%^RESET%^c%^RED%^. The %^BOLD%^%^CYAN%^r%^RESET%^%^CYAN%^u%^BOLD%^nes %^RESET%^%^RED%^are hard to make out as the%^WHITE%^y %^RED%^are always %^CYAN%^morphing %^RED%^and changing, never giving one enough time to read them. The %^CYAN%^e%^BOLD%^%^WHITE%^le%^RESET%^c%^BOLD%^tru%^RESET%^m c%^BOLD%^ol%^RESET%^ored s%^BOLD%^ash %^RESET%^%^RED%^serves as a way to close the robes. These are extremely elegant, flowing to the ground. There are probably numerous pockets to conceal spell components and the like in them.%^RESET%^");
	set_weight(5);
	set_type("clothing");

    while((int)TO->query_property("enchantment") != 7)
    {
        TO->remove_property("enchantment");
        TO->set_property("enchantment",7);
    }
    set_item_bonus("spell damage resistance",22);
    set_item_bonus("bonus_spell_slots",3);
    set_item_bonus("spellcraft",6);
    set_limbs(({"torso"}));
    set_max_internal_encumbrance(21);
    set_value(150000);
    set_wear((:TO,"wearme":));
    FLAG = "neutral";
}

int wearme()
{
    string MASTER;

    if(member_array("%^BOLD%^%^RED%^Won %^RESET%^%^RED%^a %^BOLD%^%^CYAN%^fair %^RESET%^%^CYAN%^challenge %^RED%^against %^BOLD%^B%^CYAN%^a%^RED%^tl%^CYAN%^i%^RED%^n%^RESET%^",ETO->query_mini_quests())== -1)
    {
        tell_object(ETO,"%^BOLD%^You have not earned the %^RED%^right%^WHITE%^ to make use of this item.");
        return 0;
    }

    if(this_player()->query_guild_level("mage") < 35 &&
       this_player()->query_guild_level("sorcerer") < 35 &&
       this_player()->query_guild_level("magus") < 35)
    {
        tell_object(ETO,"You are not yet powerful enough to make use of this item.");
        return 0;
    }

    if(ETO->is_class("mage") || ETO->is_class("magus")) {
        TO->set_item_bonus("intelligence",4);
        TO->set_item_bonus("charisma",0);
    }
    else {
        TO->set_item_bonus("intelligence",0);
        TO->set_item_bonus("charisma",4);
    }
    return 1;
}


void init()
{
	::init();
	add_action("check_put","put");
}

int check_put(string str)
{
	if(!query_worn())
    {
	    notify_fail("You must be wearing the robes to place something in their"+
		    " pockets.\n");
		return 0;
	}

	if(query_worn()) return ::put_into();
}
