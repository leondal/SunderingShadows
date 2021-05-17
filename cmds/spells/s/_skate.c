//adapted from fly/levitate for psywarriors - personal only
//~Circe~ 9/27/15

#include <spell.h>
#include <magic.h>
#include <rooms.h>
#include <daemons.h>
inherit SPELL;

string message_out,message_in;
int mylevel;

void create() {
    ::create();
    set_author("circe");
    set_spell_name("skate");
    set_spell_level(([ "psywarrior" : 1, "psion" : 1,]));
    set_spell_sphere("psychometabolism");
    set_syntax("cast CLASS skate");
    set_description("This power gives the psionic character the ability "
       "to skate smoothly over the ground, exerting little energy. The "
       "caster will find traveling over long distances to be very easy "
       "when under the influence of this spell, and will use very little "
       "stamina to travel.\n\nPlease note: This spell will remove your "
       "previously set enter and exit messages.  If you had these set previously, you may "
       "need to reset them after using the skate power.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}

int preSpell() {
	if(caster->query_in_vehicle()) {
		tell_object(caster,"You can't cast this while mounted.");
		return 0;
	}
    if((int)caster->query_property("flying"))
    {
        tell_object(caster,"You are already skating!");
        return 0;
    }
    return 1;
}


void spell_effect(int prof)
{
    int duration;

    mylevel = clevel;

    duration = (ROUND_LENGTH * 10) * mylevel;
    tell_object(caster,"%^RESET%^%^CYAN%^You direct your mental energies "
                "toward your legs, preparing to glide across the ground.%^RESET%^");
    tell_room(place,"%^RESET%^%^CYAN%^The air around "+caster->QCN+"'s feet "
              "begins to shimmer as "+caster->QS+" manifests a power.%^RESET%^",caster);
    caster->set_property("flying",1);
    caster->set_property("spelled", ({TO}) );
    caster->set_property("endurance",(mylevel/10));
    //commenting out to fix enter/exit message bug Odin 2/21/2020
    //caster->set_property("MIN","$N glides in.");
    //caster->set_property("MOUT","$N glides off to the $D.");
    caster->set_property("added short",({"%^BOLD%^%^BLUE%^ (hovering)%^RESET%^"}));
    addSpellToCaster();
    spell_successful();
    spell_duration = duration;
    set_end_time();
    call_out("dest_effect",spell_duration);
}

void dest_effect(){
    if(objectp(caster)){
        tell_object(caster,"%^BOLD%^%^BLUE%^As your concentration wanes, "
           "your feet return to the ground.%^RESET%^");
        tell_room(environment(caster),"%^BOLD%^%^BLUE%^"+caster->QCN+"'s feet return to the ground.%^RESET%^", caster);
        caster->set_property("flying", -1);
        caster->set_property("endurance", (-1 * (mylevel / 10)));
        caster->remove_property_value("added short",({"%^BOLD%^%^BLUE%^ (hovering)%^RESET%^"}));
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
