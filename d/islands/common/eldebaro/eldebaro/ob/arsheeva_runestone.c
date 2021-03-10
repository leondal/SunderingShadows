#include <std.h>
#include <daemons.h>
#include "../area_stuff.h"
inherit OBJECT;
int health, been_shadowed;
object shadow;

void create() 
{
    ::create();
    set_name("a dark pulsating orb");
    set_value(0);
    set_weight(10000);
    
    set_id(({"orb", "dark pulsating orb", "dark orb", "eldebarodarkorb"}));
    set_property("no animate", 1);

    set_short("%^BOLD%^%^BLACK%^A d%^BOLD%^%^WHITE%^a%^BOLD%^%^BLACK%^rk "+
    "p%^BOLD%^%^WHITE%^u%^BOLD%^%^BLACK%^l%^BOLD%^%^WHITE%^s%^BOLD%^%^BLACK%^"+
    "a%^BOLD%^%^CYAN%^t%^BOLD%^%^WHITE%^i%^BOLD%^%^BLACK%^n%^BOLD%^%^WHITE%^g "+
    "%^BOLD%^%^BLACK%^o%^BOLD%^%^WHITE%^r%^BOLD%^%^BLACK%^b%^BOLD%^%^WHITE%^"+
    " ( %^BOLD%^%^CYAN%^hovering in the air%^BOLD%^%^WHITE%^ )%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^This strange orb pulsates constantly and chaotically. "+
    "It reminds you of something struggling to breath with each pulse. There is a tremendous "+
    "power radiating out from it, which threatens to consume everything around it. There is something "+
    "%^BOLD%^%^RED%^EVIL%^BOLD%^%^BLACK%^ about it which you can neither understand nor deny. It "+
    "crackles with %^BOLD%^%^CYAN%^electricity%^BOLD%^%^BLACK%^ which zaps out constantly from "+
    "inside of it. "+
    "You are not sure where it came from or who created it. You do know though, that currently it is "+
    "serving as a ward, protecting Arsheeva Wyndar from harm. You could try to <%^BOLD%^%^WHITE%^"+
    "destroy%^BOLD%^%^BLACK%^> it.%^RESET%^");
    
    health = 1200 + random(500);
    
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
        if(vics[x]->id("eldebaroshadowevil")) continue;
        if(vics[x]->id("arsheeva_wyndar")) continue;
        if(vics[x]->query_true_invis()) continue;
        tell_room(ETO, "%^BOLD%^%^YELLOW%^Lightning zaps out from the orb "+
        "and strikes "+vics[x]->QCN+"%^BOLD%^%^YELLOW%^!", vics[x]);
        tell_object(vics[x], "%^BOLD%^%^YELLOW%^A bolt of lightning zaps out from "+
        "the orb and strikes you!%^RESET%^");
        if(!interactive(vics[x])) 
        {   
            tell_room(ETO, vics[x]->QCN+"%^BOLD%^%^BLACK%^ is INCINERATED!%^RESET%^");
            vics[x]->move("/d/shadowgate/void");
            if(objectp(vics[x])) vics[x]->remove();
            continue;
            //vics[x]->cause_typed_damage(vics[x], vics[x]->return_target_limb(), 100000, "electricity");  
            
        }            
        else vics[x]->cause_typed_damage(vics[x], vics[x]->return_target_limb(), roll_dice(6, 10), "electricity");        
        vics[x]->add_attacker(TO);
        vics[x]->continue_attack();
        if(!objectp(vics[x])) continue;
        if(!interactive(vics[x])) continue;
        if(!objectp(shadow) && !random(10)) 
        {
            shadow = new(ELMON+"shadow");
            shadow->focus_on(vics[x]);
            shadow->lasts_for(-1);
            shadow->move(ETO);
        }
        else if(objectp(shadow) && !random(6))
        {
            shadow->focus_on(vics[x]);
        }
        else if(objectp(shadow) && !random(3))
        {
            shadow->interact();
        }
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
        tell_object(TP, "%^BOLD%^%^WHITE%^You try to destroy the orb but it absorbs your "+
        "attempt!%^RESET%^");

        tell_room(ETO, TPQCN+"%^BOLD%^%^WHITE%^ tries to destroy the orb but it "+
        "seems to absorb "+TP->QP+" attempt!%^RESET%^", TP);

        TP->set_paralyzed(5, "%^BOLD%^%^RED%^You are busy trying to destroy the orb!%^RESET%^");
        return 1;
    }
    else
    {
        tell_object(TP, "%^BOLD%^%^BLACK%^You use all of your strength "+
        "and with a %^BOLD%^%^CYAN%^D%^BOLD%^%^WHITE%^EA"+
        "%^BOLD%^%^CYAN%^F%^BOLD%^%^CYAN%^EN%^BOLD%^%^WHITE%^ING%^BOLD%^%^BLACK%^ "+
        "ROAR the orb shatters!%^RESET%^");
        
        tell_room(ETO, TPQCN +"%^BOLD%^%^BLACK%^ uses all of "+TP->QP+" "+
        "strength and with a %^BOLD%^%^CYAN%^D%^BOLD%^%^WHITE%^EA"+
        "%^BOLD%^%^CYAN%^F%^BOLD%^%^CYAN%^EN%^BOLD%^%^WHITE%^ING%^BOLD%^%^BLACK%^ "+
        "ROAR the orb shatters!%^RESET%^", TP);
        RUNEPLACE->update_rune_location(ETO);        
        TO->remove();
    }
    return 1;
}		

int get() { return 0; }