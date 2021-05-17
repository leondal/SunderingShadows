/*
  _empathic_relief.c

  Cures all negative statuses on the target.

  -- Tlaloc -- 4.2.20
*/

#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;

void create()
{
    ::create();

    set_author("tlaloc");
    set_spell_name("empathic relief");
    set_spell_level( ([ "psion" : 6 ]) );
    set_spell_sphere("psychometabolism");
    set_discipline("egoist");
    set_syntax("cast CLASS empathic relief on TARGET");
    set_description("You cleanse the subject's body of unhealthy influences, relieving all debilitating conditions, including dazed, confused, stunned, blinded, paralyzed, fatigued, exhausted, sickened and will clear negative levels.");
    set_target_required(1);
    set_helpful_spell(1);
}

string query_cast_string()
{
    return "%^CYAN%^" + sprintf("%s concentrates on %s psionic powers", caster->QCN, caster->query_possessive());
}

void spell_effect(int prof)
{
    string myname, yourname;

    myname = caster->QCN;
    yourname = target->QCN;

    tell_object(caster, "%^BOLD%^" + sprintf("You pour psychic energy into %s's body, cleansing %s of all ailments.", yourname, target->query_possessive()));
    tell_object(target, "%^BOLD%^" + sprintf("%s pours psychic energy into your body, cleansing you of all ailments.", myname));
    tell_room(place, "%^BOLD%^" + sprintf("%s pours psychic energy into %s, cleansing all of %s ailments.", myname, yourname, target->query_possessive()), ({ target, caster }));

    (object)"/std/magic/cleanse"->cleanse(target);
    spell_successful();
    dest_effect();
}
