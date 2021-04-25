#include <spell.h>
#include <magic.h>
#include <daemons.h>
inherit SPELL;

int time, flag;

void create() {
    ::create();
    set_author("nienne");
    set_spell_name("hungry darkness");
    set_spell_level(([ "warlock" : 2 ]));
    set_spell_sphere("necromancy");
    set_syntax("cast CLASS hungry darkness");
    set_description("This invocation calls a supernatural darkness down within the area, blurring the line between the "
"prime material plane and the planes beyond. What lies beyond will ignore the warlock, but will reach out, biting and "
"clawing at anything close enough...");
    set_verbal_comp();
    set_somatic_comp();
    set_save("reflex");
    aoe_spell(1);
    set_aoe_message("%^BOLD%^%^BLACK%^(blanketed in %^RESET%^%^BLUE%^roiling %^BOLD%^%^BLACK%^shadows)%^RESET%^");
}

void spell_effect(int prof) {
    tell_object(caster,"%^BOLD%^%^BLACK%^You lift your arms, and a sudden %^RESET%^da%^BOLD%^%^BLACK%^r%^RESET%^kn%^BOLD%^%^BLACK%^es%^RESET%^s %^BOLD%^%^BLACK%^descends upon the area!%^RESET%^");
    tell_room(place,"%^BOLD%^%^BLACK%^"+caster->QCN+" lifts "+caster->QP+" arms, and a sudden %^RESET%^da%^BOLD%^%^BLACK%^r%^RESET%^kn%^BOLD%^%^BLACK%^es%^RESET%^s %^BOLD%^%^BLACK%^descends upon the area!%^RESET%^",caster);
    time = 0;
    addSpellToCaster();
    spell_successful();
    execute_attack();
}

void execute_attack() {
    int damage, event, i;
    object *foes;
    string target_limb;

    if (!flag) {
        flag = 1;
        ::execute_attack();
        return;
    }
    if(!objectp(caster)) {
        dest_effect();
        return;
    }
    foes = target_selector();


    if (time>clevel * 2) {
        dest_effect();
    }
    else {
        //define_base_damage(0);//lazy re-roll.
        damage = sdamage;
        tell_room(place,"%^BOLD%^%^BLACK%^The darkness moves around you like a living thing, writhing and muttering.%^RESET%^");
        event = roll_dice(1,3);

        for (i=0;i<sizeof(foes);i++) {
            if (!objectp(foes[i])) continue;
            if (!objectp(caster)) {
                dest_effect();
                return;
            }
            if (foes[i] == caster && caster != target) continue;
            if (interactive(foes[i]) && newbiep(foes[i])) continue;
            if(foes[i]->query_property("no detect")) continue;
//added by Circe to stop scry detectors, etc, from being hit.
            if (!present(caster,place) && caster != target) {
                dest_effect();
                return;
            }
            if(!present(foes[i],place)) continue;

            target_limb = foes[i]->return_target_limb();
            if(do_save(foes[i],0)) {
                switch(event) {
                case 1:
                    tell_object(foes[i],"%^CYAN%^The shadows deepen around you, and you pull away as %^BOLD%^%^WHITE%^t%^RESET%^e%^BOLD%^%^BLACK%^e%^RESET%^t%^BOLD%^%^WHITE%^h %^RESET%^%^CYAN%^graze your skin!%^RESET%^");
                    damage_targ(foes[i], target_limb, damage/2,"piercing");
                    break;
                case 2:
                    tell_object(foes[i],"%^CYAN%^Motion catches the edge of your vision, and you pull away as something claws at you from the shadows!%^RESET%^");
                    damage_targ(foes[i], target_limb, damage/2,"slashing");
                    break;
                default:
                    tell_object(foes[i],"%^CYAN%^A terrible %^RESET%^s%^BOLD%^%^WHITE%^h%^YELLOW%^r%^RESET%^i%^BOLD%^%^BLACK%^e%^RESET%^k %^CYAN%^bursts forth from the shadows, and you quickly cover your ears to fend off the worst of it!%^RESET%^");
                    damage_targ(foes[i], target_limb, damage/2,"sonic");
                    break;
                }
            }
            else {
                switch(event) {
                case 1:
                    tell_object(foes[i],"%^CYAN%^As the shadows deepen around you, you feel %^BOLD%^%^WHITE%^t%^RESET%^e%^BOLD%^%^BLACK%^e%^RESET%^t%^BOLD%^%^WHITE%^h %^RESET%^%^CYAN%^sink into your skin!%^RESET%^");
                    damage_targ(foes[i], target_limb, damage,"piercing");
                    break;
                case 2:
                    tell_object(foes[i],"%^CYAN%^Something claws at you from the shadows, drawing %^RED%^b%^BOLD%^%^RED%^lo%^RESET%^%^RED%^od%^CYAN%^!%^RESET%^");
                    damage_targ(foes[i], target_limb, damage,"slashing");
                    break;
                default:
                    tell_object(foes[i],"%^CYAN%^A terrible %^RESET%^s%^BOLD%^%^WHITE%^h%^YELLOW%^r%^RESET%^i%^BOLD%^%^BLACK%^e%^RESET%^k %^CYAN%^bursts forth from the shadows, an unnatural sound that pierces your skull like a %^BOLD%^%^CYAN%^knife%^RESET%^%^CYAN%^!%^RESET%^");
                    damage_targ(foes[i], target_limb, damage,"sonic");
                    break;
                }
            }
        }
        time++;;
        if (present(caster,place) && caster != target && !caster->query_unconscious()) {
            place->addObjectToCombatCycle(TO,1);
        }
        else {
            dest_effect();
        }
    }
}

void dest_effect() {
    if(objectp(place)) tell_room(place,"%^BOLD%^%^BLACK%^The darkness dissipates into nothing but %^RESET%^a%^CYAN%^i%^RESET%^r%^BOLD%^%^BLACK%^.%^RESET%^");
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
