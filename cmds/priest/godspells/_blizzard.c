//Blizzard - Aurilian firestorm alternative, coded by Nienne//
#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;

int i, j, time, clevel;
object caster, env;
string target_limb;
object *foes;

void create() {
    ::create();
    set_spell_name("blizzard");
    set_spell_level(8);
    set_spell_type("priest");
    set_spell_sphere("elemental");
    set_verbal_comp();
    set_somatic_comp();
}

void spell_effect(int prof) {
    clevel = CLEVEL;
    caster = CASTER;
    place = PLACE;
    if (place->query_property("iced",1)) {
        tell_room(place,"The raging storm around you flares with intensity.");
        TO->remove();
        return 1;
    }
    tell_object(caster,"%^BOLD%^%^CYAN%^You wave your hands around summoning winter's fury from the skies above!");
    tell_room(place,"%^BOLD%^%^CYAN%^"+caster->query_cap_name()+" waves "+caster->query_possessive()+" hands around summoning winter's fury from the skies above!",caster);
    place->set_property("spelled", ({TO}) );
    time = 0;
    call_out("do_storm",5);
}

void do_storm() {
    int damage;
    if(!objectp(place)) {
        dest_effect();
        return;
    }
    foes = all_living(place);
    foes = filter_array(foes, "is_non_immortal",FILTERS_D);

    j = sizeof(foes);
    if (clevel > 20) {
        clevel = 20;
    }
    //Added by saide cause I noticed a mob I'd had using it 
    //was causing a bug with it still going when the mob died.
    
    if(!objectp(caster)) {
        tell_room(place,"%^BOLD%^%^CYAN%^The blizzard weakens and dissipates.");
        dest_effect();
        return;
    }

    if (time>clevel || !present(caster,place)) {
        tell_room(place,"%^BOLD%^%^CYAN%^The blizzard weakens and dissipates.");
        dest_effect();
        return;
    } else {
        place->set_property("iced",1);
        tell_room(place,"%^BOLD%^CYAN%^A whirlwind of ice and sleet rages across the area damaging everything in sight!");
        for (i=0;i<j;i++) {
            if (!objectp(foes[i])) continue;
            if (foes[i] == caster) continue;
            if (interactive(foes[i]) && foes[i]->query_level() < 6) continue;
            if (!SAVING_D->saving_throw(target,"spell",0)) {
                damage = roll_dice(4,8)+clevel;
            } else {
                damage = roll_dice(2,8)+clevel;
            }
            target_limb = foes[i]->return_target_limb();
            if (!present(caster,place)) {
                dest_effect();
                return;
            }
            if (present(foes[i],place)) {
                damage_targ(foes[i], target_limb, damage);
                if (present(caster, place)) {
                    if (objectp(foes[i])) spell_kill(foes[i],caster);
                }
            }
        }
        time+=1;
        if (present(caster,place)) {
            call_out("do_storm",10);
        }
    }
}

void dest_effect() {
    if(objectp(place)) {
        place->remove_property("iced");
        place->remove_property_value("spelled", ({TO}) );
        tell_room(place,"%^BOLD%^%^CYAN%^The blizzard weakens and dissipates.");
    }
    ::dest_effect();
    remove_call_out("do_storm");
    remove();
}

void help() {
    write(
@HELP
Spell  : Blizzard
Level : 8th Level
Sphere : Elemental Ice
Deity  : Auril
Syntax : chant blizzard

When the blizzard spell is cast, the surrounding area is
engulfed in a storm of ice.  Any target in the area of 
effect takes damage every round while the spell is in 
effect, but does not damage the caster.
HELP
);
    return;
}
