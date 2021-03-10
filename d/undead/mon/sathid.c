#include "../undead.h"
inherit "/std/comp_vend";

void create(){
   ::create();
   set_name("sathid");
   set_id(({"sathid","shop keeper","man","elderly man"}) );
   set_short("Sathid, an elderly man");
   set_long("%^RESET%^%^CYAN%^Aged and wrinkled, you're sure Sathid has seen "
"better days.  He walks around with a stooped stance, his %^RESET%^whispy white "
"hair %^CYAN%^forming a shifting halo about his face as he moves about.  Often "
"you notice him extending withered fingers to caress a nearby %^BOLD%^crys"
"%^WHITE%^t%^CYAN%^al %^RESET%^%^CYAN%^as though they were lifelong friends "
"rather than inanimate objects.%^RESET%^\nTo get a list of shop commands, type "
"help shop.");
   set_gender("male");
   set_alignment(5);
   set_race("human");
   set_body_type("human");
   set_class("psion");
   set_hd(30,1);
   set_max_hp(300);
   set_hp(300);
   set_property("no bump", 1);
    set_shop_type("psion");
    set_components(100);
   set_spell_chance(80);
   set_spells(({"swarm of crystals","swarm of crystals","energy bolt","energy bolt","energy bolt","energy retort"}));
}
