//~Circe~ 12/2/07 for new Seneca

#include <std.h>
#include "../seneca.h"

inherit VAULT;

void create(){
   ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_light(2);
   set_indoors(1);
   set_name("Crystal Emporium of the Spire of Serenity, Seneca");
   set_short("%^BOLD%^%^WHITE%^Crystal Emporium of the %^RESET%^%^ORANGE%^"+
      "S%^RED%^p%^ORANGE%^i%^RED%^r%^ORANGE%^e %^RED%^o%^ORANGE%^f "+
      "%^RESET%^%^RED%^S%^ORANGE%^e%^RED%^r%^ORANGE%^e%^RED%^n"+
      "%^ORANGE%^i%^RED%^t%^ORANGE%^y%^BOLD%^%^WHITE%^, Seneca%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^Crystal Emporium of the %^RESET%^%^ORANGE%^"+
      "S%^RED%^p%^ORANGE%^i%^RED%^r%^ORANGE%^e %^RED%^o%^ORANGE%^f "+
      "%^RESET%^%^RED%^S%^ORANGE%^e%^RED%^r%^ORANGE%^e%^RED%^n"+
      "%^ORANGE%^i%^RED%^t%^ORANGE%^y%^BOLD%^%^WHITE%^, Seneca%^RESET%^\n"+
      "The curved walls of this shop are fashioned from %^RED%^red "+
      "stone %^RESET%^and softened with %^ORANGE%^natural wooden shelves "+
      "%^RESET%^that match the gentle arc of the walls.  Each shelf "+
      "holds items for sale - small %^ORANGE%^ceramic bowls %^RESET%^"+
      "hold uncut %^GREEN%^c%^CYAN%^r%^BOLD%^%^BLUE%^y%^MAGENTA%^s"+
      "%^RED%^t%^YELLOW%^a%^RESET%^%^MAGENTA%^l%^BOLD%^%^GREEN%^s %^RESET%^"+
      "while tiny %^ORANGE%^wooden bookcases %^RESET%^have been arranged "+
      "on other shelves, each little shelf holding a certain %^BOLD%^"+
      "c%^YELLOW%^o%^CYAN%^l%^GREEN%^o%^RED%^r %^RESET%^of crystal.  "+
      "Large %^BOLD%^%^MAGENTA%^s%^RESET%^%^MAGENTA%^p%^BOLD%^a%^RESET%^"+
      "%^MAGENTA%^r%^BOLD%^k%^RESET%^%^MAGENTA%^l%^BOLD%^i%^RESET%^"+
      "%^MAGENTA%^n%^BOLD%^g geodes %^RESET%^split in half have been "+
      "arranged on the lower shelves, allowing customers to inspect "+
      "them before buying.  In the center of the store is a %^ORANGE%^"+
      "wooden island %^RESET%^oval in shape that has been lined with "+
      "decorative %^BOLD%^%^BLACK%^vases %^RESET%^filled with "+
      "%^BOLD%^%^CYAN%^crystal chips %^RESET%^and %^BOLD%^dust %^RESET%^"+
      "for use in common powers.  To the far west stands a %^ORANGE%^"+
      "varnished counter%^RESET%^, behind which is a %^CYAN%^glass "+
      "case %^RESET%^displaying exquisite cuts of the most expensive "+
      "gems.  Taking up the space on the floor along the walls are "+
      "%^BOLD%^%^BLACK%^locked chests %^RESET%^that likely hold "+
      "additional supplies of the more common crystals.\n");
   set_smell("default","The clean scent of the ocean mingles with a light fragrance of ozone.");
   if(query_night() == 1){
      set_listen("default","You can faintly hear the crashing of "+
         "waves on the shore in the peace of night.");
   }else{
      set_listen("default","The faint humming of a busy day in Seneca can be heard.");
   }
   set_items(([
      ({"wall","walls"}) : "%^RED%^This floor must fall on one "+
         "of the red levels in the tower.  The walls are made "+
         "from smooth red stone and fitted with %^ORANGE%^"+
         "wooden shelves%^RED%^.%^RESET%^",
      ({"window","windows","archways","archway"}) : "This level "+
         "does not seem to have any windows.",
      ({"shelves","wooden shelves"}) : "The wooden shelves are "+
         "made to curve with the walls and support various items "+
         "for sale.",
      ({"bowls","ceramic bowls","uncut crystals"}) : "The small "+
         "%^ORANGE%^ceramic bowls %^RESET%^are glazed and hold "+
         "uncut %^GREEN%^c%^CYAN%^r%^BOLD%^%^BLUE%^y%^MAGENTA%^s"+
         "%^RED%^t%^YELLOW%^a%^RESET%^%^MAGENTA%^l%^BOLD%^"+
         "%^GREEN%^s %^RESET%^separated by color.",
      ({"bookcases","wooden bookcases","tiny bookcases"}) : "Obviously "+
         "not truly bookcases, this small display cases have rows "+
         "of small trays, each extending slightly beyond the "+
         "one above it.  Each tray has been filled the a specific "+
         "%^BOLD%^%^RED%^c%^YELLOW%^o%^GREEN%^l%^BLUE%^o%^CYAN%^r "+
         "%^RESET%^of crystal, all precut and ready to use.",
      ({"geode","geodes"}) : "Each of the geodes is rough on the "+
         "outside and vaguely round.  They have been split open to "+
         "reveal the sparkling stone inside.  You see geodes in "+
         "%^GREEN%^g%^BOLD%^r%^RESET%^%^GREEN%^e%^BOLD%^e%^RESET%^"+
         "%^GREEN%^n%^BOLD%^s%^RESET%^, %^BOLD%^%^BLUE%^b%^RESET%^"+
         "%^BLUE%^l%^BOLD%^u%^RESET%^%^BLUE%^e%^BOLD%^s%^RESET%^, "+
         "%^MAGENTA%^p%^BOLD%^u%^RESET%^%^MAGENTA%^r%^BOLD%^p"+
         "%^RESET%^%^MAGENTA%^l%^BOLD%^e%^RESET%^%^MAGENTA%^s"+
         "%^RESET%^, %^YELLOW%^g%^RESET%^%^ORANGE%^o%^YELLOW%^l"+
         "%^RESET%^%^ORANGE%^d%^YELLOW%^s%^RESET%^, and %^RED%^"+
         "r%^BOLD%^e%^RESET%^%^RED%^d%^BOLD%^s%^RESET%^.",
      ({"island","wooden island","chips","dust","vases","crystal chips","crystal dust"}) :
         "The wooden island is oval in shape and has a wide base, "+
         "the top overhanging it only slightly.  An eclective assortment "+
         "of vases in various sizes and colors hold different "+
         "grades of crystal fragments and dust, all of which are "+
         "used by psions in various ways - and some of which are "+
         "occasionally used as decoration by others.",
      ({"counter","varnished counter"}) : "The counter near the "+
         "western wall is the only object in the room to feature "+
         "straight lines.  It is rectangular in shape and gives "+
         "the shopkeeper a place to sort and package crystals.",
      ({"case","glass case"}) : "%^CYAN%^The glass display case "+
         "is dazzling, the exquisitely cut gems inside reflecting "+
         "light in a beautiful array.  You see the most expensive "+
         "gems inside, %^BOLD%^%^BLACK%^b%^BLUE%^l%^BLACK%^a%^BLUE%^"+
         "c%^BLACK%^k %^BLUE%^s%^BLACK%^t%^BLUE%^a%^BLACK%^r "+
         "%^BLUE%^s%^BLACK%^a%^BLUE%^p%^BLACK%^p%^BLUE%^h%^BLACK%^i"+
         "%^BLUE%^r%^BLACK%^e%^RESET%^%^CYAN%^ and %^YELLOW%^r%^BLACK%^u"+
         "%^RESET%^%^ORANGE%^t%^YELLOW%^i%^RESET%^%^ORANGE%^l"+
         "%^BOLD%^%^BLACK%^a%^YELLOW%^t%^RESET%^%^ORANGE%^e"+
         "%^YELLOW%^d %^BLACK%^q%^RESET%^%^ORANGE%^u%^YELLOW%^a"+
         "%^RESET%^%^ORANGE%^r%^BOLD%^%^BLACK%^t%^YELLOW%^z%^RESET%^.",
      ({"chests","locked chests"}) : "The chests below the shelves are "+
         "rectangular with rounded tops.  They are made of wood and "+
         "bound with iron, fastened carefully with iron locks."
   ]));
   set_exits(([
      "east" : ROOMS"psi_landing4"
   ]));
}

void reset(){
   ::reset();
   if(!present("corin"))
      find_object_or_load(MON"corin")->move(TO);
}