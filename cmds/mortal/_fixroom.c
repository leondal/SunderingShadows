//changed to log the uses of fixroom that fix the room - with the hope that maybe it will help lead to
//tracking down bugs that break rooms - of which, I suspect, there are several - Saide April, 2016
#include <std.h>

int cmd_fixroom()
{
    if(!objectp(TP)) return 0;
    if(!objectp(ETP))
    {
        tell_object(TP, "%^BOLD%^You have no valid environment. Please contact a wiz.");
        return 1;
    }

    if(!ETP->query_short())
    {
        if(!ETP->query_long() || !strlen(ETP->query_long()))
        {
            if(!pointerp(ETP->query_exits()) || !sizeof(ETP->query_exits()))
            {
                ETP->create();
                ETP->init();
                tell_room(ETP, "A fog encloses the room, and when it lifts, the room has been restored!");
                return 1;
            }
        }
    }
    tell_object(TP, "%^BOLD%^Sorry, the room isn't broken.  If you still think it is, contact a wiz.");
    return 1;
}
