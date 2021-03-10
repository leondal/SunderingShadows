//coded by grendel while wishing seraph would leave his ass alone
#include <std.h>
#include <security.h>
#include <daemons.h>
inherit ROOM;

#define GQSWORD "/d/shadow/room/city/cguild/cavalier/quest/godquestsword.c"
#define LOGSTUFF 1

void create() {
::create();
set_light(2);
set_property("indoors", 1);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
set_short("Great Hall");
// set_property("no teleport", 1);
set_long(
"%^RESET%^This is the great hall of the Cavalier's Guild.  The room has a high rectangular ceiling, and floors made of the purest white marble, which rise into a small stage for ceremonial purposes.  To the north you can see an oak door leading to the Councilor's Chambers, to the south is the courtyard, and to the southeast is the foyer.  A ceremonial %^BOLD%^sword%^RESET%^ hangs from a chain in the center of the hall."
);
set_exits(([
    "north":"/d/shadow/room/city/cguild/cavalier/chamb",
    "south":"/d/shadow/room/city/cguild/cavalier/cyard",
    "southeast":"/d/shadow/room/city/cguild/cavalier/guild2"
]));
set_items(([
"stage" : "This stage is made of the purest marble with several steps leading up to it.",
"door" : "It is an oaken door with the rider's crest on it.",
"banners" : "These banners depect several scenes of glory brought to the guild in defeating the evil of the world.",
"wall" : "It looks like a wall to me, how about you?",
"sword" : "This is a ceremonial sword.  Perhaps if you are worthy, you could %^BOLD%^%^GREEN%^'retrieve'%^RESET%^ it?"
]));
set_smell("default", "You can smell the wine and meat of several feasts past.");
set_listen("default", "You can hear the joyous cries of your comrades.");
}

void init() {
  ::init();
  add_action("gods_quest_sword","retrieve");
}

int gods_quest_sword(string str) {
object sword;
  if ((!str) || (str != "sword"))
    return notify_fail("Retrieve what?\n");
  if (newbiep(TP))
    return notify_fail("As you reach for the sword, you notice the stares of your fellow knights looking at you, and you see the doubt in their eyes.\n");
  if (TP->query_lowest_level() < 10)
    return notify_fail(@GaRrEtT
You reach for the sword, but you sense the eyes in the hall fix on you for a moment, disapprovingly.
Perhaps you need to earn the sword by taking more time with your training or becoming a squire to a worthy knight and earn enough respect to have them sponsor you?\n
GaRrEtT
);
  if ((TP->is_class("paladin")) || (TP->is_class("cavalier")) || (TP->is_class("antipaladin")) || (avatarp(TP))) {
    sword = new(GQSWORD);
    if (sword->move(TP)) {
      sword->remove();
      return notify_fail("You are too overburdened to carry that!\n");
    } else {
#ifdef LOGSTUFF
	seteuid(UID_LOG);
	log_file("god_quest",capitalize(TPQN) + " RETRIEVED the sword on "+ ctime(time()) +"\n");
	seteuid(geteuid(previous_object()));
#endif // LOGSTUFF
      message("info",TPQCN + " takes the %^BOLD%^%^WHITE%^Sword of the %^YELLOW%^Questing %^WHITE%^Knight%^RESET%^ down from it's chain.", ({ETP}),({ TP }) );
      write("You take the %^BOLD%^%^WHITE%^Sword of the %^YELLOW%^Questing %^WHITE%^Knight%^RESET%^ down from it's chain.");
      "/cmds/avatar/_note.c"->cmd_note("ckpt "+TPQN+" %^BOLD%^retrieved the questing "
	  "sword of the knights.");
      return 1;
    }
  } else {
    return notify_fail("How the hell are you in here, commoner?\n");
  }
}