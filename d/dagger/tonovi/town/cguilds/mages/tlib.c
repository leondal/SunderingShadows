#include <std.h>
inherit ROOM;

void create()
{
   ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_property("light",2);
//	set_property("no teleport", 1); //removed by Circe 6/18/08 after discussions with others
   set_property("indoors",1);
   set_name("Mage's Library, Tonovi");
   set_short("Mage's Library, Tonovi");
   set_long(
   "%^BOLD%^The Mage's Library, Tonovi%^RESET%^\n"+
   "%^CYAN%^The library is fairly nice sized with many large "+
   "%^ORANGE%^wooden shelves%^CYAN%^ that reach to the ceiling "+
   "and are packed with %^ORANGE%^books %^CYAN%^and %^WHITE%^ancient"+
   " scrolls %^CYAN%^and %^BOLD%^%^BLACK%^texts%^RESET%^%^CYAN%^.  "+
   "All the %^ORANGE%^shelves %^CYAN%^are carefully ordered and"+
   " neatly kept, making it easy to find whatever it is you're searching"+
   " for.  There is a large %^MAGENTA%^table %^CYAN%^in the center "+
   "of the room surrounded by several %^MAGENTA%^cushioned chairs "+
   "%^CYAN%^for larger groups to use, while there are some quieter "+
   "%^ORANGE%^study desks %^CYAN%^in the back for the more solitary"+
   " mages.  An %^BOLD%^%^BLUE%^intricate rug %^RESET%^%^CYAN%^"+
   "covers the floor, detailing the %^YELLOW%^Echoes Mountains "+
   "%^RESET%^%^CYAN%^and down, centering around the city of Tabor "+
   "where the mage tower is displayed in prominent detail.\n"
   );
   set_smell("default","The smell of ancient parchment fills the air.");
   set_listen("default","The library is respectfully quiet.");
   set_items(([
   ({"shelves","wooden shelves"}) : "Wooden shelves are lined up in"+
   " rows about the room, with most of them placed back to back for"+
   " support or lined up against the walls. They contain many leather"+
   " bound books, and ancient texts and scrolls. Many mages come here"+
   " to do research.",
   ({"books","texts","scrolls"}) : "There are many leather bound books,"+
   " ancient texts of all sorts of subjects, and tattered scrolls that"+
   " have been carefully organized on the shelves.",
   ({"table","large table"}) : "There is a large mahogany table in the"+
   " center of the room with several cushioned chairs seated around it."+
   " Sometimes groups of mages use it to do large research projects,"+
   " or sometimes one mage manages to cover the entire table in books"+
   " and notes.",
   ({"chairs","cushioned chairs"}) : "There are several comfortable"+
   " mahogany chairs that have been padded with %^MAGENTA%^wine%^RESET%^"+
   " cushions for added comfort.",
   ({"desk","desks","study desks"}) : "Along the far side of the room"+
   " are several smaller desks that can be used by individual mages"+
   " for research. They have wooden blinds on the sides to prevent"+
   " other mages from looking over at their work.",
   ({"rug","intricate rug"}) : "A large and intricate rug takes up the"+
   " entire floor of the room. Much of it is covered by shelves and"+
   " the table in the center, but you can tell that it begins with the"+
   " Echoes Mountains at the top and works its way down in detail to"+
   " show the city of Tabor. The mage tower is very prominently"+
   " displayed.",
   ]));
   set_exits(([
   "south" : "tfloor2",
   ]));
}
