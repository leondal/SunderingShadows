#include <std.h>

inherit OBJECT;

void create() {
  ::create();
  set_id(({"poster","wanted poster"}));
  set_name("wanted poster");
  set("short", "Wanted poster");
  set("long","This is a wanted poster for brave adventurers.");
  set_weight(0);
  set_value(0);
}

void init() {
  ::init();
  add_action("read_poster","read");
}

int read_poster(string str) {
  if(!str) notify_fail("Read what?");
  if("poster" != str) return 0;
  write("%^YELLOW%^The wanted poster reads:          %^RESET%^\n"+
        "%^GREEN%^**************************************************************\n"+
        "%^RED%^                   WANTED:  BRAVE ADVENTURERS     \n"+
        "%^GREEN%^**************************************************************\n"+
        "%^RESET%^\n"+
        "From an recently adventure, a new realm has been discovered.\n"+
        "The wealth of a wizard's lifetime can be yours!  Defeat the \n"+
        "traps!  Slay the guardians!  Loth, Queen of the Spiders, took\n"+
        "centuries to collect these marvelous treasures.  Now they \n"+
        "can be yours in a matter of hours!  Seek out Jarrow in this \n"+
        "new realm, and %^YELLOW%^listen%^RESET%^ to him about the stones.\n"+
        "\n"+
        "%^GREEN%^**************************************************************\n");
  return 1;
}
