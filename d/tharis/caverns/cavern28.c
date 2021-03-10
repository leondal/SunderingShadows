#include <std.h>
inherit ROOM;
void create(){
    ::create();
    set_name("Tharis caverns");
    set_short("A dark cavern");
    set_long(
	"You have entered a dark and dreary cave. This cave starts on an "+
	"upward slope. The water in this room measures only about 4 inches "+
	"deep. A few torches remain lit in the cavern."
    );
    set_property("indoors",1);
    set_property("light",2);
    set_property("no teleport",1);
    set_smell("default","The air in the room smells a bit cleaner than the previous tunnels.");
    set_listen("default","The sound of water rushing into the other caves can be heard.");
    set_exits( ([
	"southeast":"/d/tharis/caverns/cavern27",
	"north":"/d/tharis/caverns/cavern30"
    ]) );
    set_pre_exit_functions( ({"north"}),({"north"}) );
}
void north(){
    int AC, roll;
    AC=TP->query_ac();
    roll=random(20);
    tell_object(TP,"You hear a soft click.");
    tell_room(environment(TP),"You hear a soft click.",TP);
    if(roll > 10-AC){
	TP->do_damage("torso",roll_dice(2,6));
	tell_object(TP,"You get nailed in the chest with a barbed dart!");
	tell_room(environment(TP),""+TP->query_cap_name()+" gets nailed in the chest with a barbed dart!",TP);
	return 1;
    }
    tell_object(TP,"A dart wizzzzzzzes past your face!");
    tell_room(environment(TP),"A dart wizzzzzzzes past the face of "+TP->query_cap_name()+"!",TP);
    return 1;
}
