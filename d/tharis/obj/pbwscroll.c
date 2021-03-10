#include <std.h>

inherit OBJECT;


void create() {
        ::create();

        set_id(({"scroll"}));
        set_name("scroll");
        set("short","a scroll");
        set("long",
@OLI
	This scroll is covered with little signs of wards.
	Both ends have images of dragons breathing fire on a man.
	<read only one at a time for best effect>
OLI
	);
        set_weight(2);
        set_value(100);
}

int __Read(string str) {

        if(!str) return 0;
        if(str != "scroll") return 0;
        write(" %^BOLD%^%^YELLOW%^You read the scroll and the images of dragons glow and change.\n\n The dragons have stopped breathing.");
        tell_room(environment(TP),TPQCN+" reads the scroll.",TP);
        set("long","This scroll is glowing you can not make out the symbols.");
        remove_action("read","read");
        call_out("dest",(roll_dice(2,40)+1),TP);
		TP->set_property("strength",({"breath weapon"}));
        return 1;
}

void dest(object person) {
		string *stuff;
		stuff = person->query_property("strength");
		write("stuff size = "+sizeof(stuff));
			stuff -= ({"breath weapon"});
        	person->remove_property("strength");
        	person->set_property("strength",stuff);
        tell_object(person,"%^BOLD%^%^YELLOW%^The scroll suddenly stops glowing and crumbles.");
        TO->remove();
}
