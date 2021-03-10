//added hitching post - Circe 4/23/04
//	The Royal Southern Road
//	Thorn@Shadowgate
//	10/2/94
//	Darkwood forest
//	road7
/*Updated by Circe 10/4/03 to include room name, smell, listen and to use inherits to save on memory. Also, a few rooms were added to fix the way the area looks when mapped.*/

#include <std.h>

inherit VAULT;

void create() {
    object obj;
    ::create();
    set_terrain(LIGHT_FOREST);
    set_travel(DIRT_ROAD);
    set_light(2);
    set_indoors(0);
    set_property("night light",2);
    set_name("Magistrate's Southern Road");
    set_short("%^MAGENTA%^%^BOLD%^Rhapsody Clearing%^RESET%^");
set_long(
@THORN
%^BOLD%^%^GREEN%^Rha%^CYAN%^p%^GREEN%^sody %^CYAN%^C%^MAGENTA%^lear%^CYAN%^i%^MAGENTA%^ng%^RESET%^
%^GREEN%^You are now on the edge of the forest. From what you can tell, it is rather difficult to see in the forest as it is filled with a mixture of coniferous and %^BOLD%^%^GREEN%^d%^CYAN%^e%^GREEN%^ciduious%^RESET%^%^GREEN%^ trees that seem to form a perfect canopy. This canopy is very effective at blocking out sunlight. On the east is a large wooden building. Just north of the building is a shady, grassy area set with tethering posts. There is a %^BOLD%^%^MAGENTA%^si%^MAGENTA%^g%^MAGENTA%^n%^RESET%^%^GREEN%^ for you to read planted in the ground.
THORN
);
    set_exits(
              (["north" : "/d/darkwood/room/road6",
                "south" : "/d/darkwood/room/road8",
                "inn": "/d/darkwood/room/rhapsody",
                "northeast" : "/d/darkwood/room/tetherarea",
       ]) );

    set_items(
              (["sign" : "A painting of a beautiful black haired nymph playing a lute.  An inscription beneath the painting reads: Rhapsody Inn."]) );

   obj = new("std/bboard");
   obj->set_name("board");
   obj->set_id(({"board","bulletin board","events board","rhapsody board"}));
   obj->set_board_id("rhapsody_board");
   obj->set_short("The Rhapsody Events Board");
   obj->set_long("This small board has been established outside the Rhapsody Inn"+
   " to alert passers-by of the upcoming events that are to take place here."+
   " Shows, dances, gatherings, poetry recitals, songs, these are just a few"+
   " of the many events held at the Rhapsody. If you are not involved with"+
   " these events, then please do not post on this board or remove posts"+
   " of the events.\n");
     obj->set_max_posts(15);
   obj->set_location("/d/darkwood/room/road7.c");

   set_door("door","/d/darkwood/room/rhapsody","inn","rhapsody key");
    set_smell("default","The heavy scent of pine mingles with the delicious aroma of something cooking.");
    set_listen("default","Occasional bursts of laughter and song pierce the silence.");

}
