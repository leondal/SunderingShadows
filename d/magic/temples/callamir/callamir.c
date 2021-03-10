//Temple of Callamir - created by Nienne 4/18
//code updated and allies/enemies added by ~Circe~ 10/5/19
#include <std.h>
inherit "/std/temple";

void create(){
   ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_light(2);
   set_indoors(1);
   set_temple("callamir");
   set_name("Temple of Callamir");
   set_short("%^BOLD%^%^CYAN%^Temple of Callamir%^RESET%^");
   set_long("%^BOLD%^%^CYAN%^Temple of Callamir%^RESET%^\n%^BOLD%^%^WHITE%^A vast field opens here, sheltered by the %^RESET%^%^GREEN%^foothills %^BOLD%^%^WHITE%^of the Echoes Mountains to the north.  Brilliant %^YELLOW%^c%^GREEN%^o%^CYAN%^l%^BLUE%^o%^MAGENTA%^r%^RED%^s %^BOLD%^%^WHITE%^dance across a sea of verdant grass, in the form of tents and people and pennants that flutter gaily in the wind.  The area seems to be in a constant state of motion, both day and night.  Distantly, archers pit their skills one against another, even as closer by, dancers twirl about each other with their bells %^YELLOW%^chiming %^BOLD%^%^WHITE%^to the cheerful music that accompanies their steps.  Beneath the shelter of another bright canopy, visitors both large and small are engrossed in games of %^BOLD%^%^CYAN%^chance%^BOLD%^%^WHITE%^, while others simply watch or shout encouragement.  At the centre of the field stands the most permanent of the structures, a simple half-open building that seems to welcome a regular flow of patrons.  Its %^RESET%^%^ORANGE%^wooden walls %^BOLD%^%^WHITE%^permit a number of entryways, each draped with whispy lengths of %^BOLD%^%^CYAN%^a%^RESET%^%^CYAN%^z%^BOLD%^%^CYAN%^u%^RESET%^%^CYAN%^r%^BOLD%^%^CYAN%^e %^BOLD%^%^WHITE%^silk and tiny carved sparrows.  At its heart lies a small altar, scattered with trinkets and tokens of %^RESET%^%^GREEN%^l%^BOLD%^%^GREEN%^u%^RESET%^%^GREEN%^ck%^BOLD%^%^WHITE%^.  Carefully placed glass panels give the building a bright and cheerful aspect, and during the day cast gleaming light across the %^BOLD%^%^BLACK%^s%^RESET%^i%^BOLD%^%^WHITE%^l%^RESET%^v%^BOLD%^%^WHITE%^e%^RESET%^r%^BOLD%^%^BLACK%^y %^BOLD%^%^WHITE%^letters of the Trickster's charge.%^RESET%^");
   set_smell("default","The fresh air carries an occasional whiff of incense and pipe-smoke.");
   set_listen("default","Shouts and laughter intermittently punctuate the constant murmur of sound.");
   set_exits(([
      "out": "/d/shadow/room/meadows/pond"
   ]));
}

void init(){
   ::init();
   add_action("read_charge","read");
}

int read_charge(string str){
   if(!str || str != "charge") return __Read_me(str);
   write(
@CHARGE
%^BOLD%^Callamir charges his followers with this message:%^RESET%^%^CYAN%^
Be bold, and live each day to its fullest. Be flexible, for each day will bring new and unknown challenges. Be your own master, so that none may turn you away from your true destiny. Trust to your own skill, and with a touch of luck you can achieve almost anything. Do not fear taking chances; beyond a calculated risk is always the potential for a greater reward. Strive always towards your own goals, for without them you are as a rudderless ship, left to drift into the grasp of ill fate.

%^RESET%^---

%^BOLD%^Callamir has developed the following relationships:
%^RESET%^%^CYAN%^Allies: %^RESET%^Jarmila
%^CYAN%^Enemies: %^RESET%^%^The Faceless One, Lord Shadow

%^CYAN%^*NOTE:%^WHITE%^ Being an ally or enemy does not necessarily mean you must aid or kill on sight. Determine the best course of action for your character based on your character's beliefs, the other individual(s) in question, and past actions/interactions with the individual(s) and/or their faith.
CHARGE
   );
   return 1;
}