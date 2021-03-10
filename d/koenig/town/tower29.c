//tower29.c

#include <std.h>

inherit ROOM;

void create(){
	::create();
   set_terrain(WOOD_BUILDING);
   set_travel(PAVED_ROAD);

	set_properties((["light":2,"indoors":1,"no teleport":1]));
	set_short("At the Top of the Tower");
	set_long("%^BOLD%^%^WHITE%^You have done well. The top was your goal, and now you are here. What "+
"do you think you will find? What will you do when you find it? You are "+
"here, and you will have to deal with whatever occurs... or have it deal "+
"with you. You notice a thick layer of %^RESET%^dust%^BOLD%^%^WHITE%^ on the floor. You are not sure "+
"if this bodes well that no one has been here yet, or if it bodes badly "+
"that whatever has been didn't leave any prints.%^RESET%^\n");
	set_exits(([
		"east":"/d/koenig/town/tower30",
		"west":"/d/koenig/town/tower31",
                "north":"/d/koenig/town/tower"+(random(3)+32)
		]));
	set_items(([
		"dust":"%^BOLD%^%^BLACK%^This isn't normal dust. It's from the ceiling. Something"+
				" shake this room so as to make this dust rain down."
		]));

	set_listen("default","You hope you don't hear anything.");
	set_smell("default","Dust and dirt bother your nose.");

        call_out("new_north",random(60)+1);
//new("/d/common/assassins/freloc")->move(TO); //Fuck this guy, he only punishes true newbies - Odin 5/7/2020
}

void new_north(){
	int i;
	string path;

	i = random(3);
	switch (i){
		case 0:
			path = "/d/koenig/town/tower32";
			break;
		case 1:
			path = "/d/koenig/town/tower33";
			break;
		case 2:
			path = "/d/koenig/town/tower34";
			break;
	}

	TO->set_exits(([
		"east":"/d/koenig/town/tower30",
		"west":"/d/koenig/town/tower31",
		"north":path
		]));


	tell_room(TO,"%^BOLD%^%^RED%^The room starts to shake. Clouds of dust"+
		" rise from the ground and fall from the ceiling.");
	tell_room(find_object_or_load("/d/koenig/town/tower32"),"%^BOLD%^%^RED%^The room starts to shake. Clouds of dust"+
		" rise from the ground and fall from the ceiling.");
	tell_room(find_object_or_load("/d/koenig/town/tower33"),"%^BOLD%^%^RED%^The room starts to shake. Clouds of dust"+
		" rise from the ground and fall from the ceiling.");
	tell_room(find_object_or_load("/d/koenig/town/tower34"),"%^BOLD%^%^RED%^The room starts to shake. Clouds of dust"+
		" rise from the ground and fall from the ceiling.");
        call_out("new_north",random(60)+1);
}
