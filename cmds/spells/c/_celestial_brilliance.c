#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;

int timer,flag,stage,toggle,counter;
int prevlight;


void create()
{
    ::create();
    set_spell_name("celestial brilliance");
    set_spell_level(([ "innate" : 7 ]));
    set_spell_sphere("invocation_evocation");
    set_syntax("cast innate celestial brilliance");
    set_damage_desc("AOE Divine damage over time, 25% more damage vs undead");
    set_description("You channel energy directly from the celestial realms, unleashing a torrent of divine energy into the area and creating a celestial dawn. The room becomes brighter and all enemies take divine damage over time.");
    set_verbal_comp();
    set_somatic_comp();
    set_save("reflex");
    aoe_spell(1);
    set_aoe_message("%^BOLD%^%^CYAN%^(%^RESET%^%^CYAN%^c%^BOLD%^a%^GREEN%^s%^CYAN%^c%^RESET%^%^CYAN%^a%^BOLD%^d%^GREEN%^i%^CYAN%^n%^RESET%^%^CYAN%^g w%^BOLD%^a%^GREEN%^v%^CYAN%^e%^RESET%^%^CYAN%^s %^BOLD%^o%^RESET%^%^CYAN%^f %^BOLD%^%^WHITE%^l%^ORANGE%^i%^WHITE%^ght %^CYAN%^f%^GREEN%^i%^CYAN%^l%^RESET%^%^CYAN%^l t%^BOLD%^h%^RESET%^%^CYAN%^e %^BOLD%^a%^GREEN%^r%^CYAN%^e%^RESET%^%^CYAN%^a%^BOLD%^)%^RESET%^");
}

string query_cast_string()
{
    tell_room(place,"%^RESET%^%^CYAN%^"+caster->QCN+" %^RESET%^%^CYAN%^bows their head with a m%^BOLD%^%^MAGENTA%^u%^CYAN%^r%^RESET%^%^CYAN%^m%^BOLD%^u%^RESET%^%^CYAN%^r%^BOLD%^%^MAGENTA%^r%^RESET%^%^CYAN%^e%^BOLD%^d %^RESET%^%^CYAN%^e%^BOLD%^%^MAGENTA%^n%^CYAN%^t%^RESET%^%^CYAN%^r%^BOLD%^e%^RESET%^%^CYAN%^a%^BOLD%^%^MAGENTA%^t%^CYAN%^y%^RESET%^%^CYAN%^, holding their hands out in %^BOLD%^%^WHITE%^su%^RESET%^p%^BOLD%^p%^RESET%^l%^BOLD%^ica%^RESET%^t%^BOLD%^io%^RESET%^n%^CYAN%^.%^RESET%^");
    return "display";
}

void spell_effect(int prof)
{
    tell_room(place,"%^RESET%^%^CYAN%^A loud %^BOLD%^t%^GREEN%^r%^CYAN%^um%^GREEN%^p%^CYAN%^et bl%^GREEN%^a%^CYAN%^st %^RESET%^%^CYAN%^sounds out as the area brightens with %^BOLD%^%^WHITE%^v%^RESET%^i%^YELLOW%^b%^WHITE%^ra%^RESET%^n%^BOLD%^t l%^RESET%^u%^BOLD%^m%^ORANGE%^i%^WHITE%^n%^RESET%^e%^BOLD%^s%^ORANGE%^c%^WHITE%^e%^RESET%^n%^BOLD%^ce%^RESET%^%^CYAN%^, %^YELLOW%^p%^WHITE%^u%^ORANGE%^re %^RESET%^%^CYAN%^and %^YELLOW%^wh%^WHITE%^o%^ORANGE%^les%^WHITE%^o%^ORANGE%^me%^RESET%^%^CYAN%^!%^RESET%^");
    prevlight=place->query_light();
    if(prevlight<1)
        place->set_light(1);
    counter = clevel * 3;
    place->set_property("spelled", ({ this_object() }) );
    caster->set_property("spelled",({ this_object() }));
    addSpellToCaster();
    spell_successful();
    execute_attack();
}

void execute_attack()
{
    object *foes=({}),targ;
    int i;

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

    message("info","%^RESET%^%^CYAN%^T%^BOLD%^o%^GREEN%^r%^CYAN%^r%^RESET%^%^CYAN%^e%^BOLD%^n%^GREEN%^t%^CYAN%^s %^RESET%^%^CYAN%^of %^WHITE%^g%^BOLD%^l%^CYAN%^i%^RESET%^m%^BOLD%^m%^CYAN%^e%^RESET%^r%^BOLD%^i%^CYAN%^n%^RESET%^g %^BOLD%^p%^ORANGE%^u%^WHITE%^ri%^RESET%^t%^BOLD%^y %^RESET%^%^CYAN%^pulse in waves around the area, and a %^BOLD%^%^WHITE%^c%^RESET%^e%^BOLD%^le%^RESET%^s%^BOLD%^ti%^RESET%^a%^BOLD%^l f%^RESET%^a%^BOLD%^nf%^RESET%^a%^BOLD%^re %^RESET%^%^CYAN%^resounds with a deafening roar.%^RESET%^",place);
    foes = target_selector();
    foes -= ({ caster });

    define_base_damage(0);//reroll each turn
    for(i=0;i<sizeof(foes);i++) {
        if(!objectp(targ = foes[i]))
            continue;
        if(!do_save(foes[i],0))
        {
            "/std/effect/status/dazzled"->apply_effect(foes[i],1);
        }
        tell_object(targ,"%^BOLD%^%^WHITE%^The brightness threatens to dazzle you!");

        if(foes[i]->is_undead())
        {
            sdamage = (sdamage * 5) / 4;
            message("info","%^RESET%^%^CYAN%^The %^BOLD%^%^WHITE%^l%^ORANGE%^i%^WHITE%^g%^RESET%^h%^BOLD%^t %^RESET%^%^CYAN%^unmakes %^WHITE%^"+foes[i]->QCN+"%^RESET%^%^CYAN%^, %^BOLD%^%^RED%^tearing %^RESET%^%^CYAN%^apart its %^BOLD%^%^MAGENTA%^p%^RED%^e%^MAGENTA%^rv%^RED%^e%^MAGENTA%^r%^RED%^s%^MAGENTA%^e %^BLACK%^ex%^RESET%^i%^BOLD%^%^BLACK%^st%^RESET%^e%^BOLD%^%^BLACK%^nc%^RESET%^e%^CYAN%^!%^RESET%^",place);
        }
        damage_targ(targ,targ->return_target_limb(),sdamage,"divine");
    }
    counter--;
    place->addObjectToCombatCycle(TO,1);
}


void dest_effect() {
    if(objectp(place))
    {
        place->set_light(prevlight);
        tell_object(place,"%^BOLD%^%^BLUE%^The brightness recedes, and the place becomes a bit cooler.%^RESET%^");
        place->remove_property_value("spelled", ({TO}) );
    }
    caster->remove_property_value("spelled", ({TO}) );
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
