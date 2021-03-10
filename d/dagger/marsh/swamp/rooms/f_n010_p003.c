#include <std.h>
#include "../marsh.h"

inherit FINH;

void create()
{
    ::create();

    set_long("" + ::query_long() + "\n%^RED%^Before you lies a massive tower-shaped billowing "
             "black column of mist. There appears to be no way into the swirling mass other than "
             "to walk straight into the side of this mystical and evil place that must be the tower "
             "known only as Demongate.\n%^GREEN%^A large %^ORANGE%^oak tree%^GREEN%^ is here. From "
             "one of the branches a %^WHITE%^noose%^GREEN%^ has been slung, and from the "
             "%^WHITE%^noose%^GREEN%^ hangs a %^RED%^strangled man%^GREEN%^. The man has a bizarre "
             "%^RED%^twisted grin%^GREEN%^ upon his %^BLUE%^cold blue lips%^GREEN%^.%^RESET%^");

    set_listen("default", "Your mind screams in panic and you fight the urge to flee!");
    set_smell("default", "Blood, evil, death, decay, insanity - it's all here and waits for you to join.");

    add_item("tower", "%^RED%^Ahead of you to the north lies a massive tower-shaped billowing "
             "black column of mist. There appears to be no way into the swirling mass, but perhaps "
             "closer up you may find entrance into this mystical and evil place that must be the "
             "tower known only as Demongate.%^RESET%^");
    add_item("man", "The man is long dead, yet his face still bears a twisted grin.");
    add_item("grin", "The man's lips are contorted into a cold blue toothy grin.");
    add_item("lips", "The man's lips are twisted into a secretive knowing and evil grin.");

    set_exits(([
                   "south" : RPATH "f_n010_p002",
                   "east" : RPATH "f_n009_p003",
                   "tower": "/d/dagger/marsh/tower/rooms/a1",
                   ]));

    set_property("no phase", 1);
    set_pre_exit_functions(({ "tower" }), ({ "GoThroughDoor" }));
}

int GoThroughDoor()
{
    if (TP->query_level() < 24) {
        tell_room(TO, TPQCN + "%^BOLD%^%^WHITE%^ steps toward the tower and immediately staggers "
                  "back, looking faint and too terror stricken to proceed.", TP);
        tell_object(TP, "%^BOLD%^%^RED%^As you step toward the tower, you immediately stagger "
                    "back feeling faint and terror stricken, unable to continue forward.", TP);
        return 0;
    }

    write("%^BOLD%^%^BLUE%^A low, deep howl of pure agony echos all around you as you pass "
          "through the clouded mist which seems to be the side of Demongate "
          "tower.\nYou fear you may never see the light of day again.%^RESET%^");
    tell_room(TO, "%^BOLD%^%^BLUE%^A low, deep howl fills the marsh!", TP);
    return 1;
}
