#include <std.h>
#include <rooms.h>
inherit DAEMON;

#include <langs.h>

int cmd_emote(string str)
{
    int i;
    string first, tail, insert, * words = ({}), lang, tmp = "", temp, start_color, end_color;
    object* all, * pick;
    all = ({});
    pick = ({});

    if (TP->query("emote loss")) {
        return 0;
    }
    if (this_player()->query_ghost() && base_name(ETP) != DEATH_ROOM) {
        notify_fail("A ghost has no feelings.\n");
        return 0;
    }

/*
  if(TP->query_bound()){
  TP->send_paralyzed_message("info",TP);
  return 1;
  }
*/
    all = all_inventory(ETP);
    for (i = 0; i < sizeof(all); i++) {
        if (wizardp(all[i])) {
            pick += ({ all[i] });
        }
    }
    if (pointerp(pick)) {
        all -= pick;
    }
    all += ({ TP });
    pick += ({ TP });
    if (!str) {
        write("You look emotional.");
        if ((int)TP->query_disguised() == 0) {
            tell_room(ETP, TP->query_cap_name() + " looks emotional.", pick);
            if (TP->query_invis()) {
                tell_room(ETP, "($&$" + TP->query_name() + "$&$) looks emotional.", all);
            }else {
                tell_room(ETP, capitalize(TP->query_name()) + " looks emotional.", all);
            }
        }else {
            tell_room(ETP, capitalize(TP->query_vis_name()) + " looks emotional.", pick);
            if (TP->query_invis()) {
                tell_room(ETP, "($&$" + TP->query_vis_name() + "$&$)" + " looks emotional.", all);
            }else {
                tell_room(ETP, capitalize(TP->query_vis_name()) + " looks emotional.", all);
            }
        }
        return 1;
    }
    all -= ({ TP });
    pick -= ({ TP });
    if (sscanf(str, " %s", tail) == 1) {
        insert = "";
    }else if (sscanf(str, "'%s", tail) == 1) {
        insert = "";
    }else {
        insert = " ";
    }
    if (!random(6) && interactive(TP) && !wizardp(TP)) {
        if (!TP->query_forced()) {
            if (file_size("/log/emotes/emote.log") > 150000) {
                cp("/log/emotes/emote.log", "/log/emotes/emote.old");
                rm("/log/emotes/emote.log");
            }
            write_file("/log/emotes/emote.log", capitalize(TPQN) + insert + str + "\n");
        }
    }

    message("emote", "You emote: " + replace_string(capitalize((string)TPQN) + insert + str, "#@&", "\""), TP);

    if ((int)TP->query_disguised() == 0) {
        if (!TP->query_invis()) {
            message("emote", TPQCN + insert + str, ETP, TP);
        }else {
            message("emote", "($&$" + TPQN + "$&$)" + insert + str, pick);
            message("emote", TPQCN + insert + str, all);
        }
    }else if (!TP->query_invis()) {
        if (!TP->query_invis()) {
            message("emote", capitalize(TP->query_vis_name()) + insert + str, ETP, TP);
        }else {
            message("emote", "($&$" + TP->query_vis_name() + "$&$)" + insert + str, pick);
            message("emote", capitalize(TP->query_vis_name()) + insert + str, all);
        }
    }else {
        message("emote", TPQCN + insert + str, ETP, TP);
    }
    return 1;
}

void help()
{
    write("
%^CYAN%^NAME%^RESET%^

emote - Describe what your character does

%^CYAN%^SYNOPSIS%^RESET%^

emote %^ORANGE%^%^ULINE%^STRING%^RESET%^

%^CYAN%^DESCRIPTION%^RESET%^

Emote is a roleplay-tool that can be used to describe what your character does and how it reacts to its environment. You can describe your physical actions and gestures, as well as demeanor, appearance, facial expressions and body language. It will be seen by anyone in the room.

%^ORANGE%^%^ULINE%^STRING%^RESET%^ is the action you wish to describe. Your name will be added to the start of the emote automatically.

You may add color to your emotes (%^ORANGE%^<help color>%^RESET%^). If you find that you use an emote often, you can make it into an alias(%^ORANGE%^<help alias>%^RESET%^). If you would like to direct your emote at another player or add speech to your emote, see %^ORANGE%^<help emoteat>%^RESET%^ and %^ORANGE%^<help colors>%^RESET%^ respectively.

There are some simple commands (sit, smile, grin etc) that do not require an emote. For a list of these, see %^ORANGE%^<help souls>%^RESET%^.

You may only describe things that are physically apparent to other people. The command may not be used to describe thoughts or ideas(%^ORANGE%^<help thought>%^RESET%^) or to circumvent language barriers(%^ORANGE%^<help languages>%^RESET%^).

%^CYAN%^EXAMPLE%^RESET%^

If you use %^ORANGE%^<emote sits down and relaxes.>%^RESET%^, everyone in the room will see:

    Yourname sits down and relaxes.

%^CYAN%^SEE ALSO%^RESET%^

say, whisper, yell, emoteat, pose, colors, crayon, languages, emoteat guide
");
}
