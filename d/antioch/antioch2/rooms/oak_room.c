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
    set_short("%^ORANGE%^Oak Room");
    set_long(
        "%^ORANGE%^The Oak Room
%^ORANGE%^This room is a cozy golden color. All the furniture in the room, and even the %^BOLD%^%^BLACK%^wall%^ORANGE%^s%^BLACK%^,%^RESET%^%^ORANGE%^ are made out of oak and have been polished to glow in the light from the %^BOLD%^%^WHITE%^la%^RESET%^%^WHITE%^m%^BOLD%^%^WHITE%^ps%^RESET%^%^ORANGE%^ that are hung around the room. There is no carpet here, but a large %^BOLD%^%^BLACK%^ru%^ORANGE%^g%^RESET%^%^ORANGE%^ is in the center of the room. The design on the rug is quite lovely, depicting a forest with the leaves of the trees just beginning to turn in the fall. A large %^BOLD%^%^BLACK%^oak %^BLACK%^bed%^RESET%^%^ORANGE%^ with a %^BOLD%^%^BLACK%^yellow %^BLACK%^bed %^BLACK%^spr%^ORANGE%^e%^BLACK%^ad%^RESET%^%^ORANGE%^ is tucked into the upper left corner of the room. The headboard is engraved with the symbol of an acorn with two oak leaves on either side. A large %^BOLD%^%^BLACK%^che%^ORANGE%^s%^BLACK%^t%^RESET%^%^ORANGE%^ is at the foot of the bed for storing items. On the right hand side of the room is a tall oak dresser. A diamond shaped %^BOLD%^%^ORANGE%^m%^BLACK%^ir%^ORANGE%^r%^BLACK%^or%^RESET%^%^ORANGE%^ is attached to the top of the dresser with an oak leaf frame. A wash %^BOLD%^%^ORANGE%^b%^BLACK%^o%^ORANGE%^w%^BLACK%^l%^RESET%^%^ORANGE%^ sits on top, it's used for washing your face off. In the far right corner is a small %^BOLD%^%^BLACK%^oak %^BLACK%^table%^RESET%^%^ORANGE%^ with a matching %^BOLD%^%^BLACK%^chair%^ORANGE%^.%^RESET%^%^ORANGE%^ The %^BOLD%^%^BLACK%^tab%^ORANGE%^l%^ORANGE%^e%^RESET%^%^ORANGE%^ is rather simple and a %^BOLD%^%^CYAN%^vas%^BLACK%^e%^RESET%^%^ORANGE%^ with some %^MAGENTA%^daffod%^BOLD%^%^MAGENTA%^i%^RESET%^%^MAGENTA%^l%^BOLD%^%^MAGENTA%^s%^RESET%^%^ORANGE%^ sits on top of it. There is a window near the table that overlooks a garden. The window is framed by %^BOLD%^%^BLACK%^y%^ORANGE%^e%^BLACK%^ll%^ORANGE%^o%^BLACK%^w %^ORANGE%^c%^BLACK%^ur%^ORANGE%^t%^ORANGE%^a%^BLACK%^ins%^RESET%^%^ORANGE%^ that can be pulled shut to block out the light and prying eyes.
"
        );
    set_smell("default", "The room is rich with the scent of daffodils.");
    set_listen("default", "You can hear the wind whistling through the" +
               " trees outside.");
    set_items(([
                   "floor" : "The hardwood floor is made of oak and it is kept very" +
                   " clean. In the center of the floor is a large rug.",
                   "rug" : "%^RED%^%^BOLD%^The rug takes up most of the floor. It is" +
                   " woven with an intricate picture of forest leaves beginning to" +
                   " change color in the fall.",
                   ({ "wall", "walls" }) : "The walls are made out of oak that has been" +
                   " varnished to glow warmly in the lamp light.",
                   ({ "lamp", "lamps", "oil lamp", "oil lamps" }) : "Oil lamps are hung" +
                   " at intervals along the walls, giving light to the room.",
                   "window" : "%^BOLD%^There is a window on the far wall" +
                   " that overlooks a little garden. You can see the side walls of" +
                   " the palace, as well, they look well fortified and reach almost" +
                   " two stories in height. You can see guards patrolling the" +
                   " perimeters.",
                   ({ "curtain", "curtains" }) : "%^YELLOW%^Pretty yellow curtains" +
                   " frame the window. They bring a little cheer to the room, but" +
                   " can be closed to block out the light or to allow more privacy.",
                   "table" : "%^ORANGE%^This is a rather simple oak wood table that" +
                   " is tucked into the back right corner of the room. A matching" +
                   " chair is next to it for guests to sit on and there is a vase" +
                   " of daffodils on top of it.",
                   "chair" : "The oak wood chair perfectly matches the little table" +
                   " in front of it. It looks like it would be fairly comfortable to" +
                   " sit down and relax in.",
                   "vase" : "%^BOLD%^The porcelain vase is quite pretty. It is curved" +
                   " and open at the top with images of daffodils emboldened upon" +
                   " it. It holds several fresh %^YELLOW%^daffodil%^WHITE%^ flowers.",
                   "bed" : "The oak bed is tucked into the far left corner of the" +
                   " room. It is covered in a soft looking yellow bed spread. The" +
                   " headboard is carved with the design of an acorn with two oak" +
                   " leaves branching out from it. It is a fairly nice sized bed" +
                   " and looks comfortable.",
                   "chest" : "A large oaken chest sits at the foot of the bed. Its" +
                   " top is carved with pictures of oak leaves and acorns. It is" +
                   " for guests to place their belongings in for a time.",
                   ({ "daffodil", "daffodils" }) : "%^YELLOW%^Several pretty daffodils" +
                   " are in a vase on the table. They bring a lovely scent to the" +
                   " room and add a little cheer.",
                   ({ "bowl", "wash bowl", "wash basin", "basin" }) : "%^BOLD%^A white" +
                   " ceramic wash basin sits on top of the dresser. It is filled" +
                   " with water for washing your face off with.",
                   "dresser" : "This lovely oak dresser is positioned in the right" +
                   " hand corner of the room closest to the door. It is varnished" +
                   " to be a more golden color and has carvings of acorns and oak" +
                   " leaves on each of the drawers. It is approximately four feet" +
                   " wide, two feet deep, and five and a half feet tall. A diamond" +
                   " shaped mirror is attached to it and a wash bowl rests on the" +
                   " top of it.",
                   "mirror" : "This mirror is diamond shaped. It is of medium size" +
                   " and the oak frame that backs it is carved in the design of" +
                   " connecting oak leaves for a nice effect. It is attached to the" +
                   " top of the dresser.",
                   ({ "bed spread", "bedspread" }) : "%^YELLOW%^The bright yellow bed" +
                   " spread looks quite soft. It is light, and yet would probably" +
                   " keep you quite warm.",
               ]));
    set_exits(([
                   "south" : ROOMS + "inn5",
               ]));
    set_door("oak door", ROOMS + "inn5", "south", 0);
    set_search("dresser", (: TO, "search_dresser" :));
    set_search("chest", "You find nothing in the chest, not even dust.");
}

int search_dresser()
{
    if (TP->query_bound()) {
        TP->send_paralyze_message("info", TP);
    }
    if (found) {
        write("You find nothing of interest in the dresser.");
        return 1;
    }else {
        write("You search around in the dresser and discover a" +
              " hairbrush.");
        say("" + TP->query_cap_name() + " searches around in the dresser" +
            " and finds something in one of the drawers.");
        new(OBJ + "hairbrush")->move(TO);
        found = 1;
        return 1;
    }
}
