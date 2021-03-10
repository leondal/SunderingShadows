//  Modified from the wizard armor spell
//  ~Circe~ 7/19/05

#include <spell.h>
#include <daemons.h>
inherit SPELL;

void dest_effect();

void create() {
    ::create();
    set_spell_name("inertial armor");
    set_spell_level(([ "psion" : 1, "psywarrior" : 1 ]));
    set_spell_sphere("abjuration");
    set_syntax("cast CLASS inertial armor");
    set_description("When a psion manifests inertial armor, his psionic energy streams through a gem, where it coalesces "
"and forms a shield about the psion.  This shield of protection offers an AC bonus that grows with the psion as his "
"mental powers grow stronger.");
    set_verbal_comp();
    set_somatic_comp();
    set_property("keywords", ({ "defensive", "targeted", "personal" }));
	set_helpful_spell(1);
}

int bonus;

void spell_effect(int prof) {

    //caster = CASTER;
    //place = PLACE;
    //clevel = CLEVEL;
    //target = TARGET;

    if (!target)
        target=caster;
    if(target != caster){
       tell_object(caster,"%^BOLD%^Your mental powers can protect "+
          "only you!");
       TO->remove();
       return;
    }
    if (target->query_property("armoured")) {
        tell_object(caster,"You cannot be protected by this power and "+
           "another armor effect.");
        TO->remove();
    }
    if (!target->is_ok_armour("mage") && target->query_class() != "psywarrior") 
    {
        tell_object(caster,"The spell can not offer protection to those wearing armor.");
        if(!objectp(TO)) return;
        TO->remove();
        return;
    }
    
    bonus = min( ({ max( ({ 4, (clevel / 2) }) ), 8 }) );
    spell_successful();
    
    if (target == caster) 
    {
        tell_object(caster,"%^BOLD%^%^GREEN%^A tangible field of force "+
            "flows from the gem and surrounds you!");
        tell_room(place,"%^BOLD%^%^GREEN%^A tangible field of force "+
            "flows from the gem and surrounds "+caster->QO+"!", caster );
    } else {
       tell_object(caster,"%^BOLD%^Your mental powers can protect "+
          "only you!");
       TO->remove();
       return;
    }
    target->add_ac_bonus(bonus);
    target->set_property("spelled", ({TO}) );
    target->set_property("armoured",1);
    addSpellToCaster();
    call_out("test", 7);
    // revoking the timer as thick skinned caster no longer exists, and constant armor effectively became the default meta. N, 5/15.
/*    if(!FEATS_D->usable_feat(caster,"thick skinned caster"))
    {
        call_out("dest_effect", 1800 + (clevel * 10));
    } */
}

//      Test for damage to the magical armor takes place every 7
//      seconds of real time.  This may need to be modified as
//      player testing may indicate.
//      Thorn 1/20/95

void test() {
    
    int max_damage, add_tally, thp;
    
    if (!objectp(target)) {
        remove();
        return;
    }

    if (!target->is_ok_armour("mage") && target->query_class() != "psywarrior") 
    {
        tell_object(caster,"The spell can not offer protection to those wearing armor.");
        TO->dest_effect();
        return;
    }
    if (!objectp(target))    // To avoid errors when player quits - Thorn
        dest_effect();
    call_out("test", 7);
    return 0;
}

void dest_effect() {
    if(objectp(target)) 
    {
        target->add_ac_bonus(-1 * bonus);
        target->remove_property_value("spelled", ({TO}) );
        tell_object(target, "%^GREEN%^The field surrounding you flickers a "+
        "few times, then dissipates.");
        tell_room(environment(target),"%^GREEN%^The field surrounding "+
        ""+target->QCN+" flickers briefly and dissipates.", target );

        target->remove_property("armoured");
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}

string query_cast_string() {
    return "%^GREEN%^"+caster->QCN+" %^RESET%^%^GREEN%^holds "+
        "a gem before "+caster->QO+", and it resonates "+
        "with energy.";
}
