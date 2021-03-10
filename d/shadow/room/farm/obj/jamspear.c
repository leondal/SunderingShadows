#include <std.h>
inherit "/d/common/obj/weapon/mspear.c";

void create()
{
   	::create();
   	set_name("silver spear");
   	set_short("%^BOLD%^%^GREEN%^M%^RESET%^%^ORANGE%^a%^MAGENTA%^J %^BOLD%^%^GREEN%^Ic Spear%^RESET%^");
   	set_obvious_short("%^BOLD%^%^WHITE%^A silver medium spear%^RESET%^");
   	set_id(({"jam spear","silver spear","spear","medium spear"}));
   	set_long("%^BOLD%^%^WHITE%^Made of silver, this medium spear "+
		"has been mounted onto an oak shaft.  The leaf shape "+
		"spearhead has been hammered paper thin, with the edges"+
		" and tip sharpened to a fine point.  Across the surface"+
		" of the spearhead, minute hole can be seen drilled into"+
		" the soft metal."); 
   	set_value(100);
	set_lore("Actually the true name of this spear is the Jam Spear, "+
		"created by the gnomish inventor Piaf Huffelmuffin.  Piaf, "+
		"an absent minded genius, had originally wanted to name the"+
		" spear the Jam Spear.  Because his notes were so sticky from"+
		" a combination of orange marmalade and blackberry jam, he found"+
		" them difficult to read.  Thus the name maJ ic Spear came about."+
		"  Piaf, if questioned about this will deny everything of course."+
		"  Claiming that the true name of the spear is Marmalade and Jam in "+
		"the Canister Spear.  The spear was originally designed by Piaf to "+
		"allow him to spread his buttered toast with either orange marmalade"+
		" or blackberry jam without having to cross the room. - An Observation"+
		" of Piaf - Theadora Illonium");
	set_property("lore",5);
   	set_property("enchantment",1);
   	set_hit((:TO,"hitme":));
   	set_wield("%^BOLD%^As you heft the spear up, you can feel "+
		"something moving around inside the shaft.");
	set_unwield("%^BOLD%^You release the spear, still feeling the substance"+
		" moving around inside the shaft.");
}

int hitme(object targ)
{
   targ = ETO->query_current_attacker();
   if(!random(8)) {
      tell_object(ETO,"%^ORANGE%^%^Orange marmalade shoots out of "+
		"the holes of the spear, covering"+
      	" "+targ->QCN+" with the sticky jam.");
      tell_object(targ,"%^ORANGE%^From "+ETO->QCN+"'s spear, orange marmalade"+
		" shoots out, covering you with the sticky mess.");
      tell_room(environment(ETO),"%^ORANGE%^From "+ETO->QCN+"'s spear"+
      	" orange marmalde shoots forth, covering"+
      	" "+targ->QCN+" with the sticky mess.",({ETO,targ}));
      	     	targ->do_damage("torso",random(4)+1);
      return 1;
   }
   if(!random(16)) {
      tell_object(ETO,"%^MAGENTA%^From your spear a spray of hot "+
		"blackberry jam showers "+targ->QCN+".");
      tell_object(targ,"%^MAGENTA%^From "+ETO->QCN+"'s spear, "+
      	"a spray of hot blackberry jam showers you!");
      tell_room(environment(ETO),"%^MAGENTA%^Hot blackberry jam shoots forth from"+
      	" "+ETO->QCN+"'s spear, showering "+targ->QCN+" with the "+
		"sticky mess.",({ETO,targ}));
      		targ->do_damage("torso",random(8)+2);
      return 1;
   }
}
