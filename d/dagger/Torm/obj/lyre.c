#include <std.h>
inherit "/d/common/obj/instruments/instrument_inherit.c";

void create()
{
   ::create();
   set_name("rosewood lyre");
   set_short("%^RESET%^%^RED%^A rosewood lyre%^RESET%^");
   set_id(({"lyre","rose lyre","rosewood lyre"}));
   set_long("This is a beautifully crafted lyre made from sweet"+
   " smelling rosewood. The wood has a reddish cast to it and the"+
   " grain of the wood has many different hues. It has been smoothed"+
   " and polished and is strung with 12 strings, so as to be played"+
   " with both hands to create a soft and soothing melody. The strings"+
   " start clustered at the bottom where they are firmly fixed to the"+
   " wood, and expand outwards where they are individually attached to"+
   " the very edge of the wood, with a hollow portion near the center"+
   " that helps to enhance the sound.");
   set_weight(5); //was 10, changed to bring in line with others - Circe 12/1/07
   set_value(1200);
}
int is_instrument(){return 1;}