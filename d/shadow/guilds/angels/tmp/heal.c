//Coded by Bane//
#include <std.h>
inherit ROOM;
void create(){
    ::create();
    set_name("Angel's heal room");
    set_short("Angel's heal room");
    set_long(
	"You are standing in a small cramped room.  A man sits on a stool waiting "+
	"for injured warriors to enter for a healing.  The fallen ones enter here "+
	"to get healed and sent back to the guild hall."
    );
    set_property("indoors",1);
    set_property("light",2);
    set_property("no teleport",1);
    set_property("arena",1);
    set_property("deathmove","/d/shadow/guilds/angels/tmp/heal");
    set_listen("default","The sounds of bubbling liquids can be heard.");
    set_smell("default","The smell of blood is very strong.");
    set_exits( ([
	"out":"/d/shadow/guilds/angels/tmp/hall1"
    ]) );
}
void init(){
    write("The healer sizes up your wounds.");
    call_out("heal1",3,TP);
    return 1;
}
void heal1(){
    write("The healer grabs some bandages and wraps you up nice and good.");
    TP->set_hp(TP->query_max_hp());
    call_out("boot",2,TP);
    return 1;
}
void boot(){
    write("%^MAGENTA%^Healer says%^RESET%^: Now get going!");
    write("Healer shoves you back into the guild hall.");
    TP->move("/d/shadow/guilds/angels/tmp/hall1");
    TP->describe_current_room(1);
    return 1;
}
