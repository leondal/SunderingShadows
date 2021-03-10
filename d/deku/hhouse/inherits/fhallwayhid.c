#include <std.h>
#include <daemons.h>

#include "area_stuff.h"
#include "/d/common/common.h"

inherit FFH;
int searched;
string sexit, sexitt, dest, destt;
  	
void open_hidden_room()
{
    object hidroom;
    if(searched == 0) 
    {
        searched = 1;
        tell_room(TO, "%^BOLD%^%^RED%^A section of the "+sexit+"ern"+
        " wall slides to the side, revealing "+
        "an opening!%^RESET%^");
        TO->add_exit(dest, sexit);
        if(catch(hidroom = to_object(dest))) 
        {
            tell_room(TO, "ERROR: Tell Saide something BROKE IN ANOTHER ROOM (THIS MESSAGE IS SPECIFIC TO THIS ROOM");
        }
        if(objectp(hidroom)) hidroom->open_hidden_room();
        if(stringp(sexitt)) 
        {
            tell_room(TO, "%^BOLD%^%^RED%^A section of the "+sexitt+"ern"+
            " wall slides to the side, revealing an opening!%^RESET%^");
            TO->add_exit(destt, sexitt);
            if(catch(hidroom = to_object(destt))) 
            {
                tell_room(TO, "ERROR: Tell Saide something BROKE IN ANOTHER ROOM (THIS MESSAGE IS SPECIFIC TO THIS ROOM");
            }
            if(objectp(hidroom)) hidroom->open_hidden_room();
        }
        return;
    }
}

void close_hidden_room()
{
    object hidroom;
    if(searched == 1)
    {
        tell_room(TO, "%^BOLD%^%^RED%^A section of the "+sexit+"ern"+
        " wall slides back into place!%^RESET%^");
        searched = 0;
        TO->remove_exit(sexit);
        if(catch(hidroom = to_object(dest))) 
        {
            tell_room(TO, "ERROR: Tell Saide something BROKE IN ANOTHER ROOM (THIS MESSAGE IS SPECIFIC TO THIS ROOM");
        }
        if(objectp(hidroom)) hidroom->close_hidden_room();
        if(stringp(sexitt))
        {
            tell_room(TO, "%^BOLD%^%^RED%^A section of the "+sexitt+"ern"+
            " wall slides back into place!%^RESET%^");
            TO->remove_exit(sexitt);
            if(catch(hidroom = to_object(destt))) 
            {
                tell_room(TO, "ERROR: Tell Saide something BROKE IN ANOTHER ROOM (THIS MESSAGE IS SPECIFIC TO THIS ROOM");
            }
            if(objectp(hidroom)) hidroom->close_hidden_room();
        }
        return;
    }
}



void create() 
{
    ::create();
    set_search("bones", (:TO, "mySearch":));
    searched = 0;
}

void init()
{
    ::init();
    add_action("push_button", "push");
}


int push_button(string arg)
{
    if(!arg) return 0;
    if(arg != "button") return 0;
    if(!objectp(TP)) return 0;
    if(!objectp(TO)) return 0;
    tell_room(TO, TPQCN+"%^BOLD%^%^BLUE%^ steps on something that is hidden beneath "+
    "the bones!", TP);

    tell_object(TP, "%^BOLD%^%^BLUE%^You step on the button and press it into "+
    "the floor but as soon as you remove your weight from it, it rises back up!%^RESET%^");
    
    if(searched == 0) 
    {
        open_hidden_room();
        return 1;
    }
    if(searched == 1)
    {
        close_hidden_room();
        return 1;
    }
    return 1;
}
	
int mySearch(string ob)
{
    object mon;
    if(!objectp(TO)) return 0;
    if(!objectp(TP)) return 0;
    tell_object(TP, "%^BOLD%^%^WHITE%^You dig through the bones and "+
    "find what feels like a button that you could easily "+
    "%^RESET%^<%^BOLD%^%^CYAN%^push%^RESET%^>%^BOLD%^%^WHITE%^.");

    if(!TP->query_invis())
    {
        tell_room(TO, TPQCN+"%^BOLD%^%^WHITE%^ digs through the bones and "+
        "seems to find something of interest.%^RESET%^", TP);
    }
}

void reset()
{
    ::reset();
    searched = 0;
    close_hidden_room();
}