#include <std.h>
inherit "/d/common/obj/armour/helm";

void create(){
	::create();
    set_name("diamond helm");
    set_id(({ "helm", "helmet", "diamond helm" }));
	
    set_short("%^BOLD%^%^WHITE%^A d%^CYAN%^i%^BOLD%^%^WHITE%^"+
    "a%^CYAN%^m%^BOLD%^%^WHITE%^o%^CYAN%^n%^BOLD%^%^WHITE%^d hel"+
    "met%^RESET%^");
	
 // set_obvious_short("A diamond helmet");
	
    set_long("%^BOLD%^%^WHITE%^This helmet is made from "+
    "a %^BLUE%^sky blue %^BOLD%^%^WHITE%^d%^CYAN%^i%^BOLD%^"+
    "%^WHITE%^a%^CYAN%^m%^BOLD%^%^WHITE%^o%^CYAN%^n%^BOLD%^"+
    "%^WHITE%^d and has been designed so that the face is left "+
    "open to exposure.  The diamond that forms the helm is "+
    "almost completely flawless, yet somehow its surface has "+
    "been waxed to rid it of the innate reflective quality.  "+
    "An emblem of a large and closed fist adorns each side of the "+
    "helm.  The symbols are a much darker hue, contrasting with the "+
    "%^BLUE%^sky blue%^BOLD%^%^WHITE%^ of the rest of the helm.  "+
    "There is no visible clue to their significance.%^RESET%^");
    
    set_lore("Formed for the verbobone patrols that used to "+
    "wander the region near the town, these helms were waxed "+
    "with a mysterious substance that prevent them from "+
    "reflecting any light.  The emblem that has been known "+
    "to adorn all of them was once the official symbol of "+
    "the town in better days.");
         	
	set_weight(4);
    set_value(3000);
    set_type("armor");
    set_limbs(({ "head" }));
    set_size(random(3) + 1);
    set_property("enchantment",3);
    set_item_bonus("damage resistance",1);
    set_wear("%^BLUE%^You struggle with the tight helmet and "+
    "finally pull it into place.%^RESET%^");
    set_remove("%^BLUE%^With a powerful %^RED%^JERK%^BLUE%^ you "+
    "rip the helmet free from your head.%^RESET%^");
}


