#include <std.h>
#include <magic.h>
#include <daemons.h>
#define COLS ({"%^RED%^", "%^ORANGE%^", "%^YELLOW%^", "%^GREEN%^", "%^BLUE%^", "%^WHITE%^", "%^CYAN%^"})
inherit OBJECT;

int started;

string my_targ;

void fix_inventory(object mob)
{
    if(!objectp(mob)) return;
    foreach(object mobitem in all_inventory(mob))
    {
        if(!objectp(mobitem)) continue;
        mobitem->set_property("monsterweapon", 1);
        mobitem->set_property("monster weapon", 1);
        continue;
    }
    return;
}

void remove_me()
{
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    ETO->move("/d/shadowgate/void");
    if(objectp(ETO)) ETO->remove();
    if(objectp(TO)) TO->remove();
    return;
}

void do_start()
{
    mapping my_mobs;
    string *mychoices, col, bcol;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) 
    {
        TO->remove();
        return;
    }
    if(!living(ETO)) 
    {
        TO->remove();
        return;
    }
    if(userp(ETO) || ETO->query("alternative world okay")) 
    {
        TO->remove();
        return;
    }
    if(!objectp(EETO)) 
    {
        TO->remove();
        return;
    }
    if(!mapp(my_mobs = EETO->query("alt world monsters")) || !pointerp(mychoices = keys(my_mobs)))
    {
        ETO->set("alternative world okay", 1);
        fix_inventory(ETO);
        TO->remove();
        return;
    }    
    if(EETO->query("alt world quest"))
    {
        call_out("remove_me", 1);
        return;
    }        
    my_targ = mychoices[random(sizeof(mychoices))]; 
    /*ETO->set_property("no kill", 1);
    ETO->set_property("damage resistance", 100000000);
    ETO->set_property("weapon resistance", 1000);
    ETO->set_property("spell damage resistance", 10000000);*/
    if(userp(ETO) || ETO->query("alternative world okay") || ETO->query_property("minion") ||
    ETO->query_property("spell_creature") || ETO->is_merc())
    {
        ETO->set("alternative world okay", 1);
        TO->remove();
        return;
    }
    fix_inventory(ETO);
    ETO->remove_property("no paralyze");
    ETO->set_paralyzed(1000000000, "You are unable to move!");
    call_out("do_alt_world_morph", ROUND_LENGTH * 2);
    col = COLS[random(sizeof(COLS))];
    bcol = "%^BOLD%^"+col;
    tell_room(EETO, ETOQCN+col+" is wrong.... something about "+ETO->QO+" is off...."+bcol+
    capitalize(ETO->QS)+" is CHANGING!%^RESET%^");
    return;
}

void update_quest_item(object mon)
{
    object area, QuestOb;
    int mcount;
    if(!objectp(TO) || !objectp(mon)) return;
    if(!objectp(area = environment(mon))) return;
    if(!area->query("alt world quest")) return;
    area->set("monster count", area->query("monster count") + 1);
    if(objectp(QuestOb = area->query("alt world quest item")))
    {
        ALT_WORLD_D->update_alt_world(area->query("alternative world"), QuestOb, (int)area->query("monster count"), area);
        return;
    }
    if(area->query("monster count") > roll_dice(1, 100))
    {        
        if(!random(3))
        {
            QuestOb = new("/d/common/obj/special/alt_world_fragment");
            QuestOb->set_reward_type(area->query("reward type"));
            if(roll_dice(1,20) >= 10)
            {
                QuestOb->move(mon);                               
            }
            else QuestOb->move(area);
            area->set("alt world quest item", QuestOb);
        }
    }
    ALT_WORLD_D->update_alt_world(area->query("alternative world"), QuestOb, (int)area->query("monster count"), area);    
    return;
}

void do_alt_world_morph()
{
    string col, bcol;
    object mymob, loc;
    if(!objectp(TO)) return;
    if(!objectp(ETO) || !objectp(EETO))
    {
        TO->remove();
        return;
    }
    if(catch(mymob = new(my_targ)))
    {
        log_file("alternative_world_failures", "Failed to create new monster "+my_targ+" to "+
        "replace "+identify(ETO)+" at "+base_name(EETO)+".\n");        
        ETO->set("alternative world okay", 1);
        ETO->remove_paralyzed();        
        TO->remove();
        return;        
    }    
    col = COLS[random(sizeof(COLS))];
    bcol = "%^BOLD%^"+col;
    if(objectp(ETO) && objectp(mymob))
    {
        tell_room(EETO, ETO->QCN+col+" has completed "+ETO->QP+bcol+" change into "+
        mymob->QCN+"!%^RESET%^");
        /*if(sizeof(all_inventory(ETO)))
        {
            all_inventory(ETO)->move(mymob);
        }*/
        loc = EETO;
        mymob->set("alternative world okay", 1);
        if(loc->query("alt world quest"))
        {
            ETO->move("/realms/saide/workroom");
            ETO->move("/d/shadowgate/void");
            if(objectp(ETO)) ETO->remove();
            if(objectp(TO)) TO->remove();
            return;
        }        
        mymob->move(loc);
        mymob->force_me("wearall"); 
        fix_inventory(mymob);
        mymob->set_property("swarm", 1);
        mymob->set_property("full attacks", 1);
        ETO->move("/d/shadowgate/void");
        update_quest_item(mymob);        
        if(objectp(ETO)) ETO->remove();
        if(objectp(TO)) TO->remove();
    }    
    return;    
}

void create()
{
    ::create();
    set_property("no animate", 1);
    set_property("no drop", 1);
    set_property("soulbound", 1);
    started = 0;
}

void init()
{
    ::init();   
    if(!objectp(TO) || started) return;    
    if(objectp(ETO)) 
    {        
        if(userp(ETO) || ETO->query("alternative world okay") || ETO->query_property("minion") ||
        ETO->query_property("spell_creature") || ETO->is_merc())
        {
            TO->remove();
            return;
        }
        if(objectp(ETO->query_creator()) && ETO->query_creator()->query("alternative world okay"))
        {
            ETO->set("alternative world okay", 1);
            TO->remove();
            return;
        }
        if(living(ETO))
        {            
            started = 1;
            do_start();  
            return;
        }
        TO->remove();
        return;
    }
    return;
}
