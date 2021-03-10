/*
  acidic.c

  Adds a chance to do 4d6 acid damage on hit.

  -- Tlaloc --
*/

#include <std.h>
#include <daemons.h>

inherit DAEMON;

int acid_func(object ob)
{
    object room, player, spell, enemy;
    int amount;
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

    pname = player->query_cap_name();
    ename = enemy->query_cap_name();
    amount = roll_dice(4, 6);
    amount = min( ({ player->query_level(), amount }) );

    if(!random(10))
    {
        tell_object(player, "%^GREEN%^Your weapon splashes acid on " + ename + ", dissolving their flesh!%^RESET%^");
        tell_object(enemy, "%^GREEN%^" + pname + "'s weapon splashes acid on you, dissolving your flesh!");
        tell_room(room, "%^GREEN%^" + pname + "'s weapon splashes acid on " + ename + ", dissolving their flesh!", ({ player, enemy }));
        enemy->cause_typed_damage(enemy, enemy->return_target_limb(), amount, "acid");
    }
}

void remove_prop(object ob)
{
    object player;

    ob->remove_property_value("added short", ({ "%^GREEN%^BOLD%^ {acidic}%^RESET%^" }) );
    ob->remove_property("temp_hit_bonus");

    player = environment(this_object());
    player && tell_object(player, "%^GREEN%^The acid fades from your weapon.%^RESET%^");
}
