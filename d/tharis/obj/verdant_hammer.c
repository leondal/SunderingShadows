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
    set_property("enchantment", 5);
    set_wield((: "wield_func" :));
    set_unwield((: "unwield_func" :));   
    set_lore(CRAYON_D->color_string("Not long ago, during the re-awakening of the great and ancient primordials, a new god was formed from the vestige of the dying god, Ryorik. As the new god was forming, Ashra stuck the being, corrupting part of its essence. The god split into two shards. The two shards became the gods Seija and Khyron. While Khyron wrought the influence of chaos and destruction upon the world, Seija sought to assert balance upon nature, and began to put plans into motion to offset the great evil she saw spreading in the world. To that end, a great and powerful hammer was created, infused with the fertile power of nature. This hammer has been set upon the world, awaiting a champion worthy of wielding its verdant power. This champion, who will be known as the Verdant Champion, will once more return balance to nature and protect the wilds of the world.", "light green")); 
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
    
        