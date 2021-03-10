//_wolfjaws

#include <std.h>

inherit SPELL;

void create() {
    ::create();

    set_spell_name("black talon");
    set_spell_level(2);
    set_spell_type("priest");
    set_spell_sphere("necromantic");
    set_diety("cyric");
    set_verbal_comp();
    set_somatic_comp();
}

int preSpell() {

    object *arm;
    int i,j;

    if(caster->query_property("black talon")){
      tell_object(caster,"Your tentacles cannot morph further.");
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
        arm[i]->set_not_equipped();
    }

    if (sizeof(caster->query_armour("right hand"))) {
        write("You have armour on your right hand.");
        return 0;
    }
    if (sizeof(caster->query_armour("left hand"))) {
        write("You have armour on your left hand");
        return 0;
    }
    return 1;
}


void spell_effect(int prof) {

    int droll;
   tell_object(caster,"%^BLUE%^Your hands morph into long elastic black tentacles with a horrid claw on the end.%^RESET%^");
   tell_room(place,"%^BLUE%^"+caster->query_cap_name()+"'s hands morph into long elastic tentacles with a deadly looking claw at the end.%^RESET%^", caster);
    caster->remove_limb("right hand");
    caster->remove_limb("left hand");
   caster->add_limb("right clawed tentacle","",0,0,0);
   caster->add_limb("left clawed tentacle","",0,0,0);
   caster->set_attack_limbs(({"right %^BLUE%^clawed tentacle%^RESET%^","left %^BLUE%^clawed tentacle%^RESET%^"}));
    addSpellToCaster();
    droll = (int)caster->query_guild_level("cleric")/5;
    if(droll < 2) droll = 2;
    if(droll > 5) droll = 5;
    caster->set_attacks_num(droll);
    caster->set_damage(2,droll);
    caster->set_base_damage_type("piercing");
   caster->set_hit_funcs((["right %^BLUE%^clawed tentacle%^RESET%^":({"/daemon/specials_d", "blacktalon"}),"left %^BLUE%^clawed tentacle%^RESET%^":({"/daemon/specials_d", "blacktalon"})]));
    caster->set_property("spelled",({TO}));
    caster->set_property("black talon",1);
    call_out("dest_effect",8*clevel);
}

void dest_effect() {
    if(!objectp(caster)){remove(); return;}

    caster->set_attacks_num(0);
    caster->set_attack_limbs(({}));
    caster->add_limb("left hand","",0,0,0);
    caster->add_limb("right hand","",0,0,0);
    caster->set_wielding_limbs(({"left hand", "right hand"}));
   caster->remove_limb("right clawed tentacle");
   caster->remove_limb("left clawed tentacle");
    tell_object(caster," %^BLUE%^Your hands return to their natural form");
    caster->toggle_polymorphed();
    caster->remove_property_value("spelled", ({TO}) );
    caster->remove_property("black talon");
    TO->remove();

}

string query_cast_string() {
   return "%^BLUE%^%^With a massive tug on each hand, "+caster->query_cap_name()+" begins pulsing and molding "+caster->query_possessive()+" arms into long black tentacles.%^RESET%^";

}

int help() {
    write(
@HELP
Spell  : Black Talon
Level  : 2nd Level
Sphere : Necromatic
Deity  : Cyric
Syntax : chant black talon

This spell transforms your hands and arms into great
clawed tentacles, great for ripping your opponents
to shreds with your bare hands.
HELP
);
    return 1;
}
