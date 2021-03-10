#include "/d/dagger/aketon/short.h"

inherit ROOM;

void create() {
   ::create();
   set_property("light",2);
   set_property("indoors",1);
   set_short("An elven house of Aketon");
   set_long("%^GREEN%^An elven house of Aketon%^RESET%^\n"+
   "You are standing in the sleeping room of an elven house. It is rather"+
   " small, with only a small closet in one corner for hanging clothes,"+
   " and a bed in the center of the room with a nightstand next to it."+
   " There is a candle on the nightstand that apparently receives a lot"+
   " of use. A small window in the west wall looks out of the branches"+
   " and you can see the ground far below you. It is a nice view if you"+
   " aren't afraid of heights.");
   set_smell("default","You are assaulted by the many smells of the "
      "forest.");
   set_listen("default","You hear the branches swaying in the wind.");
   set_items(([
   "closet" : "There is a small closed closet on the south side of the"+
   " room. It holds a few hanging clothes and more clothes that are"+
   " folded neatly in the bottom. It is made of oak and has a lovely"+
   " rose and vine design that has been carved into the edges.",
   "candle" : "There is a simple candle on the nightstand that has received"+
   " a lot of use and will probably need to be replaced soon. It is"+
   " probably used for reading in bed at night, since elves have infravision.",
   "nightstand" : "There is a simple oak nightstand on the left side of the"+
   " bed that holds a much used candle.",
   "bed" : "The bed is in the center of the north wall. It is rather small,"+
   " meant only for one person, and is covered in a patchwork quilt with"+
   " many flowers and leaves on it, mostly in autumn colors.",
   "window" : "%^BOLD%^%^CYAN%^There is a tiny window in the west wall that"+
   " overlooks the ground. You are quite far up, yet only on the first level!",
   ({"curtain","silk curtain","yellow curtain","yellow silk curtain"}) : "%^YELLOW%^There"+
   " is a curtain made of yellow silk that hangs across the entrance to the"+
   " west, giving the next room some privacy. The bottom of the curtain is"+
   " weighted with a few beads of fools gold.%^RESET%^",
   ]));
   set_exits( (["east":RPATH3+"3one23"]) );
}
