#include <std.h>
#include "../inherits/area_stuff.h"
inherit WEAPONLESS;

void create()
{
    object ob;
    ::create();
    set_name("hyena");
    set_short("ugly looking and starving dog");
    set_id(({"monster","hyena","dog","ugly dog","ugly looking dog", "starving dog", "starving hyena", "chsaideoozefood"}));
    set_long(
    "The hyena is an incredibly ugly specimen. It looks similar to a wild"+
    " dog, but its face is flatter and its coloring is a mottled"+
    " %^ORANGE%^brownish-yellow%^CYAN%^, with black around the ears, face, and paws. It has"+
    " a very stupid look to it as well, with its %^BOLD%^%^MAGENTA%^tongue%^RESET%^%^CYAN%^ usually hanging out"+
    " of its mouth. This particular hyena looks as if it is starving "+
    "and may not survive much longer.");
    
    set_gender("male");
    set_race("hyena");
    set_body_type("quadruped");
    set_alignment(6);
    set_size(1);
    set("aggressive",40);
    set_property("swarm",1);
    set_hd(15,5);
    
      
    set_stats("strength", 16);
    set_stats("intelligence", 1);
    set_stats("wisdom", 1);
    set_stats("constitution", 6);
    set_stats("dexterity", 18);
    set_stats("charisma", 6);
    
    set_moving(1);
    set_speed(25);
    set_nogo(({OE}));
    
    set_hp(155 + random(35));
    set_new_exp(15,"normal");
    set_overall_ac(-1);
    add_limb("right claw","right forepaw",0,0,0);
    add_limb("left claw","left forepaw",0,0,0);
    add_limb("mouth","head",0,0,0);
    set_damage(2,5);
    set_attacks_num(2);
    set_base_damage_type("slashing");
    set_attack_limbs(({"right claw","left claw","mouth"}));
    set_hit_funcs((["mouth" : (:TO,"bite":)]));
    set_emotes(2,({
    "The hyena laughs insanely.",
    "The hyena drools as it looks at you.",
    "The hyena sniffs the air.",
    "The hyena paws the ground.",
    }),0);
    set_max_level(20);
    if(!random(15)) 
    {
        ob = new("/d/common/obj/brewing/herb_special_inherit");
        ob->set_herb_name("fur");
        ob->move(TO);
    }
}

int bite(object targ)
{
    if(!random(3)) 
    {
        tell_object(targ,"The hyena bites you viciously, letting blood flow.");
        return random(8)+8;
    }
    return 1;
}
