#include <std.h>

int help(string str);

int cmd_rerollhitpoints(string str)
{
    object player;

    if(!stringp(str) || str == "" || str == " ")
    {
        return help(str);
    }

    if(!objectp(player = find_player(str)))
    {
        tell_object(TP,"Can't seem to find the player "+str);
        return 1;
    }

    player->delete("hp_array");
    tell_object(TP,"Old hitpoint total, including con bonus: "+player->query_max_hp());
    player->make_new_hitpoint_rolls(player);
    tell_object(TP,"New hitpoint total, including con bonus: "+player->query_max_hp());

    return 1;
}

int help(string str)
{
    tell_object(TP,"Syntax rerollhitpoints <target>\n"
        "This will reroll the hitpoints of any character that needs it.  For especially low hitpoint "
        "totals, usually.");
    return 1;
}

