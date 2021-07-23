#include <std.h>
inherit "/d/common/obj/weapon/lance.c";

void create(){
	::create();
	set_name("sapphire lance");
	set_id(({ "sapphire lance", "lance", "lance of the stars", "star lance" }));
	set_short("%^BOLD%^%^BLUE%^L%^CYAN%^a%^RESET%^%^CYAN%^n%^BLUE%^c%^BOLD%^e %^RESET%^%^CYAN%^o%^BOLD%^%^BLUE%^f t%^CYAN%^h%^RESET%^%^CYAN%^e%^BOLD%^%^BLUE%^ S%^RESET%^%^BLUE%^t%^BOLD%^%^CYAN%^a%^RESET%^%^CYAN%^r%^BOLD%^%^BLUE%^s%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLUE%^s%^BOLD%^%^CYAN%^a%^RESET%^%^CYAN%^p%^BLUE%^p%^BOLD%^hi%^CYAN%^r%^RESET%^%^BLUE%^e %^BOLD%^l%^RESET%^%^CYAN%^a%^BLUE%^n%^BOLD%^%^CYAN%^c%^BLUE%^e%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLUE%^The wood used to make this lance is of such a deep and dark %^RESET%^%^BLUE%^blue%^BOLD%^, that when polished it gleams as though it were a pure piece of dark blue s%^BOLD%^%^CYAN%^a%^RESET%^%^CYAN%^p%^BLUE%^p%^BOLD%^hi%^CYAN%^r%^RESET%^%^BLUE%^e%^BOLD%^.  The grip is wrapped in %^CYAN%^bright blue leather%^BLUE%^, trimmed in %^WHITE%^silver braid%^BLUE%^.  The hand guard is made of %^RESET%^titanium %^BOLD%^%^BLUE%^that glitters with hundreds of tiny facetted s%^BOLD%^%^CYAN%^a%^RESET%^%^CYAN%^p%^BLUE%^p%^BOLD%^hi%^CYAN%^r%^RESET%^%^BLUE%^e%^CYAN%^s%^BOLD%^%^BLUE%^.  At the end of the lance the tip has also been capped with a sharp %^RESET%^titanium tip%^BOLD%^%^BLUE%^, making it a dangerous weapon.%^RESET%^

AVATAR
	);
	set_value(0);
	set_lore(
@AVATAR
The sapphire lance is said to have been created when a lightning bolt from the sky stuck an ancient blue cedar during a very powerful and raging storm. The trunk of the tree was severed and within the core, a perfect sliver of straight and perfect wood was found.  As the wood was treated the deep blue coloring became obvious and the weaponsmith who worked on the weapon night and day, soon discovered that the wood had also been touched with something else.  A gift from the stars!

AVATAR
	);
	set_property("lore difficulty",20);
   while ((int)TO->query_property("enchantment") != 2) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",2);
   }
      set_item_bonus("attack bonus",1);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
   set_overallStatus(220);
   set_property("no disenchant",1);
}
int wield_func(){
	tell_object(ETO,"%^BOLD%^%^CYAN%^The "+query_short()+" %^BOLD%^%^CYAN%^settles into your hand as though it were an extension of your arm.%^RESET%^");
	return 1;
}
int unwield_func(){
	tell_object(ETO,"%^BOLD%^%^CYAN%^With a bit of reluctance you set the "+query_short()+" %^BOLD%^%^CYAN%^aside.%^RESET%^");
	return 1;
}
int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 300){
	tell_room(environment(query_wielded()),"%^BOLD%^%^CYAN%^The wood of "+ETOQCN+"'s lance begins to %^BOLD%^%^BLUE%^glow brilliantly%^CYAN%^ just before they strike!  Like a %^BLUE%^blue star%^CYAN%^ bursting to life as it drives into "+targ->QCN+"!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^CYAN%^The wood of the lance begins to %^BOLD%^%^BLUE%^glow brilliantly%^CYAN%^ just before you strike!  Like a %^BLUE%^blue star%^CYAN%^ bursting to life as it drives into "+targ->QCN+"!%^RESET%^");
	tell_object(targ,"%^BOLD%^%^CYAN%^The wood of "+ETOQCN+"'s lance begins to %^BOLD%^%^BLUE%^glow brilliantly%^CYAN%^ just before they strike!  Like a %^BLUE%^blue star%^CYAN%^ bursting to life as it drives into you!%^RESET%^");
		return roll_dice(2,6)+0;	}
}