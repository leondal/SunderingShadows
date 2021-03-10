//_beast_claws.c

#include <std.h>

inherit SPELL;

int bonus;

void create() {
    ::create();

    set_spell_name("beast claws");
    set_spell_level(3);
    set_spell_type("priest");
    set_spell_sphere("animal");
    set_diety("malar");
    set_verbal_comp();
    set_somatic_comp();
}

int preSpell() {
    object *arm;
    int i,j;

    if(caster->query_property("beastclaws")){
        tell_object(caster,"Your claws cannot morph further.");
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
        write("You have cursed armour on your left hand");
        return 0;
    }
    return 1;
}


void spell_effect(int prof) {
    int droll;
    tell_object(caster,"%^BOLD%^%^GREEN%^Your hands morph slowly into beastial claws.");
    tell_room(place,"%^BOLD%^%^GREEN%^"+caster->query_cap_name()+"'s hands morph into two massive beastial claws.",caster);
    caster->remove_limb("right hand");
    caster->remove_limb("left hand");
    caster->set_attack_limbs(({"right claw","left claw"}));
    caster->add_limb("right claw","",0,0,0);
    caster->add_limb("left claw","",0,0,0);
    addSpellToCaster();
    droll = (int)caster->query_guild_level("cleric")/5;
    if(droll < 2) droll = 2;
    if(droll > 4) droll = 4;
    caster->set_attacks_num(droll);
    caster->set_damage(2,droll);
    caster->set_base_damage_type("slashing");
    caster->set_hit_funcs((["right claw":({"/daemon/specials_d", "beastclaws"}),"left claw":({"/daemon/specials_d", "beastclaws"})]));
    caster->set_property("spelled",({TO}));
// adjusting down a little for lower levels, needed a global variable to track it
    if(clevel > 9) bonus = 1;
    if(clevel > 19) bonus += 1;
    if(caster->is_singleClass(caster))  bonus += 1;
    caster->add_attack_bonus(bonus);
//    caster->add_attack_bonus(2);
    caster->set_property("beastclaws",1);
    call_out("dest_effect",8*clevel);
}

void dest_effect() {
    if (!objectp(caster)){ remove(); return; }

    caster->remove_limb("right claw");
    caster->remove_limb("left claw");
    caster->add_attack_bonus(-bonus);
    caster->set_attacks_num(0);
    caster->set_attack_limbs(({}));
    caster->add_limb("left hand","",0,0,0);
    caster->add_limb("right hand","",0,0,0);
    caster->set_wielding_limbs(({"left hand", "right hand"}));
    tell_object(caster,"%^GREEN%^Your hands return to their natural form.");
    caster->toggle_polymorphed();
    caster->remove_property_value("spelled", ({TO}) );
    caster->remove_property("beastclaws");
    TO->remove();
}

string query_cast_string() {
    return "%^GREEN%^With a beastial roar "+caster->query_cap_name()+" prays that "+caster->query_possessive()+" god will release the beast within.";

}

int help() {

    write(
@HELP
Spell  : Beast Claws
Level  : 3rd Level
Sphere : Animal
Deity  : Malar
Syntax : chant beast claws

This spell transforms your hands into great beastial
claws, giving you the power to rend your opponents into shreds
with your bare hands.
HELP
);
    return 1;
}
