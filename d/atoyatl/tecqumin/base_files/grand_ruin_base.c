#include <std.h>
#include <move.h>
#include "../tecqumin.h"


inherit JUNG_ROOM + "jung_base.c";
string av_dir;
string long_desc();
string hut_desc();


void create() {
  ::create();
  set_long((:TO, "long_desc":));
  add_item( ({"remains", "overgrown remains", "huts", "large huts", 
    "ruined huts"}), (: TO,"hut_desc":));
  add_item( ({"avenue", "broad avenue",}), "The avenue is stone"
  +" paved and mostly intact, despite the encroaching jungle"
  +" foliage. It leads " + av_dir + ".");
}

string base_desc () { 
  return ::base_desc()+"The overgrown remains of a grand district of"
  +" an ancient city are found within the jungle here. The ruined"
  +" bases and lower walls of large huts are widely spaced among the"
  +" foliage, with a broad avenue running "+ av_dir +" between them.";
}

string hut_desc (){
  return "Little more than foundations and a few scraps of gray"
  +" stone walls remain within the rich growth of the jungle foliage,"
  +" but even so you can see that these structures were large and"
  +" only really merit the name ?hut? because they have the same"
  +" basic circular shape, with slightly outward-sloping walls, as"
  +" the smaller buildings to be found elsewhere in the lost city";
}

