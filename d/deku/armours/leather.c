#include <std.h>
inherit "/d/common/obj/armour/leather";

void create()
{
    ::create();
    set_name("leather");
    set_id(({"leather","armor","black leather","leather of silence", 
    "leather of shadows","silence armor","shadow armor","silence leather",
    "shadow leather"}));
    set_short("%^BOLD%^%^BLACK%^Leather of sil%^CYAN%^e%^BOLD%^"+
    "%^BLACK%^nce and sh%^BOLD%^%^WHITE%^a%^BOLD%^%^BLACK%^dows"+
    "%^RESET%^");
    set_obvious_short("A suit of black leather armor");
    set_long("%^BOLD%^%^BLACK%^This armor is made from very "+
    "thin strips of leather that have been carefully stitched "+
    "together.  The strips have each been dyed with a dull "+
    "black substance.  The outter surface of the armor "+
    "is continually interrupted by the numerous stitches "+
    "in their task of connecting the strips.  The inside of the "+
    "armor has been covered tightly with a thin and dark gray "+
    "fabric that offers a slight relief from the bumpier outter "+
    "surface.  In spite of the many seams, the armor makes almost "+
    "no sound.%^RESET%^");
    set_value(1000);
    set_property("enchantment",3);
    set_item_bonus("stealth",1);
    set_wear((:TO,"wearme":));
    set_remove((:TO,"removeme":));
}

int wearme() {
    if(ETO->query_lowest_level() < 15) {
        write("The magic of the armor rejects you!");
        return 0;
    }
    write("%^BOLD%^%^BLACK%^You feel more accustomed to the "+
        "shadows around you as your movement becomes more honed "+
        "to silence.%^RESET%^");
    return 1;
}

int removeme() {
    write("Your movements return to normal as you feel your "+
        "knowledge of the shadows around you lesson.");
    return 1;
}