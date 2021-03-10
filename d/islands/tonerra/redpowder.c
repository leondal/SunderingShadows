#include <std.h>

inherit OBJECT;

void create(){
    ::create();
    set_name("red dust");
    set_id( ({"component", "specialcomp", "red dust", "dust"}) );
    set_short("Red dust of Staying");
    set_long(
      "This is a small bag containing one of the prized magical components. With this a trained and experienced wizard can make magic adhere to weapons."
    );
    set_value(100000);
    set_weight(10);
}
