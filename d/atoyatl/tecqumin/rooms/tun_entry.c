#include <std.h>
#include <terrain.h>
#include "/d/atoyatl/tecqumin/tecqumin.h"
inherit J_MAZE;

string plant, identifier;

void create() {
  int r;
  string desc, * specifics, * identifiers;
  specifics = ({});
  identifiers = ({});
  ::create();
  specifics =({"an evergreen %^GREEN%^orc's horn plant%^RESET%^ with"
            +" long, strap-shaped leaves and rounded umbels of"
            +" %^BLUE%^deep bl%^RESET%^%^MAGENTA%^u%^RESET%^%^BLUE%^e"
            +"%^RESET%^, trumpet-shaped flowers",
             "a vigorous growth of Dreth's fingers, with massive,"
            +"%^GREEN%^sh%^BOLD%^%^WHITE%^i%^RESET%^%^GREEN%^ny,"
            +" %^BOLD%^%^GREEN%^lush green%^RESET%^, rounded leaves",
             "an attractive %^GREEN%^shrub%^RESET%^ covered with"
             +" %^MAGENTA%^purple%^RESET%^ berries that seem to be"
             +" attracting large numbers of birds",
              "a slow growing succulent plant with a swollen,"
             +" contorted base and an abundance of %^BOLD%^%^RED%^c"
             +"%^MAGENTA%^a%^RED%^rm%^WHITE%^i%^RED%^ne-r%^MAGENTA%^o"
             +"%^RED%^se%^RESET%^ flowers.",
              "a three foot tall cycad with long, arching"
             +" %^BOLD%^%^BLUE%^bl%^GREEN%^u%^BLUE%^e-%^GREEN%^gr"
             +"%^BLUE%^ee%^GREEN%^n%^RESET%^ leaflets and attractive"
             +" %^ORANGE%^rusty brown%^RESET%^ cones.",
              "a 'horn of plenty', a striking plant with"
             +" %^BOLD%^%^WHITE%^fragrant white%^RESET%^ trumpet shaped"
             +" flowers held upright above %^BOLD%^%^BLUE%^bl%^GREEN%^u"
             +"%^BLUE%^e-%^GREEN%^gr%^BLUE%^ee%^GREEN%^n%^RESET%^"
             +" foliage.",
              "a very small, shrubby tree with large pendulous flowers"
             +" almost ten inches in length. The flowers are tubular, and"
             +" %^BOLD%^%^RED%^br%^RESET%^%^RED%^i%^BOLD%^%^RED%^ght"
             +" r%^RESET%^%^RED%^e%^BOLD%^%^RED%^d %^RESET%^at the mouth,"
             +" fading to %^BOLD%^%^YELLOW%^yellow%^RESET%^ at the base."
             +" It has long, oval shaped leaves.",
              "a colocasia with a %^BOLD%^%^BLACK%^d%^RESET%^%^MAGENTA%^"
             +"a%^BOLD%^%^BLACK%^rk %^RESET%^%^MAGENTA%^p%^BOLD%^"
             +"%^BLACK%^u%^RESET%^%^MAGENTA%^rple%^RESET%^ stem, tending"
             +" towards black. The leaf ribs are deepest %^BLUE%^m%^BOLD%^"
             +"%^BLACK%^i%^RESET%^%^BLUE%^dn%^BOLD%^%^BLACK%^i%^RESET%^"
             +"%^BLUE%^ght bl%^BOLD%^%^BLACK%^u%^RESET%^%^BLUE%^e"
             +"%^RESET%^.",
              "a '%^BOLD%^%^BLACK%^Black Knight%^RESET%^' canna plant,"
             +" gorgeous in both bloom and foliage.  The leaves are"
             +" %^GREEN%^str%^BOLD%^%^GREEN%^i%^RESET%^%^GREEN%^p%^BOLD%^"
             +"%^GREEN%^e%^RESET%^%^GREEN%^d%^RESET%^, cast very dark and"
             +" the large %^BOLD%^%^RED%^bright red fl%^RESET%^%^RED%^o"
             +"%^BOLD%^%^RED%^wers%^RESET%^ are quite stunning."});
  identifiers = ({"orc's horn plant", "Dreth's fingers", "shrub", "succulent plant",
              "cycad", "horn of plenty", "shrubby tree", "colocasia", "Black Knight"});
  r = random(sizeof(specifics));
  plant = "In amongst the great %^ORANGE%^boles%^RESET%^ of ancient"
          +" trees, %^BOLD%^%^GREEN%^plants%^RESET%^ of all sizes and"
          +" shapes flourish in the fertile soil of the jungle. Your eyes"
          +" light upon " + specifics[r];
  identifier = identifiers[r];
  set_items(([  ({"plants", "plant", identifier}) : (plant_desc()) ,
                ({"insects", "insect"}) : (insect_desc()) ]));

  set_search(identifier, (:TO, "find_entrance":));
  base_exits = ([ "down": ROOMS + "tunexit" ]);
  set_basic_exits();
  set_invis_exits(({"down"}));
}

string query_plant(){
  return plant;
}

string query_identifier(){
  return identifier;
}

void reset(){
  ::reset();
  if (!random(3)){
    set_invis_exits(({"down"}));
  }
}

int check_maze(){
  ::check_maze("/realms/lujke/tecqumin/jungleh/rooms/j_maze");
}

void on_enter(){
  object mazeroom1, mazeroom2;
  string *exits;
  mazeroom1 = find_object_or_load(JUNG_ROOM8 + "j_maze0.c");
  set_basic_exits();
  if (sizeof(query_exits())<2){
    BUILDER->restore_exits(TO);
  }
  if (sizeof(query_exits())<2){
    mazeroom1->remove_maze();
    mazeroom1->make_maze();
  }
  set_door("trapdoor", ROOMS + "tunexit","down",0);
}

void init(){
  ::init();
}

void find_entrance(){
  tell_object(TP, "You discover a trapdoor beneath the " + identifier + ".");
  tell_room(TO, TPQCN + " discovers a trapdoor beneath the " + identifier + ".", TP);

  place_exit();
}

void place_exit(){
  remove_invis_exit("down");
}

string plant_desc(){
  string desc;
  desc = plant;
  return desc;
}
