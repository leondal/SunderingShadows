#include "/d/dagger/aketon/short.h"

inherit VAULT;

void create() {
   ::create();
   set_property("light",2);
   set_property("indoors",1);
   set_short("An elven home of Aketon");
   set_long("%^GREEN%^An elven home of Aketon%^RESET%^\n"+
   "The room is decorated with many brightly colored swathes of"+
   " silk boutique hanging from the walls. You see images of exotic"+
   " flowers and animals pressed into the silk, set in the middle"+
   " of ever-changing lighter background colors that almost seems"+
   " to be too much but isn't. There are two small windows on the"+
   " north side of the room that are framed in some darker green"+
   " silk curtains with red and blue ginger flowers on them. A"+
   " miniature evergreen is growing on the west windowsill and a"+
   " pot full of violets is growing on the other. The middle of the"+
   " room has a large and brightly colored rug in the center of it"+
   " that is covered in several silk, satin, and velvet cushions."+
   " In the middle of the east wall is hung a large painting of a"+
   " treant, and there is a hickory chest filled with clothes in the"+
   " southwest corner.");
   set_smell("default","The room holds the faint scent of violets.");
   set_listen("default","The wind rustles through the leaves outside.");
   set_items(([
   ({"silk","silk boutique"}) : "The walls of the room are decorated"+
   " with swathes of silk boutique in various and lively colors."+
   " Exotic plants and animals are created in the designs, with"+
   " swirling colored backgrounds that are slightly less vivid than"+
   " the patterns they contain. On the east wall the silk swathes"+
   " are arched around the painting on the wall, starting at a higher"+
   " point and then dripping out to either side away from it before"+
   " falling towards the floor.",
   "windows" : "%^BOLD%^%^CYAN%^There are two small windows on the"+
   " north side of the room. Both of them are framed with pretty"+
   " green curtains. The windowsill on the west side contains a"+
   " miniature evergreen, while a pot of violets sits on the east"+
   " windowsill. The view from up here is incredible, you can see"+
   " far down to the first level below you, or look to the north to"+
   " and west to see more of the trees that comprise the city of"+
   " Aketon.%^RESET%^",
   "curtains" : "%^GREEN%^The green silk curtains have"+
   " %^BLUE%^blue%^GREEN%^ and %^RED%^red%^GREEN%^ ginger growing up"+
   " from the base to bloom half-way up the curtains. They are very"+
   " pretty and detailed.%^RESET%^",
   ({"tree","evergreen","miniature evergreen"}) : "%^GREEN%^A miniature"+
   " evergreen tree sits in a shallow ceramic pot on the west windowsill."+
   " It looks well cared for and the leaves and branches are carefully"+
   " trimmed.%^RESET%^",
   ({"violets","pot"}) : "%^MAGENTA%^A small ceramic pot on the east"+
   " windowsill contains a violet plant with many blooms on it. It"+
   " is a variety of a darker violets and the leaves are thicker,"+
   " green, and a bit fuzzier than the normal variety. They are"+
   " quite pretty.%^RESET%^",
   "rug" : "A large multi-colored rug takes up the center of the floor"+
   " and has many cushions piled high on top of it.",
   "cushions" : "There are several large cushions in a variety of"+
   " bright colors that cover the rug in the center of the room. There"+
   " are silk, satin, and velvet ones, all of them appear comfortable.",
   ({"treant","painting","east wall"}) : "%^BOLD%^%^GREEN%^There is a"+
   " large painting of a treant on the east wall. It is rather"+
   " interesting because different pieces of various fabrics have been"+
   " dyed and cut out to create the forest behind the treant, giving"+
   " it a sort of depth and texture. The treant itself is done in"+
   " oil paints and the brush strokes have also given the bark a"+
   " distinctive texture. It is a truly magnificent painting.%^RESET%^",
   ({"chest","hickory chest"}) : "A hickory chest is tucked unobtrusively"+
   " into the southwest corner of the room. It contains clothes, a"+
   " hair brush, and some shoes.",
   ]));
   set_door("hickory door",RPATH3+"3two7","south",0);
   set_exits( (["south":RPATH3+"3two7"]) );
}
