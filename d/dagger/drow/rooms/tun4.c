#include <std.h>
inherit ROOM;
void create() {
    ::create();
   set_terrain(BUILT_CAVE);
    set_travel(PAVED_ROAD);
    set_property("light",3);
    set_property("indoors",1);
    set_property("no teleport",1);
    set_short("%^BLUE%^A brightly lit cavern chamber%^RESET%^");
    set_long(
	"%^BOLD%^%^YELLOW%^The tunnel from the intersection opens up into "
	"a %^WHITE%^brightly%^YELLOW%^ lit chamber. A "
	"%^RED%^glowing%^YELLOW%^ altar lays in the center of the room. "
	"%^MAGENTA%^Diamonds%^YELLOW%^ and %^GREEN%^emeralds%^YELLOW%^ "
	"of numerous quantities are embedded in the chamber's walls and "
	"ceiling. A %^RED%^glowing chalice%^YELLOW%^ sits on top of the "
	"altar filled with a %^WHITE%^swirling, smoking substance%^YELLOW%^. "
	"The %^RESET%^%^MAGENTA%^lichen%^BOLD%^%^YELLOW%^ that grew in "
	"other areas of the cavern, fails to grow anywhere within the "
	"chamber. As you are bathed in the warmth, peace and holiness of "
	"the chamber, you feel relaxed and refreshed."
    );
    set_listen("default","Splendid music fills the air.");
    set_items(([
     "lichen":"%^MAGENTA%^If you want to look at lichen, there is "
	"plenty of it growing elsewhere.%^RESET%^",
     "chalice":"%^RED%^%^BOLD%^The glowing chalice rests on top of "
	"the altar and contains a swirling smoky substance.  Somehow you "
	"get the feeling you will not be able to move it or take "
	"it.%^RESET%^",
     "substance":"%^WHITE%^%^BOLD%^You have never seen a substance "
	"such as this and when staring at it you hear voices singing "
	"inside your head.%^RESET%^",
     "altar":"%^BOLD%^%^RED%^The glowing altar stands two feet high "
	"from the floor.  A glowing chalice stands on top of it.  There "
	"are no markings anywhere on the altar to indicate what it is "
	"for.%^RESET%^",
      "diamonds":"%^MAGENTA%^The diamonds, while vast and numerous, "
	"cannot be removed from the cavern rock face.%^RESET%^",
     "emeralds":"%^GREEN%^BOLD%^The emeralds, while vast and "
	"numerous, cannot be removed from the walls.%^RESET%^",
     "walls":"The walls are bare stone and obviously have been carved "
	"through the mountain.  Glowing %^MAGENTA%^lichen%^RESET%^ fails "
	"to grow on the walls here."
    ]));
    set_exits(([
	"south":"/d/dagger/drow/rooms/tun3"
    ]));
}
void init() {
    ::init();
//    add_action("sayfunc","say"); //moved catch_says to the mob solar
    add_action("no_fun","throw");
    add_action("no_fun","stab");
    add_action("no_fun","bump");
    add_action("no_fun","cast");
    add_action("no_fun","rush");
    add_action("no_fun","drink");
}

