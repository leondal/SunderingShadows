//leader3.c
#include <std.h>
#include "../../kildare.h"

inherit TBUILD;

void create()
{
   ::create();
   set_short("A Sitting Room");
   set_long(
      "%^RESET%^%^MAGENTA%^This small room has deep brown panelling that "+
      "seems to absorb much of the light provided by a roaring fireplace "+
      "on the eastern wall.  Two comfortable-looking armchairs sit on "+
      "either side of the fireplace, bracing a large couch.  All are "+
      "arranged so that those sitting may easily look at each other "+
      "and converse.  The stone mantle above the fireplace supports two "+
      "iron braziers that burn with the fragrant scent of lavander.  "+
      "A long table dominates the southern portion of the room and "+
      "seems at odds with the relaxed atmosphere of the rest of the "+
      "chamber.  Various bottles and jars hold strange-looking materials, "+
      "and pouches of dust are mingled among a set of scales.  Bits of "+
      "leather and a whetstone round out the strange assortment of "+
      "supplies there."

   );
   set_items(([
      (({"panelling","walls","wall"})) : "Though the walls themselves are "+
         "presumably made of the same stone as the outside of the building, "+
         "they have been covered with deep brown wooden panelling.  The "+
         "room seems darker, and yet somehow more cozy with the enveloping "+
         "browns.",
      (({"fireplace","fire place","light"})) : "The flickering light in "+
         "the room is provided by the roaring fireplace set into the "+
         "eastern wall.  Rounded stones have been bound together with "+
         "mortar to form a flat mantle above the fireplace, upon which "+
         "rests two braziers burning with lavander incense.",
      (({"chairs","armchairs"})) : "%^MAGENTA%^Each of the armchairs is made of dark "+
         "wood covered with deep burgandy fabric.  They are well-cushioned "+
         "and would be a comfortable place to rest while engaging in "+
         "conversation or just watching the fire.",
      (({"couch","large couch"})) : "The long couch facing the fireplace "+
         "is centered between the two chairs.  Spots of the gray-colored "+
         "fabric cushions are well-worn, suggesting that the couch is "+
         "often used.",
      (({"braziers","iron braziers","incense"})) : "The ornate iron braziers "+
         "on the mantle piece hold a heavily-frangranced lavander incense "+
         "that fills the room with its scent.  Each brazier is formed into "+
         "the shape of an eagle with its wings outstretched.",
      (({"table","long table"})) : "The surface of the long wooden table "+
         "in the southern part of the room is covered almost completely with "+
         "many strange items.  Bottles, jars, pouches, and other implements "+
         "are strewn around the base of a large set of scales.",
      (({"jars","bottles","pouches"})) : "The many jars and bottles hold "+
         "what looks to be spell components in their raw state.  Foul-smelling "+
         "powders and live insects are mixed with animal skins and leathers.",
      (({"leather","whetstone","bits of leather"})) : "Unlike the jars and "+
         "things holding spell components, a few piles of materials seem "+
         "to be used in crafting weapons.  Like the components, however, "+
         "there seems to be little organization discernable.",
      (({"scales","set of scales"})) : "The expensive set of scales in the "+
         "center of the table is made of a silver metal and balanced perfectly.  "+
         "It is most likely used in the creation of refined components, as "+
         "well as to perhaps make alchemical substances."
      ]));
   set_smell("default","The scent of lavander is almost overpowering.");
   set_listen("default","The quiet crackle of the flames is in the air.");

   set_exits(([
      "west" : TROOMS"leader"
      ]));
   set_door("cypress door",TROOMS"leader","west",0);
   set_door_description("cypress door","A smooth cypress door with a "+
      "simple brass doorknob.");
}

void reset()
{
        ::reset();
        if(!present("guyon")) {
                new(MON"guyon")->move(TO);
        }
}

void init() {
        ::init();
        add_action("lay","lay");
        add_action("sit","sit");
}

int sit(string str)
{
        if(str == "couch") {
                tell_object(TP,"%^ORANGE%^You sink down into the comfortable couch and look "+
                   "into the fire.");
                tell_room(ETP,"%^ORANGE%^"+TPQCN+" sinks down into the couch and stares "+
                   "at the fireplace.",TP);
                return 1;
        }
        if(str == "chair" || str == "armchair") {
                tell_object(TP,"%^MAGENTA%^You settle into an armchair before the fireplace.");
                tell_room(ETP,"%^MAGENTA%^"+TPQCN+" sits down in one of the armchairs "+
                   "in front of the fireplace.",TP);
                return 1;
        }
}
int lay(string str)
{
        if(str == "couch") {
                tell_object(TP,"%^RESET%^%^ORANGE%^You flop down onto the comfortable"+
                " couch and feel a little drowsy.");
                tell_room(ETP,"%^RESET%^%^ORANGE%^"+TP->query_cap_name()+" flops "+
                "down onto the plush couch and looks sleepy.",TP);
                return 1;
        }
}
