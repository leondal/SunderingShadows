#include <std.h>
#include "../common.h"

inherit ROOM;

string * features = ({
        "Some of the beams here have been recently replaced." 
        "Old, rotting beams lay discarded lay along the sides of the path.",
        "Volcanic concrete reinforces some of the walls where they'd started to crumble.",
        "There's a bit of blood smeared over the road.",
        "The ceiling above your head is reinforced with concrete." 
        "Drips of water hint at a body of water above.",
        "The entrance to a side tunnel has collapsed here, and the way is blocked with debris.",
        "The walls are entwined with an unusual abundance of thick roots.",
        "The stone pathway is covered with lichen.",
        "The terrain here is mostly all rocks, with almost no soil to soften your step.",
        "Bugs wriggle away into the walls, irritated at your trespassing.",
    });

void create(){
    ::create();
    set_terrain(BUILT_TUNNEL);
    set_travel(PAVED_ROAD);
    set_property("indoors",1);
    set_light(-1);
    set_short("%^BOLD%^%^BLACK%^Underpaths%^RESET%^");
    if (random(3)) {
        set_property("no teleport", 1);
    }
    set_long(query_short() + "\n" + "%^ORANGE%^Soil and stone have been forcibly "+
    "plowed through in order to create this tunnel. The well-maintained passageway is wide "+ 
    "enough that you don't feel cramped here. Wooden beams support the walls and "+ 
    "ceiling, and show no signs of rot. The floor is made from rough stones.\n");
    set_smell("default", "The air smells of roots and soil.");
    set_listen("default", "The earth silences all distant sounds.");
    set_items(([
                   ({"floor", "road", "stone road"}):"Flat stones form the path beneath your feet.",
                   "beams":"The lumber that supports this tunnel is of various quality, but placed thoroughly.",
                   "soil":"Roots push through the soil from the surface overhead.",
                   "roots":"Roots, some rather long and thick, hang from the ceiling. Most of them are cut back to keep the path clear.",
                   "tunnel":"You're in the tunnel. This is it. A tunnel. And you're in it.",
                   ]));
}


string make_fdesc()
{
    int* featurearr;
    int i;
    string fdesc;

    if (!random(3)) {
        return "";
    }

    fdesc = "";
    featurearr = distinct_array(
        map_array(
            explode(
                crypt(file_name(TO),
                      "$1$")[4..7],
                ""),
            (: atoi(sprintf("%d", $1[0])) % $2:),
            sizeof(features)));
    fdesc += " " + features[featurearr[0]];
    return fdesc;
}

void reset ()
{
    ::reset();
    if (!random(20)) {
        new(SHMON + "ratkin_scout")->move(TO);
    }
}
