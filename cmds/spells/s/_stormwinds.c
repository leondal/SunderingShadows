//altered to make it a little more viable (not hit non-hostile creatures) Circe 3/23/05
// Winds of Akadi
// changed to stormwinds -Ares
#include <std.h>
#include <daemons.h>

inherit SPELL;

int count;

void create() {
    ::create();
    set_spell_name("stormwinds");
    set_spell_level(([ "cleric" : 5, "druid":5, "oracle" : 5 ]));
    set_mystery("wind");
    set_spell_sphere("elemental air");
    set_domains("storms");
    set_syntax("cast CLASS stormwinds on TARGET");
    set_description("This spell causes a great sphere of swirling winds to appear around the target. Lightning bolts "
"come forth from the mass of air to strike them.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("reflex");
}

string query_cast_string()
{
	tell_object(caster,"%^BLUE%^Raising your hands up in front of you, "+
		"you begin to call on the power of storms!");
	tell_room(place,"%^BLUE%^"+caster->QCN+" raises "+caster->QP+" hands "+
		"up in front of "+caster->QO+" and calls on the power of storms!",caster);
	return "display";
}

int preSpell()
{
    if(!objectp(target))
    {
        tell_object(caster,"This spell requires a target.");
        return 0;
    }
    if (place->query_property("underwater"))
    {
        tell_object(caster,"%^BOLD%^That spell can only be cast in the air, not underwater.");
        return 0;
    }
    if (caster->query_property("winds"))
    {
        tell_object(caster,"%^BOLD%^You cannot control a second mass of whirling wind.");
        return 0;
    }
    return 1;
}

void spell_effect(int prof)
{
    int i;
    object *who;

    if (!objectp(target) || !objectp(caster) || !objectp(place)) {
        dest_effect();
        return;
    }
    if (!present(target,place)) {
        tell_object(caster,"%^BOLD%^Your target has left the area.");
        dest_effect();
        return;
    }
    caster->set_property("winds",1);
    tell_object(place,"%^BOLD%^%^BLUE%^The wind begins to whirl around the area, picking up dust and small rocks.");
//    who = all_living(place);
    who = caster->query_attackers();
    who = filter_array(who, "is_non_immortal",FILTERS_D);

    for (i=0;i<sizeof(who);i++) {
        if (!objectp(who[i])) continue;
        if (who[i] == caster) continue;
        if(!do_save(who[i],0)) {
	    //if (!(SAVING_D->saving_throw(who[i], "spell",0))) {
            tell_object(who[i],"%^BOLD%^The air whirling around you causes some small objects to hit you.");
            damage_targ(who[i],"torso",sdamage/2,"bludgeoning");
        }
    }
    count = 0;
	addSpellToCaster();
    call_out("do_lightning",3);
}

void do_lightning() {
    int dam,i;

    if (!objectp(target) || !objectp(caster) || !objectp(environment(target))) {
        dest_effect();
        return;
    }
    if (target->query_ghost() || caster->query_ghost() || caster->query_unconscious()) {
        dest_effect();
        return;
    }
    if (environment(target)->query_property("underwater")) {
        dest_effect();
        return;
    }
// moved up here from below *Styx*, 12/31/03
    if (environment(caster) != environment(target)) {
	tell_object(environment(target),"%^BOLD%^%^BLUE%^The swirling winds calm back to normal.");
        tell_object(caster,"%^BOLD%^%^BLUE%^The swirling winds calm back to normal.");
        dest_effect();
        return;
    }

    dam = sdamage/2;
    tell_object(target,"%^YELLOW%^A lightning bolt streaks toward you from the swirling mass of air!");
    tell_room(environment(target),"%^YELLOW%^A lightning bolt streaks toward "+target->QCN+" from the swirling mass of air!",({target}));
    if(!do_save(target,-4)) {
    //if (!(SAVING_D->saving_throw(target, "spell",-4))) {
        damage_targ(target,"torso",dam,"electricity");
    } else {
        damage_targ(target,"torso",dam/2,"electricity");
    }
    count++;
     if(!objectp(target)) {
          dest_effect();
          return;
     }
    if (count == (clevel/5)) {
        tell_object(environment(target),"%^BOLD%^%^BLUE%^The swirling winds calm back to normal.");
/* this not kicking in here until too late, so I'm moving it up *Styx*, 12/31/03, last change 6/24/01
        if (environment(caster) != environment(target))
            tell_object(caster,"%^BOLD%^%^BLUE%^The swirling winds calm back to normal.");
*/
        dest_effect();
        return;
    } else {
        call_out("do_lightning",4);
    }
}

void dest_effect()
{
	if(objectp(caster))
	{
		caster->remove_property("winds");
	}
      remove_call_out("do_lightning");
    	::dest_effect();
      if(objectp(TO)) TO->remove();
}
