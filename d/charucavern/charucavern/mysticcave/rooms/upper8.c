#include <std.h>
#include "../inherits/area_stuff.h"
inherit UPPER;

void create() 
{
    ::create();

    set_exits((["northeast" : CRROOMS+"upper7", "east" : CRROOMS +"upper9"]));		
    set_climb_exits((["descend": ({CRROOMS+"mid2_enter", 20, 30, 100}) ]));
    set_fall_desc("%^BOLD%^%^RED%^You stumble and fall landing hard on the floor of the cavern!%^RESET%^");
}

int mySearch(string str)
{
    object ob;
    if(!objectp(TP)) return 0;
    if(!objectp(TO)) return 0;
    tell_object(TP, "%^BOLD%^%^WHITE%^You carefully search the "+str+" and realize that "+
    "one is much larger than normal. You could easily <%^BOLD%^%^CYAN%^descend"+
    "%^BOLD%^%^WHITE%^> into it, if you were so inclined.%^RESET%^");    
    return 1;
}