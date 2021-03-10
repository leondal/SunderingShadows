#include <std.h>
#include "../inherits/area_stuff.h"
inherit OBJECT;
object webroom;

void create() 
{
    ::create();
    set_name("A mass of glowing web");
    set_value(0);
    set_weight(10000);
	
    set_id(({"web", "mass of web", "glowing web", 
    "mass of glowing web", "strands", "mass"}));

    set_property("no animate", 1);

    set_short("%^BOLD%^%^WHITE%^A mass of %^BOLD%^%^CYAN%^glowing"+
    "%^BOLD%^%^WHITE%^ web%^RESET%^");

    set_long("%^BOLD%^%^WHITE%^This mass of %^BOLD%^%^CYAN%^glowing"+
    "%^BOLD%^%^WHITE%^ web is enormous! It is thick, very sticky, and "+
    "has a strong odor of decay. The individual strands of the web are "+
    "very thick compared to a normal spider and wound together it is "+
    "quite resilent. The only way to get out whatever might be inside "+
    "is to <%^BOLD%^%^CYAN%^tear%^BOLD%^%^WHITE%^> at the thick "+
    "strands, but it will not be easy.%^RESET%^");
}

void init()
{
    ::init();   
    add_action("tear_act", "tear");
}

void struggling()
{
    if(!objectp(TO)) return ;
    if(!objectp(ETO)) return;
    tell_room(ETO, "%^BOLD%^%^WHITE%^You notice the mass of web "+
    "shaking back and forth as something on the inside "+
    "tries to make its way out!%^RESET%^");
    return;
}

void destroy()
{
    if(!objectp(TO)) return 0;
    if(!objectp(ETO)) return 0;
    tell_room(ETO, "%^BOLD%^%^WHITE%^The mass of web suddenly collapses and quickly "+
    "fades away!%^RESET%^");
    TO->remove();
}

void set_web_room(object ob)
{
    if(!objectp(ob)) return;
    webroom = ob;
}

int tear_act(string what) 
{
    int dam, webhp;
    if(!objectp(TO)) return 0;
    if(!objectp(ETO)) return 0;
    if(!objectp(TP)) return 0;
    if(!objectp(webroom)) return 0;
    if(!stringp(what)) return 0;
    if(TO != present(what, ETO)) return 0;
    if (TP->query_bound() || TP->query_unconscious() || TP->query_paralyzed()) 
    {
        TP->send_paralyzed_message("info",TP);
        return 1;
    }
    dam = roll_dice(2, 20);

    tell_object(TP, "%^BOLD%^%^WHITE%^You begin tearing away at "+
    "the thick strands of glowing web!%^RESET%^");
	
    tell_room(ETO, TPQCN+"%^BOLD%^%^WHITE%^ begins tearing away at "+
    "the thick strands of glowing web!%^RESET%^", TP);

    TP->set_paralyzed(8, "%^BOLD%^%^WHITE%^You are tearing away strands of the web!%^RESET%^");
    webroom->damage_web((dam*-1));
    return 1;
}		

int get() { return 0; }