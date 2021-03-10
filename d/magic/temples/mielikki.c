//by Circe 8/29/04 - desc provided by Lukas
#include <std.h>
inherit ROOM;

void create(){
   ::create();
   set_terrain(RUINS);
   set_travel(FOOT_PATH);
   set_light(2);
   set_indoors(0);
   set_name("Base of a giant oak");
   set_short("%^GREEN%^Base of a giant o%^RESET%^%^YELLOW%^a%^RESET%^%^GREEN%^k%^RESET%^");
   set_long("%^GREEN%^Utterly dwarfing the rest of the grove is the "+
         "enormous o%^RESET%^%^YELLOW%^a%^RESET%^%^GREEN%^k that stands "+
         "several hundred feet tall, the top of its leafy bows remains "+
         "hidden from all.  An intoxicating%^RESET%^ %^WHITE%^fog"+
         "%^RESET%^ %^GREEN%^lingers around the base of the great "+
         "tree, obscuring the soft ground from view.  The great tree "+
         "seems to spread its great limbs over the grove, offering "+
         "fair comfort and refuge from the elements.  High in its "+
         "leafy arms%^RESET%^ %^BLUE%^bl%^RESET%^%^BOLD%^%^WHITE%^u"+
         "%^RESET%^%^BLUE%^e lig%^RESET%^%^BOLD%^%^WHITE%^h%^RESET%^"+
         "%^BLUE%^ts%^RESET%^ %^GREEN%^dance in and about the foliage, "+
         "remaining safe from ground-dwelling visitors and guests.  "+
         "Movement in the tree indicates an abundance of life calling "+
         "its boughs home.  Birds fly from its limbs, squirrels dance "+
         "about the branches, and occasionally the flash of a beguiling "+
         "feminine face can be seen.  Even the tree itself creaks and "+
         "moans as the wind causes it to sway to and fro.  Tucked "+
         "into the massive root system of the tree is the small"+
         "%^RESET%^ %^BOLD%^%^WHITE%^altar,%^RESET%^ %^GREEN%^though "+
         "found in some disrepair.  I%^RESET%^%^RED%^v%^RESET%^"+
         "%^GREEN%^y winds its way through cracked stone and moss "+
         "blends in with the base of the altar and the ground, almost "+
         "as if absorbed into nature itself.%^RESET%^\n");
   set_items(([
         ({"oak","tree"}) : "%^GREEN%^This enormous tree looms "+
            "overhead, casting its watchful gaze across the grove%^RESET%^",
         "altar" : "%^BOLD%^%^WHITE%^The altar has obviously seen better "+
            "days, now cracked and covered with%^RESET%^ %^GREEN%^i%^RESET%^"+
            "%^RED%^v%^RESET%^%^GREEN%^y%^RESET%^ %^BOLD%^%^WHITE%^and"+
            "%^RESET%^ %^GREEN%^mo%^RESET%^%^BLUE%^s%^RESET%^%^GREEN%^s,"+
            "%^RESET%^ %^BOLD%^%^WHITE%^though it does not seem out of "+
            "place in this stronghold of nature.%^RESET%^",
         ({"lights","blue lights"}) : "%^BLUE%^Strange blue lights "+
            "dance around the leafy boughs of the tree, but you are "+
            "unsure from such a distance exactly what they are...%^RESET%^",
         "ivy" : "%^GREEN%^The creeping ivy has snaked its way around "+
            "the old stone ruins.%^RESET%^",
   ]));
   set_smell("default","%^BOLD%^%^BLUE%^The%^RESET%^ %^BOLD%^"+
         "%^WHITE%^fog%^RESET%^ %^BOLD%^%^BLUE%^seems scented with "+
         "the intoxicating smell of the%^RESET%^ %^GREEN%^gardens.%^RESET%^");
   set_listen("default","%^GREEN%^A strange beautiful song fills "+
         "the air as Dryads sing in the tops of the trees.%^RESET%^");
   set_exits(([
      "north":"/d/magic/temples/mielikki_center"
   ]));
}

void reset(){
   ::reset();
   if(base_name(TO) == "/d/magic/temples/mielikki"){
      switch(random(7)){
         case 0:  tell_room(TO,"%^GREEN%^The flash of a feminine "+
                   "face and swish of long green hair startles you "+
                   "momentarily.%^RESET%^");
                  break;
         case 1:  tell_room(TO,"%^RED%^A flock of birds take flight "+
                   "from a nearby tree before circling and landing "+
                   "once more.  Crazy birds.%^RESET%^");
                  break;
         case 2:  tell_room(TO,"%^BLUE%^The Dryads singing picks up, "+
                   "floating through the air like an intoxicating "+
                   "scent.%^RESET%^");
                  break;
         case 3:  tell_room(TO,"%^YELLOW%^A small group of druids "+
                   "make their way quietly through the grove.%^RESET%^");
                  break;
         case 4:  tell_room(TO,"%^GREEN%^A group of rowdy rangers "+
                   "wander through the grove, laughing amongst "+
                   "themselves.%^RESET%^");
                  break;
         case 5:  tell_room(TO,"%^RED%^A small cluster of animals dart "+
                   "across your path.%^RESET%^");
                  break;
         case 6:  tell_room(TO,"%^YELLOW%^The giant oak groans, casting "+
                    "a shadow across the grove.%^RESET%^");
                  break;
         default:  break;
      }
   }
}
