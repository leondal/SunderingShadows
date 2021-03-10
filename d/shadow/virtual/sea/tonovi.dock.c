#include <std.h>
#include <objects.h>
inherit DOCK;

void create() {
  ::create();
  set_property("light",2);
  set_property("no teleport",1);
  set_property("indoors",1);
  set_terrain(BARREN);
  set_travel(DECAYED_FLOOR);
  set_name("A small cave off the Dagger Sea");    
  set_short("%^BOLD%^%^BLUE%^A small cave off the Dagger Sea%^RESET%^");
  set_long("%^BOLD%^%^BLUE%^Carved by time and the %^CYAN%^waves%^BLUE%^"
", this secluded cave provides a narrow, almost unnoticed opening to the "
"encroaching %^BLACK%^Dagger Sea%^BLUE%^.  The rock shelf which circles "
"the half-moon shaped cave provides a suitable place for docking a boat "
"or even a small, quick ship.  %^BLACK%^Iron pilings %^BLUE%^have been "
"driven into the stone at even spaces to provide posts for tethering "
"one's craft, while thick%^RESET%^ rope ladders %^BOLD%^%^BLUE%^hang "
"against the side for those who enter the dock by swimming.  Though "
"fairly small, the cove is deep and the cave acts as a natural shelter "
"against prying eyes.  Judging by the tunnel that leads off from the back"
", this is probably a place where such disguise is required.%^RESET%^");
  set_smell("default","The tang of the salty sea air fills the cave.");
  set_listen("default","You can hear the rush of the tide.");

    set_items(([
      ({"cave","rock shelf","shelf","half-moon"}) : "%^BOLD%^%^BLUE%^The "
"cave is small in size but big enough to provide a safe harbor for a boat "
"or two.  The deep waters of this cove allow even small ships to make "
"their way safely to the stone rim that serves as a dock here.%^RESET%^",
      ({"Dagger Sea","dagger sea","sea"}) : "%^RESET%^%^CYAN%^Due to the "
"natural formation of the cave's shape, you can't see the Dagger Sea from "
"here, but you can certainly hear the waves crashing against the stone "
"outside as well as watch the water flow and surge in the small "
"cove.%^RESET%^",
      ({"water","tide","waves"}) : "%^RESET%^%^CYAN%^Moving with the "
"tide, you can see the water flowing in and out of the small cove.  It "
"would be a difficult place for swimming for the inexperienced.%^RESET%^",
      ({"tunnel","passage"}) : "%^BOLD%^%^BLUE%^Toward the back of the "
"cave you can see that a tunnel system opens up.  Based on the even size "
"and smooth edges, it looks to have been carved by hand. It would have "
"taken a lot of work to make such a thing and you have to wonder who "
"would have such dedication.%^RESET%^",
      ({"crates","crate","barrel","barrels"}) : "%^RESET%^%^ORANGE%^The "
"crates, barrels and chests all look to be in good condition.  Every one "
"of them is either locked or strapped with iron bands, making tampering "
"difficult if not impossible.  And unless you want to end up in those "
"cages across the way, its probably best not to tamper with "
"them.%^RESET%^",
      ({"cages","cage"}) : "%^BOLD%^%^BLACK%^Standing about five foot "
"tall and equally as wide, these cages are set off to the side out of the "
"way.  A terrible smell issues from them and you can almost feel the "
"misery of those who were once forced to endure their small "
"confines.%^RESET%^",
      ({"piling","pilings","iron piling","iron pilings"}) : "%^BOLD%^"
"%^BLACK%^Pounded into the stone of the rock shelf, these pilings are "
"made of iron and provide a place to tether a boat while at dock.  "
"Several look rusted and a few have fallen away when the stone around "
"them broke, but most are in good repair.%^RESET%^",
      ({"ladder","ladders","rope ladder"}) : "%^BOLD%^%^BLUE%^You can't "
"imagine anyone wanting to swim in this cove, not with the way the water "
"surges in and out causing a constant, dangerous motion.  Though if you "
"were to fall off the rock shelf, you might be thankful these sturdy "
"looking rope ladder have been hung off the side to provide you an easy "
"way back up.%^RESET%^",
    ]));

    set_exits(([
      "north" : "/d/underdark/upper/tonovitunnel/tormdock02",
    ]));
}