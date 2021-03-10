#include <std.h>
inherit "/d/common/obj/clothing/hat";

void create(){
     	::create();
     	set_name("griffon mask");
     	set_id(({ "griffon mask","mask" }));
  	set_short("%^BOLD%^%^WHITE%^Gr%^YELLOW%^i%^WHITE%^ff%^YELLOW%^"+
		"o%^WHITE%^n Mask%^RESET%^");
      set_obvious_short("%^%^BOLD%^%^WHITE%^A griffon mask%^RESET%^");
      set_long( "%^BOLD%^%^WHITE%^More like a half mask rather than "+
		"a full one, this mask is made to looks like a proud griffon."+
		"  White feathers are attached to a leather frame, giving the"+
		" mask a realistic look.  While most of the feathers are whit"+
		"e, a few extra colors are added for depth.  Feathers in "+
		"%^YELLOW%^cream%^WHITE%^ and in %^RESET%^light gray%^BOLD%^"+
		" are added to the plumed mask.  The front of the mask featur"+
		"es wide open eyeholes, as to give an unobstructed view.  The"+
		" top portion of a large %^YELLOW%^golden beak%^WHITE%^ is at"+
		"tached to the mask, covering the wearer's nose.  The area be"+
		"low the beak is obscured in shadows, caused by the pronounce"+
		"d beak.  This mask looks rather hot to wear.%^RESET%^\n");
      set_weight(5);
      set_value(100);
      set_lore( "Though a minor character in The Two Faced Rakshasa"+
		", Gildore the Griffon serves as a part that most people can "+
		"easily identify with.  His strong moral convictions are what"+
		" pushes him forward, that and his skill as an archer.  Wanti"+
		"ng to help his Rakshasa friend redeem himself and throw off "+
		"the labels of his race, it is Gildore that serves as Rjarek'"+
		"s moral compass, and the only person he can fully trust.  Le"+
		"mons and Limes - A History of Failed Plays - Devin Igarn");
      set_property("lore difficulty",13);
      set_type("leather");
      set_limbs(({ "head" }));
     	set_size(2);
     	set_property("enchantment",2);
      set_wear((:TO,"wear_func":));
      set_remove((:TO,"remove_func":));
}
int wear_func(){
    	tell_room(environment(ETO),"%^BOLD%^%^WHITE%^"+ETOQCN+" pulls"+
                " the plumed mask over "+ETO->QP+" head, hiding "+
		""+ETO->QP+" face.%^RESET%^",ETO);
     	tell_object(ETO,"%^BOLD%^%^WHITE%^You place the mask over your"+
		" head, hiding your face from view.%^RESET%^");
      return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^WHITE%^"+ETOQCN+" pu"+
                "lls off "+ETO->QP+" mask, giving you a clear look "+
		"at "+ETO->QP+" face.",ETO);
      tell_object(ETO,"%^%^BOLD%^%^WHITE%^You pull the mask off, exp"+
		"osing your face again to the world.");
      return 1;
}
