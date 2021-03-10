// updated dex bonus from the new system. Nienne, 09/07.
#include <std.h>
inherit "/d/common/obj/armour/hide";

void create(){
	::create();
      set_name("leather bodice");
	set_id(({ "bodice", "body armor", "armor", "leather", "mesh" }));
      set_short("%^RESET%^%^MAGENTA%^Callista's Bodice%^RESET%^");
      set_obvious_short("%^RESET%^%^MAGENTA%^A leather bodice%^RESET%^");
        set_long("%^BLUE%^This suit of leather armor is form-fitting and "
"specifically designed for the female body. The front panel of the armor is "
"made from stiff, inflexible, %^MAGENTA%^violet leather%^BLUE%^ that is sure "
"to provide good protection. %^BOLD%^%^WHITE%^Titanium%^RESET%^%^BLUE%^ "
"clasps up the front of the bodice allow the armor to be buckled closed.  "
"The armor is cut rather low and is rather revealing of the female's torso.  "
"The cups of the bodice are covered with a soft %^MAGENTA%^velvet%^BLUE%^, in "
"a matching hue.  The strapless armor though often leaves others to wonder "
"how well something this skimpy might protect in battle.\n%^RESET%^");
      set_weight(9);
	set_value(5000);
	set_lore(
@AVATAR
The Leather and Mesh bodice is armor that the duelist Callista is rumored to have worn when she was last seen in Seneca.  Being a warrior of stealth and speed, Callista prized herself on being able to move with ease in combat, but still having a good amount of protection.  The armor is designed to play with a women's body to prey on the lustful nature of men.

AVATAR
	);
	set_size(2);
      set_property("enchantment",5);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
      set_item_bonus("dexterity",4);
}
int wear_func(){
   if((string)TP->query_gender() != "female") {
   write("Your body will not fit into this.");
      return 0;
   }
        tell_room(EETO,"%^MAGENTA%^"+ETOQCN+" buckles herself into the strapless leather bodice that molds to her curves.",ETO);
        tell_object(ETO,"%^MAGENTA%^You buckler yourself into the strapless leather bodice, feeling the leather mold to your curves.");
	return 1;
}
int remove_func(){
	tell_room(EETO,"%^MAGENTA%^"+ETOQCN+" loosens the buckles of the bodice, slipping out of the form fitting leather.",ETO);
	tell_object(ETO,"%^MAGENTA%^You loosen the buckles of the bodice, slipping out of the leather.");
	return 1;
}
