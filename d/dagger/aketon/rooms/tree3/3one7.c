#include "/d/dagger/aketon/short.h"

inherit VAULT;

void create() {
   ::create();
   set_property("light",2);
   set_property("indoors",1);
   set_short("An elven home of Aketon");
   set_long("%^GREEN%^An elven home of Aketon%^RESET%^\n"+
   "Picturesque is the best way to describe this home. It almost seems"+
   " as though no one lives here everything is so perfectly in its"+
   " place, and yet there is no dust anywhere so someone must take"+
   " care of the place. Along the north wall is a mahogany end table"+
   " that has a white lace runner spread out from end to end. Above"+
   " the end table is a portrait of a mother and father with their"+
   " little girl. On the east wall is a short ebony bookcase that"+
   " apparently contains a family history complete with several"+
   " journals. Atop the bookcase is an ivory statue of an elven priestess"+
   " wearing flowing robes. There are two ebony incense holders"+
   " flanking the statue with unused sticks of incense in them. There"+
   " is a picture of a dryad sitting in an oak tree with a slightly"+
   " sad and wistful expression. An umber couch is against the west"+
   " wall. Next to one end of the couch is a ceramic vase that has"+
   " been painted a deep sienna with several flowers on the front."+
   " There is a boquet of dried flowers that are in perfect shape in"+
   " the vase. Above the couch hangs a painting of an elven fighter"+
   " dressed shining fullplate with his sword drawn. A thick wine"+
   " colored rug covers the floor from wall to wall, with not a speck"+
   " of dust or dirt anywhere.");
   set_smell("default","You are assaulted by the many smells of the "
      "forest.");
   set_listen("default","The wind rustles through the leaves oustide.");
   set_items(([
   ({"table","mahogany table","end table","mahogany end table"}) : "A"+
   " mahogany end table is perfectly centered along the north wall."+
   " It has a flat, rectangular top with rounded corners. The legs"+
   " of the table curve outwards before coming back in, almost like"+
   " half an S. There is a lace runner on top of the table that"+
   " stretches from one end to the other.",
   ({"runner","lace runner"}) : "%^BOLD%^The white lace runner rests"+
   " on top of the mahogany end table, running from one end to the"+
   " other, the perfect length. The print of the lace is that of a"+
   " rose with hearts, it is very delicate and beautiful.%^RESET%^",
   ({"portrait","family portrait","north wall"}) : "A family portrait"+
   " has been placed in the exact center of the north wall. It shows"+
   " an older elven couple with a young girl in front of them and one"+
   " of the great trees of Aketon in the background.",
   ({"book case","bookcase","short book case","ebony book case"}) : "On"+
   " the east wall is a short ebony book case. The books in it appear"+
   " to be a family history and most of the space is taken up by thick"+
   " leather bound journals. On top of the book case there is a"+
   " statue of a priestess and two incense holders.",
   ({"books","journals"}) : "There are several thick, leather bound"+
   " journals as well as family books. You don't notice any other kinds"+
   " of books.",
   ({"statue","priestess","elven priestess","ivory statue"}) : "%^BOLD%^The"+
   " statue of the priestess is made out of solid ivory. You can tell"+
   " she is elven because of the delicately pointed ears, high cheek"+
   " bones and slender stature. She is dressed in flowing robes and"+
   " has her hands clasped together in front of her. You notice she"+
   " wears the symbol of Mielikki around her neck.",
   ({"incense","incense holders"}) : "There are two ebony incense"+
   " holders that flank the ivory statue of the priestess. They are"+
   " fairly simple and each hold an unused stick of incense.",
   ({"picture","dryad","east wall"}) : "On the east wall is a picture"+
   " of a dryad resting in her oak tree. She is very beautiful and is"+
   " modestly clothed in a mottled green dress. Her expression is"+
   " almost sorrowful and slightly wistful, as though she will miss"+
   " whoever is painting her portrait but knows that it will always"+
   " remind the painter of her.",
   ({"couch","umber couch"}) : "%^ORANGE%^There is a couch of a deep"+
   " umber along the west wall. The cushions are still stiff and"+
   " it doesn't appear to have had much use, even though it could"+
   " hold at least four elves.",
   ({"elven fighter","fighter","painting","west wall"}) : "On the west"+
   " wall is a painting of an elven fighter. He is dressed in fullplate"+
   " armor but has taken his helmet off. He holds a shining elven"+
   " long sword in front of him, but by his gentle expression you"+
   " doubt he has had much chance to use it other than in practice.",
   ({"vase","sienna vase"}) : "%^RED%^A vase of dark sienna sits near"+
   " the couch. It is over a foot tall and widens at the middle, with"+
   " a more slender neck and a wider mouth. You can see the inside of"+
   " the vase has been glazed %^BOLD%^%^WHITE%^white%^RESET%^%^RED%^."+
   " On the front of the vase are painted three %^BOLD%^%^WHITE%^white"+
   " gardenias%^RESET%^%^RED%^ with %^GREEN%^green stems%^RED%^. The"+
   " detail of the flowers and leaves is wonderful. The vase holds a"+
   " boquet of dried flowers.%^RESET%^",
   ({"flowers","boquet","dried flowers"}) : "A boquet of dried flowers"+
   " rests in the vase at the side of the couch. The flowers are mostly"+
   " red roses with a few poppies and some baby's breath and ferns. They"+
   " are perfect and free of dust, but look quite fragile.",
   ({"rug","thick rug","wine rug"}) : "%^MAGENTA%^The entire floor is"+
   " covered in a thick wine rug. You don't make any footsteps walking"+
   " across it and it is very cushiony. There is no dust or dirt"+
   " anywhere, except what you may have tracked in.",
   ]));
   set_door("door",RPATH3+"3one13","south",0);
   set_exits( (["south":RPATH3+"3one13"]) );
}
