// Call lightning
// Pator@Shadowgate
// 11/06/95

#include "priest.h"
#include <std.h>
#include <daemons.h>

inherit SPELL;

void create() {
    ::create();
    set_spell_name("call lightning");
    set_spell_level(([ "druid" : 3 ]));
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS call lightning on TARGET");
    set_description("This is a destructive spell that could hurt an opponent very badly!  The higher level the caster is "
        "the more devastating this spell will become.  The spell can now be used anywhere, regardless of weather or if the caster is indoors. "
        "A cleric with the storms domain can cast this spell innately by spending one Divine Grace point.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_immunities( ({ "spell_immunity"}) );
}

string query_cast_string() {
    string cast;
    cast = "%^BOLD%^%^YELLOW%^"+caster->QCN+" accumulates lots of energy in "+caster->QP+" hands !";
    return cast;
}

int preSpell() {

   /* if (place->query_property("indoors")) {
        tell_object(caster,"This spell can not be cast from in here!");
        return 0;
    }
    if ((string)WEATHER_D->Check_Weather(caster) == "%^BOLD%^%^CYAN%^It is clear.") {
        tell_object(caster,"There are no clouds from which to summon lightning!");
        return 0;
    }
   if(place->query_property("no lightning")) {
      tell_object(caster,"You cannot summon lightning from here!");
      return 0;
   }

    if(caster->is_class("cleric"))
    {
        if(!(int)USER_D->spend_pool(this_player(), 1, "grace"))
        {
            tell_object(caster, "You don't have the Divine Grace to cast Call Lightning!");
            return 0;
        }
    }
    */

    return 1;
}

void spell_effect(int prof)
{

    if(!objectp(caster) || !objectp(target))
    {
        dest_effect();
        return;
    }

    place = environment(caster);

    if (environment(target)!=place)
    {
        tell_object(caster,"%^BOLD%^Your target has left the area!");
        dest_effect();
        return;
    }

    spell_successful();
    tell_room(place,"%^BOLD%^%^YELLOW%^From the gathering clouds over head, "+caster->QCN+" calls forth powers of heaven.",caster);
    tell_object(caster,"%^BOLD%^%^YELLOW%^Your god kindly allows you to call forth the powers of heaven!\n");

    tell_room(place,"%^BOLD%^%^YELLOW%^From above the gods grant power to "+caster->QCN+" as "+caster->QS+" calls a bolt of lightning down upon "+target->QCN+"!",({caster,target}));
    tell_object(target,"%^BOLD%^%^YELLOW%^You watch as "+caster->QCN+"'s god sends a bolt of lightning down upon you!\n");
    tell_object(caster,"%^BOLD%^%^YELLOW%^You give thanks to your god as it sends a bolt of lightning down upon "+target->QCN+"!\n");

    damage_targ(target,target->return_target_limb(),sdamage,"electricity");

    dest_effect();
}

void dest_effect()
{
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
