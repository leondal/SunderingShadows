//Giant Hammer for goodly giants
//Tlaloc 8.17.21

#include <std.h>
#include <daemons.h>

#define DEITIES ({ "nimnavanon", "seija" })

inherit "/d/common/obj/weapon/giant_hammer.c";

string owner;

void create()
{
    ::create();
    set_name("hammer");
    set_id(({ "hammer", "giant hammer", "verdant hammer", "warhammer", "protector hammer" }));
    set_short(CRAYON_D->color_string("Hammer of the Verdant Protector", "green"));
    set_long(CRAYON_D->color_string("The head of this gigantic hammer is a massive quartz crystal, one end coming to a point while the other is a mess of spinters and errant shards. As if growing from the translucent stone, a small tree trunk extends down in a natural handle, its roots twisting and knotting around the crystal. The stryations in the warp and weave of the bark are echoed in the facets of the crystal above, forming strange and mystical sigls of power.", "green"));
    set_language("sylvan");
    set_property("lore difficulty", 25);
    set_property("enchantment", 4);
    set_item_bonus("constitution", 2);
    set_item_bonus("fast healing", 1);
    set_wield((: "wield_func" :));
    set_unwield((: "unwield_func" :));
    set_hit((: "hit_func" :));
    set_lore(CRAYON_D->color_string("During the awakening of Edea, the elements were once more brought into balance and a new god was born. Ashra rose to meet Edea and the two vast primordials began to battle. Ashra struck at the nascent god, corrupting a portion of her. The god split into two, the corrupt and pure portions forming into two separate gods. The two shards became the gods Seija and Khyron. While Khyron wrought the influence of chaos and destruction upon the world, Seija sought to assert balance upon nature, and began to put plans into motion to offset the great evil she saw spreading in the world. To that end, a great and powerful hammer was created, infused with the fertile power of nature. This hammer has been set upon the world, awaiting a champion worthy of wielding its verdant power. This champion, who will be known as the Verdant Champion, will once more return balance to nature and protect the wilds of the world.", "light green")); 
}

string set_owner(string str)
{
    owner = str;
    return owner;
}

void init()
{
    ::init();
    
    if(!strlen(owner))
        set_owner(this_player()->query_name());
}

int wield_func()
{
    if(this_player()->query_name() != owner)
    {
        write("Vines lash out from around the hammer, preventing you from wielding it!");
        return 0;
    }
    
    if(member_array(this_player()->query_diety(), DEITIES) < 0)
    {
        write("The hammer rejects your touch and you sense you are not of the right faith.");
        return 0;
    }
    
    write(CRAYON_D->color_string("You grip the haft of the hammer and vines grow from around it, gripping your hands. You feel verdant energy flowing and pulsing through you, and you feel heartier.", "green"));
    
    return 1;
}

int unwield_func()
{
    write("You loosen your grip on the haft of the hammer and the vines retract, allowing you to release it.");
    
    return 1;
}

int hit_func(object ob)
{
    object wielder, room;
    int damage;
    
    wielder = environment(this_object());
    
    if(!userp(wielder) || !ob)
        return 0;
    
    room = environment(wielder);
    
    if(room != environment(ob))
        return 0;
    
    if(random(10))
        return 0;
    
    tell_object(ob, CRAYON_D->color_string("The vines encircling the hammer harden into deadly spikes as you strike at your foe!", "light green"));
    tell_room(room, "The vines encircling " + wielder->QCN + "'s hammer harden into spikes as " + wielder->query_pronoun() + " strikes at " + wielder->query_possessive() + " foes!");
    
    damage = roll_dice(1, 6) + BONUS_D->query_stat_bonus(wielder, "strength") + query_property("enchantment");
    
    return damage;
}
   
    
        