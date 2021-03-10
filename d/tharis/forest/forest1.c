//forest1.c
//Changed the pre-exit function to "GoThroughDoor" (singular) so sneaking can't
//get past it.  Also modified the warning sign a little and changed the min.
//level to 10, adding a ckpt. to anyone who tries to enter in spite of the sign
//and also logging it.
//Upping min. level to 15 after discussion with Circe about continued ooc info. abuse *Styx* 11/06/04

#include <std.h>

inherit ROOM;

void create(){
	object ob;
	::create();
	set_terrain(HEAVY_FOREST);
	set_travel(DIRT_ROAD);
	set_name("Forest Path");
	set_short("A small path through the forest");
	set_property("indoors",0);
	set_property("light",1);
	set_long(
@OLI
	%^BOLD%^%^GREEN%^A small twisting path through the forest%^RESET%^
As you enter the forest you notice a quiet all around you. Tall trees
loom over you almost basking in their grandure. Around you you
sense a horrible feeling of pain. Nature's work is here but that
work is being hurt. Small plants grow around the floor of the forest,
fighting for sunshine as it creeps sparcely through the thick canopy.
%^BOLD%^There is a sign here.... READ IT%^RESET%^
OLI
	);
	set_items((["floor":"The ground is cluttered  with twigs and leaves.",
				"trees":"These grand creatures range from oak and hickory to Pine and spruce."
				]));
	set_exits(([
				"north":"/d/tharis/forest/forest2",
				"out":"/d/tharis/road/eroad16"
				]));
        set_pre_exit_functions( ({"out","north"}),({"out_func","GoThroughDoor"}) );
	set_smell("default","The lush fragrances of the forest quell your worries.");
	set_listen("default","The silence of the forest is unnatural, as if all the insects and birds are hiding.");
	if(ob = find_object_or_load("/d/tharis/forest/forest5"))
		ob->reset();
}

int __Read_me(string str){
	if(!str || str != "sign")
		return 0;

	tell_room(TO,TPQCN+" reads over the sign. You should too.",TP);
	write(
@OLI
   %^BOLD%^
   This is meant as a warning.  This area is meant to be extremely difficult.
   Due to abuses, those below level 15 are no longer allowed to enter.
   This area is meant to be difficult and the rewards for higher levels.
   Also this is an area which makes strict use of alignment with
   far-reaching consequences.
OLI
/* first part was - This is meant as a warning. This area is extremely difficult.
	The monsters and traps in here will easily kill anyone below level
	10. And will kill any lone travelers below level 12. At any level
	you are in extreme danger. However, the bold and foolish alike
	are welcome to test their luck, but you've been warned.
*/
	);
	return 1;
}

void init(){
	::init();
	add_action("__Read_me","read");
}

int out_func() {
    if((string)TP->query_name() == "imp") return 0;
    if((string)TP->query_name() == "giantrat") return 0;
    if(!interactive(TP) && (string)TP->query_name() == "spider") return 0;
    return 1;
}
int GoThroughDoor(){
   if(TP->query_highest_level() < 15) {
       "/cmds/avatar/_note.c"->cmd_note("ckpt "+TPQN+" tried to enter Tharis "
          "forest in spite of the warning sign.");
     write("That forest seems too ominous for someone of your level.\n"
          "Read the sign if you didn't already!");
     return 0;
   }
   return 1;
}
