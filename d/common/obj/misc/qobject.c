// Prevented clean_up in order to fight the quest item population issue.
//-Octothrope 3/4/10
// adding in additional checks for clean_up to quest items which are located in
// rooms, rather than on monsters. -Ares
// generic object for random quests
#include <std.h>
inherit OBJECT;
int ob_level;
void create()
{
    ::create();
    set_short("");
    set_long("");
    set_id(({"questob"}));
    ob_level = -1;
}


int query_ob_level() { return ob_level; }


void init()
{
    object room;

    ::init();
    if (!objectp(ETO)) { return; }
    if (objectp(room=ETO))
    {
        if (room->is_room())
        {
            // setting this so the clean up daemon doesn't delete them before
            //players can see them
            room->set_had_players(4);
        }
    }

    if(interactive(TP) && ETO == TP)
    {
        if(ob_level ==-1)
        {
            ob_level =TP->query_highest_level();
        }
        "daemon/quests"->changeShort(query_short(),TP->query_short());
        "daemon/quests"->gotten(query_short());
    }

    if(TP->is_monster() && ETO == TP)
    {
        "daemon/quests"->resetItem(query_short());
    }
}


int remove()
{
    if(!objectp(PO)) return ::remove();
    if (base_name(PO) != "/std/user")
    {
        if (!(PO->is_bag() && userp(environment(PO))))
        {
            "daemon/quests"->resetItem(query_short());
        }
    }
    return ::remove();
}

int clean_up()
{
    return 0;
}
