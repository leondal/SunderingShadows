#include <std.h>

inherit ROOM;

void create(){
    ::create();
    set_short("Research Room");
    set_long(
      "Here in this room, many new spells are thought up and researched.  A myriad of books adorn shelved along the walls and a full laboratory set offsets to the right of the room.  Tables full of beakers and test-tubes sit to the left.  Many great minds have used this equipment and written these books, so take care of them."
    );
    set_light(2);
    set_property("indoors", 1);
    set_items( ([
      "books" : "These ancient handwritten books need to be treated with the utmost of care.",
      "beakers" : "These beakers are full of putrid looking disgusting smelling concotions.  C'mon you know you want to taste 'em.",
      "tables" : "These tables are covered with the papers and research of Wizards too lazy to clean up after themselves.",
    ]) );
    set_smell("default", "All you can smell are the strange beakers boiling over hot magical flames.");
    set_smell("beakers", "You sniff the tops of one of the beakers and almost loose the contents of your stomach");
    set_listen("default", "In the hush, you can only hear the boiling of the liquids in the beakers.");
    set_exits( ([
    ]) );
}
