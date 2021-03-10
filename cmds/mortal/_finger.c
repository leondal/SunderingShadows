#include <daemons.h>
#include <std.h>
#include <socket.h>
#define AVA_FINGER "/adm/daemon/ava_finger_d.c"
#define AVA_D "/daemon/avatar_d.c"

inherit DAEMON;

int cmd_finger(string str) {
    object ob, pl;
    string wer, wo;

    if (!str) {
    	if(!archp(TP)) {  // changed to only show this for arches *Styx*
              write("You need to specify the character or immortal's name, i.e. <finger [NAME]>");
              return 0;
        }
        TP->more(explode((string)FINGER_D->general_finger_display(), "\n"));
        return 1;
    }

    if(archp(TP))
    {
        TP->more(explode((string)FINGER_D->user_finger_display(str), "\n"));
        return 1;
    }
    if((pl = find_player(str))
       && avatarp(pl)
       && ((string)pl->query_vis_name() != (string)pl->query_name())
       && str == lower_case(pl->query_vis_name())) {
        //Active avatar as the persona
        TP->more(explode((string)AVA_FINGER->avatar_finger_display(str), "\n"));
        return 1;
    }
    if(AVA_D->is_persona(str) && !user_exists(str)){
        //Inactive persona
        TP->more(explode((string)AVA_FINGER->persona_finger_display(str), "\n"));
        return 1;
    }
    TP->more(explode((string)FINGER_D->user_finger_display(str), "\n"));
    return 1;
}

void help() {
   write("
%^CYAN%^NAME%^RESET%^

finger - display info about another player

%^CYAN%^SYNOPSIS%^RESET%^

finger %^ORANGE%^%^ULINE%^NAME%^RESET%^

%^CYAN%^DESCRIPTION%^RESET%^

Gives you some basic information about the character %^ORANGE%^%^ULINE%^NAME%^RESET%^. You will be able only to finger immortals or characters you have recognized.

%^CYAN%^SEE ALSO%^RESET%^

chfn, mail, passwd, who, recognize, version, notify

"
   );
}
