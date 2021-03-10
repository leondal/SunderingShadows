#include <std.h>
inherit ARMOUR;

void create(){
    
	::create();
	set_name("tear shaped amulet");
	set_id(({ "amulet", "tear shaped amulet", "marsivians tear", 
    "marsivians augmented tear", "marsivian amulet", "tear", "augmented tear"}));
    
	set_short("%^BOLD%^%^CYAN%^M%^BOLD%^%^MAGENTA%^a%^BOLD%^%^CYAN%^"+
    "rs%^BOLD%^%^MAGENTA%^i%^BOLD%^%^CYAN%^v%^BOLD%^%^MAGENTA%^ia"+
    "%^BOLD%^%^CYAN%^ns %^MAGENTA%^au%^CYAN%^m%^MAGENTA%^e%^CYAN%^nt"+
    "%^MAGENTA%^e%^CYAN%^d t%^MAGENTA%^ea%^CYAN%^r%^RESET%^");
    
    set_obvious_short("%^BOLD%^%^BLUE%^tear shaped amulet%^RESET%^");
    
    set_property("repairtype",({ "jewel" }));
    
    set_long("%^BOLD%^%^CYAN%^This amulet is formed from what appears to "+
    "be a %^BOLD%^%^WHITE%^crystal%^BOLD%^%^CYAN%^ that has been cut "+
    "into the shape of a teardrop. There are small indescribable "+
    "%^BOLD%^%^WHITE%^glyphs%^BOLD%^%^CYAN%^ etched on the surface of the "+
    "%^BOLD%^%^WHITE%^crystal%^BOLD%^%^CYAN%^. A hole near the top of it "+
    "allows a thick %^RESET%^%^ORANGE%^dingy yellow%^BOLD%^%^CYAN%^ cord to "+
    "pass through. The cord is frayed in many spots though it seems sturdy enough "+
    "that it will not likely break anytime soon. It appears old and as if it were "+
    "used frequently by some one.%^RESET%^");
    
    set_lore("This amulet is rumored to have been one of the most prized "+
    "possessions of a Lysaraian named Marsivian Wyndar, a man who has been "+
    "largely forgotten by history. It is said that this amulet was a gift given to "+
    "him by his wife, herself a cleric of some renown. The same stories suggest that "+
    "the amulet imbued him with the ability to use certain spells to augment his own "+
    "abilities and those of others, at will, as if he were innately born with the "+
    "power to do so. If the rumors are to be believed then the amulet would grant the wearer "+
    "the ability to use Owls Wisdom, Eagles Splendor, and Bears Endurance at will. Rumors "+
    "also suggest that it offered him some ability to resist the magic of his enemies.");
 
	set_weight(2);
	set_value(1000);
	set_type("clothing");
	set_limbs(({ "neck" }));
	set_size(-1);
	set_property("enchantment",5);
    set_wear((:TO,"wearme":));
    set_remove((:TO,"removeme":));  
    set_item_bonus("magic resistance", 2);
}

int wearme() 
{
    if(ETO->query_highest_level() < 35) 
    {
        tell_object(ETO,"%^BLUE%^%^RED%^The magic in the tear is "+
        "too powerful for you to harness!%^RESET%^");
        return 0;
    }
    tell_object(ETO,"%^BOLD%^%^YELLOW%^As an aura of protection flows out "+
    "from the tear shaped amulet and encompasses you... you feel your "+
    "mind expand!%^RESET%^");
    
    ETO->add_bonus_innate((["bears endurance" : (["type" : "spell", "casting level" : 1, 
    "daily uses" : -1, "delay" : 1, "uses left" : -1, 
    "refresh time" : -1, "level required" : 0, 
    "class specific" : 0]), "owls wisdom" : (["type" : 
    "spell", "casting level" : 1, 
    "daily uses" : -1, "delay" : 1, "uses left" : -1, 
    "refresh time" : -1, "level required" : 0, 
    "class specific" : 0]), "eagles splendor" : (["type" : "spell", "casting level" : 1, 
    "daily uses" : -1, "delay" : 1, "uses left" : -1, 
    "refresh time" : -1, "level required" : 0, 
    "class specific" : 0])]));    
    return 1;
}

int removeme()
{
    tell_object(ETO,"%^BOLD%^%^YELLOW%^You feel the aura from the "+
    "amulet quietly fade away!%^RESET%^");
    ETO->remove_bonus_innate(({"bears endurance", "owls wisdom", "eagles splendor"}));
    return 1;
}
