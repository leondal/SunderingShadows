#include <std.h>
inherit "/d/common/obj/weapon/rapier.c";

void create()
{
   	::create();
   	set_name("fencing foil");
   	set_short("%^BOLD%^%^CYAN%^Fencing Foil%^RESET%^");
   	set_obvious_short("%^BOLD%^%^CYAN%^A fencing foil%^RESET%^");
   	set_id(({"fencing foil","foil","rapier","rapier"}));
   	set_long("%^BOLD%^%^CYAN%^This lightweight foil is "+
		"made from steel.  The flexible foil is prized"+
		" by duelists and swashbucklers for its ability"+
		" to slip easily around the guard of shield, "+
		"weapons, and armor.  The thin blade is made "+
		"hollowed steel, allowing to bend easily without"+
		" breaking.  A steel cap hilt help to protect the"+
		" duelists' hand from counter attacks.  A rounded"+
		" sphere of steel caps off the pommel of the "+
		"blade.%^RESET%^\n"); 
   	set_value(75);
	set_lore("Fencing foils are common with in the noble "+
		"society.  Across the cities Duelist Guilds have"+
		" began to pop up where those with enough wealth "+
		"and status can practice the craft of fencing.  "+
		"Though that is not to say the rapier and foil "+
		"are only for the high born.  Several bandits "+
		"find a use for the flexibility of the foil.  And"+
		" one can never forget how the swashbuckler makes"+
		" the art of fencing seem stylish and flamboyant.");
	set_property("lore",5);
   	set_property("enchantment",1);
   	set_hit((:TO,"hitme":));
   	set_wield("%^CYAN%^The foil seems light and flexible in your hand.");
	set_unwield("%^CYAN%^You find a place to sheath your foil.");
}

int hitme(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;

	   if(!random(8)) {
      	tell_object(ETO,"%^CYAN%^%^You give a fanciful flourish of your "+
			"foil before tagging "+targ->QCN+" twice!");
      	tell_object(targ,"%^CYAN%^"+ETO->QCN+" gives a fanciful flourish"+
			" of "+ETO->QP+" foil before tagging you!");
      	tell_room(environment(ETO),"%^CYAN%^"+ETO->QCN+" gives a fanciful"+
			" flourish of "+ETO->QP+" foil before tagging"+
      		" "+targ->QCN+".",({ETO,targ}));
      	     		targ->do_damage("torso",random(4)+2);
      return 1;
   }
}
