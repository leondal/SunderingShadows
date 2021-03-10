#include <std.h>
inherit "/std/church";

void create(){
    ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
    set_short("%^BOLD%^%^BLACK%^The %^RED%^F%^RESET%^%^RED%^o%^BOLD%^r%^RESET%^%^RED%^g%^BOLD%^e%^RESET%"
			  "^%^RED%^s %^BOLD%^%^BLACK%^of %^CYAN%^Faith%^RESET%^ ");
    set_long("This %^YELLOW%^holy %^BLACK%^structure %^RESET%^is %^BOLD%^%^CYAN%^elaborately %^RESET%^and"
	         " %^BOLD%^%^RED%^lovingly %^RESET%^crafted from %^BOLD%^marble %^RESET%^by %^ORANGE%^dwarf a"
			 "rtisans%^WHITE%^. The symbols and creeds of the entire %^BOLD%^%^BLACK%^M%^RESET%^o%^BOLD%"
			 "^%^BLACK%^rn%^RESET%^d%^BOLD%^%^BLACK%^in%^RESET%^s%^BOLD%^%^BLACK%^a%^RESET%^m%^BOLD%^%^BL"
			 "ACK%^m%^RESET%^a%^BOLD%^%^BLACK%^n%^RESET%^ can be found %^BOLD%^carved %^RESET%^expertly i"
			 "nto its %^BOLD%^marble %^CYAN%^pillars%^RESET%^. However this building serves mainly as a re"
			 "vered %^ORANGE%^workshop %^WHITE%^for the %^ORANGE%^dwarf %^BOLD%^%^CYAN%^priests %^RESET%^o"
                         "f %^ORANGE%^Kreysneothosies%^WHITE%^, who maintains a sacred %^BOLD%^%^RED%^f%^RESET%^%^RED%^o%^BOLD"
			 "%^rg%^RESET%^%^RED%^e %^WHITE%^located at the center of the %^BOLD%^church%^RESET%^. %^YELLO"
			 "W%^Day %^RESET%^and %^BOLD%^%^BLACK%^night %^RESET%^they %^ORANGE%^craft %^WHITE%^objects fr"
			 "om %^BOLD%^%^BLACK%^metal %^RESET%^and keep the %^BOLD%^%^RED%^f%^RESET%^%^RED%^o%^BOLD%^rg%"
			 "^RESET%^%^RED%^e %^BOLD%^burning%^RESET%^, welcomming %^ORANGE%^dwarves %^WHITE%^from other %"
			 "^BOLD%^%^CYAN%^faiths %^RESET%^and %^CYAN%^occasionally %^BOLD%^%^WHITE%^honored %^RESET%^vis"
			 "itors to use their %^BOLD%^%^RED%^f%^RESET%^%^RED%^o%^BOLD%^rg%^RESET%^%^RED%^e%^WHITE%^. %^B"
			 "OLD%^%^RED%^W%^BLACK%^a%^RED%^r%^BLACK%^r%^RED%^i%^BLACK%^o%^RED%^r-pr%^BLACK%^i%^RED%^e%^BLA"
                         "CK%^s%^RED%^t%^BLACK%^s %^RESET%^of %^CYAN%^Kismet %^RESET%^often makes %^CYAN%^pilgri"
			 "mages%^WHITE%^, hoping to be instructed in th%^BOLD%^%^BLACK%^e m%^RESET%^e%^BOLD%^%^BLACK%^t"
			 "a%^RESET%^l%^BOLD%^%^BLACK%^lu%^RESET%^r%^BOLD%^%^BLACK%^g%^RESET%^i%^BOLD%^%^BLACK%^c%^RESET%"
			 "^al %^BOLD%^%^CYAN%^secrets %^RESET%^of %^BOLD%^%^BLACK%^armor %^RESET%^and %^BOLD%^%^BLACK%^w"
			 "eaponsmithing %^RESET%^in exchange for their %^YELLOW%^services%^RESET%^. The %^BOLD%^%^CYAN%^f"
"aithful %^RESET%^of %^MAGENTA%^L%^BOLD%^y%^RESET%^%^MAGENTA%^s%^BOLD%^a%^RESET%^%^MAGENTA%^r%^BOLD%^a %^WHI"
			 "TE%^likewise keep a small %^YELLOW%^contingent %^RESET%^of %^BOLD%^clerics %^RESET%^at this chu"
			 "rch, who offers %^BOLD%^blessings%^RESET%^, %^BOLD%^%^CYAN%^guidance %^RESET%^and %^BOLD%^heali"
			 "ng %^RESET%^to the travellers who arrive and depart from %^ORANGE%^Kinaro%^WHITE%^. There is a small sign you can read here.");
    set_exits( ([
	"west" : "/d/dagger/kinaro/street5.c",
      ]) );

    set_property("light", 2);
    set_property("indoors", 1);
    set_listen("default", "%^RESET%^%^GREEN%^You can hear faint sounds of chanting behind the clanging of hammers on metal. ");
    set_smell("default", "%^RESET%^%^ORANGE%^You smell the strange odor of incense and burning coal. .");
}

void init(){
    ::init();
}
