// Kain added as worker, not owner til HM. Nienne, 08/09.
#include <std.h>
#include <daemons.h>

#define RSHOP "/d/player_stores/rubicant/"
#define TORMC "/d/dagger/Torm/city/"
#define SHOPKEY "darksteel key"
#define MAX_ITEMS 10

inherit "/std/pstore";

void create() {
        ::create();
     set_owners(({"styx", "rubicant", "tsera", "nienne", "ares", "cythera", "lujke", "kain" }));
  set_storage(RSHOP+"sell");
  set_drop_storage(RSHOP+"repairs");
  set_drop_deposit(500);   
  set_items_allowed( ({ "jewelry", "clothing" }) );
        set_property("indoors",1);
        set_property("light",2);
        set_terrain(STONE_BUILDING);
        set_travel(PAVED_ROAD);
        set_name("The Scarlet Angel");
        set_short("%^RESET%^%^BOLD%^%^RED%^The Scarlet Angel%^RESET%^");
        set_long( (: TO, "ldesc" :) );
        set_smell("default","%^RED%^Whiffs of exotic spices tickle your senses.");
        set_listen("default","%^BOLD%^%^BLACK%^It is silent except for the occasional sounds of customers.");
        set_items(([
           ({"pillars","obsidian pillars"}) : "%^BOLD%^%^BLACK%^These "
"masterwork pillars are carved from %^RESET%^%^BLUE%^pure obsidian"
"%^BOLD%^%^BLACK%^ and kept impeccably clean, each adorned with an "
"%^RESET%^%^BLUE%^ornate black sconce%^BOLD%^%^BLACK%^.",
           "walls" : "The walls are made of %^BOLD%^%^BLACK%^gr%^RESET%^"
"%^WHITE%^a%^BOLD%^n%^RESET%^i%^BOLD%^%^BLACK%^te%^RESET%^ that has been "
"smoothed and polished to a %^BOLD%^%^CYAN%^mirrorlike%^RESET%^ sheen.  "
"On each wall are %^MAGENTA%^exquisite paintings%^WHITE%^ and %^RED%^"
"doors%^WHITE%^, perhaps a closer look at each wall would reveal more.",
            "paintings" : (: TO, "paintings" :),
           ({"north wall", "back wall" }) : (: TO, "nwall" :),
           ({"eyes of the magi", "Eyes of the Magi", "painting 1", "mage painting", "magi painting" }) : (: TO, "paint1" :),
           ({"faithful to the king", "Faithful to the King", "painting 2", "king painting" }) : (: TO, "paint2" :),
           "east wall" : (: TO, "ewall" :),
           ({"blessing of light", "Blessing of Light", "painting 3", "priest painting", "last rites painting" }) : (: TO, "paint3" :),
           ({"angel of light", "Angel of Light", "light angel painting", "male angel painting", "painting 4" }) : (: TO, "paint4" :),
           ({"angel of darkness", "Angel of Darkness", "dark angel painting", "female angel painting", "painting 5" }) : (: TO, "paint5" :),
           ({"curse of darkness", "Curse of Darkness", "painting 6", "necromancer painting", "undead painting" }) : (: TO, "paint6" :),
           ({"south wall", "front wall" }) : (: TO, "swall" :),
           ({"the first night", "The First Night", "painting 7", "halfling painting", "tavern painting" }) : (: TO, "paint7" :),
           ({"the last day", "The Last Day", "painting 8", "elven woman painting" }) : (: TO, "paint8" :),
           "west wall" : (: TO, "wwall" :),
           ({"vision of the storm", "Vision of the Storm", "storm painting", "painting 9" }) : (: TO, "paint9" :),
           ({"the watcher", "The Watcher", "painting 10", "mirror painting" }) : (: TO, "paint10" :),
           ({"the seer", "The Seer", "ball painting", "orb painting", "painting 11" }) : (: TO, "paint11" :),
           ({"vision of the calm", "Vision of the Calm", "painting 12", "garden painting", "peaceful painting" }) : (: TO, "paint12" :),
           ({"sign", "black sign" }) : 
"%^BOLD%^%^RED%^The Scarlet Angel clothing and jewelry repair\n%^RESET%"
"^*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*\n%^BOLD%^%^RED%^"
"Deposit items for repair for a %^YELLOW%^"+TO->query_deposit()+
" gold %^RED%^fee.\nOnce repaired, you may pick them up for a repair "
"cost determined by management.",
           ({"sconces", "lighting", "lights", "light" }) : "%^YELLOW%^Ample "
"lighting%^RESET%^ is provided by the %^BOLD%^%^BLACK%^ornate black "
"iron sconces%^RESET%^ on each of the %^BOLD%^%^BLACK%^pillars%^RESET%^ "
"in the shop. Magical in nature, they give off no smoke and burn "
"%^BOLD%^brilliantly%^RESET%^ at all times, illuminating far more than "
"the flames would normally.",
           ({"ceiling", "dome", "mural", "armies" }) : (: TO, "ceiling" :),
           ({"counter", "display", "glass counter" }) : (: TO, "display" :),
           "jewelry" : "The %^BOLD%^jewelry%^RESET%^ in the %^BOLD%^"
"%^CYAN%^glass cases%^RESET%^ of the circular counter has obviously "
"been designed with the latest styles for the wealthy of the realms.  "
"Each piece is set in %^BOLD%^%^BLACK%^black velvet%^RESET%^, "
"emphasizing each of their features.",
           ({"statue", "angel", "scarlet angel", "sculpture" }) : (: TO, "angel" :),
           "statues" : (: TO, "statues" :),
           "clothing" : "%^RED%^The clothing in the shop appears to be "
"in quality and style appealing to the wealthier people of the realms.  "
"The clothes are worn by the %^RESET%^statues%^RED%^ in the same fashion "
"as they would be on a person, giving a very good idea of what they will "
"look like when worn.",
           ({"paths", "path", "marble", "marble paths" }) : "%^BOLD%^"
"%^BLACK%^There are four paths made of %^RESET%^%^BLUE%^black marble"
"%^BOLD%^%^BLACK%^, which has been polished to a %^CYAN%^mirrorlike"
"%^BLACK%^ sheen, which connect in the center in a path around the "
"%^CYAN%^glass counter%^BLACK%^ displaying the jewelry. Each path is "
"wide enough for two medium humanoids to walk side by side, and leads "
"in a straight line from each of the doors to the center counter.",
           ({"floor", "ground" }) : "%^RED%^The floor is covered mostly "
"in a plush %^BOLD%^scarlet carpet%^RESET%^%^RED%^, which is divided "
"into four sections in the corners of the shop by %^BOLD%^%^BLACK%^paths "
"of black marble%^RESET%^%^RED%^.",
           ({"carpet", "carpeting" }) : "%^RED%^The carpet is thick and "
"plush, incredibly comfortable and soft to the touch. It is a %^BOLD%^"
"deep scarlet%^RESET%^%^RED%^ in color, much like %^BOLD%^fresh blood"
"%^RESET%^%^RED%^, and muffles your footsteps greatly.",
        ]));
        set_exits(([
           "south" : TORMC+"c61",
           "north" : RSHOP+"office",
           "west" :  RSHOP+"workshop",
           "east" :  RSHOP+"fitting",
        ]));
        set_door("double doors",TORMC+"c61","south",0);
	   set_string("double doors", "open", "The %^RED%^doors%^WHITE%^ open without so much as the slightest %^BOLD%^%^BLACK%^whisper%^RESET%^.");
	   set_string("double doors", "close", "The %^RED%^doors%^WHITE%^ close solidly, without a %^BOLD%^%^BLACK%^sound%^RESET%^.");
	   set_lock_description("double doors","lock", "The lock has a knob on this side of the door that turns without need of a key.");
        set_door("carved door",RSHOP+"office","north",SHOPKEY);
	   set_open("carved door",0);
	   set_locked("carved door", 1);
	   lock_difficulty("carved door",-100, "lock");
	   set_lock_description("carved door","lock", "The lock appears quite intricate and has so many tumblers you can't readily count them.");
	   set_string("carved door", "open", "The %^RED%^door%^WHITE%^ opens without so much as the slightest %^BOLD%^%^BLACK%^whisper%^RESET%^.");
	   set_string("carved door", "close", "The %^RED%^door%^WHITE%^ closes solidly, without a %^BOLD%^%^BLACK%^sound%^RESET%^.");
        set_door("workshop door",RSHOP+"workshop","west",SHOPKEY);
	   set_open("workshop door",0);
	   set_locked("workshop door", 1);
	   lock_difficulty("workshop door",-80, "lock");
	   set_lock_description("workshop door","lock", "The lock appears quite intricate and has so many tumblers you can't readily count them.");
	   set_string("workshop door", "open", "The %^RED%^door%^WHITE%^ opens without so much as the slightest %^BOLD%^%^BLACK%^whisper%^RESET%^.");
	   set_string("workshop door", "close", "The %^RED%^door%^WHITE%^ closes solidly, without a %^BOLD%^%^BLACK%^sound%^RESET%^.");
        set_door("fitting door",RSHOP+"fitting","east",0);
 	   set_string("fitting door", "open", "The %^RED%^door%^WHITE%^ opens without so much as the slightest %^BOLD%^%^BLACK%^whisper%^RESET%^.");
	   set_string("fitting door", "close", "The %^RED%^door%^WHITE%^ closes solidly, without a %^BOLD%^%^BLACK%^sound%^RESET%^.");
        set_door_description("double doors", "%^RED%^These doors are "
"made of a rich cherrywood and are shaped so that together, they form a "
"tall, bold arch that comes to a point at the top. They are framed in "
"%^BOLD%^%^BLACK%^ornate black iron%^RESET%^%^RED%^ and have %^BOLD%^"
"%^BLACK%^stylish black iron handles%^RESET%^%^RED%^ and %^BOLD%^"
"%^BLACK%^hinges%^RESET%^%^RED%^. Inscribed on the doors with %^BOLD%^"
"scarlet ink%^RESET%^%^RED%^ in the crevices is '%^BOLD%^The Scarlet "
"Angel%^RESET%^%^RED%^', with a small %^BOLD%^red silhouette%^RESET%^"
"%^RED%^ of a female angel, with wings and arms spread and her face "
"tilted to the heavens.%^RESET%^");
        set_door_description("carved door", "%^RED%^This large door is "
"made of a rich cherrywood and is shaped in an arch, coming to a point "
"at the top. It is framed in %^BOLD%^%^BLACK%^ornate black iron"
"%^RESET%^%^RED%^, and has a stylish %^BOLD%^%^BLACK%^black iron "
"handle%^RESET%^%^RED%^ and %^BOLD%^%^BLACK%^hinges%^RESET%^%^RED%^.");
        set_door_description("workshop door", "%^RED%^This large door "
"is made of a rich cherrywood and is shaped in an arch, coming to a "
"point at the top. It is framed in %^BOLD%^%^BLACK%^ornate black "
"iron%^RESET%^%^RED%^, and has a stylish %^BOLD%^%^BLACK%^black "
"iron handle%^RESET%^%^RED%^ and %^BOLD%^%^BLACK%^hinges%^RESET%^%^RED%^.");
        set_door_description("fitting door", "%^RED%^This large door "
"is made of a rich cherrywood and is shaped in an arch, coming to a "
"point at the top. It is framed in %^BOLD%^%^BLACK%^ornate black "
"iron%^RESET%^%^RED%^, and has a stylish %^BOLD%^%^BLACK%^black "
"iron handle%^RESET%^%^RED%^ and %^BOLD%^%^BLACK%^hinges%^RESET%^%^RED%^.");
}

