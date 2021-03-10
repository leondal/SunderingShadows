#include <std.h>
#include "../common.h"

inherit ROOM;

string * features = ({
        "Some of the beams here have been recently replaced, old ones still lie on the side of the tunnel.",
            "Walls of the tunnel here had been reinforced with volcanic concrete.",
            "Drops of %^RED%^blood%^ORANGE%^ can be seen on the road here.",
            "Ceiling here had been reinforced with concrete, drops of water hint that there is body of water above.",
            "It seems entrance to side tunnel recently collapsed here.",
            "Walls of this part of the tunnel is entwined with unusual abundance of thick roots.",
            "Stones in the earth here are covered with lichen.",
            "This part is unusually stony, with almost no earth.",
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
    set_long(query_short() + "\n" + "%^ORANGE%^This is a rough tunnel dug in the %^MAGENTA%^soil%^ORANGE%^ and %^WHITE%^stone%^ORANGE%^ you're in. It is not cramped and appears to be well-maintained. All wooden %^WHITE%^beams%^ORANGE%^ that support the tunnel seems to be in decent condition, with no sign of rot. Floor of this tunnel is layered with stone road." + make_fdesc() + "\n");
    set_smell("default", "The air smells of roots and soil.");
    set_listen("default", "Earth silences all distant sounds");
    set_items(([
                   ({"floor", "road", "stone road"}):"Stones cut flat and placed to form a road.",
                   "beams":"Lumber that supports this tunnels is of various quality, but placed thoroughly.",
                   "soil":"Dirt plants take roots in.",
                   "roots":"Some roots, some are long and thick, some hang from the ceiling. Most of them are cut to clear the tunnel.",
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
