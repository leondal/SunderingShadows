//coded by Shar.  Replacing white smock along with ram jerkin
//Circe 4/26/04
#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("white bliaut");
	set_id(({ "white bliaut", "smock", "tunic", "shirt","bliaut" }));
	set_short("%^BOLD%^%^WHITE%^White Bliaut%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^A white sleeveless shirt%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^This sleeveless shirt is made of a mysterious fabric.  The white cloth gleams brilliantly, as if it has been newly laundered or freshly bleached.  The shirt looks as if it was made to fit snug to the body, hugging your torso.  A high collar rises up from the shirt, standing about half a fingers length high.  Ten  horizontal white laces runs down the front of the shirt.

AVATAR
	);
	set_weight(5);
	set_value(800);
	set_lore(
@AVATAR
The White Bliaut was once worn by a famed warrior of Torm named Adamovius Grey.  Adamovius was commited to Torm's cause and traveled the lands doing his duty to protect the weak and bring justice to the lands.  His fame spread from Azha all the way to Asgard around the year 420.  Though in the spring of 422 he mysterious vanished from the lands.  What ever happened to him, no one know.

AVATAR
	);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",2);
//        set_ac(1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(EETO,"%^BOLD%^%^WHITE%^"+ETOQCN+" pulls the bliaut on over "+ETO->QP+" head and adjusts the laces on the shirt.",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^You slip into the bliaut and can't help but feel comfortable in such a garment.");
	return 1;
}
int remove_func(){
	tell_room(EETO,"%^BOLD%^%^WHITE%^"+ETOQCN+" unlaces the bliaut and pulls the shirt off over "+ETO->QP+" head.",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^You unlace the bliaut and pull it off over your head.");
	return 1;
}
