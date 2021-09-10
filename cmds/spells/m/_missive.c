//Tlaloc reskinned sending as missive for psion
//Spell sphere matters

#include <priest.h>
#define SENDOBJ "/d/magic/obj/send_ob"
inherit SPELL;

object who,send_ob;
string whoname, whocname, cname, Ccname;

void create() {
    ::create();
    set_spell_name("missive");
    set_spell_level(([ "psion" : 1, ]));
    set_spell_sphere("telepathy");
    set_syntax("cast CLASS missive to TARGET");
    set_description("This power allows a brief message to be sent to the target.  The target cannot respond, and the "
"telepath's message must be shorter than 200 characters.  If the message is too long, the power fails.  Likewise, if the "
"target is ignoring the psion or incapacitated in some way, the power will fail.");
    set_non_living_ok(0);
    set_arg_needed();
    set_silent_casting(1);
	set_helpful_spell(1);
}

void spell_effect(int prof) {
    string arg;
    string *ignored, *casterallowed, *targallowed;

    spell_successful();
    arg = lower_case(ARG);
    if (!(who = find_player(caster->realName(arg)))) {
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
    tell_object(CASTER, "%^CYAN%^You ready your mind to send a message to "+who->QCN+".");
    send_ob = new(SENDOBJ);
    send_ob->move(CASTER);
    send_ob->set_receiver(who);
    send_ob->set_teller(CASTER);
    CASTER->set_property("spelled",({TO}));
    spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH;
    set_end_time();
    call_out("dest_effect",spell_duration);
}

void dest_effect() {
    if(objectp(CASTER)){
       tell_object(CASTER,"The ability to communicate with "+who->QCN+" "+
          "fades from your mind.");
       if(objectp(send_ob)) send_ob->remove();
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
