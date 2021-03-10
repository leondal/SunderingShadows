#include <std.h>
inherit "/d/common/obj/armour/buckler.c";
int is_metal() { return 0; }
void create()
{
   	::create();
   	set_name("sandalwood buckler");
   	set_short("%^BOLD%^%^WHITE%^Sandalwood Buckler%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^A sandalwood buckler%^RESET%^");
   	set_id(({"sandalwood buckler","wooden buckler","buckler","shield"}));
   	set_long("%^BOLD%^This is a lovely buckler made out of sandalwood."+
   		" It has been finely crafted and has a smooth surface that was left"+
   		" free of varnish. The wood itself gives off a light but pleasant"+
   		" fragrance. The edges of the buckler are carved with vines"+
   		" and flowers, subtle but pretty designs. It would fit nicely"+
   		" over the arm and provide a bit of protection.");
   	set_value(350);
   	//set_type("thiefshield");
   	//set_limbs(({"right hand"}));
   	//set_ac(1);
   	set_property("enchantment",2+random(2));
	set_property("lore",8);
	set_lore("Magically crafted these fragrant bucklers are a "+
		"testament to the problems that plague the Moonstone "+
		"Valley.  Dryads, typically peaceful gentle fey creatures,"+
		" have had to arm themselves for battle with the threats "+
		"that surround their beloved valley.  Always a creature of"+
		" grace and style the dryads have created these lovely "+
		"bucklers to aid them.  Using their fey magic they shape "+
		"and warp fallen limbs of sandalwood to craft each buckler."); 
   	set_wear("%^BOLD%^You slip the scented buckler over your arm.");
}
