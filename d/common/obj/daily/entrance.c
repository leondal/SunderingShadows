#include <std.h>
#include <daemons.h>

inherit ROOM;

object *current_travelers = ({  });

string *query_current_travelers()
{
    return current_travelers;
}

string *add_traveler(object ob)
{
    current_travelers += ({ ob });
    
    return current_travelers;
}

string *remove_traveler(object ob)
{
    current_travelers -= ({ ob });
    
    return current_travelers;
}

void create()
{   
    ::create();
    set_property("indoors",0);
    set_property("light",2);
    set_property("no sticks",1);
    //set_no_clean(1);

    set_short("Entrance to the Demiplanes");
    set_long("Entrance to the Demiplanes.");

    set_smell("default","The air is full of a strange scent.");
    set_listen("default","You hear nothing but your own thoughts.");
    set_heart_beat(1);
}

void init()
{
    ::init();
    
    add_action("close", "close");
    add_action("open", "open");
}

int open(string str)
{
    object compiler;
    
    if(str != "demiplane")
    {
        write("Perhaps you'd like to <open demiplane> ?");
        return 1;
    }
    if(member_array(this_player(), current_travelers) >= 0)
    {
        write("You already have a demiplane open. Type <close demiplane> to close it.");
        return 1;
    }   
    if(this_player()->cooldown("daily demiplane"))
    {
        write("You need to wait to open another demiplane. Type <cooldowns> to see your cooldowns.");
        return 1;
    }
    
    write("Initiating demiplane teleport...");
    
    if(catch(compiler = new("/d/common/obj/daily/compiler")))
    {
        write("Demiplane compile error!");
        return 1;
    }
    
    this_player()->set_property("demiplane compiler", compiler);
    compiler->compile_plane(this_player());
    add_traveler(this_player());
    //once per day
    //this_player()->add_cooldown("daily demiplane", 86400); //commented out for testing purposes
    
    return 1;
}
