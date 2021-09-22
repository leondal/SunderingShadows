#include <std.h>
#include <daemons.h>

inherit ROOM;
inherit "/std/virtual/compile";

int is_virtual() { return 1; }

object owner, compiler;

void create()
{   
    ::create();
    set_property("indoors",0);
    set_property("light",2);
    set_property("no sticks",1);
    //set_no_clean(1);

    set_short("Plane of Shadows");
    set_long("You are lost in the Plane of Shadow.");

    set_smell("default","The air is full of a strange scent.");
    set_listen("default","You hear nothing but your own thoughts.");
}

void init()
{
    ::init();

    add_action("leave", "leave");
}

int leave(string str)
{
    if(this_player() != owner)
        return 0;
    
    if(str != "demiplane")
    {
        write("Perhaps you'd like to <leave demiplane> ?");
        return 1;
    }
    
    write("Are you sure you want to leave the demiplane? Your demiplane will collapse and cease to exist [y/n]: ");
    input_to("finish_leave");
    return 1;
}

int finish_leave(string str)
{   
    if(str != "y" && str != "Y" && str != "yes" && str != "Yes")
    {
        write("You decide to stay within the demiplane.");
        return 1;
    }
    
    write("You decide to leave the demiplane and you begin to see it fade around you.");
    compiler = this_player()->query_property("demiplane compiler");
    
    if(objectp(compiler))
        compiler->destroy_plane(owner);
    else
    {
        write("You are transported elsewhere.");
        this_player()->move_player("/d/common/obj/daily/entrance");
    }
    
    return 1;
}

object set_owner(object who)
{
    objectp(who) && owner = who;
    
    return owner;
}

object set_compiler(object ob)
{
    objectp(compiler) && compiler = ob;
    
    return ob;
}

int is_demiplane_room()
{
    return 1;
}

void remove()
{
    object *inv;
    
    inv = all_inventory(this_object());
    
    tell_room(this_object(), "The plane collapses and you are whisked away just in time!");
    
    foreach(object ob in inv)
    {
        if(playerp(ob))
            move_player(ob, (object)"/d/common/obj/daily/entrance");
    }
    
    objectp(compiler) && compiler->destroy_plane();
    
    ::remove();
}
