//Flameform
#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;

int i, time, clevel;
object caster, env;
string target_limb;
object *foes;

void create() {
    ::create();
    set_spell_name("flameform");
    set_spell_level(4);
    set_spell_type("priest");
    set_spell_sphere("elemental fire");
    set_diety("kossuth");
    set_verbal_comp();
    set_somatic_comp();
}

int preSpell() {
    object *arm;
    int i,j;

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
    object *arm;
    int i,j;

    clevel = CLEVEL;
    caster = CASTER;
    place = PLACE;

    tell_object(caster,"%^BOLD%^%^RED%^You wave your hands around summoning flames to surround you!");
    tell_object(caster,"%^BOLD%^%^ORANGE%^Your hands disappear and become wisps of flame!");
    tell_room(environment(caster),"%^BOLD%^%^RED%^"+caster->query_cap_name()+" waves "+caster->query_possessive()+" hands and they suddenly become flames!",caster);
    caster->remove_limb("right hand");
    caster->remove_limb("left hand");
    caster->set_attacks_num(2);
    caster->set_attack_limbs(({"right %^RED%^flame%^RESET%^","left %^RED%^flame%^RESET%^"}));
    caster->set_damage(1,8);
    caster->set_base_damage_type("bludgeon");
    caster->set_hit_funcs((["right %^RED%^flame%^RESET%^":({"/daemon/specials_d", "flameform"}),"left %^RED%^flame%^RESET%^":({"/daemon/specials_d", "flameform"})]));
    caster->set_property("spelled",({TO}));
    time = 0;
    call_out("do_flame",5);
}

void do_flame() {
    int j;
    int damage;

    foes = all_living(environment(caster));
    j = sizeof(foes);
    if (j>0) {
        if ((2*time)>clevel) {
            tell_object(caster,"%^BOLD%^Your hands stop burning and return to normal.");
            tell_room(environment(caster),"%^BOLD%^"+caster->QCN+"'s hands stop burning and return to normal.",caster);
            dest_effect();
        } else {
            tell_room(environment(caster),"%^BOLD%^RED%^"+caster->query_cap_name()+" reaches out, burning everything "+caster->query_subjective()+" touches!", caster);
            for (i=0;i<j;i++) {
                if (!objectp(foes[i])) continue;
                if (foes[i] == caster) continue;
                if (interactive(foes[i]) && foes[i]->query_level() < 6) continue;
                if (wizardp(foes[i])) continue;
                damage = roll_dice(2,6)+random(clevel);
                if (SAVING_D->saving_throw(target,"spell",0)) {
                    damage = damage/2;
                }
                target_limb = foes[i]->return_target_limb();
                if (present(foes[i],environment(caster))) {
                    tell_object(caster,"%^RED%^You burn "+foes[i]->query_cap_name()+" with your touch.");
                    tell_object(foes[i],"%^RED%^You are burned by "+caster->query_cap_name()+"'s touch.");
                    damage_targ(foes[i], target_limb, damage);
                    if (objectp(foes[i])) spell_kill(foes[i],caster);
                }
            }
        }
        time+=2;
        call_out("do_flame",10);
    }
}

void dest_effect() {
    ::dest_effect();
    if (!objectp(caster)) return;
    caster->set_attacks_num(0);
    caster->set_attack_limbs(({}));
    caster->add_limb("left hand","",0,0,0);
    caster->add_limb("right hand","",0,0,0);
    caster->set_wielding_limbs(({"left hand", "right hand"}));
    write("%^RED%^Your hands return to their natural form.");
    caster->toggle_polymorphed();
    caster->remove_property_value("spelled", ({TO}) );
    TO->remove();
}

void help() {
    write(
@HELP
Spell  : Flameform
Level  : 4th Level
Sphere : Elemental Fire
Deity  : Kossuth
Syntax : chant flameform

This spell changes the caster's hands into moving magical flames. 
It may be dispelled.  Creatures in the room with a flameformed priest
take damage from the flames.  Spells cannot be cast while in the
form of the flame.
HELP
);
    return;
}
