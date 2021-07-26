/*
  Dark Courtyard
  
  Temple of Ashra
  Descriptions by Balur/Faceless
  
  -- Tlaloc --
*/

#include <std.h>
#include <move.h>

inherit "/std/templemisc";

int fruit;

void create()
{
    ::create();
    set_property("indoors",1); 
    set_property("light",0);
    set_temple("ashra");
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_light(1);
    set_name("Dark Courtyard"); 
    set_short("%^BOLD%^%^BLACK%^Dark Courtyard%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^Emerging from the suffocating confines of the %^RESET%^%^GREEN%^forest%^BOLD%^%^BLACK%^ you find yourself standing before the %^RESET%^%^CYAN%^aw%^MAGENTA%^i%^CYAN%^ng majesty %^BOLD%^%^BLACK%^of a %^RESET%^%^MAGENTA%^m%^BOLD%^%^BLACK%^a%^RESET%^%^MAGENTA%^ssive t%^BOLD%^%^BLACK%^e%^RESET%^%^MAGENTA%^mp%^BOLD%^%^BLACK%^l%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^. The great courtyard is walled only by the %^RESET%^%^GREEN%^forest%^BOLD%^%^BLACK%^ itself, which gives way abruptly to the thick %^RESET%^%^GREEN%^grass%^BOLD%^%^BLACK%^ and winding obs%^WHITE%^i%^BLACK%^d%^WHITE%^i%^BLACK%^an paths. Several %^RESET%^%^BLUE%^dark streams %^BOLD%^%^BLACK%^wind their way through this %^RESET%^%^GREEN%^g%^MAGENTA%^a%^GREEN%^rd%^MAGENTA%^e%^GREEN%^n%^BOLD%^%^BLACK%^ courtyard, intersecting at a central ring that loops around a small %^RESET%^%^GREEN%^gr%^BOLD%^%^BLACK%^o%^RESET%^%^GREEN%^ve%^BOLD%^%^BLACK%^. At the center of this %^RESET%^%^GREEN%^gr%^BOLD%^%^BLACK%^o%^RESET%^%^GREEN%^ve %^BOLD%^%^BLACK%^encircled by dozens of %^RESET%^%^CYAN%^ex%^MAGENTA%^o%^CYAN%^t%^BOLD%^%^MAGENTA%^i%^RESET%^%^CYAN%^c fl%^MAGENTA%^o%^CYAN%^w%^GREEN%^e%^CYAN%^r%^MAGENTA%^s %^BOLD%^%^BLACK%^is a gnarled, leafless tree with solid black bark that bears an oily bl%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^ck and r%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^d fru%^RESET%^%^RED%^i%^BOLD%^%^BLACK%^t. Benches and %^RESET%^%^CYAN%^l%^MAGENTA%^u%^CYAN%^m%^BOLD%^%^CYAN%^i%^RESET%^CYAN%^n%^MAGENTA%^o%^CYAN%^us %^GREEN%^pl%^MAGENTA%^a%^CYAN%^nts %^BOLD%^%^BLACK%^are scattered throughout the area alongside the twisting paths and bridges that cross over the %^RESET%^%^BLUE%^streams%^BOLD%^%^BLACK%^ to create an intricate %^RESET%^%^RED%^web-like %^BOLD%^%^BLACK%^network of light and comfort. %^RESET%^%^GREEN%^G%^MAGENTA%^a%^GREEN%^rd%^CYAN%^e%^GREEN%^ns %^BOLD%^%^BLACK%^dot the landscape providing a splash of %^RESET%^%^MAGENTA%^c%^CYAN%^o%^GREEN%^l%^CYAN%^o%^MAGENTA%^r %^BOLD%^%^BLACK%^to the otherwise black surroundings. St%^WHITE%^a%^BLACK%^tues of all sorts occupy these gardens, from feline to humanoid and %^RESET%^%^RED%^menacing %^BOLD%^%^BLACK%^to %^RED%^agonized%^BLACK%^ watching over all that transpires here. Dwarfing all of it though is the colossal structure that towers over the yard, barely clinging to the precipice of the plateau. Steep steps ascend to tremendous marble pillars that line the entryway, a yawning portal in the shape of a %^RESET%^%^MAGENTA%^s%^BOLD%^%^BLACK%^e%^RESET%^%^MAGENTA%^pents%^BOLD%^%^BLACK%^ open maw. Adorned in %^RESET%^%^MAGENTA%^gl%^BOLD%^o%^RESET%^%^MAGENTA%^w%^BOLD%^i%^RESET%^%^MAGENTA%^ng windows %^BOLD%^%^BLACK%^of st%^RESET%^%^MAGENTA%^a%^BOLD%^%^BLACK%^in%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^d gl%^RESET%^%^MAGENTA%^a%^BOLD%^%^BLACK%^ss and elegantly spired buttresses, this foreboding construct is truly a masterwork of the craft. Far overhead you can see the whirling v%^RESET%^%^MAGENTA%^o%^BOLD%^%^BLACK%^rtex of d%^MAGENTA%^a%^BLACK%^rkness that crowns the temple, filling the air with a %^RESET%^%^MAGENTA%^malevolent energy%^BOLD%^%^BLACK%^.%^RESET%^");
    set_smell("default","%^MAGENTA%^You are surrounded by the thick scent floral scent of the many gardens.%^RESET%^");
    set_listen("default","%^MAGENTA%^You hear the rustling of the trees and the gentle gurgling of the streams.%^RESET%^");
    set_items(([
        ({"temple",""}) : " %^BOLD%^%^BLACK%^Looming over the courtyard, this awing structure radiates a %^RESET%^%^RED%^m%^BOLD%^a%^RESET%^%^RED%^lign a%^BOLD%^u%^RESET%^%^RED%^ra %^BOLD%^%^BLACK%^of %^RED%^terrible power%^BLACK%^. Its tall spires and flawless onyx walls have been shaped with elegantly curving ridges and balconies with elaborately engraved balustrades. The %^RESET%^%^MAGENTA%^w%^BOLD%^i%^RESET%^%^MAGENTA%^ndows %^BOLD%^%^BLACK%^which adorn near every flat expanse of the structure are works of art, the st%^RESET%^%^MAGENTA%^a%^BOLD%^%^BLACK%^ined panels depicting various scenes of a b%^RESET%^%^CYAN%^e%^MAGENTA%^a%^BOLD%^%^BLACK%^ut%^RESET%^%^CYAN%^i%^BOLD%^%^BLACK%^ful black skinned woman dancing among encircling ravens. The enormous likeness of a striking %^RESET%^%^MAGENTA%^serpent %^BOLD%^%^BLACK%^provides the yawning portal to the temples dark interior.%^RESET%^",
        ({"gardens","garden"}) : "%^GREEN%^The gardens are spread about the network of %^BOLD%^%^BLACK%^paths%^RESET%^%^GREEN%^ and %^BLUE%^streams%^GREEN%^, offering an e%^CYAN%^x%^GREEN%^o%^MAGENTA%^t%^GREEN%^ic blend of near unknown %^CYAN%^l%^MAGENTA%^u%^CYAN%^m%^BOLD%^%^CYAN%^i%^RESET%^CYAN%^n%^MAGENTA%^o%^CYAN%^us %^GREEN%^flora. The softly %^CYAN%^gl%^MAGENTA%^o%^BOLD%^%^CYAN%^w%^RESET%^%^MAGENTA%^i%^CYAN%^ng %^GREEN%^bulbs of these exquisite flowers serves to cast the entire courtyard into a %^MAGENTA%^surreal %^GREEN%^and %^CYAN%^int%^MAGENTA%^o%^CYAN%^x%^MAGENTA%^i%^CYAN%^cating l%^BOLD%^%^MAGENTA%^i%^RESET%^%^CYAN%^ght%^GREEN%^.%^RESET%^",
        ({"grove","tree"}) : " %^BOLD%^%^BLACK%^This small grove contains a smaller garden of d%^RESET%^%^CYAN%^a%^BOLD%^%^BLACK%^rkly c%^RESET%^%^MAGENTA%^o%^BOLD%^%^BLACK%^lor%^RESET%^%^CYAN%^e%^BOLD%^%^BLACK%^d fl%^RESET%^%^MAGENTA%^o%^BOLD%^%^BLACK%^ra. These however serve only as a momentary distraction from the gnarled, leafless tree which sprouts from the center, its twisted limbs bearing an oily black fruit. The same oily ichor seems to %^RESET%^%^RED%^bleed %^BOLD%^%^BLACK%^from the bark of the tree itself.%^RESET%^",
        ({"statues",""}) : "%^BOLD%^%^BLACK%^The gardens are filled with demonic effigies, feline representations, and cowled humanoids with sorrowful expressions reaching towards the tree in the center of the grove.%^RESET%^",
        ({"forest",""}) : "%^GREEN%^The dense vegetation cuts off abruptly at the edge of the courtyard, held back by no wall yet seemingly unwilling to grow any closer to the temple on the precipice. Even the snagging limbs refuse to grow out across the edges of the temple grounds.%^RESET%^",
        ({"vortex","darkness"}) : "%^BOLD%^%^BLACK%^Spinning slowly above this looming structure that dominates the end of the plateau is a halo of gloom. The darkness roils and seethes with an otherworldly energy and %^MAGENTA%^v%^RESET%^%^MAGENTA%^i%^BOLD%^ol%^RESET%^%^MAGENTA%^e%^BOLD%^t l%^RESET%^%^MAGENTA%^i%^BOLD%^ghtn%^RESET%^%^MAGENTA%^i%^BOLD%^ng fl%^RESET%^%^MAGENTA%^a%^BOLD%^sh%^RESET%^%^MAGENTA%^e%^BOLD%^s %^BLACK%^and %^MAGENTA%^str%^RESET%^%^MAGENTA%^e%^BOLD%^aks %^BLACK%^through its depths.%^RESET%^",
    ]));
    set_exits(([
        "northeast" : "/d/magic/temples/shar_path5",
        "temple" : "/d/magic/temples/ashra/hall",
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
   