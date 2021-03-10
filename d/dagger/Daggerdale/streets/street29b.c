#include <std.h>
#include "../dagger.h"
inherit ROOM;

string shadow_longdesc();
string fey_longdesc();
string shadow_shortdesc();
string fey_shortdesc();
string shadow_smelldesc();
string fey_smelldesc();
string shadow_listendesc();
string fey_listendesc();

void create(){
    ::create();
    set_terrain(ROCKY);
    set_travel(PAVED_ROAD);
    set_property("light", 2);
    set_property("indoors", 0);
    set_name("Beneath the willow tree");
    set_short((:TO,"short_desc":));
    set_long((:TO,"long_desc":));
    set_smell("default",(:TO,"smell_desc":));
    set_listen("default",(:TO,"listen_desc":));

    set_exits(([
      "south" : STREETS"street22",
      "west" : STREETS"street28",
      "east" : SHOPS"inn",
    ]));
}

string long_desc() {
   if("/daemon/area_keeper_d"->query_area_variable("daggerdale","feyshadow") < 0) return shadow_longdesc(); return fey_longdesc();
}

string short_desc() {
   if("/daemon/area_keeper_d"->query_area_variable("daggerdale","feyshadow") < 0) return shadow_shortdesc(); return fey_shortdesc();
}

string smell_desc() {
   if("/daemon/area_keeper_d"->query_area_variable("daggerdale","feyshadow") < 0) return shadow_smelldesc(); return fey_smelldesc();
}

string listen_desc() {
   if("/daemon/area_keeper_d"->query_area_variable("daggerdale","feyshadow") < 0) return shadow_listendesc(); return fey_listendesc();
}

string shadow_shortdesc() { return "%^RESET%^%^GREEN%^Beneath the shadow-swept willow%^RESET%^"; }
string shadow_longdesc() {
   return("%^CYAN%^Standing in the %^BOLD%^%^BLACK%^shadow %^RESET%^%^CYAN%^of the massive %^GREEN%^willow tree%^CYAN%^, you feel as if you are in the presence of something dark and "
"otherworldly. Overhead, the long, slender boughs reach toward the ground, swaying in an %^MAGENTA%^eerie %^CYAN%^dance of %^BOLD%^%^BLACK%^a%^RESET%^she%^BOLD%^%^BLACK%^n %^RESET%^"
"%^CYAN%^tendrils upon %^BLUE%^twilight%^CYAN%^. The %^ORANGE%^s%^BOLD%^%^BLACK%^p%^RESET%^i%^BOLD%^ral%^RESET%^i%^BOLD%^%^BLACK%^n%^RESET%^%^ORANGE%^g %^CYAN%^trunk provides a strong "
"foundation, its sturdy roots entangling themselves amongst traces of %^BOLD%^%^BLACK%^f%^RESET%^o%^BOLD%^%^BLACK%^g %^RESET%^%^CYAN%^and %^BOLD%^%^BLACK%^s%^RESET%^ton%^BOLD%^%^BLACK%^e"
"%^RESET%^%^CYAN%^. Tall %^GREEN%^grass %^CYAN%^grows tall beneath your feet, adding its own susurrus to the swaying of the tree and the %^RED%^magic %^CYAN%^that enshrouds everything within "
"this tenebrous %^GREEN%^glade%^CYAN%^.%^RESET%^\n");
}
string shadow_smelldesc() { return "%^RESET%^%^GREEN%^The %^CYAN%^cloying %^GREEN%^scent of the willow tree %^RESET%^clouds %^GREEN%^your senses.%^RESET%^"; }
string shadow_listendesc() { return "%^RESET%^%^MAGENTA%^The low %^RESET%^hiss %^MAGENTA%^of the wind and the %^BLUE%^undertone %^MAGENTA%^of a nearby stream are quite unsettling.%^RESET%^"; }

string fey_shortdesc() { return "%^BOLD%^%^GREEN%^Beneath the verdant willow%^RESET%^"; }
string fey_longdesc() {
   return("%^BOLD%^%^WHITE%^Standing in the %^BLACK%^shadow %^WHITE%^of the massive %^GREEN%^willow tree%^WHITE%^, you feel as if you are in the presence of something ancient and "
"otherworldly. Overhead, the long, slender boughs reach toward the ground, swaying in a %^CYAN%^mesmerizing %^WHITE%^dance of %^BLACK%^s%^RESET%^ilve%^BOLD%^%^BLACK%^r %^WHITE%^and "
"%^GREEN%^green%^WHITE%^. The %^RESET%^%^CYAN%^s%^BOLD%^%^BLACK%^p%^RESET%^i%^BOLD%^ral%^RESET%^i%^BOLD%^%^BLACK%^n%^RESET%^%^CYAN%^g %^BOLD%^%^WHITE%^trunk provides a strong "
"foundation, its sturdy roots grounding themselves amongst flashes of %^BLACK%^s%^RESET%^ilve%^BOLD%^%^BLACK%^r %^WHITE%^and %^BLACK%^s%^RESET%^ton%^BOLD%^%^BLACK%^e%^WHITE%^. "
"The %^GREEN%^grass %^WHITE%^grows tall beneath your feet, adding its own gentle song to the swaying of the tree and the %^MAGENTA%^magic %^WHITE%^that enchants everything alive in "
"this lovely %^GREEN%^glade%^WHITE%^.%^RESET%^\n");
}
string fey_smelldesc() { return "%^BOLD%^%^GREEN%^The fresh scent of the willow tree %^RESET%^%^GREEN%^invigorates %^BOLD%^your senses.%^RESET%^"; }
string fey_listendesc() { return "%^BOLD%^%^CYAN%^The %^RESET%^%^CYAN%^whisper %^BOLD%^of the wind and the %^RESET%^%^CYAN%^murmur %^BOLD%^of a nearby stream is quite serene.%^RESET%^"; }