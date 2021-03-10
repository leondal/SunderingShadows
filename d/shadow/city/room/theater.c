//Titania (6/29/19)
//Three Coins Theater
//Designed by Ivyes

#include <std.h>
#include "../defs.h"
inherit VAULT;

void create()
{
   ::create();
   set_property("indoors",0);
   set_property("light",2);
   set_travel(PAVED_ROAD);
   set_terrain(CITY);
   set_climate("temperate");
   set_name("The Three Coins Theater, Shadow");
   set_short("%^BOLD%^%^WHITE%^The Three Coins Theater, Shadow%^RESET%^");
   set_long("%^RESET%^%^ORANGE%^This theater is an architectural feat "+
   "and a true testament to pride in craftsmanship. From its sweeping "+ 
   "cathedral ceilings, where a massive %^RESET%^%^WHITE%^chandelier "+ 
   "%^RESET%^%^ORANGE%^hangs, to the outstanding "+ 
   "%^MAGENTA%^c%^ORANGE%^a%^MAGENTA%^rved "+ 
   "d%^ORANGE%^e%^MAGENTA%^ta%^ORANGE%^il%^MAGENTA%^s %^ORANGE%^of "+ 
   "the numerous "+ 
   "%^BOLD%^%^RED%^m%^RESET%^%^RED%^o%^ORANGE%^s%^GREEN%^ai%^ORANGE%^c%^RED%^e%^BOLD%^d "+ 
   "%^RESET%^%^ORANGE%^mezzanine boxes, everywhere your gaze settles is a "+ 
   "remarkable sight to behold. The "+ 
   "%^BOLD%^%^BLACK%^sta%^RESET%^%^ORANGE%^g%^BOLD%^%^BLACK%^e %^RESET%^%^ORANGE%^is "+ 
   "set beneath a "+ 
   "c%^GREEN%^a%^ORANGE%^rv%^GREEN%^e%^ORANGE%^d w%^GREEN%^o%^ORANGE%^od%^GREEN%^e%^ORANGE%^n "+ 
   "a%^GREEN%^r%^ORANGE%^chw%^GREEN%^a%^ORANGE%^y, and framed by "+ 
   "%^BOLD%^%^RED%^h%^RESET%^%^RED%^e%^BOLD%^a%^RESET%^%^RED%^v%^BOLD%^y "+ 
   "r%^RESET%^%^RED%^e%^BOLD%^d c%^RESET%^%^RED%^u%^BOLD%^rtai%^RESET%^%^RED%^n%^BOLD%^s%^RESET%^%^ORANGE%^. "+ 
   "A large %^BOLD%^%^BLACK%^or%^RESET%^%^ORANGE%^c%^BOLD%^%^BLACK%^hes%^RESET%^%^ORANGE%^tr%^BOLD%^%^BLACK%^a "+ 
   "pit %^RESET%^%^ORANGE%^opens up in front of the grand stage. Stadium-style seating "+ 
   "provides a clear view of the stage from every angle. Traveling orchestras "+ 
   "and famous playwrights from all corners of the world come here in order to "+ 
   "perform on this magnificent stage. If nobody is currently performing, "+ 
   "it might be possible to sneak %^MAGENTA%^backstage%^BOLD%^%^WHITE%^.%^RESET%^\n");
   
   set_smell("default","%^RESET%^%^CYAN%^It smells clean and lightly perfumed.%^WHITE%^");
   set_listen("default","%^RESET%^%^MAGENTA%^The acoustics here are fantastic.%^WHITE%^");
   
   set_items(([
      "ceiling" : "%^RESET%^%^CYAN%^The ceiling is made from ornate "+ 
	  "%^BOLD%^crests %^RESET%^%^CYAN%^and %^BOLD%^waves%^RESET%^%^CYAN%^, "+ 
	  "accumulating at the apex from which a large %^WHITE%^chandelier "+ 
	  "%^CYAN%^hangs. The crowning piece is the large stained-glass "+ 
	  "window in the center of the ceiling. Shaped like a "+ 
	  "%^BOLD%^%^BLUE%^s%^RESET%^%^BLUE%^t%^CYAN%^a%^BOLD%^r%^GREEN%^b%^CYAN%^u%^RESET%^%^CYAN%^r%^BLUE%^s%^BOLD%^t%^RESET%^%^CYAN%^, "+ 
	  "the window is in many "+ 
	  "%^BOLD%^%^BLUE%^h%^RESET%^%^BLUE%^u%^CYAN%^e%^BOLD%^%^BLUE%^s "+ 
	  "%^RESET%^%^CYAN%^of %^BOLD%^%^BLUE%^bl%^RESET%^%^BLUE%^u%^BOLD%^e "+ 
	  "%^RESET%^%^CYAN%^that remind you of the "+ 
	  "%^BOLD%^%^BLUE%^s%^RESET%^%^BLUE%^e%^BOLD%^a%^RESET%^%^CYAN%^.%^WHITE%^",
      ({"chandelier"}) : "%^RESET%^%^CYAN%^Hanging from the apex of the ceiling "+ 
	  "is this astoundingly large, tiered chandelier. Largest at the top, "+ 
	  "it cascades downward into smaller "+ 
	  "%^BOLD%^%^WHITE%^rin%^RESET%^g%^BOLD%^s%^RESET%^%^CYAN%^, "+ 
	  "and is all dripping %^BOLD%^%^WHITE%^b%^RESET%^e%^BOLD%^ads%^RESET%^%^CYAN%^, "+ 
	  "tear shaped glass %^BOLD%^%^WHITE%^sh%^RESET%^a%^BOLD%^rds%^RESET%^%^CYAN%^, "+ 
	  "and round glowing %^BOLD%^%^WHITE%^or%^RESET%^b%^BOLD%^s %^RESET%^%^CYAN%^that "+ 
	  "provide a gentle light. The lights creates a "+ 
	  "%^BOLD%^%^WHITE%^d%^RESET%^a%^CYAN%^z%^BOLD%^%^WHITE%^zli%^RESET%^n%^BOLD%^g "+ 
	  "%^RESET%^%^CYAN%^display when caught in all that glass. Truly remarkable.%^WHITE%^",
      ({"boxes","mezzanine"}) : "%^RESET%^%^CYAN%^Spread across the upper levels of "+ 
	  "the theater, these boxes are made to accommodate parties of varying sizes. "+ 
	  "Most extraordinary are the "+ 
	  "%^BOLD%^%^RED%^w%^RESET%^%^RED%^a%^ORANGE%^r%^RED%^m%^BOLD%^l%^RESET%^%^RED%^y "+ 
	  "%^ORANGE%^c%^RED%^o%^BOLD%^lo%^RESET%^%^RED%^r%^ORANGE%^e%^RED%^d "+ 
	  "%^BOLD%^t%^RESET%^%^RED%^i%^ORANGE%^l%^RED%^e%^BOLD%^s %^RESET%^%^CYAN%^from "+ 
	  "which %^ORANGE%^carv%^WHITE%^e%^ORANGE%^d wo%^WHITE%^o%^ORANGE%^d%^WHITE%^e%^ORANGE%^n "+ 
	  "b%^WHITE%^u%^ORANGE%^sts %^CYAN%^come forth, each featuring a performer "+ 
	  "in mid-performance - some with %^MAGENTA%^instruments %^CYAN%^and others "+ 
	  "caught in dramatic poses. They morph into wooden arches over the boxes as "+ 
	  "if their limbs have become twisting vines.. "+
	  "Quite lovely, if not a little strange, to see.%^WHITE%^",
      ({"stage","archway","curtains"}) : "%^RESET%^%^CYAN%^Above the stage, "+ 
	  "a %^ORANGE%^carved statue %^CYAN%^of a man being pulled "+ 
	  "in a %^ORANGE%^chariot %^CYAN%^races toward the other side, "+ 
	  "where the wood is cut to resemble the outstretched "+ 
	  "%^ORANGE%^limbs %^CYAN%^of a tree. The trunk wraps down to make "+ 
	  "a frame for the grand wooden stage. "+ 
	  "%^BOLD%^%^RED%^R%^RESET%^%^RED%^e%^BOLD%^d, "+ 
	  "h%^RESET%^%^RED%^e%^BOLD%^a%^RESET%^%^RED%^v%^BOLD%^y "+ 
	  "v%^RESET%^%^RED%^e%^BOLD%^lv%^RESET%^%^RED%^e%^BOLD%^t "+ 
	  "c%^RESET%^%^RED%^ur%^BOLD%^tai%^RESET%^%^RED%^n%^BOLD%^s "+ 
	  "%^RESET%^%^CYAN%^line the stage, at times open and other "+ 
	  "times closed.%^WHITE%^",
      ({"pit","orchestra pit"}) : "%^RESET%^%^CYAN%^An orchestra could easily "+ 
	  "fit into this pit.%^WHITE%^",
      ({"seating","seats"}) : "%^RESET%^%^CYAN%^The %^RED%^seats %^CYAN%^are wide "+ 
	  "and softly padded in %^RED%^red%^CYAN%^. They look quite comfortable.%^WHITE%^",
   ]));
   set_exits(([
      "north" : ROOMS"shadway4",
	  "backstage" : ROOMS"backstage",
   ]));
   set_invis_exits(({"backstage"}));
}  