/*  moved to the mob solar and fixed so it will filter the words from sentences
*Styx*  5/3/02
int sayfunc(string str) {
    if(str != "yes" && str != "quest" && str != "drow" && str != "temple" &&
    str != "nodeus" && str != "lloth" && str != "demonpits") {
        notify_fail ("Say what?");
        return 0;
    }
    if(str == "yes") {
	message("environment",
	    "%^BOLD%^%^WHITE%^The SOLAR says, `%^YELLOW%^A threat to all "
	    "races of this world grows in the night. A calling has been put "
	    "forth for the champions of all races to step forward and "
	    "destroy the growing threat. I have been entrapped here to "
	    "speak of the %^MAGENTA%^quest%^YELLOW%^ to those who will "
	    "listen.%^WHITE%^'%^RESET%^"
	,TP);
	return 1;
    }
    if(str == "quest") {
	message("environment",
	    "%^BOLD%^%^WHITE%^The SOLAR says, `%^YELLOW%^The "
	    "%^BLUE%^Drow%^YELLOW%^ have existed for many eons in this realm. "
	    "But now they have strengthened their power greatly. Within a city "
	    "of these evil beings awaits a %^RED%^temple%^YELLOW%^. Within "
	    "there grows an evil tool that they will soon use to conquer "
	    "this realm.%^WHITE%^'%^RESET%^"
	,TP);
	return 1;
    }
    if(str == "drow") {
	message("environment",
	    "%^WHITE%^%^BOLD%^The SOLAR says, `%^YELLOW%^The "
	    "%^BLUE%^drow%^YELLOW%^ have constructed a "
	    "%^RED%^temple%^YELLOW%^ in which to conduct their worship of "
	    "the demonqueen %^BLACK%^Lloth%^YELLOW%^.%^WHITE%^'%^RESET%^"
	,TP);
	return 1;
    }
    if(str == "city") {
	message("environment",
            "%^WHITE%^%^BOLD%^The SOLAR says, `%^YELLOW%^The %^BLUE%^Drow "
	    "%^YELLOW%^live in the city of Underdark. Take great caution "
	    "there, and seek the hidden helper.%^WHITE%^'%^RESET%^"
	,TP);
	return 1;
    }
    if(str == "temple") {
	message("environment",
	    "%^BOLD%^%^WHITE%^The SOLAR says, `%^YELLOW%^Within the "
	    "%^RED%^temple%^YELLOW%^ of the %^BLUE%^drow%^YELLOW%^ "
	    "lies a tool of great power. Through the efforts and worship "
	    "that the %^BLUE%^drow%^YELLOW%^ have performed they have "
	    "almost completed construction of the %^CYAN%^nodeus%^YELLOW%^. "
	    "With this lies the threat.%^WHITE%^'%^RESET%^"
	,TP);
	return 1;
    }
    if(str == "lloth") {
	message("environment",
	    "%^BOLD%^%^WHITE%^The SOLAR says, `%^YELLOW%^The evil Queen of "
	    "the spiders, known as %^BLACK%^Lloth%^YELLOW%^ resides in "
	    "her home dimension of the %^GREEN%^demonpits%^YELLOW%^. The "
	    "%^BLUE%^drow%^YELLOW%^ worship her and are constructing "
	    "the %^CYAN%^nodeus%^YELLOW%^ to allow her to enter this realm. "
	    "This is a grave danger to all mortal races of this realm. If "
	    "allowed to enter she will enslave every mortal within this "
	    "realm.%^WHITE%^'%^RESET%^"
	,TP);
	return 1;
    }
    if(str == "nodeus") {
	message("environment",
	    "%^BOLD%^%^WHITE%^The SOLAR says, `%^YELLOW%^The "
	    "%^CYAN%^nodeus%^YELLOW%^ has two very important powers to "
	    "%^BLACK%^Lloth%^YELLOW%^ and the %^BLUE%^drow%^YELLOW%^. "
	    "First, it can be used by the high priests of the "
	    "%^BLUE%^drow%^YELLOW%^ to open the gate for "
	    "%^BLACK%^Lloth%^YELLOW%^ to enter your realm. "
	    "Second, it prevents my entrance to the "
	    "%^RED%^temple%^YELLOW%^ to destroy it. It is only I who can "
	    "completely erase the %^CYAN%^nodeus%^YELLOW%^.%^WHITE%^'%^RESET%^"
	,TP);
	return 1;
    }
    if(str == "demonpits") {
	message("environment",
	    "%^BOLD%^%^WHITE%^The SOLAR says, `%^YELLOW%^The "
	    "%^GREEN%^demonpits%^YELLOW%^ is the name given to "
	    "%^BLACK%^Lloth's%^YELLOW%^ home plane. She will be able to "
	    "travel through the %^CYAN%^nodeus%^YELLOW%^ to this realm when "
	    "it is completed. The %^CYAN%^nodeus%^YELLOW%^ must be "
	    "deactivated so that i may enter the %^RED%^temple%^YELLOW%^ "
	    "and destroy it. Until such a time however, I am bound here "
      "and its power continues to draw close to being "
	    "complete.%^WHITE%^'%^RESET%^"
	,TP);
	return 1;
    }
}
*/
void reset() {
    ::reset();
    if(!present("solar")) {
	new("/d/dagger/drow/mon/solar")->move(TO);
	write(
	    "%^BOLD%^%^WHITE%^A bright %^RED%^flash%^WHITE%^ fills "
	    "the room and a glowing spirit arrives.%^RESET%^"
	);
    }
}
int no_fun() {
    write("%^BOLD%^Uhhh... not in this room you're not!");
    return 1;
}