void init() {
   ::init();
   if(!TP->query_true_invis()) {
      tell_room((RSHOP+"office"),"%^BOLD%^%^GREEN%^A soft chime sounds.%^RESET%^\n");
      tell_room((RSHOP+"bedroom"),"%^BOLD%^%^GREEN%^A soft chime sounds.%^RESET%^\n");
      tell_room((RSHOP+"laboratory"),"%^BOLD%^%^GREEN%^A soft chime sounds.%^RESET%^\n");
      tell_room((RSHOP+"workshop"),"%^BOLD%^%^GREEN%^A soft chime sounds.%^RESET%^\n");
   }
}

void reset() {
    ::reset();
    if(!present("shop clerk"))
	new("/d/player_stores/clerks/rubicant_shop")->move(TO);
    switch(random(10)) {
	case 0: tell_room(TO, "A %^BLUE%^well-dressed nobleman%^WHITE%^ "
"of high standing, flanked by two %^BOLD%^%^BLACK%^armored bodyguards"
"%^RESET%^, slowly walks through the store.");
		break;
	case 1: tell_room(TO, "Three %^BOLD%^%^CYAN%^young human boys"
"%^RESET%^ walk into the shop and look %^YELLOW%^awestruck%^RESET%^, "
"chatting excitedly amongst themselves as they point and stare at "
"the %^BOLD%^ceiling%^RESET%^ far above.");
		break;
	case 2: tell_room(TO, "A %^RED%^young, wealthy noblewoman's"
"%^RESET%^ eyes light up as she sees a %^BOLD%^beautiful dress"
"%^RESET%^ and she motions her lady in waiting over excitedly.");
		break;
	case 3: tell_room(TO, "An older, %^BOLD%^%^BLUE%^obviously "
"rich couple%^RESET%^ wanders along the walls, admiring and discussing "
"the many %^MAGENTA%^paintings%^WHITE%^.");
		break;
	case 4: tell_room(TO, "A pair of older, %^BOLD%^%^MAGENTA%^"
"flamboyantly dressed women%^RESET%^ gossip and talk loudly amongst "
"themselves as they look over the various garments on display.");
		break;
	case 5: tell_room(TO, "A %^BOLD%^%^BLACK%^well-dressed young "
"man%^RESET%^ wanders slowly and quietly around the %^BOLD%^%^CYAN%^"
"jewelry case%^RESET%^, looking in at the displays with his hands in "
"his pockets.");
		break;
	case 6: tell_room(TO, "A %^MAGENTA%^beautiful young woman%^WHITE%^ "
"emerges from the changing area in an %^BOLD%^%^BLACK%^elegant black "
"gown%^RESET%^, catching the attention of everyone in the store as she "
"walks out of the store with her new purchase.");
		break;
	case 7: tell_room(TO, "A %^BOLD%^%^MAGENTA%^young girl in her "
"mid-teens%^RESET%^ looks around nervously at everything in the store "
"as she is led by her %^BOLD%^%^RED%^stern-looking, upper-class "
"mother%^RESET%^ through the shop.");
		break;
	case 8: tell_room(TO, "An %^BOLD%^%^GREEN%^exotically dressed "
"man%^RESET%^ that must be from overseas somewhere wanders through "
"the %^BOLD%^statues%^RESET%^, looking at the garments on display.");
		break;
	case 9: tell_room(TO, "%^BOLD%^Two young, teenage girls"
"%^RESET%^ dressed as low-ranking nobility talk excitedly amongst "
"themselves as they wander about the garments.");
		break;
	default:  break;
   }
}

