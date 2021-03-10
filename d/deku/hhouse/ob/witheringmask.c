#include <std.h>
#include "../inherits/area_stuff.h"
inherit ARMOUR;

string OWNER;
int eyes, max_eyes;
object *MYEYES;
void init() 
{
    ::init();
    if(interactive(ETO) && !stringp(OWNER) && ETO->is_player()) 
    {
        OWNER = ETO->query_name();	
        set_size(ETO->query_size());
    }
    add_action("demand_stalk", "stalk");
    add_action("look_func", "look");
}


void adjust_max_eyes(int x) 
{
    max_eyes += x;
}

void create()
{
    ::create();
    set_name("tentacled mask");
    set_id(({"mask", "tentacled mask", "withering mask", "mask of withering"}));
    
    set_obvious_short("%^RESET%^%^ORANGE%^tentacled mask%^RESET%^");

    set_short("%^RESET%^%^ORANGE%^W%^BOLD%^i%^RESET%^%^ORANGE%^t%^BOLD%^h%^RESET%^%^ORANGE%^"+
    "e%^BOLD%^r%^RESET%^%^ORANGE%^i%^BOLD%^n%^RESET%^%^ORANGE%^g %^BOLD%^M%^RESET%^%^ORANGE%^"+
    "a%^BOLD%^s%^RESET%^%^ORANGE%^k%^RESET%^");

    set_long("%^RESET%^%^ORANGE%^This mask is quite gruesome to behold. There are "+
    "numerous living, withering t%^BOLD%^%^YELLOW%^e%^RESET%^%^ORANGE%^nt%^BOLD%^%^YELLOW%^"+
    "a%^RESET%^%^ORANGE%^cl%^BOLD%^%^YELLOW%^e%^RESET%^%^ORANGE%^s that extend from it "+
    "in all directions and small, slightly %^BOLD%^%^RED%^bloated%^RESET%^%^ORANGE%^ eyes "+
    "connected to the ends of each tentacle. Each %^BOLD%^%^GREEN%^e%^YELLOW%^y%^BOLD%^%^GREEN%^e "+
    "%^RESET%^%^ORANGE%^moves about on its own and frequently looks back at the mask, as if "+
    "awaiting instructions. The mask itself is made from a thick "+
    "leathery substance and has been contoured in such a way that it fits snugly "+
    "against the face of whoever might wear it.%^RESET%^");

    set_lore("%^RESET%^%^ORANGE%^This mask was once worn and beloved by a general "+
    "in service to Ao'rus Devar but has been lost for ages. Legends suggest that "+
    "it was a powerful spying tool used by the general to keep tabs on those "+
    "that were closest to him. Some stories suggest that the eyes on the mask "+
    "are able to be controlled and will telepathically report back all that they "+
    "hear simply by %^BOLD%^%^WHITE%^%^'%^BOLD%^%^RED%^"+
    "demanding that they %^BOLD%^%^CYAN%^stalk%^BOLD%^%^WHITE%^' %^RESET%^%^ORANGE%^"+
    " whomever the wearer wishes to spy upon.%^RESET%^");

    set_property("lore difficulty", 24);
    set_item_bonus("sight bonus", 2);
    set_item_bonus("caster level", 2);
    set_type("clothing");
    set_limbs(({"head"}));
    set_property("no curse", 1);
    set_property("enchantment",5);
    set_heart_beat(1);
    set_value(7500);
    set_wear((:TO,"wear_me":));
    set_remove((:TO,"remove_me":));
    eyes = 2 + random(3);
    max_eyes = eyes;
    set_heart_beat(1);
}


void heart_beat()
{
    int x;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(eyes == max_eyes) return;
    if(!pointerp(MYEYES)) MYEYES = ({});
    if(sizeof(MYEYES)) 
    {
        for(x = 0;x < sizeof(MYEYES);x++)
        {
            if(objectp(MYEYES[x])) return;
        }
    }
    if(!random(20)) 
    {
        if(eyes < max_eyes) eyes++;
    }
}

