#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property("light", 2);
set_property("indoors", 1);
set_short ("An elven home, the study");
set_long ("%^GREEN%^The study offers a glimpse into the character of the owner of this home.  <Books> and yellowed sheets of <music> are placed carefully and lovingly away.  <Bookshelves> glow with years of polish and attention.  The sheets of music are place with care in long tubes and put away in a <cupboard> made just for them.  A <fireplace>, <chair> and <table> complete the room, with large <candles> for lighting.%^RESET%^");
set_smell ("default", "%^MAGENTA%^\nThe odour of beeswax mixes with the smoke from the fireplace.");
set_listen ("default", "You can still hear the sound of a wooden flute, haunting and soulful.");
set_exits( ([
"north" : "/d/dagger/Elvanta/forest/roomH4b",
"east" : "/d/dagger/Elvanta/forest/roomH4",
"west" : "/d/dagger/Elvanta/forest/roomH4d"
]) );
set_items(([
"books" : "Rare books set in finest leather with gold leaf titles, line the bookshelf.  Each would be a gift in itself, just to look at let alone read.",
"music" : "Sheets of yellowed papers with notes, treble clefs, and notations lay upon the table.  Other sheets have been rolled carefully, placed in tubes and put away within the cupboard.",
"bookshelves" : "These bookshelves take up three walls in this room.  Each shelf is lovingly cared for, dust free and gleaming with polish.",
"fireplace" : "The fireplace is oval in shape, a change from the usual square or oblong.  The stone is black, and the mantel grey.",
"cupboard" : "This cupboard is a work of art in itself.  The handles are carved metal in the shape of sleeping dragons.  The doors covered in carvings of flowers, trees and shrubs.  Inside the cupboard lies with gentle care, the scrolls of music.",
"chair" : "Only one chair resides in this room.  It is small in stature, but intricate in detail.  Again, flowers, shrubs and trees are carved into the arms and back.  Gentle yellow and orange cushions set upon the chair for comfort.",
"table" : "This table is old.  You can see care has been taken, but time has taken its toll on the table.  Scratches, dents, wax stains have all added to the distress of the table, but also added to the beauty of it as well.",
"candles" : "Large candles, shaped like bowls, set into stone grey bowls give off the lighting for this room."
]) );
}
