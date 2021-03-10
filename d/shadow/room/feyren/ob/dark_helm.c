#include <std.h>
inherit "/d/common/obj/armour/helm";

void create()
{
    ::create();
    set_name("midnight black helm");
    set_id(({ "helm", "helmet", "dark helmet", "black helmet", 
    "midnight black helm", "midnight black helmet", "guard",
    "noggin guard"}));
	
    set_obvious_short("A midnight black helmet");

    set_short("%^BOLD%^%^RED%^F%^RESET%^%^RED%^e%^BOLD%^"+
    "%^RED%^yr%^RESET%^%^RED%^e%^BOLD%^%^RED%^n's Noggin "+
    "G%^RESET%^%^RED%^ua%^BOLD%^%^RED%^rd%^RESET%^");
	
    set_long("%^BOLD%^%^BLUE%^This great helm is forged from a "+
    "%^RESET%^%^BLUE%^midnight black%^BOLD%^%^BLUE%^ metal. "+
    "There are %^BOLD%^%^YELLOW%^intricate%^BOLD%^%^BLUE%^ designs "+
    "carved over the entire surface of it, each one slightly "+
    "different than the other. A long %^BOLD%^%^YELLOW%^twisted "+
    "horn%^BOLD%^%^BLUE%^ has been attached into the center "+
    "of the top of it. Slitted %^RESET%^%^RED%^dark red%^BOLD%^"+
    "%^BLUE%^ eyes have been painted above the eye sockets, in an "+
    "obvious attempt to make it appear more gruesome.%^RESET%^");

    set_property("lore difficulty", 15);

    set_lore("This mysterious helmet was forged by the once "+
    "proud half-orc Feyren. There was a time when many people "+
    "around shadow would come to his farm in search of armor and "+
    "this helm was regarded as one of his finest crafted pieces. It is "+
    "said to protect the wearer slightly from any bludgeoning damage.");
         	
    set_value(3000);
    set_size(2);
    set_property("enchantment",2);
    set_item_bonus("bludgeoning resistance", 4);
// this is broken in lib, removing til a fix can be applied. N, 9/14.

    set_wear("%^BLUE%^You carefully secure the helmet "+
    "and feel more protected.%^RESET%^");

}


