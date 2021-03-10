#include <std.h>
#include <daemons.h>
#include <magic.h>
inherit SPELL;

object *targets;

void create() {
    ::create();
    set_spell_name("glitterdust");
    set_spell_level(([ "bard" : 2, "mage" : 2, "magus" : 2 ]));
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS glitterdust");
    set_description("This spell casts glittering dust through the air, revealing all invisible and hiding beings in the room where the caster has cast his spell, and preventing them from hiding until the dust fades.");
    set_verbal_comp();
    set_somatic_comp();
    set_heart_beat(1);
    splash_spell(3);
    set_components(([
      "mage" : ([ "ruby dust" : 1 ])
    ]));
    set_helpful_spell(1);
}

void heart_beat(){
    int i;
    if(!objectp(caster)) {
      dest_effect();
      return;
    }
    if(!sizeof(targets)) return;
    for(i=0;i<sizeof(targets);i++) {
      if(!objectp(targets[i])) continue;
      if(targets[i]->query_invis()) {
        tell_object(targets[i],"%^YELLOW%^The gleaming dust gives away your position!");
        tell_room(environment(targets[i]),"%^YELLOW%^The gleaming dust gives away "+targets[i]->QCN+"'s position!",targets[i]);
        targets[i]->set_invis(0);
      }
    }
}

string query_cast_string() {
    tell_object(caster,"%^YELLOW%^You fling a hand upwards to cast forth a spray of glittering dust, and hum a single clear note.");
    tell_room(place,"%^YELLOW%^"+caster->QCN+" flings a hand upwards to cast forth a spray of glittering dust, and hums a single clear note.",caster);
    return "display";
}

void spell_effect(int prof) {
    int duration, i;
    object *inven;
    duration = (ROUND_LENGTH) * clevel+4;

    inven = all_living(place);
    inven = filter_array(inven, "is_non_immortal",FILTERS_D);
    inven = target_filter(inven);

    tell_room(place,"%^BOLD%^%^WHITE%^The motes of dust descend to outline everything in a fine coat that s%^YELLOW%^p%^WHITE%^ark%^YELLOW%^l%^WHITE%^es with pinpoints of light!%^RESET%^");
    spell_successful();

    targets = ({});
    for(i=0;i<sizeof(inven);i++) {
      if(!inven[i]->query_property("faerie fire")) targets += ({ inven[i] });
    }

    if(!sizeof(targets)) {
      dest_effect();
      return;
    }
    for(i=0;i<sizeof(targets);i++) {
      targets[i]->set_property("faerie fire",1);
      targets[i]->set_property("spelled",({TO}));
      targets[i]->set_property("added short",({"%^YELLOW%^ (sparkling)%^RESET%^"}));
    }
    spell_duration = duration;
    set_end_time();
    call_out("dest_effect",spell_duration);
}

void dest_effect(){
    int i;
    if(sizeof(targets)) {
      for(i=0;i<sizeof(targets);i++) {
        if(!objectp(targets[i])) continue;
        tell_room(place,"%^YELLOW%^The sparkling dust finally fades from "+targets[i]->QCN+"'s skin.",targets[i]);
        tell_object(targets[i],"%^YELLOW%^The sparkling dust finally fades from your skin.");
        targets[i]->remove_property("faerie fire");
        targets[i]->remove_property_value("added short",({"%^YELLOW%^ (sparkling)%^RESET%^"}));
      }
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();

}
