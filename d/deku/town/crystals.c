#include <std.h>
inherit ROOM;

void create(){
	::create();
	set_travel(PAVED_ROAD);
        set_terrain(CITY);
	set_light(2);
	set_indoors(1);
        set_name("A rustic wooden building");
        set_short("%^RED%^A rustic wooden building%^RESET%^");
        set_long("%^RED%^A rustic wooden building%^RESET%^\n"
"%^ORANGE%^This building is old, made entirely of large logs cut and placed "
"carefully.  The effect is a rustic building with a cozy feel.  Heavy "
"%^BOLD%^%^BLACK%^wro%^RESET%^%^WHITE%^u%^BOLD%^%^BLACK%^ght ir%^RESET%^"
"%^WHITE%^o%^BOLD%^%^BLACK%^n br%^RESET%^%^WHITE%^a%^BOLD%^%^BLACK%^cket"
"%^RESET%^%^WHITE%^s%^BOLD%^%^BLACK%^ %^RESET%^%^ORANGE%^hold %^BOLD%^"
"%^MAGENTA%^crys%^RESET%^%^MAGENTA%^t%^BOLD%^als%^RESET%^%^ORANGE%^ that "
"glow softly, but the light does not fill the room, instead just adding to "
"its gentle charm. A heavy counter is %^WHITE%^c%^ORANGE%^a%^WHITE%^rv%^BOLD%^"
"%^BLACK%^e%^RESET%^%^WHITE%^d %^RESET%^%^ORANGE%^with a thousand symbols "
"that overlap and almost seem to move on their own accord. The walls are "
"dominated by hundreds upon hundreds of carefully labeled drawers.\n\n"
"%^RESET%^<help shop> will give you help on how to use the shop.\n");
        set_smell("default","A soft oaky scent permeates the room.");
        set_listen("default","The quiet murmur of a small town filters in through the doorway.");
    set_exits(([
        "west" : "/d/deku/town/portal",
    ]) );
    if(!present("joran")) 
    {
        find_object_or_load("/d/deku/monster/joran")->move(TO);
    }
}

void reset(){
   ::reset();
   if(!present("joran")) {
      find_object_or_load("/d/deku/monster/joran")->move(TO);
   }
}
