#include <std.h>
inherit "/d/common/obj/weapon/fan.c";

void create()
{
   	::create();
   	set_name("leaf fan");
   	set_short("%^BOLD%^%^GREEN%^L%^RESET%^%^GREEN%^e%^BOLD%^"+
		"a%^RESET%^%^GREEN%^f %^BOLD%^Blade Fan%^RESET%^");
   	set_obvious_short("%^RESET%^%^GREEN%^A fan made from leaves%^RESET%^");
   	set_id(({"leaf blade fan","fan","leaf fan"}));
   	set_long("%^GREEN%^This %^ORANGE%^sandalwood%^GREEN%^ base "+
		"fan is truly a marvel to behold.  The sandalwood base "+
		"provides a sturdy frame from the delicate looking fan.  "+
		"Opening the fan up reveals six large %^BOLD%^leaves"+
		"%^RESET%^%^GREEN%^ that have been magically grafted to"+
		" the sandalwood base.  The thin and narrow leaves taper"+
		" to a fine point.  The razor sharp leaves look as if they"+
		" could slice through nearly anything with ease.  Carved "+
		"into the fragrant base of the fan is a %^MAGENTA%^f%^BOLD%^"+
		"l%^WHITE%^or%^MAGENTA%^a%^RESET%^%^MAGENTA%^l%^GREEN%^ vine"+
		" pattern, echoing the nature theme of this unusual weapon."+
		"\n%^RESET%^"); 
	set_lore("Used by the nymphs, the leaf blade fans are a perfect "+
		"weapon for these women.  Though nymphs usually retreat "+
		"from a battle, they have found sometimes they must fight"+
		" to protect the beauty of nature.  Thus the leaf blade "+
		"fans were born.  Crafted from sandalwood and razor leaves,"+
		" the fan is enchanted with fey magic to never wilt or "+
		"crumble.  The nymphs have made effective use of these fans.");
   	set_property("lore difficulty",10);
   	set_value(200);
   	set_property("enchantment",2+random(2));
	set_item_bonus("attack bonus",2);
   	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
   	tell_room(EETO,"%^BOLD%^%^GREEN%^%^"+ETOQCN+" slides "+ETO->QP+" "+
		"fan open to reveal the leaf interior of the fan.",ETO);
	tell_object(ETO,"%^GREEN%^%^BOLD%^You slide the fan open to reveal"+
		" the leaves inside.%^RESET%^");
	return 1;
}
int unwield_func(){
	tell_room(EETO,"%^GREEN%^"+ETOQCN+" slides "+ETO->QP+" fan closed, hiding the leaves away.",ETO);
	tell_object(ETO,"%^GREEN%^You slide the fan closed, hiding the leaves away.%^RESET%^");
	return 1;
}

int hit_func(object targ){
	if(!objectp(ETO)) return 1;
  	if(!objectp(targ)) return 1;

   if(!random(18)) {
      tell_object(ETO,"%^GREEN%^The %^MAGENTA%^floral%^GREEN%^ pattern "+
		"on the fan begins to %^BOLD%^%^MAGENTA%^glow%^RESET%^%^GREEN%^"+
		", leaving you feeling invigorated.");
      tell_room(environment(ETO),"%^GREEN%^"+ETO->QCN+"'s fan "+
		"%^BOLD%^%^MAGENTA%^glows%^RESET%^%^GREEN%^ for a moment,"+
		" leaving "+ETO->QO+" looking invigorated. and refreshed.",({ETO}));
      		ETO->do_damage("torso",-(random(5)+2));
                	targ->do_damage("torso",random(5)+2);
      return 1;
   }
   if(!random(8)) {
      tell_object(ETO,"%^BOLD%^%^GREEN%^You swiftly slash into "+targ->QCN+".");
      tell_object(targ,"%^BOLD%^%^GREEN%^"+ETO->QCN+" swiftly slashes into you.");
      tell_room(environment(ETO),"%^GREEN%^"+ETOQCN+" swiftly slashes into "+
		""+targ->QCN+".",({ETO,targ}));
      		targ->do_damage("torso",random(3)+3);
      return 1;
   }
}
