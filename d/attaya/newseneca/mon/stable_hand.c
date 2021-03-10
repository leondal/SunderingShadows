#include <std.h>
inherit NPC;

void create() {
   ::create();
   set_name("stable hand");
   set_nwp("riding",16);
   set_short("An experienced stable hand");
   set_id(({"stablehand","experienced stable hand","stable hand","hand"}));
   set_gender("male");
   set_race("human");
   set_long("This stablehand looks to be well into his thirties.  "+
      "He has shoulder-length %^BOLD%^%^BLACK%^black hair %^RESET%^"+
      "%^CYAN%^tied back to keep it out of his way.  His arms and "+
      "face bear %^MAGENTA%^scars%^CYAN%^, likely from his tough "+
      "job training mounts.  He is dressed in a simple %^ORANGE%^"+
      "leather jerkin %^CYAN%^atop matching %^ORANGE%^breeches "+
      "%^CYAN%^tucked into his boots.  He keeps a pair of %^BOLD%^"+
      "%^BLACK%^leather gloves %^RESET%^%^CYAN%^that reach past his "+
      "elbow tucked behind his belt to be at hand in case he needs "+
      "them.  He has been working with animals his whole life and "+
      "at one time thought to be a ranger, but he found that working "+
      "as a stable boy when he was young was his true calling.  He "+
      "can help you with any of the mounts you may be interested in.");
}
