#include <std.h>
#include "../derrodefs.h"

inherit CROOM;

void create(){
  set_monsters( ({MON"pech"}), ({1}) );
  ::create();
  set_repop(20);
   set_terrain(BUILT_TUNNEL);
   set_travel(FOOT_PATH);
  set_property("no teleport",1);
  set_property("light",2);
  set_property("indoors",1);
  set_short("%^BOLD%^%^RED%^Gem Studded Cave%^RESET%^");
  set_long("%^BOLD%^%^BLACK%^Carved out of the earth, this round room is studded "+
	"with gem.  Large and small stones are planted deeply within the"+
	" ground, walls, and ceiling, giving it a peaceful feeling.  The "+
	"%^BOLD%^%^RED%^fiery glow%^BLACK%^ from the lava causes the "+
	"gems to %^WHITE%^sparkle%^BLACK%^ and shine with a fiery "+
	"radiance.  A large %^WHITE%^diamond%^BLACK%^ is set in the"+
	" center of the room, with a strange fellow chipping away at"+
	" it with a pick, molding the dense stone's form.  You feel "+
	"oddly at home in this room as if nothing outside mattered and"+
	" things would be much better if you never left it all.");
  set_smell("default",  "%^RED%^The harsh vapors from the lava have"+
	" disappeared to be replaced by the scent of fresh turned earth."  );
  set_listen("default",  "%^GREEN%^Peaceful silence fills the room."  );
  set_items(([
  "walls":"Naturally formed from the action of lava through the earth"+
	" these passageways twist and turn through the rock leading "+
	"into these rooms which were just pockets at one time filled"+
	" with lava.",
  "ceiling":"Naturally formed from the action of lava through the earth"+
	" these passageways twist and turn through the rock leading into"+
	" these rooms which were just pockets at one time filled with lava.",
  "floor":"Shiny and black in places and crumbling and grey in others."+
	"   The floor seems partially unstable and you wonder how far a "+
	"fall through them to the lava would take.",
	"gems":"Studded all over this room are brilliant and shinning gems."+
	" %^ORANGE%^Sunstones%^RESET%^, %^RED%^rubies%^RESET%^, %^BOLD%^"+
	"moonstones%^RESET%^, %^BOLD%^%^BLUE%^sapphires%^RESET%^, "+
	"%^BOLD%^%^GREEN%^emeralds%^RESET%^, and %^BOLD%^%^BLACK%^black "+
	"opals%^RESET%^ seem to out number any other stone in here.",
  ]));
  set_exits(([
  "southwest":ROOMS"c40",
  ]));
//   new(MON"pech")->move(TO);  changed to use CROOM with longer reboots *Styx*  11/28/02
}
