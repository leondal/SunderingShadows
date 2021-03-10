#include <std.h>

object *nearbyRoom(object start, int x)
{
    int i, j, k;
    object *rooms,room;
    object *tmprooms;
    string *dests;

    rooms = ({start});

    for(i=0;i<x;i++)
    {
        tmprooms = ({});
        
        for (j=0;j<sizeof(rooms);j++) 
        {
            if(!objectp(rooms[j])) { continue; }

            dests = (string *)rooms[j]->query_destinations();

            for (k=0;k<sizeof(dests);k++) 
            {
                if(!objectp(room = to_object(dests[k]))) { continue; }
                tmprooms += ({ room });
            }          
        }

        rooms += tmprooms;
        rooms = distinct_array(rooms);
    }

    return rooms;
}
