#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 1);
set_short ("A sentry's house");
set_long("%^ORANGE%^You are in a sentry's house.  You marvel once again at how the house is molded to the tree.  Wood appears everywhere.  <Table>, <chairs>, <bed>, <bookshelves> and <cupboards> are made of this.  <Drapes> make the little house warm and comfortable looking.%^RESET%^");
set("night long", "%^CYAN%^The <pathway> you travel upon is surrounded by 400 foot <redwoods>.  No light comes this far, except for the odd <moonbeam>.  You see no human life.  However, you do have the feeling eyes are following your every move.  You also seem to see flickering <lights> high in the trees, but that could be an illusion.");
set_smell ("default", "%^MAGENTA%^\nYou smell pine from the trees and some smoke from a <fireplace>.");
set_listen ("default", "You hear the scampering of small animals through the forest, at least you hope they are small.");
set_exits (([
"north" : "/d/dagger/Elvanta/forest/room111"
]));
set_items
(([
"table" : "A worn round table is the centre of this room.  A candle is upon it, as well as some old books.  Whoever lives here enjoys good furniture and good books.",
"chairs" : "The chairs here are made from warm red oak.  They have padding on the back and seat for comfort and look quite inviting.",
"bed" : "The bed is soft and warm looking.  Several blankets lay upon it, with a pillow resting invitingly at the top.",
"drapes" : "Drapes with patterns of autumn leaves hang at the windows, to keep the wind out and the warmth within.",
"cupboards" : "These cupboards are made of yellow pine, and house dishes, glasses and foodstuffs.",
"bookshelves" : "Books by the score reside here, whomever lives here enjoys comfort, a pipe and a good book, as often as he or she can.",
"fireplace" : "Somehow the fireplace is embedded within the south wall.  Stone of an amber colour creates the fireplace and reflects the fires colours and warmth."
]));
}
void reset(){
::reset();
if(!present("castleguard"))
new("/d/dagger/Elvanta/forest/mon/castleguard")->move(TO);
if(!present("archer"))
new("/d/dagger/Elvanta/forest/mon/archer")->move(TO);
}
