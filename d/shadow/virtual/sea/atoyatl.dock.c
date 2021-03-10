#include <std.h>
#include <objects.h>
#include "/realms/lujke/tecqumin/tecqumin.h"

inherit DOCK;

int is_virtual() { return 1; }
int is_water() { return 1; }
int is_dock() { return 1; }
void create() {
    ::create();
    set_property("light",2);
    set_property("indoors",0);
    set_terrain(BARREN);
    set_travel(SLICK_FLOOR);
    set_short("Wharf in a small harbor.");
    set_long("A small %^MAGENTA%^quay%^RESET%^ lies sheltered in a hidden"
      +" %^ORANGE%^cove%^RESET%^. Boats and small ships can be docked here,"
      +" and the platform leads up onto a %^ORANGE%^p%^BOLD%^%^WHITE%^e"
      +"%^RESET%^%^ORANGE%^b%^CYAN%^b%^RESET%^l%^ORANGE%^e"
      +" b%^RESET%^e%^ORANGE%^a%^CYAN%^c%^ORANGE%^h%^RESET%^. A short walk"
      +"  up the beach, a %^ORANGE%^trail%^RESET%^ leads west through the"
      +" dense %^BOLD%^%^GREEN%^j%^RESET%^%^GREEN%^u%^BOLD%^ng%^RESET%^"
      +"%^GREEN%^l%^BOLD%^e %^RESET%^which crowds up to the edge of the"
      +" beach. The %^BOLD%^%^BLUE%^sea%^RESET%^ is not too rough here, as"
      +" the natural harbour breaks up the surf. The %^CYAN%^waves%^RESET%^"
      +" keep rolling in, all the same, and the %^BOLD%^%^BLUE%^water"
      +" %^RESET%^%^CYAN%^gl%^BOLD%^%^WHITE%^i%^CYAN%^n%^RESET%^%^CYAN%^ts"
      +" %^RESET%^invitingly in the %^BOLD%^%^YELLOW%^s%^WHITE%^u"
      +"%^YELLOW%^nl%^WHITE%^i%^YELLOW%^ght%^RESET%^.");
/*    set_night_long("%^BLUE%^A small %^MAGENTA%^quay%^RESET%^%^BLUE%^ lies sheltered in a hidden"
      +" %^ORANGE%^cove%^BLUE%^%^. Boats and small ships can be docked here,"
      +" and the platform leads up onto a %^ORANGE%^p%^BOLD%^%^WHITE%^e"
      +"%^RESET%^%^ORANGE%^b%^CYAN%^b%^RESET%^l%^ORANGE%^e"
      +" b%^RESET%^e%^ORANGE%^a%^CYAN%^c%^ORANGE%^h%^RESET%^%^BLUE%^. A short walk"
      +"  up the beach, a %^ORANGE%^trail%^RESET%^%^BLUE%^ leads west through the"
      +" dense %^BOLD%^%^GREEN%^j%^RESET%^%^GREEN%^u%^BOLD%^ng%^RESET%^"
      +"%^GREEN%^l%^BOLD%^e %^BLUE%^which crowds up to the edge of the"
      +" beach. The %^BOLD%^sea%^RESET%^%^BLUE%^ is not too rough here, as"
      +" the natural harbour breaks up the surf. The %^CYAN%^waves%^BLUE%^"
      +" keep rolling in, all the same, and the %^BOLD%^%^BLUE%^water"
      +" %^RESET%^%^CYAN%^gl%^BOLD%^%^WHITE%^i%^CYAN%^n%^RESET%^%^CYAN%^ts"
      +" %^RESET%^ in the %^BOLD%^%^WHITE%^m%^RESET%^oo%^BOLD%^%^WHITE%^nl%^RESET%^i%^BOLD%^%^WHITE%^ght%^RESET%^%^BLUE%^."); 
*/
     set_listen("default","The rolling waves beat against the beach,"
       +" and you can hear the cries of birds and animals in the distance");
   set_smell("default","The brine of the ocean mingles with the humid"
       +" earthy smell of the jungle.");
 
    set_exits(([
       "west" : WEMIC + "trail01",
      "north" : WEMIC + "beach05",
      "south" : WEMIC + "beach01"
    ] ));
    set_items(([
      ({"pebble", "pebbles", "pebbled beach", "beach"}) : "The %^ORANGE%^p%^BOLD%^%^WHITE%^e"
      +"%^RESET%^%^ORANGE%^b%^CYAN%^b%^RESET%^l%^ORANGE%^e%^RESET%^s seem to be formed of a"
      +" variety of rocks, giving the beach its variegated colours. They are rough on bare"
      +" feet, but it seems to have weathered the beating of the surf for many an age.",

      ({"path", "trail" }): "The trail to the west leads inland, through the jungle. It is reasonably"
      +" wide and bright, inspiring some confidence in its safety. There are some claw marks"
      +" on the trees either side of the trail, though.",
   
      "jungle" : "The %^BOLD%^%^GREEN%^j%^RESET%^%^GREEN%^u%^BOLD%^ng%^RESET%^%^GREEN%^l"
        +"%^BOLD%^e%^RESET%^ is a dense tangle of %^BOLD%^%^BLACK%^ancient %^RESET%^"
        +"%^GREEN%^trees%^RESET%^ and %^GREEN%^thick %^ORANGE%^u%^GREEN%^nd%^ORANGE%^e"
        +"%^GREEN%^rgr%^ORANGE%^o%^GREEN%^wth%^RESET%^, unpassable unless a %^ORANGE%^"
        +"path%^RESET%^ has been cut through it.",

      ({"marks", "claw marks", "trees"}) : (:TO, "claw_desc":),

      ({"dock", "quay"}) : "The quay is old, but sturdily built and shows some signs of"
      +" recent maintenance." 
    ] ));
}

string claw_desc(){
  int survival_skill;
  string result;
  survival_skill = TP->query_skill("survival");
  switch (survival_skill)
  {
  case 0:
    result = "The trees near the trail have some claw marks. You don't really know"
      +" what sort. It's kind of remarkable that you noticed them at all really,"
      +" with your level of wilderness survival skills.";
    break;
  case 1..10:
    result = "The trees near the trail have some claw marks. They are fairly deep"
      +" and the spread of the claws, along with the height they reach up the trees,"
      +" suggests some kind of large predator marking its territory.";
    break;
  case 11..20:
    result = "The trees near the trail have some claw marks. They are fairly deep"
      +" and the spread of the claws, along with the height they reach up the trees,"
      +" suggests some kind of large predator marking its territory.";
    break;
  case 21..30:
    result = "The trees near the trail have some claw marks. They are fairly deep"
      +" and the spread of the claws, along with the height they reach up the trees,"
      +" suggests some kind of large predator marking its territory. Even at a distance,"
      +" you can recognise the spread pattern of the claws as coming from a large cat,"
      +" possibly a big lion.";
  default:
    result = "The trees near the trail have some claw marks. They are fairly deep"
      +" and the spread of the claws, along with the height they reach up the trees,"
      +" suggests some kind of large predator marking its territory. You immediately"
      +" recognise them as wemic claw marks";
  } 
  return result;
}

void reset(){
   ::reset();
    if(!present("profile"))
      new(OBJ + "profile")->move(this_object());
}
