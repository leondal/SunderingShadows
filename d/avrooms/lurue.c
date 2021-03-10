// This place was designed for the Avatar Lurue as a workroom for plots and planning. She also had fun making the place fun and inviting. Props to Avatar Ibrandul, Lurue's trainer, for the original design concept of the genie bottle. And even more props to Creator Nienne for being the wizard who finalized and fixed up the coding. Yay them!

#include <std.h> 
inherit ROOM; 

void create() { 
   ::create(); 
   set_property("indoors",1); 
   set_property("light",2); 
   set_property("no teleport",1);
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_name("A Palatial Glass Chamber"); 
   set_short("%^BOLD%^%^CYAN%^A P%^RESET%^%^CYAN%^al%^BOLD%^%^WHITE%^a%^RESET%^%^CYAN%^t%^BOLD%^ial Gl%^RESET%^%^CYAN%^a%^BOLD%^ss Ch%^RESET%^%^CYAN%^a%^WHITE%^%^BOLD%^m%^CYAN%^ber%^RESET%^");
   set_long("%^RESET%^%^CYAN%^The walls of this palatial room are made of opaque, %^BOLD%^pale blue glass%^RESET%^%^CYAN%^"
".  Flawless, the smooth surfaces rise upward from the floor in an ever narrowing curve.  At the top, where the walls meet"
", a slender column can be seen leading up into the %^BOLD%^%^BLACK%^darkness %^RESET%^%^CYAN%^above.  In the center of "
"the room, comfortable looking %^RESET%^divans %^CYAN%^are arranged around a low %^BOLD%^%^BLACK%^stone table %^RESET%^"
"%^CYAN%^with a smooth, flat surface.  A thick pile of soft %^BOLD%^blue %^RESET%^%^CYAN%^and %^RESET%^white %^CYAN%^"
"carpet stretches under them, creating a sky like effect.  Above a globe of light hovers casting a %^BOLD%^cool glow "
"%^RESET%^%^CYAN%^upon the area, illuminating the %^RED%^b%^BOLD%^e%^YELLOW%^j%^RESET%^%^ORANGE%^e%^BOLD%^%^GREEN%^w"
"%^RESET%^%^GREEN%^e%^BLUE%^l%^CYAN%^e%^MAGENTA%^d %^CYAN%^grid etched into the table and the miniature figurines "
"arranged across the top.  A stack of %^MAGENTA%^c%^RESET%^o%^BLUE%^l%^MAGENTA%^or%^CYAN%^e%^MAGENTA%^d %^CYAN%^folders "
"are organized to one side, beside which is an ancient looking, ornate %^ORANGE%^clay %^CYAN%^box.  To the side of this "
"sitting area is a grouping of %^BOLD%^%^BLACK%^stone bookshelves %^RESET%^%^CYAN%^with a large leather recliner nearby "
"for relaxing and reading one of the many books, scrolls or stories.  Everything is arranged for comfort and relaxation "
"while working, studying or researching.%^RESET%^\n");
   set_smell("default","The light scent of tangerine and %^BOLD%^%^WHITE%^vanilla %^RESET%^%^ORANGE%^drift in the %^BOLD%^%^CYAN%^air%^RESET%^%^ORANGE%^ here.%^RESET%^");
   set_listen("default","%^RESET%^%^GREEN%^From somewhere distant, the gentle sound of %^BOLD%^%^CYAN%^w%^WHITE%^i%^RESET%^%^CYAN%^n%^BOLD%^d ch%^RESET%^i%^CYAN%^m%^BOLD%^es%^RESET%^%^GREEN%^ can be heard.%^RESET%^");

/*   set_long("%^RESET%^%^CYAN%^The walls of this %^BOLD%^p%^RESET%^%^CYAN%^al%^BOLD%^%^WHITE%^a%^RESET%^%^CYAN%^t%^BOLD%^ial %^RESET%^%^CYAN%^room are made of opaque, %^BOLD%^p%^WHITE%^a%^CYAN%^le b%^WHITE%^l%^CYAN%^ue %^RESET%^%^CYAN%^glass. "
"%^BOLD%^%^WHITE%^Fl%^RESET%^a%^BOLD%^%^WHITE%^wl%^RESET%^e%^BOLD%^%^WHITE%^ss%^RESET%^%^CYAN%^, the smooth surfaces rise upward from the floor in an ever narrowing %^BOLD%^%^BLACK%^c%^RESET%^u%^BOLD%^%^BLACK%^rve%^RESET%^%^CYAN%^. At the top, where the walls meet, a slender "
"%^BOLD%^%^WHITE%^c%^CYAN%^ol%^RESET%^u%^BOLD%^%^WHITE%^mn %^RESET%^%^CYAN%^can be seen leading up into the %^BOLD%^%^BLACK%^d%^RESET%^%^CYAN%^a%^RESET%^r%^BOLD%^%^BLACK%^kness %^RESET%^%^CYAN%^above. Large, comfortable looking "
"%^BOLD%^%^WHITE%^d%^RESET%^i%^BOLD%^%^WHITE%^vans %^RESET%^%^CYAN%^are arranged around the center portion of the room, their surfaces covered in plush %^BOLD%^%^WHITE%^wh%^RESET%^i%^BOLD%^%^WHITE%^te%^RESET%^%^CYAN%^, overstuffed suede and accented with "
"%^BOLD%^%^BLACK%^s%^RESET%^i%^BOLD%^%^WHITE%^l%^BLACK%^very p%^RESET%^i%^BOLD%^%^WHITE%^ll%^BLACK%^ows%^RESET%^%^CYAN%^.\nIn the center of the sitting area is a low %^BOLD%^%^BLACK%^st%^RESET%^o%^BOLD%^%^BLACK%^ne%^RESET%^%^CYAN%^ table. "
"Vaguely circular, the top has been sheared away to leave a %^BOLD%^sm%^RESET%^%^CYAN%^o%^BOLD%^oth%^RESET%^%^CYAN%^, flat surface. Counter to this, the sides are left natural, sloping downward to the thick pile of %^BOLD%^b%^RESET%^%^CYAN%^l%^BOLD%^ue %^RESET%^%^CYAN%^and "
"%^BOLD%^%^WHITE%^wh%^RESET%^i%^BOLD%^%^WHITE%^te %^RESET%^%^CYAN%^carpet. A %^RED%^b%^BOLD%^e%^YELLOW%^j%^RESET%^%^ORANGE%^e%^GREEN%^w%^BOLD%^%^GREEN%^e%^BLUE%^l%^RESET%^%^CYAN%^e%^MAGENTA%^d %^RESET%^%^CYAN%^grid has been etched into the table's surface, and several, life-like, miniature "
"%^BOLD%^%^BLACK%^f%^RESET%^i%^BOLD%^%^WHITE%^g%^BLACK%^ures %^RESET%^%^CYAN%^can be seen set across it. A stack of neatly organized, %^BOLD%^%^WHITE%^c%^CYAN%^o%^RESET%^%^CYAN%^l%^BOLD%^o%^WHITE%^red %^RESET%^%^CYAN%^folders are stacked to one side, beside which an ancient "
"looking, %^BOLD%^%^CYAN%^o%^WHITE%^r%^RESET%^%^CYAN%^n%^BOLD%^ate %^RESET%^%^CYAN%^clay box has been placed.\nTo the left, beyond this seating area are a grouping of %^BOLD%^%^BLACK%^st%^RESET%^o%^BOLD%^%^BLACK%^ne %^RESET%^%^CYAN%^shelves and a single, deep-cushioned recliner whose "
"%^BOLD%^%^BLACK%^d%^RESET%^a%^BOLD%^%^BLACK%^rk g%^RESET%^%^CYAN%^r%^BOLD%^%^BLACK%^ay %^RESET%^%^CYAN%^suede looks quite inviting. The shelves are packed with %^BOLD%^%^WHITE%^sc%^RESET%^%^CYAN%^r%^RESET%^o%^BOLD%^%^WHITE%^lls%^RESET%^%^CYAN%^, %^BOLD%^%^BLACK%^b%^RESET%^o%^CYAN%^o%^BOLD%^%^BLACK%^ks "
"%^RESET%^%^CYAN%^and %^BOLD%^%^CYAN%^l%^RESET%^%^CYAN%^o%^BOLD%^ose%^RESET%^%^CYAN%^-%^BOLD%^l%^RESET%^%^CYAN%^e%^BOLD%^af %^RESET%^%^CYAN%^slips of paper. %^BOLD%^%^CYAN%^V%^RESET%^%^CYAN%^i%^RESET%^a%^BOLD%^%^CYAN%^ls, "
"%^BOLD%^%^WHITE%^tr%^RESET%^i%^BOLD%^%^BLACK%^n%^WHITE%^kets %^RESET%^%^CYAN%^and %^BOLD%^%^WHITE%^st%^CYAN%^a%^WHITE%^tu%^CYAN%^a%^WHITE%^ry %^RESET%^%^CYAN%^have been used as bookends but the reading material appears to be winning the battle. Above everything, suspended mid-air, a "
"%^BOLD%^%^WHITE%^gl%^CYAN%^o%^WHITE%^be %^RESET%^%^CYAN%^of %^BOLD%^%^CYAN%^l%^WHITE%^i%^CYAN%^ght %^RESET%^%^CYAN%^hovers casting a %^BOLD%^%^WHITE%^c%^CYAN%^o%^WHITE%^ol gl%^CYAN%^o%^WHITE%^w %^RESET%^%^CYAN%^upon the chamber.\n%^RESET%^"); */

   set_items(([ 
({"light","globe"}) : "%^RESET%^%^CYAN%^The globe of light appears to simply float in midair, hovering above the sitting area and casting its %^BOLD%^%^BLACK%^s%^RESET%^i%^BOLD%^%^WHITE%^l%^BLACK%^very %^RESET%^%^CYAN%^glow across the room.%^RESET%^",
({"divan","divans","couch","couches","seats","chairs","chair"}) : "%^RESET%^%^CYAN%^Deeply padded, these large couches could easily surround you in their plush embrace. Covered in soft %^BOLD%^%^WHITE%^wh%^RESET%^i%^BOLD%^%^WHITE%^te "
"su%^RESET%^e%^BOLD%^%^WHITE%^de %^RESET%^%^CYAN%^and accented with %^BOLD%^%^BLACK%^s%^RESET%^i%^BOLD%^%^WHITE%^l%^BLACK%^ver p%^RESET%^i%^BOLD%^%^WHITE%^l%^BLACK%^lows%^RESET%^%^CYAN%^, they look inviting for curling up on with a good book or plot.%^RESET%^", 
({"opening","column","darkness","ceiling"}) : "%^RESET%^%^CYAN%^The ceiling is dome like, curving upward from the side walls to a central, slender opening that vanishes into the darkness above. The column itself is far too narrow for passage by anything more then %^WHITE%^%^BOLD%^gas%^RESET%^ %^CYAN%^or %^BOLD%^liquid%^RESET%^%^CYAN%^, perhaps it functions as a flu or skylight allowing fresh air into the room. %^RESET%^", 
({"floor","carpet","pile"}) : "%^RESET%^%^CYAN%^The carpet is thick and lush, a heavy pile that cushions movement and deafens sound within this glass chamber. Designed to look like a %^BOLD%^%^CYAN%^blue sky %^RESET%^%^CYAN%^dotted with %^BOLD%^%^WHITE%^white clouds %^RESET%^%^CYAN%^it covers the entire circular glass floor.%^RESET%^", 
({"glass","wall","walls","glass walls","glass wall"}) : "%^RESET%^%^CYAN%^The walls of this circular room are made of opaque, %^BOLD%^pale blue glass %^RESET%^%^CYAN%^that is %^BOLD%^%^WHITE%^fl%^CYAN%^a%^RESET%^w%^BOLD%^%^WHITE%^less "
"%^RESET%^%^CYAN%^in its design. Clearly crafted by a %^BOLD%^%^BLACK%^master%^RESET%^%^CYAN%^, the walls rise up from a glass floor, curving to form the ceiling which gives way to a narrow flu at the center. The only apparent way in or out of this palatial room.%^RESET%^", 
({"pillow","pillows"}) : "%^CYAN%^%^These thickly padded pillows are made of %^BOLD%^%^BLACK%^s%^RESET%^i%^BOLD%^%^WHITE%^l%^BLACK%^very s%^WHITE%^i%^BLACK%^lk %^RESET%^%^CYAN%^and seem very inviting. %^RESET%^", 
({"figure","figures","miniature","miniatures"}) : "%^CYAN%^Turning your gaze upon the %^BOLD%^%^BLACK%^miniature figures %^RESET%^%^CYAN%^scattered around the table, you realize that they are in fact moving of their own "
"accord. Traveling over the surface of the table with some form of invisible guidance. Oddly, at times, they seem to %^BOLD%^%^BLACK%^vanish %^RESET%^%^CYAN%^and %^BOLD%^reappear %^RESET%^%^CYAN%^at random.%^RESET%^", 
({"folders","folder","colored folders"}) : "%^CYAN%^Set to the side of the table and apparently out of the way are a stack of neatly arranged %^RED%^c%^YELLOW%^o%^GREEN%^l%^BLUE%^o%^RESET%^%^MAGENTA%^r %^CYAN%^folders. Some are thick, others are slender, each has a colored "
"label across the top formed of words that seem to make a description. They must match up with the little %^BOLD%^%^BLACK%^figures %^RESET%^%^CYAN%^moving around the table.%^RESET%^", 
({"box","clay box"}) : "%^RESET%^%^CYAN%^This %^ORANGE%^clay box %^CYAN%^looks old and well used. Painted %^BOLD%^%^BLACK%^black %^RESET%^%^CYAN%^on the sides, %^ORANGE%^tan figures %^CYAN%^adorn the sides in an archaic blocky styling. Three figures can be seen on each side of this square container, each engaged in their own activities as they "
"watch over mortals depicted below them. One holds a %^BOLD%^spindle%^RESET%^%^CYAN%^, the second a %^ORANGE%^staff %^CYAN%^with many knobs evenly spaced along it, the last holds a %^BOLD%^%^BLACK%^knife%^RESET%^%^CYAN%^. The mortals below them change and yet each seems to be caught in the moment of destiny. A ship at sea pointed toward %^BOLD%^%^BLACK%^stormy clouds%^RESET%^%^CYAN%^, a warrior upon a "
"raging %^ORANGE%^battle field%^CYAN%^, a set of %^WHITE%^passages %^CYAN%^where two groups might intersect and lastly a %^BOLD%^meadow %^RESET%^with a wide %^BOLD%^%^BLACK%^ditch %^RESET%^%^CYAN%^over which horse riders charge.%^RESET%^", 
({"shelves","shelf","stone shelves","bookshelves","bookcase","bookshelf"}) : "%^CYAN%^These shelves look to be made out of the same %^BOLD%^%^BLACK%^stone %^RESET%^%^CYAN%^as the table at the center of the sitting area, although in this case they have been made of %^BOLD%^sm%^RESET%^o%^CYAN%^o%^BOLD%^th %^RESET%^%^CYAN%^planes of stone. "
"Every shelf is covered in books, tomes, scrolls, tablets and loose sheaves of paper. For those places where the shelves are not completely full, small statues, vials, bottles and other such random paraphernalia has been used as book ends.%^RESET%^", 
({"recliner","seat"}) : "%^RESET%^%^CYAN%^Circled by stone shelves that line the walls in this part of the room, the %^BOLD%^%^BLACK%^gray suede %^RESET%^%^CYAN%^recliner looks very inviting. The soft suede is thickly padded but not as encompassing as the divans in the other part of the room. Instead this chair seems made to support the user as they read, offering a pillowed head rest and lots of room to stretch out.%^RESET%^", 
({"scroll","scrolls","book","books","paper","papers","loose-leaf","vial","vials","trinket","trinkets","statues","statuary","statue"}) : "%^RESET%^%^CYAN%^Covering each shelf is a vast array of books, tomes, tablets, scrolls, sheets of paper and other written works all awaiting "
"inspection. A few small statues, vials and other brick-a-brac has been set amongst the shelves to provide a form of bookend, but the majority of the shelf space is devoted to the written works. There seems to be an entire world of literature waiting to be %^BOLD%^research%^RESET%^%^CYAN%^ed. %^RESET%^", 
   ])); 
}