string ldesc() {
    return ("%^RESET%^This shop is itself a work of art, "
"obviously designed with the wealthy and noble in mind. %^BOLD%^%^BLACK%^"
"Obsidian pillars%^RESET%^ interrupt smooth %^BOLD%^%^BLACK%^"
"gr%^RESET%^a%^BOLD%^n%^RESET%^i%^BOLD%^%^BLACK%^te "
"w%^RESET%^a%^BOLD%^l%^RESET%^l%^BOLD%^%^BLACK%^s "
"%^RESET%^at even intervals, set with %^BOLD%^%^BLACK%^black "
"sconces%^RESET%^ to provide ample lighting for the shop. "
"Between two pillars at the center of each wall is a door, and between "
"the other pillars hang large, %^MAGENTA%^exquisite paintings%^WHITE%^. "
"The ceiling is a large dome, and painted upon it is an intricate "
"artistic rendering of the forces of %^BOLD%^light%^RESET%^ "
"and %^BOLD%^%^BLACK%^darkness%^RESET%^. In the center of the "
"shop is a circular %^BOLD%^%^CYAN%^glass counter%^RESET%^ "
"displaying various kinds of jewelry with a large space in the middle, "
"dominated by a %^BOLD%^beautiful sculpture%^RESET%^ of a "
"female angel dressed in %^BOLD%^%^RED%^scarlet%^RESET%^.  "
"The only thing on the counter is a %^BOLD%^%^BLACK%^black sign%^RESET%^"
"%^WHITE%^ with %^BOLD%^%^RED%^scarlet script%^RESET%^.  "
"Encircling the counter and extending from there straight to each "
"door are paths of %^BOLD%^%^BLACK%^black marble%^RESET%^, "
"the rest of the floor covered in plush %^BOLD%^%^RED%^scarlet carpeting"
"%^RESET%^, dividing the rectangular shop into four parts.  "
"%^BOLD%^%^BLACK%^G%^RESET%^r%^BOLD%^a%^RESET%^y "
"%^BOLD%^%^BLACK%^ma%^RESET%^r%^BOLD%^b%^RESET%^"
"l%^BOLD%^%^BLACK%^e st%^RESET%^a%^BOLD%^%^BLACK%^tu"
"%^RESET%^e%^BOLD%^%^BLACK%^s%^RESET%^ of armless "
"humanoid forms are scattered about the carpet, adorned in the fine "
"clothes the place has to offer.  There is a %^YELLOW%^golden bell%^BLACK%^ affixed to the counter."
    );
}

