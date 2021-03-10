/*
  empowered.c

  Enhances weapon with mental energy.

  -- Tlaloc --
*/

#include <std.h>
#include <daemons.h>

inherit DAEMON;

int empower_func(object ob)
{
    object room, player, spell, enemy;
    int amount, power;
    string pname, ename;
    mapping info;

    if(!objectp(ob))
        return 0;

    player = environment(ob);

    if(!userp(player))
        return 0;

    room = environment(player);

    if(!objectp(room))
        return 0;

    info = ob->query_property("temp_hit_bonus");
    spell = info["spell"];

    if(!objectp(spell))
        remove_prop(ob);

    enemy = player->query_current_attacker();

    if(!objectp(enemy))
        return 0;

    power = 1 + player->query_max_mp() / 50;

    if(player->query_mp() < power)
        return 0;

    pname = player->query_cap_name();
    ename = enemy->query_cap_name();

    amount = roll_dice(1, 8) + power * (player->query_guild_level("psywarrior") / 10);

    if(!random(10))
    {
        tell_object(player, "%^CYAN%^BOLD%^Your weapon strikes " + ename + " with a flare of psychic energy!%^RESET%^");
        tell_object(enemy, "%^CYAN%^BOLD%^" + pname + "'s weapon strikes you with a flare of psychic energy!");
        tell_room(room, "%^CYAN%^BOLD%^" + pname + "'s weapon strikes " + ename + " with a flare of psychic energy!", ({ player, enemy }));
        enemy->cause_typed_damage(enemy, enemy->return_target_limb(), amount, "mental");
        player->add_mp(-power);
    }
}

void remove_prop(object ob)
{
    object player;

    ob->remove_property_value("added short", ({ "%^CYAN%^BOLD%^ {empowered}%^RESET%^" }) );
    ob->remove_property("temp_hit_bonus");

    player = environment(this_object());
    player && tell_object(player, "%^CYAN%^The psychic energies fade from your weapon.%^RESET%^");
}
