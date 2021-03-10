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
   set_short("%^BOLD%^%^CYAN%^A Gl%^RESET%^%^CYAN%^a%^BOLD%^ss Ch%^RESET%^%^CYAN%^a%^WHITE%^%^BOLD%^m%^CYAN%^ber fu%^RESET%^%^CYAN%^l%^BOLD%^l of %^RESET%^%^MAGENTA%^st%^BOLD%^re%^RESET%^%^MAGENTA%^amers%^RESET%^");
   set_long("%^RESET%^%^CYAN%^This room is the very definition of vibrant and cheerful, to the point of utter %^BOLD%^c"
"%^BLUE%^h%^MAGENTA%^a%^WHITE%^o%^YELLOW%^s%^RESET%^%^CYAN%^!  The %^BOLD%^opaque glass walls %^RESET%^%^CYAN%^of the "
"bottle are stuck all about with streamers and balloons in a %^BOLD%^%^RED%^r%^MAGENTA%^a%^RESET%^%^MAGENTA%^i%^BLUE%^n"
"%^GREEN%^b%^YELLOW%^o%^RESET%^%^ORANGE%^w %^CYAN%^of colors.  The floor, while once perhaps a lovely color, is now "
"strewn all about with %^RESET%^papers%^CYAN%^, %^MAGENTA%^folders %^CYAN%^and %^ORANGE%^books %^CYAN%^- whoever "
"organized those is going to have a %^BOLD%^%^BLACK%^sto%^RESET%^rm%^BOLD%^%^BLACK%^y f%^YELLOW%^i%^BLACK%^t %^RESET%^"
"%^CYAN%^later, you're sure.  A huge crowd of players and the occasional immortal are laughing and chattering around the "
"room, some lounging on the comfortable %^RESET%^divans %^CYAN%^in the middle of the room.  The %^BOLD%^%^BLACK%^stone "
"table %^RESET%^%^CYAN%^in the very centre has been cleared off to make way for a tiered cake covered in %^BOLD%^%^WHITE%^"
"flu%^RESET%^ff%^BOLD%^%^WHITE%^y white i%^CYAN%^c%^WHITE%^ing %^RESET%^%^CYAN%^and %^YELLOW%^r%^RESET%^%^ORANGE%^a%^RED%^"
"i%^BOLD%^n%^MAGENTA%^b%^RESET%^%^MAGENTA%^o%^BLUE%^w %^CYAN%^s%^GREEN%^p%^BOLD%^r%^YELLOW%^i%^RESET%^%^ORANGE%^n%^RED%^k"
"%^BOLD%^l%^MAGENTA%^e%^RESET%^%^MAGENTA%^s%^CYAN%^.  Another small table has been brought in, sitting off to the side "
"and piled up with %^YELLOW%^pr%^MAGENTA%^e%^YELLOW%^sents %^RESET%^%^CYAN%^of all shapes and sizes.  The scrying table "
"and the box of figurines have both been set down off to the side, disregarded by the visitors.\n%^RESET%^");
   set_smell("default","%^ORANGE%^The aroma of tangerine and %^BOLD%^%^WHITE%^vanilla %^RESET%^%^ORANGE%^mingles with the %^BOLD%^%^MAGENTA%^sug%^WHITE%^a%^MAGENTA%^ry %^RESET%^%^ORANGE%^smell of cake!%^RESET%^");
   set_listen("default","%^GREEN%^A hum of %^ORANGE%^ch%^YELLOW%^a%^RESET%^%^ORANGE%^tter %^GREEN%^and cheerful %^YELLOW%^la%^CYAN%^u%^WHITE%^g%^YELLOW%^hter %^RESET%^%^GREEN%^constantly fills the room.%^RESET%^"); 

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
   switch(random(22)) {
     case 0..1:
     tell_room(TO,"%^CYAN%^A %^BOLD%^%^BLUE%^soggy-wet %^RESET%^%^CYAN%^half-orc runs past, trailing a mischevious puppy "
"with streamers in its mouth.  Droplets of %^BOLD%^%^BLUE%^w%^CYAN%^a%^WHITE%^t%^BLUE%^er %^RESET%^%^CYAN%^spray all "
"about as he goes, wailing mournfully %^ORANGE%^'Floppy noooo, those are for the party!'%^RESET%^");
     break;
     case 2..3:
     tell_room(TO,"%^CYAN%^An %^ORANGE%^aw%^RED%^k%^ORANGE%^ward %^CYAN%^little puppy rockets past with paws askew, "
"scrambling across the ground.  %^BOLD%^%^BLACK%^Flo%^RESET%^%^ORANGE%^pp%^BOLD%^%^BLACK%^y ears %^RESET%^%^CYAN%^trail "
"out behind him along with a bunch of %^BOLD%^%^MAGENTA%^st%^YELLOW%^r%^WHITE%^ea%^MAGENTA%^mers %^RESET%^%^CYAN%^and "
"%^RED%^ba%^MAGENTA%^ll%^BLUE%^oo%^GREEN%^ns%^CYAN%^, the strings of which he has gripped in his mouth.%^RESET%^");
     break;
     case 4..5:
     tell_room(TO,"%^CYAN%^The candles waver %^YELLOW%^ch%^RED%^e%^YELLOW%^erf%^WHITE%^u%^YELLOW%^lly %^RESET%^%^CYAN%^"
"atop the %^BOLD%^%^WHITE%^flu%^RESET%^ff%^BOLD%^%^WHITE%^y %^RESET%^%^CYAN%^cake, just waiting to be blown out by the "
"birthday girl!%^RESET%^");
     break;
     case 6..7:
     tell_room(TO,"%^RESET%^Whispy %^CYAN%^tendrils of %^BOLD%^%^WHITE%^clo%^CYAN%^u%^WHITE%^d %^RESET%^%^CYAN%^fluff-"
"fluff past, changing shape as they go. Maybe you just imagined it, but you're sure you just saw %^YELLOW%^'%^MAGENTA%^"
"happy birthday%^YELLOW%^' %^RESET%^%^CYAN%^spelled out.%^RESET%^");
     break;
     case 8..9:
     tell_room(TO,"%^CYAN%^A %^BOLD%^%^RED%^b%^MAGENTA%^r%^RESET%^%^MAGENTA%^i%^BLUE%^g%^GREEN%^h%^BOLD%^t%^YELLOW%^l"
"%^RESET%^%^ORANGE%^y %^CYAN%^clad little halfling shuffles past.  She has a sizeable chunk of cake in each hand, which "
"she is presently stuffing in her mouth with a contented %^YELLOW%^'%^RESET%^%^ORANGE%^nom-nom-nom%^YELLOW%^'%^RESET%^"
"%^CYAN%^.%^RESET%^");
     break;
     case 10..11:
     tell_room(TO,"%^CYAN%^The sound of %^MAGENTA%^music %^CYAN%^drifts through the area, sometimes to the tune of "
"%^BOLD%^%^MAGENTA%^'Happy Birthday' %^RESET%^%^CYAN%^and at other times, just forming pleasant background noise. The "
"cheerful melody is oft punctuated by the trilling of a %^GREEN%^j%^BOLD%^a%^BLACK%^d%^RESET%^%^GREEN%^e f%^RESET%^l"
"%^BOLD%^%^WHITE%^u%^GREEN%^t%^RESET%^%^GREEN%^e%^CYAN%^, in the hands of a lovely %^BOLD%^%^BLACK%^s%^RESET%^%^ORANGE%^a"
"%^BOLD%^%^BLACK%^ble-haired %^RESET%^%^CYAN%^woman off to the side.%^RESET%^");
     break;
     case 12..13:
     tell_room(TO,"%^CYAN%^A group of friendly players take a pause from their complaints to break into a chorus of "
"%^BOLD%^%^MAGENTA%^'Happy Birthday to the Cloudee!'%^RESET%^");
     break;
     case 14..15:
     tell_room(TO,"%^CYAN%^A cloaked figure with drawn, %^RESET%^ske%^BOLD%^%^WHITE%^l%^RESET%^etal %^CYAN%^features "
"shuffles forward to add another present to the pile on the table. Could it be that rare, almost mythological creature "
"known as a %^BOLD%^%^BLUE%^liche%^RESET%^%^CYAN%^? Judging by the way it %^YELLOW%^gnaps %^RESET%^%^CYAN%^at anyone that "
"gets close, perhaps so...%^RESET%^");
     break;
     case 16..17:
     tell_room(TO,"%^CYAN%^A %^YELLOW%^telephone symbol %^RESET%^%^CYAN%^floats past, chewing on some %^ORANGE%^beef hash "
"%^CYAN%^and chattering incessantly... and a %^BOLD%^%^BLACK%^shadowy%^RESET%^%^CYAN%^, slightly taller telephone symbol "
"stalks along behind it, completely silent. Uh?%^RESET%^");
     break;
     case 18..19:
     tell_room(TO,"%^CYAN%^A congregation of %^RESET%^bunneez %^CYAN%^hop-hop around amongst the players, munching on "
"bits of %^BOLD%^%^WHITE%^cake %^RESET%^%^CYAN%^and %^ORANGE%^carrot%^CYAN%^.  One suddenly leaps and drags off a "
"troublemaking player, and they are never seen again...%^RESET%^");
     break;
     case 20..21:
     tell_room(TO,"%^RED%^S%^BLUE%^c%^WHITE%^a%^GREEN%^l%^BOLD%^%^BLACK%^y %^RESET%^%^CYAN%^claws reach out, plucking a "
"few choice gifts from the presents table.  A player goes to complain, and the five-headed dagronz on the other end of "
"the claw snorts a gout of %^BOLD%^%^RED%^fla%^YELLOW%^m%^RED%^e%^RESET%^%^CYAN%^.  The %^BOLD%^%^BLACK%^s%^RESET%^mo"
"%^BOLD%^%^BLACK%^ked %^RESET%^%^CYAN%^player stutters off, as the dagronz clarifies %^BOLD%^'Only borrowing for hoard, "
"silly playur'%^RESET%^%^CYAN%^.%^RESET%^");
     break;
     default: break;
   }
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
