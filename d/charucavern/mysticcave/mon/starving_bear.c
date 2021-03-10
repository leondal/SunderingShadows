#include <std.h>
#include "../inherits/area_stuff.h"
inherit WEAPONLESS;
void create ()
{
    object ob;
    ::create ();
    set_name("starving brown bear");
    set_id(({"bear", "brown bear", "starving bear", "shaggy bear", "starving shaggy bear", "chsaideoozefood"}));
    set_short("%^RESET%^%^ORANGE%^A large starving brown bear%^RESET%^");
    set_long("%^RESET%^%^ORANGE%^This is a large brown bear with long, shaggy fur. His body is quite gaunt and you can instantly "+
    "tell that this creature has been starved nearly to death. The muscles that once rippled through his body have vastly "+
    "weakened. He searches about constantly, looking for something to eat.%^RESET%^");
    set_race("bear");
    set_gender("male");
    set_body_type("quadruped");
    set_hd(17,2);
    set_overall_ac(-8);
    set_size(3);
    set_stats("intelligence",2);
    set_stats("strength",18);
    set_stats("wisdom",12);
    set_stats("dexterity",13);
    set_stats("constitution",18);
    set_stats("charisma",6);
    set_class("fighter");
    set_moving(1);
    set_speed(25);
    set_nogo(({OE}));
    set_new_exp(18, "normal");
    set_max_level(22);
    set_alignment(5);
    set_damage(3,4);
    set_hp(175 + random(100));
    set_attacks_num(3);
    set_max_hp(query_hp());  
    set_property("full attacks",1);
    set("aggressive","aggfunc");
    add_limb("claws","left forepaw",0,0,0);
    set_attack_limbs(({"claws"}));
    set_base_damage_type("slashing");
    set_achats(2, ({"%^BOLD%^%^RED%^The bear roars hungrily at you!%^RESET%^","%^BOLD%^%^RED%^The bear swipes at you again!%^RESET%^."}) );
    if(!random(4)) 
    {
        ob = new("/d/common/obj/brewing/herb_special_inherit");
        ob->set_herb_name("fur");
        ob->move(TO);
    }
}
int aggfunc() 
{
    command("emote roars hungrily!");
    if(!TP->query_invis())
    {
        command("kill "+TPQN);
    }
}
