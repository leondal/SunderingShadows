#include <std.h>
#include "../undead.h"


inherit "/d/common/obj/weapon/two_hand_sword";
/*
switch(random(9)) {
	
case 0:
inherit WPS"two_hand_sword";
break;
case: 1:
inherit WPS"katana";
break;
case 2:
inherit WPS"khopesh";
break;
case 3:
inherit WPS"light_rapier";
break;
case 4:
inherit WPS"rapier";
break;
case 5:
inherit WPS"scimitar";
break;
case 6:
inherit WPS"scythe";
break;
case 7:
inherit WPS"shortsword";
break;
case 8
inherit WPS"two_hand_scythe";
break;
case 9
inherit WPS"wakizashi";
break;
}
*/




create() 
{
    ::create();
//    set_id(({"sword","great sword","great","ancient","blade"}));
    set_name("ancient weapon");
    set_obvious_short("%^RED%^a blood-soaked blade%^RESET%^");
    set_short("%^RED%^Ancient bloodsoaked blade%^RESET%^");
    set_long("%^BOLD%^%^RED%^This ancient weapon is perhaps the most prized possession "
        "of Kartakass's elite troopers. Each blade was forged for one "
        "soldier personally, and is engraved with various runes telling "
        "various tales of battles won. The blade itself rises five feet "
        "into the air, forming one of the most deadly blades you have "
        "ever seen.");
    set_property("enchantment",3);
    set_value(1000);
    set_wield((:this_object(), "extra_wield":));
    set_unwield((:this_object(), "extra_unwield":));
	set_hit((:this_object(),"slackit":));
}

int smackit(object targi) {
	
	
	if(!objectp(targi)) return 0;
	if(!objectp(ETO)) return 0;
	targi = ETO->query_current_attacker();
	
	if(random(1000) < 100) {
		
		tell_object(ETO,"%^RESET%^%^MAGENTA%^Kartakass's%^RED%^ blessing flow you as you hit "+targi->QCN);
		tell_object(targi,"%^RESET%^%^MAGENTA%^You year a hollow laughter as "+ETO->QCN+"'s %^RESET%^%^MAGENTA%^weapon strikes you!",ETO);
		tell_room(EETO,ETO->QCN+" gives a hollow laughter as he strikes "+targi->QCN,({ETO,targi}));
		targi->do_damage(targi->return_target_limb(),roll_dice(2,4)+2);
		return 1;
		
	}
	
}

int extra_wield()
{
    if(!ETO->is_player()) { return 1; }
    if((int)TP->query_stat("strength") < 18 && (int)TP->query_level() < 15)
		
    {
        write("%^BOLD%^You try lifting the Great blade, but are forced to drop it quickly, it's blade "
            "breaking from the fall.%^RESET%^");
        TO->remove();
        return 0;
    }
    
    tell_object(this_player(),"%^BLUE%^A great evil enters your body as you "
        "wield this ancient weapon of malice.%^RESET%^");
		ETO->set_property("evil",1);
    return 1;
}

int extra_unwield()
{
    tell_object(this_player(),"%^BOLD%^%^RED%^A terrible scream echos from "
        "the weapon as you unwield it!%^RESET%^\n");
		ETO->set_property("evil",-1);
    return 1;
}
