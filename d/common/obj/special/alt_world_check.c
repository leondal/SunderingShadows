#include <std.h>
#include <magic.h>
#include <daemons.h>
inherit OBJECT;

string invitemsg, acceptmsg, declinemsg;
int is_in;
object myplayer;

void create()
{
    ::create();
    set_property("no animate", 1);
    set_property("no drop", 1);
    set_property("soulbound", 1);   
    is_in = 0;
}

void alt_world_message(string str) { invitemsg = str; }
void alt_world_accept(string str) { acceptmsg = str; }
void set_for_player(object ob) { myplayer = ob; }
void alt_world_decline(string str) { declinemsg = str; }

void init()
{
    ::init();
    if(!objectp(TO)) return;
    if(!objectp(ETO) || !userp(ETO) || ETO != myplayer)
    {
        TO->remove();
        return;
    }
    if(!stringp(invitemsg))
    {
        TO->remove();
        return;
    }    
    if(ETO->query("alternative world"))
    {
        TO->remove();
        return;
    }
    tell_object(ETO, invitemsg);
    add_action("yes_func", "yes");
    add_action("yes_func", "y");
    add_action("no_func", "no");
    add_action("no_func", "n");
}

int query_is_in() { return is_in; }

void ro()
{
    if(!objectp(TO)) return;
    TO->remove();
    return;    
}

int yes_func(string str)
{
    if(!objectp(TO)) return 0;
    if(!objectp(ETO)) return 0;
    if(is_in) return 0;
    if(stringp(acceptmsg)) tell_object(ETO, acceptmsg);
    else
    {
        tell_object(ETO, "%^BOLD%^%^WHITE%^You have accepted an invitation to a "+
        "phased event. The event will start momentarily.%^RESET%^");
    }
    is_in = 1;
    return 1;
}

int no_func(string str)
{
    if(!objectp(TO)) return 0;
    if(!objectp(ETO)) return 0;
    if(is_in) return 0;
    if(stringp(declinemsg)) tell_object(ETO, declinemsg);
    else
    {
        tell_object(ETO, "%^BOLD%^%^WHITE%^You have declined an invitation to a "+
        "phased event.%^RESET%^");
    }
    call_out("ro", 1);
    return 1;
}