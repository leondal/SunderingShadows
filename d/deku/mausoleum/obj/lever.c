#include <std.h>
inherit OBJECT;
string lever_type;

void create()
{
    ::create();
    set_name("a narrow lever");
    set_id(({ "lever", "narrow lever", "narrow wooden lever",
    "wooden lever"}));
    
    set_short("%^RESET%^%^ORANGE%^narrow wooden lever%^RESET%^");    
    
    set_long("%^RESET%^%^ORANGE%^This lever is only about two feet long. "+
    "It is made from a heavy %^RESET%^%^GREEN%^oak%^RESET%^%^ORANGE%^ but has "+
    "been cut in such a way that it is narrow. The handle end of the lever is "+
    "ridged, in order to provide a means of gripping it. The other end of the lever "+
    "has a strange %^BOLD%^mechanical%^RESET%^%^ORANGE%^ part inset into "+
    "the wood. You think that if you found some place that had a similiar part "+
    "you could probably %^BOLD%^attach%^RESET%^%^ORANGE%^ the lever.%^RESET%^");
    
    set_lore("There are no rumors about this lever. However, you do know that "+
    "it is ancient. You also are able to tell that it serves as a key to something. "+
    "You realize that it is only part of the key though and think that perhaps there "+
    "are other levers that would work with it.");
    
    set_property("lore difficulty", 15);
    
    set_weight(6);
    set_value(0);
}

void set_lever_type(string str) { lever_type = str; }
string query_lever_type() { return lever_type; }