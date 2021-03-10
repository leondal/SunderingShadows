#include <std.h>
#include "../inherits/area_stuff.h"
inherit INNER;

void create() 
{
    ::create();
    set_long(TO->query_long()+"%^BOLD%^%^WHITE%^ A much %^BOLD%^%^BLACK%^larger crack%^BOLD%^%^WHITE%^ "+
    "runs the entire length of the northern wall. Openings in the eastern and southern walls lead "+
    "to other sections of the cavern. %^RESET%^");
    set_exits((["east" : CRROOMS+"inner19", "south" : CRROOMS+"inner29"]));		
    add_item(({"large crack", "larger crack", "north crack",
    "large north crack"}), "%^BOLD%^%^BLACK%^This larger crack looks as if it "+
    "opens into a smaller chamber. You could %^BOLD%^%^CYAN%^enter%^BOLD%^%^BLACK%^ it if you "+
    "wanted to see what was on the other side.%^RESET%^");
}

void init()
{
    ::init();
    add_action("enter_crack", "enter");
}

int enter_crack(string str)
{
    if(!objectp(TO)) return 0;
    if(!objectp(TP)) return 0;
    if(!stringp(str)) return 0;
    if(str != "crack" && str != "large crack" && str != "larger crack") return 0;
    if (TP->query_bound() || TP->query_unconscious() || TP->query_paralyzed()) 
    {
        TP->send_paralyzed_message("info",TP);
        return 1;
    }
    tell_object(TP, "%^BOLD%^%^BLACK%^You crawl through the large crack on the northern wall.%^RESET%^");
    if(!TP->query_invis()) 
    {
        tell_room(TO, TPQCN+"%^BOLD%^%^BLACK%^ crawls through the large crack on "+
        "the northern wall!%^RESET%^", TP);
    }
    TP->move(CRROOMS+"inner31");
    TP->force_me("look");
    return 1;
}