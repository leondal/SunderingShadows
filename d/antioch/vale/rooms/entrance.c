#include <std.h>
#include "../vale.h"
inherit ROOM;

void create()
{
   ::create();
   set_property("indoors",0);
   set_property("magic",1);
   set_property("light",3);
   set_short("%^GREEN%^Within the Wall of Brambles%^RESET%^");
   set_long(
   "%^GREEN%^You are standing in an apparent gap in the wall of%^BOLD%^ brambles%^GREEN%^ that"+
   " surrounds the center of this side of %^BOLD%^%^CYAN%^Moonstone Vale%^RESET%^%^GREEN%^. You have"+
   " the distinct impression that someone is watching you, sizing you"+
   " up. The %^ORANGE%^thorns%^GREEN%^ on either side seem much larger now, and venturing"+
   " further with ill intentions doesn't seem like a good idea. This"+
   " is obviously a sacred area to the druids, you can see one of their"+
   " %^BOLD%^%^CYAN%^pools%^RESET%^%^GREEN%^ to the north. The ground beneath your feet is moist and"+
   " loose, and the image of the wall closing around you is all too"+
   " vivid.\n"
   );
   set("night long",
   "%^BOLD%^%^WHITE%^Moonlight%^RESET%^%^BLUE%^ illuminates the %^ORANGE%^thorns%^BLUE%^ in the wall to either side of you"+
   " all too clearly. They look long and deadly, and you have to wonder"+
   " if it was such a good idea to come this way. The ground beneath"+
   " your feet is moist and loose, as though the wall can close itself"+
   " together at will. You also have the eerie feeling that someone is"+
   " watching you. Venturing further without good intentions might very"+
   " likely prove fatal. You can see a %^BOLD%^%^CYAN%^pool%^RESET%^%^BLUE%^ to the north that reflects"+
   " the %^BOLD%^%^WHITE%^moonlight%^RESET%^%^BLUE%^, and realize that this inner area must be a sanctuary"+
   " of sorts for the druids.\n"
   );
   set_smell("default","The delicate scent of flowers drifts on the breeze.");
   set_listen("default","Bird song echoes faintly.");
   set_items(([
   ({"wall","brambles","bushes"}) : "%^BOLD%^%^GREEN%^You're standing within a gap in"+
   " the large wall. The thorns on either side of you make you uneasy.",
   "thorns" : "Looking closely you can see sharp thorns in the wall"+
   " of brambles. You can all too easily imagine the wall closing in"+
   " on you and piercing you with its sharp thorns.",
   ({"ground","dirt","floor"}) : "%^ORANGE%^The dirt beneath your feet is moist"+
   " and fairly loose, as though perhaps the wall can close itself if"+
   " it wishes.",
   "pool" : "%^BOLD%^%^CYAN%^You can see a pool to the north that is typical of those"+
   " found in certain druidic sanctuaries.",
   ]));
   set_exits(([
   "south" : ROOMS+"c12",
   "north" : ROOMS+"sanctuary1",
   ]));
   set_pre_exit_functions(({"north"}),({"GoThroughDoor"}));
}

void reset()
{
   ::reset();
   if(member_array("north",TO->query_exits()) == -1) {
      add_exit(ROOMS+"sanctuary1","north");
      //"/d/antioch/vale/rooms/sanctuary1"->add_exit("south",ROOMS+"entrance");
      tell_room(TO,"%^GREEN%^The brambles slowly move aside to allow"+
      " passage to the north once more.%^RESET%^");
      tell_room("/d/antioch/vale/rooms/sanctuary1","%^GREEN%^The brambles"+
      " slowly move aside to allow passage to the south once more.%^RESET%^");
   }
}

int GoThroughDoor()
{
    if (TP->query_true_align() == 1 ||
        TP->query_true_align() == 4 ||
        TP->query_true_align() == 7
        ) {
        tell_object(TP, "%^GREEN%^You almost feel as if you have passed some sort" +
                    " of judgement test as you move beyond the wall.%^RESET%^");
        return 1;
    }
    if (!(TP->query_true_align() % 3)) {
        if (!"daemon/saving_d"->saving_throw(TP, "spell", -5)) {
            tell_object(TP, "%^GREEN%^The wall of brambles squeezes together" +
                        " as you attempt to pass, the thorns tear at you!%^RESET%^");
            tell_room(ETP, "%^GREEN%^As " + TPQCN + " attempts to move past the" +
                      " wall, it encloses on " + TP->query_objective() + "!%^RESET%^", TP);
            TO->remove_exit("north");
            "/d/antioch/vale/rooms/sanctuary1"->remove_exit("south");
            tell_room("/d/antioch/vale/rooms/sanctuary1", "%^GREEN%^The wall" +
                      " closes as someone attempts to get through!");
            TP->cause_typed_damage(TP, "torso", roll_dice(1, 20) + 19, "piercing");
            TP->add_attacker(TO);
            TP->continue_attack();
            TP->remove_attacker(TO);
            return 0;
        }
        tell_object(TP, "%^BOLD%^%^GREEN%^You see the thorns begin to" +
                    " close and block your passage, you manage to run through them" +
                    " but not without a few scrapes from the sharp thorns.%^RESET%^");
        tell_room(TP, "%^BOLD%^%^GREEN%^" + TPQCN + " barely manages to run" +
                  " through the brambles as the wall begins to close!%^RESET%^", TP);
        TP->cause_typed_damage(TP, "torso", roll_dice(1, 8) + 9, "piercing");
        TP->add_attacker(TO);
        TP->continue_attack();
        TP->remove_attacker(TO);
        return 1;
    }
    tell_object(TP, "%^BOLD%^%^GREEN%^The hair on the back of your neck stands on end as" +
                " you pass through the wall of brambles, but nothing happens.%^RESET%^");
    return 1;
}
