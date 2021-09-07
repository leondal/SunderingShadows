//_wave_of_pain.c
#include <std.h>
#include <daemons.h>
inherit SPELL;

void create() {
    ::create();
    set_spell_name("wave of pain");
    set_spell_level(([ "mage" : 3, "bard":3, "cleric" : 3 ]));
    set_domains("suffering");
    set_spell_sphere("illusion");
    set_syntax("cast CLASS wave of pain");
    set_damage_desc("Mental damage. Paralyzed on failed save");
    set_description("Through this spell, the caster sends out a great wave of pain that can harm, kill, and/or paralyze "
"all in its path.");
    set_verbal_comp();
    set_somatic_comp();
    set_save("will");
    splash_spell(3);
}

string query_cast_string()
{
 	tell_object(caster,"%^BOLD%^%^RED%^The air around you begins to"+
		" ripple outwards as you chant in a low prayer.");
	tell_room(place,"%^BOLD%^%^RED%^The air around "+caster->QCN+" "+
		"begins to ripple outward as "+caster->QS+" chants a "+
		"low prayer.",caster);
	return "display";
}

void spell_effect(int prof)
{
    object *inven;
    int i,j;

    inven = target_selector();

    inven -= ({caster});

    tell_room(place,"%^RED%^In a violent movement, "+caster->QCN+" thrusts "+caster->QP+" hands outward, "
        "sending a wave of pain and torturous attacks into the surrounding world.",caster);
    tell_object(caster,"%^RED%^You thrust your hands outward, sending a violet, agony filled wave "
        "into the surrounding world.");

    j = sizeof(inven);

    for (i=0;i<j;i++) {
        if (!objectp(inven[i])) continue;
        tell_object(inven[i],"%^RED%^You are struck with a horrible pain.");
        inven[i]->cause_typed_damage(inven[i], inven[i]->return_target_limb(), sdamage, "mental");
        //damage_targ(inven[i],"torso",sdamage,"mental");

        if(!do_save(inven[i],0)) {
            tell_object(inven[i],"%^RED%^The pain is too much, forcing you to your knees then "
                "to the ground writhing.");
            tell_room(place,"%^RED%^The pain is too much for "+inven[i]->QCN+", "
                "as "+inven[i]->QS+" falls to the ground writhing.",inven[i]);
            inven[i]->set_paralyzed(8 * roll_dice(1, 2),"%^BOLD%^%^BLACK%^You are writhing in torment");

        }
    }
    tell_object(caster,"%^BOLD%^%^BLACK%^Your feel a sense of satisfaction with"+
		" the pain you have inflicted.");
    caster->force_me("emote looks about with a pleased smirk.");
    dest_effect();
}

void dest_effect()
{
    ::dest_effect();
    if(objectp(TO)) TO->remove();

}
