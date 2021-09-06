//Moved Cruiser Tetron spawn to create so it'll load only when the room loads into memory - Octothorpe 6/8/09
inherit "/std/room";

#include <std.h>
#include <daemons.h>
int FLAG;

void create()
{
    ::create();
    set_light(2);
    set_property("no teleport",1);
    set_property("no pocket space",1);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_indoors(1);
    set_short("%^RESET%^%^BOLD%^%^BLUE%^The chamber of %^RED%^evil%^BLUE%^ awareness%^RESET%^");
    set_long("%^RESET%^%^BOLD%^%^BLUE%^The chamber of %^RED%^evil%^BLUE%^ awareness%^RESET%^
%^RESET%^%^BOLD%^%^BLACK%^You have come to a hidden %^RED%^al%^BLUE%^t%^BLUE%^a%^RED%^r.%^BLACK%^ This is a circular chamber with stained %^RED%^gl%^BLUE%^a%^BLUE%^s%^RED%^s %^BLUE%^w%^BLUE%^a%^RED%^l%^BLUE%^l%^RED%^s!%^BLACK%^ Bright lights glow behind the walls and beneath the floor where they shine through a glass symbol of the Kinnesaruda. A kneeling block lies at the center of the room and a sacrificial %^RED%^table%^BLACK%^ sits at either side. The %^RED%^ceiling%^BLACK%^ in here is vaivering as if a pocket of intense heat were between you and it. You can feel the angry glare of a powerful evil presence upon you.%^RESET%^
%^BOLD%^%^BLUE%^A Mysterious Portal is here.%^RESET%^\n");

    set_items(([
      "ceiling"             : "The ceiling seems to be unstable, some unseen force lies between you and it, or perhaps reality is warped.",
      "altar"               : "This is an altar dedicated to resurrecting the dead.  It is a holy place for the most malevolant forces imaginable.",
      "tables"              : "The sacrificing tables are stained with blood",
      "sacrificial tables"  : "The tables are stained with blood",
      "walls"               : "They are comprised of colored glass panels.  Bright light pours into the room from behind them.",
      "portal"              : "The portal shimmers like an inky black ooze.  There's no telling where it leads."
    ]));

    set_listen("default", "A beautiful dark melody fills your head.  You have heard it somewhere before, and could listen to it forever.\n");
    new("d/islands/common/mon/cruisertetron")->move(TO);
    set_had_players(10); // respawn about 3 hours time after last player leaves room
}


void showoff(int count)
{
    string display;
    switch(count)
    {
        case 0:
            display = "%^RESET%^%^BOLD%^A pillar of %^CYAN%^light%^RESET%^%^BOLD%^ shoots skyward from the sea somewhere in the southeast%^RESET%^";
            break;
        case 1:
            display = "%^MAGENTA%^The clouds ripple outwards, away from the ascending column of %^CYAN%^light%^RESET%^%^BOLD%^.%^RESET%^";
            break;
        case 2:
            display = "%^RESET%^%^GREEN%^For an instant a familiar %^BLUE%^dark melody%^RESET%^%^GREEN%^ touches your soul but then it is gone.%^RESET%^";
            break;
        case 3:
            display = "%^RESET%^The %^YELLOW%^Dominion Warrior%^RESET%^ wakes.";
            WORLD_EVENTS_D->inject_event((["Disturbed The Dominion Warrior" : (["start message" : "%^BOLD%^%^WHITE%^Monsters across the world revel and surge "+
            "with power as the %^YELLOW%^Dominion Warrior%^BOLD%^%^WHITE%^ Wakes!!! For the next three hours the monsters of the world are empowered to be more "+
            "deadly!%^RESET%^!%^RESET%^",
            "event type" : "monster modifications", "length" : 180,
            "notification" : "More dangerous monsters!", "event name" : "Disturbed The Dominion Warrior", "modifier" : (["strength" : 3, "dexterity" : 3, "intelligence" : 3,
            "wisdom" : 3, "constitution" : 3, "charisma" : 3, "level" : 4, "health" : roll_dice(6,10)]), "announce" : 1, "announce to" : "world" ]),]));
            break;
        case 4:
            return;
    }

    count++;
    message("info",display,users());
    call_out("showoff",1.2,count);
    return;
}


void init()
{
    ::init();
    add_action("enter", "enter");
    if(!objectp(TP)) { return; }
    if(!present("cruiser",TO)) { return; }
    if(!FLAG && !avatarp(TP) && interactive(TP))
    {
        FLAG = 1;
        showoff(0);
        return;
    }
}


int enter(string str)
{
    tell_object(TP,"%^CYAN%^You enter the mysterious portal.");
    tell_room(TO,"%^CYAN%^"+TP->QCN+" enters the mysterious portal.");
    TP->move_player("/d/attaya/cliff69");
    return 1;
}
