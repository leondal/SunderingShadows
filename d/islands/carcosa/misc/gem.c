#include <std.h>
inherit OBJECT;
string LUCIFER;

void create() {
  ::create();
set_id(({"ruby"})); 
set_short("%^RED%^A Red Ruby%^RESET%^");
set_long(
@LUCIFER
This is a large red ruby.  It looks like it could be worth
a lot of money.
LUCIFER
);
set_weight(30);
set("value",60000);
}
