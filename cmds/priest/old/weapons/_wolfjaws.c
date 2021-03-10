//_wolfjaws

#include <std.h>

inherit SPELL;

void create() {
    ::create();

    set_spell_name("wolfjaws");
    set_spell_level(2);
    set_spell_type("priest");
    set_spell_sphere("combat");
    set_diety("tyr");
    set_verbal_comp();
    set_somatic_comp();
}

int preSpell() {
    object *arm;
    int i, j;

    if(caster->query_property("wolfjaws")){
        tell_object(caster,"Your jaws cannot morph further.");
        return 0;
    }
    arm = caster->query_armour("right hand");
    j = sizeof(arm);
    for (i=0;i<j;i++) {
        if (arm[i]->query_property("enchantment"))
            if ((int)arm[i]->query_property("enchantment") < 0)
                continue;
        caster->remove_armour_from_limb(arm[i], (string *)arm[i]->query_actual_limbs());
        arm[i]->set_not_equipped();
    }

    arm = caster->query_armour("left hand");
    j = sizeof(arm);
    for (i=0;i<j;i++) {
        if (arm[i]->query_property("enchantment"))
            if ((int)arm[i]->query_property("enchantment") < 0)
                continue;
        caster->remove_armour_from_limb(arm[i], (string *)arm[i]->query_actual_limbs());
        arm[i]->set_not_equipped() ;
    }

    if (sizeof(caster->query_armour("right hand"))) {
        write("You have cursed armour on your right hand.");
        return 0;
    }

    if (sizeof(caster->query_armour("left hand"))) {
        write("You have cursed armour on your left hand.");
        return 0;
    }
    return 1;
}

void spell_effect(int prof) {
    int droll;
    tell_object(caster,"%^BOLD%^%^RED%^Your hands morph slowly into the very jaws that took off Tyrs hand.");
    tell_room(place,"%^BOLD%^%^RED%^"+caster->QCN+"'s hands morph into to massive wolf jaws.",caster);
    caster->remove_limb("right hand");
    caster->remove_limb("left hand");
    caster->set_attack_limbs(({"right wolf head","left wolf head"}));
    addSpellToCaster();
    droll = (int)caster->query_guild_level("cleric")/5;
    if(droll < 2) droll = 2;
    if(droll > 4) droll = 4;
    caster->set_attacks_num(droll);
    caster->set_damage(2,droll);
    caster->set_base_damage_type("piercing");
    caster->set_hit_funcs((["right wolf head":({"/daemon/specials_d", "wolfjaws"}),"left wolf head":({"/daemon/specials_d", "wolfjaws"})]));
    caster->set_property("spelled",({TO}));
    caster->add_attack_bonus(2);
    caster->set_property("wolfjaws",1);
    call_out("dest_effect",8*clevel);
}

void dest_effect() {
    if (objectp(caster)){
        caster->set_attacks_num(0);
        caster->set_attack_limbs(({}));
        caster->add_limb("left hand","",0,0,0);
        caster->add_limb("right hand","",0,0,0);
       tell_object(caster,"%^RED%^Your hands return to their natural form.");
        caster->set_wielding_limbs(({"left hand","right hand"}));
        caster->add_attack_bonus(-2);
        caster->toggle_polymorphed();
        caster->remove_property_value("spelled",({TO}));
    caster->remove_property("wolfjaws");
    }
    TO->remove();

}

string query_cast_string() {
    return "%^RED%^With a sheer howl "+caster->QCN+" prays for the pain that "+caster->QP+" god once had.";

}

int help() {

    write(
@HELP
Spell  : Wolfjaws
Level  : 2nd Level
Sphere : Combat
Deity  : Tyr
Syntax : chant wolfjaws

This spell will transform your hands into the jaws of a
great wolf, giving you the power to cause great damage with
your bare hands.
HELP
);
    return 1;
}
