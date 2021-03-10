#include <std.h>
#include <move.h>

inherit ROOM;

int fruit;

void create()
{
    ::create();
    set_property("indoors", 1);
    set_property("light", 1);
    set_terrain(BUILT_TUNNEL);
    set_travel(PAVED_ROAD);
    set_name("Courtyard of Tenebrous");
    set_short("%^BOLD%^%^BLACK%^Courtyard of Tenebrous%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^Emerging from the suffocating " +
             "confines of the %^RESET%^%^GREEN%^forest%^BOLD%^%^BLACK%^ " +
             "you find yourself standing before the %^RESET%^%^CYAN%^cr" +
             "%^MAGENTA%^u%^CYAN%^mbled remains %^BOLD%^%^BLACK%^of a once " +
             "%^RESET%^%^MAGENTA%^m%^BOLD%^%^BLACK%^a%^RESET%^" +
             "%^MAGENTA%^ssive t%^BOLD%^%^BLACK%^e%^RESET%^%^MAGENTA%^" +
             "mp%^BOLD%^%^BLACK%^l%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^" +
             ".  The great courtyard is walled only by the %^RESET%^" +
             "%^GREEN%^forest%^BOLD%^%^BLACK%^ itself, which gives way " +
             "abruptly to the thick %^RESET%^%^GREEN%^grass%^BOLD%^" +
             "%^BLACK%^ and winding obs%^WHITE%^i%^BLACK%^d%^WHITE%^i" +
             "%^BLACK%^an paths. Several %^RESET%^%^BLUE%^dark streams " +
             "%^BOLD%^%^BLACK%^wind their way through this %^RESET%^" +
             "%^GREEN%^g%^MAGENTA%^a%^GREEN%^rd%^MAGENTA%^e%^GREEN%^n" +
             "%^BOLD%^%^BLACK%^ courtyard, intersecting at a central " +
             "ring that loops around a small %^RESET%^%^GREEN%^gr%^BOLD%^" +
             "%^BLACK%^o%^RESET%^%^GREEN%^ve%^BOLD%^%^BLACK%^.  At the " +
             "center of this %^RESET%^%^GREEN%^gr%^BOLD%^%^BLACK%^o" +
             "%^RESET%^%^GREEN%^ve %^BOLD%^%^BLACK%^encircled by dozens " +
             "of %^RESET%^%^CYAN%^ex%^MAGENTA%^o%^CYAN%^t%^BOLD%^" +
             "%^MAGENTA%^i%^RESET%^%^CYAN%^c fl%^MAGENTA%^o%^CYAN%^w" +
             "%^GREEN%^e%^CYAN%^r%^MAGENTA%^s %^BOLD%^%^BLACK%^is a " +
             "gnarled, leafless tree with solid black bark that bears " +
             "an oily bl%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^ck and " +
             "r%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^d fru%^RESET%^%^RED%^" +
             "i%^BOLD%^%^BLACK%^t.  %^RESET%^%^CYAN%^L%^MAGENTA%^u" +
             "%^CYAN%^m%^BOLD%^%^CYAN%^i%^RESET%^%^CYAN%^n%^MAGENTA%^o" +
             "%^CYAN%^us %^GREEN%^pl%^MAGENTA%^a%^CYAN%^nts %^BOLD%^" +
             "%^BLACK%^are scattered throughout the area, overgrowing " +
             "the twisting paths and bridges that once served to create " +
             "an intricate %^RESET%^%^RED%^web-like %^BOLD%^%^BLACK%^" +
             "network of light and comfort, but now only leave traces of " +
             "intermittent brilliance in the dark.  %^RESET%^%^GREEN%^G" +
             "%^MAGENTA%^a%^GREEN%^rd%^CYAN%^e%^GREEN%^ns %^BOLD%^" +
             "%^BLACK%^dot the landscape providing a splash of " +
             "%^RESET%^%^MAGENTA%^c%^CYAN%^o%^GREEN%^l%^CYAN%^o" +
             "%^MAGENTA%^r %^BOLD%^%^BLACK%^to the otherwise black " +
             "surroundings.  St%^WHITE%^a%^BLACK%^tues of all sorts " +
             "occupy these gardens, some still intact while others " +
             "have been shattered by fallen stone from the unseen " +
             "cavern ceiling above.  Their forms flow from feline " +
             "to humanoid and %^RESET%^%^RED%^menacing " +
             "%^BOLD%^%^BLACK%^to %^RED%^agonized%^BLACK%^, still " +
             "standing at watch over the ruins of the structure " +
             "that must once have dwarfed all else.  Steep steps ascend " +
             "to broad pillars that now lie shattered and broken, " +
             "their chunks of dark marble interspersed with brittle " +
             "shards of st%^RESET%^" +
             "%^MAGENTA%^a%^BOLD%^%^BLACK%^in%^RESET%^%^MAGENTA%^e" +
             "%^BOLD%^%^BLACK%^d gl%^RESET%^%^MAGENTA%^a%^BOLD%^" +
             "%^BLACK%^ss.%^RESET%^\n");
    set_smell("default", "%^MAGENTA%^You are surrounded by " +
              "the thick scent floral scent of the many gardens.%^RESET%^");
    set_listen("default", "%^MAGENTA%^You hear the rustling " +
               "of the trees and the gentle gurgling of the streams.%^RESET%^");
    set_items(([
                   ({ "gardens", "garden" }) : "%^GREEN%^The gardens are " +
                   "spread about the network of %^BOLD%^%^BLACK%^paths" +
                   "%^RESET%^%^GREEN%^ and %^BLUE%^streams%^GREEN%^, " +
                   "offering an e%^CYAN%^x%^GREEN%^o%^MAGENTA%^t%^GREEN%^" +
                   "ic blend of near unknown %^CYAN%^l%^MAGENTA%^u%^CYAN%^" +
                   "m%^BOLD%^%^CYAN%^i%^RESET%^CYAN%^n%^MAGENTA%^o%^CYAN%^" +
                   "us %^GREEN%^flora.  The softly %^CYAN%^gl%^MAGENTA%^o" +
                   "%^BOLD%^%^CYAN%^w%^RESET%^%^MAGENTA%^i%^CYAN%^ng " +
                   "%^GREEN%^bulbs of these exquisite flowers serves to " +
                   "cast the entire courtyard into a %^MAGENTA%^surreal " +
                   "%^GREEN%^and %^CYAN%^int%^MAGENTA%^o%^CYAN%^x" +
                   "%^MAGENTA%^i%^CYAN%^cating l%^BOLD%^%^MAGENTA%^i" +
                   "%^RESET%^%^CYAN%^ght%^GREEN%^.%^RESET%^",
                   ({ "grove", "tree" }) : "%^BOLD%^%^BLACK%^This small grove " +
                   "contains a smaller garden of d%^RESET%^%^CYAN%^a" +
                   "%^BOLD%^%^BLACK%^rkly c%^RESET%^%^MAGENTA%^o%^BOLD%^" +
                   "%^BLACK%^lor%^RESET%^%^CYAN%^e%^BOLD%^%^BLACK%^d " +
                   "fl%^RESET%^%^MAGENTA%^o%^BOLD%^%^BLACK%^ra.  These " +
                   "however serve only as a momentary distraction from " +
                   "the gnarled, leafless tree which sprouts from the " +
                   "center, its twisted limbs bearing an oily black " +
                   "fruit.  The same oily ichor seems to %^RESET%^" +
                   "%^RED%^bleed %^BOLD%^%^BLACK%^from the bark of the " +
                   "tree itself.%^RESET%^",
                   "statues" : "%^BOLD%^%^BLACK%^The gardens are filled " +
                   "with demonic effigies, feline representations, and " +
                   "cowled humanoids with sorrowful expressions " +
                   "reaching towards the tree in the center of the " +
                   "grove.  Some are still intact, while others are " +
                   "damaged or entirely shattered upon the ground.%^RESET%^",
                   "forest" : "%^GREEN%^The dense vegetation cuts off " +
                   "abruptly at the edge of the courtyard, held back " +
                   "by no wall yet seemingly unwilling to grow any " +
                   "closer to the temple on the precipice.  Even " +
                   "the snagging limbs refuse to grow out across " +
                   "the edges of the temple grounds.%^RESET%^",
               ]));
    set_exits(([
                   "northeast" : "/d/magic/temples/shar_path5",
               ]));
    fruit = 5;
}

