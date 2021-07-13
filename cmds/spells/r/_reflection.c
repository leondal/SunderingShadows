// duration on all scrying spells (and between-cast delays where relevant) rebalanced. Nienne, 5/15.
#include <std.h>
inherit SPELL;

object reflection,remote,room,control;
string theName;

#define DELAY 10
#define SCRY_D "/daemon/ic_scry_locate_d"

void create()
{
    ::create();
    set_spell_name("reflection");
    set_spell_level(([ "druid" : 7 ]));
    set_spell_sphere("divination");
    set_syntax("cast CLASS reflection");
    set_description("This spell will allow the druid to look through any sufficiently still body of water and view people at a distance. The spell need a smoment of rest before used again.

When scrying, use %^ORANGE%^<help reflection>%^RESET%^ to read instructions on how to use magical puddle.

%^BOLD%^%^RED%^See also%^RESET%^ reflection *feats");
    set_verbal_comp();
    set_somatic_comp();
    //set_arg_needed();
}


int preSpell()
{
    if(caster->query_property("remote scrying"))
    {
        tell_object(caster,"You are already looking upon someone from afar.");
        return 0;
    }
    if(avatarp(caster)) return 1; // let avatars use to follow players regardless of timer.
    if(((int)caster->query_property("remote scrying time") + DELAY) > time())
    {
        tell_object(caster,"You need more time to prepare before you can peer through the reflection again.");
        return 0;
    }

    if(caster->query("no pk")){
        tell_object(caster,"%^YELLOW%^You are unable to scry while you have a %^MAGENTA%^NoPK %^YELLOW%^flag.%^RESET%^");
        return 0;
    }

    if(!place->query_property("fill waterskin"))
    {
        tell_object(caster,"You can't find the right sort of water here.");
        return 0;
    }

    return 1;
}


string query_cast_string()
{
    tell_object(caster,"%^BLUE%^You drop a single pebble into the water and as the ripples spread outwards, the surface becomes as smooth as glass.");
    tell_room(place,"%^BLUE%^"+caster->QCN+" drops a single pebble into the water and as the ripples spread outwards, the surface becomes as smooth as glass.",caster);
    return "display";
}


void spell_effect(int prof) {
    int bonus,power,myduration;

    if(!place->query_property("fill waterskin")) {
        tell_object(caster,"%^BOLD%^You can't find the right sort of water here.");
        dest_effect();
        return;
    }

    tell_room(place,"%^BLUE%^You watch quietly as an image begins to appear in the mirror smoth surface of the water.");
    tell_object(caster,"Please type help reflection for instructions on how to use the reflection.");

    room = environment(caster);
    bonus = calculate_bonus(caster->query_stats(get_casting_stat()));
    power = clevel + random(6) + bonus;

    control = new("/d/magic/obj/scry_control.c");
    control->set_observer(caster);
    control->set_parent(TO);
    control->set_scry_power(power);
    control->set_alias("reflection");
    control->move(room);

    myduration = 60+(clevel*10);
    if(myduration > 300) myduration = 300; // capping at 5min since this is free vs mages/psions that pay; this ensures only 50% uptime.
    spell_duration = myduration;
    set_end_time();
    call_out("dest_effect",spell_duration);
    caster->set_property("remote scrying",1);

    addSpellToCaster();
    call_out("check",3);

    return;

    tell_object(caster,"Your power goes unfocused.");
}


void dest_effect()
{
    remove_call_out("check");
    if(objectp(caster)) {
      caster->remove_property("remote scrying");
      caster->remove_property("remote scrying time");
      caster->set_property("remote scrying time",time());
    }
    if(objectp(control))
	{
		if(!query_property("scry_ob_destroying"))
		{
		//hopefully to get rid of the too deep recursion error of this calling
		//destruct in the scry ob, which calls dest here and a vicious cycle results :P - Saide
			control->set_property("parent_destroying", 1);
			control->self_destruct();
		}
	}
    ::dest_effect();
    if(objectp(TO)) TO->remove();

}

void check()
{
    if(objectp(TO) && objectp(caster))
    {
        if(environment(caster) != room)
        {
            tell_object(caster,"%^YELLOW%^You move away and the reflection in the water fades away.");
            dest_effect();
            return;
        }
    	call_out("check",3);
	}
}
