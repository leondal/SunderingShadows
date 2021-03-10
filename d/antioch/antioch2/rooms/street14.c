#include <std.h>
#include "../antioch.h"
#include <daemons.h>

inherit CVAULT;

void create()
{
    set_monsters(({ "/d/antioch/antioch2/mons/patrol_guard", }), ({ roll_dice(1, 4) + 1, }));
    ::create();
    set_terrain(CITY);
    set_travel(PAVED_ROAD);
    set_property("indoors", 0);
    set_property("light", 2);
    set_short("An intersection");
    set_long(
        "%^WHITE%^You are standing at the intersection of %^ORANGE%^Crescent%^RESET%^, %^RED%^C%^RED%^h%^RED%^e%^BOLD%^%^RED%^rry%^RESET%^, and %^ORANGE%^C%^BOLD%^%^BLACK%^e%^BLACK%^d%^BLACK%^a%^RESET%^%^ORANGE%^r %^ORANGE%^s%^BOLD%^%^BLACK%^tre%^RESET%^%^ORANGE%^e%^ORANGE%^t%^RESET%^. %^ORANGE%^Crescent%^RESET%^ runs to the southwest, back towards the Antioch gates. %^ORANGE%^C%^BOLD%^%^BLACK%^e%^BLACK%^d%^BLACK%^a%^RESET%^%^ORANGE%^r%^RESET%^ travels northwest towards the palace. %^MAGENTA%^%^RED%^C%^RED%^h%^RED%^e%^BOLD%^%^RED%^rry%^RESET%^ %^RED%^stre%^RESET%^%^RED%^e%^BOLD%^%^RED%^t%^RESET%^ %^RESET%^is the main %^BOLD%^%^BLACK%^str%^RESET%^%^WHITE%^e%^BOLD%^%^BLACK%^et%^RESET%^%^WHITE%^ through town, it runs to the west and has most of the shops on it. There is a large section in the middle of the street at the intersection of %^RED%^C%^RED%^h%^RED%^e%^BOLD%^%^RED%^rry%^RESET%^ and %^WHITE%^O%^WHITE%^a%^WHITE%^k %^WHITE%^s%^BOLD%^%^BLACK%^t%^RESET%^%^WHITE%^r%^BOLD%^%^BLACK%^eet%^RESET%^. On the east is a very large %^BOLD%^%^ORANGE%^churc%^WHITE%^h%^RESET%^%^WHITE%^ with its doors open for all who wish to enter. The church is very impressive, it reaches up several stories in height and is crafted from blocks of carefully carved stone. The entrance is a large archway. The center block has a crimson rose upon a shield of gold, the symbol of %^BOLD%^%^WHITE%^Jar%^RESET%^%^WHITE%^m%^BOLD%^%^WHITE%^i%^RESET%^%^WHITE%^l%^BOLD%^%^WHITE%^a.%^RESET%^
"
        );
    set_smell("default", "You smell a faint scent of incense.");
    set_listen("default", "Gentle prayers float to your ears" +
               " on the breeze.");
    set_items(([
                   ({ "street", "cobblestones", "cobbles", "road", "path" }) : "The" +
                   " street is paved with cobblestones.",
                   "street sign" : "This is the intersection of %^ORANGE%^Crescent%^RESET%^, %^RED%^C%^RED%^h%^RED%^e%^BOLD%^%^RED%^rry%^RESET%^," +
                   " and %^ORANGE%^C%^BOLD%^%^BLACK%^e%^BLACK%^d%^BLACK%^a%^RESET%^%^ORANGE%^r %^ORANGE%^s%^BOLD%^%^BLACK%^tre%^RESET%^%^ORANGE%^e%^ORANGE%^t%^RESET%^.",
                   "church" : "The church is the large building on the east," +
                   " reaching up several stories in height and it looks quite" +
                   " impressive.",
                   "fountain" : "There is a large fountain in the center of" +
                   " %^MAGENTA%^%^RED%^C%^RED%^h%^RED%^e%^BOLD%^%^RED%^rry%^RESET%^ %^RED%^stre%^RESET%^%^RED%^e%^BOLD%^%^RED%^t%^RESET%^ %^RESET%^",
                   ]));
    set_exits(([
                   "east" : ROOMS + "church1",
                   "west" : ROOMS + "street21",
                   "north" : ROOMS + "street13",
                   "south" : ROOMS + "street15"
               ]));
}

void reset()
{
    ::reset();
    if (!present("street_light")) {
        new(OBJ + "street_light")->move(TO);
    }
}
