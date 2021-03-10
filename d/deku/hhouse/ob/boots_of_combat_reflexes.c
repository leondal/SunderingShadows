#include <std.h>
#include <daemons.h>
#include <magic.h>
inherit "/d/common/obj/clothing/shoes";

int AttackDelay;

void create(){
    ::create();
    set_name("boots");
    set_id(({ "boots", "deep green boots", "green boots",
    "combat boots", "boots of reflexes", "boots of combat reflexes"}));
    
    set_short("%^BOLD%^%^GREEN%^Bo%^RESET%^%^GREEN%^o%^BOLD%^ts of "+
    "C%^RESET%^%^BOLD%^%^BLACK%^o%^GREEN%^mb%^BOLD%^%^BLACK%^a%^GREEN%^t"+
    " refl%^BOLD%^%^BLACK%^e%^GREEN%^x%^BOLD%^%^BLACK%^e%^GREEN%^s%^RESET%^");
    
    set_obvious_short("%^BOLD%^%^GREEN%^A pair of deep green combat boots%^RESET%^");

    set_long("%^BOLD%^%^GREEN%^These deep gr%^RESET%^%^GREEN%^ee%^BOLD%^n boots are "+
    "made from a h%^BOLD%^%^BLACK%^ea%^GREEN%^vy and th%^BLACK%^i%^GREEN%^ck "+
    "leathery material. They have quite obviously been dipped in some unknown "+
    "s%^BLACK%^u%^GREEN%^bst%^BLACK%^a%^GREEN%^nce which has caused them to harden. "+
    "They look almost r%^RESET%^%^GREEN%^e%^BOLD%^pt%^RESET%^%^GREEN%^i%^BOLD%^ll%^RESET%^"+
    "%^GREEN%^ia%^BOLD%^n but it is difficult to ascertain what the original material was. "+
    "Strange p%^BLACK%^a%^GREEN%^tt%^BLACK%^e%^GREEN%^rns have been embroided all along them "+
    "with a %^RESET%^%^MAGENTA%^deep purple%^BOLD%^%^GREEN%^ thread, which almost seems "+
    "to sp%^MAGENTA%^a%^GREEN%^rkl%^MAGENTA%^e %^GREEN%^with a life of its own. The soles of "+
    "them are a dull %^BOLD%^%^BLACK%^black%^GREEN%^ material that has been added almost as an "+
    "afterthought. They are sewn on externally using a %^RESET%^%^WHITE%^plain white%^BOLD%^%^GREEN%^"+
    " string that has been woven haphazardly back and forth multiple times in an attempt "+
    "to make sure they stay attached. They stand in stark contrast to the rest of the quality "+
    "of the boots.%^RESET%^");

    set_lore("%^BOLD%^%^BLACK%^These boots are nothing more than a legend. It is not the boots "+
    "themselves that comprises the legend. It is the supposed creator of them. "+
    "Some many years ago, in a time that has almost been forgotten, a man named Aorus Devar "+
    "set out with the intention of proving that life did not need to end, that death "+
    "was a mere obstacle that could be stepped around or avoided entirely. "+
    "It is uncertain of what happened to him, but these boots were one of his "+
    "creations. He was intent on finding a way to alter the very fabric of magic in "+
    "order to avoid death, in a way much different than undeath. To begin with he "+
    "experimented on items of various qualities. These boots are one such item. The "+
    "legend around these particular boots suggest that they enable the wearer to be "+
    "better suited to maneuver in combat by granting them almost unheard of reflexes. "+
    "The fact that you are holding them raises many questions. The fact that "+
    "someone else has attempted to alter them also raises a few, but you have not heard "+
    "anything about who might have attempted to alter them in your travels.%^RESET%^");

    set_weight(6);
    set_value(3500);
    set_size(-1);
    set_wear((:TO,"wear_func":));
    set_property("no curse", 1);
    set_property("enchantment",5);
    set_item_bonus("dexterity", 4);
    set_item_bonus("athletics", 4);
    set_item_bonus("stealth", 4);
    set_item_bonus("reflex", 4);    
    set_heart_beat(1);
    set_remove((:TO, "remove_me":));
    set_heart_beat(1);
    AttackDelay = 0;
}

void heart_beat()
{
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!query_worn()) return;
    if(query_worn() != ETO) return;
    if(AttackDelay >= 0) AttackDelay--;
    if(!sizeof(ETO->query_attackers())) return;
    if(random(20)) return;
    if(AttackDelay) return;
    tell_object(ETO, "%^BOLD%^%^BLACK%^You are suddenly and without effort able to maneuver in such a way "+
    "to launch another attack!%^RESET%^");
    if(objectp(EETO))
    {
        tell_room(EETO, ETOQCN+"%^BOLD%^%^BLACK%^ maneuvers suddenly and quickly, launching another attack!%^RESET%^", ETO);
    }
    AttackDelay = ROUND_LENGTH * 5;
    ETO->execute_attack();
    
}


int wear_func(){
    
    if(ETO->query_lowest_level() < 25) 
    {
        tell_object(ETO,"%^BOLD%^%^GREEN%^No matter how hard you try you "+
        "cannot find a way to slip your feet into the boots!%^RESET%^");
        return 0;
    }

    if(!ETO->query_invis()) 
    {
        tell_room(EETO,ETOQCN+"%^BOLD%^%^GREEN%^ easily slips the deep green "+
        "boots onto "+ETO->QP+" feet!%^RESET%^",ETO);
    }
      
    tell_object(ETO,"%^BOLD%^%^GREEN%^You easily slip the deep green "+
    "boots onto your feet and feel as if your reflexes have reached "+
    "new heights!%^RESET%^");
    return 1;
}

int remove_me() 
{
    if(!ETO->query_invis()) 
    {
        tell_room(EETO,ETOQCN+"%^BOLD%^%^GREEN%^ easily slips the "+
        "deep green boots from "+ETO->QP+" feet.%^RESET%^",ETO);
    }
    tell_object(ETO,"%^BOLD%^%^GREEN%^You easily slip the deep green "+
    "boots from your feet and instantly feel your reflexes slow "+
    "down.%^RESET%^");
    return 1;
}
