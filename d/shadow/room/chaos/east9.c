#include "chaos.h"

inherit VAULT;
int step;

void create() {
    ::create();
    set_property("light", 3);
    set_property("indoors", 1);
    set_short("The East Room");
    set_long( "This is the East room. \n"
	"This room is bright. There is nothing in it except a small "
	"incense burner in the center of the floor. The rest of the room is plain. "
	" There are no paintings on the walls, not even dust on the floor. "
		
    );
    set_exits( ([
	"west" : CHAOSDIR+"floor9"
        ]) );
    set_door("east door",CHAOSDIR+"floor9","west",0);
    set_smell("default","The smell of jasmine incense fills your nose.");
    set_listen("default","The sounds of silence fills your ears.");

    set_items(( [
	"incense burner":"It is a small golden burner, shaped like a dragon. It has an new incense stick in it.",
	"incence stick":"It is small and smells like jasmine."
    ] ));
    step = 0;
    set_search("default","You find an incense burner.");
    set_search("burner",(:TO,"search_it":));
    set_search("stick",(:TO,"search_it":));
    set_search("shape",(:TO,"search_it":));
    set_search("robe",(:TO,"search_it":));
    set_search("brick",(:TO,"search_it":));
    set_search("opening",(:TO,"search_it":));
    
}
void reset(){
    ::reset();
//	if(!present("glass case"))
//	    new(MISCDIR+"helmut_case")->move(TO);
//	if(!present("mage"))
//		new(MONDIR+"blackmage")->move(TO);

}
int search_it(string str){
    string temp;
	if(!str) return 0;
	if(!sscanf(str,"%s",temp)) return 0;

	if((temp == "burner") && (step >= 0)){
		step = 1;
        	write("The incense burner has a fresh stick of incense in it.");
		return 1;
	}
	if((temp == "stick") && (step >= 1)){
		step = 2;
    		write("The incense stick is un-used. Perhaps you could light it?");
		add_action("light_it","light");
		return 1;
	}
	if((temp == "shape") && (step >= 3)){
		step = 4;
    		write("The shape is vague. But as you look closer, you see that it appears to be in the shape of a robe.");
		return 1;
	}
	if((temp == "robe") && (step == 4)){
		step = 5;
    		write("You can't touch it, but you can see it. Something appears out of the corner of your eye.");
    		set_long( "This is the East room. \n"
			"This room is bright. There is nothing in it except a small "
			"incense burner in the center of the floor. The rest of the room is plain. "
			" There are no paintings on the walls, not even dust on the floor. "
			"There is a discolored brick on the north wall."
		);
		return 1;
	}
	if((temp == "brick") && (step == 5)){
		step = 6;
		write("It is an ordinary brick, but the color is wrong. It doesn't match the rest of the bricks.");
		add_action("push_it","push");
		return 1;

	}
	if((temp == "opening") && (step == 7)){
		step = 8;
		write("As you reach into the hole, you feel a cloth. You pull it out, to discover it is a robe.");
		new("/d/shadow/obj/magic/blackrobe.c")->move(TP);
		return 1;
	}
	return notify_fail("You don't notice that here.");
}
int light_it(string str){
    string is_latch;
	if(!str) return notify_fail("Press what?\n");
	if(!sscanf(str,"%s",is_latch)) return notify_fail("try 'light incense'!\n");
	step = 3;
	write("You reach down and light the incense. A jasmine fragrance fills");
	write("the room. A haze starts to build up. The incense burns quickly, ");
	write("and soon goes out. The haze starts to take on a shape.");
	remove_action("light_it","light");
	return 1;
}
int push_it(string str){
	if(!str) return 0;
	if(str != "brick") return 0;
	step = 7;
	write("As you push on the brick, you hear a grinding noise behind you.");
	write("as you look at the south wall, you notice there is a small opening, in the center of the wall.");
	return 1;

}
