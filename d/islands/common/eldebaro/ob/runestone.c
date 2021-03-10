#include <std.h>
#include <daemons.h>
#include "../area_stuff.h"
inherit OBJECT;
int health, which_rune;

void create() 
{
    ::create();
    set_name("a dark pulsating rune");
    set_value(0);
    set_weight(10000);
    
    set_id(({"rune", "dark pulsating rune", "dark rune", "eldebarodarkrune"}));
    set_property("no animate", 1);

    set_short("%^BOLD%^%^BLACK%^A d%^BOLD%^%^WHITE%^a%^BOLD%^%^BLACK%^rk "+
    "p%^BOLD%^%^WHITE%^u%^BOLD%^%^BLACK%^l%^BOLD%^%^WHITE%^s%^BOLD%^%^BLACK%^"+
    "a%^BOLD%^%^CYAN%^t%^BOLD%^%^WHITE%^i%^BOLD%^%^BLACK%^n%^BOLD%^%^WHITE%^g "+
    "%^BOLD%^%^BLACK%^r%^BOLD%^%^WHITE%^u%^BOLD%^%^BLACK%^n%^BOLD%^%^WHITE%^e%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^This strange rune is composed of a strange dark stone "+
    "which almost seems to absorb light. It is huge! It is easily six feet "+
    "wide and stands over twelve feet high. It is thick, solid, and covered with %^BOLD%^"+
    "%^CYAN%^symbols%^BOLD%^%^BLACK%^ which appear to be very ancient. Looking at it "+
    "closely it almost looks as if there is something inside, you are unable to make out "+
    "whatever it might be though. Just glancing at it somehow %^BOLD%^%^RED%^ENRAGES"+
    "%^BOLD%^%^BLACK%^ you! You have a very strong, uncontrollable urge to %^BOLD%^"+
    "%^WHITE%^destroy%^BOLD%^%^BLACK%^ it. You have no idea what this might accomplish but "+
    "you think it would at least sate your undeniable %^BOLD%^%^RED%^RAGE%^BOLD%^"+
    "%^BLACK%^.%^RESET%^");

    health = 675 + random(500);
    
    call_out("check_room", 12);    
}

void check_room()
{
    object *vics;
    int x;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
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
        tell_object(vics[x], "%^BOLD%^%^BLACK%^You are suddenly %^BOLD%^%^RED%^"+
        "ENRAGED%^BOLD%^%^BLACK%^ by the rune!%^RESET%^");
        vics[x]->force_me("destroy rune");
        continue;
    }
    call_out("check_room", 12);
    return;
}

void init()
{
    ::init();   
    add_action("destroy_function","destroy");
}

void set_which_rune(int x) { which_rune = x; }

void reform_rune()
{
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    tell_room(ETO, TO->query_short()+" %^BOLD%^%^WHITE%^REFORMS%^BOLD%^%^BLACK%^ and an "+
    "%^BOLD%^%^GREEN%^INSANE%^BOLD%^%^BLACK%^ cackle echoes all around you!%^RESET%^");
    health = 675 + random(500);
    
}

int destroy_function(string what) 
{
    int dam;
    if(!objectp(TO)) return 0;
    if(!objectp(ETO)) return 0;
    if(!objectp(TP)) return 0;
    if(!stringp(what)) return 0;
    if(TO != present(what, ETO)) return 0;
    if (TP->query_bound() || TP->query_unconscious() || TP->query_paralyzed()) 
    {
        TP->send_paralyzed_message("info",TP);
        return 1;
    }
    dam = roll_dice(10, 10)+10;
    health -= dam;
    if(health > 0) 
    {
        tell_object(TP, "%^BOLD%^%^BLACK%^You use your sudden %^BOLD%^%^RED%^RAGE%^BOLD%^%^BLACK%^ "+
        "to try to destroy the rune, but it defies you!%^RESET%^");

        tell_room(ETO, TPQCN+"%^BOLD%^%^BLACK%^ is suddenly %^BOLD%^%^RED%^ENRAGED%^BOLD%^%^BLACK%^"+
        " by the rune and tries to destroy it, but it defies "+TP->QO+"!%^RESET%^", TP);

        TP->set_paralyzed(10, "%^BOLD%^%^RED%^You are busy trying to destroy the rune!%^RESET%^");
        return 1;
    }
    else
    {
        tell_object(TP, "%^BOLD%^%^BLACK%^You use all of your %^BOLD%^%^RED%^"+
        "RAGE%^BOLD%^%^BLACK%^ and with a %^BOLD%^%^CYAN%^D%^BOLD%^%^WHITE%^EA"+
        "%^BOLD%^%^CYAN%^F%^BOLD%^%^CYAN%^EN%^BOLD%^%^WHITE%^ING%^BOLD%^%^BLACK%^ "+
        "ROAR the rune shatters!%^RESET%^");
        
        tell_room(ETO, TPQCN +"%^BOLD%^%^BLACK%^ uses all of "+TP->QP+" %^BOLD%^%^RED%^"+
        "RAGE%^BOLD%^%^BLACK%^ and with a %^BOLD%^%^CYAN%^D%^BOLD%^%^WHITE%^EA"+
        "%^BOLD%^%^CYAN%^F%^BOLD%^%^CYAN%^EN%^BOLD%^%^WHITE%^ING%^BOLD%^%^BLACK%^ "+
        "ROAR the rune shatters!%^RESET%^", TP);
        if(userp(TP)) 
        {                   
            SAVE_D->remove_array(which_rune+"_eldebaro_rune_delay");
            SAVE_D->remove_array(which_rune+"_eldebaro_rune");
            SAVE_D->set_value(which_rune+"_eldebaro_rune_delay", time() + 5400);
            ETO->dreadhorn_arrives(); 
            TO->remove();
        }
        else reform_rune();
    }
    return 1;
}		

int get() { return 0; }