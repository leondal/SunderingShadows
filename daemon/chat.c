#include <udp.h>
#include <daemons.h>
#include <objects.h>
#include <std.h>

#define MAGENTA "%^MAGENTA%^"
#define RESET "%^RESET%^"

nosave private mapping channels;

/**
 * @file
 * @brief Channels related functions
 */

void create()
{
    string* chans;
    object* who;
    int i, j;

    seteuid(getuid());
    channels = ([]);
    i = sizeof(who = users());
    while (i--) {
        j = sizeof(chans = (string*)who[i]->query_channels());
        while (j--) {
            if (!channels[chans[j]]) {
                channels[chans[j]] = ({});
            }
            channels[chans[j]] = distinct_array(channels[chans[j]] + ({ who[i] }));
        }
    }
}

/**
 * This function formats messages
 *
 * @param chan Channel for the message
 * @param name Name of the player
 * @param position Special position character to display whether player is an imm or not
 * @param message The message itself
 * @param emote Whether it is an emote (ACTION)
 *
 * @return Formatted string
 *
 */
string format_chat(string chan, string name, string position, string message, int emote)
{
    string chanprefix;

    chanprefix = "%^RESET%^%^BLUE%^[%^BOLD%^%^CYAN%^" + chan + "%^RESET%^%^BLUE%^] ";
    if (emote) {
        return chanprefix + "%^RESET%^%^BOLD%^%^MAGENTA%^* %^RESET%^%^WHITE%^" + name + " " + message + "%^RESET%^";
    }else {
        return chanprefix + "%^GREEN%^<%^RESET%^%^ORANGE%^" + position + "%^BOLD%^%^GREEN%^" + name + "%^RESET%^%^GREEN%^>%^RESET%^ " + message + "%^RESET%^";
    }
}

/**
 * This function adds user to channels
 *
 * @param *chans Pointer to channels array
 * @param who Whom to add
 *
 */
varargs void add_user(string* chans, object who)
{
    object ob;
    int i;
    if (objectp(who) && userp(who)) {
        ob = who;
    }else if (base_name(ob = previous_object()) != OB_USER) {
        return;
    }

    i = sizeof(chans);
    while (i--) {
        if (!channels[chans[i]]) {
            channels[chans[i]] = ({});
        }
        channels[chans[i]] = distinct_array(channels[chans[i]] + ({ ob }));
    }
}

/**
 * This function removes user from channels.
 *
 * @param *chans Pointer to channels array
 *
 */
void remove_user(string* chans)
{
    object ob;
    int i;

    if (base_name(ob = previous_object()) != OB_USER) {
        return;
    }
    i = sizeof(chans);
    while (i--) {
        if (!channels[chans[i]]) {
            continue;
        }else {
            channels[chans[i]] -= ({ ob });
        }
        if (!sizeof(channels[chans[i]])) {
            map_delete(channels, chans[i]);
        }
    }
}

/**
 * Sends message to everyone on related channel
 *
 * @param verb A verb user used to invoke this function. Could be a
 *        channel name or channel name+emote to indicate emotes and
 *        actions
 * @param str Message user is sending
 *
 * @return 1 on success, 0 on failure.
 *
 */
int do_chat(string verb, string str)
{
    string msg;
    int emote;
    object* archlist, * pllist;
    string tpname, tppos;

    if (!channels[verb]) {
        if (sscanf(verb, "%semote", verb)) {
            emote = 1;
        }else {
            return 0;
        }
        if (!channels[verb]) {
            return 0;
        }
    }

    if (member_array(TP, channels[verb]) == -1) {
        return 0;
    }

    if (!str) {
        TP->set_blocked(verb);
        return 1;
    }

    if ((int)TP->query_blocked(verb)) {
        if ((int)TP->query_blocked("all")) {
            message(verb, "%^BOLD%^%^RED%^You cannot chat while totally blocked.%^RESET%^", TP);
            return 1;
        }
        TP->set_blocked(verb);
    }

    str += RESET;

    pllist = channels[verb];
    //pllist -= ({TP});

    tpname = capitalize(TPQN);
    if (wizardp(TP)) {
        tppos = "@";
    }else if (avatarp(TP)) {
        tppos = "%";
    }else {
        tppos = " ";
    }

    msg = format_chat(verb, tpname, tppos, str, emote);
    message(verb, msg, pllist, ignored_list(TP));

    IPC->ipc_send_all("CHAT:" + verb + ":" + tppos + ":" + tpname + ":" + strip_colors(str) + "\n");

    return 1;
}

