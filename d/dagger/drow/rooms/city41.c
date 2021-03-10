// made a little more syntax friendly with Akadi's help *Styx* 5/26/06

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
	"%^BLUE%^The city street is made of cobblestones winding "
	"through the existing structures around you. The wind blows "
	"back your hair as you wander through the city pathways. "
	"The road comes to an abrupt halt and you stand at the foot "
	"of an enormous %^BOLD%^%^WHITE%^black obsidian "
	"tower%^RESET%^%^BLUE%^. Above the tower hangs a "
	"large %^CYAN%^blackened cloud%^BLUE%^ that hovers as if "
	"it is awaiting the arrival of something unknown. "
	"The %^RED%^red banners%^BLUE%^ of Lloth hang from the roof "
	"of the tower blowing in the wind down the tower's walls. "
        "%^ORANGE%^The ground beneath the walls here looks rather scorched.\n"
	"\n%^BOLD%^%^YELLOW%^You feel as though you are about "
	"to die..."+TPQCN+"."
    );
    set_listen("default",
	"The wind howls a strangled cry which causes you to feel "
	"nervous about being here."
    );
    set_smell("default",
	"The smell of blood hangs thick in the air."
    );
    set_items(([
	"cobblestone":"There are numerous cobblestones lining the city "
	   "pathways.",
 	"cobblestones":"The city pathway is made up of various colored "
	    "cobblestones which must have been mined in the caverns near here.",
	"tower":"%^BOLD%^%^WHITE%^The large black obsidian tower is made "
	   "of a perfectly smooth polished stone. Other than the "
	   "%^RED%^banners%^WHITE%^ there are no obvious markings "
	   "or openings on the %^BLACK%^obsidian walls.%^RESET%^",
	"banners":"%^RED%^The banners bear the "
	    "%^WHITE%^%^BOLD%^spider symbol%^RESET%^%^RED%^ of Lloth.",
        "cloud":"The cloud hangs dark and heavy and casts its doom upon "
	    "the surrounding area.",
	"street":"The street is made up of cobblestones and winds "
	    "through the buildings and %^ORANGE%^grounds%^RESET%^.",
	"pathway":"The pathway winds through the city and is made up of "
	    "cobblestones.",
	"buildings":"There are buildings lining the city streets.",
	"ground":"%^GREEN%^The ground is scorched and all plant life "
	   "is dead.",
	({"walls", "wall", "obsidian"}) : "%^BOLD%^%^BLACK%^The walls are "
	   "perfectly smooth polished stone and you can almost see your "
	   "reflection except a spot where they are somewhat scorched. It almost looks as if something was once inscribed here.",
        ({"spot", "scorched spot"}) : "%^BLACK%^%^BOLD%^There is a %^RED%^scorched with fire spot%^BLACK%^ here on the wall. It almost looks as if something was once inscribed here.%^RESET%^",
    ]));
    set_search("default", "The stone walls are perfectly smooth, although "
	"there are a few scratches on the wall near the scorched ground.");
    set_search("walls", "You search and search but find no normal means "
	"of entry.  That scorched spot makes you quite curious however.");
    set_exits(([
	"west":"/d/dagger/drow/rooms/city40"
    ]));
}
void init() {
    ::init();
    add_action("inscribe_glyph","inscribe");
}

int inscribe_glyph(string str) {
    object *obs;
    int FLAG,x,GLYPH;
    GLYPH = 0;
    if( !str || str != "glyph" ) {
    notify_fail ("Inscribe what?\n");
        return 0;
    }
    FLAG = 0;
    obs = all_inventory(TP);
    for ( x=0; x<sizeof(obs); x++)
      if ( obs[x]->id("glyph of fire")) {
    FLAG = 1;

        if (FLAG) {
          message ( "my_action",
        "%^BOLD%^%^RED%^You inscribe the glyph to the tower in a burst "
        "of flames!\n%^RESET%^%^RED%^The flames engulf you, transporting "
        "your body inside the tower!%^RESET%^"
            ,TP);
          message ( "other_action",
        "%^BOLD%^%^RED%^"+TPQCN+" inscribes a glyph to the tower in a "
        "burst of flames and vanishes!%^RESET%^"
            ,environment (TP), TP);
          FLAG = 0;
          GLYPH = 1;
          TP->move_player("/d/dagger/drow/rooms/tower4");
          return 1;
       }
    }
    if ( GLYPH != 1) {
    notify_fail ("Inscribe what?\n");
    return 0;
    }
}
