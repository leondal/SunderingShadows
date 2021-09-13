/*
  indorak.c
  
  Scythe weapon dropped by the Nightwalker Boss.
  
  -- Tlaloc --
*/

#include <std.h>
#include <daemons.h>

#define HIT_INTERVAL 5

inherit "/d/common/obj/weapon/scythe.c";

object owner;
int hit_count;

void create()
{
    ::create();
    
    set_name("scythe");
    set_id( ({ "indorak", "scythe", "chill of the grave", "indorak, the chill of the grave" }) );
    set_short("Indorak, the Chill of the Grave");
    set_obvious_short("A chill-wrapped scythe");
    set_long("This is a large scythe, with a curved haft made of deep ebony wood. The blade of the scythe is long and jagged, with a bluish metal blade encased in a rime of ice. The entire weapon gives off the chill of death and icicles are formed, seeming to drip and solidify from almost the entire length of the weapon. There is a cold mist that seems to be wrapped around the scythe and a palpable aura of cold can be felt, even from 10 feet away.");
    set_lore("Indorak was made in the aftermath of the ritual which summoned the Nightwalker to this world from the Plane of Shadows. It is said that after the crafting of the ritual summoning blade, there were additional unused souls left over. The supplicants of Nilith took these unfortunate souls and formed a blade with a strong connection of the grave, that would be worthy of Nilith's champion in this world. A scythe was made and filled with the unfortunate souls, and permanently bound to the Plane of Shadows. The weapon became known as Indorak, the Chill of the Grave, and it's mere presence almost seems to suck the heat and life energy from those around it. It is said that only a being enconsed in the energies of the Shadow Plane can effectively wield this weapon.");
    set_value(100000);
    set_property("no_curse", 1);
    set_property("no steal", 1);
    set_property("lore difficulty", 40);
    set_property("id difficulty", 40);
    set_property("able to cast", 1);
    set_property("enchantment", 7);
    
    set_item_bonus("negative energy resistance", -25);
    
    set_wield( (: this_object(), "wield_func" :) );
    set_unwield( (: this_object(), "unwield_func" :) );
    set_hit( (: this_object(), "hit_func" :) );
    
    set_heart_beat(1);
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
        if((!holder->is_undead() &&
        !holder->is_shade()) ||
        holder->query_character_level() < 40)
        {
            tell_object(holder, "The icy scythe rejects your grasp, slipping from your hand!");
            this_object()->move(environment(holder));
            return;
        }      
               
        owner = holder;
        tell_object(holder, "As you lift the icy scythe for the first time, you feel it's power seep into your very soul and you become one with the mighty weapon.");
    }
}

void heart_beat()
{
    object *enemies;
    int damage_done;
    
    if(!owner || !living(owner))
        return;
    
    enemies = owner->query_attackers();
    damage_done = 0;
    
    if(sizeof(enemies) && !random(5))
    {
        tell_object(owner, "The chill aura of the scythe saps the heat from your enemies!");
        
        foreach(object ob in enemies)
        {
            tell_object(ob, "The chill aura of the scythe saps the heat from you!");
            damage_done += ob->cause_typed_damage(ob, ob->return_target_limb(), roll_dice(6, 10) + 10, "cold");
        }
        
        if(damage_done)
        {
            tell_object(owner, "The stolen heat from the scythe restores some of your wounds.");
            owner->cause_typed_damage(owner, "torso", damage_done, "negative energy");
        }
    }
}


            
        
    
    
    
    
        