#include <std.h>
#include "../tomb.h"

inherit "/std/lab";

void create()
{
     object ob;

     ::create();
     set_travel(PAVED_ROAD);
     set_terrain(STONE_BUILDING);
     set_property("indoors",1);
     set_property("light",2);
     set_property("fill waterskin", 1);
     set_name("Marble Laboratory");
     set_short("%^BOLD%^%^WHITE%^Marble Laboratory%^RESET%^");
     set_long(query_short() + "
%^BOLD%^%^BLACK%^Carved out of %^WHITE%^w%^RESET%^%^WHITE%^h%^BOLD%^%^WHITE%^it%^RESET%^%^WHITE%^e%^BOLD%^ %^WHITE%^m%^RESET%^%^WHITE%^a%^BOLD%^%^WHITE%^r%^RESET%^%^WHITE%^b%^BOLD%^%^WHITE%^le,%^BLACK%^ this lavish laboratory provides all the essential tools and apparatus the magi and alchemists could need. There are many tables and alchemical stations scattered throughout the room. The superb glassware covers most of the tables. Tables stand on stone slabs, slightly raising to the walls as if you stood in auditorium. The center of the place slopes down with a %^RED%^c%^RESET%^%^RED%^i%^RED%^r%^RED%^c%^BOLD%^%^RED%^le %^RED%^of %^RED%^g%^RESET%^%^RED%^l%^BOLD%^%^RED%^ov%^RESET%^%^RED%^i%^BOLD%^%^RED%^ng %^RESET%^%^RED%^r%^BOLD%^%^RED%^une%^RESET%^%^RED%^s%^RED%^.

%^BOLD%^%^WHITE%^The command <help laboratory> will instruct you in its use.%^RESET%^
");
     set_exits(([
                     "north" : ROOMS + "/tomb5",
                     ]));

     set_smell("default","%^CYAN%^The the area smell pure, almost magicly so.");
     set_listen("default","%^white%^Chime of glassware can be heard.");

     setOwner("none");
     setLabId("Nurval");

     ob=new("/d/magic/obj/mirror");
     ob->set_short("%^RED%^c%^BOLD%^%^RED%^ircle %^RESET%^%^RED%^o%^RED%^f%^BOLD%^ %^RESET%^%^RED%^r%^BOLD%^%^RED%^unes%^RESET%^%^RED%^");

     ob->add_id("circle of runes");
     ob->add_id("circle");
     ob->add_id("crystal ball");
     ob->add_id("runes");
     ob->set_long("%^BOLD%^%^WHITE%^On the floor you see a circle of red %^RESET%^%^RED%^g%^BOLD%^%^RED%^l%^RESET%^%^RED%^o%^BOLD%^%^RED%^win%^RESET%^%^RED%^g%^BOLD%^ %^RED%^r%^RESET%^%^RED%^u%^RED%^n%^BOLD%^%^RED%^es%^WHITE%^ that surround perfectly clean, untouched space.%^RESET%^");
     ob->move(TO);
}
