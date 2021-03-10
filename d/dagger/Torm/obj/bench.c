#include <std.h>
inherit OBJECT;
void create(){
  ::create();
  set_id(({"bench","park bench"}));
  set_name("Park bench");
  set_short("A park bench");
  set_weight(10000);
  set_long(
  "  This ornate park bench is here for those people wandering the park to stop and take a break to enjoy the view."
  "  Its high back and soft padded seat look very comfortable and it looks in good upkeep for being out in the weather all the time."
  );
  set_value(0);
}
