#include <std.h>

varargs void broadcast_area(string area, string msg, object *exclude){
    int i;
    string base;
    object * players = users();

    if(!pointerp(exclude)) 
    {
        exclude = ({});
    }
    players -= exclude;
    if(!sizeof(players)) return;
    for(i=0;i<sizeof(players);i++) 
    {
        if(!objectp(environment(players[i]))) continue;
        base = base_name(environment(players[i]));
        if(strsrch(base, area) == -1) continue; 
        message("tell",msg,players[i]);
        continue;        
    }
    return;
}
