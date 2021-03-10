#include <std.h>
#include "area_stuff.h"

inherit MONSTER;

void create() 
{
    object ob;
    ::create();
    set_property("no tripped", 1);
    set_property("no death", 1);
    set_property("full attacks", 1);
    if(!random(20))
    {
        ob = new(ELOB+"manna");
        ob->move(TO);
    }
}

int player_target(object vic)
{
    if(!objectp(TO)) return 0;
    if(!objectp(vic)) return 0;
    if(vic->query_true_invis()) return 0;
    if(!userp(vic)) return 0;
    return 1;
}

int non_player_target(object vic)
{
    if(!objectp(TO)) return 0;
    if(!objectp(vic)) return 0;
    if(!interactive(vic) && !vic->is_merc() && !userp(vic)) return 1;
    return 0;
}

void something_evil(object targ)
{
    object shadow, *vics;
    string *funcs, func_to_call;
    int x;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(random(10)) return; // Making the spawning of the Shadow much rarer, 4 Dec 19, Uriel
    
    vics = filter_array(TO->query_attackers(), "player_target", TO);
    if(!sizeof(vics)) return;
    targ = vics[random(sizeof(vics))];
    //no more than 1 shadow at a time
    if(present("eldebaroshadowevil", ETO)) 
    {
        funcs = TO->query_funcs();
        if(!pointerp(funcs) || !sizeof(funcs)) return;
        funcs -= ({"something_evil"});
        func_to_call = funcs[random(sizeof(funcs))];
        call_other(TO, func_to_call, targ);
        return;
    }
    tell_room(ETO, "%^BOLD%^%^BLACK%^A shadow rises above "+TO->query_name()+"%^BOLD%^%^BLACK%^.....");
    
    tell_room(ETO, "%^BOLD%^%^GREEN%^The shadow materializes..... becoming something whole!%^RESET%^");
    
    tell_room(ETO, "%^BOLD%^%^WHITE%^The shadow cackles %^BOLD%^%^RED%^INSANELY%^BOLD%^WHITE%^ as it turns it gaze on "+targ->QCN+"%^BOLD%^%^WHITE%^!%^RESET%^", targ);
    
    tell_object(targ, "%^BOLD%^%^WHITE%^The shadow cackles %^BOLD%^%^RED%^INSANELY%^BOLD%^%^WHITE%^ and you feel its dreadful gaze upon %^BOLD%^%^RED%^YOU%^BOLD%^%^WHITE%^!");
    
    shadow = new(ELMON+"shadow");    
    shadow->move(ETO); 
    shadow->focus_on(targ);    
    shadow->lasts_for(roll_dice(1,4));    
    
    vics = filter_array(TO->query_attackers(), "non_player_target", TO);
    
    if(!sizeof(vics)) return;
    
    x = random(sizeof(vics));
    while(x--)
    {
        if(objectp(vics[x]))
        {       
            tell_room(ETO, "%^BOLD%^%^BLACK%^The shadow absorbs the very life from "+vics[x]->QCN+" and feeds it to "+TO->query_name()+"%^BOLD%^%^BLACK%^!%^RESET%^");
            TO->heal((int)vics[x]->query_hp());
            vics[x]->die();
            continue;
        }
        if(x < 0) break;        
    }
    return;
       
}
int query_watched() { return random(101); }
