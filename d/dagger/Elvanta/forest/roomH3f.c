#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property("light", 2);
set_property("indoors", 1);
set_short ("Elvanta city, a home");
set_long ("%^GREEN%^Now you have reached the study.  A large <chair> waits for the owner to come and look at the pile of <scrolls>, <books> and <papers> that are tumbling from the <table> and <bookshelves>.%^RESET%^");
set_smell ("default", "%^MAGENTA%^\nMusty odours from old parchment and the smell of pipe tobacco lingers here.");
set_listen ("default", "You hear the crackling of the fire in the stone fireplace");
set_exits( ([
"south" : "/d/dagger/Elvanta/forest/roomH3c"
]) );
set_items(([
"chair" : "Blue velvet the colour of deep night covers this large chair.  Arms are carved from birch and have lions heads as hand rests.",
"scrolls" : "Piles of yellowed aged scrolls lay scattered about the room, it is quite obvious that someone needs to catch up on some paperwork.",
"books" : "Books of many languages are here upon the table, or the bookshelves.  Delicate writings cover most of the books, but you cannot read them, as the language has been forgotten over the eons by most beings.",
"papers" : "Faded papers of all shapes and sizes litter the room.  Some seem to be tallies of weapons and arms.  Some appear to be just lists of people.",
"table" : "This table is made from black ironwood, and can withstand almost any damage, however, the weight of the papers and books, may be the ultimate demise of the table.",
"bookshelves" : "These bookshelves cover every wall in this room.  They stand twenty feet high and are loaded to the brim with books, scrolls and papers.  Most of the books appear to be elvish, but not all.  Someone reads an awful lot here."
]) );
}
void reset(){
::reset();
if(!present("elf"))
new("/d/dagger/Elvanta/forest/mon/elf")->move(this_object());
}
