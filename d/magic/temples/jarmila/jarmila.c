//Temple of Jarmila - created by Nienne 1/18
//updated by ~Circe~ 10/5/19 to include allies and enemies
#include <std.h>
inherit "/std/temple";

void create() {
   ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_light(2);
   set_indoors(1);
   set_temple("jarmila");
   set_name("Temple of Jarmila");
   set_short("%^YELLOW%^Temple of Jarmila%^RESET%^");
   set_long("%^YELLOW%^Temple of Jarmila%^RESET%^\n%^BOLD%^%^WHITE%^%^A small but beautiful shrine stands here, honoring Jarmila, the champion of Antioch.  %^RESET%^Pristine white marble columns %^BOLD%^%^WHITE%^rise to all sides, spaced in an orderly and symmetrical fashion.  From them hang billowing drapes in all the %^YELLOW%^c%^RESET%^%^ORANGE%^o%^RED%^l%^BOLD%^%^RED%^o%^BOLD%^%^MAGENTA%^r%^RESET%^%^MAGENTA%^s %^BOLD%^%^WHITE%^of sunrise, brightened by the natural light that filters down from the carefully-placed %^BOLD%^%^CYAN%^skylights %^BOLD%^%^WHITE%^above.  They serve as a vivid border for the clear aisleway that leads towards the rear dais, upon which stands a %^RESET%^solid marble altar%^BOLD%^%^WHITE%^.  Across it lies a snow-white silken cloth hemmed in %^YELLOW%^go%^RESET%^%^ORANGE%^ld%^YELLOW%^en %^BOLD%^%^WHITE%^thread, and behind it upon the wall has been placed a %^YELLOW%^go%^RESET%^%^ORANGE%^ld%^YELLOW%^en %^BOLD%^%^WHITE%^shield emblazoned with the %^RESET%^%^RED%^c%^BOLD%^%^RED%^ri%^RESET%^%^RED%^m%^BOLD%^%^RED%^so%^RESET%^%^RED%^n r%^BOLD%^%^RED%^os%^RESET%^%^RED%^e %^BOLD%^%^WHITE%^of Jarmila.  Beneath it, a shining plaque details her charge to the faithful.  Open access leads out upon the %^RESET%^%^GREEN%^temple ga%^BOLD%^%^GREEN%^r%^RESET%^%^GREEN%^dens %^BOLD%^%^WHITE%^to both left and right, as well as via the main entry itself, allowing fresh air to carry in the sweet scent of flowers.%^RESET%^");
   set_smell("default","The sweet smell of flowers fills the air.");
   set_listen("default","Gentle music drifts from somewhere in the temple.");
   set_exits(([
      "out": "/d/magic/temples/jarmila/jarmilaentry"
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
%^BOLD%^Jarmila charges her followers with this message:%^RESET%^%^CYAN%^
Seek always to better both yourself, and the world around you. Cultivate the light wherever it may take root, for it is where joy and love spring forth that life's true purpose is fulfilled. Nourish beauty in its many forms, and let it thrive and brighten the lives of all it touches. It is your sacred calling to foster new growth and renewal across the lands, and to protect it from those who would do it harm. Be ever alert against darkness and corruption, and do not hesitate to strike them down before they can foster rot in the hearts of mortals.

%^RESET%^---

%^BOLD%^Jarmila has developed the following relationships:
%^RESET%^%^CYAN%^Allies: %^RESET%^Callamir, Kreysneothosies, Lysara
%^CYAN%^Enemies: %^RESET%^%^Lord Shadow, Nilith, The Faceless One

%^CYAN%^*NOTE:%^WHITE%^ Being an ally or enemy does not necessarily mean you must aid or kill on sight. Determine the best course of action for your character based on your character's beliefs, the other individual(s) in question, and past actions/interactions with the individual(s) and/or their faith.
CHARGE
   );
   return 1;
}