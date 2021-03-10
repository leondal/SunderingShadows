#include <std.h>
inherit ROOM;
void create(){
    ::create();
    set_name("Bridge over troubled waters");
    set_short("Bridge over troubled waters");
     set_long("
    You find yourself within a thundering cave where underground rivers pour into a deep chasm beneath you.  You are standing before a long, ancient bridge of stone that spans the chasm to reach large doors on the other side.  The ceiling and walls of the chamber are jagged and covered with smoky quartz.
    A fine mist covers you.
    ");
    set_smell("default","You detect a hint of sulfur in the air.");
    set_listen("default","The crashing waters are nearly deafening in this echo prone cave.");
    set_items( ([ 
    "bridge" : "The bridge is about two hundred feet long and spans the deep chasm of crashing water.  It is covered in ancient symbols and pictograms.",
    "symbols" : "They are carved directly into the granite of the bridge...  You cannot read them but they are appearantly footnotes to repeating pictograms.",
    "pictograms" : "They are ancient and depict hoards of screaming people running from a burning village.",
    "quartz" : "The shards of black crystal glisten in the dim lighting.",
    "chasm" : "The shadowy chasm is fed by about six underground rivers that converge here.  It decends to unseen depths in the darkness below.",
    ]) );
    set_property("indoors",1);
    set_property("light",2);
	set_property("no sneak",1);
    set_property("no teleport",1);
    set_property("no steal",1);
    set_pre_exit_functions(({"north"}),({"go_north"}));
    set_exits( ([
	"south":"/d/shadow/room/cave/cave1",
	//"north":"/d/shadow/guilds/pack/bridge2.c"
    ]) );
}
void reset(){
    ::reset();
    if(!present("dartanion")){
	new("/realms/zerina/pack/packguard")->move(this_object());
    }
}
int go_north(){
    if((string)TP->query_guild() != "Shadows of Fate"){
    if(present("dartanion")){
	write("Dartanion grabs you and throws you to the ground.");
tell_room(TO, "Dartanion grabs "+TPQCN+" and throws them to the ground.",TP);
	return 0;
    }
    }
    return 1;
}
void init()
{
	::init();
	add_action("sneak","sneak");
}
int sneak()
{
	write("%^BOLD%^%^BLUE%^You fucking loser! You can't sneak here.");
return 1;
}
