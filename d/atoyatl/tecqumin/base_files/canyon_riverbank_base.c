#include <std.h>
#include <move.h>
#include "../tecqumin.h"

inherit ROOM;

string side;
string long_desc();
string sound_desc();

void create() {
  ::create();
  set_indoors(0);
  set_property("light", 0);
  set_terrain(SHORE);
  set_travel(SLICK_FLOOR);
  set_name("Riverbank in a canyon");
  set_short("%^BOLD%^%^BLUE%^R%^CYAN%^i%^BLUE%^v%^RESET%^%^CYAN%^e%^BOLD%^"
    +"%^BLUE%^rb%^RESET%^%^BLUE%^a%^BOLD%^%^BLUE%^nk%^RESET%^%^ORANGE%^ at the"
    +" foot of a %^GREEN%^jungle %^ORANGE%^canyon");
  set_long( (:TO,"long_desc":) );
  set_items( ([({"wall", "canyon wall"}) : "The canyon wall rises high above"
                      +" your head. A small path winds its way up the side.",
      ({"river", "fast river", "fast flowing river", "water"}) : "The"
                    +" %^BOLD%^%^BLUE%^river%^RESET%^ is wide, deep and fast"
                    +" flowing at this point, practically impossible to cross.",
      ({"path", "small path"}) : "The path leads upwards, winding north and"
                    +" south along the canyon wall. "
    ]) );
  set_smell( "default", "The rush of %^BOLD%^%^CYAN%^w%^BLUE%^a%^CYAN%^ter"
    +"%^RESET%^%^ORANGE%^ and %^BOLD%^%^WHITE%^spray %^RESET%^%^ORANGE%^fills"
    +" your nostrils" );
  set_listen("default",(:TO, "sound_desc":));
}

string long_desc(){
  string desc, candir, waterdir;
  switch(side){
  case "west":
    waterdir = "east";
    candir = "west";
    break;
  default:
    waterdir = "west";
    candir = "east";
    break;
  }
  desc = "%^ORANGE%^You are on a %^RESET%^muddy %^BLUE%^riverbank %^ORANGE%^at"
    +" the bottom of a long canyon. The narrow bank meets the"
    +" %^BOLD%^%^YELLOW%^canyon wall%^RESET%^%^ORANGE%^ to the " + candir 
    + ", and the fast flowing %^BOLD%^%^BLUE%^river%^RESET%^%^ORANGE%^ to the " 
    + waterdir + ". A small path cut into the side of the canyon wall winds"
    +" its way up to the top.";
  if (present("unfettered", TO)){
    desc += "\n%^BLUE%^In the middle of the %^BOLD%^%^BLUE%^river"
      +"%^RESET%^%^BLUE%^, an unspeakable %^BOLD%^%^BLACK%^ab%^RESET%^"
      +"%^MAGENTA%^o%^BOLD%^%^BLACK%^m%^RESET%^%^BLUE%^i%^BOLD%^%^BLACK%^nat"
      +"%^RESET%^%^ORANGE%^i%^BOLD%^%^BLACK%^on %^RESET%^%^BLUE%^against"
      +" %^BOLD%^%^GREEN%^n%^RESET%^%^GREEN%^a%^BOLD%^%^GREEN%^tu%^RESET%^"
      +"%^GREEN%^r%^BOLD%^%^GREEN%^e %^RESET%^%^BLUE%^has brought itself to a"
      +" halt by attaching long %^MAGENTA%^tentacles %^BLUE%^to the%^BOLD%^"
      +" %^YELLOW%^canyon wall%^RESET%^%^BLUE%^. The %^MAGENTA%^wr%^BOLD%^"
      +"%^MAGENTA%^i%^RESET%^%^MAGENTA%^th%^BOLD%^%^YELLOW%^i%^RESET%^"
      +"%^MAGENTA%^ng m%^BLUE%^a%^MAGENTA%^ss %^BLUE%^of its body is buffetted"
      +" by the %^BOLD%^%^BLUE%^water%^RESET%^%^BLUE%^, which appears to be"
      +" causing it some distress, to judge by the earsplittingly %^BOLD%^"
      +"%^CYAN%^high pitched %^YELLOW%^keening %^CYAN%^noise%^RESET%^%^BLUE%^"
      +" it is making. A %^BOLD%^%^BLACK%^dark aura %^RESET%^%^BLUE%^keeps"
      +" gathering around it, only to be dragged away by the rushing%^BOLD%^"
      +" %^BLUE%^water%^RESET%^%^BLUE%^.";
  }
  return desc;
}

string sound_desc(){
  string desc;
  if (present("unfettered", TO)){
    desc = "A %^BOLD%^%^CYAN%^high pitched %^YELLOW%^keening"
      +" %^CYAN%^noise%^RESET%^%^GREEN%^ assaults your ears";
  } else {
    desc = "You can hear the sound of the fast flowing %^BOLD%^%^CYAN%^w"
      +"%^BLUE%^a%^CYAN%^ter";
  }
  return desc;
}
