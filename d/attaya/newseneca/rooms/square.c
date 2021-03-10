//square.c ~Circe~ 11/7/07
//Town square for new Seneca
#include <std.h>
#include "../seneca.h"

inherit ROOM;

void create(){
   ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_name("Seneca Square");
   set_short("Seneca Square");
   set_property("light",3);
   set_long("%^BOLD%^%^WHITE%^Town Square, Seneca%^RESET%^\n"+
      "Here at the junction of %^YELLOW%^Sol Boulevard%^RESET%^ "+
      "and %^BOLD%^%^CYAN%^Viento Lane%^RESET%^ is the gorgeous town center of "+
      "%^BOLD%^Seneca%^RESET%^.  A huge, circular %^BOLD%^fountain %^RESET%^"+
      "in the middle of the square sprays jets of %^BOLD%^%^CYAN%^water %^RESET%^"+
      "high into the air, with the center spout rising well over fifteen "+
      "feet.  Spreading from this centerpiece are concentric "+
      "circles of smaller %^BOLD%^%^CYAN%^sprays%^RESET%^, with the "+
      "rings of water growing successively shorter until the outer ring "+
      "reaches only a foot.  Bounding this %^BOLD%^fountain %^RESET%^"+
      "is a ledge made from smooth %^ORANGE%^r%^RED%^i%^RESET%^v%^ORANGE%^"+
      "er %^RED%^s%^RESET%^to%^ORANGE%^n%^RED%^e%^ORANGE%^s %^RESET%^"+
      "edged with a riot of %^BOLD%^%^GREEN%^tropical %^RED%^f%^CYAN%^l"+
      "%^BLUE%^o%^YELLOW%^w%^GREEN%^e%^WHITE%^r%^MAGENTA%^s%^RESET%^.  The "+
      "ledge is brightened by small magical %^BOLD%^globes of light "+
      "%^RESET%^that are space at intervals along its suface.  An "+
      "assortment of brilliant %^ORANGE%^orange anthurium%^RESET%^, "+
      "%^BOLD%^%^RED%^tor%^WHITE%^c%^RED%^h gin%^WHITE%^g%^RED%^er%^RESET%^, "+
      "%^YELLOW%^birds of paradise%^RESET%^, and pristine %^BOLD%^"+
      "calla lilies %^RESET%^is sprinkled among a field of %^BOLD%^"+
      "%^MAGENTA%^p%^WHITE%^ink-%^MAGENTA%^t%^WHITE%^ipped "+
      "%^MAGENTA%^p%^WHITE%^lumeria%^RESET%^, luminous %^BOLD%^%^BLUE%^b"+
      "%^RESET%^%^CYAN%^l%^BOLD%^%^BLUE%^u%^RESET%^%^CYAN%^e %^BOLD%^"+
      "%^BLUE%^o%^RESET%^%^CYAN%^r%^BOLD%^%^BLUE%^c%^RESET%^%^CYAN%^h"+
      "%^BOLD%^%^BLUE%^i%^RESET%^%^CYAN%^d%^RESET%^, "+
      "and sprawling %^MAGENTA%^purple bougainvillea%^RESET%^.  "+
      "Several curved %^BOLD%^%^BLACK%^wrought-iron benches %^RESET%^are placed "+
      "a few feet away from the %^GREEN%^flowerbed%^WHITE%^, and citizens of Seneca "+
      "can often be found sitting here, engaging in idle chat or reading "+
      "%^ORANGE%^books%^RESET%^.  From this vantage point, you can see "+
      "four small %^GREEN%^parks%^RESET%^, one in each ordinal direction, "+
      "each of which houses a large %^BOLD%^statue%^RESET%^.  The "+
      "%^ORANGE%^square %^RESET%^seems to "+
      "be a relatively quiet place amidst the bustle of this prosperous city.\n");
   set_smell("default","The clean scent of the ocean rises on the breeze.");
   if(query_night() == 1){
      set_listen("default","You can faintly hear the crashing of "+
         "waves on the shore in the peace of night.");
   }else{
      set_listen("default","The faint humming of a busy day in Seneca can be heard.");
   }
   set_items(([
      ({"street","boulevard","cobblestone","cobblestones","thoroughfare","square"}) : 
         "This %^ORANGE%^co%^RED%^b%^ORANGE%^"+
         "ble%^RESET%^s%^ORANGE%^to%^RED%^n%^ORANGE%^e square%^RESET%^ "+
         "is created from stones in shades of "+
         "%^ORANGE%^brown%^RESET%^, %^RED%^red%^RESET%^, and "+
         "white, which are arranged to form a pattern of "+
         "zig-zagging rings converging on the fountain in the center, "+
         "drawing the eye to the obvious focal piece that dominates "+
         "the square.",
      ({"fountain","water","sprays","jets","spout","jets of water"}) : "%^BOLD%^"+
         "The impressive fountain commands the center of the town square, "+
         "spraying %^CYAN%^crystalline water %^WHITE%^high into the "+
         "air.  The concentric circles offer a pleasing appearance without "+
         "relying on statuary or other ornamentation.  The highest spout "+
         "rises from the center, creating a cascading effect as the "+
         "rings move outward.%^RESET%^",
      ({"ledge","stones","river stones"}) : "The ledge is crafted from "+
         "river stones echoing the colors of the cobblestone streets.  "+
         "Each individual stone has been sliced to produce a smooth "+
         "top and then rearranged in a pattern of colorful stones.",
      ({"flowers","tropical flowers","flowerbed"}) : "%^GREEN%^The %^BOLD%^tropical "+
         "%^RED%^f%^CYAN%^l%^BLUE%^o%^YELLOW%^w%^GREEN%^e%^WHITE%^r"+
         "%^MAGENTA%^b%^WHITE%^e%^RED%^d %^RESET%^%^GREEN%^seems overflowing "+
         "with greenery, a riot of leaves and blossoms that threatens "+
         "to overwhelm the senses.  Graceful %^MAGENTA%^butterflies "+
         "%^GREEN%^dance among the flowers, adding yet another touch "+
         "of color.%^RESET%^",
      ({"anthurium","orange anthurium"}) : "%^ORANGE%^Characterized by "+
         "a large, heart-shaped flower of vibrant orange, anthurium "+
         "plants are spread throughout the flowerbed.%^RESET%^",
      ({"ginger","torch ginger"}) : "%^BOLD%^%^RED%^Named appropriately, "+
         "the torch ginger is a clumping flower that resembles a red "+
         "torch of clustered petals edged in %^YELLOW%^yellow%^RED%^.  "+
         "Not a true torch ginger, which can reach heights of fifteen "+
         "feet, this is a miniature variety grown "+
         "carefully by the gardeners of Seneca.%^RESET%^",
      ({"bird of paradise","birds of paradise"}) : "%^GREEN%^A relative "+
         "of the banana plant, the bird of paradise gets its name from "+
         "its close resemblance to a %^YELLOW%^bird in flight%^RESET%^"+
         "%^GREEN%^.  This small version features %^ORANGE%^bright orange "+
         "%^GREEN%^flowers with %^BOLD%^%^BLUE%^blue tongues%^RESET%^"+
         "%^GREEN%^.%^RESET%^",
      ({"calla lily","calla lilies"}) : "%^BOLD%^Each calla lily "+
         "has a waxy, curved flower that spirals around a "+
         "%^YELLOW%^golden center%^WHITE%^.%^RESET%^",
      ({"plumeria","pink-tipped plumeria"}) : "%^BOLD%^Each plumeria "+
         "blossom is a spectacle in itself - five rounded petals "+
         "%^YELLOW%^yellow %^WHITE%^in the center turning to a "+
         "flawless white and ending with a %^MAGENTA%^pink "+
         "edge %^WHITE%^completely encircling the petal.  They have "+
         "the most amazing fragrance - a mix of cocoa butter and "+
         "cinnamon!%^RESET%^",
      ({"orchid","blue orchid"}) : "%^BOLD%^%^BLUE%^Five wide, fanning "+
         "petals of a radiant blue make up each pretty orchid.  The "+
         "blue is broken by tiny %^WHITE%^white dots %^BLUE%^that "+
         "provide a pleasant contrast.%^RESET%^",
      ({"bougainvillea","purple bougainvillea"}) : "%^GREEN%^Trained "+
         "into a ground cover, the bougainvillea has tiny, heart-shaped "+
         "%^BOLD%^leaves %^RESET%^%^GREEN%^with drip tips similar to "+
         "ivy leaves.  The plant is alive with clusters of small "+
         "%^MAGENTA%^purple flowers %^GREEN%^that cascade over the "+
         "edge of the flowerbed.%^RESET%^",
      ({"bench","benches","wrought-iron benches","wrought-iron bench"}) :
         "%^BOLD%^%^BLACK%^The wrought-iron benches are a deep black, "+
         "each with a scalloped back decorated in a triple knot "+
         "pattern.  The benches have low arms and wide bases, making "+
         "them a comfortable place for people to rest during a busy "+
         "day.%^RESET%^",
      ({"park","parks","statue","statues"}) : "In each of the four ordinal "+
         "directions, you see a small park that has its own benches and "+
         "flowers.  The centerpiece of each park is a monument "+
         "you could probably go take a closer look at."
   ]));
   set_exits(([
      "north" : ROOMS"skyline43",
      "south" : ROOMS"skyline44",
      "west" : ROOMS"viento53",
      "east" : ROOMS"viento54",
      "northwest" : ROOMS"monument1",
      "northeast" : ROOMS"monument2",
      "southeast" : ROOMS"monument3",
      "southwest" : ROOMS"monument4"
   ]));
}

void reset(){
   ::reset();
   if(!present("ring of lights")) new(OBJ"light_ring")->move(TO);
}