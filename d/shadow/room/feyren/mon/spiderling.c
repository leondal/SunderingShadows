#include <std.h>
#include <daemons.h>
#include "../inherits/area_stuff.h"
inherit WEAPONLESS;

void create() 
{
    object ob;
    ::create();
    set_name("spiderling");
    set_id(({"spider","spiderling"}));
    set_short("%^BOLD%^%^BLACK%^Large spiderling%^RESET%^");

    set_long("%^BOLD%^%^GREEN%^This spider, although young, is perhaps "+
    "two feet in diameter. Its eight legs are covered in a thick, coarse "+
    "dark fuzz that extends to the rest of its body but is not quite as thick. "+
    "Most of its body is a very dark, almost dull black color. "+
    "There are streaks of a grotesque green visible on parts of its "+
    "body in various places. The eyes of this spider are a deep, "+
    "dull red. Its mandible opens further than normal and "+
    "is a deep greenish with specks of black throughout it.%^RESET%^"); 

    set_gender("female");
    set_race("arachnid");
    set_body_type("arachnid");
    set_alignment(5);
    set_size(2);
    set_hd(10,5);
    set("aggressive", 25);
    set_stats("strength",15);
    set_stats("dexterity",15);
    set_hp(85 + random(15));
    set_max_hp(query_hp());
    set_new_exp(10, "normal");
    set_attacks_num(2);
    set_base_damage_type("piercing");
    set_damage(2,5);
	//set_moving(1);
	//set_speed(45);
	//need to fix poisons so that they work 
	//like we were playing D&D - Saide
    set_property("natural poisoner", 1);
    set_property("natural poison", "medium spider venom");
    set_property("poison chance", 2);
    //set_nogo(({FFCR"1",OA}));
    set_funcs(({"poison_bite"}));
    set_func_chance(25); 
    set_base_damage_type("piercing");
    if(!random(20)) 
    {
        ob = new("/d/common/obj/brewing/herb_special_inherit");
        ob->set_herb_name("spiderweb");
        ob->move(TO);
    }
}

void poison_bite(object targ)
{
    string limb;
    if(!objectp(TO)) return;
    if(!objectp(targ)) return;

    limb = targ->return_target_limb();

    tell_object(targ, TOQCN+"%^BOLD%^%^GREEN%^"+
    " sinks its fangs deep into your "+limb+", "+
    "pumping poison into the wound!%^RESET%^");

    tell_room(ETO, TOQCN+"%^BOLD%^%^GREEN%^ "+
    "sinks its fangs deep into "+targ->QCN+
    "%^BOLD%^%^GREEN%^'s "+limb+"!%^RESET%^", targ);

    tell_object(targ, "%^BOLD%^%^GREEN%^"+
    "You feel woozy as the poison begins to "+
    "take effect!%^RESET%^");

    tell_room(ETO, targ->QCN+"%^BOLD%^%^GREEN%^"+
    " stumbles around crazily for a moment as "+
    "the "+TOQCN+"%^BOLD%^%^GREEN%^ releases "+targ->QP+" "+
    limb+"!%^RESET%^", targ);

    POISON_D->ApplyPoison(targ, "medium spider venom", TO, "injury");
    return;
}
