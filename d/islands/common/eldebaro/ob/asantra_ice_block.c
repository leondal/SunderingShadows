#include <std.h>
#include "../area_stuff.h"
inherit OBJECT;
int health;

void create() 
{
    ::create();
    set_name("block of ice");
    set_value(1);
    set_weight(1);
	
    set_id(({"block", "ice", "block of ice", "Enormous ice block"}));
    	
    set_short("%^BOLD%^%^WHITE%^Enormous bl%^BOLD%^%^CYAN%^o%^BOLD%^%^WHITE%^"+
    "ck of %^BOLD%^%^CYAN%^I%^BOLD%^%^WHITE%^c%^BOLD%^%^CYAN%^e%^RESET%^");

    set_long("%^BOLD%^%^CYAN%^This enormous block of ice is nearly thirty feet long and "+
    "fifteen feet wide. The outter most edges of it are starting to melt "+
    "slowly. Most of it is an almost blinding %^BOLD%^%^WHITE%^white crystalline%^BOLD%^%^CYAN%^ "+
    "hue. Except for the center of it which appears much darker. In fact it looks like something that is "+
    "%^RESET%^%^MAGENTA%^violet colored%^BOLD%^%^CYAN%^ is encased in the ice. It looks fairly large but "+
    "you are unsure of what it might be. You believe that you could <%^BOLD%^%^WHITE%^break%^BOLD%^"+
    "%^CYAN%^> the ice if you were determined to find out though.%^RESET%^");

    health = 800 + random(600);
    call_out("check_room", 12);
}

void init()
{
    ::init();   
    add_action("break_function", "break");
}

void melt_away()
{
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    tell_room(ETO, TO->query_short()+"%^BOLD%^%^WHITE%^ finally melts away entirely and the water "+
    "is absorbed and added to the %^BOLD%^%^BLACK%^ebon stones%^BOLD%^%^WHITE%^!%^RESET%^");
    if(objectp(TO)) TO->remove();
    return;
}

void wakey_wakey(int stage)
{
    object mon, *targets;
    int x;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    switch(stage)
    {
        case 1:
            tell_room(ETO, "%^BOLD%^%^WHITE%^The %^RESET%^%^MAGENTA%^violet skinned"+
            "%^BOLD%^%^WHITE%^ giant begins stirring..... and her %^BOLD%^%^MAGENTA%^"+
            "deep purple%^BOLD%^%^WHITE%^ eyes %^BOLD%^%^RED%^FLARE%^BOLD%^%^WHITE%^ open!!!");
            call_out("wakey_wakey", 10, 2);
            break;
        case 2:
            tell_room(ETO, "%^BOLD%^%^BLACK%^The %^RESET%^%^MAGENTA%^violet skinned"+
            "%^BOLD%^%^BLACK%^ giant %^BOLD%^%^GREEN%^ROARS%^BOLD%^%^BLACK%^ as she jumps to her feet, her hair flashing wildly "+
            "with %^BOLD%^%^BLUE%^e%^BOLD%^%^CYAN%^l%^BOLD%^%^BLUE%^e%^BOLD%^%^CYAN%^c%^BOLD%^%^BLUE%^"+
            "t%^BOLD%^%^CYAN%^r%^BOLD%^%^BLUE%^i%^BOLD%^%^CYAN%^c%^BOLD%^%^BLUE%^i%^BOLD%^%^CYAN%^t"+
            "%^BOLD%^%^BLUE%^y%^BOLD%^%^BLACK%^.%^RESET%^");
            set_short("%^BOLD%^%^WHITE%^Enormous giant bl%^BOLD%^%^CYAN%^o%^BOLD%^%^WHITE%^"+
            "ck of %^BOLD%^%^CYAN%^I%^BOLD%^%^WHITE%^c%^BOLD%^%^CYAN%^e%^RESET%^");

            set_long("%^BOLD%^%^CYAN%^This enormous block of ice is nearly thirty feet long and "+
            "fifteen feet wide. The upper portion of it has been completely chipped away. Most of the "+
            "remainder of it is an almost blinding %^BOLD%^%^WHITE%^white crystalline%^BOLD%^%^CYAN%^ "+
            "hue. An indention where it looks like something large might have once been is visible in the bottom portion "+
            "of the ice. It looks to be melting away slowly....%^RESET%^");
            call_out("melt_away", 240);
            call_out("wakey_wakey", 10, 3);
            break;
        case 3:
            tell_room(ETO, "%^BOLD%^%^BLACK%^The %^RESET%^%^MAGENTA%^violet skinned"+
            "%^BOLD%^%^BLACK%^ giant raises both hands, screaming %^BOLD%^%^RED%^LOUDLY"+
            "%^BOLD%^%^BLACK%^ 'Kayan, I SHALL Avenge you!'%^RESET%^");
            
            tell_room(ETO, "%^BOLD%^%^CYAN%^You watch as an %^BOLD%^%^BLUE%^e%^BOLD%^"+
            "%^CYAN%^l%^BOLD%^%^BLUE%^e%^BOLD%^%^CYAN%^c%^BOLD%^%^BLUE%^"+
            "t%^BOLD%^%^CYAN%^r%^BOLD%^%^BLUE%^i%^BOLD%^%^CYAN%^f%^BOLD%^%^BLUE%^i%^BOLD%^%^CYAN%^e"+
            "%^BOLD%^%^BLUE%^d%^BOLD%^%^CYAN%^ spear appears in "+
            "one of her outstretched hands and an %^BOLD%^%^BLACK%^ebon shield%^BOLD%^%^CYAN%^"+
            " in the other!%^RESET%^");
            
            mon = new(ELMON+"asantra");
            mon->move(ETO);
            targets = all_living(ETO);
            if(!pointerp(targets));
            targets -= ({mon});
            for(x = 0;x < sizeof(targets);x++)
            {
                if(!objectp(targets[x])) continue;
                if(targets[x]->query_true_invis()) continue;
                if(targets[x]->id("eldebaro_ice_breaker")) 
                {
                    targets[x]->sacrifice(mon);
                    continue;
                }
                mon->force_me("kill "+targets[x]->query_name());
                continue;
            }
            break;            
    }
    return;
}

