//Updated to hit more often - should be a bit more balanced
//and useful now.  ~Circe~ 5/12/08 with the rebalancing of
//domains
// lightning touch based on Searing
//Light by saide - 8/05

#include <priest.h>
#include <std.h>
#include <daemons.h>

inherit SPELL;

void create() {
    ::create();
    set_author("cythera");
    set_spell_name("lightning touch");
    set_spell_level(([ "cleric" : 2, "cleric":2]));
    set_spell_sphere("invocation_evocation");
    set_domains("storms");
    set_syntax("cast CLASS lightning touch on TARGET");
    set_description("Wrapping their hand with crackling bolts of lightning, with this spell the caster tries to deliever "
"a shocking attack onto a foe.  If the caster fails to touch the target, the lighting dispurses into a flashy, but "
"harmless effect.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_immunities( ({ "spell_immunity"}) );
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
    tell_room(place, "%^YELLOW%^Crackling bolts of lightning surrounds "+caster->QCN+"'s"+
		" hand!",caster);
    tell_object(caster,"%^YELLOW%^Crackling bolts of lightning surround"+
		" your hand!%^RESET%^");
    return "display";
}

spell_effect(int prof)
{
    int effect,bonus;

    if(!objectp(caster))
    {
        dest_effect();
        return;
    }

    if(!present(target,place))
    {
        tell_object(caster,"%^BOLD%^Your target has left the area!%^RESET%^");
        dest_effect();
        return;
    }

    if(caster->Thaco(1,target,0) <= roll_dice(1,20) && ! caster->query_property("spectral_hand")) {
//changed check to hit to above - it never seemed to hit before
//~Circe~ 5/12/08
	    tell_object(caster,"%^YELLOW%^The crackling lightning around your hand"+
		    " flashes and fades away as"+
		    " you fail to touch "+target->QCN+".%^RESET%^");
     	tell_room(place,"%^YELLOW%^The crackling lightning around"+
            " "+caster->QCN+"'s hand flashes as it disperses after"+
		    " "+caster->QS+" fails to touch "+target->QCN+"."+
		    "%^RESET%^",({target,caster}));
        tell_object(target,"%^YELLOW%^The crimson flames around "+caster->QCN+"'s"+
		    " hand fades away as "+caster->QS+" fails to touch you!%^RESET%^");
        dest_effect();
        return;
    }

    tell_room(place,"%^YELLOW%^Crackling arcs of lightning leap from"+
        " "+caster->QCN+"'s hand and into "+target->QCN+"."+
        "%^RESET%^",({caster,target}));
    tell_object(caster,"%^YELLOW%^Crackling arcs of lightning leap from"+
        " your hand and into "+target->QCN+".%^RESET%^");
    tell_object(target,"%^YELLOW%^Crackling arcs of lightning leap from"+
        " "+caster->QCN+"'s hand"+
        " and into you!%^RESET%^");

    damage_targ(target,target->return_target_limb(),sdamage,"electricity");
    spell_kill(target,caster);
    spell_successful();
    dest_effect();

}

void dest_effect()
{
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
