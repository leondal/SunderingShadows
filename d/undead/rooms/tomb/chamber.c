#include <std.h>
#include "../../undead.h"

inherit INH+"tomb_five.c";

void search_stuff();
void search_panel();

int found;

void create() 
{
    ::create();
    found == 0;

    set_long("%^BLUE%^You are in a faintly lit Chamber\n"
        "%^BOLD%^%^BLACK%^You stand in a chamber shaped like a perfect "
        "cube.  It contains a large number of statues shaped from a black "
        "material the likes of which you have never seen before.  What light "
        "there is here comes from a small lantern on the ceiling, but all "
        "but the smallest portion of that light seems to be being absorbed "
        "by the metal statues.");

    set_exits(([
        "east":HALL+"hall7"
             ]));

    set_items(([
        "panel":"There appears to be some sort of panel built into the wall with "
            "three sockets carved into it.",
        "sockets":"There are three sockets here.",
        "socket 1":" This is the first socket.",
             ]));
    
    set_search("default", (: TO, "search_stuff" :) );
    set_search("panel",   (: TO, "search_panel" :) );

}

void reset() 
{
  ::reset();
  if(!present("golem")) { new(MON+"golem")->move(TO); }
}

void init() 
{
   ::init();
   add_action("insert","insert");
}

int insert(string str) 
{
    object obj;
    if(obj = present("Sring",TP))
    {
        if(!str) 
        {
            write("Insert what?");
        return 1;
        }
        if (str == "ring") 
        {
            write("Insert ring in where?");
            return 1;
        }
        if (found == 1) 
        {
            if (str == "ring in socket 1") 
            {
                TP->move_player(HALL"death");
                obj->remove();
                return 1;
            }
            if (str == "ring in socket 2") 
            {
                TP->move_player(HALL"death");
                obj->remove();
                return 1;
            }
            if (str == "ring in socket 3") 
            {
                TP->move_player(HALL"death");
                obj->remove();
                return 1;
            }
        }
        if (found == 2) 
        {
            if (str == "ring in socket" || str == "ring into socket") 
            {
                TP->move_player(HALL"chamber8");
                obj->remove();
                return 1;
            }
        }
    }
}

void search_stuff()  
{
    tell_room(ETP,TP->QCN+" searches the room and finds a small panel built into the wall.",TP);
    tell_object(TP,"You search the room and find a small panel built into one of the corner walls. ");
    found = 1;
    return;
}

void search_panel()
{
    if(found == 1) 
    {
        tell_room(ETP,TP->query_cap_name()+" searchs the panel and finds that it is loose.",TP);
        tell_object(TP,"You find a loose panel, which you remove promptly.");
        set_items((["panel":"You single panel with a single socket.",]));
        found = 2;
        return;
    }
    else write("What panel?");
    return;
}
