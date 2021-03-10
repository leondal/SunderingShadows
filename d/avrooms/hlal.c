// Hlal's room - By LoKi

#include <std.h>

inherit ROOM;


void create() {
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("indoors",1);
    set_name("a massive cavern filled with books");
    set_property("light",2);
    set_short("%^RESET%^%^ORANGE%^A massive cavern filled with books%^RESET%^");
    set_long("%^RESET%^%^ORANGE%^This cavern is so %^YELLOW%^immense%^RESET%^%^ORANGE%^ that "+
	"it almost looks like it goes on forever. Instead of being %^BLACK%^%^BOLD%^cavernous%^RESET%^%^ORANGE%^ "+
	"though it is filled floor to high ceiling with every manner of %^GREEN%^books%^RESET%^%^ORANGE%^. "+
	"In the middle of the cavern is a large comfortable %^BLACK%^%^BOLD%^leather chair%^RESET%^%^ORANGE%^ "+
	"and a smaller pile of %^BLUE%^%^BOLD%^books%^RESET%^%^ORANGE%^ personally selected by whomever "+
	"owns this room. You cannot see how the room is lit as there are no lights whatsoever but its "+
	"comfortable enough a level that you could easily sit here and read all day long.%^RESET%^\n%^RESET%^");
    set_exits(([
        "loki" : "/realms/loki/workroom.c",
        "lounge" : "/d/dagger/avalounge.c",
    ]));  

set_smell("default","%^RESET%^%^ORANGE%^It smells like books.%^RESET%^");
set_listen("default","%^RESET%^%^GREEN%^You hear very little, its as quiet as a library.%^RESET%^");

        set_items(([
                    ({"chair", "leather chair"}) : "%^BLACK%^%^BOLD%^This fine leather chair has been well "+
					"loved, and the leather is cracked, but super comfortable. This is the chair of a "+
					"reader, the chair of a thinker, and perhaps, the chair of a napper%^RESET%^\n",
                    ({"books", "piled books"}) : "%^RESET%^%^ORANGE%^Books of every type, every genre "+
					"and every language are piled up here. Manuals for fixing car transmissions are beside "+
					"harlequin romance novels and manuals on war from ancient Japan. Several are well "+
					"thumbed through and dog eared, including %^RED%^%^BOLD%^'LoKi's guide to "+
					"Personas' %^RESET%^%^ORANGE%^and %^GREEN%^%^BOLD%^'How to cook players for fun "+
					"and profit'%^RESET%^%^ORANGE%^. Perhaps you can stay to read them all%^RESET%^\n",
                    ({"ceiling", "darkness"}) : "%^BLACK%^%^BOLD%^you can barely see the ceiling, "+
					"it is so high up into the darkness%^RESET%^",
]));

}

void reset() {
  object ob;
  ::reset();
  if (!objectp(present(getuid(TO)+"_board"))) {
     ob = new("std/bboard");
     ob->set_name(getuid(TO)+"board");
     ob->set_id( ({ "board", getuid(TO)+"_board", "my board" }) );
     ob->set_board_id(geteuid(TO)+"_board");
     ob->set("short", "%^YELLOW%^A pile of books made up to be a board%^RESET%^");
     ob->set("long", "This is Hlal's board... !\n");
     ob->set_max_posts(20);
     ob->set_ooc_board(1);
     ob->set_restricted_read();
     ob->set_location(base_name(TO));
     ob->move(TO);
     ob->set_property("no steal",1);
  }
}
