#include <std.h>
#include <dirs.h>
#include <daemons.h>
#include "area_stuff.h"
#include <magic.h>

#define VALID_TYPES ({"heaven", "power", "insight"})

inherit DAEMON;

mapping MANNA_EFFECTS;
mapping FAKE_MANA_EFFECTS;

void start_manna_d();
void setup_manna_effects(object who, mapping tmp, int mod);
void parse_mana_effects(object who, string type);
void dest_effect()
{
    if(!objectp(PO)) 
    {       
        return;
    }
    setup_manna_effects(PO, (mapping)PO->query_property("eldebaro manna"), -1);
    PO->remove_property("eldebaro manna");
    return;    
}

void setup_manna_effects(object who, mapping tmp, int mod)
{
    string *effects;
    int x;
    if(!objectp(who)) return;
    if(!mapp(tmp)) return;
    if(!intp(mod)) return;
    if(mod == 1)
    {
        who->remove_property("eldebaro manna");
        if(tmp["notified"]) tmp["notified"] = 1;
        who->set_property("eldebaro manna", tmp);            
        tell_object(who, "%^BOLD%^%^CYAN%^You feel the power of the manna changing you!%^RESET%^");
        who->set_property("spelled", ({TO}));
    }
    else if(mod == -1)
    {
        tell_object(who, "%^BOLD%^%^CYAN%^You feel the power of the manna leave you!%^RESET%^");
        map_delete(MANNA_EFFECTS, (string)who->query_true_name());
        who->remove_property("eldebaro manna");        
    }    
    effects = keys(tmp);    
    for(x = 0;x < sizeof(effects);x++) 
    {
        switch(effects[x])
        {
            case "will bonus":
                who->set_saving_bonus("will", (tmp[effects[x]]*mod));
                break;
            case "wisdom bonus":
                who->add_stat_bonus("wisdom", (tmp[effects[x]]*mod));
                break;
            case "strength bonus":
                who->add_stat_bonus("strength", (tmp[effects[x]]*mod));
                break;
            case "intelligence bonus":
                who->add_stat_bonus("intelligence", (tmp[effects[x]]*mod));
                break;
            case "health bonus":
                who->add_extra_hp((tmp[effects[x]]*mod));
                break;
            case "empowered bonus":
                who->set_property("empowered", (tmp[effects[x]]*mod));
                break;
        }
        continue;
    }
    
}

void process_manna_effects()
{
    //run fake shit/no affect first
    object who;
    int x;
    mixed *people;
    people = keys(FAKE_MANA_EFFECTS);
    for(x = 0;x < sizeof(people);x++)
    {
        if(!objectp(people[x]))
        {
            map_delete(FAKE_MANA_EFFECTS, people[x]);
            continue;
        }
        //require 1d10 seconds to kick in... though this 
        //will effectively be higher, depending on the call out 
        if((time() + roll_dice(1,10)) > FAKE_MANA_EFFECTS[people[x]])
        {
            map_delete(FAKE_MANA_EFFECTS, people[x]);
            tell_object(people[x], "%^BOLD%^%^WHITE%^You feel no different from the manna.%^RESET%^");
            continue;
        }
        continue;        
    }
    people = keys(MANNA_EFFECTS);
    for(x = 0;x < sizeof(people);x++)
    {
        //somehow got added wrong... delete it.
        if(!mapp(MANNA_EFFECTS[people[x]]))
        {
            map_delete(MANNA_EFFECTS, people[x]);
            continue;
        }
        if(!objectp(who = MANNA_EFFECTS[people[x]]["object"]))
        {
            map_delete(MANNA_EFFECTS, people[x]);
            continue;       
        }
        if((time() + roll_dice(1, 10)) > MANNA_EFFECTS[people[x]]["delay"] && MANNA_EFFECTS[people[x]]["notified"] == 0)
        {
            MANNA_EFFECTS[people[x]]["notified"] = 1;
            setup_manna_effects(who, MANNA_EFFECTS[people[x]], 1);            
            continue;
        }        
        
        if (MANNA_EFFECTS[people[x]]["notified"] == 1)
        {
            MANNA_EFFECTS[people[x]]["lasts for"] -= 12;
            if(MANNA_EFFECTS[people[x]]["lasts for"] <= 0)
            {
                setup_manna_effects(who, MANNA_EFFECTS[people[x]],-1);
                map_delete(MANNA_EFFECTS, people[x]);
                continue;
            }
        }
        continue;
    }
    if(sizeof(keys(FAKE_MANA_EFFECTS)) || sizeof(keys(MANNA_EFFECTS))) start_manna_d();
    return;
}

void start_manna_d()
{
    //tell_object(find_player("saide"), "Getting to start_manna_d");
    if(find_call_out("process_manna_effects") == -1) 
    {
        //tell_object(find_player("saide"), "call out getting started....");
        call_out("process_manna_effects", 12);
    }
    return;
}

void parse_mana_effects(object who, string type)
{
    int diff;
    mapping ben = ([]);
    if(!objectp(who)) return;
    if(type == "none")
    {
        FAKE_MANA_EFFECTS += ([who : time()]);
        start_manna_d();
        return;
    }   
    if(member_array((string)who->query_true_name(), keys(MANNA_EFFECTS)) != -1)
    {
        FAKE_MANA_EFFECTS += ([who : time()]);
        start_manna_d();
        return;
    }
    switch(type)
    {
        case "heaven":
            ben += (["will bonus" : 4]);
            diff = 30 - (int)who->query_stats("wisdom");
            if(diff > 4) diff = 4;
            ben += (["wisdom bonus" : diff]);
            break;
        case "power":
            ben += (["health bonus" : roll_dice(8,10)]);
            diff = 30 - (int)who->query_stats("strength");
            if(diff > 4) diff = 4;
            ben += (["strength bonus" : diff]);
            break;
        case "insight":
            ben += (["empowered bonus" : 4]);
            diff = 30 - (int)who->query_stats("intelligence");
            if(diff > 4) diff = 4;
            ben += (["intelligence bonus" : diff]);
            break;            
    }
    ben += (["notified" : 0, "object" : who, "delay" : (time() + roll_dice(1, 10)), "lasts for" : roll_dice(10,100)]);
    MANNA_EFFECTS += ([(string)who->query_true_name() : ben]);
    start_manna_d();
    return;
}

void register_effect(object who, string type)
{
    if(!objectp(who)) return;
    if(!stringp(type)) return;
    if(member_array(type, VALID_TYPES) == -1) return;
    if(who->query_property("eldebaro manna"))
    {
        parse_mana_effects(who, "none");
        return;
    }
    parse_mana_effects(who, type);
    who->set_property("eldebaro manna", type);
    return;
}

void create()
{
    MANNA_EFFECTS = ([]);
    FAKE_MANA_EFFECTS = ([]);
    return;
}

void identify_manna_effects()
{
    return MANNA_EFFECTS;
}

void identify_fake_manna_effects()
{
    return FAKE_MANA_EFFECTS;
}