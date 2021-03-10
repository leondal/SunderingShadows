//_teach

#include <std.h>
#include <security.h>
#include <daemons.h>

inherit DAEMON;

string forbidden_to_teach = ({"druidic"});

int help()
{
    write(
        "
%^CYAN%^NAME%^RESET%^

teach - teach someone a tongue

%^CYAN%^SYNOPSIS%^RESET%^

teach %^ORANGE%^%^ULINE%^LANGUAGE%^RESET%^ to %^ORANGE%^%^ULINE%^SOMEONE%^RESET%^

%^CYAN%^DESCRIPTION%^RESET%^

If you have a fair understanding of a %^ORANGE%^%^ULINE%^LANGUAGE%^RESET%^ you can teach %^ORANGE%^%^ULINE%^SOMEONE%^RESET%^.

This will either help them learn it or give them a basic understanding of the language so they can start to learn from basic conversations.

Both teacher's and student's intelligence score affect how quickly language is being taught.

%^CYAN%^SEE ALSO%^RESET%^

languages, speak, say, races");
    return 1;
}

int cmd_teach(string str)
{
    string lang, who;
    object targ;

    if (!str) {
        return notify_fail("teach language to whom?\n");
    }

    if (TP->query_gagged()) {
        return notify_fail(TP->query_gagged_message() + "\n");
    }

    if ((int)TP->query_stats("intelligence") < 10) {
        return notify_fail("You really wouldn't know where to start.\n");
    }

    if (TP->query_property("teaching")) {
        return notify_fail("You are already teaching someone.\n");
    }

    if (TP->query_property("taught")) {
        return notify_fail("You are being taught, wait till you've finished this lesson.\n");
    }

    if (sscanf(str, "%s to %s", lang, who) != 2) {
        return notify_fail("teach language to whom?\n");
    }

    if (!TP->query_base_lang(lang) || (int)TP->query_base_lang(lang) < 50) {
        return notify_fail("You don't know that language well enough to teach it.\n");
    }

    if (member_array(lang, forbidden_to_teach) != -1) {
        return notify_fail("You can't teach that language.\n");
    }

    if (!(targ = present(who, ETP))) {
        return notify_fail("That person is not here, how are you going to teach them?\n");
    }

    if (!userp(targ)) {
        return notify_fail("That creature or object cannot learn from you.\n");
    }

    if (targ == TP) {
        return notify_fail("Umm I don't think so...\n");
    }

    if (targ->query_property("taught")) {
        return notify_fail(targ->query_cap_name() + " is already being taught.\n");
    }

    if ((int)targ->query_base_lang(lang) >= (int)TP->query_base_lang(lang)) {
        return notify_fail("That one knows as much, if not more than you.\n");
    }

    seteuid("UID_LOG");
    seteuid(getuid());
    TP->force_me("speak " + lang);
    TP->force_me("smile");
    TP->force_me("emote gestures to your head and face and body and ...");
    TP->force_me("say that is your head, face, and body.");
    TP->force_me("emote attempts to show you some common phrases.");
    TP->set_property("teaching", 1);
    targ->set_property("taught", 1);
    call_out("step", 10, 1, TP, targ, lang);
    return 1;
}

void step(int when, object who, object targ, string what)
{
    int lang, adj;
    if (!objectp(who)) {
        return;
    }
    if (!objectp(targ)) {
        who->remove_property("teaching");
        //
        return;
    }
    if (!present(targ, environment(who))) {
        tell_object(who, "Your student seems to have left the area. You will have to start over.");
        who->remove_property("teaching");
        targ->remove_property("taught");
        return;
    }
    who->set_spoken(what);
    if (when == 1) {
        who->force_me("say Hello, I will try to teach you.");
        who->force_me("smile");
        who->force_me("emote pulls out some bread.");
        who->force_me("say This is bread. This is food.");
        targ->force_me("nod with some understanding.");
        call_out("step", 5, 2, who, targ, what);
    } else if (when == 2) {
        who->force_me("emote holds out " + who->query_possessive() + " hand in welcome.");
        who->force_me("say Greetings.");
        who->force_me("emote sighs and wipes " + who->query_possessive() + " brow.");
        who->force_me("emote gathers up some items of interest.");
        call_out("step", 5, 3, who, targ, what);
    } else if (when == 3) {
        who->force_me("emote points at the items and ..");
        who->force_me("say sword");
        who->force_me("say dagger");
        who->force_me("say helmet");
        who->force_me("say cat");
        who->force_me("say armour");
        who->force_me("say boot");
        who->force_me("say cheese");
        who->force_me("say sheath");
        who->force_me("say book");
        who->force_me("say moon");
        who->force_me("emote frowns and tries to explain something else to you.");
        call_out("step", 5, 4, who, targ, what);
    }else if (when == 4) {
        who->force_me("emote starts to make motions with " + who->query_possessive() + " hands.");
        who->force_me("say ... the genitive leads to the ... and the objective case ... the subjective precedes.... ");
        targ->force_me("emote looks baffled.");
        who->force_me("smile");
        if (!targ->query_base_lang(what)) {
            if (!targ->add_lang(what)) {
                tell_object(who, targ->query_cap_name() + " just doesn't seem to get it and seems to be unable to learn new language.");
                tell_object(targ, "You just don't seem to get it, maybe your languages are just exhausted for the time being.");
                who->remove_property("teaching");
                targ->remove_property("taught");
                return;
            }

            targ->force_me("emote brightens with some limited understanding.");

            targ->add_grammar(what,
                              BONUS_D->query_stat_bonus(who,"intelligence") * 5 +
                              BONUS_D->query_stat_bonus(targ, "intelligence") * 5 + 50);

            who->remove_property("teaching");
            targ->remove_property("taught");
            return;
        }
        targ->force_me("emote seems to have gained a little more knowledge.");
        who->force_me("shrug");

        targ->add_grammar(what,
                          BONUS_D->query_stat_bonus(who, "intelligence") * 5 +
                          BONUS_D->query_stat_bonus(targ, "intelligence") * 5 + 50);

        who->remove_property("teaching");
        targ->remove_property("taught");
    }
}
