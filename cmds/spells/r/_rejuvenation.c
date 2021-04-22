#include <std.h>
#include <clock.h>
#include <magic.h>

inherit SPELL;

int duration;

void create(){
    ::create();
    set_spell_name("rejuvenation");
    set_spell_level(([ "cleric" : 3, "druid" : 3 ]));
    set_spell_sphere("healing");
    set_domains("renewal");
    set_syntax("cast CLASS rejuvenation [on TARGET]");
    set_damage_desc("fast healing 2");
    set_description("This spell will grant the caster the power of renewal, giving him a small amount of healing each round for a long period of time.");
    set_verbal_comp();
    set_property("magic",1);
	set_helpful_spell(1);
}

string query_cast_string(){
   tell_object(caster,"%^ORANGE%^With a touch of your holy symbol, you "+
      "begin a worshipful prayer to "+(string)caster->query_diety()+" "+
      "to help heal you.%^RESET%^");
   tell_room(place,"%^ORANGE%^"+caster->QCN+" touches "+caster->QP+" "+
      "holy symbol and calls upon "+caster->QP+" deity's "+
      "blessings!%^RESET%^",caster);
    return "display";
}

int preSpell()
{
    if(!target)
        target = caster;
    if(target->query_property("rejuvenation"))
    {
        tell_object(caster,"%^BOLD%^%^WHITE%^You feel your spell repelled...");
        return 0;
    }
    return 1;
}

void spell_effect(int prof){
    int duration = clevel * ROUND_LENGTH * 10;
    if(!target)
        target = caster;

    if(!objectp(target))
    {
        TO->remove();
        return;
    }
    if(!objectp(caster))
    {
        TO->remove();
        return;
    }

    tell_room(place,"%^BOLD%^%^ORANGE%^A radiant light bathes "+target->QCN+" briefly.");
    target->set_property("spelled",({TO}));
    target->set_property("fast healing",2);
    target->set_property("kiss_of_feywild",1);
    target->set_property("rejuvenation",1);
    spell_successful();
    addSpellToCaster();
    spell_duration = duration;
    set_end_time();
    call_out("dest_effect",spell_duration);

}



void dest_effect()
{
    if(objectp(target))
    {
        tell_object(target,"%^BOLD%^%^ORANGE%^The elation the light gave fades.%^RESET%^");
        target->remove_property_value("spelled", ({TO}) );
        target->set_property("fast healing",-2);
        target->remove_property("rejuvenation");
    }
    ::dest_effect();
    if(objectp(TO))
        TO->remove();
}
