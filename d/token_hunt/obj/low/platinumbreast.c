#include <std.h>
inherit "/d/common/obj/armour/breastplate.c";

void create(){
	::create();
	set_name("breastplate");
	set_id(({ "platinum breastplate", "breastplate", "platinum" }));
	set_short("%^BOLD%^%^WHITE%^Breastplate of the Platinum Dragon%^RESET%^");
        set_obvious_short("%^BOLD%^%^WHITE%^a platinum breastplate%^RESET%^");
	set_long("%^BOLD%^%^WHITE%^This breastplate is fashioned out of "+
	   "pure platinum!  The metal has been shaped and formed into a "+
	   "seamless breastplate, backing and two shoulderplates.  The "+
	   "breastplate secures in place on the side, though how it is "+
	   "not clearly visible.  Large sweeping shoulderplates dip down "+
	   "to merge with the main body of the armor, offering excellent "+
	   "protection to the shoulders and upper arms as well as the "+
	   "vital organs.  Etched onto the front of the armor is the "+
	   "image of a platinum dragon in flight.");
	set_value(0);
	set_lore("The Breastplate of the Platinum Dragons is a piece of "+
	   "armor left over from one of the generals of The Order of "+
	   "Metallic Dragons.  The general though met a horrible fate, a"+
	   "nd his armor since then has circulated many backdoor and "+
	   "underground shops.");
	set_size(-1);
   while ((int)TO->query_property("enchantment") != 2) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",2);
   }
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
   set_overallStatus(220);
   set_property("no disenchant",1);
	set_property("lore difficulty",14);
}
int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^WHITE%^An image of a platinum dragon on "+ETO->query_cap_name()+"%^BOLD%^%^WHITE%^'s breastplate sparks to life, and their armor encloses about them.",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^The eyes of the platinum dragon on the armor spark to life, locking the breastplate closed for you.");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^WHITE%^A clicking sound is heard as "+ETO->query_cap_name()+"%^BOLD%^%^WHITE%^'s armor suddenly opens on the sides.",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^The light dulls in the dragon's eyes, and your armor suddenly opens up on the sides.");
	return 1;
}