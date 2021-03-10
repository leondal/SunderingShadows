#include <std.h>
#include "../inherits/area_stuff.h"

inherit WEAPONLESS;

void create ()
{
    object ob;
    ::create ();
    set_name("starving gray wolf");
    set_id(({"wolf", "starving wolf", "gray wolf", "chsaideoozefood"}));
    set_short("%^BOLD%^%^BLACK%^A starving gray wolf%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^This large wolf has gray fur that is very long and "+
    "matted. The body of the creature is approximately four feet long and very "+
    "gaunt. There are many wounds covering most of its body, some of them look "+
    "fresher than others. The eyes of this creature are a deep and intelligent gray. They "+
    "dart about constantly, as if it is watching where it is vigorously or perhaps "+
    "it is simply searching for food.%^RESET%^");
    set_race("wolf");
    set_gender("male");
    set_body_type("quadruped");
    set_hd(16,2);
    set_overall_ac(-8);
    set_size(2);
    set_stats("intelligence",2);
    set_stats("strength",18);
    set_stats("wisdom",12);
    set_stats("dexterity",15);
    set_stats("constitution",18);
    set_stats("charisma",6);
    set_class("fighter");
    set_moving(1);
    set_speed(60);
    set_nogo(({"/d/darkwood/tabor/road/road6","/d/darkwood/yntala/rooms/forest33","/d/darkwood/yntala/rooms/forestpath"}));
    set_new_exp(16, "normal");
    set_max_level(22);
    set_alignment(3);
    set_damage(2,6);
    set_hp(186 + random(85));
    set_attacks_num(2);
    set_max_hp(query_hp());  
    set_property("full attacks",1);
    set("aggressive",19);
    add_limb("left claws","left forepaw",0,0,0);
    add_limb("right claws","right forepaw",0,0,0);
    add_limb("teeth","mouth",0,0,0);
    set_attack_limbs(({"right claws","teeth","left claws"}));
    set_base_damage_type("slashing");
    
    set_moving(1);
    set_speed(25);
    set_nogo(({OE}));    

    if(!random(8)) 
    {
        ob = new("/d/common/obj/brewing/herb_special_inherit");
        ob->set_herb_name("fur");
        ob->move(TO);
    }
}
