/*
  bane.c

  Bane feature from PF SRD for Inquisitors
  Temporarily buffs your weapon to do more
  damage to a specific type of enemy.

  -- Tlaloc --
*/

#include <std.h>
#include <daemons.h>

inherit DAEMON;

int bane_func(object ob)
{
    object room, player, spell, enemy;
    string *ids, pname, ename, bane_type;
    int valid, damage, glvl;

    if(!ob)
        return 0;

    player = environment(ob);
    player && room = environment(player);

    if(!player || !room)
        return 0;

    bane_type = ob->query_property("bane type");

    if(!bane_type)
        return 0;

    spell = ob->query_property("temp_hit_bonus")["spell"];

    if(!spell)
        return 0;

    enemy = player->query_current_attacker();

    if(!enemy)
        return 0;

    if(ob != player->query_wielded()[0])
        return 0;

    valid = 0;
    ids = enemy->query_id();

    foreach(string id in ids)
    {
        if(USER_D->is_valid_enemy(id, bane_type))
            valid = 1;
    }

    if(!valid)
        return 0;

    glvl = player->query_guild_level("inquisitor");
    //Damage scales from 1dWC + 2 to 6dWC + 2
    damage = (ob->query_wc() + 2) * (1 + glvl / 10);

    if(random(10 - glvl / 10))
        return 0;

    pname = player->query_cap_name();
    ename = enemy->query_cap_name();

    switch(player->query_true_align())
    {
        case 1:
        case 4:
        case 7:
        tell_object(player, "%^BOLD%^WHITE%^Your weapon s%^CYAN%^i%^RESET%^%^CYAN%^n%^BOLD%^%^WHITE%^gs with r%^CYAN%^i%^RESET%^%^CYAN%^g%^BOLD%^%^WHITE%^ht%^CYAN%^e%^RESET%^%^CYAN%^o%^BOLD%^%^WHITE%^us g%^CYAN%^l%^RESET%^%^CYAN%^o%^BOLD%^%^WHITE%^ry as it cuts into your foe!%^RESET%^");
        tell_object(enemy, "%^BOLD%^WHITE%^" + pname + "'s weapon s%^CYAN%^i%^RESET%^%^CYAN%^n%^BOLD%^%^WHITE%^gs with r%^CYAN%^i%^RESET%^%^CYAN%^g%^BOLD%^%^WHITE%^ht%^CYAN%^e%^RESET%^%^CYAN%^o%^BOLD%^%^WHITE%^us g%^CYAN%^l%^RESET%^%^CYAN%^o%^BOLD%^%^WHITE%^ry as it cuts into you!%^RESET%^");
        tell_room(room, "%^BOLD%^WHITE%^" + pname + "'s weapon s%^CYAN%^i%^RESET%^%^CYAN%^n%^BOLD%^%^WHITE%^gs with r%^CYAN%^i%^RESET%^%^CYAN%^g%^BOLD%^%^WHITE%^ht%^CYAN%^e%^RESET%^%^CYAN%^o%^BOLD%^%^WHITE%^us g%^CYAN%^l%^RESET%^%^CYAN%^o%^BOLD%^%^WHITE%^ry as it cuts into " + ename + "!%^RESET%^", ({ player, enemy }));
        break;
        case 2:
        case 5:
        case 8:
        tell_object(player, "%^BOLD%^CYAN%^Your weapon c%^WHITE%^u%^RESET%^%^CYAN%^t%^BOLD%^s into your foe with t%^WHITE%^i%^RESET%^%^CYAN%^r%^BOLD%^el%^WHITE%^e%^RESET%^%^CYAN%^s%^BOLD%^s v%^WHITE%^i%^RESET%^%^CYAN%^g%^BOLD%^or!%^RESET%^");
        tell_object(enemy, "%^BOLD%^CYAN%^" + pname + "'s weapon c%^WHITE%^u%^RESET%^%^CYAN%^t%^BOLD%^s into you with t%^WHITE%^i%^RESET%^%^CYAN%^r%^BOLD%^el%^WHITE%^e%^RESET%^%^CYAN%^s%^BOLD%^s v%^WHITE%^i%^RESET%^%^CYAN%^g%^BOLD%^or!%^RESET%^");
        tell_room(room, "%^CYAN%^BOLD%^" + pname + "'s weapon c%^WHITE%^u%^RESET%^%^CYAN%^t%^BOLD%^s into " + ename + " with t%^WHITE%^i%^RESET%^%^CYAN%^r%^BOLD%^el%^WHITE%^e%^RESET%^%^CYAN%^s%^BOLD%^s v%^WHITE%^i%^RESET%^%^CYAN%^g%^BOLD%^or!%^RESET%^", ({ player, enemy }));
        break;
        case 3:
        case 6:
        case 9:
        tell_object(player, "%^BOLD%^BLACK%^Your weapon t%^RESET%^%^CYAN%^e%^BOLD%^a%^WHITE%^r%^BLACK%^s into your foe with r%^RESET%^%^CYAN%^e%^BOLD%^l%^WHITE%^e%^BLACK%^nt%^RESET%^%^CYAN%^l%^BOLD%^e%^WHITE%^s%^BLACK%^s h%^RESET%^%^CYAN%^u%^BOLD%^n%^WHITE%^g%^BLACK%^er!%^RESET%^");
        tell_object(enemy, "%^BLACK%^BOLD%^" + pname + "'s weapon t%^RESET%^%^CYAN%^e%^BOLD%^a%^WHITE%^r%^BLACK%^s into you with r%^RESET%^%^CYAN%^e%^BOLD%^l%^WHITE%^e%^BLACK%^nt%^RESET%^%^CYAN%^l%^BOLD%^e%^WHITE%^s%^BLACK%^s h%^RESET%^%^CYAN%^u%^BOLD%^n%^WHITE%^g%^BLACK%^er!%^RESET%^");
        tell_room(room, "%^BOLD%^BLACK%^" + pname + "'s weapon t%^RESET%^%^CYAN%^e%^BOLD%^a%^WHITE%^r%^BLACK%^s into " + ename + " with r%^RESET%^%^CYAN%^e%^BOLD%^l%^WHITE%^e%^BLACK%^nt%^RESET%^%^CYAN%^l%^BOLD%^e%^WHITE%^s%^BLACK%^s h%^RESET%^%^CYAN%^u%^BOLD%^n%^WHITE%^g%^BLACK%^er!%^RESET%^", ({ player, enemy }));
        break;
        default:
        return 0;
        break;
    }

    enemy->cause_typed_damage(enemy, enemy->return_target_limb(), damage, "divine");
    return 1;

}

void remove_prop(object ob)
{
    object player;

    ob->remove_property_value("added short", ({ "%^CYAN%^BOLD%^ [bane]%^RESET%^" }) );
    ob->remove_property("temp_hit_bonus");
    ob->remove_property("bane type");

    player = environment(ob);
    player && tell_object(player, "%^BOLD%^Your magical bane fades from your weapon.%^RESET%^");
}
