#include <std.h>
inherit "/d/common/obj/weapon/fan.c";

void create()
{
   	::create();
   	set_name("shadow's veil fan");
   	set_short("%^BOLD%^%^BLACK%^Sh%^RESET%^%^CYAN%^a"+
		"%^BOLD%^%^BLACK%^d%^RESET%^%^MAGENTA%^o%^BOLD%^%^BLACK%^w's"+
		" V%^RESET%^%^MAGENTA%^e%^CYAN%^i%^BOLD%^%^BLACK%^l Fan%^RESET%^");
   	set_obvious_short("%^BOLD%^%^BLACK%^A darksteel base fan%^RESET%^");
   	set_id(({"shadow's veil fan","fan","lace fan","black lace fan"}));
   	set_long("%^CYAN%^The %^RESET%^%^MAGENTA%^darksteel"+
		" %^CYAN%^frame of this war fan complements the"+
		" %^BOLD%^%^BLACK%^black lace%^RESET%^%^CYAN%^"+
		" interior perfectly.  The darksteel exterior "+
		"of the fan is embossed with a trio of stacked "+
		"diamond shapes, raised up from the %^RESET%^"+
		"%^MAGENTA%^purple%^CYAN%^ sheen metal.  Opening"+
		" the fan up reveals seven sharp stiletto points "+
		"for the ribs of the fan.  Exotic %^BOLD%^%^BLACK%^"+
		"black lace%^RESET%^%^CYAN%^, finer than anything "+
		"you've ever seen, covers the interior of the fan.  "+
		"The lace pattern features a repetitious image of "+
		"ethereal like %^BOLD%^%^BLACK%^black swirls%^RESET%^"+
		"%^CYAN%^, highly uncommon for lace.  A cabochon cut"+
		" %^BOLD%^%^BLACK%^black jade%^RESET%^%^CYAN%^ stone"+
		" is attached to the base of the fan.  Hanging from a"+
		" silken cord is a %^BOLD%^%^BLACK%^pitch black%^RESET%^"+
		"%^CYAN%^ silk tassel.\n%^RESET%^"); 
	set_lore("Rumored to have first been given to an assassin of"+
		" Mask by a succubus, the Shadow's Veil Fan has been a "+
		"weapon and tool used by an elite branch in the Shadow "+
		"King's church, the Shadow Dancers.  Women outnumber men"+
		" 10:1 within the Shadow Dancer's Guild.  The guild is "+
		"composed of skilled rogues who take the tenets of Mask's"+
		" faith several steps further than your average cutpurse."+
		"  Skilled in the art of disguise the Shadow Dancers find "+
		"it easy to slip into places no other thief or assassin "+
		"would dare to go.  Known among elite or enlightened circles"+
		" by the fans the use in combat and to slay their targets, "+
		"the Shadow Dancers have one of the highest success rates "+
		"among the assassins.  Some claim they are blessed by Mask "+
		"to be able to vanish within the shadows and end up miles "+
		"away. - Dancing with the Shadows - Imrissa Goldenrod");
   	set_property("lore difficulty",22);
   	set_value(2000);
   	set_property("enchantment",3);
   	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
   	tell_room(EETO,"%^BOLD%^%^BLACK%^%^"+ETOQCN+" slowly slides "+ETO->QP+" "+
		"fan open with a smirk on "+ETO->QP+" lips.",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You slide the fan open dramatically,"+
		" as you smirk.%^RESET%^");
	return 1;
}
int unwield_func(){
	tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETOQCN+" slowly slides "+ETO->QP+" fan closed.",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You slowly slide the fan closed.%^RESET%^");
	return 1;
}

int hit_func(object targ)
{
   if(!random(25)) {
      tell_object(ETO,"%^BOLD%^%^BLACK%^Your fan draws in the surrounding "+
		"light to it, soaking it in before releasing a ray of shadows "+
		"at "+targ->QCN+".");
      tell_room(environment(ETO),"%^BOLD%^%^BLACK%^The light about you"+
		" grows dimmer for a moment. A shadowy black ray shoots out"+
		" of "+ETO->QCN+"'s fan and into "+targ->QCN+".",({ETO}));
			set_property("magic",1);
                	targ->do_damage("torso",random(4)+8);
			remove_property("magic");
      return 1;
   }
   if(!random(8)) {
      tell_object(ETO,"%^BOLD%^%^BLACK%^You swiftly slash into "+targ->QCN+" "+
		"and twist your hand around to slice again!");
      tell_object(targ,"%^BOLD%^%^BLACK%^"+ETO->QCN+" swiftly slashes into you"+
		" and twist "+ETO->QP+" hand around to slice into you again!");
      tell_room(environment(ETO),"%^CYAN%^"+ETOQCN+" swiftly slashes into "+
		""+targ->QCN+" and twists "+ETO->QP+" hand around to follow "+
		"through with another attack.",({ETO,targ}));
      		targ->do_damage("torso",random(4)+2);
			ETO->execute_attack();
	return 1;
   }
}
