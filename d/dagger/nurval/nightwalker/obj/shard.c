/*
  shard.c
  
  Dagger weapon dropped by the Nightwalker Boss.
  
  -- Tlaloc --
*/

#include <std.h>
#include <daemons.h>

//Hit interval instead of proc chance. Procs every 5 hits.
#define HIT_INTERVAL 5

inherit "/d/common/obj/weapon/dagger.c";

object owner;
int hit_count;

string color(string str)
{
    return CRAYON_D->color_string(str, "lightning yellow");
}

void create()
{
    ::create();
    
    set_name("shard");
    set_id( ({ "shard", "dagger", "shard of the deliverer", "deliverer shard" }) );
    set_short("%^BOLD%^%^WHITE%^S%^CYAN%^h%^RESET%^%^CYAN%^a%^BOLD%^%^WHITE%^rd of the D%^CYAN%^e%^RESET%^%^CYAN%^l%^BOLD%^%^WHITE%^iv%^CYAN%^e%^RESET%^%^CYAN%^r%^BOLD%^%^WHITE%^er%^RESET%^");
    set_obvious_short(color("glowing encased-shard dagger"));
    set_long("This weapon is composed of shard of glowing material encased in the shell of a finely-wrought silver dagger.");
    set_lore("When Kyra, the stalwart paladin of Jarmila, was sacrificed one night in a foul ritual to the dark primordial Ashra, her soul was condemned to the Nightmare Realm to suffer for eternity. In a strange turn of fate, a group of heroes of the light banded together to save Kyra's soul from her torment, while simultaneously locking Ashra away from the world. Their efforts resulted in an astonishing success, achieving both of their aims. Kyra's soul, freed from the depths of the Nightmare, transcended beyond the wall to be with Jarmila once more. Her last act before this transcendence was to leave behind a shard of her essence, laying in wait for a hero, strong enough to vanquish the world's greatest evils, to bond with and assist in their holy mission.");
    set_value(100000);
    set_property("no_curse", 1);
    set_property("no steal", 1);
    set_property("lore difficulty", 40);
    set_property("id difficulty", 40);
    set_property("able to cast", 1);
    set_property("enchantment", 7);
    
    set_item_bonus("attack bonus", 7);
    set_item_bonus("damage bonus", 7);
    set_item_bonus("negative energy resistance", 25);
    
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
        if((holder->query_true_align() != 1 &&
           holder->query_true_align() != 4 &&
           holder->query_true_align() != 7) ||
           holder->query_character_level() < 40)
        {
            tell_object(holder, "The glowing shard burns your hand and you drop it!");
            this_object()->move(environment(holder));
            return;
        }      
               
        owner = holder;
        tell_object(holder, color("As you lift the glowing dagger, you feel it connect with the goodness in your soul."));
    }
}

int hit_func(object target)
{
    int dam;
    
    if(!owner || !target)
        return 0;
    
    hit_count++;
    
    if(hit_count < HIT_INTERVAL)
        return 0;
    
    //This blade adds a sneak attack
    if(!target->is_vulnerable_to(owner))
        return 0;
    
    hit_count = 0;
    
    dam = roll_dice(owner->query_character_level() / 2, 6);
    
    if(FEATS_D->usable_feat(target, "mighty resilience"))
        dam = 0;

    //Armor bond sneak attack resistance
    if(target->query_property("fortification 75"))
        dam /= 4;
    else if(target->query_property("fortification 50"))
        dam /= 2;
    else if(target->query_property("fortification 25"))
        dam = (dam * 3) / 4;
    if(FEATS_D->usable_feat(target, "undead graft"))
        dam /= 2;

    //Barbarians/Thieves with danger sense gain resistance to sneak attacks
    if(FEATS_D->usable_feat(target, "danger sense") && target->query_level() + 4 > owner->query_level())
        dam /= 2;

    if(owner->query_blind() || owner->light_blind())
    {
        if(FEATS_D->usable_feat(owner, "blindfight"))
            dam /= 2;
        else
            dam = 0;
    }
    
    if(dam)
    {
        tell_object(owner, "%^WHITE%^%^BOLD%^You hit " + target->QCN + ".%^YELLOW%^[%^CYAN%^Sneak%^YELLOW%^]%^RESET%^");
        tell_object(target, "%^WHITE%^%^BOLD%^" + owner->QCN + " hits you.%^YELLOW%^[%^CYAN%^Sneak%^YELLOW%^]%^RESET%^");
        tell_room(envirnonment(owner), "%^WHITE%^%^BOLD%^" + owner->QCN + " hits " + target->QCN + ".%^YELLOW%^[%^CYAN%^Sneak%^YELLOW%^]%^RESET%^");
        target->cause_typed_damage(target, target->return_target_limb(), dam, "divine");
    }
    
    return 0;
}

int wield_func()
{
    if(environment(this_object()) != owner)
    {
        tell_object(environment(this_object()), "The holy shard rejects your touch!");
        return 0;
    }
    
    tell_object(owner, color("You feel the holy warmth of the shard seep into your skin!"));
    tell_room(environment(owner), color(owner->QCN + "'s dagger glows with divine energy!"), owner);
    return 1;
}

int unwield_func()
{
    owner && tell_object(owner, "%^CYAN%^You feel the warmth of the shard disappate as you release it.");
    return 1;
} 