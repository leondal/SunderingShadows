// Invisibility - Coded by Vashkar@shadowgate

#include <spell.h>
#include <magic.h>
#include <rooms.h>
#include <std.h>
inherit SPELL;

object invisob;

create()
{
    ::create();
    set_spell_name("invisibility");
    set_spell_level(([ "mage" : 2, "bard" : 2, "assassin" : 2, "inquisitor" : 2, "oracle" : 2, "magus" : 2, "cleric" : 2 ]));
    set_mystery("shadow");
    set_domains("illusion");
    set_spell_sphere("illusion");
    set_syntax("cast CLASS invisibility [on TARGET]");
    set_description("Although called invisibility, this spell doesn't turn target invisible. Instead, it alters perception of everyone around them, making target unnoticeable in minds of others. This spell requires target to move with some caution and will break itself if target enters into combat. Creatures that can see beyond this illusion will be able to attack the target.
If target so wishes it might %^ORANGE%^<appear>%^RESET%^.");
    set_verbal_comp();
    set_somatic_comp();
    set_components(([
      "mage" : ([ "eyelash" : 1, "gum arabic" : 1, ]),
    ]));
	set_helpful_spell(1);
}

string query_cast_string()
{
    return "%^CYAN%^"+caster->QCN+" chants rhythmically, "+caster->QP+" voice getting slowly lower and harder to hear.";
}

spell_effect(int prof)
{
    if (!target) target=caster;

    if (!silent_casting) {
        if ((string)TO->query_spell_type() == "potion") {
            tell_object(caster, "%^CYAN%^As the potion warms your stomach, you look down and realise your body is fading!%^RESET%^");
        } else{
            if (interactive(caster)) {
                if (target == caster) {
                    tell_object(caster, "%^CYAN%^You continue to chant as your body starts to fade from sight.");
                    tell_room(place, "%^CYAN%^" + caster->QCN + " continues to chant as " + caster->QS + " starts to fade and you are able to see through " + caster->QO + "!", caster);
                }else {
                    tell_object(caster, "%^CYAN%^You face " + target->QCN + ", the palms of your hands held towards " + target->QO + ", and continue to chant the spell.");
                    tell_object(target, "%^CYAN%^" + caster->QCN + " faces you, the palms of " + caster->QP + " hands held towards you, as " + caster->QS + " continues to chant.");
                    tell_room(place, "%^CYAN%^" + caster->QCN + " faces " + target->QCN + ", the palms of " + caster->QP + " hands held towards " + target->QO + ", as " + caster->QS + " continues to chant.", ({ caster, target }));
                }
            }else {
                tell_room(place, "%^CYAN%^A whispering sound emits from " + caster->QCN + " as the area glows with a black aura.");
            }
        }
    }
    call_out("targ_vanish", 2, prof);
}

void targ_vanish(int prof)
{
    if (!target)
    {
        tell_object(caster,"You look around, confused as to where your target went, and shrug.");
        tell_room(caster->query_cap_nam()+" looks around, and shrugs in confusion.", caster);
        TO->remove();
        return;
    }
    if ( !present(target,environment(caster)) ) {
        tell_object(caster,"You look around, confused as to where your target went, and shrug.");
        tell_room(caster->QCN+" looks around, and shrugs in confusion.", caster);
        TO->remove();
        return;
    }
    if (target->query_invis()) {
        tell_object(caster,target->QCN+" is already invisible.");
        TO->remove();
        return;
    }
    if(target->query_property("visible")){

        tell_object(caster,"The spell fails utterly on "+target->QCN+".");
        TO->remove();
        return;
    }
    spell_successful();
//    call_out("dest_effect",clevel*ROUND_LENGTH*10*prof/100);
    invisob=new("/d/magic/obj/invisob.c");
    invisob->set_property("spell",TO);
    invisob->set_property("spelled", ({TO}) );
    if((string)TO->query_spell_type() == "potion") invisob->set_property("potion",1); // to vary the messages!
    invisob->move_is_ok(1);
    invisob->move(target);
    invisob->set_prof(prof);
    invisob->move_is_ok(0);
//   if (caster != target) {
      addSpellToCaster();
//    }
    return;
}

void dest_effect()
{
    if (objectp(invisob))
    {
        invisob->show_up();
    }
    if(objectp(target))   // added this check for objectp on target 11/3/02 *Styx*
	target->remove_property("visible");
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}


void reverse_spell()
{
    target->set_property("visible",1);
    call_out("dest_effect",clevel*8);
}
