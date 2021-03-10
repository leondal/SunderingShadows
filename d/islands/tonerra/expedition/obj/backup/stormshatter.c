/*
  stormshatter.c
  
  Storm Shatter bow. This bow has a chance to
  cause aoe damage on hit.
  
  -- Tlaloc -- 11/2019
*/

inherit "/d/common/obj/lrweapon/longbow.c";

#include <std.h>
#include <daemons.h>

#define MIN_LEVEL     40
#define HIT_INTERVAL   5

//Using hit interval instead of random chance.
int hit_count;

object player;

void create()
{
    ::create();
    
    set_name("longbow");
    set_short("%^BOLD%^%^BLACK%^Sto%^RESET%^%^ORANGE%^r%^BOLD%^m%^WHITE%^s%^ORANGE%^h%^RESET%^%^ORANGE%^a%^BOLD%^%^BLACK%^t%^RESET%^%^ORANGE%^t%^BOLD%^e%^WHITE%^r %^RESET%^");
    set_obvious_short("strange longbow");
    set_id( ({ "longbow", "stormshatter", "bow", "stormshatter bow", "stormshatter longbow" }) );
   
    set_property("enchantment", 6);
    set_property("no_alter", 1);
    set_property("magic", 1);
    set_lrhit((:this_object(), "weapon_hit":));
    set_weapon_prof("martial");
    
    set_item_bonus("attack bonus", 4);
    
    hit_count = 0;
    
}

void init()
{
    ::init();
    add_action("do_wield","wield");
    
    player = this_player();
}

int do_wield()
{
    if(player->query_level() < 40)
        return notify_fail("The bow rejects you as being too inexperienced.\n");
    
    return 0;
}

int weapon_hit(object target)
{
    object room,
           *attackers;
           
    int damage;
    
    //Should only be one environment call per function call
    //environment() is a very costly process in terms of comp lines/sec
    if(!player)
        player = environment(this_object());
    player && room = environment(player);
    
    //Cover all of our bases in the beginning
    if(!player || !living(player) || !room || !target || !living(target))
        return 0;
    
    //10% Chance to do an extra weapon hit
    if(!random(10))
    {
        damage = roll_dice(1, 4);
        tell_object(player, "Your arrow hits with a burst of electricity, frying your opponent's tissue.");
        tell_room(room, sprintf("%s's arrow hits %s with a burst of electricity.", player->query_name()), player);
        target && target->do_damage("chest", damage);
    }
    
    //Every HIT_INTERVAL hits, we do a splash damage effect
    hit_count++;
    
    if(hit_count < HIT_INTERVAL)
        return 0;
    
    hit_count = 0;
    
    tell_object(player, "%^BOLD%^Your arrow explodes into a shower of electrical discharge.%^RESET%^");
    attackers = player->query_attackers();
    
    foreach(object ob in attackers)
    {
        //Essential to check for existence of ob and player for each iteration.
        //ob or player might be killed during this loop due to damage or reflect shields.
        if(ob && player)
        {
            tell_object(player, sprintf("The electricity hits %s, causing massive burns!", ob->query_name()));
            tell_room(room, sprintf("The electricity hits %s, causing massive burns!", ob->query_name()), player);
            damage = roll_dice(2, 10);
            ob->do_damage("torso", damage);
        }
    }
    
    return damage;
}
