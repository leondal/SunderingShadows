//  Created by Ignatius, for ShadowGate
//  Coded on 11 February, 1995
//  Antioch Wizards Room

#include <std.h>
#include "/d/antioch/areadefs.h"

inherit ROOM;

void create() {
  ::create();
  set_property("light", 3);
  set_property("indoors", 1);
  set_property("no castle", 1);
  set_property("no steal", 1);
  set_property("no magic", 1);
  set_property("no fight", 1);
  set("short",
      "The Hall of Immortals for the Village of Antioch"
     );
  set("long",
      " \n"
      "  This elegant chamber sits at the peak of Ferengir Mountain, the "
      "highest mountain in the Charu range.  From here, you can look "
      "down to the village of Antioch.  While the distance between you "
      "and the village is great, you seem to be able to make out a large "
      "group of adventurers having more fun and meeting more challenges "
      "than in any other realm in the whole of ShadowGate.\n"
      "  The chamber itself is quite unique.  The entire south wall is "
      "crafted of an odd, clear type of rock.  It allows you to view the "
      "town, and much of the surrounding realm.  To the north, you spot "
      "a large fireplace, fully loaded with wood, and a tinder box "
      "nearby.  The east and west walls house floor to ceiling bookshelves, "
      "which is humbling when you note that the ceiling is probably fourty "
      "or fifty feet up!\n"
      );
  set_exits( ([
    "down": ANTIOCH+"wiz_hall/wizard_rm2"
    ]) );
  set_items( ([
    ({"chamber", "elegant chamber"}):
      "You are in the Great Room of the Hall of Immortals.",
    ({"peak", "mountain", "Ferengir Mountain", "range", "Charu range"}):
      "You gaze out the window at the massive mountains around you.  This "
      "room is so high up that you can see the clouds passing by directly "
      "overhead!",
    ({"village", "Antioch", "village of Antioch", "adventurers", "group",
      "group of adventurers"}):
      "Looking down at the village of Antioch, you are impressed by the "
      "planning that went into the area.  However, it's not quite done "
      "yet.",
    ({"south wall", "window", "clear rock", "rock"}):
      "Your eyes are drawn to the south wall, crafted of a magical type of "
      "rock that is transparent to your eye!  Pretty neat, huh?",
    "fireplace":
      "The fireplace is loaded and ready to go.  In fact, the tinder has "
      "been set.  All you need to do is light the fire.",
    "bookshelves":
      "These bookshelves hold many texts and tomes of interest to the group "
      "of Immortals that control the area.  Perhaps you could peruse the "
      "titles?"
    ]) );
}

void init() {
  ::init();
  add_action("light_fire", "light");
  add_action("peruse_titles", "peruse");
}

int light_fire(string str) {
  if(!str) {
    notify_fail("What do you want to light?\n");
    return 0;
  }
  if(str != "the fire") {
    notify_fail("Use your damn participles!!!!!\n");
    return 0;
  }
  message("my_action",
          "  \n"+
          "You stoop at the mouth of the fireplace, and check the kindling.\n"+
          "All seems to be in order, and you light the kindling with a small\n"+
          "tinder box next to the fireplace.\n"+
          "With a crackle, the fire starts up.  In moments, the room is\n"+
          "warm and cozy.\n",
          this_player());
  message("other_action",this_player()->query_cap_name()+
          "lights a blaze in the fireplace.  The room fills with the sound\n"+
          "of crackling wood.\n",
          environment(this_player()),this_player());
  return 1;
}

int peruse_books(string str) {
  if(!str) {
    notify_fail("What would you like to peruse?\n");
    return 1;
    }
  if(str!= "the titles") {
    notify_fail("Use your damn participles!!!!\n");
    return 1;
    }
  message("my_action",
    "You scan the shelves, looking for interesting books.  You find a "
    "series of informative works regarding the Realm of Antioch.\n",
    TP );
  message("other_action",
    TPQCN+
    " tries to look sophisticated while reading the titles of a few "
    "books, but in reality they CANNOT READ!!!\n"
    "Hee hee hee.\n",
    environment(TP), TP);
  }
