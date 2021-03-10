#include <std.h>

inherit ROOM;

void create(){
    ::create();
    set_short("Alignment change room");
    set_long(
@DESC
%^BOLD%^Pick from the following alignments:
    1. Lawful Good
    2. Lawful Neutral
    3. Lawful Evil
    4. Neutral Good
    5. True Neutral
    6. Neutral Evil
    7. Chaotic Good
    8. Chaotic Neutral
    9. Chaotic Evil
DESC
    );
    set_property("light",2);
    set_property("indoors",1);
}

void init(){
    ::init();
    write(
@MSG
%^BOLD%^Pick a new alignment. If you want to keep your old
one, just pick it again. This is your one and only chance
to get a free alignment change. From here, go to pick your
new diety, since you shouldn't have one right now.
MSG
    );
    add_action("pick_align","pick");
}

int pick_align(string str){
    int align;
    
    if(!str) return notify_fail("Try picking an alignment.\n");
    if(TP->query("free align change")) return notify_fail("You already did this.\n");
    align = atoi(str);
    if(member_array(align,({1,2,3,4,5,6,7,8,9})) != -1){
        TP->set_alignment(align);
        TP->set("free align change",1);
        TP->move_player("/d/magic/temples/main");
        tell_object(TP,"%^BOLD%^Now you have to go pick a diety to follow before you can get a holy symbol.");
        tell_object(TP,"%^BOLD%^Go into the temple for the diety you want, and type <choose <name>>.");
        return 1;
    }
    else return notify_fail("Pick an alignment between 1 and 9.\n");
}
