#include <std.h>
inherit "/std/armour";

void create(){
        ::create();
  	set_name("gold headdress");
    	set_id(({ "headdress", "gold headdress" }));
  	set_short("%^YELLOW%^Gold Headdress%^RESET%^");
      set_obvious_short("%^YELLOW%^Gold Headdress%^RESET%^");
      set_long( "%^YELLOW%^Shimmering from the sheer multitude of"+
		" gold used in this headdress, this piece of jewelry would"+
		" make anyone feel special.  Twin long lengths of gold"+
		" curl out on either side of the head.  Rising up over the"+
		" head, these twin curls are joined to two smaller curls. "+
		" The smaller curls, secured to the base of the headdress,"+
		" give stability to the larger curls.  A multitude of thin"+
		" gold disks hang from each curl.  The disks sway and"+
		" sparkle in the light with even the slightest movement."+
		"%^RESET%^\n");
      set_weight(4);
      set_value(500);
	set_cointype("electrum");
      set_lore( "Worn by the Cacophony Sirens, this headdress"+
		" adds an exotic touch to any outfit.");
      set_property("lore difficulty",5);
      set_type("ring");
      set_limbs(({ "head" }));
      set_size(2);
      set_wear((:TO,"wear_func":));
      set_remove((:TO,"remove_func":));
}
int wear_func(){
     	tell_room(environment(ETO),"%^YELLOW%^"+ETOQCN+" places"+
		" the headdress on "+ETO->QP+" head. The gaudy headdress"+
		" sparkles in the light.",ETO);
      tell_object(ETO,"%^YELLOW%^You place the base of the"+
		" headdress on your head, feeling like some exotic"+
		" creature.");
     		return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^YELLOW%^"+ETOQCN+" takes "+
		"the headdress of "+ETO->QP+" head, giving a heavy sigh.",ETO);
        tell_object(ETO,"%^YELLOW%^You feel less exotic after "+
		"removing the headdress.");
        	return 1;
}