string paintings() {
    return("There are 12 paintings in all, "
"each done in %^MAGENTA%^exquisite%^WHITE%^ and %^CYAN%^magnificent%^WHITE%^ "
"detail, and all in the same style and size. Each bears the signature of "
"%^BOLD%^%^BLACK%^Rubicant Versidious%^RESET%^%^WHITE%^ done in beautiful "
"script, and is framed in %^BOLD%^%^BLACK%^ornate black iron%^RESET%^"
"%^WHITE%^. Beginning on the left side of the north wall and going "
"clockwise, the paintings are entitled, '%^RED%^Eyes of the Magi%^WHITE%^', "
"'%^ORANGE%^Faithful to the King%^WHITE%^', '%^YELLOW%^Blessing of "
"Light%^RESET%^%^WHITE%^', '%^BOLD%^Angel of Light%^RESET%^%^WHITE%^', "
"'%^BOLD%^%^BLACK%^Angel of Darkness%^RESET%^%^WHITE%^', '%^MAGENTA%^Curse "
"of Darkness%^WHITE%^', '%^BLUE%^The First Night%^WHITE%^', '%^BOLD%^"
"%^RED%^The Last Day%^RESET%^%^WHITE%^', '%^CYAN%^Vision of the Storm"
"%^WHITE%^', '%^BOLD%^%^BLUE%^The Watcher%^RESET%^%^WHITE%^', '%^BOLD%^"
"%^CYAN%^The Seer%^RESET%^%^WHITE%^', and '%^BOLD%^%^GREEN%^Vision of the "
"Calm%^RESET%^%^WHITE%^'."
    );
}

string nwall() {
   return("This wall is the same width as the south wall opposite it, "
"with four %^BOLD%^%^BLACK%^obsidian pillars%^RESET%^ dividing it into "
"three parts. The center part has an intricately %^RED%^carved door"
"%^WHITE%^, and hung in the center of each other part is an %^MAGENTA%^"
"exquisite painting%^WHITE%^. The left one, as you face the wall, is "
"of a pair of mages in a laboratory, titled '%^RED%^Eyes of the "
"Magi%^WHITE%^', and the right is of a warrior bowing before a young "
"king, entitled, '%^ORANGE%^Faithful to the King%^WHITE%^'."
   );
}

string paint1() {
    return("%^RED%^This painting depicts "
"two magi in a %^WHITE%^laboratory%^RED%^ with many tables covered "
"in %^CYAN%^alchemical potions%^RED%^ and %^ORANGE%^scrolls%^RED%^, "
"with %^MAGENTA%^summoning circles%^RED%^ inscribed around the center "
"of the laboratory, and an %^BOLD%^%^CYAN%^ornate mirror%^RESET%^%^RED%^ "
"sitting against one of the walls. The taller of the two magi is human, "
"and is dressed in beautiful %^BOLD%^blood red mage robes%^RESET%^%^RED%^ "
"with %^BOLD%^%^BLACK%^black%^RESET%^%^RED%^ and %^BOLD%^%^WHITE%^s"
"%^RESET%^%^WHITE%^i%^BOLD%^l%^RESET%^%^WHITE%^v%^BOLD%^e%^RESET%^"
"%^WHITE%^r%^RED%^ entwined runes adorning the hems. He has a stern, "
"yet wise and caring %^ORANGE%^grandfatherly%^RED%^ look to him, and "
"he is looking at the younger magus, as if in mid conversation. The "
"shorter of the magi is facing away from you, dressed in %^BOLD%^crimson "
"colored robes%^RESET%^%^RED%^ bearing an %^BOLD%^%^BLACK%^intricate "
"insignia%^RESET%^%^RED%^ on the back. He is turned towards the taller "
"mage, his unmarred youthful cheek and pointed ears visible from the "
"mess of %^BOLD%^%^BLACK%^short black hair%^RESET%^%^RED%^ upon his "
"head, though that is all that can be seen of his features."
   );
}

