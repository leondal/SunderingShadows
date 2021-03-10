
inherit "std/room";


void create() {
    ::create();
    set_property("light", 3);
    set_property("indoors", 1);
    set_property("no attack", 1);
    set("short", "Issaquah Grill");
    set("long",
@MELNMARN
      %^BOLD%^Welcome to the Issaquah Grill!%^RESET%^
      Adventurers and townspeople alike come here just for the cuisine.
      Strange and wonderful foods are brought here to be cooked
      by the most famous chef in Shadowgate, Evan Puck.
      People are enjoying themselves, and the food all around you.
MELNMARN
    );
    set_smell("default","You smell the odor of cooking food.");
    set_listen("default","You hear the sounds of plates clanging.");


    set_items(
      (["inn" : "The Deamon Inn, home of good Shadow cuisine.",
      "wall" : "The menu is posted there.",
      "menu" : "You may read it if you like."]) );
    set_exits(
      (["out" : "/d/shadow/room/forest/road1",
    ]) );
}

int clean_up(){return 1;}
