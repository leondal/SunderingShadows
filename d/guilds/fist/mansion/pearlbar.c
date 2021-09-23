#include <std.h>
//add action for a musician to begin playing?  Add a minstrel randomly?
//catch_tell some of the music & send it to the dining room?

inherit VAULT;

void create() {
    ::create();
    set_property("light",2);
    set_property("indoors",1);
    set_property("no sticks",1);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_short("The mansion's music room");
    set_long("%^RESET%^%^CRST%^%^C117%^This room spreads out before you in a spirited infusion of %^C098%^a%^C104%^q%^C110%^u%^C116%^a%^C122%^t%^C098%^i%^C104%^c %^C110%^h%^C116%^u%^C122%^e%^C098%^s%^C117%^ and %^C158%^a%^C152%^m%^C146%^b%^C158%^i%^C152%^e%^C146%^n%^C158%^t %^C152%^l%^C146%^i%^C146%^g%^C158%^h%^C152%^t%^C146%^i%^C158%^n%^C152%^g%^RESET%^%^C117%^. The far wall features a %^C144%^marvelous stage%^C117%^ that sprawls itself wide, dominating the space. This wonder is flanked by stairways that lead up to a looming %^C144%^walkway%^C117%^, which bridges over the stage. Here, a massive marvel of a %^C192%^r%^C228%^e%^C222%^e%^C216%^f %^C192%^t%^C228%^a%^C222%^n%^C216%^k%^C117%^ casts a %^C045%^s%^C051%^o%^C087%^f%^C045%^t %^C051%^b%^C087%^l%^C045%^u%^C087%^e %^C045%^g%^C051%^l%^C087%^o%^C045%^w%^C117%^ over the room. In front of the stage, velvety %^C093%^p%^C104%^lu%^C093%^s%^C104%^h %^C093%^c%^C104%^h%^C093%^air%^C104%^s%^C117%^ are gathered around %^C117%^gleaming %^C245%^tables%^C117%^. Lavish %^C073%^sof%^C067%^a%^C073%^s %^C117%^and luscious %^C073%^a%^C067%^rm%^C073%^chai%^C067%^r%^C073%^s%^C117%^ are tucked away in nooks for more intimate gatherings. A %^C144%^grand bar%^RESET%^%^C117%^ consumes a side of the room, curving outward in lazy waves before meandering its way back to the wall. Above, the ceiling is draped in %^C098%^c%^C104%^o%^C110%^l%^C116%^o%^C122%^r%^C098%^f%^C104%^u%^C110%^l %^C116%^s%^C122%^c%^C098%^a%^C104%^r%^C110%^v%^C116%^e%^C122%^s%^C117%^ and %^C158%^p%^C152%^u%^C146%^l%^C158%^s%^C152%^a%^C146%^t%^C158%^i%^C152%^n%^C146%^g %^C146%^l%^C158%^i%^C152%^g%^C146%^h%^C158%^t%^C152%^s%^RESET%^%^C117%^, as if you were looking up from beneath the waves of the sea. %^C117%^A chandelier made from %^C180%^fl%^C186%^o%^C180%^wer%^C186%^s%^C117%^ and %^C120%^s%^C114%^e%^C120%^agras%^C114%^se%^C120%^s%^C117%^ hangs beautifully overhead.%^CRST%^");
    set_listen("default","You hear snippets of conversation between "
       "songs and stories.");
    set_smell("default","Delicious smells drift in from the dining room.");
    set_items(([
      "stage" : "%^RESET%^%^CRST%^%^C144%^Three shallow steps lead up to the dark %^C059%^i%^C066%^r%^C073%^i%^C080%^d%^C087%^e%^C059%^s%^C066%^c%^C073%^e%^C080%^n%^C087%^t %^C059%^s%^C066%^u%^C073%^r%^C080%^f%^C087%^a%^C059%^c%^C066%^e%^C144%^ of the stage. Draped behind the stage are silken curtains in myriad shades of %^C021%^blue%^C144%^, %^C034%^green%^C144%^ and %^C092%^purple%^C144%^. Looming over the stage is a grand wooden walkway, carved with slender %^C138%^tentacles%^C144%^ that wrap around the dark wood rails. A %^C008%^grand piano%^C144%^ sits on the stage, ready to be played.%^CRST%^",
      ({"curtains","curtain"}) : "%^RESET%^%^CRST%^%^C231%^Airy and light, these curtains create a %^C098%^c%^C104%^o%^C110%^l%^C116%^o%^C122%^r%^C098%^f%^C104%^u%^C110%^l %^C098%^b%^C104%^a%^C110%^c%^C116%^k%^C122%^d%^C098%^r%^C104%^o%^C110%^p%^C231%^ for the stage. They sway in the slightest of breezes.%^CRST%^",
      "piano" : "%^RESET%^%^CRST%^%^C008%^This is a standard piano, its black surface polished to a shine. It is well cared for, and plays beautifully. Rumors about that this piano might be haunted as it can be heard playing itself when nobody else is occupying the stage.%^CRST%^", 
      "aquarium" : "%^RESET%^%^CRST%^%^C038%^The entire far wall is taken up by a majestic %^C190%^r%^C226%^e%^C220%^e%^C214%^f %^C021%^aq%^C027%^ua%^C033%^r%^C021%^iu%^C027%^m%^C038%^. Several columns of %^C136%^p%^C130%^oc%^C124%^k%^C130%^ed %^C136%^r%^C130%^oc%^C124%^k %^RESET%^%^C038%^stand like crumbling pillars, coated by the gently waving tendrils of living %^C219%^co%^C213%^r%^C219%^a%^C213%^l %^C038%^and %^C175%^se%^C181%^a a%^C187%^ne%^C175%^mo%^C181%^ne%^C187%^s%^C038%^. Schools of %^C021%^blue devils %^C038%^dart between the rocky shoals amid the subdued lighting filtering down through the water. They weave amid the other denizens - the %^C246%^dom%^C255%^i%^C246%^n%^C255%^o %^C246%^dams%^C255%^e%^C246%^lfi%^C255%^s%^C246%^h%^RESET%^%^C038%^, the %^C228%^yel%^C226%^lo%^C228%^w %^C038%^and %^C021%^blue ta%^C226%^n%^C228%^gs%^C038%^, and even a colorful %^C255%^c%^C246%^l%^C255%^o%^C246%^w%^C255%^n %^C098%^tr%^C104%^ig%^C110%^ge%^C098%^rf%^C104%^is%^C110%^h%^C038%^.%^RESET%^%^CRST%^",
      "menu" : "%^RESET%^%^CRST%^You could probably read the menu for a list of drinks served here.",
      ({"tables","chairs"}) : "%^RESET%^%^CRST%^%^C153%^These plush velvet-covered side chairs come in shades of bloth %^C026%^blue%^C153%^ and %^C098%^purple%^C153%^. The chairs are scattered about without any attempt at matching color schemes at a single table. The tables are big and small, some round, some square shaped. Their surfaces are %^C008%^dark%^C153%^ and %^C008%^gleaming%^C153%^, reflecting the captivating lights of the room.%^CRST%^",
      ({"stairways","stairway","walkway","rails"}) : "%^RESET%^%^CRST%^%^C144%^This walkway allows patrons to get a better look at the %^C033%^aquarium%^C144%^ as well as look down over the stage. There are even a few stools here for those who wish to linger. This grand addition to the room is carved from dark wood. %^C138%^Tentacles%^C144%^ climb up the balusters and grasp onto the handrail, adding interest to this fine piece of craftsmanship.%^CRST%^",
      ({"nooks","armchairs","sofas"}) : "%^RESET%^%^CRST%^%^C153%^Ornate but comfortable furniture encircles low gleaming tables. Their velvety surfaces match the %^C026%^r%^C098%^ic%^C026%^h t%^C098%^one%^C026%^s%^C153%^ of the side chairs scattered around the tables in the main bar area. The surfaces of the tables are %^C008%^dark%^C153%^ and %^C008%^gleaming%^C153%^, reflecting the hazy lights of the room. These nooks sit apart from the noise and general rowdiness of the bar for those who wish for some privacy.%^CRST%^",
      "walls" : "%^RESET%^%^CRST%^%^C153%^The walls are watercolor whorls of %^C033%^blues%^C153%^ and %^C035%^greens%^C153%^. The colors mingle together in a way that suggests undersea %^C044%^foliage%^C153%^ and %^C044%^flowers%^C153%^, %^C192%^light%^C153%^ and %^C192%^life%^C153%^. The abstract nature of the murals makes it impossible to ever discern exactly what you are looking at, however.%^CRST%^",
      ({"bar","stools","bottles"}) : "%^RESET%^%^CRST%^%^C144%^This bar is grandly appointed, its heavy, %^C008%^dark surface%^C144%^ polished to a gleam. Overhead, a glass rack is supported by a wooden grid attached to wooden pillars interspersed along the curving length of the bar. The pillars are carved into the shape of topless %^C086%^m%^C080%^e%^C086%^rmai%^C080%^d%^C086%^s%^C144%^, proudly displaying their voluptuous chests. Behind the bar, an impressive collection of %^C080%^bottles%^C144%^ comes in every shape, size and color. Stools line the bar, their plush velvety surfaces proving to be a rather comfortable place to relax.%^CRST%^",
      "floor" : "%^RESET%^%^CRST%^%^C144%^The marble floor is the color of light sand, shot through with black. Because it is so pale in color, the floor easily picks up and reflects the room's %^C158%^a%^C152%^m%^C146%^b%^C158%^i%^C152%^e%^C146%^n%^C158%^t %^C152%^l%^C146%^i%^C146%^g%^C158%^h%^C152%^t%^C146%^i%^C158%^n%^C152%^g%^C144%^.%^CRST%^",
      ({"mermaids","pillars"}) : "%^RESET%^%^CRST%^%^C086%^Mermaids, their beautifully carved bodies put on full, alluring display, grace each magnificent pillar. Striking various poses, the one thing these lovely ladies have in common are the %^C231%^p%^C195%^e%^C231%^a%^C195%^r%^C231%^l %^C195%^n%^C231%^e%^C195%^c%^C231%^k%^C195%^l%^C231%^a%^C195%^c%^C231%^e%^C195%^s%^C086%^ draped around their bodies.%^CRST%^",
	  ({"ceiling","scarves","lights","chandelier","flowers","seagrasses"}) : "%^RESET%^%^CRST%^%^C195%^Airy, draping %^C116%^s%^C122%^c%^C098%^a%^C104%^r%^C110%^v%^C116%^e%^C122%^s%^C195%^ create waves upon the ceiling, their %^C110%^blue%^C195%^ and %^C122%^green%^C195%^ tones matching the colors of the sea. Somewhere above, %^C229%^golden light%^C195%^ slices through the scarves, like sunlight penetrating the depths of the ocean. Cascading down from the center of the ceiling is this large upside-down %^C086%^s%^C223%^e%^RESET%^%^C086%^a gar%^C223%^d%^C086%^en%^C195%^. Bright colors mingle with wispy foliage creating the illusion of a wonderfully decadent underwater oasis. %^C183%^Lights %^C195%^twinkle from within the depths of the display.%^CRST%^",
  ]));
    set_exits(([
       "dining" : "/d/guilds/fist/mansion/dining",
       "northeast" : "/d/guilds/fist/mansion/ghall",
       "library" : "/d/guilds/fist/mansion/library",
    ] ));
//   set_door("door","/d/guilds/fist/mansion/ghall","hall");
   set_door("pocket door","/d/guilds/fist/mansion/dining","dining");
   set_door_description("pocket door","This is actually a pair of doors that "
     "suspend from rollers in tracks in the ceiling rather than hanging on "
     "hinges to swing as most do.  The walls to each side "
     "are hollow and the doors simply slide inside them to open.");
  set_string("pocket door","open","The pocket doors slide smoothly aside into "
     "the spaces inside the walls.");
  set_string("pocket door","close","The pocket doors slide smoothly out from "
     "the space inside the walls to close the room off from the next.");
}
