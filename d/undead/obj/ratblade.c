#include <std.h>
#include "../undead.h"

inherit CWEAP"longsword";

create() 
{
   ::create();
   set_name("blade");
   set_id(({"blade","ratblade", "sword"}));
   set_obvious_short("A curved longsword");
   set_short("%^BOLD%^Ratblade%^RESET%^");
   set_long("%^BOLD%^This is a truly evil looking weapon.  It is about the size of a "
       "longsword and had a standard looking hilt, but the blade is curved and looks "
       "like it could inflict a vicious wound if it were to plunge in just right.  "
       "It seems to have seen much use.%^RESET%^");
   set_value(800);
   set_wield((: TO,"extra_wield" :));
   set_hit((: TO,"extra_hit" :));
   set_property("enchantment",3);
}

int extra_wield() 
{
    tell_object(ETO,"%^BLUE%^%^BOLD%^As you wield the sword its hilt begins "
        "to contort to fit your hand!");
    tell_room(EETO,"%^BLUE%^%^BOLD%^"+ETO->QCN+"'s sword begin to contort "
        "to fit the shape of "+ETO->QP+" hand", ETO);
    return 1;
}

int extra_hit(object targ) 
{
    if(!objectp(targ)) { return 1; }
    if(!objectp(ETO)) { return 1; }

    if(!random(3)) 
    {
        tell_object(ETO,"%^RED%^Your blade turns itself in "+targ->QCN+"'s wound!");
        tell_object(targ,"%^RED%^"+ETO->QCN+"'s blade turns in your wound!");
        tell_room(EETO,"%^RED%^"+ETO->QCN+"'s blade turns itself in "
            ""+targ->QCN+"'s wound!",({targ, ETO}));
        return roll_dice(2,6);
    }
    return 1;
}
