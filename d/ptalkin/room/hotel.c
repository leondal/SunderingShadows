#include <std.h>
#include "/d/ptalkin/ptalkin.h"
inherit HOTEL;
void create(){
    ::create();
    set_property( "light" , 3);
    set_property("indoors" , 1);
set_short("%^BOLD%^RED%^Hotel D'lyssa");
set_long("%^ORANGE%^As you walk into the hotel, the first thing you notice, is how clean and tidy the hotel is. D'lyssa, herself, is greeting patrons and newcomers.  The room has elegantly carved chairs and small tables set with flowers.  A clerk waits behind a counter, pen poised over a ledger.  Should you need help in deciding upon what type of room you require, D'lyssa suggests <help hotel> will give you all the information you may need.");
set_smell("default", "%^GREEN%^You can smell ink, flowers, and perfume of the many travellers.");
set_listen("default", "%^RED%^You hear papers being rustled and people talking quietly.");
    set_exits( ([
"out" : PROOM+"room51.c"
             ]) );
    set_rooms(([
        "westgroup":6,
        "eastgroup":5,
        "southroom":3,
        "singleroom":1,
        "doubleroom":2,
        "tripleroom":3,
        "quadroom":4,
        ]));
    set_cost(10);
set_items(([
"chairs" : "Elegantly carved rosewood chairs are padded with petit point cushions in rose and lilac designs",
"tables" : "Small rosewood tables sit beside the chairs, with urns of flowers resting upon them",
"flowers" : "Urns of roses, goldenslippers and eveningstars from the flower shop rest upon the tables",
"clerk" : "A tiny little clerk, elf in race, waits behind the counter, pen in hand",
"counter" : "The counter, six feet in length and approximately 3 and a half feet high is also made of carved rosewood",
"pen" : "A tall dirwen feather with a gold nib rests in the hands of the clerk",
"ledge" : "A large black leather bound book lies upon the counter waiting for patrons to sign in"
]));
}
