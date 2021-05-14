#include <spell.h>
#include <magic.h>
#include <daemons.h>
#define SCRY_D "/daemon/ic_scry_locate_d"
inherit SPELL;

object blocker;

void create() {
    ::create();
    set_author("nienne");
    set_spell_name("heart of the wild");
    set_spell_level(([ "ranger" : 4 ]));
    set_spell_sphere("alteration");
    set_syntax("cast CLASS heart of the wild");
    set_description("A ranger powerful enough to know this spell will find they can use it to truly become a part of the "
"wilderness, so much so that magical means of scrying will fail to distinguish them apart from the nature that surrounds "
"them.  Leaving natural surroundings, however, will sever the bond between ranger and wild, and cause the spell to cease "
"functioning.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}

string query_cast_string() {
   return "%^CYAN%^"+caster->QCN+"%^RESET%^%^CYAN%^ spreads "+caster->QP+" arms "
"wide, and "+caster->QP+" eyes glaze over.%^RESET%^";
}

void spell_effect(int prof) {
    int num, wis_bonus, duration;
    object temp;
    ::spell_effect();

    if(temp = caster->query_property("block scrying")) {
      if(!objectp(temp)) caster->remove_property("block scrying");
      else {
        tell_object(caster,"You are already protected from scrying attempts!");
        TO->remove();
        return;
      }
    }
    if(isCivilization(place->query_terrain())) {
        tell_object(caster,"%^GREEN%^You try to draw yourself into the weave of "
"the wilderness, but there is just not enough natural energy here to do so.");
        tell_room(place,"%^GREEN%^"+caster->QCN+" lowers "+caster->QP+" arms "
"and looks around.",caster);
        TO->remove();
        return;
    }

    tell_room(place,"%^RESET%^%^GREEN%^For a brief moment, "+caster->QCN+
" %^RESET%^%^GREEN%^fades into nothing more than a translucent %^BOLD%^green "
"%^RESET%^%^GREEN%^outline.  Then "+caster->QS+" looks up, and is suddenly of "
"normal appearance again.",caster);
    tell_object(caster,"%^GREEN%^You calm yourself and meld into the weave of "
"nature around you, hiding yourself among the energies of the wilderness.");

    caster->set_property("spelled",({TO}));
    blocker = SCRY_D->add_block_scrying(caster);
    if(!objectp(blocker)) {
        tell_object(caster,"Something is wrong that "
            "a wiz might want to look at!");
        dest_effect();
        return;
    }
    wis_bonus = calculate_bonus(caster->query_stats(get_casting_stat()));
    blocker->set_block_power(CLEVEL + wis_bonus + random(6));
    blocker->set_ranger_block(1);
    addSpellToCaster();
    spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH * 2;
    set_end_time();
    call_out("dest_effect",spell_duration);
    return;
}

void dest_effect()
{

  if(objectp(caster))
  {
    tell_object(caster,"%^GREEN%^%^BOLD%^Your protection from scrying fades.");
    caster->remove_property_value("spelled", ({TO}) );
  }
  if(objectp(blocker)) blocker->self_destruct();
  ::dest_effect();
  if(objectp(TO)) TO->remove();
}
