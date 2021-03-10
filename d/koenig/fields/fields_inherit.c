//created to update the cornfield area after Newbietown went in (by Styx). Updated again by Circe 9/24/03
//changed by Circe 12/30/03 after the re-sowing of the fields by Tengri.

#include <std.h>

inherit ROOM;

void create()
{
    ::create();
    set_terrain(GRASSLANDS);
    set_travel(RUTTED_TRACK);
    set_property("light", 3);
    set_property("indoors", 0);
    set_name("In a vast corn field");
    set_short("In a vast corn field");
    set_long(
        "This large tract of land has been sown with tall %^BOLD%^%^GREEN%^stalks " +
        "%^RESET%^of %^YELLOW%^corn%^RESET%^ that grow tall all around you. " +
        "Narrow pathways, such as the one you stand on, form straight rows " +
        "between the healthy %^YELLOW%^cornstalks%^RESET%^ and allow passage " +
        "through the field. This field helps supply food to the cities " +
        "nearby, and it seems to be well-tended. "
        );
    set("night long", "%^GREEN%^The light of the moon reflects off the %^BOLD%^%^GREEN%^" +
        "cornstalks%^RESET%^%^GREEN%^, bathing them in %^BOLD%^%^WHITE%^silvery light" +
        "%^RESET%^%^GREEN%^. The corn has been divided into rows with narrow lanes that allow passage, " +
        "although it can be difficult to find a clear way through the shadows " +
        "cast by the stalks. The ground looks uneven with the flickering light " +
        "as it shines through the corn. "
        );
    set_items(([
                   ({ "corn", "cornstalks", "stalks", "stalks of corn" }) : "Tall, healthy stalks " +
                   "support %^YELLOW%^golden ears of corn %^RESET%^nearly bursting from " +
                   "their %^BOLD%^%^GREEN%^husks%^RESET%^.",
                   ({ "field", "here", "land", "ground" }) : "The whole area has been tilled " +
                   "so that the rich black soil will support the growing corn. No grass " +
                   "grows in the area.",
                   ]));
    set_smell("default", "The earthy scent of the fields is light on the air.");
    set_listen("default", "A gentle breeze rustles the stalks of corn in the field.");
}

void init()
{
    ::init();
}

void reset()
{
    ::reset();
}
