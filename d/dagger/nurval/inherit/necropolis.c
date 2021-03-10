#include <std.h>
#include "../tomb.h"

inherit ROOM;

string* features = ({
        "Some of the houses here remain mostly untouched.",
            "%^WHITE%^Skeletons%^BLUE%^ lie in the ashes, exposing their bones to the sky.",
            "Freshly-dug graves await their new occupants.",
            "Tombstones stand in disarray.",
            "Burned ragdoll sits by the stone.",
            "A pile of rotting corpses reeks of decay.",
            "%^CYAN%^Blue mist%^BLUE%^ covers the ground.",
            "%^BOLD%^%^BLACK%^Burnt%^RESET%^%^BLUE%^ trees form a small grove.",
            "%^CYAN%^Stone%^BLUE%^ pylon conducts currents of fell energy across the necropolis.",
            "Tiles of the road are nearly gone.",
            "Ice covers what remains of the road.",
            "Empty gallows rot, waiting for a new soul to claim.",
            "Market stalls, empty and mostly burned, stand on the side of the road."
            });

string* randevents = ({
        "%^BLUE%^A platoon of heavily armed %^WHITE%^skeletons%^BLUE%^ marches through the place.%^RESET%^",
            "%^CYAN%^An eerie laughter breaks the silence.%^RESET%^",
            "%^WHITE%^Howling winds sweep the dust.%^RESET%^",
            "%^WHITE%^%^BOLD%^Lightning %^RESET%^%^strikes the ground.%^RESET%^",
            "%^WHITE%^Ghost riders ride through on their phantasmal steeds.%^RESET%^",
            "%^BLUE%^Swarm of bats flies through, human figure inside of it.%^RESET%^",
            "%^BLUE%^A lid on one of the tombs opens, nothing inside.%^RESET%^",
            });

void create()
{
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("light", 2);
    set_property("indoors", 0);
    set_name("Necropolis");
    set_short("%^BOLD%^%^BLUE%^Necropolis, %^WHITE%^Tomb of Nurval%^RESET%^");
    set_long(
        "%^BOLD%^%^BLUE%^Necropolis, %^WHITE%^Tomb of Nurval%^RESET%^
%^BLUE%^This %^BOLD%^%^BLACK%^endless%^RESET%^%^BLUE%^ graveyard is build upon a %^BOLD%^%^BLACK%^ruined%^RESET%^%^BLUE%^ city. Walls of houses destroyed with fire stand next to the grave stones. Most of the graves are ancient. Some are newly made. Tombs and graves have been moved into the city from elsewhere, as if two places - the graveyard and the city - were joined together. The %^CYAN%^cold%^BLUE%^ rises from the ground touching everything." + make_fdesc() + "
"
        );
    set_smell("default", "%^CYAN%^A breath of fresh air briefly casts aside the smell of the ruins.");
    set_listen("default", "%^WHITE%^It is deathly quiet here.");
    set_heart_beat(1);
}

void reset()
{
    ::reset();
    tell_room(TO, randevents[random(sizeof(randevents))]);
}

void heart_beat()
{
    object* ppl, peep;

    ppl = all_living(TO);
    ppl = filter_array(ppl, (: !avatarp($1) :));

    foreach(peep in ppl)
    {
        if (!random(1000)) {
            continue;
        }
        if (peep->query_property("negative energy affinity") && peep->query_hp() > peep->query_max_hp() * 4 / 5) {
            continue;
        }
        tell_room(TO, "%^CYAN%^Fell energy raises from the ground and envelops " + peep->QCN + ".%^RESET%^", peep);
        tell_object(peep, "%^CYAN%^Fell energy raises from the ground.%^RESET%^");
//        peep->cause_typed_damage(peep,peep->return_target_limb(),peep->query_max_hp()/3,"negative energy");

        peep->cause_typed_damage(peep, peep->return_target_limb(), peep->query_max_hp() / 20, "negative energy"); // damage of 33% of total HP just for walking through town is going to kill a lot of random adventurers. Remember there is a portal to Graez right across town from the Daggerdale road. Reducing this to a 5%. - Uriel
        if (peep->query_hp() < 0) {
            peep->add_death("Cursed terrain");
            peep->die();
        }
    }
}

string make_fdesc()
{
    int* featurearr;
    int i;
    string fdesc;
    fdesc = "";
    featurearr = distinct_array(
        map_array(
            explode(
                crypt(file_name(TO),
                      "$1$")[4..6],
                ""),
            (: atoi(sprintf("%d", $1[0])) % $2:),
            sizeof(features)));
    for (i = 0; i < sizeof(featurearr); ++i) {
        fdesc += " " + features[featurearr[i]];
    }
    return fdesc;
}