void init()
{
    ::init();
    add_action("pick_fruit", "pick");
}

int pick_fruit(string str)
{
    object obj;
    if (!str) {
        tell_object(TP, "Pick what?");
        return 1;
    }
    if (str != "fruit" && str != "dark fruit") {
        return 0;
    }
    if (fruit > 0) {
        tell_object(TP, "%^BOLD%^%^BLACK%^You pick one of the " +
                    "fru%^RED%^i%^BLACK%^ts from the tree.%^RESET%^");
        tell_room(TO, "%^BOLD%^%^BLACK%^" + TPQCN + " picks one of " +
                  "the fru%^RED%^i%^BLACK%^ts from the tree.%^RESET%^", TP);
        obj = new("/d/magic/temples/misc/shar_fruit");
        if (obj->move(TP) != MOVE_OK) {
            tell_object(TP, "You drop it as fast as you pick it!");
            tell_room(TO, "" + TPQCN + " drops it!", TP);
            obj->move(ETP);
        }
        fruit--;
        return 1;
    }else {
        tell_object(TP,"%^BOLD%^%^BLACK%^A nearby garden keeper "+
           "waves you away muttering about that being enough for "+
           "today%^RESET%^.");
           tell_room(TO,"%^BOLD%^%^BLACK%^As "+TPQCN+" tries to pick "+
           "a fruit from the tree, a nearby gardener waves "+TP->QO+" "+
           "away, muttering about that being enough for today.",TP);
        return 1;
    }
}

/*
   %^BOLD%^NOTE:%^RESET%^ Nightfall has requested that the fruit be a poison that can be applied to weapons as well.  No decision has been reached yet, so I'm leaving this here for future reference in case it does go in.

   apply fruit to weapon: %^BOLD%^%^BLACK%^You deftly swipe the fruit across your blade coating it thoroughly in the oily black sap.%^RESET%^

   Others see: %^BOLD%^%^BLACK%^(Whoever) deftly swipes the fruit across the surface of his/her blade, coating it thoroughly in the oily black sap.%^RESET%^

 * poison* *random lethality*
   ~Circe~ 9/11/05
 */
