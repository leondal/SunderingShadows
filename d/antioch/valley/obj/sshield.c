//Added lore and inherits of sshield.c - Cythera 4/05\\
#include <std.h>
#include "../valley.h"
inherit "/d/common/obj/armour/sshield.c";
int is_metal() { return 0; }
void create()
{
	::create();
	set_name("sprite shield");
	set_id(({"shield","sprite shield","tiny shield","little shield","small shield"}));
	set_obvious_short("%^BOLD%^%^CYAN%^A little shield%^RESET%^");
	set_short("%^BOLD%^%^CYAN%^S%^BLUE%^pr%^GREEN%^i%^BLUE%^t%^CYAN%^e Shield%^RESET%^");
	set_long("%^BOLD%^%^CYAN%^Pale silvery birch wood is used in "+
		"the creation of this round shield.  A %^GREEN%^leaf%^CYAN%^"+
		" boarder encircles the outer edge of the shield, carved into"+
		" the wood.  On a closer inspection one can find %^RED%^birds%"+
		"^CYAN%^, %^YELLOW%^nuts%^CYAN%^, %^MAGENTA%^berries%^CYAN%^"+
		", %^WHITE%^rabbits %^CYAN%^and %^GREEN%^squirrels%^CYAN%^ "+
		"hiding in the leaf carving.  In the center of the shield is"+
		" the bright and colorful image of a %^BLUE%^to%^GREEN%^a"+
		"%^BLUE%^ds%^GREEN%^to%^BLUE%^ol%^CYAN%^."+
		"  The toadstool is painted on in shades of blue and green."+
		"  Inlaid into the toadstools cap, are %^GREEN%^vibrant green"+
		"%^CYAN%^ sparkling gems  creating the spots that all toadstools"+
		" have.");
	set_lore("The Sprite Shield is rumored to be made by sprites, "+
		"pixies and other such fey folk.  'The shield', a sage by"+
		" the name of Maraquath says, 'is made from a small piece of"+
		" wood.  Using faerie magic, they are able to shape the shield"+
		" from even the smallest twig.  Toadstools are seen as a good "+
		"luck charm in the fey world, thus it's not unknowing for them "+
		"to pop up on shields, armor and other trinkets.  The boarder "+
		"around the shield reflects the fey's love and dedication to "+
		"nature.'  Faerie Lore and Observations - by Maraquath Feldrsparn");
	set_property("lore",11);
	set_value(200);
	set_cointype("electrum");
	set_size(1);
	set_property("enchantment",2);
}
