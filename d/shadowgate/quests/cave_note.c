#include <std.h>

inherit "std/quest_ob";

void create() {
set_name("Pipe Quest");
      set_id( ({ "note", "cave note","quest_object","Pipe Quest"}) );
    set_short("Note for Rufsu");
    set_long(
	"Give this note to the Wizard in the Dragon Den Caves,\n"
	"north of Shadow. You will first have to solve the riddle\n"
	"of the statue to open the way to the wizards chambers.\n"
	"All the pieces of the puzzle are in the caves, but beware,\n"
	"do not go alone, without help, you will surely die.\n"
	"Quest Level: 1-8\n"
	"Quest Value: 5 quest points.\n"
    );
    set_quest_points(5);
}
