//      boathouse4.c
//      Pator@shadowgate
//      Wed Apr  5 10:15:32 1995

#include <boathouse.h>

inherit ROOM;

int found;

reset() {
     ::reset();
     if(found) { found = 0; }
	}

void create() {
    room::create();
    set_light(1);
    set_short("Bottom of the lake");
    set("day long",
@DAY
As you dive , you reach the bottom of the lake.  It is filled with lots and
lots of stones and lots of sand.  A shining object is almost totally covered
with the white sand.
DAY
    );
     set("night long",
@NIGHT
As you dive , you reach the bottom of the lake.  It is filled with lots and
lots of stones and lots of sand.  You can't see them, but you feel them
the better.  The thing you saw seems to be covered by something.  It is 
sand, but more white then the surrounding sand.
NIGHT
   );
    set_smell("default","Yeah .. right ... smelling UNDER water ???");
    set_listen("default","As expected just watery noises.");
    set_search("key","You don't see a key");
    set_search("stones","The sand and stones are well mixed");
    set_search("sand","The sand and stones are well mixed");
    set_search("white sand", (: this_object(),"find_key":) );
    set_exits(([
       "up" : WATERM_BH+"boathouse3.c"
    		] ));
    found = 0;
}

int find_key() 
{
 	if (found) {
	    notify_fail("You search the white sand, but find nothing.");
	    return 0;
		   }
	else 

		{	
            new(WATERM_BH+"key1")->move(this_object());
	    write("You found an iron key between the sand.");
	    found = 1;
	    return 1;
		}
}
