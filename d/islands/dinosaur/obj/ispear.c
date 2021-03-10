//Updated Ivory Spear - Cythera 7/05
#include <std.h>
#include "/d/islands/dinosaur/short.h"

inherit "/d/common/obj/weapon/mspear.c";

void create(){
    ::create();
    set_name("%^BOLD%^%^WHITE%^Iv%^YELLOW%^o%^WHITE%^ry Spear%^RESET%^");
    set_id( ({"spear", "ivory", "ivory spear"}) );
    set_short("%^RESET%^%^BOLD%^Iv%^YELLOW%^o%^WHITE%^ry Spear%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^An iv%^YELLOW%^o%^WHITE%^ry spear%^RESET%^");
    set_long("This long finely crafted spear has been made from "+
		"the %^BOLD%^%^WHITE%^ivory%^RESET%^ taken from the"+
		" bones and teeth of a large creature.  The shaft of "+
		"spear is pure %^BOLD%^%^WHITE%^iv%^YELLOW%^o%^WHITE%^ry"+
		"%^RESET%^, polished smooth.  While cool to the touch, "+
		"the shaft feels solid and strong.  Grafted to the shaft"+
		" is an eliptical spearhead, made from %^BOLD%^%^WHITE%^iv"+
		"%^YELLOW%^o%^WHITE%^ry%^RESET%^ as well.  Detailed "+
		"carvings create a latice type effect to the spearhead, "+
		"making it look far more fragile than it really is.  Inside"+
		" open carved spearhead a floating %^BOLD%^white orb%^RESET%^"+
		" can be seen, hovering in the air.%^RESET%^");
     set_lore("The Ivory Spear goes by many names, depending on the"+
		" person.  To some it is known as Reptilebane, the deadly "+
		"spear that slays any reptile, no matter the size.  To the "+
		"Aurilites it is commonly known as The Spear of Snowfalls, "+
		"for its connection to frost and ice.  Those of Kossuth know "+
		"it as one of two names, Firebane or Tinder Spear.  With so "+
		"many names for one spear its near impossible to find who "+
		"first created the spear and for what purpose it was used.  "+
		"One thing is for sure, the Ivory Spear, as its more commonly"+
		" known, is a trusted weapon of many folk.");
	set_property("lore",12);
   	set_value(1200);
   	set_hit((:TO,"hitme":));
   	set_property("enchantment",3);
   	set_wield((:TO,"wield_func":));
   	set_unwield((:TO,"unwield_func":));
}
int wield_func(string str) {
   if((int)ETO->query_level() < 16) {
      tell_object(ETO,"%^BOLD%^%^WHITE%^The spear fades away as you"+
		" try to wield it, only to resolidify.");
     	return 0;
}
   	tell_object(ETO,"%^BOLD%^The spear seems cool to the touch as"+
		" you grasp the shaft.\nA strange power seems to ebb "+
		"through the spear as you wield it.");
     	return 1;
}
int unwield_func(string str) {
   	tell_object(ETO,"%^BOLD%^You release your hold of the ivory"+
		" shaft of the spear, feeling the strange power fade away.");
     	return 1;
}

int hitme(object targ)
{
   if(!random(8)) {
      tell_object(ETO,"%^BOLD%^%^WHITE%^You jab your spear twice into "+targ->QCN+".");
      tell_object(targ,"%^BOLD%^%^WHITE%^"+ETO->QCN+" jabs "+ETO->QP+" "+
		"spear into you twice!");
      tell_room(environment(ETO),"%^BOLD%^%^WHITE%^"+ETO->QCN+" jabs"+
      	" "+ETO->QP+" spear into "+targ->QCN+" twice.",({ETO,targ}));
      		ETO->execute_attack();
      return 1;
   }
   if(!random(16)) {
      tell_object(ETO,"%^BOLD%^The white orb inside the spearhead begins to"+
		" spin wildly, releasing a burst of frost into"+
		" "+targ->QCN+".");
      tell_object(targ,"%^BOLD%^The white orb inside "+ETO->QCN+"'s"+
		" spearhead begins to spin wildly, releasing a burst of"+
		" frost that freezes you.");
      tell_room(environment(ETO),"%^BOLD%^The white orb inside "+
		""+ETO->QCN+"'s spearhead begins to spin wildly,"+
		" releasing a burst of frost that freezes "+targ->QCN+"'s"+
		" flesh.",({ETO,targ}));
			ETO->set_property("magic",1);
targ->do_damage("torso",random(8)+4);
			ETO->set_property("magic",-1);
  	return 1;
   }
   if(!random(50)) {
      tell_object(ETO,"%^BOLD%^Vapors and water collect into an "+
			"orb around your spearhead. With a fling of "+
			"your spear, you send the orb of frost and ice "+
			"speeding towards "+targ->QCN+".");
      tell_object(targ,"%^BOLD%^Vapors and watter collect into"+
		" an orb around "+ETO->QCN+"'s"+
		" spearhead.\n With a fling of "+ETO->QP+" spear,"+
		" "+ETO->QCN+" sends the orb of frost and ice "+
		"speeding towards you!");
      tell_room(environment(ETO),"%^BOLD%^Vapors and watter collect into"+
		" an orb around "+ETO->QCN+"'s"+
		" spearhead.\n With a fling of "+ETO->QP+" spear,"+
		" "+ETO->QCN+" sends the orb of frost and ice "+
		"speeding towards "+targ->QCN+"!",({ETO,targ}));
                        new("/cmds/spells/f/_frost_orb")->use_spell(ETO,targ,20,100,"mage");
  	return 1;
   }

}
