#include <std.h>
inherit "/d/common/obj/armour/coif_leather";

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
    set_name("leather coif");
    if(x < 0)
    {        
        set_id(({ "coif", "leather coif", "deep purple coif", "purple coif",
        "purple leather coif", "deep purple leather coif", "malevolent purple "+
        "coif", "malevolent coif", "newbiespecialhat"}));
        set_short("%^BOLD%^%^BLACK%^M%^RESET%^%^MAGENTA%^a%^BOLD%^%^BLACK%^l%^RESET%^"+
        "%^MAGENTA%^e%^BOLD%^%^BLACK%^v%^RESET%^%^MAGENTA%^o%^BOLD%^%^BLACK%^l"+
        "%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^nt l%^BOLD%^%^WHITE%^ea%^BOLD%^%^BLACK%^"+
        "ther coif%^RESET%^");
        set_obvious_short("%^BOLD%^%^BLACK%^A deep purple leather coif%^RESET%^");
        set_property("lore difficulty", 10);
        
        set_lore("%^BOLD%^%^BLACK%^The exact creator of this leather coif is unknown, either lost to "+
        "time or perhaps having been a mystery from the very beginning. The few rumors that exist "+
        "about it suggest that it contains a faint magic which is uniquely connected to "+
        "the one who wears it.%^RESET%^");        
        
        set_long("%^BOLD%^%^BLACK%^This strange leather coif is a deep purple hue. It is "+
        "impossible to tell if the creature from which the leather was taken was purple to "+
        "begin with or if has undergone some type of dying process. There are slight bumps "+
        "littering the entire outter surface of it, giving it a slightly %^BOLD%^%^GREEN%^"+
        "grotesque %^BOLD%^%^BLACK%^appearance. It is stitched together almost "+
        "haphazardly with several unsightly seams visible all over it, which give it "+
        "a strange patchwork appearance. Thankfully there has been a soft padding "+
        "sewn into the underside of it to make it more comfortable to wear.%^RESET%^");
    }
    //good version
    else if(x > 0)
    {
        set_id(({ "coif", "leather coif", "benevolent leather coif", "white leather coif", 
        "bright coif", "white coif", "bright white leather coif", "bright white coif", 
        "benevolent coif", "newbiespecialhat"}));
        set_short("%^BOLD%^%^WHITE%^B%^RESET%^%^GREEN%^e%^BOLD%^%^WHITE%^n%^RESET%^"+
        "%^GREEN%^e%^BOLD%^%^WHITE%^v%^RESET%^%^GREEN%^o%^BOLD%^%^WHITE%^l"+
        "%^RESET%^%^GREEN%^e%^BOLD%^%^WHITE%^nt l%^BOLD%^%^BLACK%^ea%^BOLD%^%^WHITE%^"+
        "ther coif%^RESET%^");
        set_obvious_short("%^BOLD%^%^WHITE%^A bright white leather coif%^RESET%^");
        set_property("lore difficulty", 10);
        
        set_lore("%^BOLD%^%^WHITE%^The exact creator of this leather coif is unknown, either lost to "+
        "time or perhaps having been a mystery from the very beginning. The few rumors that exist "+
        "about it suggest that it contains a faint magic which is uniquely connected to "+
        "the one who wears it.%^RESET%^");        
        
        set_long("%^BOLD%^%^WHITE%^This strange leather coif is a bright white "+
        "color. You believe that the coif has undergone some type of strange "+
        "dying process that has resulted in the unique coloration and has "+
        "rendered it impossible to discern the original creature who attributed the "+
        "leather. There are "+
        "%^BOLD%^%^CYAN%^star%^BOLD%^%^WHITE%^ patterns stitched throughout it. "+
        "Each of the patterns blink randomly out of existence before "+
        "quickly reappearing. You can find no visible stitches aside from the "+
        "patterns and there are no apparent seams. There has been a "+
        "thick pale padding sewn into the underside of it to make it more "+
        "comfortable to wear.%^RESET%^");
    }
    //neutral version
    else
    {
        set_id(({ "coif", "leather coif", "impartial leather coif", "dull green coif", 
        "green coif", "dull green leather coif", "green leather coif", "newbiespecialhat"}));
        set_short("%^BOLD%^%^WHITE%^I%^RESET%^%^MAGENTA%^m%^BOLD%^%^BLACK%^p%^RESET%^"+
        "%^GREEN%^a%^BOLD%^%^WHITE%^r%^RESET%^%^MAGENTA%^t%^BOLD%^%^WHITE%^i"+
        "%^RESET%^%^GREEN%^a%^BOLD%^%^BLACK%^l l%^BOLD%^%^WHITE%^ea%^BOLD%^%^BLACK%^"+
        "ther coif%^RESET%^");
        set_obvious_short("%^RESET%^%^GREEN%^A dull green leather coif%^RESET%^");
        set_property("lore difficulty", 10);
        
        set_lore("%^RESET%^%^GREEN%^The exact creator of this leather coif is unknown, either lost to "+
        "time or perhaps having been a mystery from the very beginning. The few rumors that exist "+
        "about it suggest that it contains a faint magic which is uniquely connected to "+
        "the one who wears it.%^RESET%^");        
        
        set_long("%^RESET%^%^GREEN%^This strange leather coif has been sewn from a "+
        "thick green hide. There are reptillian scales sewn into the surface of it. Each "+
        "is held in place by very thick and contrasting bright stitches. "+
        "There are no visible stitches apart from those holding the scales in place and "+
        "there are no apparent seams at all, as if the entire coif was created "+
        "from a single piece of hide. There has been a dingy and thick material "+
        "sewn into the underside of it to make it more comfortable to wear.%^RESET%^");  
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
