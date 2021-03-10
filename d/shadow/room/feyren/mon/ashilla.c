#include <std.h>
#include <daemons.h>
#include "../inherits/area_stuff.h"

inherit MONSTER;

void create() 
{
    object ob;
    ::create();
	
    set_name("ashilla");
    set_id(({ "ashilla", "goblin", "sorceress", 
    "ashilla the mad" }));

    set_short("%^BOLD%^%^GREEN%^A%^BOLD%^%^YELLOW%^"+
    "sh%^BOLD%^%^GREEN%^i%^BOLD%^%^YELLOW%^ll"+
    "%^BOLD%^%^GREEN%^a%^BOLD%^%^YELLOW%^, The "+
    "Mad%^RESET%^");

    set("aggressive",25);

    set_long("%^BOLD%^%^GREEN%^This hunched over goblin "+
    "stands less than four feet tall. She looks very old and "+
    "her skin is wrinkled to the point of deformation. Her "+
    "hair is almost black, very stringy, and "+
    "looks as if most of it has fallen out. "+
    "Her eyes are a %^BOLD%^%^BLUE%^deep blue%^BOLD%^"+
    "%^GREEN%^ and portray an exceptional intellect "+
    "that seems clouded by an obvious madness. "+
    "She is covered in filth, some of it her own, and "+
    "scabbed over wounds which she picks at "+
    "regularly. She emits a terrible odor "+
    "that almost causes you to gag. She seems so "+
    "preoccupied within her own mind that "+
    "none of this even seems to matter to her."+
    "%^RESET%^");

    set_hd(16,3);
    set_level(16);
    set_class("mage");
    set_guild_level("mage",16);
    set_mlevel("mage", 16);

    set_wielding_limbs(({"right hand","left hand"}));
    set_body_type("humanoid");
    set_alignment(9);

    set_stats("intelligence",20);
    set_stats("wisdom",8);
    set_stats("strength",15);
    set_stats("charisma",3);
    set_stats("dexterity",14);
    set_stats("constitution",13);
    set_race("goblin");
    set_gender("female");
    set_overall_ac(-5);
    set_new_exp(15,"boss");
    set_max_hp(300 + random(75));
    set_hp(query_max_hp());
   
    add_money("gold",random(55)+255);

    set_property("full attacks",1);

    set_funcs(({"spider_me"}));
    set_func_chance(55);

    set_spell_chance(65);
    set_spells(({"scorcher", "acid arrow", "lightning bolt", 
    "fireball", "cone of cold", "hideous laughter", "fire storm"}));
    add_search_path("/cmds/spells");

    switch(random(10)) 
    {
        case 0..2:
            ob = new("/d/deku/armours/ring_p");
            ob->set_property("enchantment", 1);
            ob->move(TO);
            break;
        case 3..5:
            new(FFOB+"robe")->move(TO);
            break;
        case 6..8:
            ob = new(FFOB+"lightstone");
            if(!random(2)) ob->make_greater();
            ob->move(TO);
            ob = new("/d/deku/armours/ring_p");
            if(!random(2)) ob->set_property("enchantment", 1);
            ob->move(TO);
            break;
        case 9: 
            ob = new(FFOB+"spider_bane");
            ob->move(TO); 
            break;
    }
    if(!present("staff", TO)) 
    {
        ob = new("/d/common/obj/weapon/mstaff");
        ob->set_property("enchantment", 2);
        ob->move(TO);
    }
    command("wield staff");
    command("wear ring");
    command("wear robe");
}

void spider_me(object targ)
{
    string limb;
    object spider_mark;
    if(!objectp(TO)) return;
    if(!objectp(targ)) return;
    if(!objectp(ETO)) return;
	
    tell_room(ETO, TO->query_short() + " %^BOLD%^"+
    "%^GREEN%^cackles insanely and %^BOLD%^%^RED%^S"+
    "%^BOLD%^%^YELLOW%^C%^BOLD%^%^RED%^R%^BOLD%^"+
    "%^YELLOW%^E%^BOLD%^%^RED%^A%^BOLD%^%^YELLOW%^"+
    "M%^BOLD%^%^RED%^S%^BOLD%^%^GREEN%^ "+
    "I place a %^BOLD%^%^BLACK%^CURSE%^BOLD%^"+
    "%^GREEN%^ upon you "+targ->QCN+"!%^RESET%^");

    tell_object(targ, "%^BOLD%^%^GREEN%^You feel "+
    "a strange sensation invade your "+
    "mind for a brief instant.... it leaves "+
    "you feeling %^BOLD%^%^RED%^CURSED"+
    "%^BOLD%^%^GREEN%^!%^RESET%^");

    if(objectp(spider_mark = present("spider_curse_ob", targ))) 
    {
        spider_mark->increase_potency(1);
        return;
    }
    spider_mark = new(FFOB+"spider_ob");
    spider_mark->move(targ);
    return;
}