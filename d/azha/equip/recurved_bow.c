// Tsarvani recurved bow
// Thorn@ShadowGate
// 000912
// Imperial Tsarvani Army
// recurved_bow.c

#include <std.h>

inherit LRWEAPON;

void create(){
	::create();
	set_name("Tsarvani light recurved bow");
	set_id(({"Tsarvani light recurved bow","bow","light recurved bow",}));
	set_short("Tsarvani light recurved bow");
	set_long(
@WEAPON
This is a composite recurved bow such as is made for the Imperial Army
of Tsarven and many inhabitants of Oudh Province of that same Empire. 
The outer arms of the bow are curved away from the archer when the bow
is strung, which imparts a mechanical advantage at the end of the draw,
hence the name "recurved".  The composite bows superior pull weight is
increased by reinforcing the rear, or belly, of the bow with horn. Its
speed and power in recoil are increased by overlaying the front of the
bow with sinew, usually applied under tension. The wooden structure of
this composite thus consists of little more than thin wooden strips
supporting the horn and sinew.  This powerful composite bow, being very
highly stressed, will actually reverse its curvature when unstrung.
This particular weapon is made for a high rate of fire and light weight
over hitting power and is usually used by Imperial light cavalry and
other horse archers.
WEAPON
        );
	set_weight(5);
	set_size(2);
	set_rate_of_fire(3);
    set_lr_prof_type("recurved bow");
	set_range(4,8,12);
	set_type("bludgeoning");
//        set_lr_type("piercing"); thieves can't use it so let it default to piercing to fix shop list confusion *Styx*  11/14/04
	set_ammo("shortbow arrow");
    set_prof_type("club");
	set_value(100);
	set_wc(1,7);
	set_large_wc(1,7);
	set_decay_rate(100);
	set_two_handed();
}   
