#include <std.h>
inherit "/d/common/obj/weapon/large_battle_axe";

void create()
{
    ::create();
    set_name("large axe");
    set_id(({ "axe", "large axe", "splitter", "devians splitter", "large splitter" }));
    set_short("%^BOLD%^%^GREEN%^D%^BOLD%^%^BLACK%^e"+
    "%^BOLD%^%^GREEN%^v%^BOLD%^%^BLACK%^ia%^BOLD%^%^GREEN%^n's "+
    "Spl%^BOLD%^%^BLACK%^i%^BOLD%^%^GREEN%^tt%^BOLD%^%^BLACK%^"+
    "e%^BOLD%^%^GREEN%^r%^RESET%^");
    set_obvious_short("A large axe with an oak handle");

    set_long("%^GREEN%^This large weapon has a solid %^BOLD%^oak "+
    "handle %^RESET%^%^GREEN%^that spans approximately five feet "+
    "and is forced through the center of a %^BOLD%^%^BLACK%^dark "+
    "metal%^RESET%^%^GREEN%^ axe blade.  The axe blade is "+
    "perhaps a foot thick where it meets the handle and "+
    "narrows to less than half of that at the %^RESET%^lighter "+
    "%^GREEN%^colored and sharpened %^BOLD%^%^WHITE%^"+
    "edge%^RESET%^%^GREEN%^.  A phrase has been engraved "+
    "into the center of the blade and a %^RED%^red rust "+
    "%^GREEN%^stain lingers around it.  "+
    "Several disturbing images have been carved or %^BOLD%^%^BLACK%^"+
    "burned%^RESET%^%^GREEN%^ into the handle, they all depict "+
    "%^BOLD%^%^WHITE%^skeletal%^RESET%^%^GREEN%^ figures in "+
    "various positions.  In addition, the weight of "+
    "this weapon has been equally distributed to make sure "+
    "the wielder doesn't lose balance mid swing.%^RESET%^");

    set_read("%^RED%^Death comes swiftly to all..%^RESET%^");
    set_language("common");
    set_value(1000);
    set_lore("%^RED%^This weapon was formed for the murderer "+
    "Devian Hythok some centuries ago.  It was said to have "+
    "been a gift to him from a mage ally long before he began "+
    "his sudden spree of murders.  It was thought buried "+
    "with him and his accomplice long ago.%^RESET%^");
    set_property("enchantment",4);
    set_item_bonus("damage bonus",2);
	set_item_bonus("attack bonus",2);
    set_wield((:TO,"wield_me":));
    set_unwield("%^GREEN%^You release your hold on the strangely "+
    "balanced axe.%^RESET%^");
    set_hit((:TO,"hit_func":));
}

int wield_me() 
{
    tell_object(ETO,"%^GREEN%^You wield the strangely balanced axe."+
    "%^RESET%^");
    return 1;
}

int hit_func(object targ)
{
    string limb;
    if(!objectp(targ)) return 0;
    if(!objectp(ETO)) return 0;
    if(random(1000) < 400) 
    {
        switch(random(2)) 
        {
            case 0:
                limb = targ->return_target_limb();
                
                tell_room(EETO,ETO->QCN+"%^RED%^ cuts deep into "+
                "the flesh of "+targ->QCN+"%^RED%^'s "+limb+" with "+
                ETO->QS+" axe!%^RESET%^",({ETO,targ}));
	            
                tell_object(ETO,"%^RED%^You cut deep into the "+
                "flesh of "+targ->QCN+"%^RED%^'s "+limb+" with your "+
                "axe!%^RESET%^");
                
                tell_object(targ,ETO->QCN+"%^RED%^ cuts deep into "+
                "the flesh of your "+limb+" with "+ETO->QP+" axe!"+
                "%^RESET%^");

                return roll_dice(2,4) + random(3);
                break;

            case 1:
            
                tell_room(EETO,ETO->QCN+"%^BOLD%^%^BLACK%^ "+
                "growls loudly and sinks "+ETO->QP+" axe deep into "+
                targ->QCN+"%^BOLD%^%^BLACK%^!%^RESET%^",({targ,ETO}));                
	            
                tell_object(ETO,"%^BOLD%^%^BLACK%^You issue a loud "+
                "growl and sink your axe deep into "+targ->QCN+
                "%^BOLD%^%^BLACK%^!%^RESET%^");
                                
                tell_object(targ,ETO->QCN+"%^BOLD%^%^BLACK%^ growls "+
                "loudly and sinks "+ETO->QP+" axe deep into you!"+
                "%^RESET%^");
               
                return roll_dice(2,3) + random(6);
                break;
        }
    }
    return 0;
}
