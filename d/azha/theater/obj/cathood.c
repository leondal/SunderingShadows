#include <std.h>
inherit ARMOUR;

void create(){
	::create();
      set_name("cat hood");
     	set_id(({ "cat hood", "hood" }));
      set_short("%^RESET%^%^ORANGE%^Cat Hood%^RESET%^");
      set_obvious_short("%^RESET%^%^ORANGE%^A furry hood%^RESET%^");
      set_long( "%^ORANGE%^Crafted from soft fur is this little"+
		" hood.  The hood looks like something that a child might"+
		" wear or maybe part of a costume from some play.  The"+
		" furry hood covers the wear's head, leaving the face"+
		" exposed.  Jutting out from the top of the head are"+
		" a pair of cat like ears.  The ears are made from"+
		" the same fur with a lighter colored suede used"+
		" on the inner parts.  Lighter orange tabby "+
		"stripes break up the orange color of the fur."+
		"  Soft fuzzy ties hang from the bottom of the"+
		" hood with fluffy pom-poms on the ends.  The"+
		" ends look like they would tie under your chin.%^RESET%^\n");
      set_weight(5);
      set_value(500);
      set_lore("The Tabby Cat in Sandals was a comedy written"+
		" in 346.  The comdey goes on to tell about how a Tabby"+
		" Cat is granted her wish to be able to speak after "+
		"finding a pair of silver sandals, and the misadventures"+
		" that befall on her as she heads to Daggerdale.  The "+
		"play was a tried and true favorite that always left the"+
		" audience rolling with laughter. - A History of Plays"+
		" - Isley Threvet");
      set_property("lore difficulty",13);
      set_type("leather");
      set_limbs(({ "head" }));
      set_size(1);
      set_property("enchantment",1);
	set_ac(0);
      set_wear((:TO,"wear_func":));
      set_remove((:TO,"remove_func":));
}
int wear_func(){
      tell_room(environment(ETO),"%^ORANGE%^"+ETOQCN+" ties on "+
		""+ETO->QP+" cat hood and fluffs out the kitty ears.",ETO);
      tell_object(ETO,"%^ORANGE%^You tie the hood on in place "+
		"and fluff out the kitty ears, feeling just purrrrfect.");
      	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^ORANGE%^"+ETOQCN+" unties the"+
		" hood and pulls it off "+ETO->QP+" head.",ETO);
      tell_object(ETO,"%^ORANGE%^Ah is it time to take off the hood already?");
      	return 1;
}
