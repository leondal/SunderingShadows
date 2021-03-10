#include <std.h>

inherit ROOM;

void create(){
    ::create();
    set_terrain(LIGHT_FOREST);
    set_travel(GAME_TRACK);
    set_property("light", 2);
    set_short("%^BOLD%^%^GREEN%^Before the Great Tree");
    set_long( query_short() + "\n%^RESET%^%^GREEN%^Before you stands a giant and beautiful tree. Surrounded by the feeling of the essence of life, you can feel the tree itself talking to you, whispering to your soul and taking your measure. Surrounded by %^BOLD%^%^GREEN%^t%^RESET%^%^GREEN%^r%^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^e%^BOLD%^%^GREEN%^s%^RESET%^%^GREEN%^,%^GREEN%^ small %^GREEN%^pa%^BOLD%^%^GREEN%^t%^GREEN%^h%^RESET%^%^GREEN%^ leads to the south. You sense %^GREEN%^mov%^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^ment%^GREEN%^ in the forest."
    );
    set_items( ([
     "trees" : "As you focus on a tree, nothing happens, but you are sure you can see the movement of others in the corner of your eye.",
      "path" : "The path continues towards a great tree to the northwest",
      "movement" : "Did you see that?  No?  Damn, I thought I just saw that tree move.",
    ]) );
    set_exits( ([
      "southeast" : "/d/shadow/room/city/cguild/ranger/rooms/path2",
      "hole" : "/d/shadow/room/city/cguild/ranger/rooms/edea",
    ]) );
    set_smell("default", "You can smell the forest all around you.");
    set_listen("default", "What you thought was the wind through the trees sounds more like voices within the tree.");
    set_search("tree", "On closer inspection you see it appears you could enter the tree.");
}

void init(){
    ::init();
    add_action("enter_tree", "enter");
}

int enter_tree(string str){
    if(!str) return notify_fail("Enter what?");
    if(str != "tree") return notify_fail("Enter what?");
    if (TP->is_class("ranger") ||
        TP->is_class("druid")
        ) {
        tell_object(TP, "You walk towards the tree, and as you get close, you can feel your lifeforce meld with it as you are moved to another place.");
    } else {
        tell_object(TP, "As you enter the tree, you are overcome with a weariness.\n"
                    "You have the strong sense the tree has sapped your strength and "
                    "you are not welcome here.");
        TP->use_stamina(100);
    }
    TP->move_player("/d/shadow/room/city/cguild/ranger/rooms/hall1");
    return 1;
}
