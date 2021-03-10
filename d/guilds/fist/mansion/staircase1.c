#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",2);
    set_property("indoors",1);
    set_property("no sticks",1);
    set_terrain(WOOD_BUILDING);
    set_travel(PAVED_ROAD);
    set_short("The mansion's spiral staircase");
    set_long( (: TO, "ldesc" :) );
    set("night long", (: TO, "ndesc" :) );
    set_listen("default","You hear the buzz of conversation all about.");
    set_smell("default","You smell a mixture of perfumes and pipe smoke.");
    set_items(([
      "belvedere" : "You can see enough through the doors even from here to "
        "tell that at least half the top floor is open on two sides and, "
        "if it were accessible, would doubtless provide a panoramic view of "
        "the city and sea.",
      ({ "doors", "glass" }) : "The doors from the belvedere have a six "
        "inch wide oak frame supporting the many "
        "pieces of glass that have their beveled edges leaded together.  "
        "Each door is unique and has a colorful center design about two "
        "ft. in diameter worked into the design.  The etchings are each unique "
        "and depict the favored emblem of one of the dieties of the land.",
    ] ));
    set_exits(([
       "foyer" : "/d/guilds/fist/mansion/entry",       
       "up" : "/d/guilds/fist/mansion/staircase2",
    ] ));
}

string ldesc(string str) {
   return("You're standing on the mansion's magnificent four-story spiral "
       "staircase.  You can see the landings at each floor and each is as "
       "spacious and well-decorated as the main rooms in even the finer homes.  "
       "The uppermost landing has two walls of leaded-glass doors that "
       "open to a roof-top belvedere.  The %^YELLOW%^sun's rays "
       "%^RESET%^refract through the cut glass of the doors to the belvedere, "
       "sending %^YELLOW%^c%^RED%^o%^BLUE%^l%^MAGENTA%^o%^CYAN%^r%^BLUE%^f"
       "%^GREEN%^u%^RED%^l %^RESET%^rays dancing along the walls and off "
       "of strategically placed mirrors to brighten the whole area.  The "
       "upper rooms are all closed off, apparently still being remodeled.");
 }

string ndesc(string str) {
   return("You're standing on the mansion's magnificent four-story spiral "
       "staircase.  You can see the landings at each floor and each is as "
       "spacious and well-decorated as the main rooms in even the finer homes.  "
       "The uppermost landing has two walls of leaded-glass doors that "
       "open to a roof-top belvedere.  The night sky is visible "
       "through the doors to the belvedere and often the cut glass of the "
       "doors catches the %^YELLOW%^moonlight %^RESET%^or %^BOLD%^starlight "
       "%^RESET%^just right to make the glass shimmer and almost glow.    The "
       "upper rooms are all closed off, apparently still being remodeled.");
}
