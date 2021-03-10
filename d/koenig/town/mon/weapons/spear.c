//Updated weapon - Cythera 5/05\\
#include <std.h>
inherit "/d/common/obj/weapon/pick.c";

void create()
{
   	::create();
   	set_name("pick");
   	set_short("%^RESET%^%^ORANGE%^Earthmover's Pick%^RESET%^");
   	set_obvious_short("%^RESET%^%^ORANGE%^A bronze pick%^RESET%^");
   	set_id(({"pick","earthmover's pick","bronze pick"}));
   	set_long("%^ORANGE%^Forged from bronze this war pick"+
		" is a strengthen version of its mining counterpart."+
		"  The worn bronze point still looks sharp enough to "+
		"pierce through metal or flesh.  The pick is mounted "+
		"onto a bronze handle that has been wrapped with earth"+
		" brown wool.  The image of a mountain is pressed into "+
		"the %^RED%^garnet%^ORANGE%^ gem set into the handle"+
		" of the pick.\n"); 
   	set_value(175);
   	set_property("enchantment",1);
	set_lore("The Earthmover's Pick is an item that has a "+
		"gnomish origin.  The pick was crafted by the gnomes"+
		" when they found their mines invaded by kobolds seeking"+
		" to prey on their small size.  The gnomes, usually a "+
		"peaceful folk, found themselves immersed in a battle with"+
		" the kobolds that still lasts to this day and age.");
   	set_property("lore difficulty",7);

   	set_hit((:TO,"hitme":));
   	set_wield("%^ORANGE%^The pick feels heavy and solid in your hands.");
	set_unwield("%^ORANGE%^You unwield the solid and heavy pick.");
}

int hitme(object targ){
if(!objectp(targ)) return 0;
if(!objectp(ETO)) return 0;
   if(!random(7)) {
      tell_object(ETO,"%^ORANGE%^Clumps of dirt fall off the pick as you"+
		" deal a savage blow to "+targ->QCN+".");
      tell_object(targ,"%^ORANGE%^Clumps of dirt fall off "+ETO->QCN+"'s "+
		"pick as they deal a savage blow to you.");
      tell_room(environment(ETO),"%^ORANGE%^Clumps of dirt fall off of "+ETO->QCN+"'s"+
		" pick as they deal a savage blow to"+targ->QCN+".",({ETO,targ}));
      		targ->do_damage("torso",random(4)+2);
	return 1;
   }
}