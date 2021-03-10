//Updated to bring in line with area difficulty - Octothorpe 4/15/10
//Changed to inherit claw.c - cythera 4/05
#include <std.h>
inherit "/d/common/obj/weapon/claw.c";

void create(){
	::create();
	set_name("katar");
	set_id(({ "katar", "dagger", "punching dagger","claws","shadow claws", "claw", "weapon" }));
	set_short("%^BOLD%^%^BLACK%^Shadow Claws%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^A blackened katar%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This is a katar, or more commonly known as a punching dagger. The blade appears to be forged out of silvery mithril but covered with some form of weaponblack that dulls the metallic surface of the weapon. A grip is mounted at ninety degrees to the blade between two parallel metal bars.  The inky black katar seems to absorb the light of the room.

AVATAR
	);
	set_lore("Shadow Claws are a form of punching daggers favored by the thieves of Mask.  Claiming to have been formed from the shadows themselves, the Shadow Cloaks train in use of these exotic weapons.  It is considered a great honor for a member of any Thieves Guild to be given a pair of Shadow Claws by a Priest of Mask.  Many assassins within the Lord of Thieves' faith utalize the Shadow Claws.");
	set_property("lore",13);
	set_value(357);
	set_property("enchantment",3+random(2));
	set_hit((:TO,"hit_func":));
}


int hit_func(object targ){
	if(!objectp(TO)) return 1;
   	if(!objectp(ETO)) return 1;
   	if(!objectp(targ)) return 1;
    	if(random(1000) < 200){
      	switch(random(10)){
case 0..5:
	tell_room(environment(ETO),"%^BOLD%^%^BLUE%^"+ETO->QCN+"%^BOLD%^%^BLUE%^ "+
		"jabs the katar forcefully into "+targ->QCN+"%^BOLD%^%^BLUE%^."+
		"%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^BLUE%^You jab the katar forcefully into"+
		" your opponent.%^RESET%^");
	tell_object(targ,"%^BOLD%^%^BLUE%^"+ETO->QCN+"%^BOLD%^%^BLUE%^ jabs"+
		" the katar forcefully into you.%^RESET%^");
			return roll_dice(2,3)+2;
break;
case 6..7:
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETO->QCN+"'s katar "+
		"seems to transmute into a shadowy substance, allowing "+
		""+ETO->QO+" to bypass "+targ->QCN+"'s defenses.",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^BLACK%^Your katar transmutes into a "+
		"shadowy substance, allowing you to bypass "+targ->QCN+"'s"+
		" defenses.%^RESET%^");
	tell_object(targ,"%^BOLD%^%^BLACK%^"+ETO->QCN+"'s katar seems to"+
		" transmute into a shadowy substance, allowing "+ETO->QO+""+
		" to bypass your defenses!%^RESET%^");
			set_property("magic",1);
			targ->do_damage("torso",random(5)+3);
			set_property("magic",-1);
break;
case 8..9:
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETO->QCN+" fades into the shadows, "+
		" then suddenly emerges behind "+targ->QCN+".",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^BLACK%^You feel yourself merge with the"+
		" shadows for one fleeting moment.  When you appear out of the"+
		" shadows "+targ->QCN+"'s back is before you defenses.%^RESET%^");
	tell_object(targ,"%^BOLD%^%^BLACK%^"+ETO->QCN+" fades into the shadows."+
		"  Where did .. AHH you feel a stinging pain in your back.%^RESET%^");
			ETO->execute_attack();			
break;

           }
   	return 1;
	}
}
