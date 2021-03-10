#include <std.h>
#include <magic.h>
#include <daemons.h>
inherit OBJECT;

string myaltworld;
int started, timer = 120;
object *players, *player_objects, *verified_objects;
mapping peri;

void create()
{
    ::create();
    set_property("no animate", 1);
    set_property("no drop", 1);
    set_property("soulbound", 1);
    set_id(({"alt world creator", "creator"}));
    set_name("alt world creator");
    set_short("an alt world creator");
    set_long("An alt world creator");
    set_heart_beat(1);
    started = 0;
}

void alt_world(string str)
{
    int minlev, maxlev, x, mylev;
    object *pl, *obs, check_obj;
    if(!stringp(str)) return;
    myaltworld = str;
    if(!mapp(peri))
    {
        TO->remove();
        return;
    }
    if(peri["party area"] == 1)
    {
        players = PARTY_D->query_party_members(PARTY_D->party_member(peri["created for"]));
        if(!pointerp(players) || !sizeof(players)) players = ({peri["created for"]});
    }
    else
    {
        minlev = peri["low level"];
        maxlev = peri["high level"];
        pl = users();
        players = ({});
        for(x = 0; x < sizeof(pl);x++)
        {
            if(!objectp(pl[x])) continue;
            mylev = pl[x]->query_base_character_level();
            if(mylev < minlev || mylev > maxlev) continue;
            //if(pl[x]->query_true_name() != "testsubject") continue;
            players += ({pl[x]});
            continue;
        }
    }
    if(!sizeof(players))
    {
        TO->remove();
        return;
    }
    foreach(object player in players)
    {
        if(!objectp(player)) continue;
        check_obj = new("/d/common/obj/special/alt_world_check.c");
        if(!objectp(check_obj)) continue;
        check_obj->alt_world_message(peri["invite msg"]);
        check_obj->alt_world_accept(peri["accept msg"]);
        check_obj->alt_world_decline(peri["decline msg"]);
        if(peri["created for"])
        {
            if(!objectp(peri["created for"]))
            {
                check_obj->remove();
                break;
            }
            mylev = peri["created for"]->query_base_character_level();
            if(absolute_value(((int)player->query_base_character_level() - mylev)) > 5)
            {
                check_obj->remove();
                continue;
            }   
            if(environment(player) != environment(peri["created for"]))
            {
                check_obj->remove();
                continue;
            }
        }    
        check_obj->set_for_player(player);
        check_obj->move(player);
        TO->add_object_to_check(check_obj);
        continue;
    }
    TO->move("/realms/saide/workroom");
    return;    
}

void set_players(object *pl)
{
    if(pointerp(pl)) 
    {
        players = pl;
        return;
    }
    return;
}

string query_alt_world() { return myaltworld; }
mapping myperi() { return peri; }
void alt_world_perimeters(mapping ma)
{
    if(mapp(ma)) peri = copy(ma);
}

void add_object_to_check(object ob)
{
    if(!objectp(ob)) return;
    if(!pointerp(player_objects)) player_objects = ({});
    if(member_array(ob, player_objects) == -1)
    {
        player_objects += ({ob});
        return;
    }
    return;
}

void start_alt_world()
{
    object world, *object_list, *vics;
    int x;
    if(!objectp(TO)) return;
    if(!pointerp(verified_objects) || !mapp(peri) || !pointerp(players))
    {
        TO->remove();
        return;
    }
       
    object_list = ({});
    vics = ({});
    /*if(find_player("saide"))
    {
        tell_object(find_player("saide"), "verified_objects = "+identify(verified_objects));
    }*/
    for(x = 0;x < sizeof(verified_objects);x++)
    {
        if(!objectp(verified_objects[x])) continue;
        if(member_array(environment(verified_objects[x]), players) == -1) continue;
        if(environment(verified_objects[x])->query("alternative world")) continue;
        vics += ({environment(verified_objects[x])});
        object_list += ({environment(verified_objects[x])});
        continue;
    }
    world = new(peri["start room"]);
    object_list += ({world}); 
    
    /*if(find_player("saide"))
    {
        tell_object(find_player("saide"), "object_list = "+identify(object_list));
    }*/
    
    while(sizeof(object_list) > 0)
    {
        if(peri["alt world borders"]) object_list[0]->set("alt world borders", peri["alt world borders"]);
        if(peri["alt world monsters"]) object_list[0]->set("alt world monsters", peri["alt world monsters"]);
        if(peri["alt world monster chance"]) object_list[0]->set("alt world monster chance", peri["alt world monster chance"]);
        object_list[0]->set("alternative world", myaltworld);
        if(peri["alt allow normal monsters"]) object_list[0]->set("alt allow normal monsters", peri["alt allow normal monsters"]);
        else object_list[0]->set("alt allow normal monsters", 0);
        if(peri["alt world ends at"]) object_list[0]->set("alt world ends at", time() + peri["alt world ends at"]);
        if(peri["alt world special rooms"]) object_list[0]->set("alt world special rooms", peri["alt world special rooms"]);
        if(pointerp(peri["alt world exit rooms"])) object_list[0]->set("alt world exit rooms", peri["alt world exit rooms"]);
        if(intp(peri["alt world guards"])) object_list[0]->set("alt world guards", peri["alt world guards"]);
        if(peri["alt world quest"] > 0) 
        {            
            object_list[0]->set("alt world quest", 1);
            if(!objectp(peri["created for"]))
            {
                /*if(find_player("saide"))
                {
                    tell_object(find_player("saide"), "removing this object?");
                }*/    
                TO->remove();
                return;
            }
            object_list[0]->set("created for", peri["created for"]);
            object_list[0]->set("created for player", peri["created for"]->query_true_name());
        }
        if(intp(peri["party area"])) object_list[0]->set("party area", 1);
        if(stringp(peri["reward type"])) object_list[0]->set("reward type", peri["reward type"]);
        object_list -= ({object_list[0]});
        continue;
    }
    foreach(object vic in vics)
    {
        if(!objectp(vic)) continue;
        vic->set("entered alt world", base_name(environment(vic)));
        if(stringp(peri["start msg"])) tell_object(vic, peri["start msg"]);
        else tell_object(vic, "Event "+myaltworld+" is now starting!");
        vic->move_player(world); 
        new("/d/common/obj/special/alt_world_exit_item")->move(vic);
        continue;
    }
    for(x = 0;x < sizeof(verified_objects);x++)
    {
        if(!objectp(verified_objects[x])) continue;
        if(verified_objects[x] == TO || living(verified_objects[x])) continue;
        verified_objects[x]->remove();
        continue;
    }
    TO->remove();
    return;   
}

void heart_beat()
{
    object who, *to_remove;
    int x;
    if(!objectp(TO)) return;
    if(!pointerp(verified_objects)) verified_objects = ({});
    timer--;
    if(!timer || !sizeof(player_objects)) 
    {
        start_alt_world();
        return;
    }
    to_remove = ({});
    for(x = 0;x < sizeof(player_objects);x++)
    {
        if(!objectp(player_objects[x])) 
        {
            to_remove += ({player_objects[x]});
            continue;
        }
        if(player_objects[x]->query_is_in())
        {
            verified_objects += ({player_objects[x]});
            to_remove += ({player_objects[x]});
            continue;
        }
    }
    if(sizeof(to_remove))
    {
        player_objects -= to_remove;
    }
    return;
}