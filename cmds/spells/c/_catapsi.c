#include <daemons.h>
#include <spell.h>
#include <std.h>
#include <magic.h>

inherit SPELL;

int count;

void create() {
    ::create();
    set_spell_name("catapsi");
    set_spell_level(([ "psion" : 5, "psywarrior" : 5 ]));
    set_spell_sphere("telepathy");
    set_syntax("cast CLASS catapsi on TARGET");
    set_description("This power can be one of the deadliest in the psion's arsenal, though it causes very little damage.  "
"By manifesting this power, the psion causes a white noise to resonate in the mind of his target, leaving the target "
"unable to think, cast spells, or manifest powers.  This power is rightly feared by psions and mages all over the "
"realms.");
    set_immunities( ({ "spell_immunity"}) );
    mental_spell();
    set_target_required(1);
    set_save("will");
}

string query_cast_string() {
    return "%^RESET%^%^MAGENTA%^"+caster->QCN+" spreads "+caster->QP+" arms wide, "+
       "palms up.%^RESET%^";
}

void spell_effect(int prof)
{
    int bonus;

    tell_room(place,"%^BOLD%^%^BLUE%^A low humming surrounds "+caster->QCN+", "+
        "focusing itself on "+target->QCN+"!%^RESET%^",({caster,target}));
    tell_object(caster,"%^BOLD%^%^BLUE%^You create an intense humming and "+
        "direct its energy towards "+target->QCN+"!%^RESET%^");

    if(!do_save(target,0))
    { // revoking the old bonus; the d20 in saving throw rolls should be more than enough -Nienne

        if(mind_immunity_damage(target, "default"))
        {
            spell_successful();
            dest_effect();
            return;
        }

        spell_successful();
        damage_targ(target,"head",roll_dice(1,clevel),"mental");
        tell_object(target,"%^BOLD%^%^CYAN%^A deafening %^WHITE%^white noise %^CYAN%^floods your "+
            "mind, making it impossible to think!%^RESET%^");
        tell_object(caster,"%^BOLD%^%^CYAN%^"+target->QCN+" has fallen prey to "+
            "your psychic noise!%^RESET%^");
        if(interactive(target))
        {
            target->set_static("spell interrupt","%^BOLD%^%^BLUE%^You "+
                "can't concentrate on anything with that noise in your mind!%^RESET%^");
        }
        else
        {
            target->set_property("spell interrupt","%^BOLD%^%^BLUE%^You "+
                "can't concentrate on anything with that noise in your mind!%^RESET%^");
        }
        call_out("next",ROUND_LENGTH,target);
        return;
    }

    spell_successful();
    tell_object(target,"%^RESET%^%^MAGENTA%^A low humming fills your mind, but "+
        "you fight off its power!%^RESET%^");
    tell_object(caster,"%^RESET%^%^MAGENTA%^"+target->QCN+" seems to have "+
        "resisted your power!%^RESET%^");
    target->add_attacker(caster);
    dest_effect();
    return;
}



void next()
{
    int enough;
    int i;
    enough = (clevel/11) +1;
//no more than 4 rounds - duration on this was impossible for something that can be recast. Nienne, 04/10
    count++;
    if(count > enough){
       dest_effect();
       return;
    }
    tell_object(target, "The noise in your mind is almost "+
       "unbearable!");
    call_out("next",ROUND_LENGTH);
    return;
}

void dest_effect(){
    remove_call_out("next");
    if(objectp(target)){
       tell_object(target, "The noise finally lifts from your mind, "+
          "leaving you able to think again!");
       target->set_static("spell interrupt",0);
       target->remove_property("spell interrupt");
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
