//updated by Circe 5/30/04 with color, etc.
// Hall of the Crown and Castle, Tabor
// Thorn@ShadowGate
// 000922
// Tabor
// cnchall.c

#include <std.h>

inherit "/std/rquestroom.c";

void create() {
object ob;
  ::create();
  set_property("light", 2);
  set_terrain(CITY);
  set_travel(DIRT_ROAD);
  set_property("indoors", 1);
  set_name("Hall of the Crown and Castle, Tabor");
  set_short("Hall of the Crown and Castle, Tabor");
  set_long(
"%^BOLD%^Hall of the Crown and Castle, Tabor%^RESET%^\n"+
"%^CYAN%^This is the hall of the Crown and Castle Inn.  "+
"Your host, %^WHITE%^Amergin Paladowyn %^CYAN%^was a bard "+
"of some local fame in Tabor.  Now you can see on the walls "+
"some of the %^YELLOW%^souvenirs %^RESET%^%^CYAN%^of his "+
"travels. Although Amergin is now retired, he is still an "+
"avid patron of the arts and invites the %^MAGENTA%^bardic "+
"luminaries %^CYAN%^of the realm to play on his %^ORANGE%^"+
"stage%^CYAN%^.\n\n"+
"%^CYAN%^From here you can go into the %^ORANGE%^bar room "+
"%^CYAN%^to the north, have a dinner in the %^MAGENTA%^cafe "+
"%^CYAN%^to the south or view shows to the east in the %^YELLOW%^"+
"theater%^RESET%^%^CYAN%^.  The %^GREEN%^courtyard %^CYAN%^and "+
"the %^ORANGE%^stables %^CYAN%^are to the west out the door.  "+
"Wooden archways to the northeast and southeast lead into "+
"two narrow hallways, and it looks as though %^ORANGE%^rooms "+
"%^CYAN%^branch off from them.\n"+
"Remember to close the door when you enter or leave!\n\n"+
"%^RESET%^Paladowyn has lately begun to sponsor rewards to "+
"adventurers who bring in special items that have been "+
"scattered about the realms.  A desk sits in one corner with "+
"a %^BOLD%^%^BLUE%^sign %^RESET%^on it about claiming them. "+
"It also appears to contain a %^BOLD%^%^GREEN%^list to read "+
"%^RESET%^of areas an adventurer might wish to go in search of "+
"them.  Beside the list has been tacked a large %^RED%^map "+
"%^RESET%^for you to look at, to help you find your way.\n"
  );
  set_items(([
     ({"souvenir","souvenirs"}) : "Hanging tastefully on the walls are "+
        "many souvenirs from Amergin's travels.  There is a framed "+
        "hand-drawn program proclaiming Amergin's visit to Azha many "+
        "years ago.  There is also an invitation to perform at the "+
        "Caer Tabor.  Among these prestigious items, there are also "+
        "many different instruments and the like, along with programs "+
        "and signs from lesser-known places.",
     ({"desk","wooden desk"}) : "This highly polished desk is made "+
        "of fragrant pine.  The scent of sap is still in the air "+
        "though the layers of polish on the desk would suggest it "+
        "has been here for quite some time.  A high-backed chair "+
        "sits behind the desk, and you can occasionally find a "+
        "young bard here, eagerly gathering the stories of "+
        "returning adventurers.",
     "sign" : "The sign points you to a list of items of interest "+
        "that are being searched for.  You could <read list> to see them."
  ]));
  set_smell("default","You smell the odor of beer mingled with fine cuisine.");
  set_listen("default","You hear the babble of the socializing guests.");
  
  set_exits( ([
      "south" : "/d/darkwood/tabor/room/cnccafe",
      "north" : "/d/darkwood/tabor/room/cncbar",
      "east"  : "/d/darkwood/tabor/room/cncstage",
      "west"  : "/d/darkwood/tabor/room/cncinn",
      "northeast" : "/d/darkwood/tabor/room/cnchall1",
      "southeast" : "/d/darkwood/tabor/room/cnchall3",
  ]) );
  set_door("door","/d/darkwood/tabor/room/cncinn","west","cnc key");
  set_quest_daemon("/daemon/quests_low");
  ob = new("/std/bboard");
  ob->set_name("board");
  ob->set_id( ({ "board", "bulletin board" }) );
  ob->set_board_id("union_board");
  ob->set_short("%^RESET%^%^CYAN%^Arcane Bulletin Board");
  ob->set_long("This corkboard has been nailed to the wall of the "+
     "inn to allow businesses to advertise and citizens and adventurers "+
     "to communicate about events.");
  ob->set_max_posts(50);
  ob->set_location("/d/darkwood/tabor/room/cnchall.c");
}

void init(){
  ::init();
  if(interactive(TP) && !random(20) && TP->query_level() < 15)
     write("%^BOLD%^The sign on the desk and the list it contains "+
        "draw your attention.");
  add_action("look","look");
}

int look(string str){
    if(!str || (str != "at map" && str != "map")) return 0;
    TP->more("/d/common/text/main_map");
    /* TP->more("/d/common/text/lowbie_map"); */
//changed to lowbie_map by Circe 6/9/05 to help lowbies find their way
    return 1;
}
