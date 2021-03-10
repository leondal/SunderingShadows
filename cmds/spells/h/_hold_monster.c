// Modified by Pator@Shadowgate
// August 25 1995

#include <daemons.h>
#include <spell.h>
#include <magic.h>

inherit SPELL;

void create() {
    ::create();
    set_spell_name("hold monster");
    set_spell_level(([ "mage" : 4, "bard" : 4, "magus" : 4, "inquisitor" : 4 ]));
    set_spell_sphere("enchantment_charm");
    set_syntax("cast CLASS hold monster on TARGET");
    set_description("This will magically hold most types of monsters.  It will hold for longer, as your levels increase.  "
"They will be able to hear, but not look or fight.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("fort");
}

string query_cast_string() {
    string cast;

    if (interactive(CASTER))
        cast = CASTER->QCN+" prays for a divine spell !";
    else
        cast = CASTER->QCN+" calls for divine help !";
    return cast;
}

void spell_effect(int prof) {
    int change=-2;
    int duration,level;

    //if (clevel >20) clevel = 20;
    if (target->query_body_type())
        if (member_array((string)target->query_body_type(),VALID_BACKS) == -1) {
            tell_object(caster, "Your spell is harmlessly dispersed.");
            TO->remove();
            return;
        }
    if (!present(target,environment(caster))) {
        tell_object(caster,"%^BOLD%^Your target is not in this area.\n");
        TO->remove();
        return;
    }
   if (target->query_property("no hold") || target->query_property("no paralyze")) {
       tell_object(caster,"%^YELLOW%^You spell disperses futilely around "+target->QCN+".\n");
      TO->remove();
      return;
   }
    if (target->query_property("magic resistance")) {
        if (target->query_property("magic resistance") < random(99) +1) {
             tell_object(caster,"%^BOLD%^%^ORANGE%^You feel your spell take a grasp on "+target->QCN+" but then disperse as its power is rendered useless!\n");
            tell_object(target,"%^BOLD%^%^ORANGE%^You feel a spell attempt to grip your mind, but the grip slips and you are freed from it.\n");
            spell_kill(target,caster);
            TO->remove();
            return;
        }
    }
    if (target->query_size()<2) {
         tell_object(caster,"%^BOLD%^%^ORANGE%^You feel your spell take a grasp on "+target->QCN+" but then disperse as its power is rendered useless!\n");
        tell_object(target,"%^BOLD%^%^ORANGE%^You feel a spell attempt to grip your mind, but the grip slips and you are freed from it.\n");
        spell_kill(target,caster);
        TO->remove();
        return;
    }
    if(do_save(target,0)) {
    /*if (SAVING_D->saving_throw(target,"paralyzation_poison_death",-4)||
        ((string)target->query_race() == "half-elf" && random(100) < 30) ||
         ((string)target->query_race() == "half-drow" && random(100) < 30) ||
        ((string)target->query_race() == "beastman" && random(100) < 80) ||
        ((string)target->query_race() == "firbolg" && random(100) < 15) ||
        ((string)target->query_race() == "drow" && random(100) < 80) ||
        ((string)target->query_race() == "elf" && random(100) < 90) ) {*/
        tell_object(caster,"%^BOLD%^%^ORANGE%^You feel your spell take a grasp on "+target->QCN+" but then disperse as its power is rendered useless!\n");
        tell_object(target,"%^BOLD%^%^ORANGE%^You feel a spell attempt to grip your mind, but the grip slips and you are freed from it.\n");
        spell_kill(target,caster);
        TO->remove();
        return;
    }
	duration = clevel/3 + 2;
	if(duration > 10) { duration = 10; }
	duration = duration * (ROUND_LENGTH * 2);
    target->set_paralyzed(duration,"%^BOLD%^%^CYAN%^You are magically held still. You can't move a muscle in your body.");
    tell_room(environment(caster),"%^BOLD%^%^RED%^"+caster->QCN+" looks at "+target->QCN+" and a small wave rushes forth and seizes "+target->QP+" head, forcing "+target->QO+" to mimic the rigidness of iron!",({caster,target}));
    tell_object(caster,"%^BOLD%^%^RED%^You send a wave rushing toward "+target->QCN+" which seizes "+target->QP+" head, forcing "+target->QO+" to mimic the rigidness of iron!\n");
    tell_object(target,"%^BOLD%^%^RED%^"+caster->QCN+" looks at you and a small wave rushes forth and seizes your head, forcing you to mimic the rigidness of iron!\n");
    TO->remove();
}
