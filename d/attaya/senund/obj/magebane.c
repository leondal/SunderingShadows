#include <std.h>
#include "../areadefs.h"
inherit "/d/common/obj/weapon/two_hand_sword";

void create() {
    ::create();
    set_name("magebane");
    set_id(({ "sword", "two handed sword", "two handed", "magebane",
              "Magebane","two_hand_sword"}));
    set_short("%^BOLD%^%^MAGENTA%^Mage%^RED%^bane%^RESET%^");
    set_obvious_short("a two handed sword");
    set_long(
@BRUENOR
This two handed sword is a marvel to look at. The %^BOLD%^stainless steel%^RESET%^
of the blade seems to sparkle even in complete %^BOLD%^%^BLACK%^dark%^RESET%^. %^MAGENTA%^Runes%^RESET%^ line
both sides of the blade up and down. The hilt is made of shining
%^BOLD%^%^CYAN%^platinum%^RESET%^ with a rather large %^BOLD%^%^GREEN%^gemstone%^RESET%^ as the pommel.
BRUENOR
    );
    set_lore(
@BRUENOR
When Elseroad first joined up with Gambrill many years ago they traded 
weapons as a sign of trust. Elseroad enchanted a sword to combat mages 
which he gave to Gambrill who being sure of his skills already decided
to hang this sword in his halls as a sign of his power and confidence. 
The assassins in the guild knew better then to even touch the sword. 
You, apparently did not.
BRUENOR
    );
    set("value",250);
    set_property("enchantment",4);
    set_item_bonus("magic resistance",1);
    set_item_bonus("spell damage resistance",25);
    set_wield((:TO, "extra_wield":));
    set_unwield((:TO, "extra_unwield":));
    set_hit((:TO, "extra_hit":));
}

int extra_unwield()
{
    return 1;
}
int extra_wield() 
{
    if((int)ETO->query_highest_level() < 25) 
    {    
        tell_object(ETO,"%^BLUE%^The sword %^RED%^burns%^BLUE%^ as "+
        "you try to wield its power.");
        return 0;
    }
    tell_object(ETO,
        "%^BOLD%^%^RED%^You take grasp of the sword and feel a surge "+
        "of power!%^RESET%^");
    tell_room(EETO,
        "%^BOLD%^%^RED%^"+ETOQCN+"'s sword %^GREEN%^flashes%^RED%^ "+
        "for an instant.%^RESET%^",ETO);       
    return 1;
}

int extra_hit(object targ)
{
    int heal;
    int dam;
    heal = random(5) + 1;
    dam = random(15) + 4;
    if(!objectp(targ)) return 1;
        if(targ->is_class("mage"))
        {
            if (!random(2))
            {
            ETO->set_property("magic",1);
            tell_object(ETO,
            "%^BOLD%^%^GREEN%^Your blade %^RED%^cleaves%^GREEN%^ into "+
            "your opponent crushing any magical "+
            "%^BOLD%^%^GREEN%^defenses they have prepared!%^RESET%^");
            tell_object(ETO,"%^CYAN%^You feel refreshed as the blade "+
            "cuts into "+targ->QCN+"%^CYAN%^!");
            ETO->do_damage("torso",-heal);
            tell_room(EETO,targ->QCN+
            " is %^RED%^struck%^GREEN%^ down by "
            +ETOQCN+"'s%^BOLD%^%^GREEN%^ "+
            "blade!",({ETO,targ}));
            tell_object(targ, "%^BOLD%^%^GREEN%^You are helpless "+
            "as %^MAGENTA%^Mage%^RED%^bane "+
            "%^BOLD%^%^GREEN%^slices into you!%^RESET%^");
            targ->do_damage("torso",dam);
            targ->set_paralyzed(random(10)+2,"%^YELLOW%^The pain "+
            "leaves you in shock.");
            ETO->set_property("magic",-1);
            return 5;
            }
        }
        else return 0;

}
