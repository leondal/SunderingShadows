//updated by Circe to be a mage study room by Lusell
//1/25/05.  Both food and drinks are now served in the restaurant
#include "/d/dagger/tonovi/town/short.h"

inherit ROOM;
/*
void init() {
    ::init();
    add_action("read", "read");
}
*/
void create() {
    ::create();
    set_name("Hotel Library");
    set_terrain(WOOD_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("light", 2);
    set_property("indoors", 1);
    set_short("Hotel Library");
/*
short was "Lost Sobriety"
    set_long(
      "%^GREEN%^You are in a pretty large, yet rather fancy, bar.  There are several small tables all around, a couple large tables, and a stage at one end.  with a dark curtain behind it.  Along the east wall is a bar with a bartender waiting to take your order.\n  %^RED%^%^BOLD%^   You can <read menu>."
    );
*/
    set_long("%^BOLD%^%^MAGENTA%^You are in a fairly large but "+
       "mediocre room.  Bookshelves line every wall and reach "+
       "from the floor to the ceiling, 20 feet high.  Soft, "+
       "comfortable %^RESET%^%^MAGENTA%^couches %^BOLD%^%^MAGENTA%^"+
       "and %^RESET%^%^MAGENTA%^sofas %^BOLD%^%^MAGENTA%^dot the "+
       "room as do small tables that are positioned at the ends of "+
       "each one.  A bright but soft %^RESET%^%^ORANGE%^gl%^BOLD%^"+
       "%^YELLOW%^o%^RESET%^%^ORANGE%^w %^BOLD%^%^MAGENTA%^fills "+
       "the room from the large chandelier hanging from the "+
       "center of the ceiling.  A tall %^RESET%^%^ORANGE%^ladder "+
       "%^BOLD%^%^MAGENTA%^leans against a bookshelf, ready for use "+
       "by a couple of small boys that are used as errand boys.%^RESET%^\n");
    set_smell("default","The smell of new and aged parchment "+
       "and leather-bound books assaults your senses.");
    set_listen("default","The only sound heard is that of pages being turned.");
/*
    set_items(([
	"menu" : "Maybe it would help if you read it.",
	"bar" : "%^BOLD%^%^YELLOW%^This is a great bar made of oak, with a marble top.  The bartender keeps several types of drinks behind it.  There are many stools set along it.",
	({"table", "tables"}) : "The tables here are made by great artisans, and have been carved ornately before being stained with a dark stain.",
	"stools" : "The stools are expertly carved with small backrests and padded seats.",
	"stage" : "The great stage is made of wood, and has several scuff marks on it from dancers and whatever else (you're afraid to guess) has been on it.",
	"curtain" : "Behind the curtain you can see several dancers getting into costume for their show.",
      ]));
*/
    set_items(([
       ({"bookshelf","bookshelves","shelf","shelves"}) : "Tall "+
          "bookshelves made of mahogany line the walls of the "+
          "room, providing a sense of enclosure.  They are "+
          "brimming with books and rolls of parchment about "+
          "every subject you could think of.",
       ({"couches","couch","sofa","sofas"}) : "Narrow sofas "+
          "stand around the room, arranged to allow a bit of "+
          "privacy while still leaving the room open.  A small "+
          "table is at the end of each, most likely for a book "+
          "to rest upon.",
       ({"table","tables"}) : "The small tables match the shelves, "+
          "but they come in every shape top.  They are all atop "+
          "thin, spindly legs that add a touch of elegance to the "+
          "otherwise merely functional room.",
       ({"chandelier","light","crystal chandelier"}) : "The chandelier "+
          "dangling from the middle of the ceiling is the only "+
          "truly ornate point in the room.  It provides a bright "+
          "light that is soft on the eyes but chases away all the "+
          "shadows, leaving the room with a secure atmosphere.",
       ({"boy","boys","small boys"}) : "The boys are dressed in "+
          "green and black livery trimmed in red.  They wear rather "+
          "bored expressions on their faces, but they seem content "+
          "enough to spend their days retrieving books for the "+
          "scholars who use this room.",
       "ladder" : "The ladder is narrow and wooden, set upon "+
          "rollers so it may be moved easily by one of the small "+
          "boys.  It reaches to the highest shelf in the room."
    ]));
    set_exits( ([
	"west" : RPATH "hotel2",
      ]) );
}
/*
void reset() {
    ::reset();
    if(!present("barkeep")) 
	new(MPATH "barkeep")->move(TO);
}

int read(string str) {
    object ob;
    int i;

    ob = present("barkeep");
    if(!ob) {
	write("You cannot read the menu, as it is smeared with grease.");
	return 1;
    }
message("Ninfo", "The following specials are availiable today at the Tonovi Bar!\n", TP);
    message("Ninfo", "-----------------------------------------------------------\n", this_player());
    message("Ninfo", "A shot of Whiskey\t\t\t"+ (int)ob->get_price("whiskey")+" gold\n", TP);
    message("Ninfo", "A shot of Vodka\t\t\t\t"+ (int)ob->get_price("vodka")+" gold\n", TP);
    message("Ninfo", "A glass of Goldschlager\t\t\t"+ (int)ob->get_price("goldschlager")+" gold\n", TP);
    message("Ninfo", "A mug of beer\t\t\t\t"+ (int)ob->get_price("beer")+" gold\n", TP);
    message("Ninfo", "-----------------------------------------------------------\n", this_player());
    message("Ninfo", "<buy drink_name> gets you a drink.\n", this_player());
    return 1;
}
*/