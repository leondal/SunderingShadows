/*
  duelist.c
  
  Rapier drop from the Nightwalker Boss.
  
  -- Tlaloc --
*/

#include <std.h>
#include <daemons.h>

#define HIT_INTERVAL 4

inherit "/d/common/obj/weapon/rapier.c";

object owner;
int hit_count;

string color(string str)
{
    return CRAYON_D->color_string(str, "whisper");
}

void create()
{
    ::create();
    
    set_name("rapier");
    set_id( ({ "rapier", "blade", "blade of the master duelist", "duelist blade", "sword" }) );
    set_short("Blade of the Master Duelist");
    set_obvious_short("pale blue blade");
    set_long("This is a stiff-bladed rapier made of a strange pale blue material. It is roughly 48 inches long, with a long triangular blade that tapers to a fine point. It is irridescent, and light can be seen through the blade and pommel. It has a finely wrought swept hilt made of finely wrought silver. The handle is also wrapped in silver cord with the utmost care. It is rather light for a rapier and allows for much more ease of maneuver than would normally be possible.");
    set_value(100000);
    set_property("no_curse", 1);
    set_property("no steal", 1);
    set_property("lore difficulty", 40);
    set_property("id difficulty", 40);
    set_property("able to cast", 1);
    set_property("enchantment", 7);
    
    set_item_bonus("attack bonus", 7);
    set_item_bonus("damage bonus", 7);
    
    set_wield( (: this_object(), "wield_func" :) );
    set_unwield( (: this_object(), "unwield_func" :) );
    set_hit( (: this_object(), "hit_func" :) );
}

void init()
{
    object holder;
    
    ::init();
    
    holder = environment(this_object());
    
    if(!holder || !userp(holder))
        return;
    
    hit_count = 0;
    
    if(!owner)
    {          
        owner = holder;
        tell_object(holder, color("As you pick up the blade, you feel it hum in harmony with your soul."));
    }
}

int wield_func()
{
    if(environment(this_object()) != owner)
    {
        tell_object(environment(this_object()), "The blade rejects your touch!");
        return 0;
    }
    
    tell_object(owner, color("You feel the blade hum as if ready for battle!"));
    tell_room(environment(owner), color(owner->QCN + "'s blade begins to hum with energy!"), owner);
    return 1;
}

int unwield_func()
{
    owner && tell_object(owner, "%^CYAN%^You blade stop humming as you release it.%^RESET%^");
    return 1;
}

int hit_func(object target)
{
    int dam;
    
    if(!owner || !target)
        return 0;
    
    //Weapon only procs for duelist fighting style
    if(!owner->validate_combat_stance("one hander"))
        return 0;
    
    hit_count++;
    
    if(hit_count < HIT_INTERVAL)
        return 0;
    
    hit_count = 0;
    dam = roll_dice(12, 10) + 40;
    
    tell_object(owner, color("Your blade seems to explode as it tears into " + target->QCN + "!"));
    tell_object(target, color(owner->QCN + "'s blade seems to explode as it tears into you!"));
    tell_room(environment(owner), color(owner->QCN + "'s blade seems to explode as it tears into " + target->QCN + "!"));
    target->cause_typed_damage(target, target->return_target_limb(), dam, "force");
    
    if(target && !random(5))
    {
        tell_object(owner, color("You disengage and follow up with a stunning coupe!"));
        tell_room(environment(owner), color(owner->QCN + " disengages and follows up with a stunning coupe!"));
        owner->execute_attack();
        return roll_dice(3, 6);
    }
    
    return 0;
}
    
    
    
    