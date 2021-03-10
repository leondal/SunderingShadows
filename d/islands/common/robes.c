#include <std.h>
inherit "/d/common/obj/clothing/magerobe.c";

string FLAG;

void create()
{
    ::create();
    set_name("robes");
    set_obvious_short("A set of dark red robes");
    set_short("%^BOLD%^%^RED%^Robes of the Archmagi%^RESET%^");
    set_id(({"robes","robes of the archmagi","Robes of the Archmagi","mage robes","magi robes","robe"}));
	set_long(
	    "%^BOLD%^%^RED%^These robes are a dark red in color, representing a mage"+
	    " who upholds the balance of power between good and evil. They are very"+
        " strong, as they appear to be made out of a very strong cotton"+
        ". A pair of wide flowing sleeves are trimmed with rune encrusted electrum fabric."+
        " The runes are hard to make out as they are always morphing and changing,"+
        " never giving one enough time to read them. The electrum colored sash serves as a"+
        " way to close the robes. These are extremely"+
	    " elegant, flowing to the ground. There are probably numerous pockets to"+
        " conceal spell components and the like in them.%^RESET%^ ");
	set_weight(5);
	set_type("clothing");
   
    while((int)TO->query_property("enchantment") != 5) 
    {
        TO->remove_property("enchantment");
        TO->set_property("enchantment",5);
    }
    set_item_bonus("magic resistance",2);
    set_item_bonus("bonus_spell_slots",2);
      set_item_bonus("spellcraft",4); // nerfed from 10 to 4; 50% on a roll is way too much. N, 2/14
    set_limbs(({"torso"}));
    set_max_internal_encumbrance(21);
    set_value(35000);
    set_wear((:TO,"wearme":));
    set_remove((:TO,"removeme":));
    FLAG = "neutral";
}

