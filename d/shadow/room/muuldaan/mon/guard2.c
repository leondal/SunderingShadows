#include <std.h>
inherit MONSTER;

void create() {
    int level;
    object ob;
    ::create();
    set_name("hobgoblin guard");
    set_id(({"guard","hobgoblin guard","muuldaan guard"}));
    set_short("hobgoblin guard");
    set_long("This fierce-looking creature is a hobgoblin, with hairy, dark red-brown skin and yellow eyes.  "
"Its mouth is full of wickedly sharp fangs, and its nose is a dull red colour.  It looks rather bored and "
"hungry, and would probably welcome any chance for a fight.");
    set_body_type("human");
    set_race("hobgoblin");
    set_gender("male");
    set_class("fighter");
    level = random(5)+10;
    set_guild_level("fighter",level);
    set_hd(level,10);
    set_exp(200);
    set_max_hp(120+random(75));
    set_hp(query_max_hp());
    set_overall_ac(1);
    set_property("swarm",1);
    set_alignment(9);
    set_size(2);
    set_stats("strength", random(4)+12);
    set_stats("constitution", random(9)+8);
    set_stats("wisdom", random(8)+9);
    set_stats("charisma", random(5)+9);
    set_stats("intelligence", random(7)+9);
    set_stats("dexterity", random(8)+11);
    set_wielding_limbs( ({ "right hand", "left hand" }) );
    new("/d/common/obj/weapon/battle_axe")->move(TO);
    force_me("wield axe in right hand");
    new("/d/common/obj/weapon/spear_sm")->move(TO);
    force_me("wield spear in left hand");
    new("/d/common/obj/armour/hide")->move(TO);
    force_me("wear hide");
    set_funcs(({"flashit"}));
    set_func_chance(20);
    set_spoken("undercommon");
}

void flashit(object target) {
   force_me("flash "+target->query_name());
}
