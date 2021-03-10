#include <std.h>
inherit "/d/common/obj/weapon/scimitar";

void create()
{
    ::create();
    set_name("ethereal scimitar");
    set_id(({ "scimitar", "ethereal scimitar", 
    "narameon's ethereal blade", "ethereal blade", "blade",
    "sword","ethereal sword",}));
    set_short("%^RED%^Naram%^BOLD%^%^WHITE%^eo%^RESET%^%^RED%^"+
    "n's %^CYAN%^ether%^BOLD%^%^WHITE%^ea%^RESET%^%^CYAN%^l "+
    "blade%^RESET%^");

    set_obvious_short("An ethereal scimitar");

    set_long("%^CYAN%^This weapon is made entirely from what "+
    "appears to be an almost %^BOLD%^%^WHITE%^ghostly%^RESET%^%^CYAN%^ "+
    "substance. It borders on the edge of transparency, "+
    "yet succeeds only in becoming translucent, reflecting in "+
    "a strange design any light that manages to come into "+
    "contact with the blade. The strange substance that "+
    "constructs the weapon is continually giving off a "+
    "very faint glow that dims where the individual parts of "+
    "the weapon meet with one another. The handle of the "+
    "weapon is a darker hue with what appears to be a design "+
    "of the %^BOLD%^%^GREEN%^cosm%^YELLOW%^o%^BOLD%^%^GREEN%^s "+
    "%^RESET%^%^CYAN%^inlaid into the substance that forms it.  "+
    "The handle travels up to meet the lighter colored and "+
    "sharpened blade, which manages to extend approximately "+
    "three feet, all the while curving back to almost touch its "+
    "base. The handle travels down to meet a ball of "+
    "glowing %^BOLD%^%^GREEN%^green light%^RESET%^%^CYAN%^ that is "+
    "apparently serving as the pommel to this strange weapon."+
    "%^RESET%^");

    set_lore("%^BOLD%^%^CYAN%^These scimitars were created by a smith "+
    "long ago to be used by servants of a man "+
    "recalled now as '%^BOLD%^%^BLACK%^blackthorn%^BOLD%^"+
    "%^CYAN%^'. The last known location of any of them "+
    "was in the burial site of a man who died on the island "+
    "of Deku years ago. It is strange that it should "+
    "have found its way back into the hands of the living.%^RESET%^");

    set_property("lore difficulty", 20);
    set_weight(7);
    set_value(1000);
    set_property("enchantment",5);
    set_wield((:TO,"wield_func":));
    set_unwield((:TO,"unwield_func":));
    set_hit((:TO,"hit_func":));
    set_decay_rate(0);
    set_item_bonus("constitution", 2);
}

int wield_func()
{
    tell_room(EETO,"%^CYAN%^The %^YELLOW%^light%^RESET%^%^CYAN%^ "+
    "emitted by "+ETOQCN+"%^RESET%^%^CYAN%^"+
    "'s sword suddenly %^BOLD%^%^BLACK%^dims!%^RESET%^",ETO);
	
    tell_object(ETO,"%^CYAN%^The %^YELLOW%^light%^RESET%^%^CYAN%^ "+
    "emitted by your sword suddenly %^BOLD%^%^BLACK%^dims!%^RESET%^");
    return 1;
}

int unwield_func()
{
    tell_room(EETO,"%^CYAN%^The %^YELLOW%^light%^RESET%^%^CYAN%^ emitted by "+
    ETOQCN+"%^RESET%^%^CYAN%^'s sword suddenly %^BOLD%^%^WHITE%^"+
    "intensifies!%^RESET%^",ETO);
    tell_object(ETO,"%^CYAN%^The %^YELLOW%^light%^RESET%^%^CYAN%^ emitted by "+
    "your sword suddenly %^BOLD%^%^WHITE%^intensifies!%^RESET%^");
    return 1;
}
int hit_func(object targ)
{
    if(!objectp(targ)) return 1+random(6);
    if(!random(10))
    {
        switch(random(3)) 
        {
            case 0:
                tell_room(EETO,ETOQCN + "%^YELLOW%^ swings "+ETO->QP+
                " ethereal sword at "+targ->QCN+"%^YELLOW%^ and "+
                "%^RED%^sears%^YELLOW%^ "+targ->QP+" flesh with the "+
                "strange blade!%^RESET%^",({ETO,targ}));

                tell_object(targ,ETOQCN+"%^YELLOW%^ swings "+
                ETO->QP+" ethereal sword at you and its strange "+
                "blade %^RED%^sears%^YELLOW%^ your flesh!%^RESET%^");
	    
                tell_object(ETO,"%^YELLOW%^You swing your ethereal "+
                "sword at "+targ->QCN+"%^YELLOW%^ and its strange "+
                "blade %^RED%^sears%^YELLOW%^ "+targ->QP+
                " flesh!%^RESET%^");
	            
                ETO->set_property("magic",1);
                targ->cause_typed_damage(targ, targ->return_target_limb(),roll_dice(2, 4), "slashing");
                ETO->set_property("magic",-1);
                return 0;
                break;
            case 1:
                tell_room(EETO,ETOQCN +"%^RED%^ suddenly chants "+
                "a short %^BLUE%^phrase%^RED%^ before slashing into "+
                targ->QCN+"%^RED%^'s torso with unnatural force!"+
                "%^RESET%^",({ETO,targ}));

                tell_object(targ,ETOQCN+"%^RED%^ suddenly chants a "+
                "short %^BLUE%^phrase%^RED%^ before slashing into "+
                "your torso with an unnatural force!%^RESET%^");

                tell_object(ETO,"%^CYAN%^A vision of power suddenly "+
                "floods your mind:  %^RESET%^You begin chanting "+
                "a short %^BLUE%^phrase%^RESET%^.....\n"+
                "%^RED%^Your body surges with sudden strength "+
                "and you slash into "+targ->QCN+"%^RED%^'s torso "+
                "with an unnatural force!%^RESET%^");
                return roll_dice(3, 4);
                break;
            case 2:
                tell_room(EETO,ETOQCN+"%^BLUE%^ drops to one knee "+
                "and %^RED%^thrusts%^BLUE%^ "+ETO->QP+" ethereal "+
                "sword forward and into "+targ->QCN+
                "%^BLUE%^ causing "+targ->QO+" to "+
                "%^RED%^scream%^BLUE%^ in agony!%^RESET%^",
                ({ETO,targ}));

                tell_object(targ,ETOQCN+"%^BLUE%^ suddenly drops to "+
                "one knee and %^RED%^thrusts %^BLUE%^"+ETO->QP+
                " ethereal sword forward and into you, causing "+
                "you to scream out in %^RED%^agony!%^RESET%^");

                tell_object(ETO,"%^BLUE%^You suddenly drop to "+
                "one knee and %^RED%^thrust%^BLUE%^ your "+
                "ethereal sword into "+targ->QCN+"%^BLUE%^ "+
                "causing "+targ->QO+" to scream out in "+
                "%^RED%^agony!%^RESET%^");
                return roll_dice(3,3);
                break;
        }
    }
}