void init() {
   ::init();
   add_action("scry_me","view");
   add_action("open_box","open");
   add_action("escape_fun","escape");
}

void reset() {
   if(!present("scrytable")) new("/d/avrooms/scrytable")->move(TO);
}

int open_box(string str) {
   if(!str) return 0;
   if(str != "box") return 0;
   tell_object(TP,"%^CYAN%^You open the clay box and peer inside. Sitting within are a complete set of "
"polyhedron dice just waiting to decide the outcome of some poor character's fate.%^RESET%^");
   tell_room(TO,"%^CYAN%^"+TP->QCN+"%^RESET%^%^CYAN%^ opens the box and peers inside.",TP);
   return 1;
}

int scry_me(string str) {
   object mytable;
   if(!str) return 0;
   if(str != "grid") return 0;
   if(!avatarp(TP)) return 0;
   if(!present("scrytable")) {
     notify_fail("%^RESET%^%^CYAN%^There is no table here to watch.%^RESET%^");
     return 0;
   }
   mytable = present("scrytable");
   if((int)mytable->query_property("magic mirror")) {
     notify_fail("%^RESET%^%^CYAN%^The figures are already moving!%^RESET%^");
     return 0;
   }
   tell_room(TO,"%^CYAN%^The jeweled lines etched upon the %^BOLD%^sh%^WHITE%^i%^RESET%^%^CYAN%^m%^BOLD%^mer %^RESET%^%^CYAN%^brightly with a %^BOLD%^%^RED%^r%^RESET%^%^RED%^a%^YELLOW%^i%^RESET%^%^ORANGE%^n%^GREEN%^b%^BLUE%^o%^MAGENTA%^w%^RESET%^%^CYAN%^ of colors, and the minature figures start moving!%^RESET%^"); 
   new("/cmds/spells/m/_magic_mirror")->use_spell(TP,"table",150,100,"mage");
   return 1;
}

int escape_fun(string str) {
   object destination;
   if(!avatarp(TP)) return notify_fail("Naughty player, no escaping!");
   if(!str) return notify_fail("What do you want to escape?");
   if(str != "bottle") return notify_fail("You can't escape that.");
   tell_object(TP,"%^BOLD%^%^BLACK%^You escape the bottle!%^RESET%^");
   tell_room(TO,"%^BOLD%^%^BLACK%^"+TP->QCN+" escapes the bottle!%^RESET%^",TP);
   destination = find_object_or_load("/d/avrooms/ibrandul");
   TP->move(destination);
   TP->force_me("look");
   return 1;
}