/**
 * This function prints list of everyone on a channel
 *
 * @param str A channel to use
 *
 * @return 1 on succes, 0 on failure
 */
int list_channel(string str)
{
    string list;
    int i;

    if (!channels[str]) {
        return 0;
    }
    if (!avatarp(TP)) {
        return 0;
    }
    if (member_array(TP, channels[str]) == -1) {
        return 0;
    }
    list = "";
    list = "%^BOLD%^Users with the " + str + " channel on %^RESET%^(are true_invis):";
    i = sizeof(channels[str]);
    while (i--) {
        if (!channels[str][i]) {
            continue;
        }
        if (channels[str][i]->query_quietness() && wizardp(channels[str][i]) && !wizardp(TP)) {
            continue;
        }
        if ((int)channels[str][i]->query_blocked(str)) {
            continue;
        }
        if (channels[str][i]->query_true_invis() && channels[str][i]->query_level() > TP->query_level() && TP != channels[str][i]) {
            continue;
        }
        if (channels[str][i]->query_true_invis()) {
            list += "    (" + capitalize(channels[str][i]->query_name() + ")");
        }else if (channels[str][i]->query_disguised()) {
            list += "    " + capitalize(channels[str][i]->query_vis_name());
        }else {
            list += "    " + capitalize(channels[str][i]->query_name());
        }
        //list += "     "+channels[str][i]->query_cap_name();
    }

    message("info", list, TP);
    return 1;
}

object* arches(object* objs)
{
    int i;
    object* these;

    these = ({});
    for (i = 0; i < sizeof(objs); i++) {
        if (!objectp(objs[i])) {
            continue;
        }
        if (wizardp(objs[i]) && !objs[i]->query_property("seesomeone")) {
            these += ({ objs[i] });
        }
    }
    return these;
}

/**
 * Send a message to everyone on the channel
 *
 * @param tp object that sends a message.
 * @param *list pointer to array of people to send message to
 * @param chan channel to send messages to.
 * @param msg message to send
 * @param emote Whether message is action/emote
 */
void do_amsg(object tp, object* list, string chan, string msg, int emote)
{
    int i;
    string tpname, tppos;

    if (wizardp(TP)) {
        tppos = "@";
    }else if (archp(TP)) {
        tppos = "%";
    }else {
        tppos = " ";
    }
    tpname = capitalize((string)tp->query_name());

    for (i = 0; i < sizeof(list); i++) {
        message(chan, format_chat(chan, tpname, tppos, msg, emote), list[i], ignored_list(TP));
    }
}

int clear_channels()
{
    channels = ([]);
    return 1;
}

void force_chat(object tp, string verb, string str, int emote)
{
    object* list;
    if (!channels[verb]) {
        return;
    }
    list = channels[verb];
    list -= ({ 0 });
    return do_amsg(tp, list, verb, str, emote);
}

object* ignored_list(object obj)
{
    object* ppl, * ignoring = ({});
    string name, * ignored;
    int i;

    if (!objectp(obj)) {
        return ({});
    }
    if (avatarp(obj)) {
        return ({});
    }
    name = obj->query_true_name();

    ppl = users();

    for (i = 0; sizeof(ppl), i < sizeof(ppl); i++) {
        if (!objectp(ppl[i])) {
            continue;
        }
        ignored = ppl[i]->query_ignored();
        if (!sizeof(ignored)) {
            continue;
        }
        if (member_array(name, ignored) == -1) {
            continue;
        }
        ignoring += ({ ppl[i] });
    }

    return ignoring;
}

/**
 * This is called from IPC to send message to all users on the
 * channel.
 */
int ipc_chat(string channel, string nick, string msg)
{

    object* pllist;

    msg = (explode(msg, "\n"))[0];

    if (previous_object() != find_object(IPC)) {
        return 0;
    }

    if (!channels[channel]) {
        return 0;
    }

    msg = format_chat(channel, nick, "+", msg);
    pllist = channels[channel];

    message(channel, msg, pllist, ({}));
    return 1;
}
