//Ice Storm coded by Bane//
//Adding to clerics because it is also a cleric spell in the
//PHB after discussions with other Imms ~Circe~ 5/18/13
//After discussing with Circe, removing it from Clerics for the time being until they we are finished rebalancing
#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;

int timer,mystage,flag;

void create() {
    ::create();
    set_spell_name("storm of vengeance");
    set_spell_level(([ "druid" : 9, "cleric" :9, "oracle" : 9 ]));
    set_mystery("wind");
    set_mystery("battle");
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS storm of vengeance");
    set_description("When this spell is cast, a dark storm cloud will cover the area.  Lightning will begin to strike enemies of the caster "
        "and they will be shaken by thunder.  Soon after, the cloud will open up in a torrent of acid rain and hail, making it difficult "
        "to maintain footing and to see.");
    set_verbal_comp();
    set_somatic_comp();
    set_save("varied");
    mystage = 1;
    aoe_spell(1);
    set_aoe_message("%^BOLD%^%^BLACK%^(shaken by a vengeful %^RESET%^storm%^BOLD%^%^BLACK%^)%^RESET%^");
}

string query_cast_string() {
    tell_object(caster,"%^BOLD%^%^GREEN%^You shout into the heavens, calling forth the vengeance of the wilds!");
    tell_room(place,"%^BOLD%^%^GREEN%^"+caster->QCN+" shouts into the heavens, calling forth the vengeance of the wilds!",caster);
    return "display";
}

void spell_effect(int prof) {
    tell_room(place,"%^BOLD%^%^BLACK%^An ominous black cloud roils into the area with %^BOLD%^%^GREEN%^unnatural %^CYAN%^purpose!%^RESET%^");

    spell_successful();
    addSpellToCaster();
}

void execute_attack() {
    object *foes=({}),*targs=({}),*tmp,targ;
    int i, strikes,hail,acid,lightning;
    string limb;

    ::execute_attack();
    if(!objectp(caster)) {
        dest_effect();
        return;
    }
    if(!objectp(place)){
        dest_effect();
        return;
    }
    if(!present(caster,place)) {
        dest_effect();
        return;
    }
    if((time() > timer) && mystage > 1) {
        dest_effect();
        return;
    }

    switch(mystage) {
    case 1:
        tell_room(place,"%^RESET%^%^BOLD%^%^BLUE%^A deafening %^BLACK%^BOOM%^RESET%^%^BOLD%^%^BLUE%^ of thunder conincides instantly with a "
            "bright flash of %^RESET%^%^YELLOW%^lightning!%^RESET%^");
        tell_room(place,"%^RESET%^%^CYAN%^A terrible storm begins to drench the area, flashes of %^YELLOW%^lightning %^RESET%^illuminating "
            "%^CYAN%^the area as fist-sized %^RESET%^%^BOLD%^hail stones%^RESET%^%^CYAN%^ smash violently all around!%^RESET%^");
        place->addObjectToCombatCycle(TO,1);
        mystage++;
        timer = time() + 30 + (ROUND_LENGTH * clevel * 2);
        return;

    default:
        tell_room(place,"%^RESET%^%^CYAN%^The terrible storm continues to rage, flashes of %^YELLOW%^lightning %^RESET%^illuminating "
            "%^CYAN%^the area as fist-sized %^RESET%^%^BOLD%^hail stones%^RESET%^%^CYAN%^ smash violently down and %^BOLD%^%^GREEN%^hissing "
            "rain %^RESET%^%^CYAN%^burns everything it touches!%^RESET%^");
        break;
    } // falls through when mystage is above 1


    foes = target_selector();
    foes -= ({ caster });
    define_base_damage(0);
    hail = sdamage/2;
    acid = sdamage;
    lightning = sdamage;

    for(i=0;i<sizeof(foes);i++) {
        if(!objectp(targ = foes[i])) continue;

        limb = targ->return_target_limb();

        switch(random(3)) {
          case 1: // hail tiem
            set_save("reflex");

            if(!do_save(targ)) {
                tell_object(targ,"%^RESET%^%^BOLD%^Hailstones smash into your head and shoulders!");
                damage_targ(targ,limb,hail,"cold");
                damage_targ(targ,limb,hail,"bludgeoning");
            }
            else {
                if(!evade_splash(foes[i])) {
                  tell_object(targ,"%^CYAN%^You move aside at the last instant, avoiding most of the damage from the hailstones!");
                  damage_targ(targ,limb,hail/2,"cold");
                  damage_targ(targ,limb,hail/2,"bludgeoning");
                }
            }
          break;

          case 2: // acid
            set_save("reflex");

            if(!do_save(targ)) {
                tell_object(targ,"%^RESET%^%^BOLD%^%^BLACK%^You feel the burn as the rain strikes your skin.  It's %^GREEN%^acid%^RESET%^%^BOLD%^%^BLACK%^!");
                damage_targ(targ,limb,acid,"acid");
            }
            else {
                if(!evade_splash(foes[i])) {
                  tell_object(targ,"%^CYAN%^You move aside at the last instant, avoiding the rain, though a few droplets still sear your skin!");
                  damage_targ(targ,limb,acid/2,"acid");
                }
            }
          break;

          default: // thunder
            set_save("reflex");

            if(!do_save(targ)) {
                tell_object(targ,"%^YELLOW%^You are electrified by a bolt of lightning from the storm cloud!");
                damage_targ(targ,limb,lightning,"electricity");
            }
            else {
                if(!evade_splash(foes[i])) {
                  tell_object(targ,"%^RESET%^%^BOLD%^You dodge aside at the last second, avoiding the brunt of the damage from the lightning strike!");
                  damage_targ(targ,limb,lightning/2,"electricity");
                }
            }

            set_save("fort");

            if(!do_save(targ)) {
                tell_object(targ,"%^RESET%^%^BOLD%^%^BLACK%^The thunder crashes right against you, deafening you!");
                targ->set_paralyzed(roll_dice(2,6),"Your ears are bleeding!");
            }
          break;
        }
    }
    place->addObjectToCombatCycle(TO,1);
}


void dest_effect() {

    if(objectp(place)) tell_room(place,"%^BOLD%^%^CYAN%^The ominous black stormclouds suddenly billow away, disappearing as quickly as they arrived!");

    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
