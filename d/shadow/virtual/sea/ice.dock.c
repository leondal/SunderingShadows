#include <std.h>
#include <objects.h>
//at 16,3 on sea
inherit DOCK;

int is_virtual() { return 1; }
int is_water() { return 1; }
int is_dock() { return 1; }
void create() {
    ::create();
    set_property("light",2);
    set_property("indoors",0);
    set_terrain(ICE);
    set_travel(SLICK_FLOOR);
	set_property("light",3);
    set_climate("arctic");
    set_short("%^BOLD%^Ice Outcroping.");
    set_long("
    %^BOLD%^This dock is more of an ice shelf jutting into "+
	"the %^CYAN%^sea%^WHITE%^ than a real %^CYAN%^dock%^WHITE%^%^BOLD%^%^BLUE%^.%^WHITE%^  Whatever shore "+
	"actually is here is completely frozen over "+
	"with glacial sheets of %^CYAN%^ice%^WHITE%^%^BOLD%^%^BLUE%^.%^WHITE%^  Icebergs are "+
	"all around here making it a rather dangerous"+
	" place to steer a boat into%^BOLD%^%^BLUE%^.%^WHITE%^  The water here"+
	" looks to be a giant tub of slush rather than"+
	" an actual %^CYAN%^sea%^BOLD%^%^BLUE%^.%^WHITE%^  Many small bits of %^CYAN%^ice%^WHITE%^ cover"+
	" the surface blocking the view below%^BOLD%^%^BLUE%^.%^WHITE%^  %^RESET%^");

    set_listen("default","Gentle slushy-like noises can be heard%^BOLD%^%^BLUE%^.%^WHITE%^");
    set_smell("default","It smells of frozen sea water%^BOLD%^%^BLUE%^.%^WHITE%^");
 
    set_exits(([
       "north" : "/d/islands/elf/shore/shore1",
    ] ));
    set_items(([
      "dock" : "The dock is more of a low bit of glacier"+
	  " one can pull a boat up to.  ",
      "ice" : "The whole area is covered in ice%^BOLD%^%^BLUE%^.%^WHITE%^",
      "sea" : "The sea is full of floating shards of ice%^BOLD%^%^BLUE%^.%^WHITE%^"
    ] ));
}

void reset(){
   ::reset();
    if(!present("sign"))
      new("/d/islands/elf/obj/sign2")->move(TO);
}