void eye_failure(mixed type)
{
    int x;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!pointerp(MYEYES)) MYEYES = ({});
    if(!type) 
    {
        if(eyes >= max_eyes) return;
        if(living(ETO)) 
        {
            tell_object(ETO, "%^BOLD%^%^RED%^An %^BOLD%^%^GREEN%^e%^YELLOW%^y%^BOLD%^%^GREEN%^e%^YELLOW%^ "+
            "%^BOLD%^%^RED%^reappears back on the end of one of the tentacles on your mask!%^RESET%^");      
            if(!ETO->query_invis()) 
            {
                tell_room(EETO, "%^BOLD%^%^RED%^An %^BOLD%^%^GREEN%^e%^YELLOW%^y%^BOLD%^%^GREEN%^e%^YELLOW%^ "+
                "%^BOLD%^%^RED%^reappears back on the end of one of the tentacles on "+ETOQCN+"%^BOLD%^%^RED%^'s mask!%^RESET%^", ETO);
            }
        }
        if(ETO->is_room()) 
        {
            tell_room(ETO, "%^BOLD%^%^RED%^An %^BOLD%^%^GREEN%^e%^YELLOW%^y%^BOLD%^%^GREEN%^e%^YELLOW%^ "+
            "%^BOLD%^%^RED%^reappears back on the end of one of the tentacles on "+TO->query_short()+"%^BOLD%^%^RED%^!%^RESET%^");
        }
        if(eyes < max_eyes) eyes++;
        return 1;
    }

    if(objectp(type)) 
    {
        eye_failure(0);
        if(member_array(type, MYEYES) != -1) 
        {
            MYEYES -= ({type});
        }
        return 1;
    }

    if(type == "all")
    {
        for(x = 0;x < sizeof(MYEYES);x++)
        {
            if(objectp(MYEYES[x]))
            { 
                MYEYES[x]->remove();
            }
            eye_failure(0);
            continue;
        }
        MYEYES = ({});
        return 1;
    }
}     

void remove()
{
    if(sizeof(MYEYES)) eye_failure("all");
    return ::remove();
}
 
int demand_stalk(string str)
{
    object victim, eye_stalker;

    if(!objectp(TO)) return 0;
    if(!objectp(ETO)) return 0;
    if(!stringp(str)) return 0;

    if(!TO->query_worn()) 
    {
        tell_object(ETO, "%^BOLD%^%^RED%^You must wear the mask first!%^RESET%^");
        return 1;
    }

    if(!eyes) 
    {
        tell_object(ETO, "%^BOLD%^%^BLACK%^None of the remaining eyes are willing to do "+
        "your bidding!%^RESET%^");
        return 1;
    }

    tell_object(ETO,"%^BOLD%^%^BLACK%^One of the %^BOLD%^%^GREEN%^e%^YELLOW%^y%^BOLD%^%^GREEN%^e%^YELLOW%^s"+
    "%^BOLD%^%^BLACK%^ pulls itself away from a tentacle and listens to your mind, before vanishing in "+
    "search of "+str+"!%^RESET%^");

    if(!ETO->query_invis()) 
    {
        tell_room(EETO, "%^BOLD%^%^BLACK%^One of the %^BOLD%^%^GREEN%^e%^YELLOW%^y%^BOLD%^%^GREEN%^e%^YELLOW%^s"+
        "%^BOLD%^%^BLACK%^ on "+ETOQCN+"%^BOLD%^%^BLACK%^'s mask pulls itself away from a tentacle and "+
        "seems to focus on "+ETO->QO+" before vanishing!%^RESET%^", ETO);   
    }
    eyes--;

    victim = find_player(ETO->realName(str)); 
    if(!objectp(victim) || wizardp(victim)) 
    {
        call_out("eye_failure", 15, 0);
        return 1;
    }
    if(!environment(victim)) 
    { 
        call_out("eye_failure", 15, 0);
        return 1;
    }
    if(environment(victim)->query_property("no scry") || present("blockerx111", victim)) 
    {
        call_out("eye_failure", 15, 0);
        return 1;
    }
    eye_stalker = new(HHOB+"listening_eye");
    eye_stalker->set_owner(ETO);
    eye_stalker->set_eye_owner(TO);
    eye_stalker->set_victim(victim);
    eye_stalker->set_scry_power(25);
    eye_stalker->move(environment(victim));
    eye_stalker->set_duration(25 + random(100));
    if(!pointerp(MYEYES)) MYEYES = ({eye_stalker});
    else MYEYES += ({eye_stalker});
    return 1;    
}

