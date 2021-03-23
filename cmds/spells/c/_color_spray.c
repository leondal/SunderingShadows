//      Color Spray
//      Thorn@Shadowgate
//      1/31/95
//      Wizard Spells
//      color_spray.c
//      Revamped by Vashkar -- 8/20/95

#include <spell.h>
#include <magic.h>
#include <rooms.h>
#include <daemons.h>
inherit SPELL;

int time, success;
object *targets;

void damage(object who, int effect);
void restore_sight(object victim);
void make_save();

void create() {
    ::create();
    set_spell_name("color spray");
    set_spell_level(([ "mage" : 1, "oracle":1, "magus" : 1 ]));
    set_mystery("heavens");
    set_spell_sphere("illusion");
    set_syntax("cast CLASS color spray");
    set_description("Color spray, when cast, will cause a blinding light of mixed colors to flash from the caster.  All "
"creatures not in the caster's party can be blinded temporarily by this, or even knocked unconscious.");
    mental_spell();
    splash_spell(3);
    set_verbal_comp();
    set_somatic_comp();
    success = 0;
    set_save("reflex");
}

string query_cast_string() {
    return caster->QCN+" throws a small handful of colored powder in the air!";
}

int bonus;
void spell_effect(int prof) {
    int x, affected;
    object *prospective, place, *ownparty, target;

    bonus = prof/10-10;
    affected = random(6) + 1+ bonus;
    prospective = target_selector();
    targets = ({});

    if (caster->query_party())
        ownparty = PARTY_D->query_party_members(caster->query_party());
    else
        ownparty = ({caster});

    prospective -= ownparty;


    tell_object(caster,"You wave your hand and a fan-shaped spray of vivid colors flares from your hand!");
    tell_room(place,"You see a fan-shaped spray of vivid colors flare from "+caster->QCN+"'s hands!\n", ({ caster}) );

    for (x=0;x < sizeof(prospective);x++) {
        if (x >= affected) break;
        if (!objectp(prospective[x])) continue;
//      if (wizardp(prospective[x])) continue;
// changing to exclude invis. avatars too and check ok to kill to avoid newbies as long as newbies are protected *Styx*  11/14/04
	if (prospective[x]->query_true_invis())  continue;
	if (!caster->ok_to_kill(prospective[x])) continue;
        if (caster == prospective[x]) continue;
        if (prospective[x]->query_blind()) continue;
        target = prospective[x];
        if (!present(target,environment(caster))) {
            tell_object(caster,"%^BOLD%^"+target->QCN+" has left the area.\n");
            continue;
        }
        if ((int)target->query_lowest_level() > (clevel+bonus)){
            if(do_save(target,0))
            //if (do_saving_throw(target))
                damage(target, 0);
            else {
                if ((int)target->query_lowest_level() > (clevel+bonus) + 2)
                    damage(target,3);
                else {
                    damage(target,2);
                }
            }
        } else {
            damage(target,1);
        }
        target->kill_ob(caster);
        affected--;
    }
}

void damage(object who, int effect) {
    if (!objectp(who)) return;
    switch (effect) {
    case 0:
        tell_object(who,"You manage to quickly turn your head before you are dazzled by the bright light.");
        return 1;
    case 1:
        if (!success) {
            success = 1;
            spell_successful();
        }
      if(who->query_property("no paralyze")) {
         tell_object(who,"%^BOLD%^You are unaffected by the bright light.");
         tell_room(environment(who),"%^BOLD%^"+who->QCN+" seems unaffected by the bright light.",who);
         return;
      }
        tell_object(who,"%^BOLD%^%^MAGENTA%^You are knocked unconscious by the bright light.");
        tell_room(environment(who),"%^BOLD%^%^MAGENTA%^"+who->QCN+" collapses to the ground, unconscious!", who);
        time = random(7)+2+bonus;
        who->set_unconscious(random(7)+2+bonus, "You are unconscious and can't do anything!\n");
        who->set_blind(1);
        who->set_property("spelled", ({TO}) );
        call_out("restore_sight", time, who);
        targets += ({who});
        return;
    case 2:
        if (!success) {
            success = 1;
            spell_successful();
        }
        tell_object(who,"%^BOLD%^%^MAGENTA%^You flail about, blinded by the bright light.");
        tell_room(environment(who),"%^BOLD%^%^MAGENTA%^"+who->QCN+" flails about, seemingly blinded by the bright light!", who);
        who->set_blind(1);
        who->set_property("spelled", ({TO}) );
        time = ROUND_LENGTH * random(4)+1;
        call_out("restore_sight", time, who);

        targets += ({who});
        return;
    case 3:
        if (!success) {
            success = 1;
            spell_successful();
        }
      if(who->query_property("no paralyze")) {
         tell_object(who,"%^BOLD%^You are unaffected by the bright light.");
         tell_room(environment(who),"%^BOLD%^"+who->QCN+" seems unaffected by the bright light.",who);
         return;
      }
        tell_object(who,"%^BOLD%^%^CYAN%^You are stunned by the bright light.");
        tell_room(environment(who),"%^BOLD%^%^CYAN%^"+who->QCN+" goes limp, apparently unable to move.", who);
        time = ROUND_LENGTH;
        who->set_paralyzed(time, "You are temporarily stunned and can't do that.");
        return;
    }
}

void restore_sight(object who){
    if(!objectp(who))  return;     //added by Styx 7/3/02 to stop it bugging
    who->set_blind(0);
}

void dest_effect() {
int i;

    for(i=0;i<sizeof(targets);i++){
        if( !objectp(targets[i])) continue;
        restore_sight(targets[i]);
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
