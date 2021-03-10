#include <std.h>
#include "../undead.h"

inherit CWEAP"halberd";

void create() 
{
    ::create();
    set_wield((: TO,"extra_wield" :));
    set_unwield((: TO,"extra_unwield" :));
}

int extra_wield()
{
    tell_object(ETO,"%^BOLD%^%^BLUE%^The halberd shrieks.%^RESET%^");
    tell_room(EETO,"%^BOLD%^%^BLUE%^The halberd wielded by "+ETO->QCN+" shrieks wildly "
        "as "+ETO->QS+" grips it.%^RESET%^",ETO);
    if((string)ETO->query_race() == "ogre" && userp(ETO))
    {
      write("%^BOLD%^%^RED%^The bloodlust of the ancient ogre warriors flows "
          "through you!%^RESET%^");
      tell_room(EETO,"%^BOLD%^%^RED%^"+ETO->QCN+"foams in the mouth as the bloodlust "
          "of "+ETO->QP+" ancestors flows through "+ETO->QS+"!%^RESET%^",ETO);
        TO->set_wc(4,4+((int)ETO->query_stat("wisdom") + 1));
        TO->set_large_wc(5,4+((int)ETO->query_stat("wisdom") + 1));
    }
    return 1;
}

int extra_unwield() 
{
    tell_object(ETO,"%^RED%^The halberd stops its infernal shrieking.%^RESET%^");
    tell_room(EETO,"%^RED%^The halberd wielded by "+ETO->QCN+" stops shrieking "
        "as "+ETO->QS+" unwields it.%^RESET%^",ETO);
    TO->set_wc(1,10);
    TO->set_large_wc(3,6);
    return 1;
}
