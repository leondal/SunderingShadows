#include <std.h>
inherit MONSTER;

void create() {
    int level;
    object ob;
    ::create();
    set_name("ogre guard");
    set_id(({"guard","ogre guard","muuldaan guard"}));
    set_short("ogre guard");
    set_long("This massive creature fills up a sizable portion of the cavern, and has a rather stupid, "
"glazed look upon its face.  It has a tough, warty gray hide, sharp talons on each hand, and dull purple "
"eyes.  It carries no armor, but is lugging around a huge hammer, which it looks quite hopeful to make use "
"of.");
    set_body_type("human");
    set_race("ogre");
    set_gender("male");
    set_class("fighter");
    level = random(5)+12;
    set_guild_level("fighter",level);
    set_hd(level,10);
    set_exp(300);
    set_max_hp(150+random(75));
    set_hp(query_max_hp());
    set_overall_ac(-1);
    set_property("swarm",1);
    set_alignment(9);
    set_size(3);
    set_stats("strength", random(4)+15);
    set_stats("constitution", random(9)+10);
    set_stats("wisdom", random(8)+9);
    set_stats("charisma", random(5)+9);
    set_stats("intelligence", random(7)+9);
    set_stats("dexterity", random(8)+11);
    set_wielding_limbs( ({ "right hand", "left hand" }) );
    new("/d/common/obj/weapon/giant_hammer")->move(TO);
    force_me("wield hammer");
    set_spoken("undercommon");
}
