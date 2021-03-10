#include <std.h>
#include "common.h"

inherit UNDEADINHERIT;

//https://www.d20pfsrd.com/bestiary/monster-listings/undead/vampire/vampire-spawn
void create(){

    ::create();
    set_name("vampire");
    set_id(({"vampire spawn","vampire","undead","Vampire spawn","spawn"}));
    set_short("%^RESET%^%^BLUE%^V%^BOLD%^%^BLUE%^ampi%^RESET%^%^BLUE%^r%^BOLD%^%^BLUE%^e %^BLUE%^s%^RESET%^%^BLUE%^p%^BOLD%^%^BLUE%^a%^RESET%^%^BLUE%^w%^BOLD%^%^BLUE%^n%^RESET%^");
    set_long("%^RED%^A disfigured humanoid figure stands in front of you. It is hard to say what it has been in its former life. Its skin is gray, it is slightly crouching its lithe athletic body on its elongated limbs. It has long bat-like ears, and the face is disfigured with the large jaw that has long fangs protruding out of the mouth. Its eyes glow red with supernatural hatred and hunger.");
    set_race("human");
    set_gender("male");

    set_size(2);
    set_class("fighter");

    set_guild_level("fighter",6);
    set_level(8);
    set_hd(8,8);

    set_max_hp(random(30)+255);
    set_hp(query_max_hp());

    set_wielding_limbs(({"right hand","left hand"}));
    set_property("undead",1);
    set_property("vampire",1);
    set_body_type("human");
    set_property("full attacks",1);
    set_property("fast healing",5);

    set_property("spell damage resistance",5);
    set_property("silver resistance",5);
    set_property("electricity resistance",5);

    set_stats("strength",14);
    set_stats("dexterity",14);
    set_stats("constitution",10);
    set_stats("intelligence",12);
    set_stats("wisdom",14);
    set_stats("charisma",18);

    set_alignment(9);

    set_funcs(({"blood_drain"}));
    set_func_chance(50);
    set_property("cast and attack",1);

    add_limb("jaw",0,0,0);
    set_attack_limbs(({"right hand","left hand","jaw"}));
    set_wielding_limbs( ({"left hand","right hand"}) );

    set_base_damage_type("piercing");
    set_damage(3,6);

    add_search_path("/cmds/feats");
    add_search_path("/cmds/fighter");

    set_monster_feats(({
                "toughness",
                    "regeneration",
                    "rush",
                    "parry"
                    }));

    set_fighter_style("soldier");
    command("message in stumbles in.");
    command("message out stumbles to $D.");
}

int blood_drain(object targ)
{
    string what;
    if (!objectp(targ)) {
        return 0;
    }
    if (!objectp(TO)) {
        return 0;
    }
    if (!objectp(ETO)) {
        return 0;
    }
    if (targ->is_undead()) {
        return 0;
    }
    if (targ->query_property("garlic_scent")) {
        return 0;
    }
    what = (!random(2))?"%^BOLD%^bite":"%^BOLD%^%^BLUE%^claw";
    tell_room(ETO, "%^RED%^A vampire spawn violently " + what + "s%^RESET%^%^RED%^ " + targ->QCN + "!", targ);
    tell_object(targ, "%^RED%^You feel your life draining away as vampire spawn " + what + "s%^RESET%^%^RED%^ you " + targ->QCN + "!", targ);
    targ->cause_typed_damage(targ, targ->return_target_limb(), roll_dice(query_level(), 8), "negative energy");
    targ->cause_typed_damage(TO, "torso", -roll_dice(query_level(), 16) * 2, "negative energy");
}

void init()
{
    if(!TO->query_casting())
        if(!TO->query_property("gaseous form"))
            new("/cmds/spells/g/_gaseous_form.c")->use_spell(TO,TO,100,100,0);
    ::init();
}


int die()
{
    tell_room(ETO,"%^BLUE%^A vampire spawn turns into dust.");
    TO->remove();
    ::die();
    return 1;
}
