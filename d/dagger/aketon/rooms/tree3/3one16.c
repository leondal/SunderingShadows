#include "/d/dagger/aketon/short.h"

inherit ROOM;

void create() {
   ::create();
   set_property("light",2);
   set_short("A balcony of Aketon");
   set_long("%^GREEN%^A balcony of Aketon%^RESET%^\n"+
   "You are standing on a small platform that has a railing running"+
   " around the edges of it to make sure people don't fall off. The"+
   " balcony provides a beautiful view of the tree beneath you. You"+
   " realize you are quite high up despite being only on the first"+
   " level of this magnificent tree. There are some wind chimes that"+
   " someone hung here that jingle merrily whenever there's a breeze."+
   " There's also a bowl of fruit and some tea that's kept in a"+
   " ceramic jug for elven refreshments.");
   set_smell("default","You are assaulted by the many smells of the "
      "forest.");
   set_listen("default","The wind chimes jingle merrily.");
   set_items(([
   "railing" : "There is a railing made of solid wood. The top bar"+
   " is done in the shape of a curving vine and the vertical bars are"+
   " carved with leaf and flower designs.",
   ({"chimes","wind chimes"}) : "Silver wind chimes jingle merrily"+
   " in the breeze. There are several slender, hollow tubes, attached"+
   " to the end of each is a delicate metal butterfly. They make a"+
   " light, pleasant sound that soothes your senses.",
   ({"bowl","fruit"}) : "There is a bowl of various fruit here that"+
   " the elves eat as a light refreshment when they come here to"+
   " enjoy the pretty scenery.",
   ({"jug","ceramic jug","tea"}) : "Some herbal tea is kept in a ceramic"+
   " jug as a refreshment for the elven citizens.",
   ]));
   set_exits( (["east":RPATH3+"3one17"]) );
}