string paint2() {
   return("%^RESET%^%^ORANGE%^This painting depicts the "
"court of a %^WHITE%^young human king%^ORANGE%^, who looks as though "
"he cannot be more than in his late teens, seated upon a magnificent "
"%^BOLD%^ORANGE%^je%^BLUE%^w%^ORANGE%^el%^RED%^e%^ORANGE%^d t%^GREEN%^"
"h%^ORANGE%^r%^WHITE%^o%^ORANGE%^ne%^RESET%^%^ORANGE%^. Youthful "
"%^BOLD%^blonde locks%^RESET%^%^ORANGE%^ frame his softer features, "
"not quite come into manhood, and he is dressed in %^BOLD%^%^BLACK%^"
"ceremonial armor%^RESET%^%^ORANGE%^. Surrounding him are numerous "
"advisors, dressed in the styles of human nobility in shades of "
"%^BOLD%^%^BLUE%^blue%^RESET%^%^ORANGE%^ and %^BOLD%^%^WHITE%^white"
"%^RESET%^%^ORANGE%^, talking amongst themselves. On either side "
"are %^BOLD%^%^WHITE%^well-armed guards%^RESET%^%^ORANGE%^, staring "
"resolutely forward at the man bowing before him. The man is facing "
"away from you, towards the %^WHITE%^young king%^ORANGE%^, and is a "
"giant of a an. He stands a head taller than everyone in the painting "
"and is built like a %^RED%^minotaur%^ORANGE%^, with grand rippling "
"muscles. Encasing his large frame is %^BOLD%^ornate %^CYAN%^m%^WHITE%^"
"i%^CYAN%^thril%^WHITE%^ armor%^RESET%^%^ORANGE%^, bearing the %^BOLD%^"
"%^BLACK%^spiked gauntlet%^RESET%^%^ORANGE%^ of %^BOLD%^%^WHITE%^"
"Tempus%^RESET%^%^ORANGE%^, %^BOLD%^%^RED%^God of War%^RESET%^"
"%^ORANGE%^. Held before him in his hands as he bows, as if offering "
"it to the king, is a %^BOLD%^%^WHITE%^huge gleaming sword%^RESET%^"
"%^ORANGE%^ nearly as big as the massive man holding it."
    );
}

string ewall() {
   return("This wall is the same "
"width as the west wall opposite it, with six %^BOLD%^%^BLACK%^"
"obsidian pillars%^RESET%^%^WHITE%^ dividing it into five parts. "
"The center part has a %^RED%^cherrywood door%^WHITE%^, and hung in "
"the center of each other part is an %^MAGENTA%^exquisite painting"
"%^WHITE%^. The leftmost one, as you face the wall, is a painting "
"of a solemn priest giving the last rites to the dead on a battlefield, "
"entitled '%^YELLOW%^Blessing of Light%^RESET%^%^WHITE%^.'  To its "
"right is a painting of a glorious male angel of light with a "
"blazing firebrand, entitled '%^BOLD%^Angel of Light%^RESET%^%^WHITE%^'.  "
"To the right of the door is a painting of a terrible dark female "
"angel with blades of utter darkness, entitled '%^BOLD%^%^BLACK%^Angel "
"of Darkness%^RESET%^%^WHITE%^'. The rightmost painting is of a "
"necromancer raising an army of undead on the field of battle, "
"entitled '%^MAGENTA%^Curse of Darkness%^WHITE%^'."
   );
}

string paint3() {
   return("%^GREEN%^This painting depicts a solemn man wearing "
"%^WHITE%^gray armor%^GREEN%^ encrusted with the symbols of %^BOLD%^"
"%^WHITE%^Kelemvor%^GREEN%^, %^BOLD%^%^BLACK%^Lord of the Dead"
"%^RESET%^%^GREEN%^. He is on a small hill in a field of battle "
"littered with %^CYAN%^thousands of bodies%^GREEN%^, kneeling over "
"a %^RED%^slain dwarf%^GREEN%^, giving him the last rites of the "
"dead. The %^WHITE%^gray-bearded%^GREEN%^ man is one of many priests "
"wandering through the battlefield, all solemn and respectful of "
"the dead before them. The dead themselves have looks of %^BOLD%^"
"%^CYAN%^eternal peace%^RESET%^%^GREEN%^ and %^BOLD%^%^WHITE%^"
"restfulness%^RESET%^%^GREEN%^ upon them, despite their violent deaths."
   );
}

string paint4() {
   return("%^BOLD%^%^WHITE%^This painting depicts a %^YELLOW%^"
"glorious male angel%^WHITE%^ wearing %^CYAN%^magnificent "
"m%^WHITE%^i%^CYAN%^thril armor%^WHITE%^ encrusted with %^ORANGE%^"
"golden symbols%^WHITE%^. His short blonde hair is blown back in "
"the wind, as he is flying high in the clouds with %^RESET%^"
"%^ORANGE%^magnificent feathered wings%^BOLD%^%^WHITE%^ like those "
"of an %^RESET%^%^ORANGE%^eagle%^BOLD%^%^WHITE%^. His face is proud "
"and stern, chiseled in the image of perfect masculinity. In his "
"hands is a huge %^BLACK%^firebrand%^WHITE%^, with %^RED%^deadly "
"flames%^WHITE%^ licking at its blade. He is facing to the right, "
"as if flying to meet the %^BLACK%^dark angel%^WHITE%^, in the "
"painting in that direction, in battle."
   );
}

