#include <std.h>
inherit ROOM;

void diving(object tp, int num);

void create(){
    ::create();
    set_name("Tharis caverns");
    set_short("A dark cavern");
    set_long(
	"You have entered a very large cavern. A massive pool "+
   "of water covers most of the cave. The stream runs and empties into "+
	"the pool from the west. The small lake looks extremely deep, for "+
	"the water is very clean but you cannot see the bottom. A green "+
	"light emerges from the pool. The cavern is poorly lit, only the "+
	"green light from the pool helps your vision."
    );
    set_property("light",2);
    set_property("indoors",1);
    set_property("no teleport",1);
    set_smell("default","The air is fresh and clean.");
    set_listen("default","Rushing water can be heard coming from the lake.");
    set_items( ([
	({"pool"}):"The pool of water is very large. A green glow comes from its depths. There seems to be a current in the water coming from the wall across the room...strange..."
    ]) );
    set_exits( ([
	"east":"/d/tharis/caverns/cavern7"
    ]) );
}
void init(){
    ::init();
    add_action("dive","dive");
}
int dive(){
    TP->set_paralyzed(5000,"You are unable to do that!");
    diving(TP,0);
    return 1;
}

void diving(object tp, int num)
{
    switch(num)
    {
    case(0):
    tell_object(tp,"You dive into the pool and get sucked down underwater!");
    break;
    case(1):
    tell_object(tp,"%^BOLD%^BLUE%^Water rushes past you at a phenomenal rate!");
    break;
    case(2):
    tell_object(tp,"%^BOLD%^BLUE%^You can feel your lungs start to ache from the lack of air...");
    break;
    case(3):
    tell_object(tp,"%^BOLD%^BLUE%^You start to pass out...the world around you goes black...");
    break;
    case(4):
    tell_object(tp,"You can hear the sound of waves crashing onto a beach.");
    break;
    case(5):
    tell_object(tp,"You wake up and find yourself on a sandy shore.");
    tp->move("/d/tharis/caverns/cavern17");
    tp->describe_current_room(1);
    tp->set_paralyzed(0);
    return;
    }
    num++;
    call_out("diving",5,tp,num);
    return;
}
