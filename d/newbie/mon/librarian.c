#include <std.h>
inherit NPC;

void create()
{
  ::create();
  set_name("Isabel");
  set_short("Isabel Candlewick, Offestry Librarian");
  set_id(({"isabel","Isabel","Isabel Candlewick","isabel candlewick","librarian","Offestry librarian","offestry librarian"}));
  set_long(
	   "Isabel Candlewick is the librarian of the city of Offestry. It is her job to keep"+
	   " all the books and scrolls organized along the numerous shelves. She has a few"+
	   " pages that help her fetch things and make copies of important scrolls. She is"+
	   " only about thirty years old, but seems to spend all her time in the library. Her"+
	   " skin is pale from lack of light, and her dark hair only emphasizes that fact. Her"+
	   " eyes are a mysterious dark blue, and she always seems to be lost in thought. She"+
	   " wears a midnight blue robe that is tied with a silk black cord. Although"+
	   " preoccupied, she is more than willing to help you find what you're looking for"+
	   " here."
	   );
  set_race("human");
  set_gender("female");
  set_class("mage");
  set_level(1);
  set("aggressive",0);
  set_alignment(1);
  set_size(2);
  set_exp(1);
  remove_std_db();
  set_db("isabel");
  set_random_act_db("isabelrandom");
  set_nwp("studying",4);

        new("/d/newbie/obj/misc/lpouch.c")->move(TO); //added in on advice of Tristan that we need more stealable things in newbieland Ts
}
