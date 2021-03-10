#include <std.h>
inherit OBJECT;
string LUCIFER;

void create() {
  ::create();
set_id(({"bag"})); 
set_short("%^RED%^A Bag of Gems%^RESET%^");
set_long(
@LUCIFER
This is a bag of Gems.  It looks like it may be worth
quite a lot.
LUCIFER
);
set_weight(30);
set("value",60000);
}
