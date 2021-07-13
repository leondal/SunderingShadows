#include <std.h>
#include "koenig.h"
inherit CROOM;

void create(){
   if(random(5) == 3){
     set_monsters(({TMONDIR +"ogrew.c"}),({2}));
     set_repop(50);
   }

::create();
  set_property("indoors",1);
  set_property("light",1);
  set_travel(SLICK_FLOOR);
  set_terrain(NAT_CAVE);
  set_name("A dank cavern");
  set_short("%^RESET%^%^BLUE%^%^A %^BOLD%^%^BLACK%^dark %^RESET%^%^BLUE%^cavern%^RESET%^");
  set_long(""+query_short()+"\n%^RESET%^%^BLUE%^These caves look as though they"
" have been crudely dug out of the very mountain itself."
" Jagged edges can just be seen in the %^BOLD%^%^BLACK%^dark"
" shadows %^RESET%^%^BLUE%^that line the edges of this system"
" and flecks of %^RED%^dried blood %^BLUE%^seem to dapple the"
" walls, floor, and somehow even the ceiling here. Vermin of all"
" sorts crawl along the floor, darting in and out of cracks, under"
" rocks, and any other dark place that they might find shelter in."
"%^RESET%^\n");
  set_smell("default","It smells foul.%^RESET%^");
  set_listen("default","Your footsteps echo through the caves.");
  set_items(([
     ({"floor","cave floor"}):"%^BOLD%^%^BLACK%^The cave floor is rocky and uneven. Puddles of water fill small holes in the rocks and %^RESET%^%^RED%^dried blood %^BOLD%^%^BLACK%^seems to be splattered everywhere.%^RESET%^",
     ({"blood","dried blood"}):"%^RESET%^%^RED%^Dried blood can be seen lining the walls, floor and even the ceiling of this cave. The way that it is splattered lends you to believe that something or someone met a horrible end here.%^RESET%^",
     ({"shadow","shadows"}):"%^BOLD%^%^BLACK%^Shadows line the edges of the cave, making it difficult to see what may be hiding there.",
      "vermin":"%^ORANGE%^All sorts of creatures crawl around the floor and walls here, their quick movements making it almost impossible to determine what exactly they are.%^RESET%^",
      "cracks":"%^RESET%^Cracks line the floor and walls here, making a good place for small creatures to hide.",
      ({"water","puddles of water"}):"%^BLUE%^Puddles of stagnant, smelly water fill small holes in the cave floor.",
      "rocks":"%^RESET%^Rocks and large boulders of various sizes lay carelessly about the cave.",
      ({"walls","cave walls"}):"%^RESET%^%^BLUE%^The cave walls look as though they were crudely dug, claw marks can still be seen deep withen the jagged rock walls, and tufts of %^ORANGE%^fur %^BLUE%^can even be seen stuck to some of the sharper edges.",
      "ceiling":"%^BOLD%^%^BLACK%^It is difficult to see the ceiling from here, but wherever the %^RESET%^light %^BOLD%^%^BLACK%^hits, you notice %^RESET%^%^RED%^dried blood.%^RESET%^",
      ({"fur","tufts of fur"}):"RESET%^%^ORANGE%^A few tufts of smelly fur can be seen stuck to some of the sharper edges of rock in the cave.%^RESET%^",
]));
   set_search("shadows","%^BOLD%^%^BLACK%^You sigh in relief as you search the shadows and find nothing.%^RESET%^");
}

