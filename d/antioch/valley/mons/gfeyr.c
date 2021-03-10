//updating the old files to use the new exp functions for standardized
//exp values. ~Circe~ 2/4/13

#include <std.h>
#include "/d/antioch/valley/valley.h"
inherit WEAPONLESS;

void create()
{
    ::create();
    set_name("great feyr");
    set_id(({ "great feyr", "monster", "feyr","aberration" }));
    set_short("A terrible great feyr");
    set_long(
        "The great feyr is one of the most disgusting creatures" +
        " in existance. Created from the remnants of nightmares it" +
        " sends a shiver of unease down your spine. The beast is" +
        " hunched over and its hide looks like the surface of a" +
        " human brain. The hide varies in color almost like some" +
        " twisted rainbow, running from one ghastly color to the" +
        " next. Two large tentacles act as legs with several" +
        " other smaller tentacles acting as limbs. Enormous jaws" +
        " line its underbelly and five golden eyes stare at you."
        );
    set_race("feyr");
    set_gender("male");
    set_body_type("snake");
    set_hd(30, 5);
    set_max_level(30);
    set_size(2);
    add_limb("left tentacle leg", "torso", 0, 0, 0);
    add_limb("right tentacle leg", "torso", 0, 0, 0);
    add_limb("right tentacle", "torso", 0, 0, 0);
    add_limb("left tentacle", "torso", 0, 0, 0);
    add_limb("left jaws", "mouth", 0, 0, 0);
    add_limb("right jaws", "mouth", 0, 0, 0);
    add_limb("center jaws", "mouth", 0, 0, 0);
    add_limb("lower jaws", "mouth", 0, 0, 0);
    set_attack_limbs(({ "left jaws", "right jaws", "center jaws", "lower jaws" }));
    set_attacks_num(4);
    set_base_damage_type("piercing");
    set_property("no charge", 1);
    set_property("no bows", 1);
    set_damage(2, 6);
//	set_exp(18000);
    set_new_exp(28, "normal");
    set_overall_ac(-6);
    set_max_hp(random(100) + 400);
    set_hp(query_max_hp());
    set_level(30);
    set_class("fighter");
    set_class("cleric");
    set_mlevel("cleric", 20);
    set_mlevel("fighter", 30);
    set_guild_level("cleric", 20);
    set_guild_level("fighter", 30);
    add_search_path("/cmds/priest"); //Didn't have search path set, wasn't able to cast - Octothorpe 4/20/10
    set_mob_magic_resistance("average");
    set_property("no paralyze", 1);
    set_property("no dominate", 1);
    /*set_funcs(({"fear"}));
       set_func_chance(10);
       Looks like the mob was probably unfinished - Octothorpe 4/20/10*/
    set_spells(({
        "fear"
    }));
    set_spell_chance(20);
    set("aggressive", 25);
    set_property("swarm", 1);
}

void die(object ob)
{
    if (!random(3)) {
        tell_room(ETO, "%^BOLD%^%^CYAN%^As the life is drained from" +
                  " the Great Feyr, a light blue mist rises from its body.\n\n" +
                  "%^RESET%^%^MAGENTA%^A ghostly figure intones%^RESET%^:  Thank you" +
                  " for freeing me, friends, I hope the gift I have left you" +
                  " will be enough of a reward.\n\n" +
                  "%^BOLD%^%^CYAN%^The mist rises up into the air and disappears.\n");
        new(OBJ + "shining_sword")->move(TO);
    }
    ::die(ob);
}
