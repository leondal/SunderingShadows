//Made 3rd level, AC bonus lowered, and attack bonus made
//to scale with level.  ~Circe~ 5/25/08 rebalancing domains
// foresight
#include <std.h>
#include <daemons.h>
#include <magic.h>

inherit SPELL;

int bonus,attk_bonus;

void create() {
    ::create();
    set_author("ares");
    set_spell_name("insight");
    set_spell_level(([ "cleric" : 3 ]));
    set_spell_sphere("divination");
    set_syntax("cast CLASS insight on TARGET");
    set_bonus_type("insight");
    set_damage_desc("+2 AC, +2 Attack.");
    set_description("This spell grants the target a second's insight into the future, allowing her to both avoid attacks "
"better, and to hit her targets better.  The spell is more effective when used by a priest that is solely dedicated to "
"her faith. This spell does not stack with the foresight spell.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
	set_helpful_spell(1);
}

string query_cast_string()
{
   	tell_object(caster,"%^BOLD%^%^CYAN%^Pressing your fingers to "+
		"your temples, you begin to chant in a rhythmic tone.");
	tell_room(place,"%^BOLD%^%^CYAN%^"+caster->QCN+" presses "+
		""+caster->QP+" fingers to "+caster->QP+" temples as"+
		" "+caster->QS+" begins to chant in a rhythmic tone.",caster);
    return "display";
}

int preSpell()
{
    if(!objectp(target))
    {
        tell_object(caster,"This spell requires a target.");
        return 0;
    }
    /*
    if(target->query_property("foresight")){
        tell_object(caster,"The target has already been given the gift of "
            "foresight.");
        return 0;
    }
    */

    return 1;
}

void spell_effect(int prof){
    int duration;
    duration = (ROUND_LENGTH * 20) * clevel;
    bonus = 2;
    //attk_bonus = clevel/8;
    attk_bonus = 2;
    if(!present(target,place)){
        tell_object(caster,"Your target has left the area.");
        dest_effect();
        return;
    }
    if(target == caster){
        tell_room(place,"%^BOLD%^%^CYAN%^Opening "+caster->QP+" eyes, "+caster->QCN+" "+
            "wears a knowledgeable look upon "+caster->QP+" face.",target);
        tell_object(target, "%^BOLD%^%^CYAN%^A tingling sensation moves through"+
            " your mind, with it a feeling of foresight is gained.");
    }else{
        tell_object(caster,"%^BOLD%^%^CYAN%^You touch "+target->QCN+" forehead and ask for "
            "the gift of foresight.");
        tell_object(target,"%^CYAN%^%^BOLD%^"+caster->QCN+" touches your forehead.\n A"+
            " tingling sensation moves through you mind, with it a feeling "+
            "of foresight is gained.");
        tell_room(place,"%^BOLD%^%^CYAN%^"+caster->QCN+" touches "+target->QCN+"'s forehead "
            "and as "+caster->QS+" finishes the last words of the prayer.",({target,caster}));
    }
    target->add_ac_bonus(bonus);
    spell_successful();
    target->add_attack_bonus(attk_bonus);
    //target->set_property("foresight",1);
    target->set_property("spelled",({TO}));
    addSpellToCaster();
    spell_duration = duration;
    set_end_time();
    call_out("dest_effect",spell_duration);

}

void dest_effect()
{
    if(objectp(target))
    {
        tell_object(target,"%^BOLD%^%^CYAN%^The sense of foresight fades.%^RESET%^");
        //target->remove_property("foresight");
        target->add_ac_bonus(-bonus);
        target->add_attack_bonus(-attk_bonus);
    }
    ::dest_effect();
   if(objectp(TO)) TO->remove();
}
