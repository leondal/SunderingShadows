#include <priest.h>
#include <magic.h>
#include <spell.h>

inherit SPELL;

int timer,flag,stage,toggle,counter;

void create(){
    ::create();
    set_author("ares");
    set_spell_name("blade barrier");
    set_spell_level(([ "cleric" : 6, "inquisitor" : 6, "oracle" : 6 ]));
    set_mystery("metal");
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS blade barrier");
    set_description("This spell surrounds the caster in a protective whirlwind of spinning, razor sharp blades.  The "
"blades will follow the caster wherever they go and inflict damage on any enemies that get too close.  The amount of "
"blades in the air depends on the level of the caster.");
    set_property("magic",1);
    set_casting_time(1);
    set_helpful_spell(1);
    traveling_aoe_spell(1);
}

string query_cast_string(){
    tell_object(caster,"%^BOLD%^%^CYAN%^Invoking a quick prayer, "+
		"you curl your fingers as you extend your hands outwards.");
    tell_room(place,"%^BOLD%^%^BLACK%^"+caster->QCN+" begins to "+
               "invoke a quick prayer as "+caster->QP+" fingers curl "+
		"while "+caster->QS+" extends "+caster->QP+" hands outwards.",caster);
    return "display";
}

int preSpell(){
    if(caster->query_property("blade barrier")){
        tell_object(caster,"You are already protected by a blade barrier.");
        return 0;
    }
    return 1;
}

void spell_effect(int prof){
     tell_room(place,"%^BOLD%^%^BLACK%^"+caster->QCN+" growls an incantation to "+caster->QP+" deity "
       "and the sound of thousands of whirling blades fills the air as "
        ""+caster->QS+" is encased in a protective barrier of blades!",caster);
    tell_object(caster,"%^BOLD%^%^BLACK%^You growl an incantation to your deity and the sound "
        "of thousands of whirring blades surrounds you as you are encased "
        "in their protective barrier!");
    caster->set_property("spelled", ({TO}));
    caster->set_property("blade barrier",1);
    caster->set_property("added short",({"%^CYAN%^ (encircled by blades)%^RESET%^"}));
    addSpellToCaster();
    spell_successful();
    counter = 8*clevel;
    execute_attack();
    call_out("room_check",ROUND_LENGTH);
}

void room_check()
{
    if(!objectp(caster) || !objectp(ENV(caster)))
    {
        dest_effect();
        return;
    }

    prepend_to_combat_cycle(ENV(caster));

    call_out("room_check",ROUND_LENGTH*2);
    return;
}

void execute_attack(){
    object *foes=({}),targ;
    int i;

    if(!flag)
    {
        flag = 1;
        ::execute_attack();
        return;
    }

    if(!objectp(caster))
    {
        dest_effect();
        return;
    }

    if(!objectp(ENV(caster)))
    {
        dest_effect();
        return;
    }

    place = ENV(caster);

    if(!objectp(place) || counter<0)
    {
        dest_effect();
        return;
    }

    foes = caster->query_attackers();

    if (sizeof(foes)) {
        define_base_damage(0);    //reroll each turn

        tell_object(caster, "%^BOLD%^%^BLACK%^Your spinning blades tear into your enemies as they get too close!");
        tell_room(place, "%^BOLD%^%^BLACK%^" + caster->QCN + "'s spinning blades tear into " + caster->QP + " enemies as they get too close!", caster);
        define_base_damage(0);
        for (i = 0; i < sizeof(foes); i++) {
            if (!objectp(foes[i])) {
                continue;
            }
            damage_targ(foes[i], foes[i]->return_target_limb(), sdamage, "fire");
        }
    }
    prepend_to_combat_cycle(place);
    counter--;
}

void dest_effect()
{
    remove_call_out("room_check");
    if (objectp(caster)) {
        tell_room(environment(caster), "%^CYAN%^The spinning blades surrounding " + caster->QCN + " slow "
                  "and then dissipate.", caster);
        tell_object(caster, "%^CYAN%^The spinning blades surrounding you slow and then fade away.");
        caster->remove_property("blade barrier");
        caster->remove_property_value("added short", ({ "%^CYAN%^ (encircled by blades)%^RESET%^" }));
    }
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
