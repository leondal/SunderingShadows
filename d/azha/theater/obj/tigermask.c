#include <std.h>
inherit "/d/common/obj/clothing/hat";

void create(){
   	::create();
 	set_name("tiger mask");
      set_id(({ "tiger mask","mask" }));
      set_short("%^RESET%^%^ORANGE%^T%^BOLD%^%^BLACK%^i%^RESET%^"+
		"%^ORANGE%^g%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^r"+
		"%^BOLD%^%^BLACK%^ Mask%^RESET%^");
     	set_obvious_short("%^RESET%^%^ORANGE%^A tiger mask%^RESET%^");
      set_long( "%^ORANGE%^Looking like a snarling head of a "+
		"tiger this mask has a frightful appearance.  The full "+
		"mask covers the entire head of the wearer, obscuring their"+
		" face from view.  The eyes of the mask are cut open, to "+
		"allow the wearer to see out.  The inside of the tiger's "+
		"mouth is covered with a thin fabric, that allows the "+
		"wearer to speak and breath, but hides their face from "+
		"view.  The tiger fur that covers the mask has a "+
		"coarseness to it, leading you to believe that it "+
		"might be the true thing.  Though the mask is hot "+
		"and can be uncomfortable, it still looks "+
		"impressive.%^RESET%^\n");
     	set_weight(5);
      set_value(500);
      set_lore( "The Two Faced Rakshasa, a heroic play about a"+
		" Rakshasa having to choose between his old life and new,"+
		" was the seventh play by the famous playwrite Prenicus."+
		"  The play was not well received for many found the "+
		"frightening appearance of the Rakshasa to be difficult"+
		" to take as an anti-hero. Lemons and Limes - "+
		"A History of Failed Plays - Devin Igarn");
    	set_property("lore difficulty",13);
     	set_type("leather");
     	set_limbs(({ "head" }));
      set_size(2);
      set_property("enchantment",2);
	set_ac(0);
     	set_wear((:TO,"wear_func":));
      set_remove((:TO,"remove_func":));
}
int wear_func(){
      tell_room(environment(ETO),"%^ORANGE%^"+ETOQCN+" covers "+
		""+ETO->QP+" face with a tiger mask.%^RESET%^",ETO);
      tell_object(ETO,"%^ORANGE%^You place the mask over your "+
		"head, hiding your face from view.%^RESET%^");
     	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^ORANGE%^"+ETOQCN+" pulls off"+
		" "+ETO->QP+" mask, giving you a clear look at "+
		""+ETO->QP+" face.%^RESET%^",ETO);
      tell_object(ETO,"%^ORANGE%^You pull the mask off, "+
		"exposing your face again to the world.");
     	return 1;
}