int look_func(string str) 
{
    if(ETO->query_paralyzed()) return 0;
    if(!query_worn()) return 0;
    if(!str) return 0;
    if(random(15)) return 0;
    if(str) 
    {
        tell_object(ETO,"%^RESET%^%^ORANGE%^The tenacles wither about wildly and the "+
        "%^BOLD%^%^GREEN%^e%^YELLOW%^y%^BOLD%^%^GREEN%^e%^YELLOW%^s%^RESET%^%^ORANGE%^ "+
        "attached to them follow your gaze!%^RESET%^");
     
        if(!ETO->query_invis()) 
        {
            tell_room(EETO, "%^RESET%^%^ORANGE%^The tenacles attached to "+ETOQCN+
            "%^RESET%^%^ORANGE%^'s mask wither about wildly and the %^BOLD%^"+
            "%^GREEN%^e%^YELLOW%^y%^BOLD%^%^GREEN%^e%^YELLOW%^s%^RESET%^%^ORANGE%^ "+
            "attached to them follow "+ETO->QP+" gaze!%^RESET%^", ETO);
        }
        return 0;
    }
    return 0;
}

void wear_me()
{
    if((int)ETO->query_level() < 25)
    {
        tell_object(ETO, "%^BOLD%^%^BLACK%^The mask refuses to fit you!!%^RESET%^");
        return 0;
    }

    if(interactive(ETO) && (string)ETO->query_name() != OWNER)
    {
        tell_object(ETO, "%^BOLD%^%^BLACK%^The mask will not fit you!.%^RESET%^");
        return 0;
    }
    tell_object(ETO, "%^RESET%^%^ORANGE%^You slip the mask onto your face and many of the "+
    "%^BOLD%^%^GREEN%^e%^YELLOW%^y%^BOLD%^%^GREEN%^e%^YELLOW%^s%^RESET%^%^ORANGE%^ "+
    "attached to the tentacles turn toward you, gleaming in approval as the "+
    "tentacles begin withering wildly!%^RESET%^");

    if(!ETO->query_invis()) 
    {
        tell_room(EETO, ETOQCN+"%^RESET%^%^ORANGE%^ slips on "+ETO->QP+" "+TO->query_short()+ 
        "%^RESET%^%^ORANGE%^ and many of the %^BOLD%^%^GREEN%^e%^YELLOW%^y%^BOLD%^%^GREEN%^e"+
        "%^YELLOW%^s%^RESET%^%^ORANGE%^ attached to the tentacles turn toward "+
        ETO->QO+", gleaming "+
        "in approval as the tentacles begin withering wildly!%^RESET%^", ETO);
    }
    return 1;

}

void remove_me()
{
    tell_object(ETO, "%^RESET%^%^ORANGE%^You slip the mask off of your face and many of the "+
    "%^BOLD%^%^GREEN%^e%^YELLOW%^y%^BOLD%^%^GREEN%^e%^YELLOW%^s%^RESET%^%^ORANGE%^ attached "+
    "to the tentacles stare at you in obvious disapproval!%^RESET%^");
    
    if(sizeof(MYEYES)) eye_failure("all");

    if(!ETO->query_invis())
    {
        tell_room(EETO, ETOQCN+"%^RESET%^%^ORANGE%^ slips "+ETO->QP+" "+TO->query_short()+
        " off of "+ETO->QP+" face and many of the "+
        "%^BOLD%^%^GREEN%^e%^YELLOW%^y%^BOLD%^%^GREEN%^e%^YELLOW%^s%^RESET%^%^ORANGE%^ attached "+
        "to the tentacles stare at "+ETO->QO+" in obvious disapproval!%^RESET%^", ETO);
    }
    return 1;
}