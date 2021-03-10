//  This area is to be DEATH to anyone that enters it.  there is NO way out.
//     if you are a wiz reading this... LET THEM DIE
//     Love. G.
#include <std.h>

inherit ROOM;
string *exts;

void create(){
    ::create();
    set_name("The flames of hell");
    set_short("%^RED%^Your own personal corner of HELL%^RESET%^");
    set_long(
      "%^BOLD%^%^RED%^All around you all you see are the endless flames of the pits of hell as the reach for you, tauntingly floating away never burning you just slowly roasting you alive.%^RESET%^"
    );
    set_smell("default", "you smell %^RED%^FIRE AND BRIMSTONE%^RESET%^");
    set_listen("default", "You hear the eternal %^RED%^FLAMES%^RESET%^");
    set_property("indoors", 1);
    set_property("no teleport", 1);
    set_property("light", 2);
    set_property("night light", 2);
    set_exits( ([
	"north" : "/d/azha/rift/hell2.c",
	"south" : "/d/azha/rift/hell2.c",
	"east" : "/d/azha/rift/hell2.c",
	"west" : "/d/azha/rift/hell2.c",
	"northwest" : "/d/azha/rift/hell2.c",
	"southwest" : "/d/azha/rift/hell2.c",
	"southeast" : "/d/azha/rift/hell2.c",
	"northeast" : "/d/azha/rift/hell2.c",
      ]) );
    set_heart_beat(8);
}

void init(){
    ::init();
    add_action("peer", "peer");
    add_action("peer", "lpeer");
    exts = ETP->query_exits();
    if(member_array("rift",exts) != -1){
	TO->remove_exit("rift");
	tell_room(ETP, "%^RED%^%^BOLD%^As you step through the portal, you realize that somthing has gone very wrong as the portal closes before you leaving you in this corner of hell.");
    }
}

int peer(){
    write("%^RED%^All you see is FLAME");
    return 1;
}

void heart_beat(){
    object *starved;
    int i,j;
    starved = all_living(TO);
    j = sizeof(starved);
    for(i=0;i<j;i++){
	    tell_object(starved[i],"%^BOLD%^%^RED%^The flames lick at your flesh torturing you endlessly.");
	    if(!wizardp(starved[i])){
            starved[i]->cause_typed_damage(starved[i], starved[i]->return_target_limb(), roll_dice(5, 5), "fire");
	        starved[i]->add_attacker(TO);
	        starved[i]->continue_attack();
	    }
    }
}
