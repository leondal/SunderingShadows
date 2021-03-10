#include "/d/dagger/aketon/short.h"

inherit VAULT;

void create() {
   ::create();
   set_property("light",2);
   set_property("indoors",1);
   set_short("An elven house of Aketon");
   set_long("%^GREEN%^An elven house of Aketon%^RESET%^\n"+
   "You are standing in the living room of a tastefully decorated elven"+
   " home. The floor is made of a large section of a tree branch that"+
   " has been flattened out, it is quite wide here giving you plenty of"+
   " room to walk around. There is a bookshelf in one corner that has"+
   " a few leather bound volumes but is mostly taken up with small"+
   " statues, dried flowers, and various gemstones. There is a lovely"+
   " tapestry against the southern wall, with a matching rectangular"+
   " mat that covers the center of the floor. There is a curtain of"+
   " yellow silk that hangs to the west, giving some privacy to the"+
   " next room. There is not much furniture in this room. You notice a"+
   " small table with two chairs on the south side, but that is all.");
   set_smell("default","You are assaulted by the many smells of the "
      "forest.");
   set_listen("default","You hear the branches swaying in the wind.");
   set_items(([
   ({"door","golden door"}) : "%^YELLOW%^The door is painted that same"+
   " beautiful shade of gold on this side as well, it helps brighten the"+
   " room.%^RESET%^",
   "bookshelf" : "There is a large oak bookshelf in the northeast corner"+
   " of the room. You notice a few old and worn leather bound books that"+
   " appear to contain mostly poetry or philosophy. Most of the other"+
   " shelves are taken up by an interesting gem collection, a few statues"+
   " made from various stones, and a couple of dried flowers.",
   ({"stones","gems","gemstones"}) : "Different gemstones cover the bookshelf."+
   " Many are simple geods that have been split open to reveal their"+
   " crystalline center. There are a couple gemstones that are a bit more"+
   " rare, and a few you can't even place, but you have the feeling that"+
   " they have been collected more for intrigue than for actual value.",
   "statues" : "There are a few statues on the shelves, you see an elephant"+
   " carved from ivory, a serpent done in jade, and a cheetah made from"+
   " leopard granite that gives the animal beautiful spots.",
   ({"flowers","dried flowers"}) : "There are a few dried flowers on the"+
   " bookshelf as well. You notice a single purple rose as well as a smaller"+
   " boquet of delicate wildflowers.",
   "tapestry" : "Hanging on the southern wall is a beautiful tapestry. It"+
   " depicts the fall and has silken threads in the most brilliant and"+
   " breath-taking shades of yellows, oranges, reds, and pinks.",
   ({"rectangular mat","mat"}) : "There is a large rectangular mat that"+
   " stretches across the center of the room. It has a yellow border with"+
   " a white center, patterned within which are geometric shapes in colors"+
   " that nearly match the tapestry hanging on the wall, lovely reds,"+
   " yellows, and oranges.",
   ({"curtain","silk curtain","yellow curtain","yellow silk curtain"}) : "%^YELLOW%^There"+
   " is a curtain made of yellow silk that hangs across the entrance to the"+
   " west, giving the next room some privacy. The bottom of the curtain is"+
   " weighted with a few beads of fools gold.%^RESET%^",
   "table" : "There is a small wooden table that would be just big enough"+
   " for two people to eat off of. It is flanked on either side by two"+
   " wooden chairs.",
   ({"chairs","wooden chairs"}) : "There are two chairs made of oak that"+
   " are on either side of the table. They are hand carved and fairly"+
   " simple, but someone has carefully engraved beautiful rose and vine"+
   " designs along the edges of them.",
   ]));
   set_door("golden door",RPATH3+"3one30","southeast",0);
   set_exits( (["southeast":RPATH3+"3one30",
      "west":RPATH3+"3one22"]) );
}
