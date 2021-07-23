//Original by Lurue, ported for low vendor by Octothorpe

#include <std.h>
inherit "/d/common/obj/armour/fullplate.c";

void create(){
	::create();
	set_name("full plate");
	set_id(({ "battle's glory", "full plate", "plate", "armor" }));
	set_short("%^BOLD%^%^BLACK%^B%^RED%^a%^BLACK%^tt%^WHITE%^l"+
	   "%^BLACK%^e's G%^RED%^l%^BLACK%^ory%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^a %^RESET%^burnished%^BOLD%^"+
	   "%^BLACK%^ set of full plate%^RESET%^");
	set_long("%^RESET%^%^CYAN%^Sheets of burnished %^WHITE%^steel "+
	   "%^CYAN%^have been fitted together to form the basis of this "+
	   "elaborate suit of armor.  Decorated with an eye for function, "+
	   "none of the intricate decorations that depict the %^RED%^"+
	   "ebb%^CYAN%^-%^WHITE%^and%^CYAN%^-%^BOLD%^%^BLACK%^flow "+
	   "%^RESET%^%^CYAN%^of battle cause the plates to catch or "+
	   "grate upon each other.  Brushed with a %^BOLD%^%^BLACK%^"+
	   "darkening agent%^RESET%^%^CYAN%^, the steel has a lustrous "+
	   "sheen to it that catches faintly in the light and gleams "+
	   "with a %^WHITE%^dark silver%^CYAN%^ finish.  Atop each "+
	   "shoulder plate the symbol of the %^RED%^God of War "+
	   "%^CYAN%^can be seen.%^RESET%^");
	set_value(0);
	set_lore("The suit of armor called 'Battle's Glory' is actually "+
	   "several different sets of armor.  Made for a unit of elite "+
	   "knights and warriors sent by the temple to aid the southern "+
	   "empires during one of the many wars.  The warriors were known "+
	   "for their skill and their tenacity and are quoted as yelling "+
	   "'for the glory of battle.'  In time, due to the uniqueness of "+
	   "their armor, they became recognized as the 'Battle's Glory.'");
	set_property("lore difficulty",18);
	set_size(-1);
   while ((int)TO->query_property("enchantment") != 2) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",2);
   }
      set_item_bonus("attack bonus",1);
      set_item_bonus("damage bonus",1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
   set_overallStatus(220);
   set_property("no disenchant",1);
}

int wear_func(){
	tell_object(ETO,"%^BOLD%^%^RED%^You settle the plates of armor upon "+
	   "your shoulders and feel years of experience flood your mind. %^RESET%^");
	return 1;
}

int remove_func(){
	tell_object(ETO,"%^BOLD%^%^RED%^You draw the armor off and feel the "+
	   "heat of battle drain away.%^RESET%^");
	return 1;
}