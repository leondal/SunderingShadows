#include <std.h>
#include "../bpeak.h"
inherit OBJECT;

void make_me();

void create()
{
::create();
   make_me();
   set_weight(1);
   set_value(2);
}
void init(){
   ::init();
}
void make_me() {
   switch(random(5)) {
      case 0:
         set_name("%^RESET%^C%^BOLD%^%^WHITE%^l%^RESET%^a%^BOLD%^%^WHITE%^m s%^BLACK%^h%^RESET%^e%^BOLD%^%^WHITE%^l%^RESET%^l");
         set_id(({"shell","Clam shell","Shell","clam shell","seashell"}));    
         set_short("%^RESET%^C%^BOLD%^%^WHITE%^l%^RESET%^a%^BOLD%^%^WHITE%^m s%^BLACK%^h%^RESET%^e%^BOLD%^%^WHITE%^l%^RESET%^l");
         set_long("%^RESET%^This shell is not actually a whole shell but rather just"
" the top half of a clam shell.  About an inch and a half in diameter, this shell"
" is semi-circular in shape with a deeply ribbed dome.  It is a dull white in color,"
" with darker colorings in the recesses of the ribs.  Near the back of the shell"
" you can see where it once attached to its lower half.  The inside of the shell is"
" smooth to the touch and due to the domed design, is shaped almost like a shallow"
" bowl.%^RESET%^\n");
      break;
      case 1:
         set_name("%^RESET%^Sand dollar");
         set_id(({"shell","sand dollar","Shell","Sand dollar","seashell"}));    
         set_short("%^RESET%^Sand dollar");
         set_long("%^RESET%^This shell is about two inches in diameter and is"
" fairly flat.  The shell looks as though it were actually made from two separate"
" flat shells, pressed together, one forming the top, and the other the bottom."
"  There are no visible openings into the shell other than a small round hole"
" located in the center of the bottom shell.  The top shell is a dull white in color"
" and is slightly domed and portrays the perfectly centered image of a star.  The"
" bottom half of the shell is also the same dull white color, but is covered by very"
" tiny %^ORANGE%^brown hairs.%^RESET%^\n");
      break;
      case 2:
         set_name("%^RESET%^%^ORANGE%^Starfish%^RESET%^");
         set_id(({"shell","seashell","starfish","Starfish","Star fish","star fish"}));
         set_short("%^RESET%^%^ORANGE%^Starfish%^RESET%^");
         set_long("%^RESET%^%^ORANGE%^This is a dried out starfish that is a dull"
" orange in color.  Once a living creature, this animal got its name from its star"
" like shape.  The texture of the skin is slightly rough to the touch, and dried out"
" as it is, it is very hard and durable.%^RESET%^");
      break;
      case 3:
         set_name("%^YELLOW%^S%^RESET%^%^ORANGE%^e%^RESET%^a%^YELLOW%^s%^RESET%^%^ORANGE%^n%^RESET%^a%^BOLD%^%^WHITE%^i%^BLACK%^l s%^WHITE%^h%^RESET%^e%^ORANGE%^l%^RESET%^l");
         set_id(({"shell","seashell","snailshell","snail shell","seasnail","seasnailshell","seasnail shell","sea snail shell","sea snail"}));
         set_short("%^YELLOW%^S%^RESET%^%^ORANGE%^e%^RESET%^a%^YELLOW%^s%^RESET%^%^ORANGE%^n%^RESET%^a%^BOLD%^%^WHITE%^i%^BLACK%^l s%^WHITE%^h%^RESET%^e%^ORANGE%^l%^RESET%^l");
         set_long("%^RESET%^This shell is a typical %^YELLOW%^s%^RESET%^%^ORANGE%^"
"e%^RESET%^a%^YELLOW%^s%^RESET%^%^ORANGE%^n%^RESET%^a%^BOLD%^%^WHITE%^i%^BLACK%^l"
" s%^WHITE%^h%^RESET%^e%^ORANGE%^l%^RESET%^l, wrapped something like a %^ORANGE%^c"
"%^BOLD%^%^WHITE%^o%^RESET%^n%^ORANGE%^c%^RESET%^h but without any spikes and much"
" smaller.  Usually you will find %^BOLD%^%^BLACK%^sandcrabs %^RESET%^making their"
" homes in these shells.  The texture of the shell is fairly smooth, and the color"
" of the shell is a bright %^YELLOW%^yellow %^RESET%^with %^RESET%^%^ORANGE%^darker"
" orange %^YELLOW%^s%^RESET%^%^ORANGE%^t%^YELLOW%^r%^RESET%^%^ORANGE%^i%^YELLOW%^p"
"%^RESET%^%^ORANGE%^e%^YELLOW%^s.%^RESET%^");
      break;
      case 4:
         set_name("%^RESET%^%^CYAN%^G%^GREEN%^r%^CYAN%^e%^GREEN%^e%^CYAN%^n %^GREEN%^L%^CYAN%^i%^GREEN%^m%^CYAN%^p%^GREEN%^e%^CYAN%^t%^RESET%^");
         set_short("%^RESET%^%^CYAN%^G%^GREEN%^r%^CYAN%^e%^GREEN%^e%^CYAN%^n %^GREEN%^L%^CYAN%^i%^GREEN%^m%^CYAN%^p%^GREEN%^e%^CYAN%^t%^RESET%^");
         set_id(({"shell","Green Limpet","green limpet","Green limpet","seashell","sea shell"}));
         set_long("%^RESET%^This shell is about one half of an inch in diameter and"
" is cone shaped.  The top half of the shell is a dullish %^ORANGE%^o%^YELLOW%^"
"r%^RESET%^%^ORANGE%^an%^YELLOW%^g%^RESET%^%^ORANGE%^e %^RESET%^to %^ORANGE%^brown,"
" %^RESET%^matching the colors of the %^BOLD%^%^WHITE%^s%^BLACK%^a%^RESET%^n"
"%^ORANGE%^d%^BOLD%^%^WHITE%^s, %^RESET%^while the underside %^BOLD%^"
"%^CYAN%^shimmers %^RESET%^in shades from %^BOLD%^%^WHITE%^white %^RESET%^to"
" %^CYAN%^a%^BOLD%^%^CYAN%^q%^RESET%^%^GREEN%^u%^CYAN%^a.%^RESET%^  The outside of"
" the shell is rather rough feeling, but the inside of the shell is amazingly "
"smooth.");
      break;
   }    
}     

