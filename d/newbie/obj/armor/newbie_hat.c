#include <std.h>
inherit "/d/common/obj/clothing/hat";

int setForLev;

void create() 
{
    ::create();
    set_weight(4);
    set_value(1000);
    set_property("no curse", 1);
    set("no curse", 1);
}

void set_myAlign(int x)
{
    if(!objectp(TO)) return;
    if(!intp(x)) return;
    //evil version
    set_name("wizard hat");
    if(x < 0)
    {        
        set_id(({ "hat", "wizard hat", "malevolent wizardly hat", "wizardly hat", "newbiespecialhat"}));
        set_short("%^BOLD%^%^BLACK%^M%^RESET%^%^MAGENTA%^a%^BOLD%^%^BLACK%^l%^RESET%^"+
        "%^MAGENTA%^e%^BOLD%^%^BLACK%^v%^RESET%^%^MAGENTA%^o%^BOLD%^%^BLACK%^l"+
        "%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^nt w%^BOLD%^%^WHITE%^i%^BOLD%^%^BLACK%^"+
        "zards hat%^RESET%^");
        set_obvious_short("%^BOLD%^%^BLACK%^A deep purple wizard's hat%^RESET%^");
        set_property("lore difficulty", 10);
        
        set_lore("%^BOLD%^%^BLACK%^The exact creator of this hat is unknown, either lost to "+
        "time or perhaps having been a mystery from the very beginning. The few rumors that exist "+
        "about it suggest that it contains a faint magic which is uniquely connected to "+
        "the one who wears it.%^RESET%^");        
        
        set_long("%^BOLD%^%^BLACK%^This strange looking hat is approximately two "+
        "feet high. Near the base is is round and large enough to fit on almost anyone "+
        "comfortably, with a roundish brim that extends out several inches in every direction. "+
        "At the top of it is much narrower and tends to flop over to one "+
        "side or another when worn. It is sewn from a very deep purple material that "+
        "almost seems to absorb light. There are strange %^BOLD%^%^CYAN%^symbols%^BOLD%^"+
        "%^BLACK%^ stitched over the entire thing which appear to shift randomly "+
        "into different forms, all of which appear to be demonic.%^RESET%^");
    }
    //good version
    else if(x > 0)
    {
        set_id(({ "hat", "wizard hat", "benevolent wizardly hat", "wizardly hat", "newbiespecialhat"}));
        set_short("%^BOLD%^%^WHITE%^B%^RESET%^%^GREEN%^e%^BOLD%^%^WHITE%^n%^RESET%^"+
        "%^GREEN%^e%^BOLD%^%^WHITE%^v%^RESET%^%^GREEN%^o%^BOLD%^%^WHITE%^l"+
        "%^RESET%^%^GREEN%^e%^BOLD%^%^WHITE%^nt w%^BOLD%^%^BLACK%^i%^BOLD%^%^WHITE%^"+
        "zards hat%^RESET%^");
        set_obvious_short("%^BOLD%^%^WHITE%^A bright white wizard's hat%^RESET%^");
        set_property("lore difficulty", 10);
        
        set_lore("%^BOLD%^%^WHITE%^The exact creator of this hat is unknown, either lost to "+
        "time or perhaps having been a mystery from the very beginning. The few rumors that exist "+
        "about it suggest that it contains a faint magic which is uniquely connected to "+
        "the one who wears it.%^RESET%^");        
        
        set_long("%^BOLD%^%^WHITE%^This strange looking hat is approximately two "+
        "feet high. Near the base is is round and large enough to fit on almost anyone "+
        "comfortably, with a roundish brim that extends out several inches in every direction. "+
        "At the top of it is much narrower and tends to flop over to one "+
        "side or another when worn. It is sewn from a very bright white material that "+
        "almost seems to reflect all light. There are strange %^BOLD%^%^CYAN%^symbols%^BOLD%^"+
        "%^WHITE%^ stitched over the entire thing which appear to shift randomly "+
        "into different forms, all of which seems almost celestial.%^RESET%^");        
    }
    //neutral version
    else
    {
        set_id(({ "hat", "wizard hat", "impartial wizardly hat", "wizardly hat", "newbiespecialhat"}));
        set_short("%^BOLD%^%^WHITE%^I%^RESET%^%^MAGENTA%^m%^BOLD%^%^BLACK%^p%^RESET%^"+
        "%^GREEN%^a%^BOLD%^%^WHITE%^r%^RESET%^%^MAGENTA%^t%^BOLD%^%^WHITE%^i"+
        "%^RESET%^%^GREEN%^a%^BOLD%^%^BLACK%^l w%^BOLD%^%^WHITE%^i%^BOLD%^%^BLACK%^"+
        "zards hat%^RESET%^");
        set_obvious_short("%^RESET%^%^GREEN%^A dull green wizard's hat%^RESET%^");
        set_property("lore difficulty", 10);
        
        set_lore("%^RESET%^%^GREEN%^The exact creator of this hat is unknown, either lost to "+
        "time or perhaps having been a mystery from the very beginning. The few rumors that exist "+
        "about it suggest that it contains a faint magic which is uniquely connected to "+
        "the one who wears it.%^RESET%^");        
        
        set_long("%^RESET%^%^GREEN%^This strange looking hat is approximately two "+
        "feet high. Near the base is is round and large enough to fit on almost anyone "+
        "comfortably, with a roundish brim that extends out several inches in every direction. "+
        "At the top of it is much narrower and tends to flop over to one "+
        "side or another when worn. It is sewn from a dull green material that "+
        "almost seems to shimmer sometimes and waver others. There are strange %^BOLD%^%^CYAN%^symbols%^RESET%^"+
        "%^GREEN%^ stitched over the entire thing which appear to shift randomly "+
        "into different forms, some of which appear almost demonic and others "+
        "which seems celestial.%^RESET%^");        
    }
}

