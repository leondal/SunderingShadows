#include <std.h>
inherit "/d/common/obj/jewelry/necklace";

string choose_protection();

void create(){

	::create();
	set_name("amulet");
	set_id(({ "amulet", "amulet of protection", "protection amulet", "crystal amulet", "blue crystal amulet", "blue amulet" }));
	set_short("%^BLUE%^A%^CYAN%^m%^RESET%^%^BLUE%^u%^CYAN%^l"+
    "%^RESET%^%^BLUE%^e%^CYAN%^t of Pr%^BOLD%^%^WHITE%^o%^CYAN%^"+
    "t%^BOLD%^%^WHITE%^e%^CYAN%^cti%^BOLD%^%^WHITE%^o%^CYAN%^"+
    "n%^RESET%^");
    set_obvious_short("%^BOLD%^%^BLUE%^A blue crystal amulet%^RESET%^");
    set_property("repairtype",({ "jewel" }));

    set_long("The cord of this necklace is made from several "+
    "thin strips of leather.  The strips have been woven so that "+
    "they intertwine harmoniously with one another to form a "+
    "much thicker piece of %^BOLD%^%^BLACK%^black leather%^RESET%^.  "+
    "The center of what is apparently meant to be the front of "+
    "the cord grasps a %^BLUE%^blue crystal%^RESET%^.  The crystal "+
    "has been cut so that almost every centimeter of its surface "+
    "forms another and somewhat different angle.  It is "+
    "large and the angles serve to grant it a reflective and "+
    "almost captivating quality.%^RESET%^");

    set_lore("Created by a guild of magi some many years ago "+
    "these amulets have all been remarkably similiar in design.  "+
    "They were enchanted to grant the wearer a protection from "+
    "the very aggressive magic that some who practive the art "+
    "like to employ.  Some say that they are still being forged "+
    "and circulated, the location of such work a mystery that is "+
    "likely to remain unsolved.");

	set_value(1000);
	set_size(-1);
	set_property("enchantment",3);
    set_wear((:TO,"wearme":));
    set_remove((:TO,"removeme":));
    set_item_bonus(choose_protection(), 10);
}

string choose_protection()
{
    int x;
    string myprot;
    string *possible_protections;
    possible_protections = ({"fire resistance", "cold resistance", "sonic resistance ", "acid resistance", "negative energy resistance", "positive energy resistance", "mental resistance"});   
    x = sizeof(possible_protections);
    myprot = possible_protections[random(x)];
    return myprot;
}

int wearme() {
  if(ETO->query_highest_level() <15) {
        tell_object(ETO,"%^BLUE%^The magic in the amulet is "+
        "too great for you to control!%^RESET%^");
        return 0;
    }
    tell_object(ETO,"%^BLUE%^An aura of protection flows out "+
    "from the crystal and encompasses you!%^RESET%^");
    return 1;
}

int removeme() {
    tell_object(ETO,"%^BLUE%^You shudder and feel somehow colder"+
    ".%^RESET%^");
    if(!ETO->query_invis()) {
        tell_room(EETO,ETOQCN+"%^BLUE%^ visibly shudders.%^RESET%^",
        ETO);
    }
    return 1;
}
