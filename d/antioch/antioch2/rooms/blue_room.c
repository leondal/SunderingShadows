#include <std.h>
#include "../antioch.h"
inherit VAULT;

int found;

void create()
{
    ::create();
    set_terrain(WOOD_BUILDING);
    set_travel(DIRT_ROAD);
    set_property("indoors", 1);
    set_property("light", 2);
    set_short("%^BLUE%^Blue Room");
    set_long(
        "%^BLUE%^The Blue Room\n" +
        "%^BLUE%^This room is very relaxing, it is done in shades of dark blue. The carpet is very thick and soft, muffling any footsteps. You can hear people walking around outside on the street. The little %^BOLD%^%^BLACK%^window%^RESET%^%^BLUE%^ at the far side of the room overlooks the top of the tailor's shop and the street in front of it. Thick %^BOLD%^%^BLACK%^c%^RESET%^%^CYAN%^u%^CYAN%^r%^BOLD%^%^BLACK%^tai%^RESET%^%^CYAN%^n%^BOLD%^%^BLACK%^s%^RESET%^%^BLUE%^ frame the %^BOLD%^%^BLACK%^wi%^RESET%^%^CYAN%^n%^BOLD%^%^BLACK%^dow,%^RESET%^%^BLUE%^ they can be pulled close to block out sunlight. This room is fairly large and there is a small %^BOLD%^%^BLACK%^c%^RESET%^%^CYAN%^o%^BOLD%^%^BLACK%^u%^RESET%^%^CYAN%^c%^BOLD%^%^BLACK%^h%^RESET%^%^BLUE%^ on the left %^BOLD%^%^BLACK%^w%^RESET%^%^CYAN%^a%^BOLD%^%^BLACK%^ll.%^RESET%^%^BLUE%^ On the right wall is a big blue bed that looks as though it could hold a small whale. The pillows and cushions look very soft, as though you'd just sink into them. There's a %^CYAN%^d%^BOLD%^%^BLACK%^ress%^RESET%^%^CYAN%^e%^BOLD%^%^BLACK%^r%^RESET%^%^BLUE%^ at the foot of the bed that's made of shadowtop wood and varnished to be darker. A %^CYAN%^mir%^BOLD%^%^CYAN%^r%^RESET%^%^CYAN%^or%^BLUE%^ is attached to the top of the %^CYAN%^d%^CYAN%^r%^CYAN%^e%^BOLD%^%^BLACK%^s%^RESET%^%^CYAN%^s%^BOLD%^%^BLACK%^er%^RESET%^%^CYAN%^,%^BLUE%^ it is oval shaped and the wooden frame backing it is cleverly done in the likeness of a clam shell. A %^BOLD%^%^BLACK%^bowl%^RESET%^%^BLUE%^ of water sits on top of the dresser for washing your face and hands. Sea shell wall paper covers the walls of the room, and oil %^BOLD%^%^BLACK%^lamp%^RESET%^%^CYAN%^s%^BLUE%^ are hung at intervals to add light.
"
        );
    set_smell("default", "The scent of tobacco clings to the edges of" +
              " the room.");
    set_listen("default", "You can hear people walking by on the street" +
               " below.");
    set_items(([
                   ({ "lamp", "lamps", "oil lamps", "oil lamp" }) : "Oil lamps are hung" +
                   " at intervals around the walls, shedding light.",
                   ({ "floor", "carpet" }) : "%^BLUE%^A thick blue carpet covers the" +
                   " floor, muffling any sounds.",
                   ({ "walls", "wall", "wall paper" }) : "%^BOLD%^%^BLUE%^Sea shell wall" +
                   " paper decorates the walls, bringing a tranquil feeling to the" +
                   " room.",
                   "bed" : "%^BLUE%^This big bed is covered with soft looking" +
                   " pillows and blankets. It's absolutely enormous, taking up" +
                   " about half of the room. The headboard is made of shadowtop" +
                   " wood and is shaped like a sea shell.",
                   "dresser" : "The dresser is made of shadowtop wood and varnished" +
                   " to be even darker. It is tucked into the right hand corner of" +
                   " the room at the foot of the bed. On top of the dresser is a" +
                   " wash bowl and a mirror is fixed to the back of it.",
                   ({ "bowl", "wash bowl" }) : "%^BOLD%^%^CYAN%^The wash bowl is the" +
                   " aqua shade of a tropical sea and even has a few sea shells" +
                   " plastered onto the outside of the bowl. It contains water for" +
                   " washing your face with.",
                   "mirror" : "A mirror is fixed to the top of the dresser. It is" +
                   " oval shape and of medium size. The backing for the mirror" +
                   " is done in the shape of a clam shell.",
                   "window" : "A little window on the far side of the room overlooks" +
                   " the roof of the tailor's house. You can just see the road in" +
                   " front of it and hear people walking by.",
                   ({ "curtains", "curtain" }) : "%^BLUE%^These thick curtains frame" +
                   " the window. They can be pulled shut to keep the light out.",
                   ({ "couch", "small couch" }) : "%^BOLD%^%^BLUE%^The couch is on the" +
                   " left hand side of the room and is nestled back against the" +
                   " wall. It would be a good place for someone to sit back and read" +
                   " a book and relax.",
               ]));
    set_exits(([
                   "north" : ROOMS + "inn5",
               ]));
    set_door("blue door", ROOMS + "inn5", "north", 0);
    set_search("dresser", (: TO, "search_dresser" :));
}

int search_dresser()
{
    if (found) {
        write("You find nothing but a few ashes inside one of the" +
              " drawers.");
        return 1;
    }else {
        write("In one of the drawers of the dresser you find an old" +
              " pipe.");
        say("" + TP->query_cap_name() + " searches around and finds" +
            " something in one of the dresser drawers.");
        new(OBJ + "old_pipe")->move(TO);
        found = 1;
        return 1;
    }
}
