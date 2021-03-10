#include <std.h>

inherit MONSTER;

#define COLORS ({"red", "white", "yellow", "orange", "blue", "black", "brown", "clear"})
#define SIZES ({"tiny", "small", "average", "big", "gigantic"})

void create(){
    string size, color;
    ::create();
    size = SIZES[random(sizeof(SIZES))];
    color = COLORS[random(sizeof(COLORS))];
    set_property("swims", 1);
    set_property("water breather", 1);
    set_name(size+" "+color+" fish");
    set_short("A "+size+" "+color+" fish");
    set_id( ({"fish", color+" fish", size+" fish"}) );
    set_long(
      "This "+size+" "+color+" fish has lived its entire life here in the mirky waters below this magical lake.  He swims around contently in the cool waters."
    );
    set_race("fish");
    set_gender("male");
    set_body_type("snake");
    set_overall_ac(9);
    set_hd(1,1);
    set_hp(20+random(20));
    set("aggressive", random(15));
    set_alignment(5);
    set_moving(1);
    set_speed(3);
}
