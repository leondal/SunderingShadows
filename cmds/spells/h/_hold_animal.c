#include <daemons.h>
#include <spell.h>
#include <magic.h>
inherit SPELL;

#define VALIDTYPES ({ "arachnid","dragon","equine","fowl","insectoid","insectoid-winged","quadruped","reptile","snake" })

void create() {
    ::create();
    set_spell_name("hold animal");
    set_spell_level(([ "ranger" : 2 ]));
    set_spell_sphere("enchantment_charm");
    set_syntax("cast CLASS hold animal on TARGET");
    set_description("This will magically hold most types of animals.  It will hold for longer, as your levels increase.  "
"They will be able to hear, but not look or fight.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("fort");
}

string query_cast_string() {
    string cast;

    if (interactive(CASTER)) cast = CASTER->QCN+" prays for a divine spell !";
    else cast = CASTER->QCN+" calls for divine help !";
    return cast;
}

void spell_effect(int prof) {

    if(!present(target,environment(caster))) {
      tell_object(caster,"%^BOLD%^Your target is not in this area.\n");
      dest_effect();
      return;
    }
    if(userp(target)) {
      tell_object(caster, "Your spell is harmlessly dispersed.");
      dest_effect();
      return;
    }
    if(member_array((string)target->query_body_type(),VALIDTYPES) == -1) {
      tell_object(caster, "Your spell is harmlessly dispersed.");
      dest_effect();
      return;
    }
    if (target->query_property("no hold") || target->query_property("no paralyze")) {
      tell_object(caster,"%^YELLOW%^You spell disperses futilely around "+target->QCN+".\n");
      dest_effect();
      return;
    }
    spell_successful();
    if(do_save(target,0)) {
      tell_object(caster,"%^BOLD%^%^ORANGE%^You feel your spell take a grasp on "+target->QCN+" but then disperse as its power is rendered useless!\n");
      tell_object(target,"%^BOLD%^%^ORANGE%^You feel a spell attempt to grip your mind, but the grip slips and you are freed from it.\n");
      spell_kill(target,caster);
      dest_effect();
      return;
    }
    duration = clevel/3 + 2;
    if(duration > 10) duration = 10;
    duration = duration * (ROUND_LENGTH * 2);
    target->set_paralyzed(duration,"%^BOLD%^%^CYAN%^You are magically held still. You can't move a muscle in your body.");
    tell_room(environment(caster),"%^BOLD%^%^RED%^"+caster->QCN+" looks at "+target->QCN+" and a small wave rushes forth "
"and seizes "+target->QP+" head, forcing "+target->QO+" to mimic the rigidness of iron!",({caster,target}));
    tell_object(caster,"%^BOLD%^%^RED%^You send a wave rushing toward "+target->QCN+" which seizes "+target->QP+" head, "
"forcing "+target->QO+" to mimic the rigidness of iron!\n");
    tell_object(target,"%^BOLD%^%^RED%^"+caster->QCN+" looks at you and a small wave rushes forth and seizes your head, "
"forcing you to mimic the rigidness of iron!\n");
    dest_effect();
}

void dest_effect(){
   ::dest_effect();
   if(objectp(TO)) TO->remove();
}
