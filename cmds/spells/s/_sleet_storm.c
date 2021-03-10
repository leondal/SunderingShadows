#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;

int timer,flag,stage,toggle,counter;


void create()
{
    ::create();
    set_spell_name("sleet storm");
    set_spell_level(([ "druid" : 3, "mage" : 3,"oracle" : 3, "magus" : 3 ]));
    set_domains("storms");
    set_mystery( ({ "apocalypse", "winter" }) );
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS sleet storm");
    set_description("The spell sleet storm only works outdoors.  When it is cast, the skies will open up and begin pouring freezing rain on the area.  Within a few moments, howling winds and freezing rain will turn the ground into ice. Movement through the area is difficult and sometimes visibility is obstructed to the point of virtual blindness.");
    set_verbal_comp();
    set_somatic_comp();
    set_save("reflex");
    set_immunities( ({"cold"}) );
    set_components((["mage":(["pinch of special dust":1,"water":1])]));
    aoe_spell(1);
    set_aoe_message("%^BOLD%^%^WHITE%^(besieged by winds and sleet)%^RESET%^");
}

void spell_effect(int prof)
{
    tell_object(caster,"%^BLUE%^You raise your hand to the air and clench your fist.  A peal of thunder sounds as you unclench your fist and the skies "
        "open with freezing rain!");
    tell_room(place,"%^BLUE%^"+caster->QCN+" raises "+caster->QP+" hand into the air and clenches "+caster->QP+" fist.  A peal of thunder sounds as "
        ""+caster->QCN+" unclenches "+caster->QP+" fist and the skies open, pouring the area with freezing rain!",caster);
    counter = clevel/10 + 1;
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

    message("info", "%^RESET%^%^BOLD%^%^CYAN%^Howling winds and the pelting of heavy rain threaten to drown out all other sounds!", nearbyRoom(place,2));

    foes = target_selector();
    foes -= ({ caster });

    for(i=0;i<sizeof(foes);i++) {
        if(!objectp(targ = foes[i])) continue;

        limb = targ->return_target_limb();
        if(do_save(targ,0)) {
          tell_object(targ,"%^BOLD%^%^CYAN%^You avoid the worst of the sleet, but some of the cold still bites at your skin!");
          tell_room(place,"%^CYAN%^"+targ->QCN+" manages to hold on the ice!",({targ}));
          damage_targ(targ,limb,sdamage/2,"cold");
        }
        else {
          tell_object(targ,"%^BOLD%^%^CYAN%^Unable to hold your balance, you slip on the ice!%^RESET%^");
          tell_room(place,"%^CYAN%^%^BOLD%^Unable to hold balance, "+targ->QCN+" slips on the ice!",({targ}));
          targ->set_temporary_blinded(1);
          targ->set_tripped(1,"%^BOLD%^You are struggling to regain your footing!%^RESET%^",4);
          damage_targ(targ,limb,sdamage,"cold");
        }
    }

    counter--;
    place->addObjectToCombatCycle(TO,1);
}


void dest_effect() {
    if(objectp(place)) tell_object(place,"%^RESET%^%^BLUE%^The freezing rain and wind die down and then fade away as the storm clears from the area.");
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
