// made a little more syntax friendly with Akadi's help, including searches *Styx* 5/26/06

#include <std.h>
inherit ROOM;

void create() {
    ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
    set_property("light",1);
    set_property("indoors",1);
    set_property("no teleport",1);
    set_short("%^BLUE%^City street%^RESET%^");
    set_long(
      "%^MAGENTA%^%^BOLD%^The wind blows back your hair and sets "
      "your nerves on end with it wail. You have come to the foot "
      "of a large %^BOLD%^%^RED%^ivory tower%^RESET%^%^MAGENTA%^. "
      "\n%^BOLD%^%^MAGENTA%^The %^RED%^tower%^MAGENTA%^ is "
      "constructed completely of %^CYAN%^"
      "bones and skulls%^MAGENTA%^.  It stands roughly one "
      "hundred feet in the air.\n"
      "%^GREEN%^All the grounds beneath the tower are full of dead "
      "and withered grass and plants.\n"
      "%^MAGENTA%^A slow chill runs up your spine.%^RESET%^"
    );
    set_listen("default",
      "Buried within the howl of the wind a voice whispers, `Welcome "
      +TPQCN+"'."
    );
    set_smell("default",
      "The stench of your flesh rotting begins to seep into the air."
    );
    set_search("default", "The skulls are almost too numerous to count. "
	"At least four of them stand out.");
    set_search("skulls", "They seem to be held together by some magical "
	"%^BOLD%^%^BLUE%^force%^RESET%^ and you notice some markings on them. You are especially drawn to the fourth one.");
    set_items(([
	"cobblestone":"There are numerous cobblestones lining the "
	   "city pathways.",
	"flesh":"The longer you linger here...the more your flesh seems "
	   "to rot away.",
	"spine":"Spine?!? You want to look at your spine...laugh!",
	"cobblestones":"The city pathway is made up of various colored "
	   "cobblestones which must have been mined in the caverns near here.",
	"tower":"%^BOLD%^%^WHITE%^The tower is composed of bones and "
	   "skulls held together by some mysterious force. "
	   "It rises one hundred feet in the air and appears to have no "
	   "doorways or windows. "
	   "Many various types of bones and skulls from different creatures "
           "were used in its construction.%^RESET%^",
	"bones":"The bones gleam and are nicely polished.",
	"skulls":"As you look at skulls it seems as though they are "
	   "screaming to you, each with a different expression of horror. "
	   "Some of the skulls stand out more than others, perhaps you should take a closer look.",
	"bones and skulls":"The bones and skulls seem to be held together "
	   "by some mysterious force.",
	"force":"As you examine the force holding the skulls and bones "
	   "together you see markings on one of the skulls.",
	"grounds":"%^GREEN%^The grounds are scorched and all plant life "
	   "is dead.",
	"markings":"There are markings on at least four of the skulls.",
	({"skull","skull 1"}):"These markings make no sense, but while "
	   "trying to read them you see a few other skulls "
	   "have similar markings.",
	"skull 4":"On the fourth skull the markings can be translated to "
	   "read: vxtyzdl",
	"skull 3":"Bah...these markings are meaningless.",
	"skull 2":"The markings on this skull contain no meaning and are "
	   "unreadable.",
	"plants":"%^GREEN%^The plants are withered and dead.%^RESET%^",
	"street":"The street is made up of cobblestones and winds through "
	   "the buildings.",
	"pathway":"The pathway winds through the city and is made up of "
	   "cobblestones.",
	"buildings":"There are buildings lining the city streets."
      ]));
    set_exits(([
	"southwest":"/d/dagger/drow/rooms/city36"
      ]));
}

void init() {
    ::init();
    add_action("say_word","say");
}

int say_word(string str) {
//    if(str != "vxtyzdl") {
    if( (strsrch(str,"vxtyzdl") == -1)  ) {
	return 0;
    }
    message("my_action",
	"%^CYAN%^You speak the word and are drawn into the tower!%^RESET%^"
    ,TP);
    message("other_action",
	"%^CYAN%^"+TPQCN+" speaks a word and vanishes in a blinding "
	"flash of smoke!%^RESET%^"
    ,environment(TP),TP);
    TP->move_player("/d/dagger/drow/rooms/tower1");
    return 1;
}
