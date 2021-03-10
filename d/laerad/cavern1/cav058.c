//Coded by Bane//
#include <std.h>
inherit "/d/laerad/cavern1/special/cavern.c";
int flag;
void create(){
    ::create();
    set_short("Laerad caverns");
    set_long(
	"You are standing in an underground cavern system.  A small stream "+
	"is running along one of the walls winding its way through the room.  "+
	"The ceiling is fairly low, only about 9 feet from the ground.  Lichen "+
	"and other assorted mosses cover about 90 percent of the walls, glowing "+
	"a strange fluorescent yellow and lighting up the area.  Stalagtites "+
	"and stalagmites litter the ceilings and floor."
	"\nThere is a pile of rubble in the middle of the room."
    );
    set_property("indoors",1);
    set_property("light",2);
    set_smell("default","The air is surprisingly clean and refreshing.");
    set_listen("default","You can hear the trickling of the stream.");
    set_items( ([
	({"rubble"}):"The rubble looks as though it is covering something. Mayhaps you can <push> it aside?"
	]) );
    set_exits( ([
	"northwest":"/d/laerad/cavern1/cav056"
    ]) );
    set_pre_exit_functions( ({"down"}), ({"no_mon"}) );
}
void init()
{
    ::init();
    add_action("push","push");
}
void push(string str)
{
    if(!str)
        return notify_fail("Push what?\n");
    if(str != "rubble")
        return 0;
    if(flag == 1)
        return notify_fail("The rubble is already pushed aside.\n");
    TP->use_stamina(roll_dice(2,4));
    if(TP->query_stats("strength") < roll_dice(1,20))
    {
        write("You struggle to push enough rubble aside, but only tire yourself out. This is hard work!");
        return 1;
    }
    write("You push the rubble aside revealing a passage that leads down.");
    tell_room(TO,TPQCN+" pushes the rubble aside.",TP);
    add_exit("/d/laerad/cavern2/cav01","down");
    flag = 1;
    return 1;
}

void reset()
{
    flag = 0;
    remove_exit("down");
}

int no_mon()
{
    if(TP->query_property("wandermon")) return 0;
    else return 1;
}
