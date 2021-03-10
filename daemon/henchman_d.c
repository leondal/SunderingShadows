#include <std.h>
#include <daemons.h>
#include <security.h>

inherit DAEMON;

#define SAVE_FILE "/daemon/save/henchmen_saves"

mapping DATA_MAP;

// adjust this to modify cost to hire henchmen
                                        // if they keep it for more than a day, the next
                                        // time they hire one, it costs double.  If they
                                        // get a henchman killed the next time it costs
                                        // tripple.  If they do both, the next time it
                                        // costs 10 times the original amount

nosave int BASE_COST_PER_LEVEL = 599;

void create()
{
    ::create();
    DATA_MAP = ([]);
    seteuid(UID_DAEMONSAVE);
    restore_object(SAVE_FILE);
    seteuid(geteuid());
}


void save_me()
{
    seteuid(UID_DAEMONSAVE);
    save_object(SAVE_FILE);
    seteuid(geteuid());
    return;
}


string get_data_map() { return identify(DATA_MAP); }

// could stick other types in here.. like abuse.. to make them cost more, or an impossible amount
void penalize(mixed player, string type)
{
    string name;
    if(!player) { return; }


    if(objectp(player)) { name = (string)player->query_true_name(); }
    else if(stringp(player))
    {
        if(user_exists(player)) { name = player; }
    }
    if(!name) { return; }

    if(!mapp(DATA_MAP)) { DATA_MAP = ([]); }
    if(!mapp(DATA_MAP[name])) { DATA_MAP[name] = ([]); }

    switch(type)
    {
    case "late":
        DATA_MAP[name]["late"] = 1;
        save_me();
        break;
    case "dead":
        DATA_MAP[name]["dead"] = 1;
        save_me();
        break;
    }

    return;
}


void remove_penalty(object player)
{
    string name;
    if(!objectp(player)) { return; }
    name = (string)player->query_true_name();
    if(!mapp(DATA_MAP)) { DATA_MAP = ([]); }
    DATA_MAP[name] = ([]);
    save_me();
    return;
}


int is_late(string name)
{
    if(DATA_MAP[name]["late"]) { return 1; }
    return 0;
}


int got_killed(string name)
{
    if(DATA_MAP[name]["dead"]) { return 5; }
    return 0;
}


string has_penalty(object player)
{
    string name;
    int num = 0;
    if(!objectp(player)) { return "no player"; }
    name = (string)player->query_true_name();

    if(!mapp(DATA_MAP))
    {
        DATA_MAP = ([]);
        save_me();
        return "none";
    }

    if(!mapp(DATA_MAP[name]))
    {
        DATA_MAP[name] = ([]);
        save_me();
        return "none";
    }

    num += is_late(name); // adds 1 if they were late
    num += got_killed(name); // adds 5 if they got the hire killed

    switch(num)
    {
    case 1:     return "late";
    case 5:     return "dead";
    case 6:     return "both";
    default:    return "none";
    }
    return "none";
}


int calculate_price(object player)
{
    int cost,level;
    string penalty;
    if(!objectp(player)) { return -1; }

    penalty = has_penalty(player);

    level = (int)player->query_base_character_level();

    if(level < 5) { return -1; }

    cost = BASE_COST_PER_LEVEL;

    cost = cost * level;

    if(player->query_true_invis()) { cost = 1; }

    switch(penalty)
    {
    case "no player": return -1;
    case "none": break;
    case "late":
        cost = cost * 2;
        break;
    case "dead":
        cost = cost * 3;
        break;
    case "both":
        cost = cost * 10;
        break;
    default: break;
    }

    return cost;
}
