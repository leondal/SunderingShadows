//      Teleport
#include <spell.h>
#include <magic.h>
#include <daemons.h>
#include <teleport.h>

inherit SPELL;
mixed endplace;

void create() {
    ::create();
    set_spell_name("teleport");
    set_spell_level(([ "mage" : 5, "magus" : 5 ]));
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS teleport on LOCATION");
    set_description("The teleport spell will move the caster from his current location to a specified 'remembered "
"location'.  The remember command is used to retain a location in the caster's memory, <remember here as cave> for example"
".  Then the caster can type <cast classname teleport to cave> and the the spell will move the caster to the location "
"specified.  Be warned, however.  This powerful spell of teleport is not always without error.  The caster may end up far "
"from where he/she intended to teleport to. You may also <unremember location> which will remove a specific location from "
"memory.

%^BOLD%^%^RED%^See also:%^RESET%^ remember, unremember, recall");
    set_verbal_comp();
    set_arg_needed();
	set_helpful_spell(1);
    set_peace_needed(1);
}

string query_cast_string() {
    tell_room(place,"%^CYAN%^As "+caster->QCN+" chants, "+caster->QP+" form shines in a bright blue light.%^RESET%^",caster);
    return "display";
}

void spell_effect(int prof) {

    int power, prob;

    power = clevel>50?50:clevel;
    prob = to_int(25.0 + 65.0*(power/50.0));

    if (roll_dice(1, 100) > prob) {
        if (!objectp(endplace = TELEPORT->scatter_destination(caster->query_rem_room(arg)))) {
            endplace = caster->query_rem_room(arg);
        }
    }else {
        endplace = caster->query_rem_room(arg);
    }

    tell_object(caster,"%^BLUE%^%^BOLD%^You recall your destination "+
                "in your mind, focusing to bring yourself to it.");

    spell_successful();
    
    //sdamage / 4 because it was killing people - Tlaloc 7.25.20
    if(!TELEPORT->object_can_be_teleported(caster,endplace,clevel))
    {
        tell_object(caster,"You sense something is wrong with your spell and it backfires.");
        tell_room(place,caster->QCN+" "+"looks startled.",caster);
        damage_targ(caster, caster->return_target_limb(), sdamage / 4, "mental");
        dest_effect();

    }
    tell_room(endplace,"%^BOLD%^%^BLUE%^A blue light grows in your vicinity.",caster);
    call_out("spell_effect_next",ROUND_LENGTH);
}

void spell_effect_next()
{
    if(!TELEPORT->teleport_object(caster,caster,endplace,clevel))
    {
        tell_object(caster,"You sense something is wrong with your spell and loose concentration.");
        tell_room(place,caster->QCN+" "+
                  "looks startled.",caster);
    }
    dest_effect();
}

void dest_effect() {
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