string paint5() {
   return("%^BOLD%^%^BLACK%^This painting depicts a %^RESET%^"
"%^MAGENTA%^ terrible female angel%^BOLD%^%^BLACK%^ wearing %^RESET%^"
"%^BLUE%^gleaming black adamantium armor%^BOLD%^%^BLACK%^ encrusted "
"in %^WHITE%^silver symbols%^BLACK%^. Her long black hair is blown "
"back in the wind, as she is flying high in the clouds with %^RESET%^"
"%^ORANGE%^unsettling leathery wings%^BOLD%^%^BLACK%^ like those of "
"a bat. Her face is %^CYAN%^cold%^BLACK%^ and %^MAGENTA%^beautiful"
"%^BLACK%^, crafted in the image of perfect femininity. In her hands "
"are two blades of %^RESET%^%^BLUE%^utter darkness%^BOLD%^%^BLACK%^, "
"one of medium size and one of short size, that seem to %^RESET%^"
"%^RED%^absorb%^BOLD%^%^BLACK%^ the light around them. She is facing "
"to the left, as if flying to meet the %^WHITE%^light angel%^BLACK%^, "
"in the painting in that direction, in battle."
   );
}

string paint6() {
   return("%^MAGENTA%^This painting "
"depicts a %^BOLD%^%^BLACK%^dark-robed necromancer%^RESET%^%^MAGENTA%^ "
"with %^BOLD%^%^WHITE%^s%^RESET%^%^WHITE%^i%^BOLD%^l%^RESET%^%^WHITE%^"
"v%^BOLD%^e%^RESET%^%^WHITE%^r%^MAGENTA%^ arcane runes lining the hems "
"of his robes, standing with his arms raised to the air, a %^BOLD%^"
"%^BLACK%^gnarled black staff%^RESET%^%^MAGENTA%^ in his hands. He is "
"in the middle of chanting, and %^BOLD%^%^WHITE%^silvery wisps%^RESET%^"
"%^MAGENTA%^ of %^BOLD%^%^BLACK%^dark magic%^RESET%^%^MAGENTA%^ line "
"the air, enchanting the bodies of the dead and forcing them to do "
"his bidding as %^WHITE%^undead%^MAGENTA%^. His face is hidden in the "
"%^BOLD%^%^BLACK%^shadows%^RESET%^%^MAGENTA%^ of his hood, allowing "
"only the glitter of his %^BOLD%^%^WHITE%^menacing eyes%^RESET%^"
"%^MAGENTA%^ to be seen. The %^WHITE%^undead warriors%^MAGENTA%^, "
"garbed as they were in life, have grim looks of %^BOLD%^%^BLACK%^"
"determination%^RESET%^%^MAGENTA%^ and %^RED%^tireless vigilance"
"%^MAGENTA%^ upon their faces as they look obediently to their master."
   );
}

string swall() {
   return("This wall is the same "
"width as the north wall opposite it, with four %^BOLD%^%^BLACK%^"
"obsidian pillars%^RESET%^%^WHITE%^ dividing it into three parts. "
"The center part has a tall set of %^RED%^double doors%^WHITE%^, and "
"hung in the center of each other part is an %^MAGENTA%^exquisite "
"painting%^WHITE%^. The left one, as you face the wall, is of a "
"tavern scene, with a halfling doing a backflip on the stage, "
"entitled '%^BLUE%^The First Night%^WHITE%^', the right of a "
"beautiful elven woman and stern elven man, entitled '%^BOLD%^"
"%^RED%^The Last Day%^RESET%^%^WHITE%^'."
   );
}

string paint7() {
   return("%^BLUE%^This painting "
"depicts a tavern scene at night. The tavern is packed and busy with "
"all sorts of people, mostly humans, and is decorated in the motif "
"of a %^WHITE%^white wyvern%^BLUE%^. The crowd is eating and drinking "
"merrily, and the detail on each person in the crowd is amazing. On "
"the stage is a %^GREEN%^halfling%^BLUE%^ in the middle of a backflip, "
"and most of the eyes of the crowd are on him. In the center of the "
"piece is a table with many young human men dressed in %^BOLD%^"
"%^RED%^crimson robes%^RESET%^%^BLUE%^ with an %^BOLD%^%^BLACK%^"
"intricate insignia%^RESET%^%^BLUE%^, eating and drinking, several "
"of whom have %^MAGENTA%^beautiful women%^BLUE%^ in their laps. "
"However, one is different, and is paying no attention to the "
"%^GREEN%^halfling%^BLUE%^. He appears to be a %^WHITE%^half-elf"
"%^BLUE%^, dressed similarly to the others, but is looking at a "
"%^BOLD%^%^WHITE%^beautiful serving maid%^RESET%^%^BLUE%^ who is "
"handing him a drink. She is dressed %^ORANGE%^plainly%^BLUE%^, "
"but is well-formed and has amazingly lucid eyes the %^ORANGE%^"
"sh%^BOLD%^a%^RESET%^%^ORANGE%^de of h%^BOLD%^o%^RESET%^%^ORANGE%^"
"ney%^BLUE%^, and is looking back at him with a %^BOLD%^%^MAGENTA%^"
"flirtatious smile%^RESET%^%^BLUE%^."
   );
}

string paint8() {
   return("%^BOLD%^%^RED%^This painting depicts an elven "
"woman and man standing in a cold castle hallway on a bright morning. "
" %^YELLOW%^Light%^RED%^ falls in through the windows, illuminating the "
"%^RESET%^%^RED%^plush carpet%^BOLD%^ beneath their feet.  The woman "
"is %^MAGENTA%^beautiful%^RED%^ in the fragile way of elves and is "
"dressed in the fine noble garb of humans, in shades of %^BOLD%^"
"%^WHITE%^s%^RESET%^%^WHITE%^i%^BOLD%^l%^RESET%^%^WHITE%^v%^BOLD%^"
"e%^RESET%^%^WHITE%^r%^RED%^, %^RESET%^%^RED%^deep red%^BOLD%^, "
"and %^BLACK%^black%^RED%^. Her eyes are turned towards the window, "
"%^CYAN%^tears%^RED%^ running down her %^RESET%^%^WHITE%^pale cheeks"
"%^BOLD%^%^RED%^. The man shares many of her features and appears "
"to be about the same age, suggesting a close blood relation.  He is "
"dressed in %^RESET%^%^RED%^in%^ORANGE%^tr%^GREEN%^ic%^ORANGE%^at"
"%^RED%^e f%^ORANGE%^al%^RED%^l%^BOLD%^ colors done fancifully in "
"the elven style, looking down at the ground as his hand clasps the "
"woman's on her shoulder in a consoling manner."
   );
}

