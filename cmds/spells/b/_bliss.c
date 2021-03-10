// Bliss - 8/05
#include <priest.h>
#include <std.h>
#include <daemons.h>
#include <magic.h>

inherit SPELL;

void create() {
    ::create();
    set_author("cythera");
    set_spell_name("bliss");
    set_spell_level(([ "cleric" : 6 ]));
    set_spell_sphere("enchantment_charm");
    set_domains("charm");
    set_syntax("cast CLASS bliss on TARGET");
    set_description("This spell allows the caster to place a target's mind in a state of bliss.  While in the enraptured "
"blissful state the target only seems to focus on the intense pleasure and happiness that she feels, unable to attack or "
"defend herself.");
    mental_spell();
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_immunities( ({ "spell_immunity"}) );
    set_save("will");
}

int preSpell()
{
    if(!objectp(target))
    {
        tell_object(caster,"This spell requires a target.");
        return 0;
    }
    return 1;
}

string query_cast_string()
{
    tell_room(place, "%^MAGENTA%^"+caster->QCN+" cups "+caster->QP+" hands"+
	    " together, as "+caster->QS+" begins to chant an enthralling prayer.",caster);
    tell_object(caster,"%^MAGENTA%^You cup your hands together as you begin to chant.%^RESET%^");
    return "display";
}


void spell_effect(int prof)
{
    int effect, bonus;

    if(!present(target,place))
    {
        tell_object(caster,"Your target has left the area.");
        dest_effect();
        return;
    }

    if(mind_immunity_damage(target, "default"))
    {
        spell_successful();
        dest_effect();
        return;
    }

    tell_room(place,"%^MAGENTA%^"+caster->QCN+" blows into "+caster->QP+" "+
        "cupped hands as "+caster->QS+" complete the last word of the "+
        "prayer.\n %^BOLD%^%^MAGENTA%^A light breeze blows across "+
        ""+target->QCN+"'s face, as "+target->QS+" gives a blissfilled"+
        " grin.",({caster,target}));
    tell_object(caster,"%^MAGENTA%^Blowing into your cupped hands, you "+
        "complete the last word of the prayer.\n%^BOLD%^%^MAGENTA%^A "+
        "light breeze passes through your fingers as it carsses "+
        ""+target->QCN+"'s face.  A blissfilled grin crosses "+target->QS+"'s"+
        " face.");
    tell_object(target,"%^BOLD%^%^MAGENTA%^A light breeze caresses your"+
        " face, bringing with it some of the most blissful experiences"+
        " imaginable.  You find yourself wrapped up in the emotions.");

    if(do_save(target,0))
	//if(!SAVING_D->saving_throw(target,"paralyzation_poison_death",0))
    {
//		target->set_paralyzed((roll_dice(3,4)+(clevel/10)),"%^RED%^You just smile,"+
//		    " enjoying the pure bliss that fills your mind.");
		target->set_paralyzed((roll_dice(3,4)+(clevel/2)),"%^RED%^You just smile,"+
		    " enjoying the pure bliss that fills your mind."); //modified as sitting between hold person and PWS, for L5 spell. Roughly 2 rounds for save at L40. N, 4/11.
	}
    else
    {
//	    	target->set_paralyzed((roll_dice(3,6)+(clevel/5)),"%^RED%^You just smile,"+
//		    " enjoying the pure bliss that fills your mind.");
	    	target->set_paralyzed((roll_dice(3,6)+clevel),"%^RED%^You just smile,"+
		    " enjoying the pure bliss that fills your mind."); //modified as sitting between hold person and PWS, for L5 spell. Roughly 5 rounds for no save at L40. N, 4/11.
	}

	target->set_property("added short",({"%^BOLD%^%^MAGENTA%^ (smiling blissfully)"}));
    spell_successful();
  	dest_effect();
}

void dest_effect()
{
    if(objectp(target))
    {
        target->remove_property_value("added short",({"%^BOLD%^%^MAGENTA%^ (smiling blissfully)"}));
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
