#include <std.h>
#include <daemons.h>
inherit OBJECT;

// adding sets so ones inheriting this can have diff. day/night shorts *Styx* 12/24/03
void set_nightShort(string str) { set("nightShort", str);  }
void set_dayShort(string str) {  set("dayShort", str);  }

void create() {
    ::create();
    set_id( ({"street light","street_light","light"}) );
    set_name("street light");
    set_short("A dark street light");
    set_dayShort("A dark street light");
    set_nightShort("%^BOLD%^%^WHITE%^A lit street light%^RESET%^");
    set_weight(1000000);
    set_long("The street light is made of wrought iron and stands about ten feet high.  It appears to be an oil fueled lamp.  It lights up the streets at night.");
    set_value(0);
    set_property("no animate", 1);   // making this standard for street lights *Styx* 12/03
}

void init() {
    string tod;
    ::init(); // don't know how we missed having this but adding it now, Styx 12/24/03
    if(!interactive(TP)) return;
    tod = EVENTS_D->query_time_of_day();
    if((tod == "night") && !query_property("light")) {
        set_property("light",3);
        set_short(query("nightShort"));
    }
    if((tod != "night") && query_property("light")){
        remove_property("light");
        set_short(query("dayShort"));
    }
}
