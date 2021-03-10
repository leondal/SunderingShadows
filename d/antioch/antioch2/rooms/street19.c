#include <std.h>
#include "../antioch.h"
inherit CVAULT;

void create()
{
        set_monsters( ({ "/d/antioch/antioch2/mons/patrol_guard", }), ({ roll_dice(1, 4) + 1, }), );
        ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
        set_property("indoors",0);
        set_property("light",2);
        set_short("%^RED%^C%^RED%^h%^RED%^e%^BOLD%^%^RED%^rry%^RESET%^ Street");
        set_long(
        "%^ORANGE%^You are on %^MAGENTA%^%^RED%^C%^RED%^h%^RED%^e%^BOLD%^%^RED%^rry%^RESET%^ %^RED%^stre%^RESET%^%^RED%^e%^BOLD%^%^RED%^t%^RESET%^ %^RESET%^\n"+
        "%^ORANGE%^A strange musky odor hangs in the air here. It is coming from the %^BOLD%^%^BLACK%^sho%^RESET%^%^ORANGE%^p%^ORANGE%^ directly south. It is a little house with a red roof and the sign of a mage's component shop out front. On the sign is a picture of a lizard's tail. The door is made of a dark walnut wood and looks sturdy. To the north there is a building that is marked as the general store, it has a pine wood door, in fact, the entire building seems to be made out of pine. There you can buy basic things and any odds and ends you might need. A sign that hangs over the doorway has a picture of a winged griffin on it. To the west %^RED%^C%^RED%^h%^RED%^e%^BOLD%^%^RED%^rry%^RESET%^ %^RED%^stre%^RESET%^%^RED%^e%^BOLD%^%^RED%^t%^RESET%^  joins with %^BOLD%^%^BLACK%^P%^RESET%^%^GREEN%^ine %^GREEN%^str%^BOLD%^%^BLACK%^e%^RESET%^%^GREEN%^e%^BOLD%^%^BLACK%^t%^RESET%^ and %^GREEN%^A%^RED%^pp%^GREEN%^l%^RED%^e %^RED%^st%^GREEN%^r%^RED%^eet%^RESET%^ right outside the stables. To the east is a very large %^BOLD%^%^CYAN%^f%^RESET%^%^CYAN%^ount%^BOLD%^%^CYAN%^a%^RESET%^%^CYAN%^in%^ORANGE%^ and the intersection of %^RED%^C%^RED%^h%^RED%^e%^BOLD%^%^RED%^rry%^RESET%^ and %^WHITE%^O%^WHITE%^a%^WHITE%^k %^WHITE%^s%^BOLD%^%^BLACK%^t%^RESET%^%^WHITE%^r%^BOLD%^%^BLACK%^eet%^RESET%^. All the way at the end of the street there is an impressive stone church.
"
        );
        set_smell("default","There is an odd musky scent coming from"+
        " the component shop on the south.");
        if(query_night() == 1) {
                set_listen("default","The gurgle of the fountain is very"+
                " relaxing.");
        }
        else {
                set_listen("default","The street is buzzing with the"+
                " shoppers and store owners haggling over prices.");
        }
        set_items(([
        ({"street","cobblestones","cobbles","road","path"}) : "The"+
        " street is paved with cobblestones.",
        "street sign" : "This is %^MAGENTA%^%^RED%^C%^RED%^h%^RED%^e%^BOLD%^%^RED%^rry%^RESET%^ %^RED%^stre%^RESET%^%^RED%^e%^BOLD%^%^RED%^t%^RESET%^ %^RESET%^",
        "fountain" : "There is a fountain to the east of here.",
        "shops" : "There are many shops along this street.",
        ]));
        set_exits(([
        "west" : ROOMS+"street18",
        "east" : ROOMS+"fountain",
        "south" : ROOMS+"component",
        "north" : ROOMS+"general",
        ]));
        set_door("walnut door",ROOMS+"component","south",0);
        set_door("pine door",ROOMS+"general","north",0);
        if(query_night() == 1) {
                set_open("walnut door",0);
                set_open("pine door",0);
            find_object_or_load("/d/antioch/antioch2/rooms/component.c")->set_open("walnut door",0);
                find_object_or_load("/d/antioch/antioch2/rooms/general.c")->set_open("pine door",0);
        }
        else if(query_night() != 1) {
                set_open("walnut door",1);
                set_open("pine door",1);
                find_object_or_load("/d/antioch/antioch2/rooms/component.c")->set_open("walnut door",1);
                find_object_or_load("/d/antioch/antioch2/rooms/general.c")->set_open("pine door",1);
        }
}

void reset()
{
        ::reset();
        if(!present("street_light")) {
                new(OBJ+"street_light")->move(TO);
        }
        if(query_night() == 1) return;
        else if(!present("citizen")) {
             switch(random(4)) {
                        case 0:
                                new(MONS+"citizen1")->move(TO);
                                break;
                        case 1:
                                new(MONS+"citizen2")->move(TO);
                                break;
                        case 2:
                                new(MONS+"citizen3")->move(TO);
                                break;
                        case 3:
                                new(MONS+"citizen4")->move(TO);
                                break;
                }
        }
}