void init()
{
    string WE = "%^RESET%^%^CYAN%^An excited whispering fills your mind:%^RESET%^";
    int lev, enchVal;
    ::init();
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!userp(ETO)) return;
    lev = (int)ETO->query_lowest_level();
    if(setForLev == lev) return;
    enchVal = (int)TO->query_property("enchantment");
    if(lev >= 5 && lev < 12)
    {
        if(enchVal == 1) return;
        else
        {
            if(enchVal < 1) 
            {
                tell_object(ETO,"\n\n"+ WE+" Your "+TO->query_short()+" is becoming more powerful!%^RESET%^");
            }
            else tell_object(ETO, "\n\n"+WE+" Your "+TO->query_short()+" seems to have lost some power!%^RESET%^");
            if(query_worn())
            {
                ETO->force_me("remove newbiespecialhat");
            }
            TO->remove_property("enchantment");
            TO->set_property("enchantment", 1);
        }
    }
    else if(lev >= 12 && lev <= 17)
    {
        if(enchVal == 2) return;
        else
        {
            if(enchVal < 2) tell_object(ETO,"\n\n"+ WE+" Your "+TO->query_short()+" is becoming more powerful!%^RESET%^");
            else tell_object(ETO, "\n\n"+WE+" Your "+TO->query_short()+" seems to have lost some power!%^RESET%^");
            if(query_worn())
            {
                ETO->force_me("remove newbiespecialhat");
            }
            TO->remove_property("enchantment");
            TO->set_property("enchantment", 2);
        }
    }
    else if(lev > 17)
    {
        if(enchVal == 3) return;
        else
        {
            if(enchVal < 3) tell_object(ETO,"\n\n"+ WE+" Your "+TO->query_short()+" is becoming more powerful!%^RESET%^");
            else tell_object(ETO, "\n\n"+WE+" Your "+TO->query_short()+" seems to have lost some power!%^RESET%^");
            if(query_worn())
            {
                ETO->force_me("remove newbiespecialhat");
            }
            TO->remove_property("enchantment");
            TO->set_property("enchantment", 3);
        }
    }
    return;    
}
