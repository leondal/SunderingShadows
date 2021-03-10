#include <std.h>
inherit ROOM;

void create()
{
  ::create();
  set_property("light",1);
  set_property("indoors",1);
  set_short("Gnome Sleeping Room");
  set("day long","%^ORANGE%^A Gnome Sleeping Room%^RESET%^\n"
      "This is the sleeping room of the family that lives here. "
      "Since it is day time all the beds have been neatly made "
      "and everything put in its place. In one far corner curtains "
      "hang and are pulled back to reveal a bed larger then the "
      "others. You also notice that in a corner near the door "
      "there are a pile of sleeping mats and blankets that give "
      "you the feeling that they have guests over alot.");
  set("night long","%^ORANGE%^A Gnome Sleeping Room%^RESET%^\n"
      "This is the sleeping room of the family that lives here. "
      "There are sleeping forms in some of the beds and in one "
      "far corner there are curtains that have been drawn around "
      "one of the beds for privacy.");
  set_smell("default","Air smells fresh and of the surrounding forest.");
  set_listen("default","A gentle breeze rustles the curtains covering "
             "the window and around the bed.");
  set_items( ([
     "curtains" : "Large curtains surround the far bed in the corner,"
                  "it looks like they can pulled closed for privacy.",
     "bed" : "This bed is larger then the others and belongs to the "
             "parents your sure.",
     "mats" : "These are for laying on in the night and are apparently "
              "here for guests.",
     "blankets" : "These are here for guest or on cold nights, to add "
                  "to the families beds for warmth."
	       ]) );
  set_exits( ([
     "down" : "/d/darkwood/forest/village/home1"
	       ]) );
  }

void init()
{
  ::init();
  add_action("pull","pull");
  }
int pull(string str)
{
  if(str != "curtains" || str != "curtain")
  tell_room(environment(TP), TPQCN+" steps behind the curtains and draws "
            "them closed.",TP);
  tell_object(TP,"You step behind the curtains and draw them closed for "
              "privacy.");
  TP->move_player("/d/darkwood/forest/village/priv1.c");
  return 1;
}
