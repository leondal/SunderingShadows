//little side path, elven ritual plot & permanent addition to retain lore. N, 3/15.
#include <std.h>
#include <daemons.h>
inherit ROOM;

void create() {
    ::create();
    set_terrain(LIGHT_FOREST);
    set_travel(DIRT_ROAD);
    set_property("indoors",0);
    set_property("light",2);
    set_name("Deeper Within The Kilkean Forest");
    set_short("%^RESET%^%^GREEN%^Deeper Within The Kilkean Forest%^RESET%^");
    set_long("%^RESET%^%^GREEN%^The %^BOLD%^trees %^RESET%^%^GREEN%^are more dense the deeper into the forest you wander. The %^BOLD%^%^BLACK%^shadows %^RESET%^%^GREEN%^grow as does the "
"%^BOLD%^%^BLACK%^silence%^RESET%^%^GREEN%^. The quiet disturbance of your passage through the thick foliage and the occasional %^MAGENTA%^bird song %^GREEN%^are the only sounds. Almost no "
"%^BOLD%^%^BLACK%^light %^RESET%^%^GREEN%^manages to find its way here. The trees high above your head %^BOLD%^%^BLACK%^blot %^RESET%^%^GREEN%^out the sky. The %^BOLD%^untamed %^RESET%^"
"%^GREEN%^forest around you feels somehow alive, and you cannot shake the feeling that you are being %^BOLD%^%^BLACK%^watched%^RESET%^%^GREEN%^.%^RESET%^\n");
    set("night long","%^RESET%^%^GREEN%^The %^BOLD%^trees %^RESET%^%^GREEN%^are more dense the deeper into the forest you wander. The %^BOLD%^%^BLACK%^shadows %^RESET%^%^GREEN%^grow as does "
"the %^BOLD%^%^BLACK%^silence%^RESET%^%^GREEN%^. The quiet disturbance of your passage through the thick foliage and the occasional %^MAGENTA%^nightingale song %^GREEN%^are the only sounds. "
"Almost no %^BOLD%^%^BLACK%^light %^RESET%^%^GREEN%^manages to find its way here. The trees high above your head %^BOLD%^%^BLACK%^blot %^RESET%^%^GREEN%^out the sky. The %^BOLD%^untamed "
"%^RESET%^%^GREEN%^forest around you feels somehow alive, and you cannot shake the feeling that you are being %^BOLD%^%^BLACK%^watched%^RESET%^%^GREEN%^.%^RESET%^\n");
    set_smell("default","%^CYAN%^The scents of %^GREEN%^nature %^CYAN%^surround you.%^RESET%^");
    set_listen("default",(:TO,"listen_switch":));

    set_exits(([
      "northeast" : "/d/dagger/road/elfglade/elfglade2",
      "west" : "/d/dagger/road/elfglade/elfglade4",
    ]));
    set_invis_exits(({"northeast","west"}));

    set_items(([
      ({ "trees","branch" }) : ({"%^RESET%^%^GREEN%^The ancient trees tower of you, their trunks thick, imposing, and covered in moss. Looking closer you can make out words scrawled into a low hanging branch.%^RESET%^","\n\n%^BOLD%^%^WHITE%^~ northeast ~\n\n~ west ~%^BOLD%^%^WHITE%^","elven"}),
      "foliage" : "%^RESET%^%^GREEN%^The foliage is thick and constantly snagging your boots.%^RESET%^",
    ]));
}

string listen_switch() {
   if ((string)EVENTS_D->query_time_of_day() == "night") 
     return "%^RESET%^%^ORANGE%^It is almost silent here except for the occasional %^MAGENTA%^nightingale song %^ORANGE%^heard in the distance.%^RESET%^";
   return "%^RESET%^%^ORANGE%^It is almost silent here except for the occasional %^MAGENTA%^bird song %^ORANGE%^heard in the distance.%^RESET%^";
}
