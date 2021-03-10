//added the size so item generator and cloning would make it right since it's
//supposed to be large - Styx 1/5/02
//moved hidden AC point to enchant, nienne 05/07
//Revised - Cythera 8/05
#include <std.h>

inherit ARMOUR;

void create() {
   	::create();
   	set_name("robe of moon");
   	set_id( ({"robe","moon","moon robe"}) );
	set_short("%^RESET%^%^CYAN%^Robe of the %^BOLD%^%^BLUE%^M%^CYAN%^o%^BLUE%^o%^CYAN%^n%^RESET%^");
        set_obvious_short("%^RESET%^%^CYAN%^A light blue robe%^RESET%^");
	set_long("%^CYAN%^This light blue colored robe is made of some "
      	"unknown material. The soft robe are cut full, allowing plenty of "+
		"room to move around in.  Trailing lines in shades of %^BOLD%^"+
		"%^BLUE%^b%^CYAN%^l%^BOLD%^%^BLUE%^u%^CYAN%^e%^RESET%^%^CYAN%^ "+
		"have been stitched into the light blue cloth, giving the robe a "+
		"touch of style.  The full sweeping sleeves of the robe stop in the"+
		" middle of the forearms, keeping them out of the way.  The robe is"+
		" on the shorter side, hemmed halfway between the knees and ankles. "+
		" The inside of the robe is lined with washed silk, which gives the"+
		" fabric an uneven, but pleasant, texture.%^RESET%^\n");
	set_lore("Crafted by a Warrior-Wizard Voadkyn by the name of Oldiarn, the"+
		" Moon Robes were woven from spidersilk and moonbeams, some claim.  "+
		"It is true that Oldiarn was a loyal follower of Selune, waging a "+
		"war against the Sharran of the lands.  The massive voadkyn was well"+
		" known for his silver falchion that he wielded in battle, as well as"+
		" his deadly Art.");
	set_property("lore",9);
   	set_weight(5);
   	set_type("clothing");
   	set_limbs( ({"torso"}) );
   	set_size(3);
      set_property("enchantment",5);
      set_item_bonus("sight bonus",2);
   	set_value(300+random(2)*300);
   	set_wear( (: TO,"wear_func" :) );
   	set_remove( (: TO,"remove_func" :) );
}

int wear_func() {
	tell_room(environment(ETO),"%^CYAN%^"+ETOQCN+" pulls the stylish"+
	  	" robes on.\n%^BOLD%^%^CYAN%^The robes start to shed a pale glow.",ETO);
   	tell_object(ETO,"%^CYAN%^You pull the stylish robe on,"+
		" feeling the soft fabric against your skin.\n"+
		"%^BOLD%^%^CYAN%^The robes start to shed a pale glow.");   
   	return 1;
}

int remove_func() {
	tell_room(environment(ETO),"%^CYAN%^"+ETOQCN+" pulls the stylish"+
		" robe off.",ETO);
      tell_object(ETO,"%^CYAN%^You pull off the stylish robes."+
		"  The pale glow of the robes goes dim.");
   	return 1;
}