string wwall() {
   return("This wall is the same "
"width as the east wall opposite it, with six %^BOLD%^%^BLACK%^"
"obsidian pillars%^RESET%^%^WHITE%^ dividing it into five parts.  "
"The center part has a %^RED%^cherrywood door%^WHITE%^, and hung "
"in the center of each other part is an %^MAGENTA%^exquisite "
"painting%^WHITE%^. The leftmost one, as you face the wall, is of "
"a young man garbed in chain-draped stormrobes, entitled '%^CYAN%^"
"Vision of the Storm%^WHITE%^'. To its right is a painting of a "
"black-robed figure before a mirror, entitled '%^BOLD%^%^BLUE%^The "
"Watcher%^RESET%^%^WHITE%^.' To the right of the door is a "
"painting of a beautiful elven woman gazing into an orb, entitled "
"'%^BOLD%^%^CYAN%^The Seer%^RESET%^%^WHITE%^.' The rightmost "
"painting is of a young man garbed in white, entitled '%^GREEN%^"
"Vision of the Calm%^WHITE%^.'"
   );
}

string paint9() {
   return("%^CYAN%^This painting depicts a young man "
"of half-elven, half-human heritage standing on the edge of a "
"%^BOLD%^%^BLACK%^rocky cliff coastline%^RESET%^%^CYAN%^ that juts "
"out towards the ocean. The coastline is staggeringly beautiful, "
"rising about 50 feet above the %^BOLD%^stormy ocean waters"
"%^RESET%^%^CYAN%^ below. The rocks mix with sand until it becomes "
"only %^WHITE%^sandy beach%^CYAN%^ as you look further inland. The "
"%^ORANGE%^sun%^CYAN%^ in the distance is setting behind the horizon "
"to the west, and to the east the winds of a fierce storm drive the "
"%^BOLD%^waves of the ocean%^RESET%^%^CYAN%^ crashing against the "
"rocks below. The %^BOLD%^%^BLACK%^dark, stormy clouds%^RESET%^"
"%^CYAN%^ and %^YELLOW%^flashing lightning%^RESET%^%^CYAN%^ are "
"reflected in the %^BOLD%^chain-draped stormrobes%^RESET%^%^CYAN%^ "
"the man wears, blowing in winds of their own. His face is marred "
"by a %^RED%^deep scar%^CYAN%^, and his %^BOLD%^%^BLACK%^black hair"
"%^RESET%^%^CYAN%^ is chaotic and juts every which way. His %^WHITE%^"
"gray eyes%^CYAN%^ are fixated upon a %^MAGENTA%^painting%^CYAN%^ "
"sitting on an easel, which he is currently working on, with a "
"%^ORANGE%^paintbru%^BOLD%^%^BLACK%^sh%^RESET%^%^CYAN%^ in one hand "
"and an %^ORANGE%^oval piece of wood%^CYAN%^ with dabs and mixtures "
"of %^MAGENTA%^p%^ORANGE%^a%^RED%^i%^BLUE%^n%^BOLD%^%^BLACK%^t"
"%^RESET%^%^CYAN%^ upon it in the other."
   );
}

string paint10() {
   return("%^BOLD%^%^BLUE%^This painting depicts a "
"human man in intense, unadorned %^BLACK%^black mage robes%^BLUE%^ "
"that look to be made of velvet. The man's build is tall and wiry, "
"but it is hard to tell much more because the %^BLACK%^hood of his "
"robes%^BLUE%^ is drawn over his head, and he is looking away from "
"you, towards a %^GREEN%^green, glowing mirror%^BLUE%^. He appears "
"to be in some sort of %^RESET%^%^WHITE%^laboratory%^BOLD%^%^BLUE%^,"
" but it is hard to tell because the lighting in the area is very dark. "
"The mirror is %^GREEN%^crackling green with energy%^BLUE%^, as if an "
"%^BLACK%^arcane spell%^BLUE%^ had just been cast upon it."
   );
}

string paint11() {
   return("%^BOLD%^%^CYAN%^This painting depicts a "
"beautiful elven woman who seems to be advancing in age, dressed in "
"the %^WHITE%^silver and white traveling robes%^CYAN%^ of a priestess. "
"She seems to be in some sort of study, human in design, seated in "
"a simple %^RESET%^%^ORANGE%^wooden chair%^BOLD%^%^CYAN%^ with a "
"simple %^RESET%^%^ORANGE%^wooden pedestal%^BOLD%^%^CYAN%^ in front "
"of her. She is focusing intently on a %^RESET%^%^CYAN%^large crystal "
"orb%^BOLD%^ on top of the %^RESET%^%^ORANGE%^pedestal%^BOLD%^%^CYAN%^, "
"and her hands are waving over it as if casting a spell. The orb "
"itself has just flared into a %^BLUE%^soft blue light%^CYAN%^, "
"crackling with %^WHITE%^divine energy%^CYAN%^."
   );
}

