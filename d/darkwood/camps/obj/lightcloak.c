// changed to +1 with new enchantment settings, nienne 05/07
#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("cloak");
        set_id(({ "cloak", "cloak of dawn's light", "bright cloak","dawn cloak" }));
	set_short("%^YELLOW%^Cloak of %^MAGENTA%^Dawn's%^YELLOW%^ Light%^RESET%^");
	set_obvious_short("a bright cloak");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^This thin cloak has been crafted out of some mysterious fabric.  The fabric glows with a bright light in colors that fade from %^MAGENTA%^pink%^WHITE%^,%^RED%^red%^WHITE%^,%^YELLOW%^yellow%^WHITE%^, and %^RESET%^%^ORANGE%^orange%^BOLD%^%^WHITE%^, the colors of the sky at dawn.  There is a brilliant glow about it, as if it was woven from rays of sun itself!

AVATAR
	);
	set_weight(5);
	set_value(75);
	set_lore(
@AVATAR
The Cloak of Dawn's Light was without a doubt first seen in Lathander's clergy.  It was a way for his faithful to take his presence where ever he went.  Since then many of Selune, Eldath and Mielikki's faithful have discovered what a boon the cloak is on travels.

AVATAR
	);
	set_type("clothing");
	set_limbs(({ "neck" }));
        if(random(3)) set_size(2);
        else set_size(1);
        set_property("enchantment",1);
      set_item_bonus("sight bonus",1);
	set_ac(0);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^WHITE%^The light about you suddenly seem %^YELLOW%^brighter!",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^The light about you suddenly seem %^YELLOW%^brighter!");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^WHITE%^The lighting about you fades softly.",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^The lighting about you fades softly.");
	return 1;
}
