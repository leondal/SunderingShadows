// /std/flying_room.c  for use with the flying mount inherit -Ares
#include <std.h>

inherit ROOM;


void create()
{
    ::create();
    set_terrain(BARREN);
    set_travel(FRESH_BLAZE);
    set_property("light",2);
    set_property("no pocket space",1);
    set_name("flying through the air");

    set_short("%^BLUE%^You are climbing into the air!%^RESET%^");

    set_long("%^RESET%^You have just begun to climb off of the ground.  You can see the tops "
        "of trees nearby beginning to drop further and further below you as you rise.  Buildings "
        "can be seen far in the distance.");

    set_smell("default","You can smell the fresh, cool air as you climb into the sky!");
    set_listen("default","The sound of rushing wind whistles past your ears!");
}

void change_stage(string stage)
{
    switch(stage)
    {
    case "initial climb":

        TO->set_short("%^BLUE%^You are climbing into the air!%^RESET%^");

        TO->set_long("%^RESET%^You have just begun to climb off of the ground.  You can see the tops "
            "of trees nearby beginning to drop further and further below you as you rise.  Buildings "
            "can be seen far in the distance.");
        return;

    case "climbing":

        TO->set_short("%^CYAN%^Higher in the sky!%^RESET%^");

        TO->set_long("%^CYAN%^You are higher off the ground now.  The trees are starting to look "
            "like a leafy mass below and you can only make out the shapes of distant buildings.  "
            "Winding ribons of rivers or creeks can be seen in the distance and you can even "
            "make out the distant silvery shimmer of the ocean.");
        return;

    case "soaring":

        TO->set_short("%^BLUE%^Soaring among the clouds!");

        TO->set_long("%^BLUE%^You can see almost the whole world from so high up in the air!  "
            "Forests look like shaggy carpets from this altitude as you glide among the clouds!  "
            "You can see for miles and miles in all directions, the ocean glimmers on the "
            "horizon and the buildings below are only the smallest of specks.  You can even "
            "see little smudges on the ocean that must be massive islands!");
        return;

    case "landing":

        TO->set_short("%^YELLOW%^Descending towards the earth.");

        TO->set_long("%^YELLOW%^You can see the ground rising back to meet you as "
            "you carefully begin to descend for a landing.  The trees are becoming "
            "distinguishable again and the shapes of buildings are more obvious.  ");
        return;

    case "final landing":

        TO->set_short("%^GREEN%^Approaching the ground!");

        TO->set_long("%^GREEN%^The world rapidly approaches as you get closer and "
            "closer to the ground.  Your stomach feels like it's lifting high into "
            "your chest and you hope that the landing will go well!");
        return;

    case "falling":

        TO->set_short("%^RED%^Falling through the air!");

        TO->set_long("%^RED%^You have fallen off of your mount and are dropping rapidly "
            "back towards the ground!  You can see the earth rapidly approaching and if "
            "you don't do something soon, you may hit it with lethal force!");
        return;

    case "final falling":

        TO->set_short("%^RED%^About to hit the ground!");

        TO->set_long("%^RED%^Oh gods!  You are about to hit the ground!  It may kill you!  "
            "You are going so fast!  The earth rushes up to meet you at blinding speed!");
        return;
    }
    return;
}

int is_flight_room() { return 1; }
