//Coded by Bane//
#include <std.h>
inherit "/d/laerad/cavern2/special/cavern.c";
int i, hp, lever;
object file1, file2, *things;
void create(){
    ::create();
    set_short("Laerad caverns");
    set_long(
	"You are in some kind of underground cavern system.  The air here is damp "+
	"and humid.  The area is much darker here below the first level of the caves.  "+
	"The ground is covered in a few inches of water, it trickles down from the "+
	"walls all around you.  Strange mosses and fungi grow on the walls."
    );
    set_property("indoors",1);
    set_property("light",2);
    set_smell("default","The air smells very musty and old.");
    set_listen("default","You can hear the trickling of water down the walls and passages.");
    set_items( ([
	({"rope"}):"A small rope that hangs from the ceiling."
    ]) );
    set_exits( ([
	"north":"/d/laerad/cavern2/cav24",
	"east":"/d/laerad/cavern2/cav22"
    ]) );
    set_trap_functions(({"north","east"}),({"water_trap","water_trap"}),({"north","east"}));
}
void init(){
    ::init();
    add_action("search","search");
    add_action("pull","pull");
}
int water_trap(){
    tell_object(TP,"As you walk through the room you step on a small stone button.");
    tell_room(TO,"The room starts to shake and rumble.");
    tell_room(TO,"%^BOLD%^Huge stone slabs fall in front of the exits closing the room off!");
    call_out("water1",3);
    lever = 1;
    toggle_trap("north");
    remove_exit("north");
    remove_exit("east");
    file1 = find_object_or_load("/d/laerad/cavern2/cav22");
    file1->remove_exit("west");
    file2 = find_object_or_load("/d/laerad/cavern2/cav24");
    file2->remove_exit("south");
    return 1;
}
void water1(){
    if(!lever) return 1;
    tell_room(TO,"The water starts rushing down the sides of the walls in torrents!");
    call_out("water2",15);
    return 1;
}
void water2(){
    if(!lever) return 1;
    tell_room(TO,"The water quickly fills into the room rising to the top!");
    call_out("water3",15);
    return 1;
}
void water3(){
    if(!lever) return 1;
    things = all_living(TO);
    tell_room(TO,"You start sucking water down and realize you are going to drown very soon!");
    for(i=0;i<sizeof(things);i++){
	hp = (int)things[i]->query_max_hp()/5;
	things[i]->do_damage(things[i]->return_target_limb(),random(hp));
	things[i]->add_attacker(TO);
	things[i]->continue_attack();
        if (things[i]->query_hp() < 0) {
            things[i]->add_death("Laerad Caverns");
            things[i]->die();
        }
    }
    if(sizeof(things) != 0){
	call_out("water3",15);
	} else {
	call_out("endit",3);
    }
    return 1;
}
void search(string str){
    if(str) return 0;
    write("You notice a short rope hanging from the ceiling in the corner.");
    return 1;
}
void pull(string str){
    if(!str) return 0;
    if(str != "rope") return 0;
    write("You give the rope a tug!");
    if(lever == 0){
	write("Nothing happens.");
	} else {
	call_out("endit",5);
	lever = 0;
    }
    return 1;
}
void endit(){
    tell_room(TO,"The water starts flowing out of the room quickly!");
    call_out("endit2",10);
    return 1;
}
void endit2(){
    tell_room(TO,"The slabs of stone rise back up into the ceiling and the rest of the water empties out of the room.");
    add_exit("/d/laerad/cavern2/cav22","east");
    add_exit("/d/laerad/cavern2/cav24","north");
    file1 = find_object_or_load("/d/laerad/cavern2/cav22");
    file1->add_exit("/d/laerad/cavern2/cav23","west");
    file2 = find_object_or_load("/d/laerad/cavern2/cav24");
    file2->add_exit("/d/laerad/cavern2/cav23","south");
    return 1;
}
void reset(){
    ::reset();
    if(!trapped("north"))
	toggle_trap("north");
    if(!trapped("east"))
	toggle_trap("east");
}
