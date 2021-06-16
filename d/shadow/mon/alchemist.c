#include <std.h>
inherit VENDOR;

void create() {
    ::create();
    set_name("Meguile");
    set_id( ({ "meguile", "clerk", "shop keeper", "shopkeeper"}) );
    set_short("Meguile, The Alchemist");
    set("aggressive", 0);
    set_level(19);
    set_long("Meguile always seems busy grinding something into a powder "+
        "in a mortar and pestle, portioning out something into small packets, or "+
        "counting out other items the local magi need for spells. He's tall, "+
        "lanky and dresses simply, but clearly knows his alchemy.  His bright blue "+
        "eyes give a hint of his intelligence and the years of study he's devoted "+
        "to his alchemy. He's a helpful sort and tries to keep his shelves well "+
        "stocked as well as provide advice to the new magi if you get his "+
        "attention with a question."+
        "\n\n<help shop> will get you a list of shop commands.");
    set_gender("male");
    set_alignment(5);
    set("race", "human");
    set_hd(19,1);
    set_exp(20);
    set_body_type("human");
    set_property("no bump", 1);
    set_storage_room("/d/shadow/mon/alchemist_storage.c");
    set_items_allowed("misc");
    set_mymaxvalue(1);
}

