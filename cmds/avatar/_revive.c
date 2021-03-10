//      /bin/dev/_vis.c
//      coded by Lujke, slave-driven by Garret
//      September 2005
//      Updated to reverse damaged equipment by Saide - December, 2016

#include <std.h>

inherit DAEMON;

int cmd_revive(string str)
{
    object targ, *inv;
    int x;
    if (!objectp(TP)||!objectp(ETP)){return 0;}
    targ = find_player(str);
    if (!objectp(targ))
    {
        notify_fail(str + " isn't around to be revived\n");
        return 0;
    }
    targ->revive();
    targ->advance_death_time();
    targ->set_blind(0);
    targ->set_heart_beat(1);
    targ->set_heal_rate(2);
    targ->add_stuffed(25);
    targ->add_quenched(25);
    "/adm/daemon/perma_d.c"->remove_player(str);
    tell_object(TP, "You revive " + str);
    return 1;
}


void help()
{
  write(
"
%^CYAN%^NAME%^RESET%^

revive - returns player to life

%^CYAN%^SYNTAX%^RESET%^

revive %^ORANGE%^%^ULINE%^PLAYER%^RESET%^

%^CYAN%^DESCRIPTION%^RESET%^

%^CYAN%^SEE ALSO%^RESET%^

slay
"
  );
}
