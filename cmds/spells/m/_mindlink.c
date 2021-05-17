// 1st level telepathy spell for Telepath psions only
// based on Telepathy ~Circe~ 8/20/15

#include <priest.h>
inherit SPELL;

object who;
string whoname, whocname, cname, Ccname;

void create() {
    ::create();
    set_spell_name("mindlink");
    set_spell_level(([ "psion" : 1 ]));
    set_discipline("telepath");
    set_spell_sphere("telepathy");
    set_syntax("cast CLASS mindlink to TARGET");
    set_description("This power will allow the psion to establish "
       "a mental link with the target, permitting telepathic conversations "
       "for a short time. To ensure comprehension, the two parties "
       "should share a common language.");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
    set_helpful_spell(1);
}

string query_cast_string() {
    return "%^CYAN%^"+YOU+" closes "+MINE+" eyes and concentrates deeply.";
}

void spell_effect(int prof) {
    string *ignored, *casterallowed, *targallowed;

    arg = lower_case(arg);
    if (!(who = find_player(caster->realNameVsProfile(arg)))) {
        tell_object(CASTER,capitalize(arg)+" cannot be found to establish a link.\n");
        TO->remove();
        return;
    }
    cname = CASTER->query_name();
    whoname = who->query_name();
    whocname = who->QCN;
    Ccname = CASTER->QCN;
    if (avatarp(who) && !who->query_disguised()) {
        tell_object(CASTER,capitalize(arg)+" cannot be found to establish a link.\n");
        TO->remove();
        return;
    }
   if(avatarp(who) && arg == (string)who->query_true_name()) {
      tell_object(CASTER,capitalize(arg)+" cannot be found to establish a link.\n");
      TO->remove();
      return;
   }
    if (arg == cname) {
        tell_object(CASTER,"You cannot establish a link with yourself.\n");
        TO->remove();
        return;
    }
    if (who->query_invis() && (int)who->query_level() > (int)CASTER->query_level()) {
        tell_object(CASTER,capitalize(arg)+" cannot be found to establish a link.\n");
        TO->remove();
        return;
    }
    if (who->is_player() && !interactive(who)) {
        tell_object(CASTER, who->QCN+" is link-dead and cannot hear you.\n");
        TO->remove();
        return;
    }
	if(who->query_ghost())
	{
		tell_object(CASTER,capitalize(arg)+" cannot be found to establish a link.\n");
		TO->remove();
		return;
	}
    if (who->query_blocked("tell")) {
        write(who->QCN+" is currently blocking all tells.");
        TO->remove();
        return;
    }
    ignored = who->query_ignored();
    if (!ignored) {
        who->reset_ignored();
        ignored = who->query_ignored();
    }
    if ((member_array(cname, ignored) != -1)) {
        tell_object(CASTER, who->QCN+" is ignoring you.\n");
        TO->remove();
        return;
    }
    casterallowed = CASTER->query_property("allowed tell");
    targallowed = who->query_property("allowed tell");
    if (!casterallowed) casterallowed = ({});
    if (!targallowed) targallowed = ({});
    if (member_array(cname,targallowed) != -1
        && member_array(whoname,casterallowed) != -1) {
        tell_object(CASTER,"You already have a mental link with "+who->QCN+".\n");
        TO->remove();
        return;
    }
    tell_object(CASTER, "%^CYAN%^You establish a mental connection with "+who->QCN+".");
    tell_object(who, "%^CYAN%^"+CASTER->QCN+" has established a mental connection with you.");
    addSpellToCaster();
    spell_successful();
    casterallowed += ({whoname});
    targallowed += ({cname});
    CASTER->set_property("allowed tell",casterallowed);
    CASTER->set_property("spelled", ({TO}) );
    who->set_property("allowed tell",targallowed);
    spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH;
    set_end_time();
    call_out("dest_effect",spell_duration);
}

void dest_effect() {
    string *casterallowed, *targallowed;

    casterallowed = ({});
    targallowed = ({});
    if (objectp(CASTER)) {
        CASTER->remove_property_value("spelled", ({TO}) );
        casterallowed = CASTER->query_property("allowed tell");
        if (pointerp(casterallowed))
        if (member_array(whoname,casterallowed) != -1) {
            casterallowed = casterallowed - ({whoname});
            CASTER->remove_property("allowed tell");
            CASTER->set_property("allowed tell",casterallowed);
              tell_object(CASTER,"%^CYAN%^Your mental link with "+whocname+" has been ended.\n");
        }
    }
    if (objectp(who)) {
        targallowed = (string *)who->query_property("allowed tell");
        if (member_array(cname,targallowed) != -1) {
            targallowed = targallowed - ({cname});
            who->remove_property("allowed tell");
            who->set_property("allowed tell",targallowed);
              tell_object(who,"%^CYAN%^Your mental link with "+Ccname+" has been ended.\n");
        }
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
