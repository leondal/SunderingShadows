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
    set_short("Shard of the Deliverer");
    set_obvious_short("glowing encased-shard dagger");
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

