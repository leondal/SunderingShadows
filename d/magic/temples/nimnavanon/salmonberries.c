#include <std.h>
inherit "/std/food";

void create()
{
   ::create();
   set_name("salmonberries");
   set_short("%^GREEN%^A handful of %^RED%^Sa%^BOLD%^lm%^RESET%^%^RED%^o%^BOLD%^n%^RESET%^%^RED%^berr%^BOLD%^ies%^RESET%^");
   set_id(({"salmonberries","berries"}));
   set_long("The %^RED%^Sa%^BOLD%^lm%^RESET%^%^RED%^o%^BOLD%^n%^RESET%^%^RED%^berr%^BOLD%^ies%^RESET%^ are red with a hint of orange and look juicy and ripe.");
   set_smell("The %^RED%^Sa%^BOLD%^lm%^RESET%^%^RED%^o%^BOLD%^n%^RESET%^%^RED%^berr%^BOLD%^ies%^RESET%^ have a sweet fragrance.");
   set_weight(1);
   set_value(0);
   set_destroy();
   set_strength(5);
   set_my_mess("You eat a handful of %^RED%^Sa%^BOLD%^lm%^RESET%^%^RED%^o%^BOLD%^n%^RESET%^%^RED%^berr%^BOLD%^ies%^RESET%^. They are juicy, floral-sweet and sour in a fresh way.");
   set_your_mess("eats a handful of %^RED%^Sa%^BOLD%^lm%^RESET%^%^RED%^o%^BOLD%^n%^RESET%^%^RED%^berr%^BOLD%^ies%^RESET%^.");
}