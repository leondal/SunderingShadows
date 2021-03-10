#include <std.h> 
inherit ROOM; 

void create() { 
    ::create(); 
    set_property("indoors",1);
    set_property("light",2); 
    set_terrain(STONE_BUILDING);
    set_travel(RUTTED_TRACK);
    set_name("Training Hall");
    set_short("%^GREEN%^Training Hall%^RESET%^"); 
    set_long("This immense hall shows recent use despite its age. A new "
"floor made of a rubber covers the greater part of the area. Several weapon "
"racks lay about here with simple training weapons of various sizes. On the "
"north wall an odd portrait of a dwarf can been seen, which surely warrants a "
"look.");
    set_smell("default","The smell of rubber and sweat lingers here.");
    set_listen("default","The sounds of young trainees can be heard practicing their martial arts."); 
    set_items(([ 
      "portrait":"This picture shows a very large %^ORANGE%^dwarf%^RESET%^ "
"standing proud with a mighty %^BOLD%^%^BLACK%^war hammer%^RESET%^ in both "
"hands. The dwarf is glaring down at the area. He looks very %^YELLOW%^drunk"
"%^RESET%^. This picture is labeled '%^ORANGE%^Ungrim%^RESET%^ is always "
"watching us!", 
    ])); 
    set_exits(([ 
      "north" : "/d/guilds/order/hall/main",
      "west": "weaponroom",
    ])); 
}
