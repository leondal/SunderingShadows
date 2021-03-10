#include <std.h>
#include <magic.h>
#include <daemons.h>
inherit OBJECT;

void create()
{
    ::create();
    set_property("no animate", 1);
    set_property("soulbound", 1); 
    
    set_id(({"alt world quest item", "alt world exit item", "tether", "plane tether", "tether to the prime material plane"}));
    set_name("tether to the prime material plane");
    set_short(CRAYON_D->color_string("Tether to The Prime Material Plane", "dark red"));   
    
    set_long("%^BOLD%^%^YELLOW%^You are not sure what you gaze upon. It is composed of a strange, unfathomable substance "+
    "that appears impervious to any type of harm. You feel a strange fondness come over you as you continue "+
    "to look at it. You realize that there is some powerful magic involved with its construction that is actually "+
    "bending your will. However, you also quickly recognize that it means you no harm at all, in fact it is "+
    "a tether between you and the prime material plane of existence. It is keeping you from being absorbed by the "+
    "reality that you are currently in. You also realize that you may use it to "+
    "%^BOLD%^%^CYAN%^leave event%^BOLD%^%^YELLOW%^ at anytime you are not in combat if you want to "+
    "return to the prime material plane of existence.%^RESET%^");        
    set_weight(0);

    
}

void init()
{
    object ob, *obs;
    int x;
    ::init();
    if(!objectp(TO)) return;
    if(!objectp(ETO) || !userp(ETO))
    {
        TO->remove();
        return;
    }
    
    obs = deep_inventory(ETO);
    for(x = 0;x < sizeof(obs);x++)
    {
        if(!objectp(obs[x])) continue;
        if(obs[x]->id("alt world exit item"))
        {
            if(obs[x] == TO || base_name(obs[x]) == "/d/common/obj/special/alt_world_quest_item") continue;
            obs[x]->remove();
            continue;
        }        
    }
    if(present("saidealtworldquestitem", ETO))
    {
        TO->remove();
        return;
    }
    add_action("exit_func", "leave");
}

void remove_my_tether()
{
    if(!objectp(TO)) return;
    TO->remove();
    return;
}

int exit_func(string str)
{
    if(!objectp(TO) || !objectp(ETO) || !objectp(EETO)) return 0;
    if(!stringp(str) || str != "event") return 0;
    if(ETO->query("alternative world") != EETO->query("alternative world") || !ETO->query("alternative world"))
    {
        tell_object(ETO, "You are not within an alternative world, or are within one for which this tether is not linked. "+
        "If you think this an error please contact an immortal for assistance.");
        call_out("remove_my_tether", 0.20);
        return 1;
    }
    if(sizeof(ETO->query_attackers()))
    {
        tell_object(ETO, "You are not able to do that during combat!");
        return 1;
    }
    ALT_WORLD_D->remove_from_alt_world(ETO);
    call_out("remove_my_tether", 0.20);
    return 1;
}
   