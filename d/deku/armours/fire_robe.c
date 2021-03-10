#include <std.h>
inherit "/d/common/obj/armour/robe";

void create(){
	::create();
	set_name("robe of fire");
	set_id(({ "robe", "flame robe", "robe of flame",
    "robe of fire","kinordas robe","phoenix robe"}));
	set_short("%^BOLD%^%^WHITE%^K%^YELLOW%^i%^BOLD%^%^WHITE%^n%^YELLOW%^o%^BOLD%^%^WHITE%^rd%^YELLOW%^a%^BOLD%^%^WHITE%^'s%^RESET%^ "+
    "%^RESET%^%^RED%^Robe of The Ph%^YELLOW%^o%^RESET%^%^RED%^en%^YELLOW%^i"+
    "%^RESET%^%^RED%^x%^RESET%^");
    set_obvious_short("%^RESET%^%^RED%^A robe of %^BOLD%^f%^RESET%^%^ORANGE%^i%^RED%^r%^BOLD%^e%^RESET%^");
    set_long("%^RED%^This robe is made entirely from fire.  "+
    "A light %^BLUE%^blue%^RESET%^%^RED%^ barrier surrounds the "+
    "entire outside and inside of the garment, holding the "+
    "destructive power of the flames at bay.  The neck of this "+
    "robe puffs out in a circular shape, with the edges glowing "+
    "a %^BLUE%^dark blue%^RESET%^%^RED%^ f%^YELLOW%^i%^RESET%^"+
    "%^RED%^r%^YELLOW%^e%^RESET%^%^RED%^.  The sleeves end in "+
    "wide cuffs, allowing plenty of room for the hands of the "+
    "wearer, and the edges of the cuffs glow brightly with "+
    "a %^YELLOW%^yellow%^RESET%^%^RED%^ fl%^YELLOW%^a%^RESET%^"+
    "%^RED%^m%^YELLOW%^e%^RESET%^%^RED%^.  A fl%^YELLOW%^a"+
    "%^RESET%^%^RED%^ming Ph%^YELLOW%^o%^RESET%^%^RED%^en"+
    "%^YELLOW%^i%^RESET%^%^RED%^x resides on the torso of the "+
    "robe, its body withering and twisting occassionally as you "+
    "glance at the robe.  The robe ties at the waist with a "+
    "%^BLUE%^dark blue%^RESET%^%^RED%^ f%^YELLOW%^i%^RESET%^"+
    "%^RED%^r%^YELLOW%^e%^RESET%^%^RED%^ sash and it "+
    "continues downward to just below the knees.%^RESET%^");
    set_value(1000);
	set_lore("This strange robe was created by the high priest "+
    "Kinorda some many years ago.  It was rumored to once "+
    "hold many strange magical properties, the exact nature "+
    "of which were never known.  Most of the magic in it has "+
    "faded over the course of time and what remains keeps "+
    "its fire alive and manages to prevent the flame from "+
    "burning the wearer to death.");
    set_weight(5);
	set_property("lore difficulty",8);
    set_ac(0);
    set_property("enchantment",3);
    set_item_bonus("fire resistance", 12);
    set_wear("%^RED%^You tie the f%^YELLOW%^i%^RESET%^%^RED%^r"+
    "%^YELLOW%^e%^RESET%^%^RED%^ sash around your waist.%^RESET%^");
    set_remove("%^RED%^You loosen the f%^YELLOW%^i%^RESET%^%^RED%^r"+
    "%^YELLOW%^e%^RESET%^%^RED%^ sash and the robe falls off.%^RESET%^");
    set_struck((:TO,"strike_func":));
}

int strike_func(int damage, object what, object who){
    if(random(1000) < 455){
        tell_room(EETO,"%^RED%^As "+who->QCN+" strikes the "+
        "robe worn by "+ETOQCN+"%^RED%^ the ph%^YELLOW%^o%^RESET%^%^RED%^"+
        "en%^YELLOW%^i%^RESET%^%^RED%^x on the "+
        "torso of the robe screams loudly!%^RESET%^",({ETO,who}));
        	
        tell_object(ETO,who->QCN+"%^RED%^ strikes your robe "+
        "and the ph%^YELLOW%^o%^RESET%^%^RED%^en%^YELLOW%^i%^RESET%^"+
        "%^RED%^x on its torso screams loudly!%^RESET%^");
        
        tell_object(who,"%^RED%^You strike the robe "+
        "worn by "+ETOQCN+"%^RED%^ and the ph%^YELLOW%^o%^RESET%^"+
        "%^RED%^en%^YELLOW%^i%^RESET%^%^RED%^x on its torso "+
        "screams loudly and an immense pain swells in your "+
        "head!%^RESET%^");
        who->cause_typed_damage(who, "torso", roll_dice(1, 10) + 4, "fire");
        return 0;
    }
}