string paint12() {
   return("%^BOLD%^%^GREEN%^"
"This painting depicts a young man of half-elven, half-human "
"heritage lounging in the midst of a %^RESET%^%^GREEN%^luscious "
"botanical garden%^BOLD%^. He is sitting on a %^BLACK%^large boulder"
"%^GREEN%^ beside a %^CYAN%^calm lake%^GREEN%^ that stretches into "
"the distance and is framed by a %^YELLOW%^beautiful sunrise%^GREEN%^ "
"coming over the tips of magnificent mountain peaks. His face is "
"rather plain, but his %^RESET%^%^WHITE%^clean cut%^BOLD%^%^GREEN%^ "
"image gives him a dignified look for his age, which can be no more "
"than 25 or so. His %^RESET%^%^WHITE%^gray eyes%^BOLD%^%^GREEN%^ look "
"peacefully towards a %^WHITE%^white rose%^GREEN%^ in the %^RESET%^"
"%^GREEN%^garden%^BOLD%^, which matches in hue the unadorned, %^WHITE%^"
"flowing white robes%^GREEN%^ that he wears."
   );
}

string ceiling() {
   return("The ceiling "
"is a towering dome that stretches to the corners of the walls, "
"painstakingly painted in an %^MAGENTA%^impressive mural%^WHITE%^ "
"that stretches the length and width of the dome. The rendering has "
"been done as a bird's eye view of two %^RED%^sprawling armies%^WHITE%^ "
"are charging towards one another, so when you look up, it looks as "
"if you're looking down into another world. The armies are done in "
"intricate detail, with each individual soldier being completely "
"different from another. The %^BOLD%^armies of light%^RESET%^%^WHITE%^ "
"are clad all in %^BOLD%^glittering white%^RESET%^%^WHITE%^ and "
"%^BOLD%^silver%^RESET%^%^WHITE%^ and are led by a %^YELLOW%^glorious "
"male angel%^RESET%^%^WHITE%^ wielding a %^BOLD%^%^RED%^giant flaming "
"firebrand%^RESET%^%^WHITE%^. The %^BOLD%^%^BLACK%^armies of darkness"
"%^RESET%^%^WHITE%^ are clad in %^BOLD%^%^BLACK%^gleaming black"
"%^RESET%^%^WHITE%^ and are led by a %^MAGENTA%^terrible female angel"
"%^WHITE%^ wielding a pair of %^BOLD%^%^BLACK%^utterly black blades%^RESET%^."
   );
}

string display() {
   return("The circular counter is made in two parts. The bottom half "
"has been made of %^BOLD%^%^BLACK%^gr%^RESET%^%^WHITE%^a%^BOLD%^n"
"%^RESET%^%^WHITE%^i%^BOLD%^%^BLACK%^te%^RESET%^%^WHITE%^, while the "
"top half consists of %^BOLD%^%^CYAN%^glass display cases%^RESET%^"
"%^WHITE%^, showing off all the jewelry the shop has for sale. The "
"counter encircles the statue of the %^BOLD%^scarlet angel%^RESET%^"
"%^WHITE%^, with one opening in the counter directly facing the "
"%^RED%^carved door%^WHITE%^, and is encircled by a %^BOLD%^"
"%^BLACK%^black marble path%^RESET%^%^WHITE%^ around the perimeter."
   );
}

string angel() {
   return("%^BOLD%^"
"%^WHITE%^The statue in the middle of the shop has been masterfully crafted "
"into a %^RESET%^%^MAGENTA%^beautiful female angel%^BOLD%^%^WHITE%^ dressed "
"in %^RED%^scarlet%^WHITE%^. She is the image of %^YELLOW%^perfection%^WHITE%^, "
"every one of her features absolutely perfect and symmetrical. Her arms are "
"raised towards the %^CYAN%^heavens%^WHITE%^ above, her alabaster wings spread "
"wide, though not as if in flight. Her legs are together, with one knee "
"slightly bent as she stands on some marble left unworked beneath her "
"feet. Her noble visage is tilted towards the %^CYAN%^heavens%^WHITE%^ "
"with her mouth open in a %^BLACK%^silent cry%^WHITE%^. Tumbling down "
"about halfway down her back is her %^RED%^wavy scarlet hair%^WHITE%^, "
"which has been somehow colored differently than the rest of her.  "
"%^RED%^Tattered scarlet robes%^WHITE%^ adorn her, fashioned with similar "
"process as her hair, though they cover barely enough to be modest and "
"little more. They look as if rent by the %^BLACK%^slices of blades%^WHITE%^,"
" though she is unmarred and pristine. The most striking thing about the "
"statue, however, are her eyes. They are the most beautiful %^RESET%^"
"%^ORANGE%^sh%^BOLD%^a%^RESET%^%^ORANGE%^de of h%^BOLD%^o%^RESET%^"
"%^ORANGE%^ney%^BOLD%^%^WHITE%^ and look enchantingly lifelike."
   );
}

string statues() {
   return("The many statues of the shop "
"have been made of %^BOLD%^%^BLACK%^g%^RESET%^%^WHITE%^r%^BOLD%^a%^RESET%^"
"%^WHITE%^y %^BOLD%^%^BLACK%^ma%^RESET%^%^WHITE%^r%^BOLD%^b%^RESET%^"
"%^WHITE%^l%^BOLD%^%^BLACK%^e%^RESET%^%^WHITE%^. Each is carved into a "
"%^CYAN%^beautiful, unique likeness%^WHITE%^ of one of the many races of "
"the realms, allowing customers to see what the clothes on the statues "
"will look like when worn."
   );
}
