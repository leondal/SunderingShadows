#include <std.h>
#include "../inherits/book_pages.h"
inherit OBJECT;

void create()
{
    ::create();
    set_name("a leather bound tome");
    set_id(({ "tome", "leather bound tome", "leather tome", 
    "book", "leather book"}));
    
    set_short("%^RESET%^%^ORANGE%^leather bound tome%^RESET%^");    
    
    set_long("%^RESET%^%^ORANGE%^The first thing that you really "+
    "notice about this tome is that it is spewing forth a very "+
    "powerful and ancient magic. When you hold it, it seems to "+
    "wash over you, but it has no affect, at least not one that "+
    "you recognize. It is ancient and thick. The spine of it is bound "+
    "with %^BOLD%^%^BLACK%^dark leather%^RESET%^%^ORANGE%^ strips "+
    "that have bound tied tightly together. The front and back of "+
    "the tome are engraved with the words 'Aorus Devar', which shift "+
    "places on the tome before your very eyes. The words slowly fade away "+
    "before appearing somewhere else. You could likely %^BOLD%^"+
    "read%^RESET%^%^ORANGE%^ it but it looks as if "+
    "it was submerged in some type of liquid at some point in the "+
    "past. You are unsure of how much of what it once contained would "+
    "still be legible.%^RESET%^");    
    set_weight(5);
    set_value(0);
}

void init()
{
    ::init();
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!living(ETO)) return;
    add_action("read", "read");
}

int read(string str)
{    
    string *PAGES = ({PAGE_1, PAGE_2, PAGE_3, PAGE_4, PAGE_5});
    if(!objectp(TO)) return 0;
    if(!objectp(ETO)) return 0;
    if(!stringp(str)) return 0;
    if(str != "tome") return 0;
    
    tell_object(ETO, "%^RESET%^%^ORANGE%^You open the tome and "+
    "attempt to read an exert from it... you watch in amazement as "+
    "words appear on what is at first a blank page!");
    
    ETO->more(PAGES[random(sizeof(PAGES))]);
    return 1;
}