#include <spell.h>
#include <daemons.h>
#include <magic.h>
inherit SPELL;

void dest_effect();

void create() {
    ::create();
    set_spell_name("thicken skin");
    set_spell_level(([ "psion" : 2, "psywarrior" : 2 ]));
    set_discipline("egoist");
    set_bonus_type("natural armor");
    set_spell_sphere("psychometabolism");
    set_syntax("cast CLASS thicken skin");
    set_description("An egoist who chooses can focus his power to thicken his skin, granting him extra protection in combat. This power works much like inertial armor, but unlike other armor abilities, it can be used with inertial armor to grant an additional bonus. This spell will not work while you're wearing armour.");
    set_verbal_comp();
    set_somatic_comp();
    set_property("keywords", ({ "defensive", "targeted", "personal" }));
    set_helpful_spell(1);
}

void spell_effect(int prof) {

    if (!target)
        target=caster;
    /*
    if (target->query_property("add_armor")) {
        tell_object(caster,"You cannot be protected by this power and "+
           "another armor effect.");
        TO->remove();
        return;
    }
    */
    if (!target->is_ok_armour("mage")) {
        tell_object(caster,"The power cannot offer protection to those wearing armor.");
        if(objectp(TO)) { TO->remove(); }
        return;
    }
    spell_successful();
    if (target == caster) {
        tell_object(caster,"%^BOLD%^%^BLUE%^You focus your mind and "+
           "feel your skin thicken to provide protection!");
        tell_room(place,"%^BOLD%^%^BLUE%^"+caster->QCN+"'s skin "+
           "seems to grow tougher!", caster );
    } else {
       tell_object(caster,"%^BOLD%^Your mental powers can protect "+
          "only you!");
       TO->remove();
       return;
    }
    target->add_ac_bonus(2);
    target->set_property("spelled", ({TO}) );
    //target->set_property("add_armor",1);
    addSpellToCaster();
    call_out("test", 7);
    spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH + 1800;
    set_end_time();
    call_out("dest_effect",spell_duration);
}

void test(){

    int max_damage, add_tally, thp;
    if (!objectp(target))    // To avoid errors when player quits - Thorn
        dest_effect();

    if (!target->is_ok_armour("mage"))
    {
        tell_object(caster,"The power cannot offer protection to those wearing armor.");
        dest_effect();
        return;
    }

    call_out("test", 7);
    return 0;
}

void dest_effect() {

    if(!objectp(target)) return;
    if(objectp(target))
    {
        target->add_ac_bonus(-2);
        target->remove_property_value("spelled", ({TO}) );
        tell_object(target,"%^BOLD%^%^BLUE%^Your concentration drains "+
        "as your skin reverts to normal.");
        //target->remove_property("add_armor");
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}

string query_cast_string() {
    return "%^BLUE%^"+caster->QCN+" %^RESET%^%^BLUE%^concentrates deeply.";
}