int wearme()
{
    string MASTER;

    if(member_array("%^BOLD%^%^RED%^Defeated the great red wyrm Klauth!%^RESET%^",ETO->query_mini_quests())== -1) 
    {
        tell_object(ETO,"You have not earned the right to make use of this item.");
        return 0;
    }

    if((int)ETO->query_class_level("mage") < 35 && (int)ETO->query_class_level("sorcerer") < 35) 
    {
        tell_object(ETO,"You have not earned the right to make use of this item.");
        return 0;
    }

    if((string)ETO->query_gender() == "female") MASTER = "mistress";
    if((string)ETO->query_gender() == "male")   MASTER = "master";
    
    if(ALIGN->is_evil(ETO)) 
    {
        if(FLAG != "evil") 
        {
            tell_object(ETO,"%^BOLD%^%^BLACK%^The robes turn the darkest"+
                " black as you slip them on.");
            tell_room(environment(ETO),"%^BOLD%^%^BLACK%^The robes"+
                " turn pitch black as "+ETO->query_cap_name()+" puts them on,"+
                " reflecting their new "+MASTER+".",ETO);
            set_obvious_short("A set of pitch black robes");
            set_short("%^BOLD%^%^BLACK%^Robes of the Archmagi%^RESET%^");
            set_long("%^BOLD%^%^BLACK%^These robes are pitch black in color,"+
                " representing a mage who will stop at nothing to gain ultimate"+
                " power, even if it means using darker forces. They are very"+
                " strong, as they appear to be made out of a very strong cotton"+
                ". A pair of wide flowing sleeves are trimmed with rune encrusted electrum fabric."+
                " The runes are hard to make out as they are always morphing and changing,"+
                " never giving one enough time to read them. The electrum colored sash serves as a"+
                " way to close the robes. These are extremely"+
                " elegant, flowing to the ground. There are probably numerous"+
                " pockets to conceal spell components and the like in"+
                " them.%^RESET%^ ");
            FLAG = "evil";
        }   
        else 
        {
            tell_object(ETO,"%^BOLD%^%^BLACK%^The robes feel like a part of"+
                " you as you slip the trusted garment on.");
            tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETO->query_cap_name()+""+
                " seems more powerful after slipping on "+ETO->query_possessive()+" robes.",ETO);
        }
    }

    if(ALIGN->is_good(ETO)) 
    {
        if(FLAG != "good") 
        {
            tell_object(ETO,"%^BOLD%^The robes turn a sparkling white as"+
                " you slip them on.");
            tell_room(environment(ETO),"%^BOLD%^%^WHITE%^The robes"+
                " a bright shade of white as "+ETO->query_cap_name()+" puts them"+
                " on, reflecting their new "+MASTER+".",ETO);
            set_obvious_short("A set of bright white robes");
            set_short("%^BOLD%^%^WHITE%^Robes of the Archmagi%^RESET%^");
            set_long("%^BOLD%^%^WHITE%^These robes are bright white in color,"+
                " representing a mage whose intentions are pure and who strives"+
                " for good to maintain control of a power as strong and dangerous"+
                " as that of magic. They are very"+
                " strong, as they appear to be made out of a very strong cotton"+
                ". A pair of wide flowing sleeves are trimmed with rune encrusted electrum fabric."+
                " The runes are hard to make out as they are always morphing and changing,"+
                " never giving one enough time to read them. The electrum colored sash serves as a"+
                " way to close the robes. These are extremely"+
                " elegant, flowing to the ground."+
                " There are probably numerous pockets to conceal spell components"+
                " and the like in them.%^RESET%^ ");
            FLAG = "good";
        }
        
        else 
        {
            tell_object(ETO,"%^BOLD%^The robes feel like a part of you"+
                " as you slip the trusted garment on.");
            tell_room(environment(ETO),"%^BOLD%^"+ETO->query_cap_name()+""+
                " seems more powerful after slipping on "+ETO->query_possessive()+" robes.",ETO);
        }
    }
    if(ALIGN->is_neutral(ETO)) 
    {
        if(FLAG != "neutral") 
        {
            tell_object(ETO,"%^BOLD%^%^RED%^The robes turn a splendid dark"+
                " red as you slip them on.");
            tell_room(environment(ETO),"%^BOLD%^%^RED%^The robes"+
                " change to a dark red as "+ETO->query_cap_name()+" slips them"+
                " on, reflecting their new "+MASTER+".",ETO);
            set_obvious_short("A set of dark red robes");
            set_short("%^BOLD%^%^RED%^Robes of the Archmagi%^RESET%^");
            set_long("%^BOLD%^%^RED%^These robes are a dark red in color,"+
                " representing a mage who upholds the balance of power between"+
                " good and evil. They are very"+
                " strong, as they appear to be made out of a very strong cotton"+
                ". A pair of wide flowing sleeves are trimmed with rune encrusted electrum fabric."+
                " The runes are hard to make out as they are always morphing and changing,"+
                " never giving one enough time to read them. The electrum colored sash serves as a"+
                " way to close the robes. These are extremely"+
                " elegant, flowing to the ground."+
                " There are probably numerous pockets to conceal spell components"+
                " and the like in them.%^RESET%^ ");
            FLAG = "neutral";
        }
        else 
        {
            tell_object(ETO,"%^BOLD%^%^RED%^The robes feel like a part of you"+
                " as you slip the trusted garment on.");
            tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETO->query_cap_name()+""+
                " seems more powerful after slipping on "+ETO->query_possessive()+" robes.",ETO);
        }
    }
    if(ETO->is_class("mage")) {
        TO->set_item_bonus("intelligence",4);
        TO->set_item_bonus("charisma",0);
    }
    else {
        TO->set_item_bonus("intelligence",0);
        TO->set_item_bonus("charisma",4);
    }
    return 1;
}

int removeme()
{
	if(FLAG == "neutral") 
    {
		tell_object(ETO,"%^BOLD%^%^RED%^You feel power slip from you as you"+
		    " remove your wonderful robes.");
	}
	if(FLAG == "good") 
    {
		tell_object(ETO,"%^BOLD%^You feel power slip from you as you"+
		    " remove your wonderful robes.");
	}
	if(FLAG == "evil") 
    {
		tell_object(ETO,"%^BOLD%^%^BLACK%^You feel power slip from you as you"+
		    " remove your wonderful robes.");
	}
    //these cannot be here - otherwise when the robe is removed
    //the item bonuses will NOT be removed - should not matter because of the 
    //way that they are set up in the wear function - Saide, December 2016
	//set_item_bonus("intelligence",0);
    //set_item_bonus("charisma",0);
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
