/*
  stormshatter.c
  
  Storm Shatter bow. This bow has a chance to
  cause aoe damage on hit.
  
  -- Tlaloc -- 11/2019
*/

inherit "/d/common/obj/lrweapon/longbow.c";

#include <std.h>
#include <daemons.h>

#define MIN_LEVEL     20
#define HIT_INTERVAL   5

//Using hit interval instead of random chance.
int hit_count;

object player;

void create()
{
    ::create();
    
    set_name("longbow");
    set_short("%^BOLD%^%^BLACK%^Sto%^RESET%^%^ORANGE%^r%^BOLD%^m%^WHITE%^s%^ORANGE%^h%^RESET%^%^ORANGE%^a%^BOLD%^%^BLACK%^t%^RESET%^%^ORANGE%^t%^BOLD%^e%^WHITE%^r%^RESET%^");
    set_long("\
This massive bow seems to be out of a single large bone from some sort of animal. The bone has "+ 
"been strenghened by sinews tanned and wrapped around it tightly. The tip of the bow has been "+
"sharpened into an almost crude spear with jagged sides. The bow almost seems to radiate power and "+
"there is a distict smell of ozone in the area. Small crude native images have been cut into the "+
"bone showing a massive storm that is destroying a village with lightning, winds and rain. The "+
"strong bowstring is made out of twisted aninal sinews, and you can only imagine what strength it "+
"takes to draw the bow.\n");

    set_obvious_short("strange longbow");
    set_id( ({ "longbow", "stormshatter", "bow", "stormshatter bow", "stormshatter longbow" }) );
   
    set_property("enchantment", 4);
    set_property("no_alter", 1);
    set_property("magic", 1);
    set_property("flrhit", 1);
    set_lrhit((:this_object(), "weapon_hit":));
    set_weapon_prof("martial");
    set_weight(6);
    
    set_item_bonus("attack bonus", 2);
    
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
    if(player->query_level() < MIN_LEVEL)
        return notify_fail("The bow rejects you as being too inexperienced.\n");
    
    return 0;
}

int weapon_hit(object target)
{
    object room,
           *attackers;
           
    int damage, max;
    
    //Should only be one environment call per function call
    //environment() is a very costly process in terms of comp lines/sec
    if(!player)
        player = environment(this_object());
    
    player && room = environment(player);
    
    //Cover all of our bases in the beginning
    if(!living(player) || !room || !living(target))
        return 0;
    
    //10% Chance to do an extra weapon hit
    if(!random(10))
    {
        damage = roll_dice(1, 6);
        tell_object(player, "%^BOLD%^%^BLACK%^Y%^RESET%^%^ORANGE%^o%^BOLD%^u%^WHITE%^r %^BLACK%^a%^RESET%^%^ORANGE%^r%^BOLD%^r%^WHITE%^o%^BLACK%^w hits with a b%^RESET%^%^ORANGE%^u%^BOLD%^r%^WHITE%^s%^BLACK%^t of e%^RESET%^%^ORANGE%^l%^BOLD%^e%^WHITE%^c%^BLACK%^t%^RESET%^%^ORANGE%^r%^BOLD%^i%^WHITE%^c%^BLACK%^i%^RESET%^%^ORANGE%^t%^BOLD%^y%^BLACK%^, frying your opponent's tissue.%^RESET%^");
        tell_room(room, sprintf("%s's arrow hits %s with a burst of electricity.", player->query_name(), target->query_name()), player);
        target && target->cause_typed_damage(target, "body", damage, "electricity");
    }
    
    //Every HIT_INTERVAL hits, we do a splash damage effect
    hit_count++;
    
    if(hit_count < HIT_INTERVAL)
        return damage;
    
    hit_count = 0;
    
    tell_object(player, "%^BOLD%^%^BLACK%^Your arrow e%^RESET%^%^ORANGE%^x%^BOLD%^p%^WHITE%^l%^BLACK%^o%^RESET%^%^ORANGE%^d%^BOLD%^e%^WHITE%^s %^BLACK%^into a s%^RESET%^%^ORANGE%^h%^BOLD%^o%^WHITE%^w%^BLACK%^er of e%^RESET%^%^ORANGE%^l%^BOLD%^e%^WHITE%^c%^BLACK%^trical d%^RESET%^%^ORANGE%^i%^BOLD%^s%^WHITE%^c%^BLACK%^harge.%^RESET%^");
    attackers = player->query_attackers();
    attackers = shuffle(attackers);
    max = min( ({ sizeof(attackers), 8 }) );
    attackers = attackers[0..max];
    
    
    foreach(object ob in attackers)
    {
        //Essential to check for existence of ob and player for each iteration.
        //ob or player might be killed during this loop due to damage or reflect shields.
        if(ob && player && !ob->reflex_save(player->query_level()))
        {
            tell_object(player, "%^YELLOW%^BOLD%^The electricity hits %^WHITE%^"+ob->query_name()+"%^YELLOW%^, causing massive burns!%^RESET%^");
            tell_room(room, "%^BOLD%^The electricity hits %^YELLOW%^"+ob->query_name()+"%^WHITE%^, causing massive burns!", player);
            damage = roll_dice(1, 10);
            ob->set_paralyzed(roll_dice(1,4) * 8, "%^BOLD%^You are shocked and can't move!%^RESET%^");
            ob->cause_typed_damage(ob, "body", damage, "electricity");
        }
    }
    
    return damage;
}
