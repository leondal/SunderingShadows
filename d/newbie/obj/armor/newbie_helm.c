#include <std.h>
inherit "/d/common/obj/armour/helm";

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
    set_name("helmet");
    if(x < 0)
    {        
        set_id(({ "helm", "helmet", "deep purple helm", "purple helm",
        "purple leather helm", "deep purple leather helm", "malevolent purple "+
        "helm", "malevolent helm", "newbiespecialhat"}));
        set_short("%^BOLD%^%^BLACK%^M%^RESET%^%^MAGENTA%^a%^BOLD%^%^BLACK%^l%^RESET%^"+
        "%^MAGENTA%^e%^BOLD%^%^BLACK%^v%^RESET%^%^MAGENTA%^o%^BOLD%^%^BLACK%^l"+
        "%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^nt h%^BOLD%^%^WHITE%^e%^BOLD%^%^BLACK%^"+
        "lmet%^RESET%^");
        set_obvious_short("%^BOLD%^%^BLACK%^A deep purple helmet%^RESET%^");
        set_property("lore difficulty", 10);
        
        set_lore("%^BOLD%^%^BLACK%^The exact creator of this helmet is unknown, either lost to "+
        "time or perhaps having been a mystery from the very beginning. The few rumors that exist "+
        "about it suggest that it contains a faint magic which is uniquely connected to "+
        "the one who wears it.%^RESET%^");        
        
        set_long("%^BOLD%^%^BLACK%^This helmet is a strange purple hue. It has been "+
        "crafted from some unknown mineral substance. You are not sure the exact material but "+
        "it is not metallic, however, it seems quite durable. It has been made so that it "+
        "covers almost the entire head of the wearer, thankfully there is a soft padding "+
        "attached to the inside. There are %^BOLD%^%^CYAN%^strange symbols%^BOLD%^%^BLACK%^ "+
        "engraved into all sides of it. The symbols shift constantly, going from "+
        "being at peace to becoming enraged almost instantaneously and quite at random. They all "+
        "appear demonic even during the periods of peace.%^RESET%^");
    }
    //good version
    else if(x > 0)
    {
        set_id(({ "helm", "helmet", "white helmet", "white helmet", "benevolent helmet", "white leather helm", 
        "bright helm", "white helm", "bright white helmet", "bright white helm", 
        "benevolent helmet", "newbiespecialhat"}));
        set_short("%^BOLD%^%^WHITE%^B%^RESET%^%^GREEN%^e%^BOLD%^%^WHITE%^n%^RESET%^"+
        "%^GREEN%^e%^BOLD%^%^WHITE%^v%^RESET%^%^GREEN%^o%^BOLD%^%^WHITE%^l"+
        "%^RESET%^%^GREEN%^e%^BOLD%^%^WHITE%^nt h%^BOLD%^%^BLACK%^e%^BOLD%^%^WHITE%^"+
        "lmet%^RESET%^");
        set_obvious_short("%^BOLD%^%^WHITE%^A bright white helmet%^RESET%^");
        set_property("lore difficulty", 10);
        
        set_lore("%^BOLD%^%^WHITE%^The exact creator of this helmet is unknown, either lost to "+
        "time or perhaps having been a mystery from the very beginning. The few rumors that exist "+
        "about it suggest that it contains a faint magic which is uniquely connected to "+
        "the one who wears it.%^RESET%^");        
        
        set_long("%^BOLD%^%^WHITE%^This helmet is a bright white color. It has been "+
        "crafted from some unknown mineral substance. You are not sure the exact material but "+
        "it is not metallic, however, it seems quite durable. It has been made so that it "+
        "covers almost the entire head of the wearer, thankfully there is a soft padding "+
        "attached to the inside. There are %^BOLD%^%^CYAN%^mysterious symbols%^BOLD%^%^WHITE%^ "+
        "engraved into all sides of it. The symbols shift constantly, going from "+
        "being at peace to being watchful and vigilant, seemingly at random. They all "+
        "appear celestial and almost resemble living beings.%^RESET%^");
    }
    //neutral version
    else
    {
        set_id(({ "helm", "helmet", "impartial helmet", "dull green helmet", 
        "green helmet", "dull green helmet", "green helm", "green helmet", "newbiespecialhat"}));
        set_short("%^BOLD%^%^WHITE%^I%^RESET%^%^MAGENTA%^m%^BOLD%^%^BLACK%^p%^RESET%^"+
        "%^GREEN%^a%^BOLD%^%^WHITE%^r%^RESET%^%^MAGENTA%^t%^BOLD%^%^WHITE%^i"+
        "%^RESET%^%^GREEN%^a%^BOLD%^%^BLACK%^l h%^BOLD%^%^WHITE%^e%^BOLD%^%^BLACK%^"+
        "lmet%^RESET%^");
        set_obvious_short("%^RESET%^%^GREEN%^A dull green helmet%^RESET%^");
        set_property("lore difficulty", 10);
        
        set_lore("%^RESET%^%^GREEN%^The exact creator of this helmet is unknown, either lost to "+
        "time or perhaps having been a mystery from the very beginning. The few rumors that exist "+
        "about it suggest that it contains a faint magic which is uniquely connected to "+
        "the one who wears it.%^RESET%^");        
        
        set_long("%^RESET%^%^GREEN%^This helmet is a dull green hue. It has been "+
        "crafted from some unknown mineral substance. You are not sure the exact material but "+
        "it is not metallic, however, it seems quite durable. It has been made so that it "+
        "covers almost the entire head of the wearer, thankfully there is a soft padding "+
        "attached to the inside. There are %^BOLD%^%^CYAN%^mysterious symbols%^RESET%^%^GREEN%^ "+
        "engraved into all sides of it. The symbols shift constantly, going from "+
        "being at peace to becoming enraged, seemingly at random. They appear "+
        "almost celestial while calm but morph into being almost demonic when "+
        "enraged.%^RESET%^");
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

int is_metal() { return 0; }
