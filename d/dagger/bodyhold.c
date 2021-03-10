#include <std.h>

inherit ROOM;

void create(){
    ::create();
   set_light(3);
    set_property("inside",1);
    set_long(
@DESC
This is the chamber for resetting your body type information.
You will pick a preferred range for height and weight, and will select
a descriptive adjective for your resulting body type.

You will be given 3 chances to change your body type.

When finished, you will be returned to the world of ShadowGate.

    <go>   will begin the setting process
    <view> will display your current height, weight, and body type
    <done> will allow you to leave before your 3 tries are done

DESC
    );
}

void init(){
    ::init();
    add_action("start_set","go");
    add_action("view_settings","view");
    add_action("leave_early","done");
    if(!TP->query("body set"))
        TP->set("body set",2);
    else
        TP->set("body set",(int)TP->query("body set")-1);
}

int start_set(string str){
    TP->move(new("/realms/vetri/bodyreset.c"));
    return 1;
}

int view_settings(string str){
    write("Here are your current settings:");
    write("-------------------------------");
    write("Height: "+TP->query_player_height());
    write("Weight: "+TP->query_player_weight());
    write("Body Type: "+TP->query_body_type());
    return 1;
}
int leave_early(string str){
    if(!TP->query_body_type()){
        write("You cannot leave without setting a body type.");
        return 1;
    }
   TP->move_player("/realms/crystal/colorhold.c");
    return 1;
}