int break_function(string what) 
{
    if(!objectp(TO)) return 0;
    if(!objectp(ETO)) return 0;
    if(!objectp(TP)) return 0;
    if(!stringp(what)) return 0;
    if(TO != present(what, ETO)) return 0;
    if(health <= 0) return 0;    
    if(TP->id("eldebaro_ice_breaker")) 
    {
        TP->set_moving(0);
        TP->set_speed(0);
    }
    tell_object(TP, "%^BOLD%^%^WHITE%^You chip away at the block of "+
    "ice, attempting to reveal whatever is hidden within it!%^RESET%^");    
   
    tell_room(ETO, TPQCN+"%^BOLD%^%^WHITE%^ chips away at the block of "+
    "ice, attempting to reveal whatever is hidden within it!%^RESET%^", TP);
    TP->set_paralyzed(10, "%^BOLD%^%^WHITE%^You are busy chipping away at the block of ice!%^RESET%^");
    health -= (75 + random(76));
    if(health <= 0) 
    {
        health = 0;
        tell_object(TP, "%^BOLD%^%^WHITE%^You gasp in %^BOLD%^%^CYAN%^"+
        "AWE%^BOLD%^%^WHITE%^ as you realize that the violet object contained within the "+
        "ice is actually a %^RESET%^%^MAGENTA%^violet skinned%^BOLD%^%^WHITE%^ giant!%^RESET%^");
        
        tell_room(ETO, TPQCN+"%^BOLD%^%^WHITE%^ gasps in %^BOLD%^%^CYAN%^AWE"+
        "%^BOLD%^%^WHITE%^ as "+TP->QP+" chipping away has revealed the %^RESET%^%^MAGENTA%^violet"+
        "%^BOLD%^%^WHITE%^ object contained within the ice to be a %^RESET%^%^MAGENTA%^"+
        "violet skinned%^BOLD%^%^WHITE%^ giant!%^RESET%^", TP);
        
        set_short("%^BOLD%^%^WHITE%^Chipped enormous bl%^BOLD%^%^CYAN%^o%^BOLD%^%^WHITE%^"+
        "ck of %^BOLD%^%^CYAN%^I%^BOLD%^%^WHITE%^c%^BOLD%^%^CYAN%^e %^BOLD%^%^WHITE%^(containing "+
        "a %^RESET%^%^MAGENTA%^violet skinned%^BOLD%^%^WHITE%^ giant)%^RESET%^");

        set_long("%^BOLD%^%^CYAN%^This giant block of ice is nearly thirty feet long and "+
        "fifteen feet wide. The upper portion of it has been completely chipped away. Most of the "+
        "remainder of it is an almost blinding %^BOLD%^%^WHITE%^white crystalline%^BOLD%^%^CYAN%^ "+
        "hue. Laying on the top of it, where it was recently chipped away, and still partly contained within "+
        "the bottom portion of the ice is a %^RESET%^%^MAGENTA%^violet skinned%^BOLD%^%^CYAN%^ giant with "+
        "bluish hair which crackles with static electricity.%^RESET%^");
        call_out("wakey_wakey", 10, 1);
    }
    
    return 1;
}		

void check_room()
{
    object *vics;
    int x;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(health <= 0) return;
    vics = all_living(ETO);
    if(!sizeof(vics)) 
    {
        call_out("check_room", 12);
        return;
    }
    for(x = 0;x < sizeof(vics);x++)
    {
        if(!objectp(vics[x])) continue;
        if(vics[x]->query_true_invis()) continue;
        if(!vics[x]->id("eldebaro_ice_breaker")) continue;
        vics[x]->force_me("break ice");
        continue;
    }
    call_out("check_room", 12);
    return;
}

int get() { return 0; }