#include <std.h>
inherit ROOM;
void create(){
    ::create();
    set_name("Tharis caverns");
    set_short("A dark cavern");
    set_long(
	"You have entered a dark dreary cave. The room is fairly small and "+
	"very dirty. Pieces of stone lie all over the floor. Four pillars "+
	"about 5 feet in diameter rise up from the ground and stretch up "+
	"to the ceiling. The pillars are slanting, almost to the point of "+
	"falling over. The base of the scructures are covered in runes."
    );
    set_property("indoors",1);
    set_property("light",2);
    set_property("no teleport",1);
    set_smell("default","The air is old and stale.");
    set_listen("default","You hear nothing but silence.");
    set_items( ([
	({"stone"}):"Little pieces of stone. They look like they were broken off a statue or something.",
	({"pillars"}):"Four pillars that rise about 15 feet into the ceiling. The base of the pillars are covered in some strange runes.",
	({"runes"}):"The runes seem to glow a faint red, they are written in some strange language that you cannot understand."
    ]) );
    set_exits( ([
	"south":"/d/tharis/caverns/cavern6",
	"north":"/d/tharis/caverns/cavern22"
    ]) );
    set_trap_functions( ({"north"}),({"shock"}),({"move"}) );
}
void shock(){
    int shock, damage;
    {
    tell_object(TP,"As you pass through the pillars a jolt of blue light streaks between them shocking you!\n");
    say("A jolt of blue light streaks between the pillars lighting up the room!\n",TP);
    shock=1;
    damage=random(15)+5;
    TP->do_damage("torso",(shock*damage));
    return 1;
    }
    TP->force_me("north");
    return 1;
}
