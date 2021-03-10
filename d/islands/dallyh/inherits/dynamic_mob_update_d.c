/*==============================================================================================================================================
a daemon that dynamically updates monsters for # of players in a room

should check approximately 1 time per minute - after initial heart beat set up 

================================================================================================================================================*/
#include <std.h>
#include <daemons.h>

inherit DAEMON;

void dynamic_update(object ob)
{
    object env, *pls;
    int setFor, pSetFor; // setFor = amount of players this mob has been updated for, pSetFor, previous amount of players this mob was set for
    float CurHpPerc;
    int baseHP;
    if(!objectp(ob)) return;
    if(!objectp(env = environment(ob))) return;
    if(!sizeof(pls = filter_array(all_inventory(env), "is_non_immortal_player", FILTERS_D))) return;
    setFor = sizeof(pls);
    pSetFor = (int)ob->query("dynamically_updated_for");
    if(pSetFor == setFor) return;    
    ob->set("dynamically_updated_for", setFor);
    ob->set("damage mod", (setFor/2));
    if(!(int)ob->query("base_hp")) ob->set("base_hp", ob->query_max_hp());
    baseHP = (int)ob->query("base_hp");
    CurHpPerc = (percent(ob->query_hp(), ob->query_max_hp())) / 100;
    ob->set_max_hp(baseHP * setFor);
    ob->set_hp(to_int(((int)ob->query_max_hp() * CurHpPerc)));
    return;
}