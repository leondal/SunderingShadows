#include <std.h>
inherit "/d/common/obj/instruments/instrument_inherit.c";

void create()
{
   ::create();
   set_name("ocean drums");
   set_short("%^BOLD%^%^BLUE%^Ocean Drums%^RESET%^");
   set_id(({"drums","ocean drums"}));
   set_long("This is a set of three ocean drums, the largest being"+
   " about eight inches in diameter, and the other two decrease in"+
   " size to six and four inches. They are all round and contain"+
   " many steel pellets. The drums can either be gently rolled to"+
   " imitate the soft rhythms of the ocean, or even shaken. Two"+
   " mallets with their heads covered in black cloth, but with an"+
   " obviously hard head underneath, can create a percussive sound.");
   set_weight(5); //was 15, changed to bring in line with others - Circe 12/1/07
   set_value(2000);
}
int is_instrument(){return 1;}