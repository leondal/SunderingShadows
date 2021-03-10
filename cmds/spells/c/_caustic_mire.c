#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;

int timer,flag,stage,toggle,counter;


void create()
{
    ::create();
    set_spell_name("caustic mire");
    set_spell_level(([ "warlock" : 2 ]));
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS caustic mire");
    set_description("This invocations causes the ground in the area to turn into a muddy, acidic mire that will cause all caught within it to lose their footing. The caustic fumes cause victims to suffer from acid damage throughout the duration.");
    set_verbal_comp();
    set_somatic_comp();
    set_save("reflex");
    set_immunities( ({"acid"}) );
    aoe_spell(1);
    set_aoe_message("%^BOLD%^%^GREEN%^(covered in acidic mud)%^RESET%^");
    set_feats_required(([ "warlock" : "tome of ancient secrets"]));
}

string query_cast_string()
{
    return "%^BLACK%^BOLD%^" + caster->QCN + " puts " + caster->QP + " hands together where e%^RESET%^%^GREEN%^l%^BOLD%^d%^RESET%^r%^BOLD%^i%^BLACK%^tch e%^RESET%^%^GREEN%^n%^BOLD%^e%^RESET%^r%^BOLD%^g%^BLACK%^y f%^RESET%^%^GREEN%^o%^BOLD%^r%^RESET%^m%^BOLD%^s%^BLACK%^.%^RESET%^";
}

void spell_effect(int prof)
{
    tell_object(caster,"%^BOLD%^GREEN%^You raise your hands to the air and the dark e%^RESET%^%^GREEN%^n%^BOLD%^%^BLACK%^e%^GREEN%^r%^RESET%^%^GREEN%^g%^BOLD%^%^BLACK%^y %^GREEN%^spreads throughout the area, forming into a sticky, a%^RESET%^%^GREEN%^c%^BOLD%^%^BLACK%^i%^GREEN%^dic m%^RESET%^%^GREEN%^u%^BOLD%^%^BLACK%^d%^GREEN%^!%^RESET%^");
    tell_room(place,"%^GREEN%^BOLD%^"+caster->QCN+" puts "+caster->QP+" hands to the air and the dark e%^RESET%^%^GREEN%^n%^BOLD%^%^BLACK%^e%^GREEN%^r%^RESET%^%^GREEN%^g%^BOLD%^%^BLACK%^y %^GREEN%^spreads throughout the area, forming into a sticky, a%^RESET%^%^GREEN%^c%^BOLD%^%^BLACK%^i%^GREEN%^dic m%^RESET%^%^GREEN%^u%^BOLD%^%^BLACK%^d%^GREEN%^!%^RESET%^",caster);
    counter = clevel/8 + 2;
    addSpellToCaster();
    spell_successful();
    execute_attack();
}


void execute_attack()
{
    object *foes=({}),targ;
    int i;
    string limb;

    if(!flag)
    {
        flag = 1;
        ::execute_attack();
        return;
    }

    if(!objectp(caster) || !objectp(place) || !present(caster,place)|| counter<0)
    {
        dest_effect();
        return;
    }

    message("info", "%^RESET%^%^BOLD%^%^GREEN%^The mud seethes and hisses as it almost seems to grope at the living!", nearbyRoom(place,2));

    foes = target_selector();
    foes -= ({ caster });

    for(i=0;i<sizeof(foes);i++) {
        if(!objectp(targ = foes[i])) continue;

        limb = targ->return_target_limb();
        if(do_save(targ,0)) {
          tell_object(targ,"%^BOLD%^%^GREEN%^You avoid the worst of the mire, but the acidic fumes still cause scalding burns!");
          tell_room(place,"%^GREEN%^"+targ->QCN+" manages to hold strong in the mud!",({targ}));
          damage_targ(targ,limb,sdamage/2,"acid");
        }
        else {
          tell_object(targ,"%^BOLD%^%^GREEN%^Unable to keep your footing, you slip in the mud!%^RESET%^");
          tell_room(place,"%^GREEN%^%^BOLD%^Unable to keep balance, "+targ->QCN+" slips in the mud!",({targ}));
          targ->set_temporary_blinded(1);
          targ->set_tripped(1,"%^BOLD%^You are struggling to regain your footing!%^RESET%^",4);
          damage_targ(targ,limb,sdamage,"acid");
        }
    }

    counter--;
    place->addObjectToCombatCycle(TO,1);
}


void dest_effect() {
    if(objectp(place)) tell_object(place,"%^RESET%^%^GREEN%^The caustic mire dries up and the acidic fumes dissappate.");
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
