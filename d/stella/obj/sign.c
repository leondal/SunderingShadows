#include <std.h>
inherit OBJECT;

void init(){
        ::init();
        add_action("read_sign","read");
        }

void create()
{
  ::create();
  set_name("sign");
  set_id( ({"sign"}) );
  set_short("a sign");
  set_long("The sign appears to be a warning ... perhaps you should read it.");
  set_value(0);
  set_weight(100000);
}

int read_sign(string str){
        if (!str) {
          notify_fail("Read what?\n");
          return 0; }
        if (str=="sign") {
            say(TPQCN +" reads over a sign!\n",TP);
            tell_object(TP,"The sign reads: To the west lies the Stellar Castle!\n"
			"This area should be approached with caution by players of "
			"every level and class!  It would be foolish for a low mid "
			"or newbie to attempt!");
	  }
        return 1;
      }
