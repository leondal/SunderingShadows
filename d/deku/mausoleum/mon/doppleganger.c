#include <std.h>

inherit MONSTER;

int drink_kit, flag, timer;
object current_room;
string after;

void create() 
{
    object ob;
    ::create();
}

void hunting(object targ)
{
    int lev, x, weaps;
    string *classes, *ids, race;
    object *inv, ob;
    if(!objectp(targ)) 
    {
        TO->remove();
        return;
    }
    after = targ->query_true_name();
    classes = (string *)targ->query_classes();
    lev = (int)targ->query_base_character_level();
    race = (string)targ->query_race();
    set_name((string)targ->getWholeDescriptivePhrase());
    set_id( ({ "doppleganger", race}) );
    set_race(race);
    set_gender((string)targ->query_gender());   
    set_short((string)targ->getWholeDescriptivePhrase());
    set_long((string)targ->getWholeDescriptivePhrase() + " " +(string)targ->query_description());   
    for(x = 0;x < sizeof(classes);x++)
    {
        set_class(classes[x], (int)targ->query_class_level(classes[x]));
        continue;
    }
    set_monster_feats((string *)targ->query_player_feats());
    set_max_hp((int)targ->query_max_hp() * 5);
    set_hp(query_max_hp());
    
    set_alignment((int)targ->query_alignment());
    set_size((int)targ->query_size());
    set_new_exp(lev, "high");    
    set_property("no death",1);
    set_overall_ac((int)targ->query_ac());
    set_property("no paralyze",1);
    set_property("full attacks", 1);
    set_property("magic resistance", (int)targ->query_property("magic resistance"));
    set_property("attack bonus", (int)targ->query_property("attack bonus"));
    set_property("damage bonus", (int)targ->query_property("damage bonus"));
    set_property("damage resistance", (int)targ->query_property("damage resistance"));
    set_stats("strength",(int)targ->query_stats("strength"));
    set_stats("intelligence",(int)targ->query_stats("intelligence"));
    set_stats("wisdom",(int)targ->query_stats("wisdom"));
    set_stats("dexterity",(int)targ->query_stats("dexterity"));
    set_stats("charisma",(int)targ->query_stats("charisma"));
    set_stats("constitution",(int)targ->query_stats("constitution"));    
    set_spells(({"fireball", "lightning bolt", "magic missile", "cone of cold", "meteor swarm", "hideous laughter"}));
    set_property("falls unconscious", 0);
    set_spell_chance(45);   
    set_speed(10 + random(25));
    set_moving(1);
    inv = deep_inventory(targ);    
    //tell_object(find_player("saide"), "inv variable = "+identify(inv));
    for(x = 0;x < sizeof(inv);x++)
    {
        //tell_object(find_player("saide"), "x = "+x);
        if(!objectp(inv[x])) { continue; }
        if(inv[x]->query_worn())
        {
            if(catch(ob = new(base_name(inv[x])))) { continue; }
            ob->move(TO);
            ob->set_property("monsterweapon", 1);
            command("wearall");
            if(!inv[x]->is_sheath()) continue;
        }
        if(inv[x]->query_wielded() && weaps < 2 || inv[x]->is_sheath())
        {
            if(inv[x]->is_sheath())
            {
                if(!sizeof(all_inventory(inv[x]))) { continue; }
                if(catch(ob = new(base_name(all_inventory(inv[x])[0])))) { continue; }              
            }
            else { if(catch(ob = new(base_name(inv[x])))) { continue; } }
            ob->move(TO);
            ob->set_property("monsterweapon", 1);
            ids = ob->query_id();
            if(!pointerp(ids) || !sizeof(ids))
            {
                ob->remove();
                continue;
            }
            command("wield "+ids[0]);
            weaps++;
            continue;
        }
        if((int)inv[x]->query_uses() && inv[x]->id("kit"))
        {
            if(catch(ob = new(base_name(inv[x])))) { continue; }
            ob->move(TO);
            ob->set_property("monsterweapon", 1);
            ob->set_uses((int)inv[x]->query_uses());
            drink_kit = 1;
            continue;
        }
        continue;
    }   
}

void die(object ob)
{
    if(objectp(current_room) && flag) current_room->set_no_clean(0);
    return ::die(ob);
}

void heart_beat()
{
    ::heart_beat();
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(sizeof(TO->query_attackers()))
    {
        if(drink_kit)
        {
            if((int)TO->query_hp() < ((int)TO->query_max_hp() / 8))
            {
                command("drink vial");
                command("drink vial");
                command("drink vial");
            }
        }
    }
    if(current_room != ETO)
    {
        if(objectp(current_room) && flag) current_room->set_no_clean(0);
        current_room = ETO;
        if(!current_room->query_no_clean()) 
        {
            flag = 1;
            current_room->set_no_clean(1);
        }
        else flag = 0;
    }
    if(sizeof(TO->query_attackers()))
    {
        timer = 7200;
        if(!query_no_clean()) set_no_clean(1);
    }
    else 
    {
        if(timer > 0) timer--;
        if(timer <= 0 && query_no_clean()) { set_no_clean(0); }
    }
    return;    
}

void init()
{
    ::init();
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!objectp(TP)) return;
    if(avatarp(TP)) return;
    if(userp(TP))
    {        
        command("kill "+TP->query_name());
        return;
    }
}

string *query_mini_quests() { return ({}); }
string *query_temporary_feats() { return ({}); }