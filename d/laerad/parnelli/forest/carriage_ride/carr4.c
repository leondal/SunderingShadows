//Coded by Bane//
#include <std.h>
inherit ROOM;
void driving(object targ, int num);
void create(){
    ::create();
    set_terrain(HUT);
    set_travel(PAVED_ROAD);
    set_name("Carriage");
    set_short("A nice carriage");
    set_long(
	"You are sitting in a beautiful carriage.  The windows are open so "+
	"that you can see the country side as you travel.  A man sits outside "+
	"on a bench controlling the speed and direction of the horses driving "+
	"the carriage."
    );
    set_property("light",2);
    set_property("indoors",1);
    set_property("no teleport",1);
    set_smell("default","The air is fresh and clean.");
    set_listen("default","The pounding of the horses hooves on the ground can be heard.");
}
void init(){
    ::init();
    call_out("driving",10,TP,0);
}
void driving(object targ, int num){
  if (!present(targ,TO)) return;
    switch(num){
    case(0):
    tell_object(targ,"\n%^BOLD%^The driver calls out his departure and snaps the reins.\n");
    break;
    case(1):
    tell_object(targ,"\n%^BOLD%^The horses gallop off into the valley past the carriage house.\n");
    break;
    case(2):
    tell_object(targ,"\n%^BOLD%^The carriage bounces up and down as the horses rush through the valley of mountains surrounding you.\n");
    break;
    case(3):
    tell_object(targ,"\n%^BOLD%^The beautiful scenery rushes past the carriage at a rather fast rate.\n");
    break;
    case(4):
    tell_object(targ,"\n%^BOLD%^At last the horses and carriage start to slow down.\n");
    break;
    case(5):
    tell_object(targ,"\n%^BOLD%^The carriage comes to a stop at another carriage house at the gods plains entrance.\n");
    break;
    case(6):
    tell_object(targ,"\nThe driver yells for everyone to get out.\n");
    targ->move_player("/d/laerad/parnelli/forest/carr1");
    tell_room(environment(targ),targ->query_cap_name()+" steps off the carriage.",targ);
    return;
    }
    num++;
    call_out("driving",5,targ,num);
    return;
}
